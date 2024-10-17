#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint> // For uintptr_t, uint32_t
#include <Windows.h> // For DWORD
#include <vector>
#include <string>

namespace Memory {

    // Define function prototypes
    void ChangeMemoryProtection(uintptr_t address, size_t size, DWORD newProtection, DWORD& oldProtection);

    // Reading functions
    float ReadFloat(uintptr_t address);
    int ReadInt(uintptr_t address);
    double ReadDouble(uintptr_t address);
    uint32_t Read4Bytes(uintptr_t address);

    // Writing functions
    void WriteFloat(uintptr_t address, float value);
    void WriteInt(uintptr_t address, int value);
    void WriteDouble(uintptr_t address, double value);
    void Write4Bytes(uintptr_t address, uint32_t value);
    void WriteFloatConstant(uintptr_t address, float value, bool bDone);

    // Pointer chain function
    uintptr_t FollowPointerChain(uintptr_t base, const std::ptrdiff_t* offsets, size_t count);

    // String manipulation functions
    std::vector<uintptr_t> FindString(uintptr_t baseAddress, size_t memorySize, const std::wstring& targetString);
    void ModifyString(uintptr_t address, const std::wstring& newString);

    // Calculate memory size required for a string
    size_t CalculateMemorySize(const std::wstring& str);
}

#endif // MEMORY_H
