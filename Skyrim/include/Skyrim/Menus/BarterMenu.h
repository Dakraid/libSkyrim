#pragma once

#include "../BSCore/BSTArray.h"
#include "../Misc/InventoryChanges.h"
#include "IMenu.h"

/*==============================================================================
class BarterMenu +0000 (_vtbl=010E3860)
0000: class BarterMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 68
class BarterMenu : public IMenu
{
	public:
	// unk0C - 0
	// Flags - 0xA489
	// unk14 - 3
	virtual ~BarterMenu(); // 00842D50

	// @override
	virtual void   Accept(CallbackProcessor* processor) override; // 00843C20
	virtual UInt32 ProcessMessage(UIMessage* message) override;	  // 00844560
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

	struct BarterData
	{
		TESObjectREFR* barterTarget;			 // 00 // actually a smart pointer
		bool		   unk04;					 // 04
		bool		   bypassVendorStolenCheck;	 // 05 // player actor value BypassVendorStolenCheck != 0?
		bool		   bypassVendorKeywordCheck; // 06 // player actor value BypassVendorKeywordCheck != 0?

		DEFINE_MEMBER_FN(ctor, void, 0x00842D80, TESObjectREFR* target);
	};

	InventoryData* inventoryData; // 1C - init'd 0

	/*
	GFxValue*	   root;		  //  ? - view->GetVariable(&root, "Menu_mc") (00869AF0)
	UInt32		   pad20;		  // init'd 0
	UInt32		   pad24;		  // init'd 0
	UInt32		   pad28;		  // init'd 0
	UInt32		   pad38;
	UInt32		   pad3C;
	UInt32		   pad40;
	UInt32		   pad44;
	UInt8		   pad48;
	UInt32		   pad58;
	UInt32		   pad5C;
	UInt32		   pad60;
	bool		   pad64; // bPCControlsReady ?
	*/

	/*
	mov     dword ptr ds:[esi], tesv.10E3860
	mov     dword ptr ds:[esi + 0x1C], ebx
	mov     dword ptr ds:[esi + 0x20], ebx
	mov     dword ptr ds:[esi + 0x24], ebx
	mov     dword ptr ds:[esi + 0x28], ebx
	mov     dword ptr ds:[esi + 0x2C], ebx
	mov     dword ptr ds:[esi + 0x38], ebx
	mov     dword ptr ds:[esi + 0x3C], ebx
	mov     dword ptr ds:[esi + 0x40], ebx
	mov     dword ptr ds:[esi + 0x44], ebx
	mov     byte  ptr ds:[esi + 0x48], bl
	mov     dword ptr ds:[esi + 0x58], ebx
	mov     dword ptr ds:[esi + 0x5C], ebx
	mov     dword ptr ds:[esi + 0x60], ebx
	mov     byte  ptr ds:[esi + 0x64], bl
	mov     dword ptr ds:[esi + 0x10], 0xA489
	mov     dword ptr ds:[esi + 0x14], 0x3
	mov     byte  ptr ds:[esi + 0xC] , bl
	mov     byte  ptr ds:[esi + 0x64], 0x1
	*/

	private:
	DEFINE_MEMBER_FN(ctor, BarterMenu*, 0x00842690);
};
// static_assert(sizeof(BarterMenu) >= 0x68, "BarterMenu is too small!");
static_assert(sizeof(BarterMenu) <= 0x68, "BarterMenu is too large!");
static_assert(offsetof(BarterMenu, inventoryData) >= 0x1C, "BarterMenu::inventoryData is too early!");
static_assert(offsetof(BarterMenu, inventoryData) <= 0x1C, "BarterMenu::inventoryData is too late!");
