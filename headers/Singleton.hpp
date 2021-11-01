#include <iostream>
#include <memory>
#include <string>

class Singleton{
private:
    Singleton();
    ~Singleton();

    Singleton(const Singleton& other) = delete;
    Singleton(Singleton&& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;
    Singleton& operator=(Singleton&& other) = delete;
public:
    static Singleton* makeInstance();
    void setName(std::string name);
    std::string getName() const;
    
private:
    std::string m_name;
    static Singleton* m_instance;
};