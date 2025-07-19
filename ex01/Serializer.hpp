#pragma once

#include <iostream>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &s);
    Serializer &operator=(const Serializer &s);
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};
