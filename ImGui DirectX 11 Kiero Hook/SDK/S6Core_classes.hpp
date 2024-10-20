#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S6Core

#include "Basic.hpp"

#include "S6Core_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "DeveloperSettings_classes.hpp"


namespace SDK
{

// Class S6Core.CommandLineHelper
// 0x0000 (0x0028 - 0x0028)
class UCommandLineHelper final : public UBlueprintFunctionLibrary
{
public:
	static bool DoesCommandlineHaveSwitch(const class FString& SWITCH);
	static bool TryGetCommandlineKeyValuePair(const class FString& Key, class FString* Value);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CommandLineHelper">();
	}
	static class UCommandLineHelper* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCommandLineHelper>();
	}
};
static_assert(alignof(UCommandLineHelper) == 0x000008, "Wrong alignment on UCommandLineHelper");
static_assert(sizeof(UCommandLineHelper) == 0x000028, "Wrong size on UCommandLineHelper");

// Class S6Core.GuidDataAsset
// 0x0018 (0x0048 - 0x0030)
class UGuidDataAsset : public UDataAsset
{
public:
	uint8                                         Pad_1A65[0x8];                                     // 0x0030(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGuid                                  Guid;                                              // 0x0038(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"GuidDataAsset">();
	}
	static class UGuidDataAsset* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGuidDataAsset>();
	}
};
static_assert(alignof(UGuidDataAsset) == 0x000008, "Wrong alignment on UGuidDataAsset");
static_assert(sizeof(UGuidDataAsset) == 0x000048, "Wrong size on UGuidDataAsset");
static_assert(offsetof(UGuidDataAsset, Guid) == 0x000038, "Member 'UGuidDataAsset::Guid' has a wrong offset!");

// Class S6Core.S6DataAssetManager
// 0x0058 (0x0088 - 0x0030)
class US6DataAssetManager final : public UEngineSubsystem
{
public:
	TMap<struct FGuid, class UGuidDataAsset*>     GuidToAssetMap;                                    // 0x0030(0x0050)(NativeAccessSpecifierPrivate)
	uint8                                         Pad_1A66[0x8];                                     // 0x0080(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	class UGuidDataAsset* FindConfigByGuid(const struct FGuid& Guid) const;
	TArray<class UGuidDataAsset*> GetAllGuidDataAssets() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6DataAssetManager">();
	}
	static class US6DataAssetManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6DataAssetManager>();
	}
};
static_assert(alignof(US6DataAssetManager) == 0x000008, "Wrong alignment on US6DataAssetManager");
static_assert(sizeof(US6DataAssetManager) == 0x000088, "Wrong size on US6DataAssetManager");
static_assert(offsetof(US6DataAssetManager, GuidToAssetMap) == 0x000030, "Member 'US6DataAssetManager::GuidToAssetMap' has a wrong offset!");

// Class S6Core.S6UsesCustomReferenceSerializationInterface
// 0x0000 (0x0028 - 0x0028)
class IS6UsesCustomReferenceSerializationInterface final : public IInterface
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6UsesCustomReferenceSerializationInterface">();
	}
	static class IS6UsesCustomReferenceSerializationInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<IS6UsesCustomReferenceSerializationInterface>();
	}
};
static_assert(alignof(IS6UsesCustomReferenceSerializationInterface) == 0x000008, "Wrong alignment on IS6UsesCustomReferenceSerializationInterface");
static_assert(sizeof(IS6UsesCustomReferenceSerializationInterface) == 0x000028, "Wrong size on IS6UsesCustomReferenceSerializationInterface");

// Class S6Core.S6Core_AssetLoader
// 0x0050 (0x0078 - 0x0028)
class US6Core_AssetLoader final : public UObject
{
public:
	uint8                                         Pad_1A67[0x50];                                    // 0x0028(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_AssetLoader">();
	}
	static class US6Core_AssetLoader* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_AssetLoader>();
	}
};
static_assert(alignof(US6Core_AssetLoader) == 0x000008, "Wrong alignment on US6Core_AssetLoader");
static_assert(sizeof(US6Core_AssetLoader) == 0x000078, "Wrong size on US6Core_AssetLoader");

