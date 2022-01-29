#include "script_component.hpp"
//#define DEBUG_MODE_FULL

DFUNC(Loading_Next) = {
    params ["_radioId"];
    // Turn the radio on
    [_radioId, "setOnOffState", 1] call EFUNC(sys_data,dataEvent);
    if (_radioId isEqualTo GVAR(currentRadioId)) then {
        [GVAR(LOADING), ["0"]] call DFUNC(onButtonPress_Display);
    };
};

DFUNC(Loading_Done) = {
    params ["_radioId"];
    // Turn the radio on
    [_radioId, "setOnOffState", 1] call EFUNC(sys_data,dataEvent);
    if (_radioId isEqualTo GVAR(currentRadioId)) then {
        private _currentMenu = GET_STATE_DEF("currentHome", GVAR(VULOSHOME));
        [_currentMenu] call FUNC(changeMenu);
    };
};

GVAR(LOADING) = ["LOADING", "LOADING", "",
    MENUTYPE_DISPLAY,
    [
        ["LOADING-STAGE-1", "LOADING-STAGE-1", "",
            MENUTYPE_STATIC,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "¤¤¤¤¤¤¤¤¤"]
            ],
            [
                {
                    private _radioId = GVAR(currentRadioId);
                    // Turn the radio on
                    [_radioId, "setOnOffState", 0.5] call EFUNC(sys_data,dataEvent);

                    TRACE_1("Registering function","");
                    [GVAR(currentRadioId), DFUNC(Loading_Next), 1] call DFUNC(delayFunction);
                }, // onEntry
                nil,  // onExit. Our parent static display generic event handler handles the 'Next' key
                { true },
                {
                    TRACE_1("Rendering LOADING-STAGE-1","");
                }
            ]
        ],
        ["LOADING-STAGE-2", "LOADING-STAGE-2", "",
            MENUTYPE_STATIC,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "ER65.8E-S"]
            ],
            [
                {[GVAR(currentRadioId), DFUNC(Loading_Next), 2] call DFUNC(delayFunction);}, // onEntry
                nil, // onExit
                { true },
                {}
            ]
        ],
        ["LOADING-STAGE-3", "LOADING-STAGE-3", "",
            MENUTYPE_STATIC,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "TEST  ..."]
            ],
            [
                {[GVAR(currentRadioId), DFUNC(Loading_Next), 5] call DFUNC(delayFunction);}, // onEntry
                nil, // onExit
                { true },
                {}
            ]
        ],
        ["LOADING-STAGE-4", "LOADING-STAGE-4", "",
            MENUTYPE_STATIC,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "GO REC"]
            ],
            [
                {[GVAR(currentRadioId), DFUNC(Loading_Done), 1] call DFUNC(delayFunction);}, // onEntry
                nil, // onExit
                { true },
                {}
            ]
        ]
    ],
    nil
];
[GVAR(VULOSHOME)] call FUNC(createMenu);
