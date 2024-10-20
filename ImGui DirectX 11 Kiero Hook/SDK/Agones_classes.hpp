#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Agones

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// Class Agones.AgonesComponent
// 0x0080 (0x0120 - 0x00A0)
class UAgonesComponent final : public UActorComponent
{
public:
	class FString                                 HttpPort;                                          // 0x00A0(0x0010)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         HealthRateSeconds;                                 // 0x00B0(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDisableAutoConnect;                               // 0x00B4(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDisableAutoReady;                                 // 0x00B5(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDisableAutoHealth;                                // 0x00B6(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1D6F[0x1];                                     // 0x00B7(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             ConnectedDelegate;                                 // 0x00B8(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             ConnectedFailDelegate;                             // 0x00C8(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_1D70[0x48];                                    // 0x00D8(0x0048)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void Allocate(TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void Connect();
	void ConnectFail(const struct FAgonesError& Error);
	void ConnectSuccess(const struct FGameServerResponse& GameServerResponse);
	void GameServer(TDelegate<void(struct FGameServerResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void GetConnectedPlayers(TDelegate<void(struct FConnectedPlayersResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void GetPlayerCapacity(TDelegate<void(struct FCountResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void GetPlayerCount(TDelegate<void(struct FCountResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void Health(TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void HealthPing(float RateSeconds);
	void IsPlayerConnected(const class FString& PlayerId, TDelegate<void(struct FConnectedResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void PlayerConnect(const class FString& PlayerId, TDelegate<void(struct FConnectedResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void PlayerDisconnect(const class FString& PlayerId, TDelegate<void(struct FDisconnectResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void Ready(TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void Reserve(int64 Seconds, TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void SetAnnotation(const class FString& Key, const class FString& Value, TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void SetLabel(const class FString& Key, const class FString& Value, TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void SetPlayerCapacity(int64 Count, TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void Shutdown(TDelegate<void(struct FEmptyResponse& Response)> SuccessDelegate, TDelegate<void(struct FAgonesError& Error)> ErrorDelegate);
	void WatchGameServer(TDelegate<void(struct FGameServerResponse& Response)> WatchDelegate);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"AgonesComponent">();
	}
	static class UAgonesComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAgonesComponent>();
	}
};
static_assert(alignof(UAgonesComponent) == 0x000008, "Wrong alignment on UAgonesComponent");
static_assert(sizeof(UAgonesComponent) == 0x000120, "Wrong size on UAgonesComponent");
static_assert(offsetof(UAgonesComponent, HttpPort) == 0x0000A0, "Member 'UAgonesComponent::HttpPort' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, HealthRateSeconds) == 0x0000B0, "Member 'UAgonesComponent::HealthRateSeconds' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, bDisableAutoConnect) == 0x0000B4, "Member 'UAgonesComponent::bDisableAutoConnect' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, bDisableAutoReady) == 0x0000B5, "Member 'UAgonesComponent::bDisableAutoReady' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, bDisableAutoHealth) == 0x0000B6, "Member 'UAgonesComponent::bDisableAutoHealth' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, ConnectedDelegate) == 0x0000B8, "Member 'UAgonesComponent::ConnectedDelegate' has a wrong offset!");
static_assert(offsetof(UAgonesComponent, ConnectedFailDelegate) == 0x0000C8, "Member 'UAgonesComponent::ConnectedFailDelegate' has a wrong offset!");

}