// Class S6Core.S6VersioningFunctionLibrary
// 0x0000 (0x0028 - 0x0028)
class US6VersioningFunctionLibrary final : public UBlueprintFunctionLibrary
{
public:
	static class FString GetNetworkCompatibilityString();
	static class FString GetVersionString();
	static bool IsValidVersionString(const class FString& InVersion);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6VersioningFunctionLibrary">();
	}
	static class US6VersioningFunctionLibrary* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6VersioningFunctionLibrary>();
	}
};
static_assert(alignof(US6VersioningFunctionLibrary) == 0x000008, "Wrong alignment on US6VersioningFunctionLibrary");
static_assert(sizeof(US6VersioningFunctionLibrary) == 0x000028, "Wrong size on US6VersioningFunctionLibrary");

// Class S6Core.S6Core_General_BlueprintFunctionLibrary
// 0x0000 (0x0028 - 0x0028)
class US6Core_General_BlueprintFunctionLibrary final : public UBlueprintFunctionLibrary
{
public:
	static class UClass* BlueprintObjectToClass(class UObject* Object);
	static bool DeleteFileAtPath(const class FString& FilePath);
	static bool DoesFunctionExist(class UObject* Instance, const class FName& FunctionName);
	static class UActorComponent* FindDefaultComponentByClass(const TSubclassOf<class AActor> InActorClass, const TSubclassOf<class UActorComponent> InComponentClass);
	static TArray<class UActorComponent*> FindDefaultComponentsByClass(const TSubclassOf<class AActor> InActorClass, const TSubclassOf<class UActorComponent> InComponentClass);
	static void GetActorBounds(const TSubclassOf<class AActor> InActorClass, bool bOnlyCollidingComponents, struct FBox* OutBounds);
	static void GetAllKnownPlayerPawns(const class ULocalPlayer* LocalPlayer, TMap<struct FUniqueNetIdRepl, class APawn*>* PlayerPawns, const bool bIncludeLocalPawn);
	static TMap<class FName, struct FS6Core_StatData> GetAllStatDataForStatGroup(const class FName& StatGroupName);
	static class UActorComponent* GetComponentByInterface(const class AActor* InActor, const TSubclassOf<class IInterface> Interface);
	static int32 GetCurrentDrawCalls();
	static class FName GetCurrentMapName(class UObject* WorldContextObject);
	static class ULocalPlayer* GetLocalPlayerFromController(const class APlayerController* Controller);
	static struct FS6Core_StatData GetStatDataFromName(const class FName& StatName);
	static bool HasBegunPlay(const class AActor* InActor);
	static bool IsStatGroupToggled(const class FName& StatGroupName);
	static void PrintToConsoleWindow(const class FString& Msg);
	static void ShowSimpleNotification(const class FString& Text, bool bErrorMessage, float WidthOverride);
	static void TakeHighResScreenshotOfGameViewport(const class UGameInstance* GameInstance, const int32 ImageSize_X, const int32 ImageSize_Y, const float ImageResolution, const bool UseHDR, const bool MaskBackground);
	static void ToggleScreenshotMaskOnCurrentGameViewport(const class UGameInstance* GameInstance, const bool MaskEnabled);
	static int64 ToInt64(const class FString& InString);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_General_BlueprintFunctionLibrary">();
	}
	static class US6Core_General_BlueprintFunctionLibrary* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_General_BlueprintFunctionLibrary>();
	}
};
static_assert(alignof(US6Core_General_BlueprintFunctionLibrary) == 0x000008, "Wrong alignment on US6Core_General_BlueprintFunctionLibrary");
static_assert(sizeof(US6Core_General_BlueprintFunctionLibrary) == 0x000028, "Wrong size on US6Core_General_BlueprintFunctionLibrary");

