#include "Prop.h"

bool Prop::init()
{
	return true;
}

Prop::Prop(int num)
{
	def = PropInfo[num][0];
	atk = PropInfo[num][1];
	hp = PropInfo[num][2];
}
