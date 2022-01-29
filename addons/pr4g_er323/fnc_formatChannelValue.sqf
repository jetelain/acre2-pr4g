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
 * [ARGUMENTS] call acre_pr4g_er323_fnc_formatChannelValue
 *
 * Public: No
 */

params ["_name", "_value"];

#define GET_RADIO_VALUE(x) [x] call FUNC(CURRENT_RADIO_VALUE)
#define GET_CHANNEL_DATA() [] call FUNC(CURRENT_RADIO_CHANNEL);

#define SQUELCH_OFF 0
#define SQUELCH_ON 1

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
            case "BASIC": { _value = "NORM"; }
        };
    };
    case "squelch": {
        private _channel = GET_CHANNEL_DATA();
        private _ctcss = HASH_GET(_channel, "CTCSSRx");

        if (_value > 0) then {
            _value = "TONE";
            if (_ctcss != 150) then {
                _value = "TCS";
            };
            if (_ctcss == 0) then {
                _value = "NOISE";
            };
        } else {
            _value = "OFF";
        };
    };
};

if !(_value isEqualType "") then {
    _value = format["%1", _value];
};
TRACE_1("Output", _value);

_value
