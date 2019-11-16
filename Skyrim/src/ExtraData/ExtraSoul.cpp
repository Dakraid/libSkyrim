#include "Skyrim/ExtraData/ExtraSoul.h"
#include "Skyrim.h"

static const UInt32 s_ExtraSoulVtbl = 0x01079D6C;

ExtraSoul* ExtraSoul::Create()
{
	ExtraSoul* xSoul = (ExtraSoul*)BSExtraData::Create(sizeof(ExtraSoul), s_ExtraSoulVtbl);
	return xSoul;
}
