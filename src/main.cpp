#include "main.hpp"
#include "bsml/shared/BSML.hpp"
#include "logger.hpp"
#include "custom-types/shared/register.hpp"
#include "lapiz/shared/zenject/Zenjector.hpp"
#include "lapiz/shared/AttributeRegistration.hpp"
#include "Installers/MenuInstaller.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    getModConfig().Init(modInfo);
    ::BSML::Init();
    ::custom_types::Register::AutoRegister();
    ::Lapiz::Attributes::AutoRegister();

    getLogger().info("Installing hooks...");
    // Install our hooks (none defined yet)
    getLogger().info("Installed all hooks!");

    auto zenjector = ::Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<::RandomShit::Installers::MenuInstaller *>(::Lapiz::Zenject::Location::Menu);
}