#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include "model.h"
#include "view.h"

class ControllerInterface {
public:
    virtual void processUserInput() = 0;
};

class Controller : public ControllerInterface {
public:
    Controller(ModelInterface& model, ViewInterface& view);

    void processUserInput() override;

private:
    ModelInterface& model;
    ViewInterface& view;

    void executeOption(int option);
    void addRecord();
    void editRecord();
    void deleteRecord();
};
Controller::Controller(ModelInterface& model, ViewInterface& view) : model(model), view(view) {}

void Controller::processUserInput() {
    int option;

    do {
        view.displayMenu();
        std::cin >> option;

        executeOption(option);
    } while (option != 7);
}

void Controller::executeOption(int option) {
    switch (option) {
        case 1:
            view.displayRecords(model.getRecords());
            break;
        case 2:
            addRecord();
            break;
        case 3:
            editRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            model.saveToFile();
            break;
        case 6:
            model.loadFromFile();
            break;
        case 7:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный вариант\n";
    }
}

void Controller::addRecord() {
    std::string date, name, product;
    int orderId, quantity;

    std::cout << "Введите дату: ";
    std::cin >> date;

    std::cout << "Введите разработчика: ";
    std::cin >> name;

    std::cout << "Введите ID: ";
    std::cin >> orderId;

    std::cout << "Введите название продукта: ";
    std::cin >> product;

    std::cout << "Введите количество: ";
    std::cin >> quantity;

    People customer(name);
    Order order(orderId, product, quantity);
    Record record(date, customer, order);

    model.addRecord(record);

    std::cout << "Заказ успешно добавлен\n";
}

void Controller::editRecord() {
    view.displayRecords(model.getRecords());

    if (model.getRecords().empty()) {
        std::cout << "Нет записей для редактирования.\n";
        return;
    }

    int indexToEdit;
    std::cout << "Введите индекс для редактирования: ";
    std::cin >> indexToEdit;

    if (indexToEdit < 0 || indexToEdit >= model.getRecords().size()) {
        std::cout << "Неверный индекс.\n";
        return;
    }

    // Получаем копию вместо ссылки
    Record recordToEdit = model.getRecords()[indexToEdit];

    std::string newDate, newName, newProduct;
    int newOrderId, newQuantity;

    std::cout << "Введите новую дату: ";
    std::cin >> newDate;

    std::cout << "Введите нового разработчика: ";
    std::cin >> newName;

    std::cout << "Введите новый ID: ";
    std::cin >> newOrderId;

    std::cout << "Введите новое название продукта: ";
    std::cin >> newProduct;

    std::cout << "Введите новое количество: ";
    std::cin >> newQuantity;

    People newCustomer(newName);
    Order newOrder(newOrderId, newProduct, newQuantity);
    Record newRecord(newDate, newCustomer, newOrder);

    model.editRecord(indexToEdit, newRecord);

    std::cout << "Заказ успешно изменен.\n";
    model.saveToFile(); // Сохраняем изменения в файл
}

void Controller::deleteRecord() {
    view.displayRecords(model.getRecords());

    if (model.getRecords().empty()) {
        std::cout << "Нет заказов для удаления.\n";
        return;
    }

    int indexToDelete;
    std::cout << "Введите индекс для удаления: ";
    std::cin >> indexToDelete;

    // Получаем копию вместо ссылки
    Record recordToDelete = model.getRecords()[indexToDelete];

    model.deleteRecord(indexToDelete);
    model.saveToFile(); // Сохраняем изменения в файл
}
#endif 
