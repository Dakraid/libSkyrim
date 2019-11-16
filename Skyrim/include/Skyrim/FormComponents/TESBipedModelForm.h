#pragma once

#include "BGSMessageIcon.h"
#include "BaseFormComponent.h"
#include "TESIcon.h"
#include "TESModelRDT.h"
#include "TESModelTextureSwap.h"

// 78
class TESBipedModelForm : public BaseFormComponent
{
	public:
	TESModelTextureSwap textureSwap[2]; // 04
	TESIcon				icon[2];		// 3C
	BGSMessageIcon		messageIcon[2]; // 4C
	TESModelRDT			modelRDT;		// 64
};
