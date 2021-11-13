#include "Facade.hpp"
//----- AccountInterface class
void AccountInterface::deposit(uint16_t amount){
    m_amount += amount;
}
void AccountInterface::transfer(uint16_t amount){
    m_amount -= amount;
}
void AccountInterface::setAccountNumber(uint16_t accountNumber){
    m_accountNumber = accountNumber;
}
uint16_t AccountInterface::getAccountNumber() const {
    return m_accountNumber;
}
uint16_t AccountInterface::getAmount() const {
    return m_amount;
}



//----- Chequing class
std::string Chequing::getAccountType() const {
    return m_accountType;
}

//----- Saving class
std::string Saving::getAccountType() const {
    return m_accountType;
}

//----- Investment class
std::string Investment::getAccountType() const {
    return m_accountType;
}

//----- BankService class
uint16_t BankService::createNewAccount(AccountType type, uint16_t amount){
    switch (type)
    {
        case AccountType::chequingAccount:
        {
            std::unique_ptr<Chequing> pChequing = std::make_unique<Chequing>();
            pChequing->setAccountNumber(++m_accountNumber);
            pChequing->deposit(amount);
            m_allAccounts.insert(std::make_pair(m_accountNumber, std::move(pChequing)));
            break;
        }
        case AccountType::savingAccount:
        {
            std::unique_ptr<Saving> pSaving = std::make_unique<Saving>();
            pSaving->setAccountNumber(++m_accountNumber);
            pSaving->deposit(amount);
            m_allAccounts.insert(std::make_pair(m_accountNumber, std::move(pSaving)));
            break;
        }
        case AccountType::investmentAccount:
        {
            std::unique_ptr<Investment> pInvestment = std::make_unique<Investment>();
            pInvestment->setAccountNumber(++m_accountNumber);
            pInvestment->deposit(amount);
            m_allAccounts.insert(std::make_pair(m_accountNumber, std::move(pInvestment)));
            break;
        }
        default:
        {
            std::cerr << "This is an invalid account type" << std::endl;
            break;
        }
    }
    return m_accountNumber;
}

void BankService::transferMoney(uint16_t fromAccountNumber, uint16_t toAccountNumber, uint16_t amount){
    m_allAccounts[fromAccountNumber]->transfer(amount);
    m_allAccounts[toAccountNumber]->deposit(amount);
}

uint16_t BankService::getAmountOfAccount(uint16_t accountNumber){
    uint16_t amount = m_allAccounts[accountNumber]->getAmount();
    return amount;
}