#include "Skyrim/NetImmerse/NiExtraData.h"
#include "Skyrim.h"

const BSFixedString& NiExtraData::GetName() const
{
	return m_pcName;
}

void NiExtraData::SetName(const BSFixedString& name)
{
	m_pcName = name;
}
