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
#include "script_component.hpp"

DFUNC(onButtonPress_List) = {
//    TRACE_1("onButtonPress_List", _this);
    params ["_menu", "_event"];

    private _currentSelection = GET_STATE_DEF("menuSelection", 0);
    private _selectedMenu = MENU_SUBMENUS_ITEM(_menu, _currentSelection);
    TRACE_3("", _currentSelection, _selectedMenu, _menu);
    switch (_event select 0) do {
        case 'VAL': {
            [_selectedMenu, _menu] call FUNC(changeMenu);
        };
        case 'RC': {
            // Back out of the menu back to the root menu of this menu...confusing right?
            private _homeDisplay = GET_STATE_DEF("currentHome", GVAR(VULOSHOME));
            [_homeDisplay] call FUNC(changeMenu);
        };
        case 'FORWARDX': {
            TRACE_1("Enter LEFT", _currentSelection);
            if (_currentSelection > 0 ) then {
                _currentSelection = _currentSelection - 1;
            };
        };
        case 'BACK': {
            TRACE_1("Enter RIGHT", _currentSelection);
            if (_currentSelection+1 < (count MENU_SUBMENUS(_menu) )) then {
                _currentSelection = _currentSelection + 1;
            };
        };
        default {
            //diag_log text format["!!! UNHANDLED KEY FOR LIST"];
        };
    };

    SET_STATE("menuSelection", _currentSelection);

    false
};

