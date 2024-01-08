#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class People {
public:
    People(const std::string& name);

    std::string getName() const;

private:
    std::string name;
};
People::People(const std::string& name) : name(name) {}

std::string People::getName() const {
    return name;
}
#endif 
