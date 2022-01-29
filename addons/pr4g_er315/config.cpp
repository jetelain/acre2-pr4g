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

class CfgVehicles {
    class Car_F;
    class MRAP_01_base_F : Car_F {
        class AcreRacks {
            class Rack_2 {
                mountedRadio = "ACRE_ER315";
            };
        };
    };
    class MRAP_02_base_F: Car_F {
        class AcreRacks {
            class Rack_2 {
                mountedRadio = "ACRE_ER315";
            };
        };
    };
    class MRAP_03_base_F: Car_F {
        class AcreRacks {
            class Rack_2 {
                mountedRadio = "ACRE_ER315";
            };
        };
    };
    class Tank;
    class Tank_F: Tank {
         class AcreRacks {
            class Rack_1 {
                mountedRadio = "ACRE_ER315";
            };
        };
    };
    class Wheeled_APC_F: Car_F {
         class AcreRacks {
            class Rack_1 {
                mountedRadio = "ACRE_ER315";
            };
        };
    };
};