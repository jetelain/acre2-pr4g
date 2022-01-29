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
 * [ARGUMENTS] call acre_pr4g_er328_fnc_formatChannelValue
 *
 * Public: No
 */

params ["_name","_value"];

#define SQUELCH_CTCSS 3

TRACE_1("Formatting", _this);

switch _name do {
    case "frequency": {
        _value = [_value * 1000, 5] call CBA_fnc_formatNumber;
    };
    case "frequencytx": {
        _value = [_value * 1000, 5] call CBA_fnc_formatNumber;
    };
    case "frequencyrx": {
        _value = [_value * 1000, 5] call CBA_fnc_formatNumber;
    };
    case "encryption": {
        if (_value > 1) then { _value = "CT"; } else { _value = "PT"; };
    };
    case "channelMode": {
        switch _value do {
            case "BASIC": { _value = "VULOS"; }
        };
    };
    case "squelch": {
        switch _value do {
            case SQUELCH_CTCSS: { _value = "TCS"; }
        };
    };
};

if !(_value isEqualType "") then {
    _value = format["%1", _value];
};
TRACE_1("Output", _value);

_value

