#include <iostream>
#include <string>
#include <unordered_map>


enum class AccountType{
    chequingAccount,
    savingAccount,
    investmentAccount
};

class AccountInterface {
public:
    AccountInterface() = default;
    virtual ~AccountInterface() = default;

public:
    virtual void deposit(uint16_t amount);
    virtual void transfer(uint16_t amount);
    virtual void assignAccountNumber(uint16_t newAccountNumber);
    virtual uint16_t getAccountNumber() const;
    virtual uint16_t getAmount() const;
    virtual std::string getAccountType() const = 0;

private:
    uint16_t m_amount;
    uint16_t m_accountNumber;
};

class Chequing : public AccountInterface{
public:
    Chequing()
    : AccountInterface()
    , m_accountType("Chequing")
    {}
    virtual ~Chequing() = default;
    Chequing(const Chequing& rhs) = delete;
    Chequing(const Chequing&& rhs) = delete;
    Chequing& operator=(const Chequing& rhs) = delete;
    Chequing& operator=(const Chequing&& rhs) = delete;

public:
    std::string getAccountType() const override;

private:
    std::string m_accountType;
};

class Saving : public AccountInterface{
public:
    Saving()
    : AccountInterface()
    , m_accountType("Saving")
    {}
    virtual ~Saving() = default;
    Saving(const Saving& rhs) = delete;
    Saving(const Saving&& rhs) = delete;
    Saving& operator=(const Saving& rhs) = delete;
    Saving& operator=(const Saving&& rhs) = delete;

public:
    std::string getAccountType() const override;

private:
    std::string m_accountType;
};

class Investment : public AccountInterface{
public:
    Investment()
    : AccountInterface()
    , m_accountType("Investment")
    {}
    virtual ~Investment() = default;
    Investment(const Investment& rhs) = delete;
    Investment(const Investment&& rhs) = delete;
    Investment& operator=(const Investment& rhs) = delete;
    Investment& operator=(const Investment&& rhs) = delete;

public:
    std::string getAccountType() const override;

private:
    std::string m_accountType;
};

// BankService class is the Facade Design Pattern
class BankService{
public:
    BankService()
    : m_allAccounts()
    , m_newAccountNumber(1000)
    {}
    ~BankService() = default;
    BankService(const BankService& rhs) = delete;
    BankService(const BankService&& rhs) = delete;
    BankService& operator=(const BankService& rhs) = delete;
    BankService& operator=(const BankService&& rhs) = delete;

public:
    uint16_t createNewAccount(AccountType type, uint16_t amount);
    void transferMoney(uint16_t fromAccountNumber, uint16_t toAccountNumber, uint16_t amount);
    uint16_t getAmountOfAccount(uint16_t accountNumber);

private:
    // Maps account number to its corresponding account
    std::unordered_map<uint16_t, std::shared_ptr<AccountInterface> > m_allAccounts;
    // The account number that is assigned to a new account
    uint16_t m_newAccountNumber;
};