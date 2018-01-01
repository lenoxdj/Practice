#include "stdafx.h"
#include "TestResource.h"

TestResource::TestResource()
{
    this->name = "default";
    std::cout << "constructing default" << std::endl;
}

TestResource::TestResource(std::string n) :
    name(n)
{
    std::cout << "constructing " << n << std::endl;
}

TestResource::TestResource(const TestResource& r) :
    name(r.name)
{
    std::cout << "copy constructing " << name << std::endl;
}

TestResource& TestResource::operator=(const TestResource& r)
{
    name = r.GetName();
    std::cout << "copy assigning " << name << std::endl;
    return *this;
}

TestResource::TestResource(TestResource&& r) :
    name(std::move(r.name))
{
    std::cout << "move constructing " << name << std::endl;
}

TestResource& TestResource::operator=(TestResource&& r)
{
    std::cout << "move assigning " << name << std::endl;

    if (this != &r)
    {
        name = std::move(r.name);
        r.name.clear();
    }

    return *this;
}

TestResource::~TestResource(void)
{
    std::cout << "destructing " << this->name << std::endl;
}

std::string TestResource::GetName() const
{
    return this->name;
}

void ResourceDriver()
{
    TestResource local("local");
    std::vector<TestResource> resources(2);
    resources.clear();

    std::cout << "======================== add local to resources" << std::endl;
    resources.push_back(local);                                                   // pass by value, copy constructor

    std::cout << "======================== add rvalue to resources" << std::endl;
    resources.push_back(TestResource("rvalue"));

    std::cout << "======================== iterate by value" << std::endl;
    std::for_each(begin(resources), end(resources),
        [](TestResource r)                                                            // pass by value, copy constructor
    {
        std::cout << "processing " << r.GetName() << std::endl;
    });

    std::cout << "======================== iterate by ref" << std::endl;
    std::for_each(begin(resources), end(resources),
        [](const TestResource& r)                                                     // pass by reference, no copy or move
    {
        std::cout << "processing " << r.GetName() << std::endl;
    });
}
