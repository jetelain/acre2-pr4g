#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {RADIO_WEAPON_LIST_STR(ACRE_ER314)};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"acrefr_main", "acre_sys_radio", "acre_sys_fonts"};
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
#include "er314_RadioDialog.hpp"

class CfgFontFamilies
{
	class led16sgmnt2
	{
		fonts[]=
		{
			QPATHTOF(data\led16sgmnt2\led16sgmnt26),
			QPATHTOF(data\led16sgmnt2\led16sgmnt27),
			QPATHTOF(data\led16sgmnt2\led16sgmnt28),
			QPATHTOF(data\led16sgmnt2\led16sgmnt29),
			QPATHTOF(data\led16sgmnt2\led16sgmnt210),
			QPATHTOF(data\led16sgmnt2\led16sgmnt211),
			QPATHTOF(data\led16sgmnt2\led16sgmnt212),
			QPATHTOF(data\led16sgmnt2\led16sgmnt213),
			QPATHTOF(data\led16sgmnt2\led16sgmnt214),
			QPATHTOF(data\led16sgmnt2\led16sgmnt215),
			QPATHTOF(data\led16sgmnt2\led16sgmnt216),
			QPATHTOF(data\led16sgmnt2\led16sgmnt217),
			QPATHTOF(data\led16sgmnt2\led16sgmnt218),
			QPATHTOF(data\led16sgmnt2\led16sgmnt219),
			QPATHTOF(data\led16sgmnt2\led16sgmnt220),
			QPATHTOF(data\led16sgmnt2\led16sgmnt221),
			QPATHTOF(data\led16sgmnt2\led16sgmnt222),
			QPATHTOF(data\led16sgmnt2\led16sgmnt223),
			QPATHTOF(data\led16sgmnt2\led16sgmnt224),
			QPATHTOF(data\led16sgmnt2\led16sgmnt225),
			QPATHTOF(data\led16sgmnt2\led16sgmnt226),
			QPATHTOF(data\led16sgmnt2\led16sgmnt227),
			QPATHTOF(data\led16sgmnt2\led16sgmnt228),
			QPATHTOF(data\led16sgmnt2\led16sgmnt229),
			QPATHTOF(data\led16sgmnt2\led16sgmnt230),
			QPATHTOF(data\led16sgmnt2\led16sgmnt231),
			QPATHTOF(data\led16sgmnt2\led16sgmnt234),
			QPATHTOF(data\led16sgmnt2\led16sgmnt225),
			QPATHTOF(data\led16sgmnt2\led16sgmnt237),
			QPATHTOF(data\led16sgmnt2\led16sgmnt246)
		};
	};
};