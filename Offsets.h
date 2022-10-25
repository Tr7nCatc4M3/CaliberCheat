#pragma once

#include "IncludeFiles.h"

// Would use SDK for calling blueprints but NO ONE CAN
// MAKE A FUCKING DUMPER FOR UE5 LMAO

// I will constantly update dynamic offsets :) YW

namespace Offsets {
	typedef struct {
		LPCWSTR Name; // Offset Name;
		DWORD& Offset; // Offset Byte
	} OFFSET;
	extern uintptr_t fnGetBounds;
	extern uintptr_t nObjectsCount;
	extern uintptr_t uObjects;
	extern uintptr_t fnLineOfSightTo;
	extern uintptr_t fnGetBoneMatrix;
	extern uintptr_t fnGetWeaponStats;
	extern PVOID* uWorld;
	extern PVOID K2_TeleportTo;
	extern PVOID ServerTickSetup;

	namespace Engine {
		namespace World {
			extern DWORD OwningGameInstance;
			extern DWORD Levels;
			extern DWORD PersistentLevel;
		}

		namespace Level {
			extern DWORD AActors;
		}

		namespace GameInstance {
			extern DWORD LocalPlayers;
		}

		namespace Player {
			extern DWORD PlayerController;
		}

		namespace Controller {
			extern DWORD ControlRotation;
			extern PVOID SetControlRotation;
			extern DWORD RemoteViewPitch;
			extern PVOID ClientSetRotation;
			extern PVOID SetIgnoreLookInput;
		}

		namespace PlayerController { // PlayerCameraManager
			extern DWORD AckowledgedPawn;
			extern DWORD PlayerCameraManager;
		}

		namespace Pawn {
			extern DWORD PlayerState;
		}

		namespace SceneComponent {
			extern DWORD RelativeLocation;
			extern DWORD ComponentVelocity;
		}

		namespace PlayerState {
			extern PVOID GetPlayerName;
		}

		namespace Actor {
			extern PVOID SetActorHiddenInGame;
			extern DWORD CusstomTimeDilation;
			extern DWORD RootComponent;
		}

		namespace Character {
			extern DWORD Mesh;
		}

		namespace StaticMeshComponent {
			extern DWORD ComponentToWorld;
			extern DWORD StaticMesh;
		}

		namespace SkinnewdMeshComponent {
			extern DWORD CachedWorldSpaceBounds;
		}
	}

	namespace FortniteGame {
		namespace FortPawn {
			extern DWORD bIsDBNO;
			extern DWORD bIsDying;
			extern DWORD CurrentWeapon;
		}

		namespace FortPickup {
			extern DWORD PrimaryPickupItemEntry;
		}

		namespace FortItemEntry {
			extern DWORD ItemDefinition;
		}

		namespace FortItemDefinition {
			extern DWORD DisplayName;
			extern DWORD Tier;
		}

		namespace FortPlayerStateAthena {
			extern DWORD TeamIndex;
			extern DWORD SquadID;
		}

		namespace FortWeapon {
			extern DWORD LastFireTime;
			extern DWORD LastFireTimeVerified;
			extern DWORD WeaponData;
			extern DWORD LastFireAbilityTime;
			extern DWORD IsReloading;
		}

		namespace FortWeaponItemDefinition {
			extern DWORD WeaponStatHandle;
		}

		namespace FortProjectileAthena {
			extern DWORD FireStartLoc;
		}

		// Reloading offsets
		namespace FortBaseWeaponStats {
			extern DWORD ReloadTime;
			extern DWORD ReloadScale;
			extern DWORD ChargeDownTime;
		}

		// Recoil / Spread offsets
		namespace FortRangedWeaponStats {
			extern DWORD RecoilHoriz;
			extern DWORD RecoilVert;
			extern DWORD RecoilDownsightsMultiplier;
			extern DWORD Spread;
			extern DWORD SpreadDownsights;
			extern DWORD StandingStillSpreadMultiplier;
			extern DWORD AthenaJumpingFallingSpreadMultiplier;
			extern DWORD AthenaCrouchingSpreadMultiplier;
			extern DWORD AthenaSprintingSpreadMultiplier;
			extern DWORD MinSpeedForSpreadMultiplier;
			extern DWORD MaxSpeedForSpreadMultiplier;
		}

		namespace BuildingContainer {
			extern DWORD bAlreadySearched;
		}

		namespace BuildingWeakSpot {
			extern DWORD bActive;
		}
	}

	BOOLEAN Initialize();
}