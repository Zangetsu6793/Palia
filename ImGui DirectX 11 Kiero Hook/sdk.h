#pragma once

#include <vector>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "../ImGui DirectX 11 Kiero Hook/vec.h"
#include "../ImGui DirectX 11 Kiero Hook/vec2.h"
#include <d3d11.h>
#include <string>
#include "./JsonHelper.h"
#include "./SDK/Engine_classes.hpp"

inline bool show_menu = true;
inline bool show_info = true;

namespace vars {
    //changable by user later
    inline static const std::string teleportDirectory = "C:\\Users\\boeta\\OneDrive\\Desktop\\JsonTest";
    inline static char nameBuffer[128] = "";

    inline bool Inisialized = false;

    inline static UINT vps = 1;
    inline Vector2 screen_size = { 0, 0 };
    inline Vector2 screen_center = { 0, 0 };
    inline D3D11_VIEWPORT viewport;

    inline int waitForClientSec = 2;


    //bools
    inline bool watermark = true;
    //inline bool logPlayerHealth = false;
    //inline bool bHop = false;
    //inline bool bHopIntitialized = false;

    inline bool test = false;

    //Colours
    inline ImVec4 Rainbow = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

    //Cheat Modified
    inline float PlayerXPos = 0;
    inline float PlayerYPos = 0;
    inline float PlayerZPos = 0;

    inline bool Teleport = false;
    inline bool SelectAllTp = false;
    inline bool SelectAllTpChange = true;
    inline bool LoadOnce = false;
    inline bool JsonsLoaded = false;


    inline std::vector<JsonSaveFile> teleportLocations;

    inline float FlySpeed = 10.0f;
    inline bool noClip = false;
    inline bool noClipOn = false;

    inline bool AutoLoot = false;
    inline bool bPressF = false;
    inline float distanceThreshold = 100.0f;


    //ESP
    inline bool espEnable = false;
    inline bool espBox = false;
    inline bool espLine = false;
    inline bool espNPC = false;
    inline bool espMonster = false;
    inline bool espSceneItem = false;
    inline bool espCustoms = false;
    inline bool espOtherCustoms = false;
    inline bool espVision = false;
    inline bool espAnimal = false;

    inline bool espChests = false;
    inline bool espTeleport = false;
    inline bool espCollectable = false;

    inline float colorNPC[3] = { 1.0f, 1.0f, 1.0f };     // White
    inline float colorMonster[3] = { 1.0f, 0.0f, 0.0f };  // Red
    inline float colorSceneItem[3] = { 0.0f, 1.0f, 0.0f };// Green
    inline float colorCustoms[3] = { 0.0f, 0.0f, 1.0f };  // Blue
    inline float colorVision[3] = { 0.0f, 0.0f, 1.0f };  
    inline float colorAnimal[3] = { 1.0f, 1.0f, 0.0f };
    inline float colorChest[3] = {1.0f, 0.5f, 0.0f}; // Orange color for chests
    inline float colorTeleport[3] = { 0.0f, 1.0f, 1.0f }; // Cyan color for teleports
    inline float colorCollectable[3] = { 1.0f, 1.0f, 0.0f }; // Yellow color for collectables

    inline float x, y;


    inline bool tpChests = false;
    inline bool tpTeleport = false;
    inline bool tpCollectable = false;

}

namespace sdk {

    inline uintptr_t NewStringOffset = 0x4CCCCC0;
    inline uintptr_t NewString = 0x00;
    inline uintptr_t ClientBase = 0x00;
    inline SDK::UWorld* World;
    inline SDK::UEngine* Engine;


}
