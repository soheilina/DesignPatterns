#ifndef __TEST_STRATEGY__HPP
#define __TEST_STRATEGY__HPP

#include "lib/Strategy.hpp"

void testStrategy() {
    std::cout << "----- TEST STRATS-----" << std::endl;
    std::vector<int> digits{5, -8, 22, 0, 12, 193, -45, 2, -5};
    std::unique_ptr<Context<int>> digitContext = std::make_unique<Context<int>>(std::make_unique<StableSort<int>>());
    std::vector<int> sorted_digits = digitContext->executeStrategy(digits);
    std::cout << "digits sorted (stable): ";
    for(int const& i : sorted_digits){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> names{"Charlie", "Bob", "Alice", "Zoe", "Rose", "Soheil"};
    std::unique_ptr<Context<std::string>> namesContext = std::make_unique<Context<std::string>>(std::make_unique<UnstableSort<std::string>>());
    std::vector<std::string> sorted_names = namesContext->executeStrategy(names);
    std::cout << "names sorted (unstable): ";
    for(std::string const& name : sorted_names){
        std::cout << name << " ";
    }
    std::cout << std::endl;
}
#endif