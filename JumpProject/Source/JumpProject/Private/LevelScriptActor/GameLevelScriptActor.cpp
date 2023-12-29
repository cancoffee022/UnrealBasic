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

	// 시작 색상을 정의합니다.
	NextPassableColor = EColorType::Color_White;

	// Map의 내용을 모두 지웁니다
	ColorDatas.Empty();

	for (FName rowName : DT_ColorType->GetRowNames())
	{
		FString contextString;
		FColorData* colorData = DT_ColorType->FindRow<FColorData>(rowName, contextString);
		// FindRow<T>(rowName, contextString) : rowName과 일치하는 행에 대한 내용을 T*형식으로 얻습니다.
		// rowName : 찾을 행 이름을 전달합니다
		// contextString : 찾기 결과에 대한 부가 내용을 전달하기 위한 문자열

		// Map 에 찾은 데이터를 기록합니다
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
	// 생성시킬 라인 그룹에 포함시킬 색상을 저장해둡니다.
	EColorType inclusiveColor = NextPassableColor;

	// 다음 색상을 랜덤하게 설정합니다
	NextPassableColor = GetRandomColorType();

	// LineGroupActor를 생성합니다
	ALineGroupActor* newLineGroup = 
		GetWorld()->SpawnActor<ALineGroupActor>(BP_LineGroupActorClass);

	// 생성된 LineGroupActor를 초기화 합니다.
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

	// colorType 에 대한 색상값을 반환합니다
	return ColorDatas[colorType];
}


TArray<EColorType> AGameLevelScriptActor::GetSuffledColorTypeArray(EColorType inclusiveColor)
{
	// 색상 타입에 대한 배열
	TArray<EColorType> colorTypes;
	ColorDatas.GetKeys(colorTypes);

	TArray<EColorType> colorTypeArray = colorTypes;

	// 모든 요소들을 섞습니다.
	// 대상 1을 선택시키기 위한 for문
	for (int32 i = 0; i < colorTypeArray.Num() - 1; i++)
	{
		// 대상2 인덱스를 선택합니다.
		int32 swapTargetIndex = FMath::RandRange(i + 1, colorTypeArray.Num() - 1);

		// 대상 1과 대상2를 교체합니다.
		Swap(colorTypeArray[i], colorTypeArray[swapTargetIndex]);
	}

	// 포함 시킬 색상 요소의 인덱스를 찾습니다
	int inclusiveColorIndex = INDEX_NONE;

	for (int32 i = 0; i < colorTypeArray.Num(); ++i)
	{
		// 만약 퐇함시킬 색상을 찾은경우
		if (colorTypeArray[i] == inclusiveColor)
		{
			// 포함 시킬 색상 요소 인덱스를 잠시 저장합니다
			inclusiveColorIndex = i;
			break;
		}
	}

	// 포함되어야 하는 색상을 반환시킬 배열 범위내에 포함시킵니다.
	// 만약 포함 시킬 색상 요소가 반환될 배열 범위를 벗어난 경우
	if (inclusiveColorIndex > FGameConstants::NUMBER_OF_LINEOBJECT - 1)
	{
		// 배열에 포함시킬 값의 위치를 결정시킬 인덱스를 설정합니다.
		int32 randomIndex = FMath::RandRange(0, FGameConstants::NUMBER_OF_LINEOBJECT - 1);

		// 포함 시킬 색상 요소와 randomIndex 위치의 요소를 교환 합니다.
		Swap(colorTypeArray[inclusiveColorIndex], colorTypeArray[randomIndex]);
	}

	// 반환시킬 배열을 생성합니다.
	TArray<EColorType> returnValue;
	for (int32 i = 0; i < FGameConstants::NUMBER_OF_LINEOBJECT; ++i)
		returnValue.Add(colorTypeArray[i]);

	return returnValue;
}

EColorType AGameLevelScriptActor::GetRandomColorType() const
{
	// ColorDats의 모든 key를 배열로 반환 받습니다
	TArray<EColorType> colorTypeArray;
	ColorDatas.GetKeys(colorTypeArray);
	
	// 랜덤한 인덱스를 얻음
	int randomIndex = FMath::RandRange(0, colorTypeArray.Num() - 1);

	return colorTypeArray[randomIndex];
}

void AGameLevelScriptActor::Swap(EColorType& ref_a, EColorType& ref_b)
{
	EColorType temp = ref_a;
	ref_a = ref_b;
	ref_b = temp;
}