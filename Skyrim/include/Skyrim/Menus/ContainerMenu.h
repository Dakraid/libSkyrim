#pragma once

#include "../BSCore/BSTArray.h"
#include "../Misc/InventoryChanges.h"
#include "IMenu.h"

/*==============================================================================
class ContainerMenu +0000 (_vtbl=010E4098)
0000: class ContainerMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
class ContainerMenu : public IMenu
{
	public:
	virtual ~ContainerMenu(); // 0084A6A0

	// @override
	virtual void   Accept(CallbackProcessor* processor) override; // 0084C100
	virtual UInt32 ProcessMessage(UIMessage* message) override;	  // 0084B970
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

	GFxValue	   root;
	InventoryData* inventoryData; // init'd 0
};
