#include <iostream>
#include <Windows.h>
#include <string>
#include <filesystem>
#include <vector>
#include <TlHelp32.h>

namespace fs = std::filesystem;

std::wstring utf8_to_wstring(const std::string& str) {
	int wstr_size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	std::wstring wstr(wstr_size, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], wstr_size);
	return wstr;
}

std::string wstring_to_utf8(const std::wstring& wstr) {
	int str_size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
	std::string str(str_size, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], str_size, NULL, NULL);
	return str;
}

HANDLE open_process(const std::wstring& path) {
	HWND hwnd = FindWindow(nullptr, path.c_str());
	if (hwnd == NULL) {
		std::wcout << "Error: Game window not found." << std::endl;
		return NULL;
	}

	int pid = GetWindowThreadProcessId(hwnd, NULL);
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, pid);

	if (hProcess == NULL) {
		std::wcout << "Error: Failed to open game process." << std::endl;
		return NULL;
	}

	return hProcess;
}

bool inject_dll(HANDLE hProcess, const std::wstring& dll_path) {
	HMODULE hKernel32 = GetModuleHandleA("kernel32.dll");
	if (hKernel32 == NULL) {
		std::cout << "Failed to get handle to kernel32.dll." << std::endl;
		return false;
	}

	FARPROC load_library_proc = GetProcAddress(hKernel32, "LoadLibraryA");
	if (load_library_proc == NULL) {
		std::cout << "Failed to get address of LoadLibraryA." << std::endl;
		return false;
	}

	std::string dll_path_utf8 = wstring_to_utf8(dll_path);

	LPVOID allocated_memory = VirtualAllocEx(hProcess, NULL, dll_path_utf8.size() + 1, MEM_COMMIT, PAGE_READWRITE);
	if (allocated_memory == NULL) {
		std::cout << "Failed to allocate memory for the DLL path." << std::endl;
		return false;
	}

	if (!WriteProcessMemory(hProcess, allocated_memory, dll_path_utf8.c_str(), dll_path_utf8.size() + 1, NULL)) {
		std::cout << "Failed to write DLL path to the target process' memory." << std::endl;
		return false;
	}

	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)load_library_proc, allocated_memory, 0, NULL);
	if (hRemoteThread == NULL) {
		std::cout << "Failed to create remote thread." << std::endl;
		return false;
	}

	CloseHandle(hRemoteThread);
	return true;
}

HANDLE find_process(const std::wstring& path) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		std::cout << "Failed to create snapshot of the current process list." << std::endl;
		return NULL;
	}

	PROCESSENTRY32W processEntry;
	processEntry.dwSize = sizeof(processEntry);

	if (!Process32FirstW(hSnapshot, &processEntry)) {
		CloseHandle(hSnapshot);
		std::cout << "Failed to obtain the first process in the snapshot." << std::endl;
		return NULL;
	}

	std::wstring exe_path(processEntry.szExeFile);

	while (Process32NextW(hSnapshot, &processEntry)) {
		std::wstring current_path(processEntry.szExeFile);

		if (current_path == path) {
			HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, processEntry.th32ProcessID);
			if (hProcess != NULL) {
				CloseHandle(hSnapshot);
				return hProcess;
			}
		}
	}

	CloseHandle(hSnapshot);
	return NULL;
}

int main() {

	std::wstring target_process = L"Client-Win64-Shipping.exe";

	std::wstring Cheat_dll = std::filesystem::current_path().wstring() + L"\\WWC.dll";
	std::wstring Bypass_dll = std::filesystem::current_path().wstring() + L"\\Bypass.dll";
	//std::wstring 




	HANDLE hProcess = find_process(target_process);
	
	while(!hProcess)
	{
		system("cls");
		printf("Waiting for Game");
		hProcess = find_process(target_process);


		if (hProcess != NULL) {
			Sleep(100);
			inject_dll(hProcess, Bypass_dll);
			printf("Bpassed AC");
			inject_dll(hProcess, Cheat_dll);
			printf("Cheat Injected Enjoy");
			CloseHandle(hProcess);
		}
		Sleep(100);
	}

	system("sleep");

	return 0;
}