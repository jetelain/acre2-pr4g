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

GVAR(CAN) = ["CAN", "CAN", "",
    MENUTYPE_ACTIONSERIES,
    [
        [nil, "CHANNEL", "",
            MENUTYPE_NUMBER,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "CANAL   %1"]
            ],
            [
                {
                    private _value = ((["getCurrentChannel"] call GUI_DATA_EVENT) + 1) mod 7;
                    SCRATCH_SET(GVAR(currentRadioId), "menuNumber", _value);
                },   // onEntry
                nil, // onExit. Our parent static display generic event handler handles the 'Next' key
                nil  // We've implemented dynamic button press handlers for static displays
            ],
            [
                0, // min number/start default
                6, // Max number
                1, // Digit count
                [ROW_XXLARGE_1, 0, 1] // Highlighting cursor information
            ],
            "pgm_can"
        ]
    ],
    [nil, nil],
    {
        private _channelNumber = GET_STATE("pgm_can");
        if ( !isNil "_channelNumber") then {
            if ( _channelNumber == 0 ) then { _channelNumber = 7; };
            ["setCurrentChannel", _channelNumber - 1] call GUI_DATA_EVENT;
        };
        SET_STATE("pgm_can", nil);
        false
    },
    "VULOSHOME"
];
[GVAR(CAN)] call FUNC(createMenu);
