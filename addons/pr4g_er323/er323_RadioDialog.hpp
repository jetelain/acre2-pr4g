class ER323_RadioDialog {
    idd = 31337;
    MovingEnable = 0;
    onUnload = QUOTE(['closeGui'] call GUI_INTERACT_EVENT);
    onLoad = QUOTE(_this call FUNC(render));
    controlsBackground[] = {ER323Background};
    objects[] = {};

    class ER323Background: ER323_RscBackground {
        type = CT_STATIC;
        idc = -1;
        style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = "led16sgmnt2";
        sizeEx = 0.03;
        x = SafeZoneX;
        y= (0.5-((1*safezoneW)/2));
        w = 1*SafeZoneW;
        h = 1*SafeZoneW;
        text = QPATHTOF(Data\rework\er323_ui.paa);
    };
    class controls {

        BEGIN_CONTROL(DisplayBackground, ER323_RscBackground, 99990)
            style = 0x800;
            x = ((0.33 * safeZoneW) + safeZoneX);
            y = ((0.392 * safeZoneW) + safeZoneX);
            w = ((0.00438 * 32) + 0.0043)*SafeZoneW;
            h = ((0.011 * 4) + 0.011)*SafeZoneW;
            colorBackground[] = {0.9, 0.96, 0.2, 0};
            text = "";
        END_CONTROL

        TEXT_ROW_XXLARGE(41, ROW_XXLARGE_X, ROW_XXLARGE_Y, 0, ROW_XXLARGE_W, ROW_XXLARGE_H, ROW_XXLARGE_OFFX, ROW_XXLARGE_OFFY, ROW_XXLARGE_FONT_SIZE)

        BEGIN_CONTROL(MODE_ICON, ER323_RscPicture, 99901)
            x = SafeZoneX;
            y= (0.5-((1*safezoneW)/2));
            w = 1*SafeZoneW;
            h = 1*SafeZoneW;
            colorText[] = {1,1,1,1};
            text = QPATHTOF(Data\rework\power\er323_power_1.paa);
        END_CONTROL

        BEGIN_CONTROL(MODE_KNOB, ER323_RscButton, 99902+222)
            x = (0.4008 * safeZoneW) + safeZoneX;
            y = (0.4574 * safeZoneW) + safeZoneX;
            w = (0.03775 * SafeZoneW);
            h = (0.05034 * SafeZoneW);
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['MODE_KNOB'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(CHANNEL_ICON, ER323_RscPicture, 99803)
            x = SafeZoneX;
            y= (0.5-((1*safezoneW)/2));
            w = 1*SafeZoneW;
            h = 1*SafeZoneW;
            colorText[] = {1,1,1,1};
            text = QPATHTOF(Data\rework\channel\er323_channel_1.paa);
        END_CONTROL

        BEGIN_CONTROL(CHANNEL_KNOB, ER323_RscButton, 99804)
            x = (0.4024 * safeZoneW) + safeZoneX;
            y = (0.5083 * safeZoneW) + safeZoneX;
            w = (0.03775 * SafeZoneW);
            h = (0.05034 * SafeZoneW);
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['CHANNEL_KNOB'] + _this) call FUNC(onButtonPress));
        END_CONTROL


        BEGIN_CONTROL(BUTTON_ICON, ER323_RscPicture, 1000)
            x = SafeZoneX;
            y= (0.5-((1*safezoneW)/2));
            w = 1*SafeZoneW;
            h = 1*SafeZoneW;
            colorText[] = {1,1,1,1};
            text = QPATHTOF(Data\rework\er323_ui_keys_default.paa);
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ZERO, ER323_RscButton, 99902+100)
            BUTTON_GRID(3,0);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['0'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ONE, ER323_RscButton, 99902+101)
            BUTTON_GRID(0,2);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['1'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_TWO, ER323_RscButton, 99902+102)
            BUTTON_GRID(1,2);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['2'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_THREE, ER323_RscButton, 99902+103)
            BUTTON_GRID(2,2);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['3'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_FOUR, ER323_RscButton, 99902+104)
            BUTTON_GRID(0,1);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['4'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_FIVE, ER323_RscButton, 99902+105)
            BUTTON_GRID(1,1);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['5'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_SIX, ER323_RscButton, 99902+106)
            BUTTON_GRID(2,1);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['6'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_SEVEN, ER323_RscButton, 99902+107)
            BUTTON_GRID(0,0);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['7'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_EIGHT, ER323_RscButton, 99902+108)
            BUTTON_GRID(1,0);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['8'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_NINE, ER323_RscButton, 99902+109)
            BUTTON_GRID(2,0);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['9'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_LEFT, ER323_RscButton, 99902+112)
            BUTTON_GRID(4,0);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['FORWARDX'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_RIGHT, ER323_RscButton, 99902+113)
            BUTTON_GRID(4,1);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['BACK'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_CLR, ER323_RscButton, 99902+114)
            BUTTON_GRID(3,1);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['RC'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ENT, ER323_RscButton, 99902+115)
            BUTTON_GRID(3,2);
            BUTTONSIZE;
            text = "";
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['VAL'] + _this) call FUNC(onButtonPress));
        END_CONTROL

    };
};
