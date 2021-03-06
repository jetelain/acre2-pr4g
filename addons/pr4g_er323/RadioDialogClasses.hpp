class ER323_RscBackground {
        type = CT_STATIC;
        idc = -1;
        style = ST_BACKGROUND + ST_KEEP_ASPECT_RATIO;
        colorBackground[] = {0, 0, 0, .75};
        colorText[] = {1, 1, 1, 1};
        font = FontM;
        sizeEx = 0.04;
};

// text
class ER323_RscText {
    idc = -1;
    type = CT_STATIC;
    style = ST_CENTER;
    font = "led16sgmnt2";
    colorText[] = {1,1,1,1};
    colorBackground[] = {0, 0, 0, 0};
    sizeEx = 0.024;
    shadow = 0;
    w = 0.2;
    h = 0.03;
};

class ER323_RscButton {
  type = CT_BUTTON;
  idc = -1;
  style = ST_CENTER + ST_KEEP_ASPECT_RATIO;

  x = 0.0;
  y = 0.0;
  w = 0.1;
  h = Dlg_CONTROLHGT;
  sizeEx = 0.0325;
  offsetX = 0;
  offsetY = 0.002;
  offsetPressedX = 0;
  offsetPressedY = 0.002;
  borderSize = 0;

  #define ClrWhite 1,1,1
  #define ClrBlack 0,0,0
  #define ClrGray 0.5,0.5,0.5
  #define ClrBlue 0.2,0.5,1

  colorText[] = {ClrWhite,1};
  colorBackground[] = {1, 0, 0, 0};
  colorFocused[] = {ClrGray,0};

  colorShadow[] = {ClrBlack,0};
  colorBorder[] = {ClrBlack,0};
  colorBackgroundActive[] = {ClrGray,0};
  colorDisabled[] = {ClrGray, 0};
  colorBackgroundDisabled[] = {ClrGray,0};
  font = FontM;

  soundEnter[] = {"", 0.2, 1};
  soundPush[] = {"", 0.2, 1};
  soundClick[] = {"", 0.2, 1};
  soundEscape[] = {"", 0.2, 1};

  default = false;
  text = "";
  action = "";
};

class ER323_RscPicture: ER323_RscButton {
    type = CT_STATIC;
    idc = -1;
    style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
    text = "";
};
