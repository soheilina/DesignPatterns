void testFactory(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::shared_ptr<Client> c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::BikeType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SUVType);
    c->getVehicle()->printVehicleData();

    c = std::make_shared<Client>(VehicleType::SedanType);
    c->getVehicle()->printVehicleData();
}