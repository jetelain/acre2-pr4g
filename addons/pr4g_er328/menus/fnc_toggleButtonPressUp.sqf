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
 * [ARGUMENTS] call acre_pr4g_er328_fnc_toggleButtonPressUp
 *
 * Public: No
 */

private _display = uiNamespace getVariable [QGVAR(currentDisplay), displayNull];
if (isNull _display) exitWith {};

private _iconcontrol = 1000;
private _knobImageStr = QPATHTOF(Data\rework\er350_keyb_base.paa);
(_display displayCtrl _iconcontrol) ctrlSetText _knobImageStr;
SET_STATE("pressedButton",-1);
