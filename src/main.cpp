#include "main.hpp"
#include "ModConfig.hpp"

#include "ViewControllers/ModSettingsViewController.hpp"

#include "questui/shared/QuestUI.hpp"
#include "questui/shared/BeatSaberUI.hpp"

#include "GlobalNamespace/MainCamera.hpp"

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/CanvasRenderer.hpp"
#include "UnityEngine/Canvas.hpp"
#include "UnityEngine/RenderMode.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Quaternion.hpp"
#include "UnityEngine/UI/Text.hpp"



static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// hook onto the main camera setup and add a hud
MAKE_HOOK_MATCH(MainCamera, &GlobalNamespace::MainCamera::Awake, void, GlobalNamespace::MainCamera* self) {
    MainCamera(self);
    getLogger().info("MainCamera");
    if (getModConfig().HUD.GetValue()) {
        getLogger().info("HUD");

        // Add a canvas to the camera
        UnityEngine::GameObject* canvas = UnityEngine::GameObject::New_ctor();
        canvas->AddComponent<UnityEngine::CanvasRenderer*>();
        UnityEngine::Canvas* canvasComponent = canvas->AddComponent<UnityEngine::Canvas*>();
        canvasComponent->set_renderMode(UnityEngine::RenderMode::WorldSpace);
        canvasComponent->get_transform()->set_position(UnityEngine::Vector3(0.0f, 2.0f, 2.0f));
        canvasComponent->get_transform()->set_rotation(UnityEngine::Quaternion::Euler(0.0f, 180.0f, 0.0f));
        canvasComponent->get_transform()->set_localScale(UnityEngine::Vector3(0.01f, 0.01f, 0.01f));
        canvasComponent->set_sortingOrder(100);
        canvasComponent->set_pixelPerfect(false);
        canvasComponent->set_overrideSorting(true);

        canvasComponent->get_transform()->SetParent(self->get_transform(), false);

        // Add a text element to the canvas
        UnityEngine::GameObject* text = UnityEngine::GameObject::New_ctor();
        text->AddComponent<UnityEngine::CanvasRenderer*>();
        UnityEngine::UI::Text* textComponent = text->AddComponent<UnityEngine::UI::Text*>();
        textComponent->set_fontSize(100);
        textComponent->set_text("Hello World!");


        textComponent->get_transform()->SetParent(canvasComponent->get_transform(), false);

    }
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;

    getModConfig().Init(info);

    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    QuestUI::Init();

    QuestUI::Register::RegisterMainMenuModSettingsViewController(modInfo, DidActivate);

    getLogger().info("Installing hooks...");
    INSTALL_HOOK(getLogger(), MainCamera);
    getLogger().info("Installed all hooks!");
}