// Class S6Core.S6Core_LocalPlayer
// 0x0010 (0x02C0 - 0x02B0)
class US6Core_LocalPlayer : public ULocalPlayer
{
public:
	FMulticastInlineDelegateProperty_             OnParentalControlsEnabled;                         // 0x02B0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_LocalPlayer">();
	}
	static class US6Core_LocalPlayer* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_LocalPlayer>();
	}
};
static_assert(alignof(US6Core_LocalPlayer) == 0x000008, "Wrong alignment on US6Core_LocalPlayer");
static_assert(sizeof(US6Core_LocalPlayer) == 0x0002C0, "Wrong size on US6Core_LocalPlayer");
static_assert(offsetof(US6Core_LocalPlayer, OnParentalControlsEnabled) == 0x0002B0, "Member 'US6Core_LocalPlayer::OnParentalControlsEnabled' has a wrong offset!");

// Class S6Core.S6Core_AsyncAction_LevelTravel
// 0x0038 (0x0068 - 0x0030)
class US6Core_AsyncAction_LevelTravel final : public UBlueprintAsyncActionBase
{
public:
	uint8                                         Pad_1A72[0x10];                                    // 0x0030(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                WorldContextObject;                                // 0x0040(0x0008)(ZeroConstructor, Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnComplete;                                        // 0x0048(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnFail;                                            // 0x0058(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)

public:
	static class US6Core_AsyncAction_LevelTravel* LevelTravel(const class FString& LevelName, class UObject* InWorldContextObject);

	void OnLevelTravelComplete__DelegateSignature();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_AsyncAction_LevelTravel">();
	}
	static class US6Core_AsyncAction_LevelTravel* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_AsyncAction_LevelTravel>();
	}
};
static_assert(alignof(US6Core_AsyncAction_LevelTravel) == 0x000008, "Wrong alignment on US6Core_AsyncAction_LevelTravel");
static_assert(sizeof(US6Core_AsyncAction_LevelTravel) == 0x000068, "Wrong size on US6Core_AsyncAction_LevelTravel");
static_assert(offsetof(US6Core_AsyncAction_LevelTravel, WorldContextObject) == 0x000040, "Member 'US6Core_AsyncAction_LevelTravel::WorldContextObject' has a wrong offset!");
static_assert(offsetof(US6Core_AsyncAction_LevelTravel, OnComplete) == 0x000048, "Member 'US6Core_AsyncAction_LevelTravel::OnComplete' has a wrong offset!");
static_assert(offsetof(US6Core_AsyncAction_LevelTravel, OnFail) == 0x000058, "Member 'US6Core_AsyncAction_LevelTravel::OnFail' has a wrong offset!");

// Class S6Core.S6Core_AsyncAction_LoadSublevel
// 0x0048 (0x0078 - 0x0030)
class US6Core_AsyncAction_LoadSublevel final : public UBlueprintAsyncActionBase
{
public:
	uint8                                         Pad_1A73[0x20];                                    // 0x0030(0x0020)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                WorldContextObject;                                // 0x0050(0x0008)(ZeroConstructor, Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnComplete;                                        // 0x0058(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)
	FMulticastInlineDelegateProperty_             OnFail;                                            // 0x0068(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPrivate)

public:
	static class US6Core_AsyncAction_LoadSublevel* LoadSublevel(const class FString& InLevelName, class UObject* InWorldContextObject, bool bInShouldBeVisible);

	void HandleOnLevelLoaded();
	void OnSublevelActionCompleted__DelegateSignature();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_AsyncAction_LoadSublevel">();
	}
	static class US6Core_AsyncAction_LoadSublevel* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_AsyncAction_LoadSublevel>();
	}
};
static_assert(alignof(US6Core_AsyncAction_LoadSublevel) == 0x000008, "Wrong alignment on US6Core_AsyncAction_LoadSublevel");
static_assert(sizeof(US6Core_AsyncAction_LoadSublevel) == 0x000078, "Wrong size on US6Core_AsyncAction_LoadSublevel");
static_assert(offsetof(US6Core_AsyncAction_LoadSublevel, WorldContextObject) == 0x000050, "Member 'US6Core_AsyncAction_LoadSublevel::WorldContextObject' has a wrong offset!");
static_assert(offsetof(US6Core_AsyncAction_LoadSublevel, OnComplete) == 0x000058, "Member 'US6Core_AsyncAction_LoadSublevel::OnComplete' has a wrong offset!");
static_assert(offsetof(US6Core_AsyncAction_LoadSublevel, OnFail) == 0x000068, "Member 'US6Core_AsyncAction_LoadSublevel::OnFail' has a wrong offset!");

