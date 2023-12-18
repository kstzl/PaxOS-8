//
// Created by Kevin on 17/12/2023.
//

#ifndef CSOLLUAAPP_HPP
#define CSOLLUAAPP_HPP

#include <sol/sol.hpp>

#include "CApp.hpp"

class CSolLuaApp : public CApp
{
public:
    [[nodiscard]] const char* getAppName() const override
    {
        return m_luaAppName.c_str();
    }

    [[nodiscard]] std::string getAppBasePath() const override
    {
        std::string appBasePath;
        appBasePath += "apps/lua/";
        appBasePath += getAppName();
        appBasePath += "/";
        return appBasePath;
    }

    void initializeLuaApp(const std::string& luaAppName)
    {
        m_luaAppName = luaAppName;
    }

    void execute() override
    {
        sol::state luaState;
        luaState.open_libraries(sol::lib::base);
        luaState.script_file("./storage/" + getAppBasePath() + "main.lua");

        // UserType
        luaState.new_usertype<Window>(
            "Window",
            sol::constructors<Window(std::string)>(),
            "updateAll", &Window::updateAll,
            "addChild", &Window::addChild
        );

        luaState.new_usertype<Label>(
            "Label",
            sol::constructors<Label(int16_t, int16_t, int16_t, int16_t)>(),
            "setText", &Label::setText
        );

        luaState.new_usertype<Button>(
            "Button",
            sol::constructors<Button(int16_t, int16_t, int16_t, int16_t)>(),
            "getParent", &Button::getParent
        );


        // Setup
        luaState["onSetup"]();

        // -----------
        while(!home_button::isPressed()) {
            luaState["onLoop"]();
            SDL_Delay(20);
        }

    }

private:
    std::string m_luaAppName;
    inline static Window* spCurrentRoot = nullptr;
};



#endif //CSOLLUAAPP_HPP
