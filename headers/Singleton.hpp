#include <iostream>
#include <memory>
#include <string>

class Singleton{
private:
    Singleton();
    ~Singleton();
public:
    static Singleton* makeInstance();
    void setName(std::string name);
    std::string getName() const;
    
private:
    std::string m_name;
    static Singleton* m_instance;
};