// Class S6Core.S6Core_PlatformInvitationManager
// 0x01D8 (0x0208 - 0x0030)
class US6Core_PlatformInvitationManager : public ULocalPlayerSubsystem
{
public:
	uint8                                         Pad_1A75[0x70];                                    // 0x0030(0x0070)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IS6Core_PlatformSessionInterface> PlatformSessionInterface;                          // 0x00A0(0x0010)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1A76[0x158];                                   // 0x00B0(0x0158)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformInvitationManager">();
	}
	static class US6Core_PlatformInvitationManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_PlatformInvitationManager>();
	}
};
static_assert(alignof(US6Core_PlatformInvitationManager) == 0x000008, "Wrong alignment on US6Core_PlatformInvitationManager");
static_assert(sizeof(US6Core_PlatformInvitationManager) == 0x000208, "Wrong size on US6Core_PlatformInvitationManager");
static_assert(offsetof(US6Core_PlatformInvitationManager, PlatformSessionInterface) == 0x0000A0, "Member 'US6Core_PlatformInvitationManager::PlatformSessionInterface' has a wrong offset!");

// Class S6Core.S6Core_PlatformPermissionsSettings
// 0x0038 (0x0070 - 0x0038)
class US6Core_PlatformPermissionsSettings final : public UDeveloperSettings
{
public:
	float                                         PlatformUserPermissionsPollInSeconds;              // 0x0038(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1A77[0x4];                                     // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   OnlineCommunicationsDisabledPermissionText;        // 0x0040(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, Config, NativeAccessSpecifierPublic)
	class FText                                   UseUserGeneratedContentDisabledPermissionText;     // 0x0058(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, Config, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformPermissionsSettings">();
	}
	static class US6Core_PlatformPermissionsSettings* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_PlatformPermissionsSettings>();
	}
};
static_assert(alignof(US6Core_PlatformPermissionsSettings) == 0x000008, "Wrong alignment on US6Core_PlatformPermissionsSettings");
static_assert(sizeof(US6Core_PlatformPermissionsSettings) == 0x000070, "Wrong size on US6Core_PlatformPermissionsSettings");
static_assert(offsetof(US6Core_PlatformPermissionsSettings, PlatformUserPermissionsPollInSeconds) == 0x000038, "Member 'US6Core_PlatformPermissionsSettings::PlatformUserPermissionsPollInSeconds' has a wrong offset!");
static_assert(offsetof(US6Core_PlatformPermissionsSettings, OnlineCommunicationsDisabledPermissionText) == 0x000040, "Member 'US6Core_PlatformPermissionsSettings::OnlineCommunicationsDisabledPermissionText' has a wrong offset!");
static_assert(offsetof(US6Core_PlatformPermissionsSettings, UseUserGeneratedContentDisabledPermissionText) == 0x000058, "Member 'US6Core_PlatformPermissionsSettings::UseUserGeneratedContentDisabledPermissionText' has a wrong offset!");

// Class S6Core.S6Core_PlatformPrivilegesManager
// 0x0018 (0x0048 - 0x0030)
class US6Core_PlatformPrivilegesManager final : public ULocalPlayerSubsystem
{
public:
	FMulticastInlineDelegateProperty_             OnPermissionsChanged;                              // 0x0030(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_1A78[0x8];                                     // 0x0040(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void AddPermission(ES6Core_PlatformPermissions Permission);
	void OnPermissionsChanged__DelegateSignature(ES6Core_PlatformPermissions Permissions);
	void RemovePermission(ES6Core_PlatformPermissions Permission);

