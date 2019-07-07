#include <iostream>

class Rakugoka
{
public:
    virtual ~Rakugoka()
    {
        std::cout << "~Rakugoka()" << std::endl;
    };
    virtual void Hello() = 0;
};

class Koyuza : public Rakugoka
{
public:
    ~Koyuza() override
    {
        std::cout << "~Koyuza()" << std::endl;
    }
    void Hello() override
    {
        std::cout << "I'm Koyuza." << std::endl;
    }
};

class Konpei : public Rakugoka
{
public:
    ~Konpei() override
    {
        std::cout << "~Konpei()" << std::endl;
    }
    void Hello() override
    {
        std::cout << "Konpeee desu." << std::endl;
    }
};

int main()
{
    Rakugoka* rakugoka[] = { new Koyuza(), new Konpei() };

    for (auto& r : rakugoka)
    {
        r->Hello();
    }

    for (auto& r : rakugoka)
    {
        delete r;
    }
}

// I'm Koyuza.
// Konpeee desu.
// ~Koyuza()
// ~Rakugoka()
// ~Konpei()
// ~Rakugoka()
