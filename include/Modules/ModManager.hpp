#include <iostream>

#include "UnityEngine/SceneManagement/SceneManager.hpp"
#include "UnityEngine/SceneManagement/Scene.hpp"

#ifndef RANDOMSHIT_MODMANAGER_HPP
#define RANDOMSHIT_MODMANAGER_HPP

class ModManager {

    public:
        ModManager(std::string modName);
        void setActiveScene(std::string sceneName);
        void onSceneChange(UnityEngine::SceneManagement::Scene previousActiveScene, UnityEngine::SceneManagement::Scene newActiveScene);

    private:
        std::string _modName;
        std::string _activeSceneName;

};

#endif //RANDOMSHIT_MODMANAGER_HPP
