#include "Skyrim/ExtraData/ExtraCharge.h"
#include "Skyrim.h"

static const UInt32 s_ExtraChargeVtbl = 0x01079228;

ExtraCharge* ExtraCharge::Create()
{
	ExtraCharge* xCharge = (ExtraCharge*)BSExtraData::Create(sizeof(ExtraCharge), s_ExtraChargeVtbl);
	xCharge->charge		 = 0;
	return xCharge;
}
