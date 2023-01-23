#include "Receipt.h"

namespace Homework {

	bool operator ==(const Receipt& l, const Receipt& r) {
		return l.receiptNumber == r.receiptNumber && l.amount == r.amount;
	}
	int comparator(const void* rec1, const void* rec2) {
		size_t rec1Number = ((Receipt*)rec1)->receiptNumber;
		size_t rec2Number = ((Receipt*)rec2)->receiptNumber;
		return (rec1Number - rec2Number);
	}
}