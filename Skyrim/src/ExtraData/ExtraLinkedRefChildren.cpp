#include "Skyrim/ExtraData/ExtraLinkedRefChildren.h"
#include "Skyrim.h"

static const UInt32 s_ExtraLinkedRefChildrenVtbl = 0x01079B08;

ExtraLinkedRefChildren* ExtraLinkedRefChildren::Create()
{
	ExtraLinkedRefChildren* xLinkedRefChildren = (ExtraLinkedRefChildren*)BSExtraData::Create(sizeof(ExtraLinkedRefChildren), s_ExtraLinkedRefChildrenVtbl);
	return xLinkedRefChildren;
}
