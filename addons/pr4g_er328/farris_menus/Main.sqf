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

GVAR(OFF) = ["OFF", "OFF", "", MENUTYPE_STATIC, [],[ nil,nil, nil ] ];
[GVAR(OFF)] call FUNC(createMenu);

GVAR(INVALID_MODE) = ["INVALID_MODE", "INVALID_MODE", "",
    MENUTYPE_STATIC,
    [
        [ROW_XXLARGE_1, ALIGN_LEFT, "INVALID MODE"]
    ],
    [
        nil, // onEntry
        nil, // onExit
        nil
    ]
];
[GVAR(INVALID_MODE)] call FUNC(createMenu);

GVAR(VULOSHOME) = ["VULOSHOME", "VULOSHOME", "",
    MENUTYPE_DISPLAY,
    [
        ["VULOSHOME-MAIN", "VULOSHOME-MAIN", "",
            MENUTYPE_STATIC,
            [
                [ROW_XXLARGE_1, ALIGN_LEFT, "RC  $cch-frequencyrx"]
            ],
            [
                nil,
                nil,
                nil,
                {
                    [ICON_LOADING, false] call DFUNC(toggleIcon);
                }
            ]
        ]
    ],
    nil
];
[GVAR(VULOSHOME)] call FUNC(createMenu);
