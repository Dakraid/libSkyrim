#pragma once

#include "../BSCore/BSTArray.h"
#include "BSExtraData.h"

class TESFaction;

class ExtraFactionChanges : public BSExtraData
{
	public:
	enum
	{
		kExtraTypeID = (UInt32)ExtraDataType::FactionChanges
	};

	ExtraFactionChanges();
	virtual ~ExtraFactionChanges();

	struct FactionInfo
	{
		TESFaction* faction;
		UInt32		rank;
	};

	UInt32				  unk08;
	BSTArray<FactionInfo> factions;
};
