#include "includes.h"
#include "./main.h"
#include "../ImGui DirectX 11 Kiero Hook/kiero/minhook/include/MinHook.h"


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
;


#pragma region ImGui



/////////////////////////////////////////////////////////

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;
	if (show_menu)  // <-- thats what u need 
		return true;
	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;

static DWORD lasttick = 0;
void renderloop()
{
	DWORD currentTime = GetTickCount64(); // Get current time in milliseconds

	if (currentTime - lasttick > 5) //  5 ms Timer For Whatever you want to do
	{

		lasttick = currentTime;
	}
}


HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{

	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			ImGui::GetIO().Fonts->AddFontDefault();
			ImFontConfig font_cfg;
			font_cfg.GlyphExtraSpacing.x = 1.2;
			gameFont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(TTSquaresCondensedBold, 14, 14, &font_cfg);
			ImGui::GetIO().Fonts->AddFontDefault();
			// Grab A shader Here If You want
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	pContext->RSGetViewports(&vars::vps, &vars::viewport);
	vars::screen_size = { vars::viewport.Width, vars::viewport.Height };
	vars::screen_center = { vars::viewport.Width / 2.0f, vars::viewport.Height / 2.0f };

	auto begin_scene = [&]() {
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		};

	auto end_scene = [&]() {
		ImGui::Render();
		};

	begin_scene();

	auto isFrames = ImGui::GetFrameCount();
	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
	if (isFrames % 1 == 0)
	{
		if (isGreen == 0.01f && isBlue == 0.0f)
		{
			isRed += 0.01f;

		}
		if (isRed > 0.99f && isBlue == 0.0f)
		{
			isRed = 1.0f;

			isGreen += 0.01f;

		}
		if (isGreen > 0.99f && isBlue == 0.0f)
		{
			isGreen = 1.0f;

			isRed -= 0.01f;

		}
		if (isRed < 0.01f && isGreen == 1.0f)
		{
			isRed = 0.0f;

			isBlue += 0.01f;

		}
		if (isBlue > 0.99f && isRed == 0.0f)
		{
			isBlue = 1.0f;

			isGreen -= 0.01f;

		}
		if (isGreen < 0.01f && isBlue == 1.0f)
		{
			isGreen = 0.0f;

			isRed += 0.01f;

		}
		if (isRed > 0.99f && isGreen == 0.0f)
		{
			isRed = 1.0f;

			isBlue -= 0.01f;

		}
		if (isBlue < 0.01f && isGreen == 0.0f)
		{
			isBlue = 0.0f;

			isRed -= 0.01f;

			if (isRed < 0.01f)
				isGreen = 0.01f;

		}
	}
	vars::Rainbow = ImVec4(isRed, isGreen, isBlue, 1.0f);

	if (vars::watermark)
	{
		render::DrawOutlinedText(gameFont, ImVec2(vars::screen_center.x, vars::screen_size.y - 20), 13.0f, ImColor(vars::Rainbow.x, vars::Rainbow.y, vars::Rainbow.z), true, "[ WWC ]");
		render::DrawOutlinedText(gameFont, ImVec2(vars::screen_center.x, 5), 13.0f, ImColor(vars::Rainbow.x, vars::Rainbow.y, vars::Rainbow.z), true, "[ %.1f FPS ]", ImGui::GetIO().Framerate);
	}

	POINT mousePos;
	GetCursorPos(&mousePos);
	ScreenToClient(window, &mousePos);



	Esp();

	if (show_info)
	{
		DrawInfo();
	}

	if (show_menu)
	{
		// X Mouse Cursor
		//render::DrawOutlinedTextForeground(gameFont, ImVec2(mousePos.x, mousePos.y), 13.0f, ImColor(vars::Rainbow.x, vars::Rainbow.y, vars::Rainbow.z), false, "X");
		DrawMenu();
	}
	// Render
	try
	{
		renderloop();
	}
	catch (...) {}

	end_scene();

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		show_menu = !show_menu;
		ImGui::GetIO().MouseDrawCursor = show_menu;
		//JsonLoader::saveConfig("Config");
	}

	if (GetKeyState(VK_END))
	{
		FreeLibraryAndExitThread(static_cast<HMODULE>(GetModuleHandle(NULL)), 0);
	}

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	//IL2CPP::Thread::Detach(m_pThisThread);

	return oPresent(pSwapChain, SyncInterval, Flags);
}



