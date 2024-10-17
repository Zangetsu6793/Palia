#include "JsonHelper.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "../nlohmann/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

namespace JsonLoader
{
	



	 std::vector<JsonSaveFile> loadAllTeleportCoords(const std::string& directory) {
		std::vector<JsonSaveFile> teleportLocations;

		// Ensure the directory exists
		if (!fs::exists(directory)) {
			fs::create_directories(directory);
		}

		for (const auto& entry : fs::directory_iterator(directory)) {
			if (entry.is_regular_file() && entry.path().extension() == ".json") {
				std::ifstream file(entry.path());
				if (file.is_open()) {
					try {
						json jsonData;
						file >> jsonData;
						file.close();

						JsonSaveFile saveFile;
						saveFile.name = jsonData["Name"];
						saveFile.x = jsonData["x"];
						saveFile.y = jsonData["y"];
						saveFile.z = jsonData["z"];
						teleportLocations.push_back(saveFile);
					}
					catch (const std::exception& e) {
						std::cerr << "Error parsing JSON: " << e.what() << std::endl;
						file.close();
						continue;
					}
				}
				else {
					std::cerr << "Error opening file: " << entry.path() << std::endl;
					continue;
				}
			}
		}

		return teleportLocations;
	}

	 void saveTeleportCoords(const std::string& directory, std::string name, float x, float y, float z) {
		// Ensure the directory exists
		if (!fs::exists(directory)) {
			fs::create_directories(directory);
		}

		int index = 0;
		std::string filename;
		do {
			filename = directory + "/teleport" + std::to_string(index++) + ".json";
		} while (fs::exists(filename));

		json jsonData;
		jsonData["Name"] = name;
		jsonData["x"] = x;
		jsonData["y"] = y;
		jsonData["z"] = z;

		std::ofstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;
		}

		try {
			file << std::setw(4) << jsonData << std::endl;
			file.close();
		}
		catch (const std::exception& e) {
			std::cerr << "Error writing JSON: " << e.what() << std::endl;
			file.close();
			return;
		}

