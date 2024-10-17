#pragma once
#include "imgui/imgui.h"
#include "sdk.h"
#include "GodMode.h"
//#include "functions.h"
//#include "Dumper.hpp"
#include "imgui/imgui.h"
//#include "Lists.hpp"
#include <iomanip> 
#include"./Teleport.h"
#include "./JsonHelper.h"
#include <tuple> 
#include "ESP.h"


#include "Utils.h"

using namespace ImGui;

void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("[?]");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void ImGuiTheme1()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;
	ImGui::StyleColorsDark();
	style->FrameBorderSize = 1.0f;
	style->FramePadding = ImVec2(4.0f, 2.0f);
	style->ItemSpacing = ImVec2(8.0f, 2.0f);
	style->WindowBorderSize = 1.0f;
	style->WindowRounding = 1.0f;
	style->ChildRounding = 1.0f;
	style->AntiAliasedFill = true;
	style->AntiAliasedLines = true;
	style->WindowBorderSize = 0.0f;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.18f, 0.18f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.46f, 0.47f, 0.48f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.70f, 0.70f, 0.70f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.70f, 0.70f, 0.70f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.48f, 0.50f, 0.52f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.72f, 0.72f, 0.72f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.73f, 0.60f, 0.15f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.87f, 0.87f, 0.87f, 0.35f);
	//colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
}
void ImGuiTheme2()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	ImGuiStyle& style = ImGui::GetStyle();
	//style.WindowPadding = ImVec2(8.00f, 8.00f);
	//style.FramePadding = ImVec2(5.00f, 2.00f);
	//style.CellPadding = ImVec2(6.00f, 6.00f);
	//style.ItemSpacing = ImVec2(6.00f, 6.00f);
	//style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	//style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	//style.FrameBorderSize = 1;
	style.WindowRounding = 4;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
}
void TeleportUI();
void EspMenu();
void Esp();
float GetMapPos(float x, float y);

void TpNeariestActor();

/*
void DrawInspector() {
	ImGui::SetNextWindowSize(ImVec2(600.000f, 1000.000f), ImGuiCond_Once);
	if (!ImGui::Begin("Inspector", nullptr, 2)) {
		ImGui::End();
		return;
	}

	static std::vector<std::string> components;
	static std::vector<std::string> classes;
	static std::vector<std::string> methods;
	static std::string current_comp = "";

	ImGui::Text("Components");
	if (ImGui::Button("Update##comp")) {
		components = Dumper::DumpComponentsString();
	}
	ImGui::SetNextItemWidth(150.000f);
	static int component_current_idx = 0; // Here we store our selection data as an index.
	static ImGuiTextFilter c_filter;
	c_filter.Draw("Search##compfilter");
	if (ImGui::BeginListBox("##Components", ImVec2(-FLT_MIN, 200)))
	{
		for (size_t n = 0; n < components.size(); n++)
		{
			if (!c_filter.PassFilter(components[n].c_str())) {
				continue;
			}
			const bool comp_is_selected = (component_current_idx == (int)n);
			if (ImGui::Selectable(components[n].c_str(), comp_is_selected))
				component_current_idx = (int)n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (comp_is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}
	ImGui::Spacing();
	ImGui::Text("Classes");
	if (ImGui::Button("Update##class")) {
		classes = Dumper::DumpClassesString(components[component_current_idx]);
		current_comp = components[component_current_idx];
	}

	ImGui::SetNextItemWidth(150.000f);
	static int class_current_idx = 0; // Here we store our selection data as an index.
	static ImGuiTextFilter cl_filter;
	cl_filter.Draw("Search##classfilter");
	if (ImGui::BeginListBox("##Class", ImVec2(-FLT_MIN, 200)))
	{
		for (size_t n = 0; n < classes.size(); n++)
		{
			if (!cl_filter.PassFilter(classes[n].c_str())) {
				continue;
			}
			const bool class_is_selected = (class_current_idx == (int)n);
			if (ImGui::Selectable(classes[n].c_str(), class_is_selected)) {
				class_current_idx = (int)n;
			}

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (class_is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}

	ImGui::Spacing();
	ImGui::Text("Methods");
	if (ImGui::Button("Update##Methods")) {
		methods = Dumper::DumpMethodsString(current_comp, classes[class_current_idx]);
	}

	ImGui::SetNextItemWidth(150.000f);
	static int method_current_idx = 0; // Here we store our selection data as an index.
	static ImGuiTextFilter me_filter;
	me_filter.Draw("Search##methodfilter");
	if (ImGui::BeginListBox("##Methods", ImVec2(-FLT_MIN, 200)))
	{
		for (size_t n = 0; n < methods.size(); n++)
		{
			if (!me_filter.PassFilter(methods[n].c_str())) {
				continue;
			}
			const bool meth_is_selected = (method_current_idx == (int)n);
			if (ImGui::Selectable(methods[n].c_str(), meth_is_selected))
				method_current_idx = (int)n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (meth_is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}

	ImGui::End();
}
*/