//////////////////////////////////////////////////////////
#pragma endregion

void* this_fjs = nullptr;
void* Isolate_ptr = nullptr;
//v8::Local<v8::Context> context;

void ReloadAllJs()
{/*

	UC::FString Path = L"../../../Client/Content/Aki/JavaScript/Game/NewWorld/SceneItem/";
	UC::FString Filter = L"*";
	bool IncludeFiles = true;
	bool IncludeDirectories = false;
	UC::TArray<UC::FString> Files = SDK::UKuroStaticLibrary::LoadFilesRecursive(Path, Filter, IncludeFiles, IncludeDirectories);
*/

/*UC::FString ScriptContent = L"\n"
	"const LogW = logger.warn;\n"
	"\n"
	"LogW(`test1234test4321`);\n";

UC::FString ScriptPath = L"..\\..\\..\\Client\\Content\\Aki\\JavaScript\\Game\\NewWorld\\SceneItem\\test.js";
SDK::UKuroStaticLibrary::SaveStringToFile(ScriptContent, ScriptPath, false);
SDK::UKismetStringLibrary* lib = SDK::UKismetStringLibrary::GetDefaultObj();
SDK::UPuertsBlueprintLibrary* puertLib = SDK::UPuertsBlueprintLibrary::GetDefaultObj();
SDK::FName module = lib->Conv_StringToName(tester);
SDK::UGameInstance* gameInstance = SDK::UGameplayStatics::GetGameInstance(SDK::UWorld::GetWorld());
puertLib->ExecuteModuleInSharedJsEnv(module);*/



//if (this_fjs == nullptr)
//	return;

//typedef void (*JsReloadModuleFn)(void* this_, void* name, const UC::FString& source);
//JsReloadModuleFn o_Reload = (JsReloadModuleFn)(reinterpret_cast<uint64_t>(GetModuleHandleW(L"Client-Win64-Shipping.exe")) + 0x138bd60);

//const wchar_t* source = L"this.Entity.CheckGetComponent(116).IsInState(2)";
//
////std::string module_name_str = "CharacterSkillCdComponent";
//
//const char* module_name_str = "GamePlayTreasureBoxComponent.js";
//// Convert const char* to std::wstring
//size_t convertedChars = 0;
//size_t sizeInBytes = strlen(module_name_str) + 1;
//std::unique_ptr<wchar_t[]> wPath(new wchar_t[sizeInBytes]);
//mbstowcs_s(&convertedChars, wPath.get(), sizeInBytes, module_name_str, _TRUNCATE);

//UC::FString module_name_fstr(wPath.get());
//SDK::FName name = SDK::UKismetStringLibrary::Conv_StringToName(module_name_fstr);


/////void* module_name = reinterpret_cast<void*>(static_cast<uintptr_t>(&name));
////void* module_name = reinterpret_cast<void*>(&name);
//void* module_name = &name;

//o_Reload(this_fjs, module_name, UC::FString((wchar_t*)source));
}
//
//void ReloadScripts()
//{
//	//std::cout << "Reloading scripts..." << std::endl;
//	fprintf(stderr, "Reloading scripts... %d\n", 1);
//	SDK::UKuroPakMountStatic* PakMountStatic = SDK::UKuroPakMountStatic::GetDefaultObj();
//	if (PakMountStatic)
//	{
//		const char* pakPath = "C:\Program Files\Wuthering Waves\Wuthering Waves Game\Client\Content\Paks\pakchunk11-WindowsNoEditor.pak"; // Converting std::string to FString
//
//		// Convert const char* to std::wstring
//		size_t convertedChars = 0;
//		size_t sizeInBytes = strlen(pakPath) + 1;
//		std::unique_ptr<wchar_t[]> wPath(new wchar_t[sizeInBytes]);
//		mbstowcs_s(&convertedChars, wPath.get(), sizeInBytes, pakPath, _TRUNCATE);
//
//		UC::FString pakPathFString(wPath.get());
//
//		//std::cout << "Unmounting existing pak..." << std::endl;
//		fprintf(stderr, "Unmounting existing pak... %d\n", 1);
//		PakMountStatic->UnmountPak(pakPathFString);
//
//		//std::cout << "Mounting new pak..." << std::endl;
//		fprintf(stderr, "Mounting new pak... %d\n", 1);
//		PakMountStatic->MountPak(pakPathFString, 0);
//
//		fprintf(stderr, "Scripts reloaded successfully... %d", 1);
//		//std::cout << "Scripts reloaded successfully." << std::endl;
//	}
//	else
//	{
//		std::cout << "Failed to get KuroPakMountStatic object." << std::endl;
//	}
//}


