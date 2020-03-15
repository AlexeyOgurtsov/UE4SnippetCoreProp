#include "DemoComponent.h"
#include "Util/Core/LogUtilLib.h"
#include "Util/Property/PropertyLogLib.h"

void UDemoComponent::PostInitProperties()
{
	M_LOGFUNC();

	Super::PostInitProperties();
}

void UDemoComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	M_LOGFUNC();

	M_LOG(TEXT("Before Super call"));
	UPropertyLogLib::LogPropertyChangedEvent(PropertyChangedEvent);

	Super::PostEditChangeProperty(PropertyChangedEvent);

	M_LOG(TEXT("After Super call"));
	UPropertyLogLib::LogPropertyChangedEvent(PropertyChangedEvent);
}

void UDemoComponent::PreEditChange(UProperty* PropertyAboutToChange)
{
	M_LOGFUNC();
	ULogUtilLib::LogStringC(TEXT("PropertyAboutToChange"), UPropertyLogLib::GetFieldStringSafe(PropertyAboutToChange));
	Super::PreEditChange(PropertyAboutToChange);
}
