#include "Actor/EnemyController/Dragon/DragonController.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BlackboardComponent.h"

void ADragonController::SetPlayerCharacterKey(AGameCharacter* playerCharacter)
{
	BlackboardComponent->SetValueAsObject(KEYNAME_PLAYERCHARACTER, playerCharacter);
}

void ADragonController::OnDashFinished()
{
	BlackboardComponent->SetValueAsBool(KEYNAME_ISMOVETASKRUNNING, false);
}

void ADragonController::UpdateCurrentHp(float currentHp)
{
	BlackboardComponent->SetValueAsFloat(KEYNAME_CURRENTHP, currentHp);
}
