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
 * [ARGUMENTS] call acre_pr4g_er328_fnc_setVolume
 *
 * Public: No
 */

params ["_radioId", "", "_eventData", "_radioData"];

private _vol = _eventData;

if (_vol % 0.10 != 0) then {
    _vol = _vol - (_vol % 0.10);
};

HASH_SET(_radioData, "volume", _eventData);

TRACE_3("VOLUME SET",_radioId, _vol, _radioData);
