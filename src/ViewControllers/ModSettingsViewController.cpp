#include "ViewControllers/ModSettingsViewController.hpp"

#include "HMUI/Touchable.hpp"
#include "questui/shared/BeatSaberUI.hpp"

#include "ModConfig.hpp"

using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace HMUI;

void DidActivate(ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    if(firstActivation) {
        self->get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(self->get_transform());
        Transform* parent = container->get_transform();
        auto layout = BeatSaberUI::CreateVerticalLayoutGroup(parent);
        layout->set_spacing(0.4f);

        AddConfigValueToggle(parent, getModConfig().Enabled);
        AddConfigValueToggle(parent, getModConfig().HUD);
    }
}