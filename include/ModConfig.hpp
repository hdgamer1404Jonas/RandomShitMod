#pragma once
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
                CONFIG_VALUE(Enabled, bool, "Enabled", true);
                CONFIG_VALUE(HUD, bool, "Player HUD", true);


                CONFIG_INIT_FUNCTION(
                        CONFIG_INIT_VALUE(Enabled);
                        CONFIG_INIT_VALUE(HUD);

                ))