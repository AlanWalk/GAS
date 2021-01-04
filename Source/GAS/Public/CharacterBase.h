// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CharacterBase.generated.h"

UCLASS()
class GAS_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = BaseCharacter)
	void GiveAbility(TSubclassOf<UGameplayAbility>AbilityToGive);

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UAbilitySystemComponent* AbilitySystemComponent;
};
