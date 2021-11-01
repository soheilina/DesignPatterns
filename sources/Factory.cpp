#include "Factory.hpp"

// ----- class VehicleFactory -----
std::shared_ptr<VehicleFactory> VehicleFactory::build(VehicleType type){

    switch(type){
        case VehicleType::BikeType:{
            std::shared_ptr<Bike> newBike = std::make_shared<Bike>();
            return newBike;
            break;
        }
        case VehicleType::SedanType:{
            std::shared_ptr<Sedan> newBike = std::make_shared<Sedan>();
            return newBike;
            break;
        }
        case VehicleType::SUVType:{
            std::shared_ptr<SUV> newBike = std::make_shared<SUV>();
            return newBike;
            break;
        }
    }
}

// ---- class Bike ----
int Bike::s_serialNumber = 1000;
Bike :: Bike(){
    s_serialNumber++;
}
void Bike::printVehicleData(){
    std::cout << "This is a Bike with the serial number " << s_serialNumber << std::endl;
}

// ---- class Sedan ----
int Sedan::s_serialNumber = 2000;
Sedan :: Sedan(){
    s_serialNumber++;
}
void Sedan::printVehicleData(){
    std::cout << "This is a Sedan with the serial number " << s_serialNumber << std::endl;
}

// ---- class SUV ----
int SUV::s_serialNumber = 3000;
SUV :: SUV(){
    s_serialNumber++;
}
void SUV::printVehicleData(){
    std::cout << "This is a SUV with the serial number " << s_serialNumber << std::endl;
}

// ---- class client ----
Client::Client(VehicleType type){
    m_vehicle = VehicleFactory::build(type);
}
std::shared_ptr<VehicleFactory> Client::getVehicle() const{
    return m_vehicle;
}