//
// Created by Kevin on 15/12/2023.
//

#ifndef PAXOS_CAPP_HPP
#define PAXOS_CAPP_HPP

#include <memory>

namespace paxos {

    class CApp
    {
    public:
        virtual ~CApp() = default;
        virtual const char* getAppPath() = 0;
        virtual const char* getAppName() = 0;
        virtual void init() = 0;
        virtual void update() = 0;
    };

    // CApp Unique Ptr
    using AppUniquePtr = std::unique_ptr<CApp>;

} // paxos

#endif //PAXOS_CAPP_HPP
