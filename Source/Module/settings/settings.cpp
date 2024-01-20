#include "settings.h"



//GENERAL
bool settings::CanRenderMenu = false;

//MOVEMENT
bool settings::AutoSprint = false;
bool settings::Speed = false;
float settings::multiplier = 1.0f;
bool settings::NCPYPort = false;
bool settings::Fly = false;
float settings::flySpeed = 0.5;
bool settings::NCPBHop = false;
bool settings::VanillaSpeed = false;
bool settings::Strafe = false;
bool settings::Timer = false;
float settings::timerspeed = 1.2f;

//COMBAT
bool settings::NoHitDelay = false;
bool settings::NoBuildDelay = false;
bool settings::Autoclicker = false;
bool settings::RightClick = false;
int settings::AutoclickerCount = 16;
int settings::RightClickSpeed = 16;
bool settings::BlockHit = true;
bool settings::HitBoxExtender = false;
float settings::HitBoxWidth = 0.4f;
float settings::HitBoxHeight = 0.2f;
bool settings::JumpReset = false;
bool settings::Velocity = false;
float settings::vert = 1;
float settings::hori = .75;
bool settings::groundSpoof = true;
int settings::VeloTicks = 0;
bool settings::Killaura = false;
float settings::range = 3.5;
bool settings::NoSlow = false;
bool settings::Reach = false;
float settings::dist = 3.2;


//PROTECTION
bool settings::AntiBot = false;
bool settings::AntiBotNameFlag = false;
bool settings::AntiBotPingFlag = false;
bool settings::AntiBotRiskyPingFlag = false;
bool settings::AntiBotUUIDFlag = false;

//Visual
bool settings::FrameSpoof = false;
int settings::FrameSpoofValue = 999;
bool settings::PingSpoof;
int settings::PingSpoofValue = 999;
bool settings::NoFire = false;

//ESP
bool settings::PlayerESP = false;
bool settings::ChestESP = false;

//MISC
bool settings::NameSpoof = false;
char settings::NameSpoofValue = (const char)"Skidware";
bool settings::LegitScaffold = false;
int settings::sneak_delay = 100;
bool settings::Disabler = false;
bool settings::FrequencyFly = true;
bool settings::TimerDisable;
bool settings::OldAAC = false;
//HYPIXEL
bool settings::MurderExpose = false;