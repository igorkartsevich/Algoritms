#include "pch.h"
#include "rnd.h"

namespace Lib {

	rnd::rnd() :gen(rd()) {};

	rnd& rnd::ptr() {
		static rnd instance;
		return instance;
	}

}