#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// randomly instanciates A, B or C and returns the instance as a Base pointer.
Base *generate(void);

// It prints the actual type of the object pointed to by p: "A", "B" or "C"
void identify(Base *p);

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.
void identify(Base &p);

int main()
{
    Base *obj;
    try
    {
        obj = generate();
    }
    catch (std::bad_alloc &e)
    {
        e.what();
        return 1;
    }
    identify(obj);
    identify(*obj);
    delete obj;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "This is class A" << std::endl;
    }
    catch (std::bad_cast &e)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "This is class B" << std::endl;
    }
    catch (std::bad_cast &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "This is class C" << std::endl;
    }
    catch (std::bad_cast &e)
    {
    }
}

void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    if (a != nullptr)
    {
        std::cout << "This is class A" << std::endl;
        return;
    }
    B *b = dynamic_cast<B *>(p);
    if (b != nullptr)
    {
        std::cout << "This is class B" << std::endl;
        return;
    }
    C *c = dynamic_cast<C *>(p);
    if (c != nullptr)
    {
        std::cout << "This is class C" << std::endl;
        return;
    }
}

Base *generate(void)
{
    // Seed the random number generator
    std::srand(std::time(nullptr)); // Seed with current time
    int random_index = std::rand() % 3;
    switch (random_index)
    {
    case 0:
    {
        return new A;
    }
    case 1:
    {
        return new B;
    }
    case 2:
    {
        return new C;
    }
    default:
    {
        return nullptr;
    }
    }
}