		std::cerr << "Teleport coordinates written to file: " << filename << std::endl;
	}


	void JsonLoader::saveConfig(const std::string& configName) {
		char dllPath[MAX_PATH];
		HMODULE hModule = GetModuleHandle(nullptr);
		GetModuleFileName(hModule, dllPath, MAX_PATH);
		std::filesystem::path configDirectory = std::filesystem::path(dllPath).parent_path();

		std::string filename = (configDirectory / (configName + ".json")).string();

		json configData;
		// Save all variables from the vars namespace
		configData["PlayerXPos"] = vars::PlayerXPos;
		configData["PlayerYPos"] = vars::PlayerYPos;
		configData["PlayerZPos"] = vars::PlayerZPos;
		configData["Teleport"] = vars::Teleport;
		configData["SelectAllTp"] = vars::SelectAllTp;
		configData["SelectAllTpChange"] = vars::SelectAllTpChange;
		configData["LoadOnce"] = vars::LoadOnce;
		//configData["JsonsLoaded"] = vars::JsonsLoaded;
		configData["FlySpeed"] = vars::FlySpeed;
		configData["noClip"] = vars::noClip;
		configData["noClipOn"] = vars::noClipOn;
		configData["AutoLoot"] = vars::AutoLoot;
		configData["bPressF"] = vars::bPressF;
		configData["distanceThreshold"] = vars::distanceThreshold;
		configData["espEnable"] = vars::espEnable;
		configData["espBox"] = vars::espBox;
		configData["espLine"] = vars::espLine;
		configData["espNPC"] = vars::espNPC;
		configData["espMonster"] = vars::espMonster;
		configData["espSceneItem"] = vars::espSceneItem;
		configData["espCustoms"] = vars::espCustoms;
		configData["espOtherCustoms"] = vars::espOtherCustoms;
		configData["espVision"] = vars::espVision;
		configData["espAnimal"] = vars::espAnimal;
		configData["espChests"] = vars::espChests;
		configData["espTeleport"] = vars::espTeleport;
		configData["espCollectable"] = vars::espCollectable;
		configData["colorNPC"] = { vars::colorNPC[0], vars::colorNPC[1], vars::colorNPC[2] };
		configData["colorMonster"] = { vars::colorMonster[0], vars::colorMonster[1], vars::colorMonster[2] };
		configData["colorSceneItem"] = { vars::colorSceneItem[0], vars::colorSceneItem[1], vars::colorSceneItem[2] };
		configData["colorCustoms"] = { vars::colorCustoms[0], vars::colorCustoms[1], vars::colorCustoms[2] };
		configData["colorVision"] = { vars::colorVision[0], vars::colorVision[1], vars::colorVision[2] };
		configData["colorAnimal"] = { vars::colorAnimal[0], vars::colorAnimal[1], vars::colorAnimal[2] };
		configData["colorChest"] = { vars::colorChest[0], vars::colorChest[1], vars::colorChest[2] };
		configData["colorTeleport"] = { vars::colorTeleport[0], vars::colorTeleport[1], vars::colorTeleport[2] };
		configData["colorCollectable"] = { vars::colorCollectable[0], vars::colorCollectable[1], vars::colorCollectable[2] };
		configData["x"] = vars::x;
		configData["y"] = vars::y;
		configData["tpChests"] = vars::tpChests;
		configData["tpTeleport"] = vars::tpTeleport;
		configData["tpCollectable"] = vars::tpCollectable;

		std::ofstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;
		}

		try {
			file << std::setw(4) << configData << std::endl;
			file.close();
		}
		catch (const std::exception& e) {
			std::cerr << "Error writing JSON: " << e.what() << std::endl;
			file.close();
		}

		std::cerr << "Configuration saved to file: " << filename << std::endl;
	}

	void JsonLoader::loadConfig(const std::string& configName) {
		char dllPath[MAX_PATH];
		HMODULE hModule = GetModuleHandle(nullptr);
		GetModuleFileName(hModule, dllPath, MAX_PATH);
		std::filesystem::path configDirectory = std::filesystem::path(dllPath).parent_path();

		std::string filename = (configDirectory / (configName + ".json")).string();

		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;
		}

		try {
			json configData;
			file >> configData;
			file.close();

			// Load all variables into the vars namespace
			if (configData.contains("PlayerXPos")) vars::PlayerXPos = configData["PlayerXPos"];
			if (configData.contains("PlayerYPos")) vars::PlayerYPos = configData["PlayerYPos"];
			if (configData.contains("PlayerZPos")) vars::PlayerZPos = configData["PlayerZPos"];
			if (configData.contains("Teleport")) vars::Teleport = configData["Teleport"];
			if (configData.contains("SelectAllTp")) vars::SelectAllTp = configData["SelectAllTp"];
			if (configData.contains("SelectAllTpChange")) vars::SelectAllTpChange = configData["SelectAllTpChange"];
			if (configData.contains("LoadOnce")) vars::LoadOnce = configData["LoadOnce"];
			//if (configData.contains("JsonsLoaded")) vars::JsonsLoaded = configData["JsonsLoaded"];
			if (configData.contains("FlySpeed")) vars::FlySpeed = configData["FlySpeed"];
			if (configData.contains("noClip")) vars::noClip = configData["noClip"];
			if (configData.contains("noClipOn")) vars::noClipOn = configData["noClipOn"];
			if (configData.contains("AutoLoot")) vars::AutoLoot = configData["AutoLoot"];
			if (configData.contains("bPressF")) vars::bPressF = configData["bPressF"];
			if (configData.contains("distanceThreshold")) vars::distanceThreshold = configData["distanceThreshold"];
			if (configData.contains("espEnable")) vars::espEnable = configData["espEnable"];
			if (configData.contains("espBox")) vars::espBox = configData["espBox"];
			if (configData.contains("espLine")) vars::espLine = configData["espLine"];
			if (configData.contains("espNPC")) vars::espNPC = configData["espNPC"];
			if (configData.contains("espMonster")) vars::espMonster = configData["espMonster"];
			if (configData.contains("espSceneItem")) vars::espSceneItem = configData["espSceneItem"];
			if (configData.contains("espCustoms")) vars::espCustoms = configData["espCustoms"];
			if (configData.contains("espOtherCustoms")) vars::espOtherCustoms = configData["espOtherCustoms"];
			if (configData.contains("espVision")) vars::espVision = configData["espVision"];
			if (configData.contains("espAnimal")) vars::espAnimal = configData["espAnimal"];
			if (configData.contains("espChests")) vars::espChests = configData["espChests"];
			if (configData.contains("espTeleport")) vars::espTeleport = configData["espTeleport"];
			if (configData.contains("espCollectable")) vars::espCollectable = configData["espCollectable"];
			if (configData.contains("colorNPC")) {
				vars::colorNPC[0] = configData["colorNPC"][0];
				vars::colorNPC[1] = configData["colorNPC"][1];
				vars::colorNPC[2] = configData["colorNPC"][2];
			}
			if (configData.contains("colorMonster")) {
				vars::colorMonster[0] = configData["colorMonster"][0];
				vars::colorMonster[1] = configData["colorMonster"][1];
				vars::colorMonster[2] = configData["colorMonster"][2];
			}
			if (configData.contains("colorSceneItem")) {
				vars::colorSceneItem[0] = configData["colorSceneItem"][0];
				vars::colorSceneItem[1] = configData["colorSceneItem"][1];
				vars::colorSceneItem[2] = configData["colorSceneItem"][2];
			}
			if (configData.contains("colorCustoms")) {
				vars::colorCustoms[0] = configData["colorCustoms"][0];
				vars::colorCustoms[1] = configData["colorCustoms"][1];
				vars::colorCustoms[2] = configData["colorCustoms"][2];
			}
			if (configData.contains("colorVision")) {
				vars::colorVision[0] = configData["colorVision"][0];
				vars::colorVision[1] = configData["colorVision"][1];
				vars::colorVision[2] = configData["colorVision"][2];
			}
			if (configData.contains("colorAnimal")) {
				vars::colorAnimal[0] = configData["colorAnimal"][0];
				vars::colorAnimal[1] = configData["colorAnimal"][1];
				vars::colorAnimal[2] = configData["colorAnimal"][2];
			}
			if (configData.contains("colorChest")) {
				vars::colorChest[0] = configData["colorChest"][0];
				vars::colorChest[1] = configData["colorChest"][1];
				vars::colorChest[2] = configData["colorChest"][2];
			}
			if (configData.contains("colorTeleport")) {
				vars::colorTeleport[0] = configData["colorTeleport"][0];
				vars::colorTeleport[1] = configData["colorTeleport"][1];
				vars::colorTeleport[2] = configData["colorTeleport"][2];
			}
			if (configData.contains("colorCollectable")) {
				vars::colorCollectable[0] = configData["colorCollectable"][0];
				vars::colorCollectable[1] = configData["colorCollectable"][1];
				vars::colorCollectable[2] = configData["colorCollectable"][2];
			}
			if (configData.contains("x")) vars::x = configData["x"];
			if (configData.contains("y")) vars::y = configData["y"];
			if (configData.contains("tpChests")) vars::tpChests = configData["tpChests"];
			if (configData.contains("tpTeleport")) vars::tpTeleport = configData["tpTeleport"];
			if (configData.contains("tpCollectable")) vars::tpCollectable = configData["tpCollectable"];
		}
		catch (const std::exception& e) {
			std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			file.close();
		}

		std::cerr << "Configuration loaded from file: " << filename << std::endl;
	}
}