void DrawMenu()
{
	ImGuiTheme2();
	// DrawInspector();
	static int page = 0;
	if (ImGui::Begin("[ WWC ]", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings))
	{
		ImGui::SetWindowPos(ImVec2(50, 50), ImGuiCond_Once);
		ImGui::SetWindowSize(ImVec2(375, 600), ImGuiCond_Once);
		if (sdk::World != nullptr && sdk::World->OwningGameInstance != nullptr && sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn != nullptr)
		{
		static int tabb = 0;
		ImGui::SameLine();
		if (ImGui::Button("Character"))
		{
			tabb = 0;
		}
		ImGui::SameLine();
		if (ImGui::Button("World"))
		{
			tabb = 1;
			if (sdk::World)
			{
				SDK::FVector pos = Teleport::GetPlayerPosition();
				vars::PlayerXPos = pos.X;
				vars::PlayerYPos = pos.Y;
				vars::PlayerZPos = pos.Z;
				fprintf(stderr, "Player pos x %f y %f z %f\n", pos.X, pos.Y, pos.Z);
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Visual"))
		{
			tabb = 2;
		}
		ImGui::SameLine();
		if (ImGui::Button("Info"))
		{
			tabb = 3;
		}
		ImGui::Separator();
		if (ImGui::Button("Debug Info"))
		{
			tabb = 4;
		}
		ImGui::Separator();
		
		
			switch (tabb)
			{
			case 0:
				
				ImGui::Checkbox("No Clip", &vars::noClip);
				TeleportUI();

				break;
			case 1:

					
				if (ImGui::Button("Test"))
				{
					//GetMapPos(vars::x, vars::y);

					TpNeariestActor();
					vars::test = true;
				}

				break;
			case 2:
				EspMenu();
				break;

			case 3:
				ImGui::TextUnformatted("[ WWC ]");
				if (ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					ImGui::Text("WWC: Placeholder Text");

					// Uncomment the following line to open a popup with a link
					//if (ImGui::BeginPopup("link_to_more_info"))
					//{
					//    ImGui::Text("Find more information on:");
					//    if (ImGui::Button("Platform X")) {
					//        // Open link to Platform X
					//    }
					//    if (ImGui::Button("Platform Y")) {
					//        // Open link to Platform Y
					//    }
					//    ImGui::EndPopup();
					//}

					ImGui::EndTooltip();
				}
				break;
			case 4:
				if (sdk::World != nullptr && sdk::World->OwningGameInstance != nullptr) {

					ImGui::Text("GWorld -> 0x%d", &sdk::World);
					ImGui::Text("GEngine -> 0x%d", &sdk::Engine);

					if (&sdk::World->OwningGameInstance->LocalPlayers[0])
					{
						ImGui::Text("LocalPlayer -> 0x%d", &sdk::World->OwningGameInstance->LocalPlayers[0]);
						ImGui::Text("APlayerController -> 0x%d", &sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController);
						ImGui::Text("APawn -> 0x%d", &sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
						ImGui::SliderFloat("Character Speedhack", &sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->CustomTimeDilation, 1.0f, 100.0f);
						//ImGui::SliderFloat("World Speedhack", &sdk::World->K2_GetWorldSettings()->CustomTimeDilation, 1.0f, 100.0f);
					}

				}
				break;

			}
		}
		else
		{
			ImGui::Text("Load into world to use cheats");
			if (ImGui::Button("Test"))
			{
				fprintf(stderr, "Button pressed");
				vars::test = true;
			}
		}
		ImGui::End();
	}



}


void DrawInfo()
{
//	if (sdk::World != nullptr && sdk::World->OwningGameInstance != nullptr && sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn != nullptr && sdk::World->PersistentLevel != nullptr && sdk::World->PersistentLevel->Actors[0] != nullptr)
//	if (sdk::World != nullptr && sdk::World->OwningGameInstance != nullptr && sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn != nullptr)
//	
//	{
//
//		float nearestDistance = FLT_MAX;
//
//		if (sdk::World) {
//			auto Actors = SDK::UWorld::GetWorld()->PersistentLevel->Actors;
//
//			SDK::AActor* nearestActor = nullptr;
//
//
//			auto playerpos = Teleport::GetPlayerPosition();
//
//			for (SDK::AActor* Actor : Actors) {
//				if (Actor && Actor->IsA(SDK::AActor::StaticClass())) {
//					std::string actorInfo = std::string(Actor->BlueprintTypeName.GetRawString()) + " | " + std::to_string(Actor->KuroEntityType);
//
//					if (Actor->KuroEntityType == 7) {
//						if (actorInfo.find("Treasure") != std::string::npos && vars::tpChests) {
//							// Get item position
//							auto itempos = Actor->K2_GetActorLocation();
//
//							// Calculate distance between player and item
//							float distance = sqrt(pow(itempos.X - playerpos.X, 2) + pow(itempos.Y - playerpos.Y, 2) + pow(itempos.Z - playerpos.Z, 2));
//
//							// Check if this is the nearest item
//							if (distance < nearestDistance) {
//								nearestDistance = distance;
//								nearestActor = Actor;
//
//							}
//						}
//					}
//				}
//			}
//		}
	/*float nearestDistance = FLT_MAX;

		if (ImGui::Begin("Info", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings))
		{

			ImGui::SetWindowPos(ImVec2(50, 300), ImGuiCond_Once);
			ImGui::SetWindowSize(ImVec2(150, 50), ImGuiCond_Once);

			ImGui::Text("Treasure %f", nearestDistance);
		}*/
	//}
}



void EspMenu()
{
	ImGui::Checkbox("Esp", &vars::espEnable);
	if (vars::espEnable)
	{
		ImGui::Checkbox("Box Esp", &vars::espBox);
		ImGui::Checkbox("Line Esp", &vars::espLine);

		ImGui::Separator();

		ImGui::Checkbox("NPC", &vars::espNPC);
		ImGui::SameLine();
		ImGui::ColorEdit3("##NPCColor", vars::colorNPC);

		ImGui::Checkbox("Monster", &vars::espMonster);
		ImGui::SameLine();
		ImGui::ColorEdit3("##MonsterColor", vars::colorMonster);

		ImGui::Checkbox("SceneItem", &vars::espSceneItem);
		ImGui::SameLine();
		ImGui::ColorEdit3("##SceneItemColor", vars::colorSceneItem);

		ImGui::Checkbox("Customs", &vars::espCustoms);
		if (vars::espCustoms)
		{

			ImGui::Checkbox("Chests", &vars::espChests);
			ImGui::SameLine();
			ImGui::ColorEdit3("##ChestsColor", vars::colorChest);

			ImGui::Checkbox("Teleport", &vars::espTeleport);
			ImGui::SameLine();
			ImGui::ColorEdit3("##TeleportColor", vars::colorTeleport);

			ImGui::Checkbox("Collectable", &vars::espCollectable);
			ImGui::SameLine();
			ImGui::ColorEdit3("##CollectableColor", vars::colorCollectable);

			ImGui::Checkbox("Other Customs", &vars::espOtherCustoms);
			ImGui::SameLine();
			ImGui::ColorEdit3("##Other Customs Color", vars::colorCustoms);

		}

		ImGui::Checkbox("Vision", &vars::espVision);
		ImGui::SameLine();
		ImGui::ColorEdit3("##VisionColor", vars::colorVision);

		ImGui::Checkbox("Animal", &vars::espAnimal);
		ImGui::SameLine();
		ImGui::ColorEdit3("##AnimalColor", vars::colorAnimal);
	}
}


void TeleportUI()
{
	ImGui::Checkbox("Teleporting", &vars::Teleport);
	if (vars::Teleport)
	{
		ImGui::Text("Quick Teleport Options:");

		ImGui::Checkbox("Teleport to Chests", &vars::tpChests);
		ImGui::Checkbox("Teleport to Teleports", &vars::tpTeleport);
		ImGui::Checkbox("Teleport to Collectables", &vars::tpCollectable);

		ImGui::Separator();

		ImGui::Text("Teleport to Coordinates:");

		ImGui::Columns(4); // Divide the space into 4 columns

		// Input field for X coordinate
		ImGui::InputFloat("x", &vars::PlayerXPos);

		// Input field for Y coordinate
		ImGui::NextColumn();
		ImGui::InputFloat("y", &vars::PlayerYPos);

		// Input field for Z coordinate
		ImGui::NextColumn();
		ImGui::InputFloat("z", &vars::PlayerZPos);

		// Teleport button
		ImGui::NextColumn();
		if (ImGui::Button("Teleport coords"))
		{
			SDK::FVector des = SDK::FVector(vars::PlayerXPos, vars::PlayerYPos, vars::PlayerZPos);
			SDK::FRotator rot = SDK::FRotator(0, 0, 0);
			Teleport::TpPlayerPos(des);
			fprintf(stderr, "Teleported\n");
		}

		ImGui::Columns(1); // Restore to single column layout

		if (ImGui::InputText("Name", vars::nameBuffer, sizeof(vars::nameBuffer)))
		{
			// Update the name as the user types
		}

		if (ImGui::Button("Save Location"))
		{
			auto [x, y, z] = Teleport::GetPlayerPosition();
			JsonLoader::saveTeleportCoords(vars::teleportDirectory, vars::nameBuffer, x, y, z);
		}

		if (ImGui::Button("Load Jsons"))
		{
			vars::JsonsLoaded = true;
			vars::LoadOnce = false;
		}

		if (vars::JsonsLoaded)
		{
			ImGui::SameLine();
			if (ImGui::Checkbox("Select all tp locations", &vars::SelectAllTp))
				vars::SelectAllTpChange = true;
			if (!vars::LoadOnce)
			{
				vars::teleportLocations = JsonLoader::loadAllTeleportCoords(vars::teleportDirectory);
				vars::LoadOnce = true;
			}
			if (vars::SelectAllTp && vars::SelectAllTpChange)
			{
				for (size_t i = 0; i < vars::teleportLocations.size(); ++i)
					vars::teleportLocations[i].selected = true;
				vars::SelectAllTpChange = false;
			}
			else if (!vars::SelectAllTp && vars::SelectAllTpChange)
			{
				for (size_t i = 0; i < vars::teleportLocations.size(); ++i)
					vars::teleportLocations[i].selected = false;
				vars::SelectAllTpChange = false;
			}
			ImGui::BeginChild("TeleportLocations", ImVec2(0, 200), true);
			if (vars::teleportLocations.size() != 0)
			{
				for (size_t i = 0; i < vars::teleportLocations.size(); ++i)
				{
					ImGui::Checkbox(("##" + std::to_string(i)).c_str(), &vars::teleportLocations[i].selected);
					ImGui::SameLine();
					ImGui::Text("%s", (vars::teleportLocations[i].name + " (" + std::to_string(i) + ")").c_str());
				}
			}
			ImGui::EndChild();
			if (vars::teleportLocations.size() != 0)
				if (ImGui::Button("Teleport"))
				{
					Teleport::startTpAsync();
				}
		}
	}
}

void Esp()
{
	//if (sdk::World != nullptr && sdk::World->OwningGameInstance != nullptr && sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn != nullptr && sdk::World->PersistentLevel != nullptr && sdk::World->PersistentLevel->Actors[0] != nullptr)
	//	if (vars::espEnable)
	//	{
	//		if (sdk::World) {
	//			auto Actors = SDK::UWorld::GetWorld()->PersistentLevel->Actors;

	//			for (SDK::AActor* Actor : Actors) {

	//				if (Actor && Actor->IsA(SDK::AActor::StaticClass()))
	//				{

	//					if (Actor->KuroEntityType == 1) // Skip drawing the player
	//						continue;

	//					std::vector<int> color;
	//					bool draw = false;

	//					std::string actorInfo = std::string(Actor->BlueprintTypeName.GetRawString()) + " | " + std::to_string(Actor->KuroEntityType);
	//					//fprintf(stderr, "Info: %s\n", actorInfo.c_str());

	//					switch (Actor->KuroEntityType) {
	//					case 2: // NPC
	//						if (vars::espNPC) {
	//							color = { (int)(vars::colorNPC[0] * 255), (int)(vars::colorNPC[1] * 255), (int)(vars::colorNPC[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					case 4: // Monster
	//						if (vars::espMonster) {
	//							color = { (int)(vars::colorMonster[0] * 255), (int)(vars::colorMonster[1] * 255), (int)(vars::colorMonster[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					case 6: // SceneItem
	//						if (vars::espSceneItem) {
	//							color = { (int)(vars::colorSceneItem[0] * 255), (int)(vars::colorSceneItem[1] * 255), (int)(vars::colorSceneItem[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					case 7: // Customs
	//						if (actorInfo.find("Treasure") != std::string::npos && vars::espChests) {
	//							// This is a treasure, use a different color
	//							color = { (int)(vars::colorChest[0] * 255), (int)(vars::colorChest[1] * 255), (int)(vars::colorChest[2] * 255), 255 };
	//							draw = true;
	//						}
	//						if (actorInfo.find("Teleport") != std::string::npos && vars::espTeleport) {
	//							// Handle teleports
	//							color = { (int)(vars::colorTeleport[0] * 255), (int)(vars::colorTeleport[1] * 255), (int)(vars::colorTeleport[2] * 255), 255 };
	//							draw = true;
	//						}
	//						if (actorInfo.find("Collect") != std::string::npos && vars::espCollectable) {
	//							// Handle collectables
	//							color = { (int)(vars::colorCollectable[0] * 255), (int)(vars::colorCollectable[1] * 255), (int)(vars::colorCollectable[2] * 255), 255 };
	//							draw = true;
	//						}
	//						if (vars::espOtherCustoms && actorInfo.find("Treasure") == std::string::npos && actorInfo.find("Collect") == std::string::npos && vars::espCollectable && actorInfo.find("Teleport") == std::string::npos && vars::espTeleport) {
	//							// Other gameplay entities
	//							color = { (int)(vars::colorCustoms[0] * 255), (int)(vars::colorCustoms[1] * 255), (int)(vars::colorCustoms[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					case 8: // Vision
	//						if (vars::espCustoms) {
	//							color = { (int)(vars::colorCustoms[0] * 255), (int)(vars::colorCustoms[1] * 255), (int)(vars::colorCustoms[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					case 9: // Animal
	//						if (vars::espAnimal) {
	//							color = { (int)(vars::colorAnimal[0] * 255), (int)(vars::colorAnimal[1] * 255), (int)(vars::colorAnimal[2] * 255), 255 };
	//							draw = true;
	//						}
	//						break;
	//					default:
	//						//std::string actorInfo = std::string(Actor->BlueprintTypeName.GetRawString()) + " | " + std::to_string(Actor->KuroEntityType);
	//						//fprintf(stderr, "Info: %s\n",actorInfo.c_str());
	//						break;
	//					}

	//					if (draw && vars::espBox && !vars::espLine) {
	//						ESP::DrawActor(Actor, ESP::DrawMode::Box, ESP::PointMode::Nulls, color, (SDK::AActor*)sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
	//					}
	//					else if (draw && vars::espBox && vars::espLine)
	//					{
	//						ESP::DrawActor(Actor, ESP::DrawMode::Box, ESP::PointMode::Line, color, (SDK::AActor*)sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
	//					}
	//					else if (draw && !vars::espBox && vars::espLine)
	//					{
	//						ESP::DrawActor(Actor, ESP::DrawMode::Chams, ESP::PointMode::Line, color, (SDK::AActor*)sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
	//					}
	//				}
	//			}
	//		}
	//	}
}


float GetMapPos(float x, float y)
{
	//auto line = SDK::UTraceLineElement::GetDefaultObj();
	//line->SetStartLocation(x, y, 10000);
	//line->SetEndLocation(x, y, -1000);
	//line->bIgnoreSelf = true;
	//line->bIsSingle = true;
	//line->bTraceComplex = true;
	//line->WorldContextObject = sdk::World;
	//
	//auto q = SDK::UKuroStaticLibrary::ConvertToTraceType(SDK::ECollisionChannel::ECC_WorldStatic);
	//line->SetTraceTypeQuery(q);

	//if (SDK::UKuroTraceLibrary::LineTrace(line, Util::FString("TraceUtil")))
	//	fprintf(stderr, "Hit\n");
	//for ( auto lin : line->HitResult->LocationZ_Array)
	//{
	//	fprintf(stderr, "Z: %f \n", lin);
	//}
	///*fprintf(stderr, "Z: %f \n", line->HitResult->LocationZ_Array[0]);
	//fprintf(stderr, "Impact point Z: %f \n", line->HitResult->ImpactPointZ_Array[0]);*/
	////fprintf(stderr, "Impact point Z: %f \n", line->HitResult->imp);
}

void TpNeariestActor()
{
	/*if (sdk::World) {
		auto Actors = SDK::UWorld::GetWorld()->PersistentLevel->Actors;
		
		SDK::AActor* nearestActor = nullptr;
		float nearestDistance = FLT_MAX;
		
		auto playerpos = Teleport::GetPlayerPosition();

		for (SDK::AActor* Actor : Actors) {
			if (Actor && Actor->IsA(SDK::AActor::StaticClass())) {
				std::string actorInfo = std::string(Actor->BlueprintTypeName.GetRawString()) + " | " + std::to_string(Actor->KuroEntityType);
				
				if (Actor->KuroEntityType == 7) {
					
					if (actorInfo.find("Collect") != std::string::npos && vars::tpCollectable) {
					
						auto itempos = Actor->K2_GetActorLocation();
						
						
						float distance = sqrt(pow(itempos.X - playerpos.X, 2) + pow(itempos.Y - playerpos.Y, 2) + pow(itempos.Z - playerpos.Z, 2));
					
						
						if (distance >= 200 && distance < nearestDistance) {
							nearestDistance = distance;
							nearestActor = Actor;
						
						}
					}

					if (actorInfo.find("Treasure") != std::string::npos && vars::tpChests) {
					
						auto itempos = Actor->K2_GetActorLocation();

						
						float distance = sqrt(pow(itempos.X - playerpos.X, 2) + pow(itempos.Y - playerpos.Y, 2) + pow(itempos.Z - playerpos.Z, 2));

						
						if (distance >= 200 && distance < nearestDistance) {
							nearestDistance = distance;
							nearestActor = Actor;

						}
					}

					if (actorInfo.find("Teleport") != std::string::npos && vars::tpTeleport) {
						
						auto itempos = Actor->K2_GetActorLocation();

						
						float distance = sqrt(pow(itempos.X - playerpos.X, 2) + pow(itempos.Y - playerpos.Y, 2) + pow(itempos.Z - playerpos.Z, 2));

						
						if (distance >= 200 && distance < nearestDistance) {
							nearestDistance = distance;
							nearestActor = Actor;

						}
					}
				}
			}
		}

		
		if (nearestActor) {
			auto nearestItemPos = nearestActor->K2_GetActorLocation();
			nearestItemPos.Z += 75;
			nearestItemPos.X += 75;
			nearestItemPos.Y += 75;
			Teleport::TpPlayerPos(nearestItemPos);
		}
	}*/
}


