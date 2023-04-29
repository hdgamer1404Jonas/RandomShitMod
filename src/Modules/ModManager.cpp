#include "Modules/ModManager.hpp"
#include "logger.hpp"

ModManager::ModManager(std::string modName) {
    this->_modName = modName;
    getLogger().info("ModManager for %s initialized", modName.c_str());
}

void ModManager::setActiveScene(std::string sceneName) {
    this->_activeSceneName = sceneName;
    getLogger().info("Active scene set to %s", sceneName.c_str());
}

void ModManager::onSceneChange(UnityEngine::SceneManagement::Scene previousActiveScene, UnityEngine::SceneManagement::Scene newActiveScene) {
    getLogger().info("Scene changed: %s -> %s", to_utf8(csstrtostr(previousActiveScene.get_name())).c_str(), to_utf8(csstrtostr(newActiveScene.get_name())).c_str());
}