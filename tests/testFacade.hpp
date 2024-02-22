#include "lib/Facade.hpp"

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