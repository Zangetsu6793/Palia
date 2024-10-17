#include "GodMode.h"

namespace GodMode
{
	bool GodMode()
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
             return false ;
        }

        auto playerController = localPlayers[0]->PlayerController;
        if (!playerController) {
            fprintf(stderr, "Error: PlayerController is null.\n");
             return false ;
        }
        SDK::AActor* AcknowledgedPawn = (SDK::AActor*)localPlayers[0];
        if (!AcknowledgedPawn) {
            fprintf(stderr, "Error: AcknowledgedPawn is null.\n");
             return false ;
        }
        //AcknowledgedPawn->bCanBeDamaged = !vars::Godmode;
        return true;
	}
}