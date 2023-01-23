#pragma once

namespace Homework {

	struct Receipt {
		size_t receiptNumber = 0;
		double amount = 0.0;
	};

	bool operator ==(const Receipt& l, const Receipt& r);

	int comparator(const void* rec1, const void* rec2);

}