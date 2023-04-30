#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig, CONFIG_VALUE(rotateCamEnabled, bool, "rotateCamEnabled", false);
                          CONFIG_VALUE(noHealthAndSafety, bool, "noHealthAndSafety", true);)