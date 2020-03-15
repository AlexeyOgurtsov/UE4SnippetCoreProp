#include "DemoActor.h"
#include "Util/Core/LogUtilLib.h"
#include "Util/Property/PropertyLogLib.h"
#include "DemoComponent.h"

ADemoActor::ADemoActor()
{
	DemoComp = CreateDefaultSubobject<UDemoComponent>(TEXT("DemoComponent"));
}

void ADemoActor::BeginPlay()
{
	M_LOGFUNC();
	Super::BeginPlay();
}
void ADemoActor::PostInitProperties()
{
	M_LOGFUNC();

	Super::PostInitProperties();
}

void ADemoActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	M_LOGFUNC();

	M_LOG(TEXT("Before Super call"));
	UPropertyLogLib::LogPropertyChangedEvent(PropertyChangedEvent);

	Super::PostEditChangeProperty(PropertyChangedEvent);

	M_LOG(TEXT("After Super call"));
	UPropertyLogLib::LogPropertyChangedEvent(PropertyChangedEvent);
}

void ADemoActor::PreEditChange(UProperty* PropertyAboutToChange)
{
	M_LOGFUNC();
	ULogUtilLib::LogStringC(TEXT("PropertyAboutToChange"), UPropertyLogLib::GetFieldStringSafe(PropertyAboutToChange));
	Super::PreEditChange(PropertyAboutToChange);
}
