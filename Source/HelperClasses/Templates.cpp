#include "stdafx.h"
#include "Templates.h"

template<typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template int max<int>(int a, int b);

template<typename T>
void foo(T data)
{
    if (is_char<T>::value)
        std::cout << "is a char" << std::endl;
    else
        std::cout << "not a char" << std::endl;
}

template void foo<int>(int data);

void Lock::lock()
{
    std::cout << "Locking" << std::endl;
}

void Lock::unlock()
{
    std::cout << "Unlocking" << std::endl;
}

void TemplatesDriver()
{
    auto pn = new int{ 10 };
    auto pn2 = new int{ 20 };

    Data<int, Lock> d1{ pn };
    Data<int, NoLock> d2{ pn2 };

    d1.do_something();
    d2.do_something();
}