#define COMPONENT pr4g_er315
#define COMPONENT_BEAUTIFIED PR4G/ER315
#include "\z\acrefr\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_PR4G_ER315
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_ENABLED_PR4G_ER315
    #define DEBUG_SETTINGS DEBUG_SETTINGS_PR4G_ER315
#endif

#include "\idi\acre\addons\main\script_macros.hpp"

#undef EFUNC
#undef EGVAR
#undef QEGVAR
#define EFUNC(var1,var2) TRIPLES(DOUBLES(acre,var1),fnc,var2)
#define EGVAR(var1,var2) TRIPLES(acre,var1,var2)
#define QEGVAR(var1,var2) QUOTE(EGVAR(var1,var2))

#define ACRE_EFUNC(var1,var2) TRIPLES(DOUBLES(acre,var1),fnc,var2)
#define ACRE_EGVAR(var1,var2) TRIPLES(acre,var1,var2)
#define ACRE_QEGVAR(var1,var2) QUOTE(ACRE_EGVAR(var1,var2))

#define NAME_ER315 PR4G/ER315
#define CHANNEL_NAME_MAX_LENGTH 12
#define CHANNEL_PADDING_STRING "            " // Should be same length as CHANNEL_NAME_MAX_LENGTH

#include "\z\acrefr\addons\pr4g_er315\menus\script_menus.hpp"

#include "\idi\acre\addons\sys_components\script_acre_component_defines.hpp"
#include "\idi\acre\addons\sys_rack\script_acre_rack_defines.hpp"

#define MAX_CHANNEL 7