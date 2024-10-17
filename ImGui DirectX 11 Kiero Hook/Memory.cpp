#include "Memory.h"

namespace Memory {

    void ChangeMemoryProtection(uintptr_t address, size_t size, DWORD newProtection, DWORD& oldProtection) {
        VirtualProtect(reinterpret_cast<void*>(address), size, newProtection, &oldProtection);
    }

    // Reading functions
    float ReadFloat(uintptr_t address) {
        return *reinterpret_cast<float*>(address);
    }

    int ReadInt(uintptr_t address) {
        return *reinterpret_cast<int*>(address);
    }

    double ReadDouble(uintptr_t address) {
        return *reinterpret_cast<double*>(address);
    }

    uint32_t Read4Bytes(uintptr_t address) {
        return *reinterpret_cast<uint32_t*>(address);
    }

    // Writing functions
    void WriteFloat(uintptr_t address, float value) {
        DWORD oldProtection;
        ChangeMemoryProtection(address, sizeof(float), PAGE_EXECUTE_READWRITE, oldProtection);

        *reinterpret_cast<float*>(address) = value;

        ChangeMemoryProtection(address, sizeof(float), oldProtection, oldProtection);
    }

    void WriteInt(uintptr_t address, int value) {
        DWORD oldProtection;
        ChangeMemoryProtection(address, sizeof(int), PAGE_EXECUTE_READWRITE, oldProtection);

        *reinterpret_cast<int*>(address) = value;

        ChangeMemoryProtection(address, sizeof(int), oldProtection, oldProtection);
    }

    void WriteDouble(uintptr_t address, double value) {
        DWORD oldProtection;
        ChangeMemoryProtection(address, sizeof(double), PAGE_EXECUTE_READWRITE, oldProtection);

        *reinterpret_cast<double*>(address) = value;

        ChangeMemoryProtection(address, sizeof(double), oldProtection, oldProtection);
    }

    void Write4Bytes(uintptr_t address, uint32_t value) {
        DWORD oldProtection;
        ChangeMemoryProtection(address, sizeof(uint32_t), PAGE_EXECUTE_READWRITE, oldProtection);

        *reinterpret_cast<uint32_t*>(address) = value;

        ChangeMemoryProtection(address, sizeof(uint32_t), oldProtection, oldProtection);
    }

    bool bOpened = false;
    DWORD oldProtectionC;
    void WriteFloatConstant(uintptr_t address, float value, bool bDone) {
        if (!bOpened) {
            ChangeMemoryProtection(address, sizeof(float), PAGE_EXECUTE_READWRITE, oldProtectionC);
            bOpened = true;
        }

        *reinterpret_cast<float*>(address) = value;

        if (bDone) {
            ChangeMemoryProtection(address, sizeof(float), oldProtectionC, oldProtectionC);
            bOpened = false;
        }
    }

    // Pointer chain function
    uintptr_t FollowPointerChain(uintptr_t base, const std::ptrdiff_t* offsets, size_t count) {
        uintptr_t address = base;
        for (size_t i = 0; i < count; ++i) {
            address = *reinterpret_cast<uintptr_t*>(address);
            address += offsets[i];
        }
        return address;
    }

    // String manipulation functions
    std::vector<uintptr_t> FindString(uintptr_t baseAddress, size_t memorySize, const std::wstring& targetString) {
        std::vector<uintptr_t> addresses;
        const wchar_t* memoryRegion = reinterpret_cast<const wchar_t*>(baseAddress);
        size_t targetLength = targetString.size();
        for (size_t i = 0; i < memorySize / sizeof(wchar_t) - targetLength; ++i) {
            if (wcsncmp(&memoryRegion[i], targetString.c_str(), targetLength) == 0) {
                addresses.push_back(reinterpret_cast<uintptr_t>(&memoryRegion[i]));
            }
        }
        return addresses;
    }

    void ModifyString(uintptr_t address, const std::wstring& newString) {
        DWORD oldProtection;
        size_t size = newString.size() * sizeof(wchar_t);
        ChangeMemoryProtection(address, size, PAGE_EXECUTE_READWRITE, oldProtection);

        wcsncpy_s(reinterpret_cast<wchar_t*>(address), newString.size() + 1, newString.c_str(), newString.size());

        ChangeMemoryProtection(address, size, oldProtection, oldProtection);
    }

    size_t CalculateMemorySize(const std::wstring& targetString) {
        return targetString.size() * sizeof(wchar_t);
    }


} // namespace Memory