//void CallJavaScriptFunction(v8::Isolate* isolate, v8::Local<v8::Context> context, const char* funcName, const char* arg)
//{
//	v8::HandleScope handle_scope(isolate);
//	v8::Context::Scope context_scope(context);
//
//	// Retrieve the JavaScript function by name
//	v8::Local<v8::String> function_name = v8::String::NewFromUtf8(isolate, funcName).ToLocalChecked();
//	v8::Local<v8::Value> func_val = context->Global()->Get(context, function_name).ToLocalChecked();
//
//	if (func_val->IsFunction()) {
//		v8::Local<v8::Function> func = v8::Local<v8::Function>::Cast(func_val);
//		v8::Local<v8::String> arg_value = v8::String::NewFromUtf8(isolate, arg).ToLocalChecked();
//		v8::Local<v8::Value> argv[1] = { arg_value };
//		v8::Local<v8::Value> result = func->Call(context, context->Global(), 1, argv).ToLocalChecked();
//
//		v8::String::Utf8Value utf8(isolate, result);
//		fprintf(stderr, "%s\n", *utf8); // Print the result from JavaScript
//	}
//	else {
//		fprintf(stderr, "Error: Function %s not found or not a function.\n", function_name);
//	}
//}






typedef void* (*NewString)(void*, void*, const char*, int, int);
NewString originalNewString;

void* hook_NewString(void* this_, void* Isolate, const char* data, int type, int length)
{
	this_fjs = this_;
	Isolate_ptr = Isolate;

	std::string scriptData(data);
	if (std::string(data).find("__esModule") != std::string::npos)
	{
		//V8Cont(Isolate);
		//fprintf(stderr, "Module found\n");
		//fprintf(stderr, "hook_EvalScript called with data: %s\n", data);

		size_t pos = scriptData.find("this.Entity.CheckGetComponent(116).IsInState(2)");
		if (pos != std::string::npos) {
			//scriptData.replace(pos, std::string("this.Entity.CheckGetComponent(116).IsInState(2)").length(), "this.Entity.CheckGetComponent(116).IsInState(1)");
			fprintf(stderr, "changed it!\n");
			//fprintf(stderr, "Isolate pointer %p\n", Isolate);
		}
		if (std::string(data).find("class ShopController") != std::string::npos)
			fprintf(stderr, "Shop Isolate pointer %p\n", Isolate);

		/*if (std::string(data).find("class ShopController") != std::string::npos)
		{

			size_t pos = scriptData.find("ModelManager.ShopModel.IsOpen(e)");
			if (pos != std::string::npos) {
				scriptData.replace(pos, std::string("ModelManager.ShopModel.IsOpen(e)").length(), "ModelManager.ShopModel.IsOpen(4)");

			}
			pos = scriptData.find("UiManager_1.UiManager.OpenView(\"ShopView\", e)");
			if (pos != std::string::npos) {
				scriptData.replace(pos, std::string("UiManager_1.UiManager.OpenView(\"ShopView\", e)").length(), "UiManager_1.UiManager.OpenView(\"ShopView\", 4)");

			}
			pos = scriptData.find("ModelManager_1.ModelManager.ShopModel.GetShopConfig(e).ShopName");
			if (pos != std::string::npos) {
				scriptData.replace(pos, std::string("ModelManager_1.ModelManager.ShopModel.GetShopConfig(e).ShopName").length(), "ModelManager_1.ModelManager.ShopModel.GetShopConfig(4).ShopName");

			}

			fprintf(stderr, "changed Shop id!\n");
		}
*/

	}
	return originalNewString(this_, Isolate, scriptData.c_str(), type, length);

}
SDK::UPuertsSetting* SafeGetDefaultObj()
{
	__try {
		return SDK::GetDefaultObjImpl<SDK::UPuertsSetting>();
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		std::cerr << "Exception caught while calling GetDefaultObjImpl<SDK::UPuertsSetting>()!" << std::endl;
		return nullptr;
	}
}



