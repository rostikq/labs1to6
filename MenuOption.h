//
// Created by user on 3/29/2026.
//

#ifndef LABS1TO6_MENUOPTION_H
#define LABS1TO6_MENUOPTION_H
#include <functional>
#include <string>

class Application;

struct MenuOption {
    std::string label;
    std::function<void(Application* app)> funcPtr;
    bool adminOnly = false;
};


#endif //LABS1TO6_MENUOPTION_H