#include "Skyrim/FormComponents/BGSPerkRankArray.h"
#include "Skyrim.h"

void BGSPerkRankArray::VisitPerkRanks(PerkRankVisitor& visitor) const
{
	for(UInt32 i = 0; i < numPerkRanks; ++i) {
		if(visitor(perkRanks) == false) return;
	}
}
