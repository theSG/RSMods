#pragma once

#include "Windows.h"
#include "../Offsets.hpp"
#include "../MemUtil.hpp"
#include <iostream>

namespace TrueTuning
{
	void DisableTrueTuning(float newtuning);
	void EnableTrueTuning();
}