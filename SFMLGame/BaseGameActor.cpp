#include "BaseGameActor.h"

BaseGameActor::~BaseGameActor()
{
	for (auto i : ActorSubobjects)
	{
		if (i)
		{
			delete i;
		}
	}
}
