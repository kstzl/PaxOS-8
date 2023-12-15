//
// Created by Kevin on 15/12/2023.
//

#ifndef PAXOS_CAPPMANAGER_HPP
#define PAXOS_CAPPMANAGER_HPP

#include <unordered_set>

#include "CApp.hpp"

namespace paxos {

    class CAppManager
    {
    public:
        static CAppManager& getInstance()
        {
            static CAppManager instance;
            return instance;
        }

        template <typename T>
        static void registerApp()
        {
            CAppManager::getInstance().m_apps.insert(std::make_unique<T>());
        }

        static const std::unordered_set<AppUniquePtr>& getApps()
        {
            return getInstance().m_apps;
        }

        template <typename T>
        static void launchAppByType()
        {
            auto& apps = CAppManager::getApps();

            for (const auto& app : apps)
            {
                if (T* pSpecificApp = dynamic_cast<T*>(app.get()))
                    pSpecificApp->init();
            }
        }

    private:
        std::unordered_set<AppUniquePtr> m_apps;
    };

} // paxos

#endif //PAXOS_CAPPMANAGER_HPP
