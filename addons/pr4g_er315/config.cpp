#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {RADIO_WEAPON_LIST_STR(ACRE_ER315)};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"acrefr_main", "acre_sys_radio", "acre_sys_fonts", "acre_sys_rack"};
        author = ECSTRING(main,Author);
        authors[] = {"Jaynus", "Nou", "GrueArbre", "Starlight"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

PRELOAD_ADDONS;

#include "CfgWeapons.hpp"
#include "CfgAcreRadios.hpp"
#include "CfgEventHandlers.hpp"
#include "DialogDefines.hpp"
#include "RadioDialogClasses.hpp"
#include "er315_RadioDialog.hpp"
