#pragma once

#include "../BSCore/BSTArray.h"
#include "../Misc/InventoryChanges.h"
#include "IMenu.h"

/*==============================================================================
class InventoryMenu +0000 (_vtbl=010E5B90)
0000: class InventoryMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 58
class InventoryMenu : public IMenu
{
	public:
	// InventoryMenu
	// unk0C - 0
	// Flags - 0x4400
	// unk14 - 0x12

	virtual ~InventoryMenu(); // 0086A450

	// @override
	virtual void   Accept(CallbackProcessor* processor) override; // 0086B240
	virtual UInt32 ProcessMessage(UIMessage* message) override;	  // 0086BA80
	virtual void   Render(void) override;						  // 00849200

	struct InventoryData
	{
		void*						unk00;			  // 00
		GFxValue					categoryListRoot; // 08
		GFxValue					unk18;			  // 18
		BSTArray<StandardItemData*> items;			  // 28
		bool						selected;		  // 34

		DEFINE_MEMBER_FN(GetSelectedItemData, StandardItemData*, 0x00841D90);
		DEFINE_MEMBER_FN(Update, void, 0x00841E70, TESObjectREFR* owner);
	};

	struct Data3C // BSTArray?
	{
		UInt32 unk00;
		UInt32 unk04;
		UInt32 unk08; // ctor 0x00A49B40 { this->unk00 = 0; }
	};

	// @members
	// void			** _vtbl;			// 00 - 010E5B90
	// UInt32		pad1C;				// 1C - pad for alignment
	GFxValue	   root;			 // 20 - view->GetVariable(&root, "Menu_mc") (00869AF0)
	InventoryData* inventoryData;	 // 30 - init'd 0
	GFxValue*	   unk34;			 // 34 - init'd 0
	GFxValue*	   unk38;			 // 38 - init'd 0
	Data3C		   unk3C;			 // 3C - BSTArray? ctor 0x00A49AD0
	UInt8		   unk48;			 // 48 - UInt8?
	UInt32		   unk4C;			 // 4C - init'd 0
	bool		   bPCControlsReady; // 50 - init'd 0 root.GetMember("bPCControlsReady", tmpValue) (00869B15)
	bool		   unk51;			 // 51 - init'd 0

	private:
	DEFINE_MEMBER_FN(ctor, InventoryMenu*, 0x00869A70);
};
STATIC_ASSERT(sizeof(InventoryMenu) == 0x58);
STATIC_ASSERT(offsetof(InventoryMenu, root) == 0x20);
STATIC_ASSERT(offsetof(InventoryMenu, inventoryData) == 0x30);
