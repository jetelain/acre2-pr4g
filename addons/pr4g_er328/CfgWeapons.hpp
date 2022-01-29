class CfgWeapons {
    class ACRE_BaseRadio;
    class CBA_MiscItem_ItemInfo;

    class ACRE_ER328: ACRE_BaseRadio {
        displayName = QUOTE(NAME_ER328);
        useActionTitle = QUOTE(NAME_ER328);
        picture = QPATHTOF(Data\ER328_ico.paa);
        descriptionShort = "PRG4 ER 328";
        scopeCurator = 2;
        scope = 2;

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 8;
            scope = 0;
        };

        class Library {
            libTextDesc = QUOTE(NAME_ER328);
        };
    };

    RADIO_ID_LIST(ACRE_ER328)
};
