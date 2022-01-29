class ER328_RadioDialog {
    idd = 31337;
    MovingEnable = 0;
    onUnload = QUOTE(['closeGui'] call GUI_INTERACT_EVENT);
    onLoad = QUOTE(_this call FUNC(render));
    controlsBackground[] = {ER328Background};
    objects[] = {};

    class ER328Background: ER328_RscBackground {
        type = CT_STATIC;
        idc = -1;
        style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = "led16sgmnt2";
        sizeEx = 0.03;
        x = ((0.5-(NEW_SCALE*(safeZoneH)/2)));
        y = ((0.5-(NEW_SCALE*(safeZoneH)/2)));
        w = NEW_SCALE*safeZoneH;
        h = NEW_SCALE*safeZoneH;
        text = QPATHTOF(Data\rework\er350_ui.paa);
    };
    class controls {

        TEXT_ROW_XXLARGE(41, ROW_XXLARGE_X, ROW_XXLARGE_Y, 0, ROW_XXLARGE_W, ROW_XXLARGE_H, ROW_XXLARGE_OFFX, ROW_XXLARGE_OFFY, ROW_XXLARGE_FONT_SIZE)

        BEGIN_CONTROL(BUTTON_ICON, ER328_RscPicture, 1000)
            x = ((0.5-(NEW_SCALE*(safeZoneH)/2)));
            y = ((0.5-(NEW_SCALE*(safeZoneH)/2)));
            w = NEW_SCALE*safeZoneH;
            h = NEW_SCALE*safeZoneH;
            colorText[] = {1,1,1,1};
            text = QPATHTOF(Data\rework\er350_keyb_base.paa);
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ONE, ER328_RscButton, 99902+101)
            BUTTON_GRID(0,0);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['1'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_TWO, ER328_RscButton, 99902+102)
            BUTTON_GRID(1,0);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['2'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_THREE, ER328_RscButton, 99902+103)
            BUTTON_GRID(2,0);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['3'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_FOUR, ER328_RscButton, 99902+104)
            BUTTON_GRID(0,1);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['4'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_FIVE, ER328_RscButton, 99902+105)
            BUTTON_GRID(1,1);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['5'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_SIX, ER328_RscButton, 99902+106)
            BUTTON_GRID(2,1);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['6'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_SEVEN, ER328_RscButton, 99902+107)
            BUTTON_GRID(0,2);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['7'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_EIGHT, ER328_RscButton, 99902+108)
            BUTTON_GRID(1,2);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['8'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_NINE, ER328_RscButton, 99902+109)
            BUTTON_GRID(2,2);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['9'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ZERO, ER328_RscButton, 99902+100)
            BUTTON_GRID(1,3);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['0'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_ENT, ER328_RscButton, 99902+111)
            BUTTON_GRID(2,3);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['VAL'] + _this) call FUNC(onButtonPress));
        END_CONTROL

        BEGIN_CONTROL(BUTTON_FORWARDX, ER328_RscButton, 99902+114)
            BUTTON_GRID(0,3);
            BUTTONSIZE;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            onMouseButtonUp = QUOTE((['FORWARDX'] + _this) call FUNC(onButtonPress));
        END_CONTROL


        BEGIN_CONTROL(KNOB_BUTTON, ER328_RscButton, 99902+116)
            x = ((((0.2929)*SCALE) * safeZoneH) + safeZoneY);
            y = ((((0.09)*SCALE) * safeZoneH)  + safeZoneY);
            w = SCALE*0.085*safeZoneH;
            h = SCALE*0.027*safeZoneH;
            sizeEx = 0.014;
            color[] = {1,1,1,0};
            // colorBackground[] = {1,1,1,0};
            text = "";
            onMouseButtonUp = QUOTE((['KNOB'] + _this) call FUNC(onButtonPress));
            tooltip = QUOTE(Change channel);
        END_CONTROL
    };
};