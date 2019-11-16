#pragma once

#include "../BSCore/BSTArray.h"
#include "TESRegionData.h"

class BGSMusicType;
class BGSSoundDescriptorForm;

// 18
class TESRegionDataSound : public TESRegionData
{
	public:
	virtual ~TESRegionDataSound();

	BGSMusicType* musicType; // 08

	struct SoundData
	{
		BGSSoundDescriptorForm* soundDescriptor; // 00
		UInt32					flags;			 // 04
		float					chance;			 // 08
	};

	BSTArray<SoundData*> soundData; // 0C
};
