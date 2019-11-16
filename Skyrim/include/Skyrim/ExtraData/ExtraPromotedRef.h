#pragma once

#include "../BSCore/BSTArray.h"
#include "BSExtraData.h"

class TESForm;

class ExtraPromotedRef : public BSExtraData
{
	public:
	enum
	{
		kExtraTypeID = (UInt32)ExtraDataType::PromotedRef
	};

	ExtraPromotedRef();
	virtual ~ExtraPromotedRef();

	BSTArray<TESForm*> unk08;
};
