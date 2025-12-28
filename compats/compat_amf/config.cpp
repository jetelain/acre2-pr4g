#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = QUOTE(COMPONENT);
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "acre_sys_rack",
            "acrefr_pr4g_er315",
            "acrefr_pr4g_er323",
            "AMF_Heli_Transport_01",
            "amf_nh90",  
            "amf_tigre",
            "ffaa_et_cougar",
            "AMF_light_helicopters",
            "AMF_AMX10_RCR",
            "AMF_TANK_01",
            "AMF_TRANSPORT_VEHICLE_03",
            "AMF_TRANSPORT_VEHICLE_07",
            "AMF_JAGUAR"};
        author = "GrueArbre";
        VERSION_CONFIG;
    };
};


#include "CfgVehicles.hpp"
