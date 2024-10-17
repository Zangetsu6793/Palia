#pragma once

#ifndef ESP_H
#define ESP_H
#include "vec2.h"
#include "vec.h"
#include "Vector.h"
#include "imgui/imgui.h"
#include <vector>
#include "CppSDK/SDK/Engine_classes.hpp"

namespace ESP
{
    struct Bounds {
        SDK::FVector center;
        SDK::FVector extent;

        SDK::FVector p_min() const;
        SDK::FVector p_max() const;
    };

    enum class DrawMode {
        Box,
        Chams
    };

    enum class PointMode {
       Nulls,
       Line
    };

    ImVec4 ColorVecToImVec(const std::vector<int>& color);
    Bounds GetBoundsFromActor(SDK::AActor* actor);
    ImVec2 WorldToScreen(const SDK::FVector& world);
    void DrawActor(SDK::AActor* actor, DrawMode drawmode, PointMode pointmode, const std::vector<int>& color, SDK::AActor* PlayerActor);
}

#endif // ESP_H
