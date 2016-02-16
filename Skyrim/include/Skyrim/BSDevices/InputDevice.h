#pragma once

#include "../BSCore/BSTHashMap.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class BSInputDevice +0000 (_vtbl=0110E944)
0000: class BSInputDevice
==============================================================================*/
// 28
class BSInputDevice
{
public:
	enum Type
	{
		kType_Keyboard = 0,
		kType_Mouse,
		kType_Gamepad
	};

	// 10
	struct Data
	{
		BSFixedString	name;		// 00
		float			timer;		// 04
		UInt32			charCode;	// 08
		UInt32			unk0C;		// 0C
	};

	virtual UInt32	Unk_00(void) = 0;					// 00 
	virtual	void	Unk_01(float unk1) = 0;				// 01 
	virtual	void	Unk_02(void) = 0;					// 02 
	virtual bool	IsEnabled(void) const;				// 03 009B86F0 { return true; }
	virtual			~BSInputDevice();					// 04 00A6AD80
	virtual void	Unk_05(void) = 0;					// 05

	inline bool IsKeyboard() const	{ return type == kType_Keyboard; }
	inline bool IsMouse() const		{ return type == kType_Mouse; }
	inline bool IsGamepad() const	{ return type == kType_Gamepad; }

	inline bool IsPressed(UInt32 keyCode) const
	{
		Data *data = nullptr;
		return (codeMap.GetAt(keyCode, data) && data->timer > 0.0f);
	}

	// @members
	Type						type;		// 04
	BSTHashMap<UInt32, Data *>	codeMap;	// 08
};


/*==============================================================================
class BSMouseDevice +0000 (_vtbl=0110EDF4)
0000: class BSMouseDevice
0000: |   class BSInputDevice
==============================================================================*/
// 28+
class BSMouseDevice : public BSInputDevice
{
public:
	// @add
	virtual	void	Unk_06(bool arg);				// 00588F30 (UInt32 arg) { return; }

	//BSMouseDevice();		// 00A6AD40
};


/*==============================================================================
class BSWin32MouseDevice +0000 (_vtbl=0110ED94)
0000: class BSWin32MouseDevice
0000: |   class BSMouseDevice
0000: |   |   class BSInputDevice
==============================================================================*/
// 5C
class BSWin32MouseDevice : public BSMouseDevice
{
public:
	// @override
	virtual	UInt32	Unk_00(void) override;			// 00 00A69F40
	virtual	void	Unk_01(float arg) override;		// 01 00A69FE0
	virtual	void	Unk_02(void) override;			// 02 00A6A0C0 { [01B2E9BC]->Unk_00A696F0(unk2C); unk2C = 0; }
	virtual	void	Unk_05(void) override;			// 05 00A69F10 { each (unk30 ... unk54) = 0; }
	virtual	void	Unk_06(bool arg) override;		// 06 00A69EE0 { unk28 = arg; unk58 = true; Unk_02(); Unk_00(); unk58 = false; }
};


/*==============================================================================
class BSKeyboardDevice +0000 (_vtbl=0110EE58)
0000: class BSKeyboardDevice
0000: |   class BSInputDevice
==============================================================================*/
// 28+
class BSKeyboardDevice : public BSInputDevice
{
public:
	// @members



private:
	DEFINE_MEMBER_FN(ctor, BSKeyboardDevice *, 0x00A6ADB0);
};


/*==============================================================================
class BSWin32KeyboardDevice +0000 (_vtbl=0110EDB4)
0000: class BSWin32KeyboardDevice
0000: |   class BSKeyboardDevice
0000: |   |   class BSInputDevice
==============================================================================*/
// 02F4
class  BSWin32KeyboardDevice : public BSKeyboardDevice
{
public:
	virtual	UInt32	Unk_00(void) override;			// 00 00A6B060
	virtual	void	Unk_01(float arg) override;		// 01 00A6B110 { MapVirtualKey, ToUnicode, ... }
	virtual	void	Unk_02(void) override;			// 02 00A6B2B0 { [1B2E9BC]->Unk_00A696F0(unk28); unk28 = 0; }
	virtual	void	Unk_05(void) override;			// 05 00A6B030 { Unk_00F52240(0, &unk0F4); Unk_00F52240(&unk1F4, 0, 100); }
};


/*==============================================================================
class BSGamepadDevice +0000 (_vtbl=0110E960)
0000: class BSGamepadDevice
0000: |   class BSInputDevice
==============================================================================*/
// 2E+
class BSGamepadDevice : public BSInputDevice
{
public:
	// @override
	virtual bool	IsEnabled(void) const override;		// 03 00A69EC0	{ return unk2C && unk28 != -1; }

														// @add
	virtual	void	Unk_06(void) = 0;					// 00F51EE8 (pure)

	
	// @members
	//void	** _vtbl;		// 00 - 0110E960
	SInt32	unk28;			// 28 - init'd -1
	bool	unk2C;			// 2C - init'd false - isConnected ?
	bool	unk2D;			// 2D - init'd false

private:
	//BSGamepadDevice();					// 00A69E70
	//init_hash(const char* txtPath);		// 00A6AC60 - txtPath = "Interface/Controls/PC/Gamepad.txt"
};


/*==============================================================================
class BSWin32GamepadDevice +0000 (_vtbl=0110EDD0)
0000: class BSWin32GamepadDevice
0000: |   class BSGamepadDevice
0000: |   |   class BSInputDevice
==============================================================================*/
// 80
class BSWin32GamepadDevice : public BSGamepadDevice
{
public:
	// @override
	virtual	UInt32	Unk_00(void) override;				// 00A6B2E0 { each (unk30 ... unk7C) = 0; Unk_06(); }
	virtual	void	Unk_01(float arg) override;			// 00A6B370 { XInput1_3.XInputGetState, ... }
	virtual	void	Unk_02(void) override;				// 00A6B2D0 { return; }
	virtual	void	Unk_05(void) override;				// 00A6B330 { each (unk30 ... unk7c) = 0; }
	virtual	void	Unk_06(void) override;				// 00A6B5B0
};
