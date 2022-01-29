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

#define GET_RADIO_VALUE(x) [x] call FUNC(CURRENT_RADIO_VALUE)
#define GET_CHANNEL_DATA() [] call FUNC(CURRENT_RADIO_CHANNEL);

DFUNC(CURRENT_RADIO_VALUE) = {
    private _channelNumber = ["getCurrentChannel"] call GUI_DATA_EVENT;
    private _channels = GET_STATE("channels");
    private _channel = HASHLIST_SELECT(_channels, _channelNumber);
    private _value = HASH_GET(_channel, (_this select 0));
    _value
};
DFUNC(CURRENT_RADIO_CHANNEL) = {
    private _channelNumber = ["getCurrentChannel"] call GUI_DATA_EVENT;
    private _channels = GET_STATE("channels");
    private _channel = HASHLIST_SELECT(_channels, _channelNumber);
    _channel
};

GVAR(RC) = ["RC", "RC", "",
    MENUTYPE_ACTIONSERIES,
    [
        [nil, "FREQUENCY", "",
            MENUTYPE_NUMBER,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "RC  %1"]
            ],
            [
                {
                    private _value = GET_RADIO_VALUE("frequencyRX");
                    SCRATCH_SET(GVAR(currentRadioId), "menuNumber", _value * 1000);
                }, // onEntry
                nil,  // onExit. Our parent static display generic event handler handles the 'Next' key
                nil     // We've implemented dynamic button press handlers for static displays
            ],
            [
                30000,  // min number/start default
                87975,  // Max number
                5,    // Digit count
                [ROW_XXLARGE_1, 0, 1] // Highlighting cursor information
            ],
            "pgm_freq"
        ]
    ],
    [nil, nil],
    {
        private _freq = GET_STATE("pgm_freq");
        if ( !isNil "_freq") then {
            private _channelNumber = ["getCurrentChannel"] call GUI_DATA_EVENT;
            private _channels = GET_STATE("channels");
            private _channel = HASHLIST_SELECT(_channels, _channelNumber);
            HASH_SET(_channel, "frequencyRX", _freq / 1000);
            HASH_SET(_channel, "frequencyTX", _freq / 1000);
            HASHLIST_SET(_channels, _channelNumber, _channel);
            SET_STATE("channels", _channels);
        };
        SET_STATE("pgm_freq", nil);
        false
    },
    "VULOSHOME"
];
[GVAR(RC)] call FUNC(createMenu);
