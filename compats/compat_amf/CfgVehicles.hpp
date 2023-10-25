class CfgVehicles {

	// Caracal (AMF_Heli_Transport_01)
    class Heli_Transport_base_F;
    class AMF_Heli_Transport_01_base_F : Heli_Transport_base_F { 
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
    };

	// NH90 (amf_nh90)
	class Helicopter_Base_H;
	class amf_nh90_base : Helicopter_Base_H {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
	};

	// Tigre (amf_tigre)
	class Helicopter_Base_F;
	class AMF_TIGRE_01_BASE : Helicopter_Base_F {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
	};

	// Cougar (amf_cougar)
	class amf_cougar_base : Helicopter_Base_H {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
	};


	// Gazelle AFTE (AMF_light_helicopters)
	class AMF_Gazelle_afte_BASE : Helicopter_Base_H {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
	};

	// Gazelle MiniGun (AMF_light_helicopters)
	class AMF_gazelle_minigun_base : Helicopter_Base_H {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "gunner", "copilot"};
                mountedRadio = "ACRE_ER323";
            };
        };
	};

	// AMX10 (AMF_AMX10_RCR)
    class Wheeled_APC_F;
    class AMF_AMX10_RCR_01_base_F : Wheeled_APC_F {
        class AcreRacks {
            class Rack_1 {
                displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner"};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };

	// Leclerc (AMF_TANK_01)
    class Tank_F;
    class AMF_leclerc_01_base_F : Tank_F {
        class AcreRacks {
            class Rack_1 {
				displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner"};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };

	// VBCI (AMF_TRANSPORT_VEHICLE_03, CfgPatches collide)
    class AMF_VBCI_BASE_01_F : Wheeled_APC_F {
        class AcreRacks {
            class Rack_1 {
                displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner"};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };

	// Jaguar (AMF_TRANSPORT_VEHICLE_03, CfgPatches collide)
    class APC_Wheeled_03_base_F;
    class AMF_APC_Wheeled_03_base_F : APC_Wheeled_03_base_F {
        class AcreRacks {
            class Rack_1 {
                displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner"};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };


	// Griffon HMG/Génie (AMF_TRANSPORT_VEHICLE_03, CfgPatches collide)
    class AMF_VBMR_01_BASE_F : APC_Wheeled_03_base_F {
        class AcreRacks {
            class Rack_1 {
                displayName="$STR_acre_sys_rack_dash";
                shortName="$STR_acre_sys_rack_dashShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner"};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };

	// Griffon Commandement (AMF_TRANSPORT_VEHICLE_03, CfgPatches collide)
    class MRAP_01_base_F;
    class AMF_VBMR_02_BASE_F : MRAP_01_base_F {
        class AcreRacks {
			class Rack_1
            {
                displayName="$STR_acre_sys_rack_dashUpper";
                shortName="$STR_acre_sys_rack_dashUpperShort";
                componentName="ACRE_VRC110";
                allowedPositions[]={"driver", "commander", "gunner", {"cargo", 0}};
                isRadioRemovable=1;
                intercom[]={"intercom_1"};
            };
            class Rack_2 {
                displayName="$STR_acre_sys_rack_dashLower";
                shortName="$STR_acre_sys_rack_dashLowerShort";
                componentName="ACRE_VRC103";
                allowedPositions[]={"driver", "commander", "gunner", {"cargo", 0}};
                mountedRadio="ACRE_ER315";
                intercom[]={"intercom_1"};
            };
        };
    };



};