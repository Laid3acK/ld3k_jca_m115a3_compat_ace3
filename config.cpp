class CfgPatches
{
    class ld3k_jca_m115a3_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_AWM",
            "Weapons_F_JCA_AWM_Accessories",
            "weapons_f_JCA_AWM_LongRangeRifles_AWM"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    // L115A3 twist rate 1:11" optimized for bullets around 250gr, for 300gr twist rate 1:10" or faster
    class B_338_Ball;
    class JCA_B_338LM_Ball: B_338_Ball // B_338_Ball, Lapua .338 LM Scenar 250gr GB488 https://www.lapua.com/product/338-lapua-mag-tactical-target-cartridge-scenar-162g-250gr-4318017/
    {
        ACE_caliber=8.61; // .338 LM CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-i/338-lapua-mag-en.pdf
        ACE_bulletLength=39.4; // Strelok Pro .338 LM Lapua Scenar 250gr GB488, 1.551" https://jbmballistics.com
        ACE_bulletMass=16.2; // Lapua .338 LM Scenar 250gr GB488 https://www.lapua.com/product/338-lapua-mag-tactical-target-cartridge-scenar-162g-250gr-4318017/
        ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32
        ACE_ammoTempMuzzleVelocityShifts[]={-5.31,-5.094,-4.57,-4.024,-3.396,-2.56,-1.528,-0.306,1.192,3.034,5.238}; // default ACE_ammoTempMuzzleVelocityShifts values /5. Muzzle velocity shift 0 at 70°F (21°C), -2m/s at 15°C
        ACE_ballisticCoefficients[]={0.648}; // Lapua .338 LM Scenar 250gr GB488 https://www.lapua.com/product/338-lapua-mag-tactical-target-cartridge-scenar-162g-250gr-4318017/
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO"; // ICAO: 15°C, 1013.25 hPa, 0%
        ACE_dragModel=1; // Lapua .338 LM Scenar 250gr GB488 https://www.lapua.com/product/338-lapua-mag-tactical-target-cartridge-scenar-162g-250gr-4318017/
        ACE_muzzleVelocities[]={908}; // muzzle velocity 908 m/s at 21°C (70°F: Temp vs MV chart zero), 906 m/s with barrel length 27" at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_5Rnd_338LM_Mag initSpeed
        ACE_barrelLengths[]={685.8}; // 27"
        hit=20; // hit value according to Arma3 "Armor Level IV" value, B_338_Ball 16, JCA 18. 16.2g 906 m/s = 6650 Joules. NIJ Type IV (Armor Piercing Rifle) and NIJ RF3: 30.06 M2 AP bullet 10.8g 878m/s (165.7gr 2880ft/s): 4163 Joules
        caliber=0.443; // Perforation 5mm RHA "armour_plate_5mm.bisurf" at 300m (5mm 752m/s default ballistic - 761m/s ICAO advanced ballistics), B_338_Ball 2, JCA 1.8, should be Lapua Scenar penetration 3mm RHA at 300m
        typicalSpeed=906; // according to JCA_5Rnd_338LM_Mag initSpeed, B_338_Ball 890
        tracerScale=1.2; // No .338 LM tracer irl, B_338_Ball, JCA 1.3
        tracerStartTime=0.23; // No .338 LM tracer irl, based on 12.7x99 Tracer visible < 200 m to ≥ 1 500 m https://www.nammo.com/ ToF ICAO at 200m 0.23s (Strelok Pro), B_338_Ball 0.075
        tracerEndTime=2.75; // No .338 LM tracer irl, based on 12.7x99 Tracer visible < 200 m to ≥ 1 500 m https://www.nammo.com/ ToF ICAO at 1500m 2.75s (Strelok Pro), B_338_Ball 1, JCA 3
        airFriction=-0.00061662; // elevation gap 0.1, 0.2mRad until 1700m, airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_338LM_Ball_Tracer_IR: JCA_B_338LM_Ball
    {
        tracerScale=0.6; // IR dim tracer
        tracerStartTime=0.01; // No .338 LM tracer irl, based on 7.62 mm x 51 DIM TRACER (IR), 13–775 m (typically visible to 1250 m) https://www.nammo.com/ ToF ICAO at 13m 0.01s (Strelok Pro), B_338_Ball 0.075
        tracerEndTime=2.08; // No .338 LM tracer irl, based on 7.62 mm x 51 DIM TRACER (IR), 13–775 m (typically visible to 1250 m) https://www.nammo.com/ ToF ICAO at 1250m 2.08s (Strelok Pro), B_338_Ball 1, JCA 3
    };
    class JCA_B_338LM_AP_Ball: JCA_B_338LM_Ball // Lapua .338 LM 248gr AP485 Armor Piercing https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-armor-piercing-161g-248gr-4318035/
    {
        ACE_bulletLength=35.5; // 1.398" 35.51mm https://jbmballistics.com
        ACE_bulletMass=16.1; // Lapua .338 LM 248gr AP485 Armor Piercing https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-armor-piercing-161g-248gr-4318035/
        ACE_ballisticCoefficients[]={0.564}; // Lapua .338 LM 248gr AP485 Armor Piercing https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-armor-piercing-161g-248gr-4318035/
        ACE_muzzleVelocities[]={908}; // muzzle velocity 908 m/s at 21°C (70°F: Temp vs MV chart zero), 906 m/s with barrel length 27" at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_5Rnd_338LM_AP_Mag initSpeed
        caliber=1.307; // Perforation 12mm RHA "armour_plate_12mm.bisurf" at 550m (12mm 612m/s default ballistic - 619m/s ICAO advanced ballistics), B_338_Ball 2, should be 12 mm at 550 m Steel plate 400 HB https://www.nammo.com/
        hit=20; // hit value according to Arma3 "Armor Level IV" value. 16.1g 906 m/s = 6609 Joules. NIJ Type IV (Armor Piercing Rifle) and NIJ RF3: 30.06 M2 AP bullet 10.8g 878m/s (165.7gr 2880ft/s): 4163 Joules
        typicalSpeed=906; // according to JCA_5Rnd_338LM_AP_Mag initSpeed, B_338_Ball 890
        airFriction=-0.00070864; // elevation gap 0.1, 0.2mRad until 1500m, airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_338LM_API_Ball: JCA_B_338LM_Ball // Lapua .338 LM 253gr API526 Armor Piercing Incendiary https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-api526-164g-253gr-4318048/
    {
        ACE_bulletLength=39; // 1.535" 38.99mm https://jbmballistics.com
        ACE_bulletMass=16.4; // Lapua .338 LM 253gr API526 Armor Piercing Incendiary https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-api526-164g-253gr-4318048/
        ACE_ballisticCoefficients[]={0.554}; // Lapua .338 LM 253gr API526 https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-api526-164g-253gr-4318048/
        ACE_muzzleVelocities[]={898}; // muzzle velocity 898 m/s at 21°C (70°F: Temp vs MV chart zero), 896 m/s with barrel length 27" at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_5Rnd_338LM_API_Mag initSpeed
        ace_vehicle_damage_incendiary=1; // observable flash at hard targets. Ignition of vaporized fuel https://www.nammo.com/product/our-products/ammunition/small-caliber-ammunition/8-6mm-series-338/8-6-mm-x-70-338-lapua-armor-piercing-incendiary/
        caliber=1.07; // Perforation 10mm RHA (no vanilla "armour_plate_10mm.bisurf", custom model) at 500m (10mm 623m/s default ballistic - 630m/s ICAO advanced ballistics), B_338_Ball 2, should be 10 mm at 500 m Steel plate 400 HB https://www.nammo.com/
        hit=24; // hit value according to Arma3 "Armor Level V" value. 16.4g 896 m/s = 6584 Joules. NIJ Type IV (Armor Piercing Rifle) and NIJ RF3: 30.06 M2 AP bullet 10.8g 878m/s (165.7gr 2880ft/s): 4163 Joules
        indirectHit=4; // B_20mm_AP 8
        indirectHitRange=0.1; // B_20mm_AP 0.2
        typicalSpeed=896; // according to JCA_5Rnd_338LM_API_Mag initSpeed, B_338_Ball 890
        airFriction=-0.0007233; // elevation gap 0.1, 0.2mRad until 1500m, airFrictionAnalysis.txt in docs folder
        CraterEffects="ExploAmmoCrater"; // ammo_Penetrator_Base
        class HitEffects // B_30mm_APFSDS. Observable flash at hard targets. Ignition of vaporized fuel https://www.nammo.com/product/our-products/ammunition/small-caliber-ammunition/8-6mm-series-338/8-6-mm-x-70-338-lapua-armor-piercing-incendiary/
        {
            hitMetal="ImpactMetalSabotSmall";
            hitMetalPlate="ImpactMetalSabotSmall";
            hitBuilding="ImpactConcreteSabotSmall";
            hitConcrete="ImpactConcreteSabotSmall";
            hitGroundSoft="ImpactEffectsGroundSabot";
            hitGroundRed="ImpactEffectsGroundSabot"; // BulletBase ImpactEffectsRed
            hitGroundHard="ImpactEffectsGroundSabot";
            Hit_Foliage_green="ImpactLeavesGreen";
            Hit_Foliage_Dead="ImpactLeavesDead";
            Hit_Foliage_Green_big="ImpactLeavesGreenBig";
            Hit_Foliage_Palm="ImpactLeavesPalm";
            Hit_Foliage_Pine="ImpactLeavesPine";
            hitFoliage="ImpactLeaves";
            hitGlass="ImpactGlass";
            hitGlassArmored="ImpactGlassThin";
            hitWood="ImpactWood";
            hitHay="ImpactHay";
            hitPlastic="ImpactPlastic";
            hitRubber="ImpactRubber";
            hitTyre="ImpactTyre";
            hitMan="ImpactEffectsBlood";
            hitWater="ImpactEffectsWater";
            hitVirtual="ImpactMetal"; // BulletBase
            default_mat="ImpactEffectsGroundSabot";
        };
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_5Rnd_338LM_Mag: CA_Magazine
    {
        mass=9.7; // magazine 219g + 5x 44.5g, JCA 8
        initSpeed=906; // Lapua .338 LM Scenar 250gr GB488: 905m/s with barrel length 680mm, 906m/s barrel length 27" (685.8mm) according to ACE_ammoTempMuzzleVelocityShifts https://www.lapua.com/product/338-lapua-mag-tactical-target-cartridge-scenar-162g-250gr-4318017/
    };
    class JCA_5Rnd_338LM_Tracer_Red_Mag: JCA_5Rnd_338LM_Mag
    {
        displaynameshort="Tracer";
    };
    class JCA_5Rnd_338LM_Tracer_Green_Mag: JCA_5Rnd_338LM_Tracer_Red_Mag
    {
        displaynameshort="Tracer";
    };
    class JCA_5Rnd_338LM_Tracer_Yellow_Mag: JCA_5Rnd_338LM_Tracer_Red_Mag
    {
        displaynameshort="Tracer";
    };
    class JCA_5Rnd_338LM_Tracer_IR_Mag: JCA_5Rnd_338LM_Tracer_Red_Mag
    {
        displaynameshort="Tracer IR";
    };
    class JCA_5Rnd_338LM_AP_Mag: JCA_5Rnd_338LM_Mag
    {
        author="Grave";
        displayName=".338 LM 5Rnd AP Mag";
        displaynameshort="AP";
        ammo="JCA_B_338LM_AP_Ball";
        // mass=9.7; // magazine 219g + 5x 44.3g
        // initSpeed=906; // Lapua .338 LM 250gr AP485: 905m/s with barrel length 680mm, 906m/s barrel length 27" (685.8mm) according to ACE_ammoTempMuzzleVelocityShifts https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-armor-piercing-161g-248gr-4318035/
    };
    class JCA_5Rnd_338LM_API_Mag: JCA_5Rnd_338LM_Mag
    {
        author="Grave";
        displayName=".338 LM 5Rnd API Mag";
        displaynameshort="API";
        ammo="JCA_B_338LM_API_Ball";
        // mass=9.7; // magazine 219g + 5x 44.4g
        initSpeed=896; // Lapua .338 LM 253gr API526: 895m/s with barrel length 680mm, 896m/s barrel length 27" (685.8mm) according to ACE_ammoTempMuzzleVelocityShifts https://www.lapua.com/product/338-lapua-mag-tactical-cartridge-api526-164g-253gr-4318048/
    };
};
class Mode_SemiAuto;
class CfgWeapons
{
    class InventoryMuzzleItem_Base_F;
    class InventoryOpticsItem_Base_F;
    class InventoryUnderItem_Base_F;
    class ItemCore;
    class Rifle_Base_F;
    class Rifle_Long_Base_F: Rifle_Base_F
    {
        class WeaponSlotsInfo;
    };
    class JCA_srifle_AWM_base_F: Rifle_Long_Base_F
    {
        ACE_barrelTwist=279.4; // 1:11" optimized for bullets around 250gr, for 300gr twist rate 1:10" or faster
        ACE_barrelLength=685.8; // 27"
        ACE_railHeightAboveBore=1.64895; // from ACE3 checkScopes.sqf
        initSpeed=-1; // 906m/s - 896 m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_5Rnd_338LM_Mag, JCA_5Rnd_338LM_AP_Mag and JCA_5Rnd_338LM_API_Mag initSpeed
        magazines[]=
        {
            "JCA_5Rnd_338LM_Mag",
            "JCA_5Rnd_338LM_Tracer_Red_Mag",
            "JCA_5Rnd_338LM_Tracer_Green_Mag",
            "JCA_5Rnd_338LM_Tracer_Yellow_Mag",
            "JCA_5Rnd_338LM_Tracer_IR_Mag",
            "JCA_5Rnd_338LM_AP_Mag",
            "JCA_5Rnd_338LM_API_Mag"
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000209; // average dispersion from .338 LM Scenar, AP and API https://www.nammo.com/: 1.28 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00022 (0.76 MOA)
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=149.9; // 6.8kg https://www.army.mod.uk/equipment/small-arms-and-support-weapons/, JCA 105
        };
    };
    class JCA_optic_HPPO_base: ItemCore
    {
        ACE_ScopeZeroRange=100; // Always keep vanilla discreteDistance 100 same that Range Card zeroed distance, to increase eventually zeroing distance: Interaction Menu -> "Set zero adjustment" (AB enabled only)
        ACE_ScopeHeightAboveRail=4.89867; // from ACE3 checkScopes.sqf, JCA 4.2098
        descriptionShort="High Power Precision Optic<br />Magnification: 11x-23x";
        class ItemInfo: InventoryOpticsItem_Base_F
        {
            mass=23.8; // S&B 5-25x56 1080g, JCA 18
            class OpticsModes
            {
                class HPPO
                {
                    opticsZoomMin=0.010992; // accurate mRad reticle calibration at magnification 22.7x, JCA 0.01 (25x)
                    opticsZoomMax=0.021963; // accurate mRad reticle calibration at magnification 11.4x, JCA 0.042 (6x)
                    opticsZoomInit=0.021963; // accurate mRad reticle calibration at magnification 11.4x, JCA 0.042 (6x)
                    discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=100;
                    distanceZoomMax=2400;
                    discretefov[]={0.021963,0.010992}; // {11.4x, 22.7x}
                };
            };
        };
    };
    class JCA_optic_HPPO_RAD_base: ItemCore
    {
        ACE_ScopeZeroRange=100; // Always keep vanilla discreteDistance 100 same that Range Card zeroed distance, to increase eventually zeroing distance: Interaction Menu -> "Set zero adjustment" (AB enabled only)
        ACE_ScopeHeightAboveRail=4.89867; // from ACE3 checkScopes.sqf, JCA 4.2098
        descriptionShort="High Power Precision Optic - Range Acquisition Device<br />Magnification: 11x-23x";
        class ItemInfo: InventoryOpticsItem_Base_F
        {
            mass=33.1; // S&B 5-25x56 1080g + Wilcox RAPTAR-S 420g, JCA 24
            class OpticsModes
            {
                class HPPO
                {
                    opticsZoomMin=0.010992; // accurate mRad reticle calibration at magnification 22.7x, JCA 0.01 (25x)
                    opticsZoomMax=0.021963; // accurate mRad reticle calibration at magnification 11.4x, JCA 0.042 (6x)
                    opticsZoomInit=0.021963; // accurate mRad reticle calibration at magnification 11.4x, JCA 0.042 (6x)
                    discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=100;
                    distanceZoomMax=2400;
                    discretefov[]={0.021963,0.010992}; // {11.4x, 22.7x}
                };
            };
        };
    };
    class JCA_muzzle_snds_tactical_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F // muzzle_snds_338_black
        {
            mass=10.5; // Accuracy International Tactical Moderator 475g, only compatible with the Accuracy International Tactical muzzle break, not the standard muzzle break, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_338_black 1.1
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_338_black 0.8
                recoilCoef=0.95;
                recoilProneCoef=0.95;
            };
        };
    };
    class JCA_bipod_AWM_base: ItemCore
    {
        class ItemInfo: InventoryUnderItem_Base_F
        {
            mass=13; // Accuracy International AW/AWM Steel Bipod 590g, JCA 10
        };
    };
};
class CfgMagazineWells
{
    class JCA_AWM_338LM // Weapon initSpeed -1 with ACE_barrelLength 685.8mm (27"), 906m/s - 896m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_5Rnd_338LM magazines initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_5Rnd_338LM_Mag",
            "JCA_5Rnd_338LM_Tracer_Red_Mag",
            "JCA_5Rnd_338LM_Tracer_Green_Mag",
            "JCA_5Rnd_338LM_Tracer_Yellow_Mag",
            "JCA_5Rnd_338LM_Tracer_IR_Mag",
            "JCA_5Rnd_338LM_AP_Mag",
            "JCA_5Rnd_338LM_API_Mag"
        };
    };
};
class ACE_ATragMX_Presets
{
    class ld3k_JCA_B_338LM_Ball
    {
        preset[]=
        {
            "JCA M115A3",
            906,
            100,
            0.0732268,
            -0.00061662,
            6.55,
            0,
            2,
            10,
            120,
            0,
            0,
            16.2,
            8.95,
            27.94,
            0.648,
            1,
            "ICAO",

            {
                {-15,903},
                {0,904},
                {10,905},
                {15,906},
                {25,909},
                {30,911},
                {35,913}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_B_338LM_AP_Ball
    {
        preset[]=
        {
            "JCA M115A3 AP",
            906,
            100,
            0.0734488,
            -0.00070864,
            6.55,
            0,
            2,
            10,
            120,
            0,
            0,
            16.1,
            9.28,
            27.94,
            0.564,
            1,
            "ICAO",

            {
                {-15,903},
                {0,904},
                {10,905},
                {15,906},
                {25,909},
                {30,911},
                {35,913}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_B_338LM_API_Ball
    {
        preset[]=
        {
            "JCA M115A3 API",
            896,
            100,
            0.074292,
            -0.0007233,
            6.55,
            0,
            2,
            10,
            120,
            0,
            0,
            16.4,
            9.03,
            27.94,
            0.554,
            1,
            "ICAO",

            {
                {-15,893},
                {0,894},
                {10,895},
                {15,896},
                {25,899},
                {30,901},
                {35,903}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
};
