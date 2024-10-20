#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S6UXIntentSubsystem

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "Engine_classes.hpp"
#include "S6UXIntentSubsystem_structs.hpp"
#include "GameFeatures_classes.hpp"


namespace SDK
{

// Class S6UXIntentSubsystem.S6RegisterUXActivityFunctor
// 0x0000 (0x0028 - 0x0028)
class US6RegisterUXActivityFunctor final : public UObject
{
public:
	void HandleUXIntentReceived(class US6UXIntentSubsystem* UXIntentSubsystem, class US6UXIntent* UXIntent);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6RegisterUXActivityFunctor">();
	}
	static class US6RegisterUXActivityFunctor* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6RegisterUXActivityFunctor>();
	}
};
static_assert(alignof(US6RegisterUXActivityFunctor) == 0x000008, "Wrong alignment on US6RegisterUXActivityFunctor");
static_assert(sizeof(US6RegisterUXActivityFunctor) == 0x000028, "Wrong size on US6RegisterUXActivityFunctor");

// Class S6UXIntentSubsystem.S6GameFeatureAction_RegisterUXActivity
// 0x0088 (0x00B0 - 0x0028)
class US6GameFeatureAction_RegisterUXActivity final : public UGameFeatureAction
{
public:
	TSoftClassPtr<class UClass>                   UXIntentType;                                      // 0x0028(0x0028)(Edit, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class US6RegisterUXActivityFunctor> UXIntentHandlerClass;                              // 0x0050(0x0008)(Edit, ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TMap<TWeakObjectPtr<class UGameInstance>, struct FGuid> RegisteredUXActivityIdByGameInstance;              // 0x0058(0x0050)(Transient, NativeAccessSpecifierPrivate)
	uint8                                         Pad_2D64[0x8];                                     // 0x00A8(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6GameFeatureAction_RegisterUXActivity">();
	}
	static class US6GameFeatureAction_RegisterUXActivity* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6GameFeatureAction_RegisterUXActivity>();
	}
};
static_assert(alignof(US6GameFeatureAction_RegisterUXActivity) == 0x000008, "Wrong alignment on US6GameFeatureAction_RegisterUXActivity");
static_assert(sizeof(US6GameFeatureAction_RegisterUXActivity) == 0x0000B0, "Wrong size on US6GameFeatureAction_RegisterUXActivity");
static_assert(offsetof(US6GameFeatureAction_RegisterUXActivity, UXIntentType) == 0x000028, "Member 'US6GameFeatureAction_RegisterUXActivity::UXIntentType' has a wrong offset!");
static_assert(offsetof(US6GameFeatureAction_RegisterUXActivity, UXIntentHandlerClass) == 0x000050, "Member 'US6GameFeatureAction_RegisterUXActivity::UXIntentHandlerClass' has a wrong offset!");
static_assert(offsetof(US6GameFeatureAction_RegisterUXActivity, RegisteredUXActivityIdByGameInstance) == 0x000058, "Member 'US6GameFeatureAction_RegisterUXActivity::RegisteredUXActivityIdByGameInstance' has a wrong offset!");

// Class S6UXIntentSubsystem.S6UXIntent
// 0x0008 (0x0030 - 0x0028)
class US6UXIntent final : public UObject
{
public:
	class APlayerController*                      InstigatingPC;                                     // 0x0028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, EditConst, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6UXIntent">();
	}
	static class US6UXIntent* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6UXIntent>();
	}
};
static_assert(alignof(US6UXIntent) == 0x000008, "Wrong alignment on US6UXIntent");
static_assert(sizeof(US6UXIntent) == 0x000030, "Wrong size on US6UXIntent");
static_assert(offsetof(US6UXIntent, InstigatingPC) == 0x000028, "Member 'US6UXIntent::InstigatingPC' has a wrong offset!");

// Class S6UXIntentSubsystem.S6UXIntentSubsystem
// 0x0100 (0x0130 - 0x0030)
class US6UXIntentSubsystem final : public UGameInstanceSubsystem
{
public:
	uint8                                         Pad_2D65[0x8];                                     // 0x0030(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<TSoftClassPtr<class UClass>, struct FGuid> IntentTypesToActivityIds;                          // 0x0038(0x0050)(NativeAccessSpecifierPrivate)
	TMap<TSoftClassPtr<class UClass>, FMulticastInlineDelegateProperty_> IntentTypesToChangeDelegates;                      // 0x0088(0x0050)(ContainsInstancedReference, NativeAccessSpecifierPrivate)
	TMap<struct FGuid, struct FS6RegisteredUXActivity> RegisteredActivitiesMap;                           // 0x00D8(0x0050)(ContainsInstancedReference, NativeAccessSpecifierPrivate)
	uint8                                         Pad_2D66[0x8];                                     // 0x0128(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	bool CanStartUXActivity(const TSoftClassPtr<class UClass>& UXIntentType);
	struct FGuid RegisterUXActivity(const TSoftClassPtr<class UClass>& UXIntentType, const TDelegate<void(class US6UXIntentSubsystem* UXIntentSubsystem, class US6UXIntent* UXIntent)>& HandleUXIntentReceived);
	void S6OnDifferentUXActivityRegistered__DelegateSignature(class US6UXIntentSubsystem* UXIntentSubsystem, const TSoftClassPtr<class UClass>& UXIntentType);
	void S6OnDifferentUXActivityRegistered_Multicast__DelegateSignature(class US6UXIntentSubsystem* UXIntentSubsystem, const TSoftClassPtr<class UClass>& UXIntentType);
	void SubscribeToUXActivityChanges(const TSoftClassPtr<class UClass>& UXIntentType, const TDelegate<void(class US6UXIntentSubsystem* UXIntentSubsystem, TSoftClassPtr<class UClass>& UXIntentType)>& HandleDifferentUXActivityRegistered);
	bool TryStartUXActivity(class US6UXIntent* UXIntent);
	bool UnregisterUXActivity(const struct FGuid& UXActivityHandle);
	void UnsubscribeFromUXActivityChanges(const TSoftClassPtr<class UClass>& UXIntentType, const TDelegate<void(class US6UXIntentSubsystem* UXIntentSubsystem, TSoftClassPtr<class UClass>& UXIntentType)>& HandleDifferentUXActivityRegistered);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"S6UXIntentSubsystem">();
	}
	static class US6UXIntentSubsystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<US6UXIntentSubsystem>();
	}
};
static_assert(alignof(US6UXIntentSubsystem) == 0x000008, "Wrong alignment on US6UXIntentSubsystem");
static_assert(sizeof(US6UXIntentSubsystem) == 0x000130, "Wrong size on US6UXIntentSubsystem");
static_assert(offsetof(US6UXIntentSubsystem, IntentTypesToActivityIds) == 0x000038, "Member 'US6UXIntentSubsystem::IntentTypesToActivityIds' has a wrong offset!");
static_assert(offsetof(US6UXIntentSubsystem, IntentTypesToChangeDelegates) == 0x000088, "Member 'US6UXIntentSubsystem::IntentTypesToChangeDelegates' has a wrong offset!");
static_assert(offsetof(US6UXIntentSubsystem, RegisteredActivitiesMap) == 0x0000D8, "Member 'US6UXIntentSubsystem::RegisteredActivitiesMap' has a wrong offset!");

}