//#pragma region V8
//
//
//void GetV8Context(void* Isolate_ptr) {
//	if (!Isolate_ptr) {
//		fprintf(stderr, "Invalid isolate pointer\n");
//		return;
//	}
//
//	v8::Isolate* isolate = reinterpret_cast<v8::Isolate*>(Isolate_ptr);
//
//	// Ensure that V8 is properly initialized
//	/*if (!v8::V8::Initialize()) {
//		fprintf(stderr, "Failed to initialize V8\n");
//		return;
//	}*/
//
//	// Ensure that the isolate is in a context
//	if (!isolate->InContext()) {
//		fprintf(stderr, "Isolate is not in a context. Entering context explicitly.\n");
//
//		// Enter a context explicitly
//		v8::Isolate::Scope isolate_scope(isolate);
//		v8::HandleScope handle_scope(isolate);
//
//		context = v8::Context::New(isolate);
//		if (context.IsEmpty()) {
//			fprintf(stderr, "Failed to create a new context\n");
//			return;
//		}
//
//		v8::Context::Scope context_scope(context);
//
//		// Now the isolate is in the context
//	}
//
//	// Retrieve the current context
//	fprintf(stderr, "Attempting to retrieve the current context\n");
//
//	v8::Local<v8::Context> context = isolate->GetCurrentContext();
//
//	// Check if the context is available
//	if (context.IsEmpty()) {
//		fprintf(stderr, "Failed to retrieve the current context\n");
//		return;
//	}
//
//	// Print the context
//	fprintf(stderr, "Context: %p\n", *context);
//}
//
//
//void V8Cont(void* Isolate_ptr)
//{
//	// Get the V8 version
//	const char* v = v8::V8::GetVersion();
//	v8::V8::Dispose();
//	// Initialize V8
//	v8::V8::Initialize();
//
//	v8::Isolate::CreateParams parms;
//	// Create a V8 isolate
//	v8::Isolate* isolate = v8::Isolate::New(parms);
//
//	std::cerr << "V8 Version: " << v << std::endl;
//	std::cerr << "Isolate Pointer: " << isolate << std::endl;
//	auto con = isolate->GetCurrentContext();
//	fprintf(stderr, "Context %p", con);
//
//	//	// Cast the void pointer to a v8::Isolate pointer
//	//	v8::Isolate* isolate = reinterpret_cast<v8::Isolate*>(Isolate_ptr);
//	//
//	//	// Ensure the isolate is valid
//	//	if (!isolate) {
//	//		std::cerr << "Invalid isolate pointer: " << isolate << std::endl;
//	//		return;
//	//	}
//	//
//	//	// Use v8::Locker to lock the isolate
//	//	v8::Locker locker(isolate);
//	//
//	//	// Create a v8::Isolate::Scope to ensure all operations are done within this isolate
//	//	v8::Isolate::Scope isolate_scope(isolate);
//	//
//	//	
//	//	// Print isolate pointer
//	//	std::cerr << "Isolate Pointer: " << isolate << std::endl;
//	//
//	//	// Print isolate data
//	//	for (int i = 0; i < isolate->GetNumberOfDataSlots(); i++) {
//	//		std::cerr << "Isolate Data " << i << ": " << isolate->GetData(i) << std::endl;
//	//	}
//	//
//	//	// Check if isolate is in use
//	//	std::cerr << "IsInUse: " << isolate->IsInUse() << std::endl;
//	//
//	//	// Check if isolate is in a context
//	//	std::cerr << "InContext: " << isolate->InContext() << std::endl;
//	//
//	//	// Get the current context
//	//	v8::Local<v8::Context> context = isolate->GetCurrentContext();
//	//
//	//	// Check if context is empty
//	//	if (context.IsEmpty()) {
//	//		std::cerr << "No current context available" << std::endl;
//	//	}
//	//	else {
//	//		// Print some information about the context
//	//		v8::Local<v8::Object> global = context->Global();
//	//		v8::String::Utf8Value utf8(isolate, global->GetConstructorName());
//	//		std::cout << "Current context global object: " << *utf8 << std::endl;
//	//	}
//}
//#pragma endregion



