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
 * [ARGUMENTS] call acre_pr4g_er328_fnc_defaultButtonPress
 *
 * Public: No
 */

params ["_menu", "_event"];

private _ret = false;

private _dir = _event select 2;
if (_dir == 0) then {
    _dir = 1;
} else {
    if (_dir == 1) then {
        _dir = -1;
    };
};

private _display = uiNamespace getVariable [QGVAR(currentDisplay), displayNull];
TRACE_2("defaultButtonPress", _display, _event);
switch (_event select 0) do {
    case 'KNOB': {
        // Knob was clicked
        private _volume = GET_STATE("volume");
        private _knobPositionOld = GET_STATE_DEF("knobPosition", ceil ((_volume / 0.2) + 1));
        TRACE_2("Knob Press", _knobPositionOld, _dir);

        ///////////////////////
        private _knobPosition = _knobPositionOld + _dir;
        if (_knobPosition > 6) then {
            _knobPosition = 6;
        };
        if (_knobPosition < 0) then {
            _knobPosition = 0;
        };

        TRACE_1("New knob position", _knobPosition);
        SET_STATE("knobPosition", _knobPosition);

        _this call FUNC(changeMode);
    };
};

_ret
