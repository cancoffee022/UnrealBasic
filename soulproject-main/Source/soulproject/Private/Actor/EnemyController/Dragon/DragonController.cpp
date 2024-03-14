#include "Actor/EnemyController/Dragon/DragonController.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BlackboardComponent.h"

void ADragonController::SetPlayerCharacterKey(AGameCharacter* playerCharacter)
{
	BlackboardComponent->SetValueAsObject(KEYNAME_PLAYERCHARACTER, playerCharacter);
}
