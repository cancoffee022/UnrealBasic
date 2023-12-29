// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelScriptActor/GameLevelScriptActor.h"
#include "Actor/LineGroupActor.h"
#include "../Structure/ColorData.h"
#include "../GameConstants.h"

AGameLevelScriptActor::AGameLevelScriptActor()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_COLOR_TYPE(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DT_ColorType.DT_ColorType'"));

	if (DT_COLOR_TYPE.Succeeded())
		DT_ColorType = DT_COLOR_TYPE.Object;
	else UE_LOG(LogTemp, Error, TEXT("DT_COLOR_TYPE is not loaded!"));

	static ConstructorHelpers::FClassFinder<ALineGroupActor> BP_LINEGROUPACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_LineGroupActor.BP_LineGroupActor_C'"));

	if (BP_LINEGROUPACTOR.Succeeded())
		BP_LineGroupActorClass = BP_LINEGROUPACTOR.Class;
	else UE_LOG(LogTemp, Error, TEXT("BP_LINEGROUPACTOR is not loaded!"));

	// ���� ������ �����մϴ�.
	NextPassableColor = EColorType::Color_White;

	// Map�� ������ ��� ����ϴ�
	ColorDatas.Empty();

	for (FName rowName : DT_ColorType->GetRowNames())
	{
		FString contextString;
		FColorData* colorData = DT_ColorType->FindRow<FColorData>(rowName, contextString);
		// FindRow<T>(rowName, contextString) : rowName�� ��ġ�ϴ� �࿡ ���� ������ T*�������� ����ϴ�.
		// rowName : ã�� �� �̸��� �����մϴ�
		// contextString : ã�� ����� ���� �ΰ� ������ �����ϱ� ���� ���ڿ�

		// Map �� ã�� �����͸� ����մϴ�
		ColorDatas.Add(colorData->ColorType, colorData->Color);
	}
}

void AGameLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < InitialLineGroupCount; ++i)
	{
		GenerateLineGroup(i);
	}

	for (int32 i = 0; i < 10; ++i)
	{
		FString randomizeValues = TEXT("");
		for (EColorType randomColorType : GetSuffledColorTypeArray(EColorType::Color_White))
		{
			randomizeValues += FString::FromInt((int32)randomColorType) + FString(" ");
		}
		UE_LOG(LogTemp, Log, TEXT("%s"), *randomizeValues);
	}
}

ALineGroupActor* AGameLevelScriptActor::GenerateLineGroup(int32 lineGroupIndex)
{
	// ������ų ���� �׷쿡 ���Խ�ų ������ �����صӴϴ�.
	EColorType inclusiveColor = NextPassableColor;

	// ���� ������ �����ϰ� �����մϴ�
	NextPassableColor = GetRandomColorType();

	// LineGroupActor�� �����մϴ�
	ALineGroupActor* newLineGroup = 
		GetWorld()->SpawnActor<ALineGroupActor>(BP_LineGroupActorClass);

	// ������ LineGroupActor�� �ʱ�ȭ �մϴ�.
	newLineGroup->InitializeLineGroup(lineGroupIndex);

	return newLineGroup;
}

FLinearColor AGameLevelScriptActor::GetColorData(EColorType colorType) const
{
	if (!ColorDatas.Contains(colorType))
	{
		UE_LOG(LogTemp, Error, TEXT("colorType is Invalid Value : %d"), (int32)colorType);
		return FLinearColor::Black;
	}

	// colorType �� ���� ������ ��ȯ�մϴ�
	return ColorDatas[colorType];
}


TArray<EColorType> AGameLevelScriptActor::GetSuffledColorTypeArray(EColorType inclusiveColor)
{
	// ���� Ÿ�Կ� ���� �迭
	TArray<EColorType> colorTypes;
	ColorDatas.GetKeys(colorTypes);

	TArray<EColorType> colorTypeArray = colorTypes;

	// ��� ��ҵ��� �����ϴ�.
	// ��� 1�� ���ý�Ű�� ���� for��
	for (int32 i = 0; i < colorTypeArray.Num() - 1; i++)
	{
		// ���2 �ε����� �����մϴ�.
		int32 swapTargetIndex = FMath::RandRange(i + 1, colorTypeArray.Num() - 1);

		// ��� 1�� ���2�� ��ü�մϴ�.
		Swap(colorTypeArray[i], colorTypeArray[swapTargetIndex]);
	}

	// ���� ��ų ���� ����� �ε����� ã���ϴ�
	int inclusiveColorIndex = INDEX_NONE;

	for (int32 i = 0; i < colorTypeArray.Num(); ++i)
	{
		// ���� �l�Խ�ų ������ ã�����
		if (colorTypeArray[i] == inclusiveColor)
		{
			// ���� ��ų ���� ��� �ε����� ��� �����մϴ�
			inclusiveColorIndex = i;
			break;
		}
	}

	// ���ԵǾ�� �ϴ� ������ ��ȯ��ų �迭 �������� ���Խ�ŵ�ϴ�.
	// ���� ���� ��ų ���� ��Ұ� ��ȯ�� �迭 ������ ��� ���
	if (inclusiveColorIndex > FGameConstants::NUMBER_OF_LINEOBJECT - 1)
	{
		// �迭�� ���Խ�ų ���� ��ġ�� ������ų �ε����� �����մϴ�.
		int32 randomIndex = FMath::RandRange(0, FGameConstants::NUMBER_OF_LINEOBJECT - 1);

		// ���� ��ų ���� ��ҿ� randomIndex ��ġ�� ��Ҹ� ��ȯ �մϴ�.
		Swap(colorTypeArray[inclusiveColorIndex], colorTypeArray[randomIndex]);
	}

	// ��ȯ��ų �迭�� �����մϴ�.
	TArray<EColorType> returnValue;
	for (int32 i = 0; i < FGameConstants::NUMBER_OF_LINEOBJECT; ++i)
		returnValue.Add(colorTypeArray[i]);

	return returnValue;
}

EColorType AGameLevelScriptActor::GetRandomColorType() const
{
	// ColorDats�� ��� key�� �迭�� ��ȯ �޽��ϴ�
	TArray<EColorType> colorTypeArray;
	ColorDatas.GetKeys(colorTypeArray);
	
	// ������ �ε����� ����
	int randomIndex = FMath::RandRange(0, colorTypeArray.Num() - 1);

	return colorTypeArray[randomIndex];
}

void AGameLevelScriptActor::Swap(EColorType& ref_a, EColorType& ref_b)
{
	EColorType temp = ref_a;
	ref_a = ref_b;
	ref_b = temp;
}