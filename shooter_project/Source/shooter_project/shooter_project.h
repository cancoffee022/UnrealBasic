#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"

// World Item Actor �� �߰��Ǵ� �±��Դϴ�
#define TAG_WORLDITEM				FName(TEXT("WorldItem"))

// �ѱ� ��ġ�� ��Ÿ���� ���� �̸�
#define SOCKET_NAME_FIRE_POS		FName(TEXT("Socket_Fire"))

#define BULLETACTOR_LIFETIME		4.0f

#define WLOG(_log_, ...) UE_LOG(LogTemp,Warning, _log_, ##__VA_ARGS__)

#define PLOG(_log_, ...) UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(_log_, ##__VA_ARGS__), true, true, FLinearColor::Green, 3.0f)