#include "../lib/pch.hpp"

// Tests
#include "../tests/testComposite.hpp" //FIXME: without '../' we get error in clang-tidy but if we use '../' what's the point of including lib in bazel & cmake?
#include "testFacade.hpp"
#include "testFactory.hpp"
#include "testFlyWeight.hpp"
#include "testSingleton.hpp"
#include "testDecorator.hpp"
#include "testAdapter.hpp"
#include "testStrategy.hpp"

enum class DesignPatterns{
    DEFAULT = 0,
    SINGLETON = 1,
    FACTORY = 2,
    FACADE = 3,
    FLYWEIGHT = 4,
    COMPOSITE = 5,
    DECORATOR = 6,
    ADAPTER = 7,
    STARTEGY = 8,
    COUNT = 9
};

DesignPatterns getTestRequestFromUser(void);

int main()
{
    std::cout << "To test any Design Pattern, please enter its corresponding number." << std::endl;
    std::cout << "1 For Singleton \n"
              << "2 For Factory \n"
              << "3 For Facade \n"
              << "4 For FlyWeight \n"
              << "5 For Composite \n"
              << "6 For Decorator \n"
              << "7 For Adapter \n"
              << "8 For Strategy \n"
              << std::endl;

    const DesignPatterns input = getTestRequestFromUser();

    switch (input)
    {
    case DesignPatterns::SINGLETON:
    {
        testSingleton();
        break;
    }
    case DesignPatterns::FACTORY:
    {
        testFactory();
        break;
    }
    case DesignPatterns::FACADE:
    {
        testFacade();
        break;
    }
    case DesignPatterns::FLYWEIGHT:
    {
        testFlyWeight();
        break;
    }
    case DesignPatterns::COMPOSITE:
    {
        testComposite();
        break;
    }
    case DesignPatterns::DECORATOR:
    {
        testDecorator();
        break;
    }
    case DesignPatterns::ADAPTER:
    {
        testAdapter();
        break;
    }
    case DesignPatterns::STARTEGY:
    {
        testStrategy();
        break;
    }

    default:
        std::cout << "You entered an invalid number" << std::endl;
        break;
    }
}

DesignPatterns getTestRequestFromUser()
{
    uint16_t n{0};
    std::cin >> n;
    if (n >= 1 && n < static_cast<uint16_t>(DesignPatterns::COUNT))
    {
        return static_cast<DesignPatterns>(n);
    }
    else
    {
        std::cout << "You entered an invalid number. Try again! Enter a value from 1 to "
        << static_cast<uint16_t>(DesignPatterns::COUNT) << ":" << std::endl;
        return getTestRequestFromUser();
    }
}