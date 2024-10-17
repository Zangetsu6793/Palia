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

}







void initchair()
{



	CreateConsole();
	AttachConsole(GetCurrentProcessId());
	system("cls");
	initvars();
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