	ES6Core_PlatformPermissions GetPermissions() const;
	bool HasPermission(ES6Core_PlatformPermissions Permission) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformPrivilegesManager">();
	}
	static class US6Core_PlatformPrivilegesManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_PlatformPrivilegesManager>();
	}
};
static_assert(alignof(US6Core_PlatformPrivilegesManager) == 0x000008, "Wrong alignment on US6Core_PlatformPrivilegesManager");
static_assert(sizeof(US6Core_PlatformPrivilegesManager) == 0x000048, "Wrong size on US6Core_PlatformPrivilegesManager");
static_assert(offsetof(US6Core_PlatformPrivilegesManager, OnPermissionsChanged) == 0x000030, "Member 'US6Core_PlatformPrivilegesManager::OnPermissionsChanged' has a wrong offset!");

// Class S6Core.S6Core_PlatformSessionGDK
// 0x0008 (0x0030 - 0x0028)
class US6Core_PlatformSessionGDK final : public UObject
{
public:
	uint8                                         Pad_1A79[0x8];                                     // 0x0028(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformSessionGDK">();
	}
	static class US6Core_PlatformSessionGDK* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_PlatformSessionGDK>();
	}
};
static_assert(alignof(US6Core_PlatformSessionGDK) == 0x000008, "Wrong alignment on US6Core_PlatformSessionGDK");
static_assert(sizeof(US6Core_PlatformSessionGDK) == 0x000030, "Wrong size on US6Core_PlatformSessionGDK");

// Class S6Core.S6Core_PlatformSessionInterface
// 0x0000 (0x0028 - 0x0028)
class IS6Core_PlatformSessionInterface final : public IInterface
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformSessionInterface">();
	}
	static class IS6Core_PlatformSessionInterface* GetDefaultObj()
	{
		return GetDefaultObjImpl<IS6Core_PlatformSessionInterface>();
	}
};
static_assert(alignof(IS6Core_PlatformSessionInterface) == 0x000008, "Wrong alignment on IS6Core_PlatformSessionInterface");
static_assert(sizeof(IS6Core_PlatformSessionInterface) == 0x000028, "Wrong size on IS6Core_PlatformSessionInterface");

// Class S6Core.S6Core_PlatformSessionPS5
// 0x0008 (0x0030 - 0x0028)
class US6Core_PlatformSessionPS5 final : public UObject
{
public:
	uint8                                         Pad_1A7A[0x8];                                     // 0x0028(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6Core_PlatformSessionPS5">();
	}
	static class US6Core_PlatformSessionPS5* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6Core_PlatformSessionPS5>();
	}
};
static_assert(alignof(US6Core_PlatformSessionPS5) == 0x000008, "Wrong alignment on US6Core_PlatformSessionPS5");
static_assert(sizeof(US6Core_PlatformSessionPS5) == 0x000030, "Wrong size on US6Core_PlatformSessionPS5");

// Class S6Core.S6PlatformUtils
// 0x0000 (0x0028 - 0x0028)
class US6PlatformUtils final : public UBlueprintFunctionLibrary
{
public:
	static void CleanUpObject(class UObject* Object);
	static bool DoesSteamOSSExist();
	static class FString GetEnvironment();
	static class FName GetPlatformOnlineSubsystemName();
	static class FString GetPlatformString();
	static ERedirectsPlatform GetPlatformType();
	static ERedirectsPlatform GetPlatformTypeFromString(const class FString& PlatformName);
	static bool GetSonyPlayerIdsAtLocalUserIndex(const int32 LocalUserIndex, int64* OutAccountId, int64* OutUserId);
	static bool IsConsole();
	static bool IsConsolePlatform();
	static bool IsConstrainedPlatform();
	static bool IsDesktop();
	static bool IsInParentalControl();
	static bool IsMobile();
	static bool IsMobilePlatform();
	static bool IsPS5Platform();
	static bool IsSwitchPlatform();
	static bool IsWindowsPlatform();
	static bool IsWithSteamOSSDefined();
	static bool IsXSXPlatform();
	static void ReportEnterInGameStoreUI();
	static void ReportExitInGameStoreUI();
	static bool ShowPlatformProfileUI(int32 LocalUserNum, const class FString& RequesteeId);
	static void TryCollectGarbageBasedOnPlatform();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6PlatformUtils">();
	}
	static class US6PlatformUtils* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6PlatformUtils>();
	}
};
static_assert(alignof(US6PlatformUtils) == 0x000008, "Wrong alignment on US6PlatformUtils");
static_assert(sizeof(US6PlatformUtils) == 0x000028, "Wrong size on US6PlatformUtils");

