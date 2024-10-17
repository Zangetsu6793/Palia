#include "Utils.h"


namespace Scripts
{
   

    
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