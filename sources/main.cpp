#include<iostream>
#include<memory>

#include "Singleton.hpp"
#include "Factory.hpp"
#include "Facade.hpp"
#include "FlyWeight.hpp"

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

void testSingleton(){
    std::cout << "----- STRAT TEST -----" << std::endl;
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
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::shared_ptr<Client> c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SUVType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SedanType);
    c->getVehicle()->printVehicleData();
}

void testFacade(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::unique_ptr<BankService> pBankService = std::make_unique<BankService>();
    
    auto AliceSavingAccountNumber = pBankService->createNewAccount(AccountType::savingAccount, 500);
    auto AliceInvestmentAccountNumber = pBankService->createNewAccount(AccountType::investmentAccount, 1000);
    std::cout << "AliceSavingAccountNumber: " << AliceSavingAccountNumber << std::endl;
    std::cout << "AliceSavingAccountNumber: " << AliceSavingAccountNumber << std::endl;
    std::cout << "Alice' saving is: " << pBankService->getAmountOfAccount(AliceSavingAccountNumber) << " and her investment is: " << pBankService->getAmountOfAccount(AliceInvestmentAccountNumber) << std::endl;

    auto BobSavingAccountNumber = pBankService->createNewAccount(AccountType::savingAccount, 1500);
    auto BobInvestmentAccountNumber = pBankService->createNewAccount(AccountType::investmentAccount, 2000);
    std::cout << "Bob's saving is: " << pBankService->getAmountOfAccount(BobSavingAccountNumber)  << " and his investment is: " << pBankService->getAmountOfAccount(BobInvestmentAccountNumber) << std::endl;

    uint16_t transferAmount{500};
    pBankService->transferMoney(BobSavingAccountNumber, AliceSavingAccountNumber, transferAmount);
    std::cout << "Bob transfered " << transferAmount << " to Alice' saving account."
              << " Now his saving account is: " << pBankService->getAmountOfAccount(BobSavingAccountNumber)
              << " and her saving account is: " << pBankService->getAmountOfAccount(AliceSavingAccountNumber)
            << std::endl;

    
}

void testFlyWeight(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::unique_ptr<FlyWeight> FW = std::make_unique<FlyWeight>();
    // add new images
    FW->addImage<PNG>("Alice");
    FW->addImage<JPG>("Bob");
    FW->addImage<GIF>("Charlie");
    FW->addImage<PNG>("Dani");

    // get invalid image
    std::cout << "\nTry to get an invalid image called Hanna:" << std::endl;
    FW->getImage("Hanna");

    // get type of valid images
    std::cout << "\nWhat is the type of Alice' image?" << std::endl;
    FW->getImage("Alice")->print();
    std::cout << "\nWhat is the type of Bob's image?" << std::endl;
    FW->getImage("Bob")->print();

    // delete an image and get it
    std::cout << "\nDeletes an image and tries to access it:" << std::endl;
    FW->deleteImage("Dani");
    FW->getImage("Dani");
}