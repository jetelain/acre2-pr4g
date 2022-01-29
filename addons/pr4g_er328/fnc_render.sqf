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
 * [ARGUMENTS] call acre_pr4g_er328_fnc_render
 *
 * Public: No
 */

private ["_display"];
if !(_this isEqualTo []) then {
    _display = _this select 0;
    uiNamespace setVariable [QGVAR(currentDisplay), _display];
} else {
    _display = uiNamespace getVariable [QGVAR(currentDisplay), displayNull];
};

private _volume = GET_STATE("volume");
private _knobPosition = GET_STATE_DEF("knobPosition", ceil ((_volume / 0.2) + 1));
//private _knobImageStr = [_knobPosition, 1, 0] call CBA_fnc_formatNumber;
//_knobImageStr = format ["\z\acrefr\addons\pr4g_er328\Data\knobs\channelknob\ER328_ui_knob_%1.paa", _knobImageStr];
//TRACE_1("Setting knob image", _knobImageStr);

//(_display displayCtrl ICON_KNOB) ctrlSetText _knobImageStr;
(_display displayCtrl (99902+116)) ctrlSetTooltip (['Off', format ["Volume %1%2", (_knobPosition-1) * 20, "%"]] select (_knobPosition != 0));
(_display displayCtrl ICON_KNOB) ctrlCommit 0;

true
