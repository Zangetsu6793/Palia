#include "Utils.h"


namespace Scripts
{
    std::string eval(std::string script)
    {
        auto source = Util::FString((char*)script.c_str());
        auto out = SDK::UWorldFunctionLibrary_C::EvalScript(source, sdk::World);
        return out.ToString();
    }

     bool isMapOpen() 
     {
        if (sdk::World == nullptr) return false;
        return eval("require('../Ui/UiManager').UiManager.IsViewOpen('WorldMapView')") == "true";
     }

    
}


namespace Util
{
    SDK::FString FString(std::string str) 
    {
        size_t convertedChars = 0;
        size_t sizeInBytes = str.length() + 1;
        std::unique_ptr<wchar_t[]> wPath(new wchar_t[sizeInBytes]);
        mbstowcs_s(&convertedChars, wPath.get(), sizeInBytes, str.c_str(), _TRUNCATE);
        SDK::FString result(wPath.get());
        return result;
    }

}