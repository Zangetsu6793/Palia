#pragma once
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <Windows.h>

#include <cstdint>
#include <thread>

#include "./Offsets.h"
#include "./sdk.h"
#include "Memory.h"
#include "Teleport.h"
#include "Utils.h"
#include "NoClip.h"

#include "kiero/minhook/include/MinHook.h"
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "./Rendering.hpp"
#include "./Font.h"
#include "./Menu.h"
#include "ESP.h"

#include "./JsonHelper.h"

#include "./SDK/Engine_classes.hpp"

//#include "CppSDK/SDK/KuroRenderingRuntimeBPPlugin_classes.hpp"






typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

void Cheese();
void initchair();
//void ReloadScripts();



