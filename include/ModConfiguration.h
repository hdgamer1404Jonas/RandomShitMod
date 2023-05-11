#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig, CONFIG_VALUE(rotateCamEnabled, bool, "rotateCamEnabled", false);
                          CONFIG_VALUE(quotes, bool, "quotes", false);
                          CONFIG_VALUE(gptToken, std::string, "gptToken", "");
                          )