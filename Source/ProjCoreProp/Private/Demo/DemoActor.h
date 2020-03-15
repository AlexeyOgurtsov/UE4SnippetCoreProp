#pragma once

/**
* To be copied to the destination and changed.
*/

#include "Util/TestUtil/TUVisibleActor.h"
//#include "UObject/TextProperty.h" // we MUST include it to make UTextProperty work
#include "DemoActor.generated.h"

class UDemoComponent;

UCLASS()
class ADemoActor : public ATUVisibleActor
{
	GENERATED_BODY()

public:
	ADemoActor();

	virtual void BeginPlay() override;

	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; 
	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;

	UPROPERTY(EditAnywhere, Category = Test)
	UDemoComponent* DemoComp = nullptr;

	// ~UPROPERTY Actor/Component Begin
	/**
	* Actors of Actor DO can be set
	*/
	UPROPERTY(EditAnywhere, Category = Test)
	AActor* ActorProp = nullptr;

	/**
	* Components of Actor DO can be set
	*/
	UPROPERTY(EditAnywhere, Category = Test)
	UActorComponent* ComponentProp = nullptr;

	UPROPERTY(EditAnywhere, Category = Test)
	TArray<FString> StringArrayProp;
	// ~UPROPERTY End
	
	// ~Text UPROPERTY Begin
	UPROPERTY(EditAnywhere, Category = Test)
	FText TextProperty;
	// ~Text UPROPERTY End
};
