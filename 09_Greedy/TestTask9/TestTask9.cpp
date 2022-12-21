#include "TestTask9.h"

using namespace std;

namespace bm = HomeworkCheck::WorkPlanner;
namespace hw = Homework::WorkPlanner;

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
		EXPECT_EQ(hw::FindMaximumIncome(it.first, it.second), bm::FindMaximumIncome(it.first, it.second));
		});
}

TEST(FindMinimumManagers, FindMinimumManagers) {
	constexpr time_t hour = 60 * 60;
	constexpr time_t minMeet = hour / 2;
	constexpr time_t day = hour * 24;
	const time_t start = time(nullptr) / day * day;
	const time_t stop = start + day;
	using rates = vector<pair<time_t, time_t>>;
	using testRates = vector<rates>;
	testRates test(RND.range<size_t>(50, 100));
	generate(test.begin(), test.end(), [=] {
		rates ret(RND.range<size_t>(0, 100));
	generate(ret.begin(), ret.end(), [=] {
		auto b = RND.range<time_t>(start, stop - 2 * minMeet);
	return pair<time_t, time_t>{ b, RND.range<time_t>(b + minMeet, stop) };
		});
	return ret;
		});
	for_each(test.begin(), test.end(), [](auto it) {
		EXPECT_EQ(hw::FindMinimumManagers(it), bm::FindMinimumManagers(it));
		});
}

TEST(LoadTruck, LoadTruck) {
	using Rate = pair<bm::TruckCapacity, vector<bm::GoodsInfo>>;
	using TestRates = vector<Rate>;
	TestRates test(RND.range<size_t>(50, 100));
	generate(test.begin(), test.end(), [] {
		vector<bm::GoodsInfo> goods(RND.range<size_t>(0, 50));
	generate(goods.begin(), goods.end(), [] {
		return bm::GoodsInfo{ RND.range<bm::GoodsCount>(1,1000), RND.range<bm::GoodsPrice>(1,1000) };
		});
	return  Rate{ RND.range<bm::TruckCapacity>(0,1000), goods };
		});
	for_each(test.begin(), test.end(), [](auto it) {
		EXPECT_EQ(hw::LoadTruck(it.first, it.second), bm::LoadTruck(it.first, it.second));
		});
}

TEST(HuffmanCode, HuffmanCode) {
	namespace hwhc = Homework::HuffmanCode;
	namespace bmhc = HomeworkCheck::HuffmanCode;
	vector<string> testRates{ "","a","aaa","Skillbox","abcdefg" };
	for_each(testRates.begin(), testRates.end(), [](auto it) {
		EXPECT_EQ(bmhc::EncodeHuffman(it), hwhc::EncodeHuffman(it));
		});
}
