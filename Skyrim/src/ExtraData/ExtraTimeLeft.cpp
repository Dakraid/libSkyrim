#include "Skyrim/ExtraData/ExtraTimeLeft.h"
#include "Skyrim.h"

static const UInt32 s_ExtraTimeLeftVtbl = 0x01079218;

ExtraTimeLeft* ExtraTimeLeft::Create(float time)
{
	ExtraTimeLeft* xLeft = (ExtraTimeLeft*)BSExtraData::Create(sizeof(ExtraTimeLeft), s_ExtraTimeLeftVtbl);
	xLeft->time			 = time;
	return xLeft;
}
