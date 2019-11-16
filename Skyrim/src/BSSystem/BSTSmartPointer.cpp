#include "Skyrim/BSSystem/BSTSmartPointer.h"
#include "Skyrim.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

SInt32 BSIntrusiveRefCounted::IncRefCount(void)
{
	return InterlockedIncrement(&m_refCount);
}

SInt32 BSIntrusiveRefCounted::DecRefCount(void)
{
	return InterlockedDecrement(&m_refCount);
}
