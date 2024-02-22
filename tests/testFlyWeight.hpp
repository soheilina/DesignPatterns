#include "lib/FlyWeight.hpp"

void testFlyWeight(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::unique_ptr<FlyWeight> FW = std::make_unique<FlyWeight>();
    // add new images
    FW->addImage<PNG>("Alice");
    FW->addImage<JPG>("Bob");
    FW->addImage<GIF>("Charlie");
    FW->addImage<PNG>("Dani");

    // get invalid image
    std::cout << "\nTry to get an invalid image called Hanna:" << std::endl;
    FW->getImage("Hanna");

    // get type of valid images
    std::cout << "\nWhat is the type of Alice' image?" << std::endl;
    FW->getImage("Alice")->print();
    std::cout << "\nWhat is the type of Bob's image?" << std::endl;
    FW->getImage("Bob")->print();

    // delete an image and get it
    std::cout << "\nDeletes an image and tries to access it:" << std::endl;
    FW->deleteImage("Dani");
    FW->getImage("Dani");
}