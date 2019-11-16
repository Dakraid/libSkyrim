#include "Skyrim/FormComponents/TintMask.h"
#include "Skyrim.h"

#define MAKE_COLOR(a, r, g, b) (((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0))

UInt32 TintMask::ToARGB()
{
	return MAKE_COLOR((UInt32)(alpha * 255), color.red, color.green, color.blue);
}
