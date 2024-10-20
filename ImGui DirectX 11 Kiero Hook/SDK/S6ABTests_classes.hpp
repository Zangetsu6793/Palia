#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S6ABTests

#include "Basic.hpp"

#include "S6ABTests_structs.hpp"
#include "Engine_classes.hpp"
#include "DeveloperSettings_classes.hpp"


namespace SDK
{

// Class S6ABTests.S6ABTest
// 0x0038 (0x0068 - 0x0030)
class US6ABTest final : public UPrimaryDataAsset
{
public:
	class FString                                 Identifier;                                        // 0x0030(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FS6ABTestVariant>               Variants;                                          // 0x0040(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	int64                                         ControlValue;                                      // 0x0050(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DevComments;                                       // 0x0058(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6ABTest">();
	}
	static class US6ABTest* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6ABTest>();
	}
};
static_assert(alignof(US6ABTest) == 0x000008, "Wrong alignment on US6ABTest");
static_assert(sizeof(US6ABTest) == 0x000068, "Wrong size on US6ABTest");
static_assert(offsetof(US6ABTest, Identifier) == 0x000030, "Member 'US6ABTest::Identifier' has a wrong offset!");
static_assert(offsetof(US6ABTest, Variants) == 0x000040, "Member 'US6ABTest::Variants' has a wrong offset!");
static_assert(offsetof(US6ABTest, ControlValue) == 0x000050, "Member 'US6ABTest::ControlValue' has a wrong offset!");
static_assert(offsetof(US6ABTest, DevComments) == 0x000058, "Member 'US6ABTest::DevComments' has a wrong offset!");

// Class S6ABTests.S6ABTestClientServerSyncer
// 0x0000 (0x00A0 - 0x00A0)
class US6ABTestClientServerSyncer final : public UActorComponent
{
public:
	void RpcServer_SendToServer(const TArray<struct FABTestAssignment>& TestAssignments);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6ABTestClientServerSyncer">();
	}
	static class US6ABTestClientServerSyncer* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6ABTestClientServerSyncer>();
	}
};
static_assert(alignof(US6ABTestClientServerSyncer) == 0x000008, "Wrong alignment on US6ABTestClientServerSyncer");
static_assert(sizeof(US6ABTestClientServerSyncer) == 0x0000A0, "Wrong size on US6ABTestClientServerSyncer");

// Class S6ABTests.S6ABTestManager
// 0x0080 (0x00B0 - 0x0030)
class US6ABTestManager final : public UGameInstanceSubsystem
{
public:
	bool                                          bLocalClientAssignmentsLoaded;                     // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1EE7[0x7];                                     // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FABTestAssignmentArray                 LocalClientAssignments;                            // 0x0038(0x0010)(NativeAccessSpecifierPrivate)
	TMap<class APlayerController*, struct FABTestAssignmentArray> ServerAssignments;                                 // 0x0048(0x0050)(NativeAccessSpecifierPrivate)
	class US6ABTestSettings*                      CurrentSettings;                                   // 0x0098(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<class US6ABTest*>                      AllTests;                                          // 0x00A0(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)

public:
	void HandleAbTestSettingsChanged(const class US6ABTestSettings* Settings);
	void HandlePlayerControllerDestroyed(class AActor* Actor);

	int64 Client_GetValueOfAbTest(const class US6ABTest* AbTest) const;
	bool IsEnabled() const;
	int64 Server_GetValueOfAbTest(const class US6ABTest* AbTest, const class APlayerController* PC) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6ABTestManager">();
	}
	static class US6ABTestManager* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6ABTestManager>();
	}
};
static_assert(alignof(US6ABTestManager) == 0x000008, "Wrong alignment on US6ABTestManager");
static_assert(sizeof(US6ABTestManager) == 0x0000B0, "Wrong size on US6ABTestManager");
static_assert(offsetof(US6ABTestManager, bLocalClientAssignmentsLoaded) == 0x000030, "Member 'US6ABTestManager::bLocalClientAssignmentsLoaded' has a wrong offset!");
static_assert(offsetof(US6ABTestManager, LocalClientAssignments) == 0x000038, "Member 'US6ABTestManager::LocalClientAssignments' has a wrong offset!");
static_assert(offsetof(US6ABTestManager, ServerAssignments) == 0x000048, "Member 'US6ABTestManager::ServerAssignments' has a wrong offset!");
static_assert(offsetof(US6ABTestManager, CurrentSettings) == 0x000098, "Member 'US6ABTestManager::CurrentSettings' has a wrong offset!");
static_assert(offsetof(US6ABTestManager, AllTests) == 0x0000A0, "Member 'US6ABTestManager::AllTests' has a wrong offset!");

// Class S6ABTests.S6ABTestSettings
// 0x0028 (0x0060 - 0x0038)
class US6ABTestSettings final : public UDeveloperSettings
{
public:
	FMulticastInlineDelegateProperty_             OnChanged;                                         // 0x0038(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	bool                                          bIsEnabled;                                        // 0x0048(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1EE8[0x7];                                     // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FS6ABTestDistribution>          Distributions;                                     // 0x0050(0x0010)(Edit, ZeroConstructor, Config, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6ABTestSettings">();
	}
	static class US6ABTestSettings* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6ABTestSettings>();
	}
};
static_assert(alignof(US6ABTestSettings) == 0x000008, "Wrong alignment on US6ABTestSettings");
static_assert(sizeof(US6ABTestSettings) == 0x000060, "Wrong size on US6ABTestSettings");
static_assert(offsetof(US6ABTestSettings, OnChanged) == 0x000038, "Member 'US6ABTestSettings::OnChanged' has a wrong offset!");
static_assert(offsetof(US6ABTestSettings, bIsEnabled) == 0x000048, "Member 'US6ABTestSettings::bIsEnabled' has a wrong offset!");
static_assert(offsetof(US6ABTestSettings, Distributions) == 0x000050, "Member 'US6ABTestSettings::Distributions' has a wrong offset!");

}

