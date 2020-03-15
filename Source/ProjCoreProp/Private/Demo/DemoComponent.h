#pragma once

#include "Components/ActorComponent.h"
#include "DemoComponent.generated.h"

class UActorComponent;
class AActor;

UCLASS()
class UDemoComponent : public UActorComponent
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; 
	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;

public:
	UPROPERTY(EditAnywhere, Category = Test)
	UActorComponent* ComponentProp = nullptr;

	UPROPERTY(EditAnywhere, Category = Test)
	AActor* ActorProp = nullptr;
};
