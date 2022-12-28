#include "TestTask9.h"

using namespace std;

TEST(FindMaximumIncome, FindMaximumIncome)
{
	using rates = vector<size_t>;
	using testRates = vector<pair<rates, size_t>>;
	testRates test(RND.range<size_t>(50, 100));
	generate(test.begin(), test.end(), [] {
		pair<rates, size_t> ret(rates(RND.range<size_t>(0, 24)), RND.range<size_t>(0, 24));
	generate(ret.first.begin(), ret.first.end(), [] {return RND.range<size_t>(0, 24); });
		return ret;
		});
	for_each(test.begin(), test.end(), [](auto it) {
		EXPECT_EQ(TestWorkPlanner::FindMaximumIncome(it.first, it.second), TaskWorkPlanner::FindMaximumIncome(it.first, it.second));
		});
}

TEST(FindMinimumManagers, FindMinimumManagers) {
	constexpr time_t hour = 60 * 60;
	constexpr time_t minMeet = hour / 2;
	constexpr time_t day = hour * 24;
	const time_t start = time(nullptr) / day * day;
	const time_t stop = start + day;
	using rates = vector<pair<time_t, time_t>>;
	/*using testRates = vector<rates>;
	testRates test(RND.range<size_t>(50, 100));
	generate(test.begin(), test.end(), [=] {
		rates ret(RND.range<size_t>(0, 100));
	generate(ret.begin(), ret.end(), [=] {
		auto b = RND.range<time_t>(start, stop - 2 * minMeet);
	return pair<time_t, time_t>{ b, RND.range<time_t>(b + minMeet, stop) };
		});
	return ret;
		});*/

	vector<pair<time_t, time_t>> test = { pair(1,3), pair(3,4), pair(4,5) };
	EXPECT_EQ(TestWorkPlanner::FindMinimumManagers(test), TaskWorkPlanner::FindMinimumManagers(test));

	/*for_each(test.begin(), test.end(), [](auto it) {
		EXPECT_EQ(TestWorkPlanner::FindMinimumManagers(it), TaskWorkPlanner::FindMinimumManagers(it));
		});*/
}

//TEST(LoadTruck, LoadTruck) {
//	using Rate = pair<TestWorkPlanner::TruckCapacity, vector<TestWorkPlanner::GoodsInfo>>;
//	using TestRates = vector<Rate>;
//	TestRates test(RND.range<size_t>(50, 100));
//	generate(test.begin(), test.end(), [] {
//		vector<TestWorkPlanner::GoodsInfo> goods(RND.range<size_t>(0, 50));
//	generate(goods.begin(), goods.end(), [] {
//		return TestWorkPlanner::GoodsInfo{ RND.range<TestWorkPlanner::GoodsCount>(1,1000), RND.range<TestWorkPlanner::GoodsPrice>(1,1000) };
//		});
//	return  Rate{ RND.range<TestWorkPlanner::TruckCapacity>(0,1000), goods };
//		});
//	for_each(test.begin(), test.end(), [](auto it) {
//		EXPECT_EQ(TaskWorkPlanner::LoadTruck(it.first, it.second), TestWorkPlanner::LoadTruck(it.first, it.second));
//		});
//}

//TEST(HuffmanCode, HuffmanCode) {
//	vector<string> testRates{ "","a","aaa","Skillbox","abcdefg" };
//	for_each(testRates.begin(), testRates.end(), [](auto it) {
//		EXPECT_EQ(TestHuffmanCode::EncodeHuffman(it), TaskHuffmanCode::EncodeHuffman(it));
//		});
//}