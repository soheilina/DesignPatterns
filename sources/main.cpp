#include<iostream>
#include<memory>

// Headers
#include "Singleton.hpp"
#include "Factory.hpp"
#include "Facade.hpp"
#include "FlyWeight.hpp"

// Tests
#include "testSingleton.h"
#include "testFactory.h"
#include "testFacade.h"
#include "tetsFlyWeight.h"

void testSingleton();
void testFactory();
void testFacade();
void testFlyWeight();

int main(){
    std::cout << "To test any Design Pattern, please enter its corresponding number." << std::endl;
    std::cout << "1) For Singleton enter \n"
              << "2) For Factory enter \n"
              << "3) For Facade enter \n"
              << "4) For FlyWeight enter \n"
              << std::endl;
    
    int input{0};
    std::cin >> input;
    switch (input)
    {
    case 1:{
        testSingleton();
        break;
    }
    case 2:{
        testFactory();
        break;
    }
    case 3:{
        testFacade();
        break;
    }
    case 4:{
        testFlyWeight();
        break;
    }
    
    default:
        std::cout << "You entered invalid number" << std::endl;
        break;
    }
}