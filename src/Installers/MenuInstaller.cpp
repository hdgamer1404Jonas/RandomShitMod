#include "Installers/MenuInstaller.hpp"

#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

#include "Zenject/DiContainer.hpp"
#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

#include "UI/SettingsUI.hpp"
#include "UI/FlowCoordinators/SettingsFlowCoordinator.hpp"
#include "UI/ViewControllers/SettingsViewController.hpp"

DEFINE_TYPE(RandomShit::Installers, MenuInstaller);

using namespace Lapiz::Zenject::ZenjectExtensions;

namespace RandomShit::Installers {
    void MenuInstaller::InstallBindings() {
        auto container = get_Container();

        FromNewComponentAsViewController(
                container->Bind<::RandomShit::UI::ViewControllers::SettingsViewController *>())->AsSingle();

        container->BindInterfacesAndSelfTo<::RandomShit::UI::SettingsUI *>()->AsSingle();

        FromNewComponentOnNewGameObject(
                container->BindInterfacesAndSelfTo<::RandomShit::UI::FlowCoordinators::SettingsFlowCoordinator *>()
        )->AsSingle();
    }
}