#include "../headers/Singleton.hpp"

Singleton* Singleton::s_instance{nullptr};

Singleton::Singleton()
: m_name("")
{}

Singleton* Singleton::makeInstance(){
    if(s_instance==nullptr){
        s_instance = new Singleton;
        return s_instance;
    }
    else{
        return nullptr;
    }
}

void Singleton::setName(std::string name){
    m_name = name;
}

std::string Singleton::getName() const {
    return m_name;
}