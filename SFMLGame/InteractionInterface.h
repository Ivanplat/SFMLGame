#pragma once
#include "BaseGameActor.h"
/*CRTP Interface for entities*/
template<class T>
class InteractionInterface
{
public:
	virtual void Interact(BaseGameActor* Caller)
	{
		static_cast<T*>(this)->Interact(Caller);
	}
};
