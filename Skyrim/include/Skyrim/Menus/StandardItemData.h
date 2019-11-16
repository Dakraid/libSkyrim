#pragma once

#include "IMenu.h"
#include "../BSCore/BSTArray.h"
#include "../Misc/InventoryChanges.h"

/*==============================================================================
class StandardItemData +0000 (_vtbl=010E3778)
0000: class StandardItemData
==============================================================================*/
// 20
class StandardItemData
{
public:
	virtual ~StandardItemData();						// 00841A60

	// @override
	virtual const char *	GetName(void);				// 01 00867C30 { return objDesc->GenerateName(); } - called from 00842193
	virtual UInt32			GetCount(void);				// 02 00867C40 { return objDesc->GetCount(); }
	virtual UInt32			GetEquipState(void);		// 03 00868A80
	virtual UInt32			GetFilterFlag(void);		// 04 00868330
	virtual UInt32			GetFavorite(void);			// 05 00867C50
	virtual bool			GetEnabled(void);			// 06 009B86F0 { return true; }

	// @members
	//void				** _vtbl;	// 00 - 010E3778
	InventoryEntryData	* objDesc;	// 04 - init'd pEntry
	UInt32				unk08;		// 08 - init'd *arg3  always 0x00100000 ?
	UInt32				pad0C;		// 0C
#pragma pack(4)
	GFxValue			fxValue;	// 10
#pragma pack()

private:
	DEFINE_MEMBER_FN(ctor, StandardItemData *, 0x00842140, GFxMovieView ** movieView, InventoryEntryData * pEntry, void* arg3);
};
STATIC_ASSERT(sizeof(StandardItemData) == 0x20);
STATIC_ASSERT(offsetof(StandardItemData, objDesc) == 0x04);
STATIC_ASSERT(offsetof(StandardItemData, fxValue) == 0x10);
