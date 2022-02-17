#include<iostream>
#include<memory>

// Headers
#include "Singleton.hpp"
#include "Factory.hpp"
#include "Facade.hpp"
#include "FlyWeight.hpp"
#include "Composite.hpp"

// Tests
#include "testSingleton.h"
#include "testFactory.h"
#include "testFacade.h"
#include "tetsFlyWeight.h"
#include "testComposite.h"

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
              << "5) For Composite enter \n"
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
    case 5:{
        testComposite();
        break;
    }
        
    default:
        std::cout << "You entered invalid number" << std::endl;
        break;
    }
}