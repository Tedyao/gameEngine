#include "hzpch.h"
#include "Input.h"
#include "Hazel/Core.h"

namespace Hazel {
	Input* Input::s_Instance = nullptr;

	Input::Input() {
		HZ_CORE_ASSERT(!s_Instance, "Input has already been initialized!");
		s_Instance = this;
	}
}