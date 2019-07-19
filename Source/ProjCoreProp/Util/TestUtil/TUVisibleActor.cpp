#include "TUVisibleActor.h"
#include "VisibleActorConfig.h"
#include "Util/Core/LogUtilLib.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/SphereComponent.h"

#include "UObject/ConstructorHelpers.h"

using namespace VisibleActorConfig;

ATUVisibleActor::ATUVisibleActor()
{
	RootComponent = RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));

	InitCameraAndSpringArm(RootSceneComponent);
	InitMesh(RootSceneComponent);
	InitProxSphere(RootSceneComponent);
}

void ATUVisibleActor::InitCameraAndSpringArm(USceneComponent* InAttachTo)
{
	checkf(InAttachTo, TEXT("When calling %s component to attach to must be non-NULL pointer"), TEXT(__FUNCTION__));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = Default::SPRINGARM_TARGET_ARM_LENGTH;
	SpringArm->RelativeRotation = Default::SPRINGARM_RELATIVE_ROTATION;
	SpringArm->RelativeLocation = Default::SPRINGARM_RELATIVE_LOCATION;
	SpringArm->bEnableCameraLag = Default::SPRINGARM_ENABLE_CAMERA_LAG;
	SpringArm->CameraLagSpeed = Default::SPRINGARM_CAMERA_LAG_SPEED;
	SpringArm->SetupAttachment(InAttachTo);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = true;
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ATUVisibleActor::InitMesh(USceneComponent* InAttachTo)
{
	checkf(InAttachTo, TEXT("When calling %s component to attach to must be non-NULL pointer"), TEXT(__FUNCTION__));

	static ConstructorHelpers::FObjectFinderOptional<UStaticMesh> MeshFinder { Default::MESH_ASSET_PATH };
	M_LOG_ERROR_IF( ! MeshFinder.Succeeded(), TEXT("Default mesh (\"%s\") NOT found"), Default::MESH_ASSET_PATH);

	{
		Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

		if(MeshFinder.Succeeded())
		{
			M_LOG(TEXT("Default mesh (\"%s\") found, setting it up"), Default::MESH_ASSET_PATH);
			Mesh->SetStaticMesh(MeshFinder.Get());
		}

		Mesh->SetupAttachment(InAttachTo);
	}
}

void ATUVisibleActor::InitProxSphere(USceneComponent* InAttachTo)
{
	checkf(InAttachTo, TEXT("When calling %s component to attach to must be non-NULL pointer"), TEXT(__FUNCTION__));

	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	ProxSphere->InitSphereRadius(Default::PROX_SPHERE_RADIUS);
	ProxSphere->RelativeLocation = Default::MESH_REAL_CENTER_ACTOR_SPACE_LOCATION;
	ProxSphere->SetupAttachment(InAttachTo);
}
