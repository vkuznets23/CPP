#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main()
{
    Data data{123, "string"};

    uintptr_t ptr = Serializer::serialize(&data);
    Data *data_ptr = Serializer::deserialize(ptr);

    std::cout << "Initial object address: " << &data << '\n'
              << "Deserialized object address: " << data_ptr << '\n';

    std::cout << "Initial int:" << data.integer << ", string:" << data.string << '\n'
              << "Deserialized int:" << data.integer << ", string:" << data.string << '\n';

    data_ptr->integer = 0;
    data_ptr->string = "NEW_STRING";

    std::cout << "Initial int:" << data.integer << ", string:" << data.string << '\n'
              << "Deserialized int:" << data.integer << ", string:" << data.string << '\n';
}