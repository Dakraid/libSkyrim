#pragma once

#include "../BSCore/BSTArray.h"

class Actor;
class MagicItem;

/*==============================================================================
class MagicCaster +0000 (_vtbl=010C95B4)
0000: class MagicCaster
==============================================================================*/
class MagicCaster
{
	public:
	virtual ~MagicCaster(); // 00660D60

	virtual void   InitMagicCaster(MagicItem* arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6, UInt32 arg7); // 01 00662040
	virtual UInt32 MagicCaster_Unk_02(void);																					   // 02 0065F4E0
	virtual void   MagicCaster_Unk_03(void);																					   // 03 0065EEE0
	virtual bool   MagicCaster_Unk_04(void);																					   // 04 0065FDF0
	virtual void   MagicCaster_Unk_05(void);																					   // 05 0065E2E0
	virtual void   MagicCaster_Unk_06(void);																					   // 06 00662420
	virtual void   MagicCaster_Unk_07(void);																					   // 07 006C50E0 { return; }
	virtual void   MagicCaster_Unk_08(UInt32 arg1);																				   // 08 00588F30 { return; }
	virtual void   MagicCaster_Unk_09(UInt32 arg1, UInt32 arg2, UInt32 arg3);													   // 09 00D62BE0 { return; }
	virtual bool   MagicCaster_Unk_0A(UInt32 arg1, UInt32 arg2, float* arg3, UInt32* arg4, UInt32 arg5, UInt32 arg6, UInt32 arg7); // 0A 0065E0F0
																																   //				{ if (arg3) { *arg3 = 1.0; } if (arg4) { *arg4 = 0; } }
	virtual Actor* MagicCaster_Unk_0B(void);																					   // 0B 005EADD0 { return nullptr; }
	virtual Actor* GetCaster();																									   // 0C 005EADD0 { return nullptr; }
	virtual Actor* MagicCaster_Unk_0D(Actor** arg1);																			   // 0D 0065E120
	virtual UInt32 MagicCaster_Unk_0E(void);																					   // 0E 005EADD0 { return nullptr; }
	virtual void   MagicCaster_Unk_0F(void);																					   // 0F 006C50E0 { return; }
	virtual void   MagicCaster_Unk_10(MagicItem* arg);																			   // 10 00588F30 { return; }
	virtual void   MagicCaster_Unk_11(void);																					   // 11 006C50E0 { return; }
	virtual void   MagicCaster_Unk_12(void);																					   // 12 006C50E0 { return; }
	virtual void   MagicCaster_Unk_13(void);																					   // 13 006C50E0 { return; }
	virtual void   CalculateMagickaCost(void);																					   // 14 0065E7A0
	virtual UInt32 GetSlot(void);																								   // 15 005EADD0 { return 0; }
	virtual bool   MagicCaster_Unk_16(void);																					   // 16 0092D110 { return false; }
	virtual void   MagicCaster_Unk_17(bool b);																					   // 17 00588F30 { return; }
	virtual void   MagicCaster_Unk_18(UInt32 arg1);																				   // 18 0065FBB0
	virtual void   MagicCaster_Unk_19(UInt32 arg1);																				   // 19 0065FB20
	virtual void   MagicCaster_Unk_1A(UInt32 arg1);																				   // 1A 0065F290
	virtual void   MagicCaster_Unk_1B(UInt32 arg1, UInt32 arg2);																   // 1B 0065EC70
	virtual void   MagicCaster_Unk_1C(UInt32 arg1, UInt32 arg2, UInt32 arg3);													   // 1C 0065E0D0

	// @members
	// void				** _vtbl;		// 00 - 010C95B4
	BSTArray<void*> unk04;	   // 04
	RefHandle		unk10;	   // 10 - init'd to 0 | maybe RefHandle
	MagicItem*		magicItem; // 14 - init'd to 0
	UInt32			unk18;	   // 18 - init'd to 0 | current state? 1=cast start 7=???
	float			castTime;  // 1C - init'd to 0
	float			cost;	   // 20 - init'd to 1.0f
	UInt32			unk24;	   // 24 - init'd to 0 | temporary init'd arg6 in InitMagicCaster()
	float			unk28;	   // 28 - init'd to 0 | 3E800000 = 0.25f
	UInt32			unk2C;	   // 2C 0

	// ctor		0065FD90
};
STATIC_ASSERT(sizeof(MagicCaster) == 0x30);
