#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <vector>
#include "record.h"
class ViewInterface {
public:
    virtual void displayRecords(const std::vector<Record>& records) const = 0;
    virtual void displayMenu() const = 0;
};

class View : public ViewInterface {
public:
    void displayRecords(const std::vector<Record>& records) const override;
    void displayMenu() const override;
};


void View::displayRecords(const std::vector<Record>& records) const {
    for (const auto& record : records) {
        std::cout << "Дата: " << record.getDate() << "\n";
        std::cout << "Разработал: " << record.getCustomer().getName() << "\n";
        std::cout << "Заказ: " << record.getOrder().getProduct() << "\n";
        std::cout << "Количество: " << record.getOrder().getQuantity() << "\n";
        std::cout << "-----------------------\n";
    }
}

void View::displayMenu() const {
    std::cout << "1. Вывести список заказов \n";
    std::cout << "2. Добавить новый заказ\n";
    std::cout << "3. Редактирование заказа\n";
    std::cout << "4. Удалить заказ\n";
    std::cout << "5. Сохранить в файл\n";
    std::cout << "6. Загрузить из файла\n";
    std::cout << "7. Выход\n";
    std::cout << "Введите ваш выбор: ";
}

#endif
