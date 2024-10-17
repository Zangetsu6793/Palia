#pragma once


#include <vector>
#include <string>


 struct JsonSaveFile {
	std::string name;
	float x, y, z;
	bool selected = false;
};

#include "sdk.h"
namespace JsonLoader {

	 std::vector<JsonSaveFile> loadAllTeleportCoords(const std::string& directory);
     void saveTeleportCoords(const std::string& directory, std::string name, float x, float y, float z);
	void saveConfig(const std::string& configName);
	void loadConfig(const std::string& configName);
};
