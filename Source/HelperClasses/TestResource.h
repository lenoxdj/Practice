#pragma once

class TestResource
{
public:
    TestResource();
    TestResource(std::string n);
    ~TestResource(void);

    TestResource(const TestResource& r);
    TestResource& operator=(const TestResource& r);

    TestResource(TestResource&& r);
    TestResource& operator=(TestResource&& r);

    std::string GetName() const;

    void ResourceDriver();
private:
    std::string name;
};