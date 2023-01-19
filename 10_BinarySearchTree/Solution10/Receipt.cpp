#include "Receipt.h"

namespace Homework {

	bool operator ==(const Receipt& l, const Receipt& r) {
		return l.receiptNumber == r.receiptNumber && l.amount == r.amount;
	}

}