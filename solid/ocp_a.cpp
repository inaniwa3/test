#include <iostream>

class Rakugoka
{
public:
    virtual void Hello() = 0;  // pure virtual function
};

class Koyuza : public Rakugoka
{
public:
    void Hello() override
    {
        std::cout << "I'm Koyuza." << std::endl;
    }
};

class Konpei : public Rakugoka
{
public:
    void Hello() override
    {
        std::cout << "Konpeee desu." << std::endl;
    }
};

int main()
{
    Koyuza koyuza;
    Konpei konpei;
    Rakugoka* rakugoka[] = { &koyuza, &konpei };

    for (auto& r : rakugoka)
    {
        r->Hello();
    }
}
