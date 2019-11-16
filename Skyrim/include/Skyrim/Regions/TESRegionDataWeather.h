#pragma once

#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"
#include "TESRegionData.h"

class TESWeather;
class TESGlobal;

// 10
class TESRegionDataWeather : public TESRegionData
{
	public:
	virtual ~TESRegionDataWeather();

	struct WeatherData
	{
		TESWeather* weather;	  // 00
		UInt32		chance;		  // 04
		TESGlobal*	globalChance; // 08
	};

	BSSimpleList<WeatherData*> weatherData; // 08
};
