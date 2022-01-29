#include "script_component.hpp"
/*
 * Author: ACRE2Team
 * SHORT DESCRIPTION
 *
 * Arguments:
 * 0: ARGUMENT ONE <TYPE>
 * 1: ARGUMENT TWO <TYPE>
 *
 * Return Value:
 * RETURN VALUE <TYPE>
 *
 * Example:
 * [ARGUMENTS] call acre_COMPONENT_fnc_FUNCTIONNAME
 *
 * Public: No
 */

DFUNC(onButtonPress_Display) = {
    TRACE_1("onButtonPress_Display", _this);
    params ["_menu", "_event"];

    private _currentSelection = GET_STATE_DEF("menuSelection", 0);
    switch (_event select 0) do {
        case '9': { // RC
            ["RC"] call FUNC(changeMenu);
        };
        case '2': { // CAN
            ["CAN"] call FUNC(changeMenu);
        };
        case '0': {
            TRACE_2("Cycling display", _currentSelection, (count MENU_SUBMENUS(_menu)));
            [MENU_SUBMENUS_ITEM(_menu, _currentSelection)] call FUNC(callCompleteFunctor);

            if (_currentSelection+1 >= (count MENU_SUBMENUS(_menu))) then {
                _currentSelection = 0;
            } else {
                _currentSelection = _currentSelection + 1;
            };

            SET_STATE("menuSelection", _currentSelection);
            [MENU_SUBMENUS_ITEM(_menu, _currentSelection)] call FUNC(callEntryFunctor);
            [MENU_SUBMENUS_ITEM(_menu, _currentSelection)] call FUNC(renderMenu_Static);
        };
        default {
            // Pass the button press along to the child menu
            [MENU_SUBMENUS_ITEM(_menu, _currentSelection)] call FUNC(onButtonPress_Static);
        };
    };

    false
};

DFUNC(renderMenu_Display) = {
    #ifdef ENABLE_PERFORMANCE_COUNTERS
        BEGIN_COUNTER(renderMenu_Display);
    #endif

    TRACE_1("renderMenu_Display", _this);
    params ["_menu"]; // the menu to render is passed
    private _displaySet = MENU_SUBMENUS(_menu);


    private _currentSelection = GET_STATE_DEF("menuSelection", 0);
    private _currentDisplay = MENU_SUBMENUS_ITEM(_menu,_currentSelection);

    // A display set has a set of children STATIC displays, which are rendered and canFire
    // be swaped with the 'NEXT' circly button thingy
    private _entry = SCRATCH_GET_DEF(GVAR(currentRadioId), "menuEntry", false);
    if (_entry) then {
        [_currentDisplay] call FUNC(callEntryFunctor);
    };

    [_currentDisplay, _menu] call FUNC(renderMenu);

    #ifdef ENABLE_PERFORMANCE_COUNTERS
        END_COUNTER(renderMenu_Display);
    #endif
};
