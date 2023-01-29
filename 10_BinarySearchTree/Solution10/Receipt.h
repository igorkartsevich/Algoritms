#pragma once

namespace Homework {

	struct Receipt {
		size_t receiptNumber = 0;
		double amount = 0.0;
	};

	bool operator ==(const Receipt& l, const Receipt& r);

	bool operator > (Receipt rec_1, Receipt rec_2);
	bool operator < (Receipt rec_1, Receipt rec_2);

	int comparator(const void* rec1, const void* rec2);

}