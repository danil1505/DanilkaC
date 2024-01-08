#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "record.h"

class ModelInterface {
public:
    virtual void addRecord(const Record& record) = 0;
    virtual std::vector<Record> getRecords() const = 0;
    virtual void editRecord(int index, const Record& newRecord) = 0;
    virtual void deleteRecord(int index) = 0;
    virtual void saveToFile() const = 0;
    virtual void loadFromFile() = 0;
};

class Model : public ModelInterface {
public:
    void addRecord(const Record& record) override;
    std::vector<Record> getRecords() const override;
    void editRecord(int index, const Record& newRecord) override;
    void deleteRecord(int index) override;
    void saveToFile() const override;
    void loadFromFile() override;

private:
    std::vector<Record> records;
};
void Model::addRecord(const Record& record) {
    records.push_back(record);
}

std::vector<Record> Model::getRecords() const {
    return records;
}

void Model::editRecord(int index, const Record& newRecord) {
    if (index >= 0 && index < records.size()) {
        records[index] = newRecord;
    } else {
        std::cout << "Неверный индекс для редактирования\n";
    }
}

void Model::deleteRecord(int index) {
    if (index >= 0 && index < records.size()) {
        records.erase(records.begin() + index);
        std::cout << "Заказ удален\n";
    } else {
        std::cout << "Неверный индекс для удаления\n";
    }
}

void Model::saveToFile() const {
    std::ofstream file("records.txt");

    if (file.is_open()) {
        for (const auto& record : records) {
            file << record.getDate() << " "
                 << record.getCustomer().getName() << " "
                 << record.getOrder().getOrderId() << " "
                 << record.getOrder().getProduct() << " "
                 << record.getOrder().getQuantity() << "\n";
        }

        file.close();
        std::cout << "Заказ сохранены в файл\n";
    } else {
        std::cout << "Невозможно сохранить\n";
    }
}

void Model::loadFromFile() {
    std::ifstream file("records.txt");

    if (file.is_open()) {
        records.clear(); // Очищаем существующие записи

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string date, name, product;
            int orderId, quantity;

            if (!(iss >> date >> name >> orderId >> product >> quantity)) {
                std::cout << "Ошибка при чтении файла\n";
                break;
            }

            People customer(name);
            Order order(orderId, product, quantity);
            Record record(date, customer, order);

            records.push_back(record);
        }

        file.close();
        std::cout << "Заказы загружены\n";
    } else {
        std::cout << "Невозможно загрузить\n";
    }
}
#endif
