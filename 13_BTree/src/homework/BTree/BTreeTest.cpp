#include "BTree.h"
#include <algorithm>
#include <cassert> //#include <assert.h>
#include <random>

void test() {
      BTree t;
      std::vector<int> a;
      for (int i = 0; i < 1000000; ++i) {
          a.push_back(i * 2);
      }
      std::shuffle(a.begin(), a.end(), std::random_device()); // std::random_shuffle(a.begin(), a.end()); (c++17 deleted)

      for (int i = 0; i < 1000000; ++i) {
          t.add(a[i]); // t.add(i);
      }

      assert(!t.contains(-10));
      assert(!t.contains(1));
      assert(!t.contains(12381));
      assert(!t.contains(99115));
      assert(t.contains(0));
      assert(t.contains(4));
      assert(t.contains(1230));
      assert(t.contains(87612));
      assert(t.contains(1230000));

      std::vector<int> ar = t.getSorted();

      for (int i = 0; i < 1000000; ++i) {
          assert(ar[i] == i * 2);
      }

      /*assert(t.getMaxHeight() < 1000);*/
}


int main(){
  test();
  return 0;
}