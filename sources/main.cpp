#include<iostream>
#include<memory>

#include "Singleton.hpp"
#include "Factory.hpp"

void testSingleton();
void testFactory();

int main(){
    std::cout << "To test any Design Pattern, please enter its corresponding number." << std::endl;
    std::cout << "For Singleton enter 1\n"
              << "For Factory enter 2\n"
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
    }
    
    default:
        break;
    }
}

void testSingleton(){
    Singleton* p1 = Singleton::makeInstance();
    if(p1!=nullptr)
        std::cout << "An instance was created" << std::endl;
    else
        std::cout << "An instance has already been created! No more instance is allowed!" << std::endl;
    
    Singleton* p2 = Singleton::makeInstance();
    if(p2!=nullptr)
        std::cout << "An instance created" << std::endl;
    else
        std::cout << "An instance has already been created! No more instance is allowed!" << std::endl;
}

void testFactory(){
    std::shared_ptr<Client> c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SUVType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SedanType);
    c->getVehicle()->printVehicleData();
}