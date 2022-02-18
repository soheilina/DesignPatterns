/* It implements Singleton Design Pattern.
*  Main idea: By making c'tor protected/private we prevent any instantiation via calling c'tor. Moreover,
              a static counter stores the number of instattiation. Furthermore,
              A static function checks counter==0 and creats an instance.
*/
#include <iostream>
#include <memory>
#include <string>

class Singleton{
private:
    Singleton();
    ~Singleton() = default;

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
    static Singleton* s_instance;
};