// Class S6Core.S6RCONSubsystem
// 0x0030 (0x0060 - 0x0030)
class US6RCONSubsystem final : public UGameInstanceSubsystem
{
public:
	uint8                                         Pad_1A80[0x30];                                    // 0x0030(0x0030)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6RCONSubsystem">();
	}
	static class US6RCONSubsystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6RCONSubsystem>();
	}
};
static_assert(alignof(US6RCONSubsystem) == 0x000008, "Wrong alignment on US6RCONSubsystem");
static_assert(sizeof(US6RCONSubsystem) == 0x000060, "Wrong size on US6RCONSubsystem");

// Class S6Core.S6ServerMetrics
// 0x0028 (0x0058 - 0x0030)
class US6ServerMetrics final : public UGameInstanceSubsystem
{
public:
	uint8                                         Pad_1A81[0x20];                                    // 0x0030(0x0020)(Fixing Size After Last Property [ Dumper-7 ])
	bool                                          ShouldEmitServerMetrics;                           // 0x0050(0x0001)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1A82[0x7];                                     // 0x0051(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6ServerMetrics">();
	}
	static class US6ServerMetrics* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6ServerMetrics>();
	}
};
static_assert(alignof(US6ServerMetrics) == 0x000008, "Wrong alignment on US6ServerMetrics");
static_assert(sizeof(US6ServerMetrics) == 0x000058, "Wrong size on US6ServerMetrics");
static_assert(offsetof(US6ServerMetrics, ShouldEmitServerMetrics) == 0x000050, "Member 'US6ServerMetrics::ShouldEmitServerMetrics' has a wrong offset!");

// Class S6Core.S6WorldPartitionStreamer
// 0x0028 (0x02D0 - 0x02A8)
class AS6WorldPartitionStreamer final : public AActor
{
public:
	class UWorldPartitionStreamingSourceComponent* WorldPartitionStreamingSourceComponent;            // 0x02A8(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FMulticastInlineDelegateProperty_             OnWorldPartitionStreamerAreaLoaded;                // 0x02B0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	bool                                          bAreaLoaded;                                       // 0x02C0(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_1A83[0x7];                                     // 0x02C1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           AreaLoadedTimerHandle;                             // 0x02C8(0x0008)(NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

public:
	void CheckForAreaLoaded();

	bool HasAreaLoaded() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6WorldPartitionStreamer">();
	}
	static class AS6WorldPartitionStreamer* GetDefaultObj()
	{
		return GetDefaultObjImpl<AS6WorldPartitionStreamer>();
	}
};
static_assert(alignof(AS6WorldPartitionStreamer) == 0x000008, "Wrong alignment on AS6WorldPartitionStreamer");
static_assert(sizeof(AS6WorldPartitionStreamer) == 0x0002D0, "Wrong size on AS6WorldPartitionStreamer");
static_assert(offsetof(AS6WorldPartitionStreamer, WorldPartitionStreamingSourceComponent) == 0x0002A8, "Member 'AS6WorldPartitionStreamer::WorldPartitionStreamingSourceComponent' has a wrong offset!");
static_assert(offsetof(AS6WorldPartitionStreamer, OnWorldPartitionStreamerAreaLoaded) == 0x0002B0, "Member 'AS6WorldPartitionStreamer::OnWorldPartitionStreamerAreaLoaded' has a wrong offset!");
static_assert(offsetof(AS6WorldPartitionStreamer, bAreaLoaded) == 0x0002C0, "Member 'AS6WorldPartitionStreamer::bAreaLoaded' has a wrong offset!");
static_assert(offsetof(AS6WorldPartitionStreamer, AreaLoadedTimerHandle) == 0x0002C8, "Member 'AS6WorldPartitionStreamer::AreaLoadedTimerHandle' has a wrong offset!");

}

