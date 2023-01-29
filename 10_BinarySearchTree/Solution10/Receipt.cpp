#include "Receipt.h"

namespace Homework {

	bool operator ==(const Receipt& l, const Receipt& r) {
		return l.receiptNumber == r.receiptNumber && l.amount == r.amount;
	}
	bool operator > (Receipt rec_1, Receipt rec_2) {
		return rec_1.receiptNumber > rec_2.receiptNumber;
	}
	bool operator < (Receipt rec_1, Receipt rec_2) {
		return rec_1.receiptNumber < rec_2.receiptNumber;
	}
	int comparator(const void* rec_1, const void* rec_2) {
		return (*((Receipt*)rec_1) < *((Receipt*)rec_2)) ? -1 : (*((Receipt*)rec_1) > *((Receipt*)rec_2)) ? 1 : 0;
	}
}