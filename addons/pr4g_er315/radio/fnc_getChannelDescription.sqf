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
 * [ARGUMENTS] call acre_pr4g_er315_fnc_getChannelDescription
 *
 * Public: No
 */

params ["_radioId"];

private _channelNumber = [_radioId, "getCurrentChannel"] call EFUNC(sys_data,dataEvent);
private _channels = [_radioId, "getState", "channels"] call EFUNC(sys_data,dataEvent);
private _channel = HASHLIST_SELECT(_channels, _channelNumber);

private _frequencyTX = HASH_GET(_channel, "frequencyTX");

format ["%1 - RC %2", 
	[" 1"," 2"," 3"," 4"," 5"," 6"," 0", "RG"] select _channelNumber, 
	[_frequencyTX, 2, 3] call CBA_fnc_formatNumber]
