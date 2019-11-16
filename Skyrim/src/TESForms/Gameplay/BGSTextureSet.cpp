#include "Skyrim/TESForms/Gameplay/BGSTextureSet.h"
#include "Skyrim.h"
#include "Skyrim/Memory.h"

BSShaderTextureSet* BSShaderTextureSet::Create()
{
	BSShaderTextureSet* textureSet = (BSShaderTextureSet*)FormHeap_Allocate(sizeof(BSShaderTextureSet));
	textureSet->ctor();
	return textureSet;
}
