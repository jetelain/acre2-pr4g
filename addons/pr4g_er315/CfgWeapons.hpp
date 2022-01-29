class CfgWeapons {
    class ACRE_BaseRadio;
    class CBA_MiscItem_ItemInfo;

    class ACRE_ER315: ACRE_BaseRadio {
        displayName = QUOTE(NAME_ER315);
        useActionTitle = QUOTE(NAME_ER315);
        picture = QPATHTOF(Data\ER315_ico.paa);
        descriptionShort = "PRG4 ER 314";
        scopeCurator = 2;
        scope = 2;

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 120;
            allowedSlots[] = {901};
            scope = 0;
         };

        class Library {
            libTextDesc = QUOTE(NAME_ER315);
        };
    };

    RADIO_ID_LIST(ACRE_ER315)
};
