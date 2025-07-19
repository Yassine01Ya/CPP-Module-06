#include "Serializer.hpp"

int main()
{
    Data data;

    data.name = "Yassine";
    data.age = 24;
    data.salary = 100000;

    std::cout << "-------------------------------\n";
    std::cout << "Adress of data before seralizer -> " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    Data *des = Serializer::deserialize(raw);
    std::cout << "Adress of data after seralizer -> " << des << std::endl;
    std::cout << "-------------------------------\n";
    std::cout << "des->name == " << des->name << std::endl;
    std::cout << "des->age == " << des->age << std::endl;
    std::cout << "des->salary == " << des->salary << std::endl;
}