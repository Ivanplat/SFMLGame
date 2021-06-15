#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "BaseGameObject.h"
#include "BaseActorComponent.h"
#include "PlayerCamera.h"
/*Abstact class for all entities*/
class BaseGameActor : BaseGameObject
{
public:
	template<class ReturnType>
	ReturnType* CreateDefaultSubobject();
	~BaseGameActor();
private:
	std::vector<BaseActorComponent*> ActorSubobjects;
};

template<class ReturnType>
ReturnType* BaseGameActor::CreateDefaultSubobject()
{
	ReturnType* t = new ReturnType();
	BaseActorComponent* component = reinterpret_cast<BaseActorComponent*>(t);
	ActorSubobjects.push_back(component);
	return t;
}
