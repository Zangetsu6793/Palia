#include "ESP.h"

namespace ESP
{
    ImVec4 ColorVecToImVec(const std::vector<int>& color) {
        if (color.size() < 4) return ImVec4(1, 1, 1, 1); 
        return ImVec4(color[0] / 255.f, color[1] / 255.f, color[2] / 255.f, color[3] / 255.f);
    }

    Bounds GetBoundsFromActor(SDK::AActor* actor) {
        SDK::FVector origin, extent;
        actor->GetActorBounds(true, &origin, &extent, true);
        return { origin, extent };
    }

    ImVec2 WorldToScreen(const SDK::FVector& world) {
        SDK::FVector2D out;
        SDK::UWorld* worldInstance = SDK::UWorld::GetWorld(); 
        if (!worldInstance) return ImVec2(0, 0);

        SDK::APlayerController* playerController = worldInstance->OwningGameInstance->LocalPlayers[0]->PlayerController;
        playerController->ProjectWorldLocationToScreen(world, &out, true);
        return { static_cast<float>(out.X), static_cast<float>(out.Y)};
    }

    SDK::FVector Bounds::p_min() const {
        return center - extent;
    }

    SDK::FVector Bounds::p_max() const {
        return center + extent;
    }

    void DrawActor(SDK::AActor* actor, DrawMode drawmode, PointMode pointmode, const std::vector<int>& color, SDK::AActor* PlayerActor) {
  //      switch (drawmode) 
		//{
		//case DrawMode::Box:
		//{
		//	auto bounds = GetBoundsFromActor(actor);
		//	ImVec2 p_min = WorldToScreen(bounds.p_min());
		//	ImVec2 p_max = WorldToScreen(bounds.p_max());
		//	ImGui::GetBackgroundDrawList()->AddRect(p_min, p_max, ImColor(ColorVecToImVec(color)));
		//	std::string actorInfo = std::string(actor->BlueprintTypeName.GetRawString()) + " | " + std::to_string(actor->KuroEntityType);
		//	ImGui::GetBackgroundDrawList()->AddText(p_min, ImColor(ColorVecToImVec(color)), actorInfo.c_str());
		//	break;
		//}
		//case DrawMode::Chams: 
  //      {
		//	// Implement your Chams drawing logic here

		//	break;
		//}


		//}
        if (pointmode == PointMode::Line)
        {
            auto playerpos = PlayerActor->K2_GetActorLocation();
            auto endpos = actor->K2_GetActorLocation();

            ImVec2 p_min = WorldToScreen(playerpos);
            ImVec2 p_max = WorldToScreen(endpos);


            ImGui::GetBackgroundDrawList()->AddLine(p_min, p_max, ImColor(ColorVecToImVec(color)), 1.0f);

        }

    }
}
