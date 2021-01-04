// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ACharacterBase::GiveAbility(TSubclassOf<UGameplayAbility> AbilityToGive)
{
    //先判断AbilitySytemcomp是否为空
    if (AbilitySystemComponent) {
        //HasAuthrity用于判断客户端是否对Actor有控制权
        //再判断传入的技能是否为空
        if (HasAuthority() && AbilityToGive) {
            //GiveAbility用于具体的为AbilitySystemComp赋予能力，会调用TryActiveAbility
            //FGameplayAbilitySpec是一个用于存储被赋予Ability相关的数据信息的结构体
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToGive, 1, 0));
            //InitAbilityActorInfo用于说明是谁在逻辑上控制Actor(Pawn、Characrter等等)、谁在物理上控制（可以是建筑，也可能和OwnedActor相同）
            AbilitySystemComponent->InitAbilityActorInfo(this, this);
        }
    }
}