void Cheese()
{

	fprintf(stderr, "Well hello there\n");


	while (!GetKeyState(VK_END))
	{
		if (!sdk::World)
			sdk::World = SDK::UWorld::GetWorld();
		if (!sdk::Engine)
			sdk::Engine = SDK::UEngine::GetEngine();

		if (vars::test)
		{




			vars::test = false;
		}




		if (vars::noClip && !vars::noClipOn)
		{
			if (NoClip::EnableNoClip())
				fprintf(stderr, "No clip enabled.\n");
			else
			{
				vars::noClip = false;
				vars::noClipOn = false;
				fprintf(stderr, "No clip failed to.\n");
			}
		}
		else if (!vars::noClip && vars::noClipOn)
		{
			if (NoClip::DisableNoClip())
				fprintf(stderr, "No clip disabled.\n");
			else
			{
				fprintf(stderr, "No clip failed to disabled.\n");
			}
		}



		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}









#pragma region Initialization
void CreateConsole() {
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	SetConsoleTitle("[ WWC ]");
	FILE* f;
	//freopen_s(&f, "CONOUT$", "w", stdout);
	freopen_s(&f, ("CONOUT$"), "w", stderr);
}

void initvars()
{


	bool debuging = true;
	if (debuging)
	{
		Sleep(5000);
		for (int i = 0; i < 30; ++i) {
			fprintf(stderr, "Attempt %d: Trying to get UPuertsSetting object...\n", i + 1);
			SDK::UPuertsSetting* psett = SafeGetDefaultObj();

			if (psett) {
				psett->DebugEnable = true;
				psett->WaitDebugger = true;
				fprintf(stderr, "UPuertsSetting object acquired and modified.\n");
				break;
			}
		}
	}

	MH_Initialize();
	while (sdk::NewString == 0x00)
	{
		if (sdk::ClientBase == 0x00)
		{
			auto hModule = GetModuleHandle("Client-Win64-Shipping.exe");
			sdk::ClientBase = (uintptr_t)hModule;
		}

		if (sdk::NewString == 0x00)
		{
			if (sdk::ClientBase == 0x00)
				continue;
			sdk::NewString = sdk::ClientBase + sdk::NewStringOffset;

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	fprintf(stderr, "Clientbase: %p\n", sdk::ClientBase);
	fprintf(stderr, "NewString: %p\n", sdk::NewString);

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(sdk::NewString), &hook_NewString, (LPVOID*)(&originalNewString)) == MH_OK)
	{
		MH_STATUS stat = MH_EnableHook(reinterpret_cast<LPVOID*>(sdk::NewString));
		//fprintf(stderr, "Status: %d", stat);
		fprintf(stderr, "NewString Hook eneabled\n");
	}
	else
	{
		fprintf(stderr, "Failed to hook");
	}




}




void TEST();


void initchair()
{



	CreateConsole();
	AttachConsole(GetCurrentProcessId());
	system("cls");
	//initvars();
	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Cheese, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Cheese, NULL, NULL, NULL);


	//kiero::bind(8, (void**)&oPresent, hkPresent);

}




























DWORD WINAPI MainThread(LPVOID lpReserved)
{




	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			initchair();
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}


BOOL WINAPI DllMain(const HMODULE instance, DWORD reason, LPVOID lpReserved)
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(instance);
		CreateThread(nullptr, 0, MainThread, instance, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}

	//const auto thread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), instance, 0, nullptr);

	return 1;

}



#pragma endregion

