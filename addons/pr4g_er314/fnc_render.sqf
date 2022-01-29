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
 * [ARGUMENTS] call acre_pr4g_er314_fnc_render
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

private _knobPosition = GET_STATE_DEF("knobPosition", 3);
private _knobImageStr = [_knobPosition, 1, 0] call CBA_fnc_formatNumber;
_knobImageStr = format ["\z\acrefr\addons\pr4g_er314\Data\rework\power\er314_power_%1.paa", _knobImageStr];
TRACE_1("Setting knob image", _knobImageStr);

(_display displayCtrl ICON_KNOB) ctrlSetText _knobImageStr;
(_display displayCtrl ICON_KNOB) ctrlCommit 0;


private _volume = round ((GET_STATE("volume")) * 4);
private _volImageStr = [_volume, 1, 0] call CBA_fnc_formatNumber;
_volImageStr = format ["\z\acrefr\addons\pr4g_er314\Data\rework\volume\er314_volume_%1.paa", _volImageStr];
TRACE_1("Setting knob image", _volImageStr);

(_display displayCtrl ICON_VOL_KNOB) ctrlSetText _volImageStr;
(_display displayCtrl ICON_VOL_KNOB) ctrlCommit 0;

private _channelNumber = ((["getCurrentChannel"] call GUI_DATA_EVENT) + 1) mod (MAX_CHANNEL + 1);
private _channelImageStr = [_channelNumber, 1, 0] call CBA_fnc_formatNumber;
_channelImageStr = format ["\z\acrefr\addons\pr4g_er314\Data\rework\channel\er314_channel_%1.paa", _channelImageStr];

(_display displayCtrl ICON_CH_KNOB) ctrlSetText _channelImageStr;
(_display displayCtrl ICON_CH_KNOB) ctrlCommit 0;

true
