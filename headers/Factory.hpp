#include<iostream>
#include<string>
#include<memory>

enum class VehicleType{
    BikeType,
    SedanType,
    SUVType
};

class VehicleFactory{
public:
    VehicleFactory() = default;
    ~VehicleFactory() = default;

    VehicleFactory(const VehicleFactory& other) = delete;
    VehicleFactory(const VehicleFactory&& other) = delete;
    VehicleFactory& operator=(const VehicleFactory& other) = delete;
    VehicleFactory& operator=(const VehicleFactory&& other) = delete;

public:
    static std::shared_ptr<VehicleFactory> build(VehicleType type);
    virtual void printVehicleData() = 0;
};

class Bike : public VehicleFactory{
public:
    Bike();
    ~Bike() = default;

    Bike(const Bike& other) = delete;
    Bike(const Bike&& other) = delete;
    Bike& operator=(const Bike& other) = delete;
    Bike& operator=(const Bike&& other) = delete;
public:
    void printVehicleData() override final;

private:
    static int s_serialNumber;
};

class Sedan : public VehicleFactory{
public:
    Sedan();
    ~Sedan() = default;

    Sedan(const Sedan& other) = delete;
    Sedan(const Sedan&& other) = delete;
    Sedan& operator=(const Sedan& other) = delete;
    Sedan& operator=(const Sedan&& other) = delete;
public:
    void printVehicleData() override final;
private:
    static int s_serialNumber;
};

class SUV : public VehicleFactory{
public:
    SUV();
    ~SUV() = default;
    
    SUV(const SUV& other) = delete;
    SUV(const SUV&& other) = delete;
    SUV& operator=(const SUV& other) = delete;
    SUV& operator=(const SUV&& other) = delete;
public:
    void printVehicleData() override final;
private:
    static int s_serialNumber;
};

class Client{
public:
    Client(VehicleType type);
    ~Client() = default;
public:
    std::shared_ptr<VehicleFactory> getVehicle() const;
private:
    std::shared_ptr<VehicleFactory> m_vehicle;
};