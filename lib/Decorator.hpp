#ifndef __DECORATOR_HPP
#define __DECORATOR_HPP

#include "pch.hpp"

///////////////////////////////////////////////////////////////////////////////////////////
// Beverage interface (Main component)
///////////////////////////////////////////////////////////////////////////////////////////
class Beverage {
  public:
    Beverage() = default;
    virtual ~Beverage() = default;
    Beverage(Beverage const& other) = delete;
    Beverage(Beverage&& other) = delete;
    Beverage& operator=(Beverage const& other) = delete;
    Beverage& operator=(Beverage&& other) = delete;

  public:
    virtual void drink() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////
// Drinks which can be decorated (Concrete Components which are the base for decoration)
///////////////////////////////////////////////////////////////////////////////////////////
class Coffee : public Beverage {
  public:
    Coffee() = default;
    ~Coffee() noexcept = default;
    Coffee(Coffee const& other) = delete;
    Coffee(Coffee&& other) noexcept = delete;
    Coffee& operator=(Coffee const& other) = delete;
    Coffee& operator=(Coffee&& other) noexcept = delete;

  public:
    void drink() override {
        std::cout << "Drinking Coffee";
        }
};

class Soda : public Beverage {
  public:
    Soda() = default;
    ~Soda() noexcept = default;
    Soda(Soda const& other) = delete;
    Soda(Soda&& other) noexcept = delete;
    Soda& operator=(Soda const& other) = delete;
    Soda& operator=(Soda&& other) noexcept = delete;

  public:
    void drink() override {
        std::cout << "Drinking Soda";
        }
};

///////////////////////////////////////////////////////////////////////////////////////////
// Decorator (Interface)
///////////////////////////////////////////////////////////////////////////////////////////
class BeverageDecorator : public Beverage {
  public:
    BeverageDecorator(std::unique_ptr<Beverage> component)
        : m_component(std::move(component)) {}

    // decorator must be abstract, so make the function pure virtual again
    void drink() override = 0;

  protected:
    void callComponentDrink() {
        if (m_component) {
            m_component->drink();
        }
    }

  private:
    std::unique_ptr<Beverage> m_component; //store the base drink (concrete component)
};

///////////////////////////////////////////////////////////////////////////////////////////
// Concrete Decorators decorate the concrete component (i.e. the base drink)
///////////////////////////////////////////////////////////////////////////////////////////
class Milk : public BeverageDecorator {
  public:
    Milk(std::unique_ptr<Beverage> component, float percentage)
        : BeverageDecorator(std::move(component))
        , m_percentage(percentage) {}

    void drink() final {
        callComponentDrink();
        std::cout << ", with milk of richness " << m_percentage << "%";
    }

  private:
    float m_percentage;
};

class IceCubes : public BeverageDecorator {
  public:
    IceCubes(std::unique_ptr<Beverage> component, int count)
        : BeverageDecorator(std::move(component))
        , m_count(count) {}

    void drink() final {
        callComponentDrink();
        std::cout << ", with " << m_count << " ice cubes";
    }

  private:
    int m_count;
};

class Sugar : public BeverageDecorator {
  public:
    Sugar(std::unique_ptr<Beverage> component, int spoons)
        : BeverageDecorator(std::move(component))
        , m_spoons(spoons) {}

    void drink() final {
        callComponentDrink();
        std::cout << ", with " << m_spoons << " spoons of sugar";
    }

  private:
    int m_spoons = 1;
};

#endif //__DECORATOR_HPP