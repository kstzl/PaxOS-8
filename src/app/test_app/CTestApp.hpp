//
// Created by Kevin on 15/12/2023.
//

#ifndef PAXOS_CTESTAPP_HPP
#define PAXOS_CTESTAPP_HPP

#include <iostream>

#include "../CApp.hpp"

namespace paxos {

    class CTestApp: public CApp
    {
    public:
        const char* getAppPath() override { return "TEST_APP"; }
        const char* getAppName() override { return "Application de test"; }

        void init() override
        {
            std::cout << "Init !" << getAppName() << std::endl;
        }
        void update() override
        {
            std::cout << "Update !" << std::endl;
        }
    };

}

#endif //PAXOS_CTESTAPP_HPP
