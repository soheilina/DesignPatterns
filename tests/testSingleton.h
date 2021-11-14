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