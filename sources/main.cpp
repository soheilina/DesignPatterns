#include <iostream>
#include <memory>

// Headers
#include "../headers/Singleton.hpp"
#include "../headers/Factory.hpp"
#include "../headers/Facade.hpp"
#include "../headers/FlyWeight.hpp"
#include "../headers/Composite.hpp"

// Tests
#include "../tests/testSingleton.h"
#include "../tests/testFactory.h"
#include "../tests/testFacade.h"
#include "../tests/testFlyWeight.h"
#include "../tests/testComposite.h"

int getTestRequestFromUser(int numberOfTests);
void testSingleton();
void testFactory();
void testFacade();
void testFlyWeight();

int main()
{
    std::cout << "To test any Design Pattern, please enter its corresponding number." << std::endl;
    std::cout << "1) For Singleton enter \n"
              << "2) For Factory enter \n"
              << "3) For Facade enter \n"
              << "4) For FlyWeight enter \n"
              << "5) For Composite enter \n"
              << std::endl;

    const int numberOfTests{5};
    const int input = getTestRequestFromUser(numberOfTests);

    switch (input)
    {
    case 1:
    {
        testSingleton();
        break;
    }
    case 2:
    {
        testFactory();
        break;
    }
    case 3:
    {
        testFacade();
        break;
    }
    case 4:
    {
        testFlyWeight();
        break;
    }
    case 5:
    {
        testComposite();
        break;
    }

    default:
        std::cout << "You entered an invalid number" << std::endl;
        break;
    }
}

int getTestRequestFromUser(int numberOfTests)
{
    int n{0};
    std::cin >> n;
    if (n >= 1 && n <= numberOfTests)
    {
        return n;
    }
    else
    {
        std::cout << "You entered an invalid number. Try again! Enter a value from 1 to " << numberOfTests << ":" << std::endl;
        return getTestRequestFromUser(numberOfTests);
    }
}