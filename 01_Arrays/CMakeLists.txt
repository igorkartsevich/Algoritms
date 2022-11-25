cmake_minimum_required(VERSION 3.0)
project(01_Arrays)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(ArrayTests src/homework/ArrayMax/array_max_tests.cc src/homework/ArrayMax/array_max.cc src/homework/ArrayTop/TopX.cpp src/homework/ArrayTop/TopX.h src/homework/ArrayTop/TopXTests.cpp src/homework/UniqueNumbers/ArrayUnique.cpp src/homework/UniqueNumbers/ArrayUnique.h src/homework/UniqueNumbers/ArrayUniqueTests.cpp src/homework/UniqueSorted/ArraySorted.cpp src/homework/UniqueSorted/ArraySorted.h src/homework/UniqueSorted/ArraySortedTests.cpp)
target_link_libraries(ArrayTests gtest_main)

include(GoogleTest)
gtest_discover_tests(ArrayTests)

add_executable(ListTest ..//04_Standard_Structures/List/main.cpp ..//04_Standard_Structures/List/list.cpp ..//04_Standard_Structures/List/list.h)
add_executable(StackTest ..//04_Standard_Structures/Stack/main.cpp ..//04_Standard_Structures/Stack/Stack.cpp ..//04_Standard_Structures/Stack/Stack.h)
add_executable(DLListTest ..//05_Standard_Structures2/main.cpp ..//05_Standard_Structures2/DLList.cpp ..//05_Standard_Structures2/DLList.h)
add_executable(BookComparatorTest ..//06_Sorting/test/homework/BookComparatorTest.cpp ..//06_Sorting/homework/Comparator/BookComparator.h ..//06_Sorting/homework/Comparator/BookComparator.cpp ..//06_Sorting/homework/Comparator/Book.h ..//06_Sorting/homework/Comparator/Book.cpp)

set ( SORT_HEADER
    ..//06_Sorting/homework/SortAlgorithms/Animal.h
    ..//06_Sorting/homework/SortAlgorithms/SuperArray.h
    ..//06_Sorting/homework/SortAlgorithms/SortAlgorithms.h
)
set ( SORT_SOURCE
    ..//06_Sorting/homework/SortAlgorithms/SortAlgorithms.cpp
    ..//06_Sorting/test/homework/SortTest.cpp
)
add_executable(SortTest ${SORT_HEADER} ${SORT_SOURCE})

add_executable(BrutalForseRecursionTest ..//07_Recursion/homework/BacktrackingResursion/BruteForceRecursionTest.cpp ..//07_Recursion/homework/BacktrackingResursion/BruteForceRecursion.cpp ..//07_Recursion/homework/BacktrackingResursion/BruteForceRecursion.h)
add_executable(MergeSortRecursionTest ..//07_Recursion/homework/MergeSortRecursion/MergeSortRecursionTest.cpp ..//07_Recursion/homework/MergeSortRecursion/MergeSortRecursion.cpp ..//07_Recursion/homework/MergeSortRecursion/MergeSortRecursion.h)
add_executable(SimpleRecursionTest ..//07_Recursion/homework/SimpleRecursion/SimpleRecursionTest.cpp ..//07_Recursion/homework/SimpleRecursion/SimpleRecursion.cpp ..//07_Recursion/homework/SimpleRecursion/SimpleRecursion.h)
  