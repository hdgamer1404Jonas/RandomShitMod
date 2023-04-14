#pragma once

// Include the modloader header, which allows us to tell the modloader which mod this is, and the version etc.
#include "modloader/shared/modloader.hpp"

// Include config-utils, which allows us to easily create and read configuration files
#include "config-utils/shared/config-utils.hpp"

// Quest and BS UI includes
#include "questui/shared/QuestUI.hpp"

// beatsaber-hook is a modding framework that lets us call functions and fetch field values from in the game
// It also allows creating objects, configuration, and importantly, hooking methods to modify their values
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"


// Include project headers
#include "ModConfiguration.h"

// Define these functions here so that we can easily read configuration and log information from other files
Configuration& getConfig();
Logger& getLogger();