#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    srand(time(0));
    int random = rand() % 3;

    switch (random)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();

    default:
        return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Object by pointer. of type: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Object by pointer. of type: B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Object by pointer. of type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Object by reference. of type: A" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Object by reference. of type: B" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "Object by reference. of type: C" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
}

int main()
{
    Base *obj = generate();

    identify(obj);
    identify(*obj);
    delete obj;
    return 1;
}