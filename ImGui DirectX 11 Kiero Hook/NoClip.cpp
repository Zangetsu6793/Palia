#include "NoClip.h"

namespace NoClip
{
    std::future<void> result;

    bool EnableNoClip()
    {
        if (!sdk::World) {
            fprintf(stderr, "Error: sdk::World is null.\n");
            return false;
        }

        auto gameInstance = sdk::World->OwningGameInstance;
        if (!gameInstance) {
            fprintf(stderr, "Error: OwningGameInstance is null.\n");
            return false;
        }

        auto localPlayers = gameInstance->LocalPlayers;
        if (!localPlayers) {
            fprintf(stderr, "Error: LocalPlayers array is empty.\n");
            return false;
        }

        auto playerController = localPlayers[0]->PlayerController;
        if (!playerController) {
            fprintf(stderr, "Error: PlayerController is null.\n");
            return false;
        }

        auto acknowledgedPawn = playerController->AcknowledgedPawn;
        if (!acknowledgedPawn) {
            fprintf(stderr, "Error: AcknowledgedPawn is null.\n");
            return false;
        }

        auto character = static_cast<SDK::ACharacter*>(acknowledgedPawn);
        if (!character) {
            fprintf(stderr, "Error: Failed to cast AcknowledgedPawn to ACharacter.\n");
            return false;
        }

        auto characterMovement = character->CharacterMovement;
        if (!characterMovement) {
            fprintf(stderr, "Error: CharacterMovement is null.\n");
            return false;
        }

        // Set movement mode to flying
        characterMovement->MovementMode = SDK::EMovementMode::MOVE_Flying;
        // Disable collision
        character->bActorEnableCollision = false;

        vars::noClipOn = true;
        character->CharacterMovement->GravityScale = 0;

        result = std::async(std::launch::async, NoClipRun);
        return true;
    }

    bool DisableNoClip()
    {
        if (!sdk::World) {
            fprintf(stderr, "Error: sdk::World is null.\n");
            return false;
        }

        auto gameInstance = sdk::World->OwningGameInstance;
        if (!gameInstance) {
            fprintf(stderr, "Error: OwningGameInstance is null.\n");
            return false;
        }

        auto localPlayers = gameInstance->LocalPlayers;
        if (!localPlayers) {
            fprintf(stderr, "Error: LocalPlayers array is empty.\n");
            return false;
        }

        auto playerController = localPlayers[0]->PlayerController;
        if (!playerController) {
            fprintf(stderr, "Error: PlayerController is null.\n");
            return false;
        }

        auto acknowledgedPawn = playerController->AcknowledgedPawn;
        if (!acknowledgedPawn) {
            fprintf(stderr, "Error: AcknowledgedPawn is null.\n");
            return false;
        }

        auto character = static_cast<SDK::ACharacter*>(acknowledgedPawn);
        if (!character) {
            fprintf(stderr, "Error: Failed to cast AcknowledgedPawn to ACharacter.\n");
            return false;
        }

        auto characterMovement = character->CharacterMovement;
        if (!characterMovement) {
            fprintf(stderr, "Error: CharacterMovement is null.\n");
            return false;
        }

        // Set movement mode back to walking (or default)
        characterMovement->MovementMode = SDK::EMovementMode::MOVE_Walking;
        // Enable collision
        character->bActorEnableCollision = true;
        character->CharacterMovement->GravityScale = 9.8;
        vars::noClipOn = false;
        return true;
    }

    void NoClipRun()
    {
        while (vars::noClipOn)
        {
            auto playerController = sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController;
            if (!playerController) {
                fprintf(stderr, "Error: PlayerController is null during NoClipRun.\n");
                break;
            }

            auto pos = playerController->K2_GetActorLocation();
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
            {
                fprintf(stderr, "State: UP.\n");
                // Shift key is pressed
                pos.Y += vars::FlySpeed;
            }
            else if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
            {
                fprintf(stderr, "State: Down.\n");
                // Control key is pressed
                pos.Y -= vars::FlySpeed;
            }
            auto character = static_cast<SDK::ACharacter*>(playerController->AcknowledgedPawn);

            if (character->CharacterMovement->MovementMode != SDK::EMovementMode::MOVE_Flying)
                character->CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Flying;

            character->CharacterMovement->GravityScale = 0;

            //character->CharacterMovement->re
            // Sleep for a short duration to prevent high CPU usage
            Sleep(16); // Approx. 60 updates per second
        }
    }
}