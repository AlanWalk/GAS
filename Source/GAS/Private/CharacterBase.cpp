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
    //���ж�AbilitySytemcomp�Ƿ�Ϊ��
    if (AbilitySystemComponent) {
        //HasAuthrity�����жϿͻ����Ƿ��Actor�п���Ȩ
        //���жϴ���ļ����Ƿ�Ϊ��
        if (HasAuthority() && AbilityToGive) {
            //GiveAbility���ھ����ΪAbilitySystemComp���������������TryActiveAbility
            //FGameplayAbilitySpec��һ�����ڴ洢������Ability��ص�������Ϣ�Ľṹ��
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToGive, 1, 0));
            //InitAbilityActorInfo����˵����˭���߼��Ͽ���Actor(Pawn��Characrter�ȵ�)��˭�������Ͽ��ƣ������ǽ�����Ҳ���ܺ�OwnedActor��ͬ��
            AbilitySystemComponent->InitAbilityActorInfo(this, this);
        }
    }
}