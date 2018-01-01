#pragma once

template <typename T>
T max(T a, T b);

template<typename T>
void foo(T data);

template<typename T>
struct is_char
{
    static const bool value = false;
};

template<>
struct is_char<char>
{
    static const bool value = true;
};

template<>
struct is_char<wchar_t>
{
    static const bool value = true;
};

// Policy design
class LockingPolicy
{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class Lock : public LockingPolicy
{
public:
    virtual void lock() override;
    virtual void unlock() override;
};

class NoLock : public LockingPolicy
{
public:
    virtual void lock() { }
    virtual void unlock() { }
};

template<typename T, typename Locking>
class Data : public Locking
{
    T *data;
public:
    Data(T* _data) : data{ _data } {}

    void do_something()
    {
        this->lock();
        std::cout << "Data: " << *data << std::endl;
        this->unlock();
    }
};