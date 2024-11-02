#ifndef __TESTADAPTER_HPP__
#define __TESTADAPTER_HPP__

#include "lib/Adapter.hpp"
#include "lib/pch.hpp"

using namespace adapter;

void testAdapter(){
    std::cout << "----- TEST STRATS-----" << std::endl;
    // client can understands inputs comming from the target
    std::unique_ptr<Target> target = std::make_unique<Target>();
    adapter::Client client_1(std::move(target));
    client_1.request();

    // client cannot understand the inputs from the Adaptee because it's incompatible with client interface
     std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
    std::unique_ptr<Adapter> adapter = std::make_unique<Adapter>(std::move(adaptee));
    adapter::Client client_2(std::move(adapter));
    client_2.request();
}
#endif