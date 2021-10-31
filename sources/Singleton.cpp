#include "Singleton.hpp"

Singleton* Singleton::m_instance{nullptr};

Singleton::Singleton()
: m_name("NoName")
{}

Singleton::~Singleton(){
    delete m_instance;
}

Singleton* Singleton::makeInstance(){
    if(m_instance==nullptr){
        m_instance = new Singleton;
        return m_instance;
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