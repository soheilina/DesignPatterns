#ifndef __TEST_DECORATOR__HPP
#define __TEST_DECORATOR__HPP

#include "lib/Decorator.hpp"

void testDecorator() {
    std::cout << "----- TEST STRATS-----" << std::endl;
    // decorate a drink based on soda
    std::unique_ptr<Beverage> soda = std::make_unique<Soda>();
    soda = std::make_unique<IceCubes>(std::move(soda), 3);
    soda = std::make_unique<Sugar>(std::move(soda), 1);
    // serve the drink
    soda->drink();
    std::cout << std::endl;

    // decorate a drink based on coffee
    std::unique_ptr<Beverage> coffee = std::make_unique<Coffee>();
    coffee = std::make_unique<IceCubes>(std::move(coffee), 16);
    coffee = std::make_unique<Milk>(std::move(coffee), 3.);
    coffee = std::make_unique<Sugar>(std::move(coffee), 2);
    // serve the drink
    coffee->drink();
    std::cout << std::endl;
}
#endif