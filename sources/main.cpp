#include<iostream>
#include<memory>

#include "Singleton.hpp"
#include "Factory.hpp"
#include "Facade.hpp"

void testSingleton();
void testFactory();
void testFacade();

int main(){
    std::cout << "To test any Design Pattern, please enter its corresponding number." << std::endl;
    std::cout << "For Singleton enter 1\n"
              << "For Factory enter 2\n"
              << "For Facade enter 3\n"
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
    
    default:
        std::cout << "You entered invalid number" << std::endl;
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

void testFacade(){
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