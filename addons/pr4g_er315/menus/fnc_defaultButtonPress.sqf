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
 * [ARGUMENTS] call acre_pr4g_er315_fnc_defaultButtonPress
 *
 * Public: No
 */

params ["_menu", "_event"];

private _ret = false;


private _display = uiNamespace getVariable [QGVAR(currentDisplay), displayNull];
TRACE_2("defaultButtonPress", _display, _event);
switch (_event select 0) do {
    case 'VOLUME_KNOB': {
        private _volume = (round ((GET_STATE("volume")) * 4)) / 4;
        private _dir = _event select 2;
        if (_dir == 0) then {
            _volume = _volume + 0.25;
        } else {
            if (_dir == 1) then {
                _volume = _volume - 0.25;
            };
        };
        if (_volume > 1) then {
            _volume = 1.0;
        };
        if (_volume < 0) then {
            _volume = 0.0;
        };
        ["setVolume", _volume] call GUI_DATA_EVENT;
    };
    case 'CHANNEL_KNOB': {
        private _channelNumber = ((["getCurrentChannel"] call GUI_DATA_EVENT) + 1) mod (MAX_CHANNEL + 1);
        private _dir = _event select 2;
        if (_dir == 0) then {
            _channelNumber = _channelNumber + 1;
        } else {
            if (_dir == 1) then {
                _channelNumber = _channelNumber - 1;
            };
        };
        if (_channelNumber > MAX_CHANNEL) then {
            _channelNumber = MAX_CHANNEL;
        };
        if (_channelNumber < 0) then {
            _channelNumber = 0;
        };
        ["setCurrentChannel", (_channelNumber + MAX_CHANNEL) mod (MAX_CHANNEL + 1)] call GUI_DATA_EVENT;
    };
    case 'MODE_KNOB': {
        // Knob was clicked
        private _knobPositionOld = GET_STATE_DEF("knobPosition", 3);
        private _dir = _event select 2;
        if (_dir == 0) then {
            _dir = 1;
        } else {
            if (_dir == 1) then {
                _dir = -1;
            };
        };
        TRACE_2("Knob Press", _knobPositionOld, _dir);

        ///////////////////////
        private _knobPosition = _knobPositionOld + _dir;
        if (_knobPosition > 4) then {
            _knobPosition = 4;
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
