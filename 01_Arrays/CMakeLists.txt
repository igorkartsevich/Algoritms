cmake_minimum_required(VERSION 3.0)
project(01_Arrays)

set (CMAKE_CXX_STANDARD 17)

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
add_executable(SortingTest ..//08_QSort/SortingTest.cpp ..//08_QSort/Sorting.h)

set(TASK9_HEADER
    ..//09_Greedy/Task9/TestTask9.h
    ..//09_Greedy/Task9/HuffmanCode.h
    ..//09_Greedy/Task9/WorkPlanner.h

    ..//09_Greedy/Solution9/HuffmanCode.h
    ..//09_Greedy/Solution9/WorkPlanner.h
)
set(TASK9_SOURCE
    ..//09_Greedy/Task9/TestTask9.cpp
    ..//09_Greedy/Task9/HuffmanCode.cpp
    ..//09_Greedy/Task9/WorkPlanner.cpp

    ..//09_Greedy/Solution9/HuffmanCode.cpp
    ..//09_Greedy/Solution9/WorkPlanner.cpp
)
add_executable(Task9 ${TASK9_HEADER} ${TASK9_SOURCE})

set(LIB_TASK9_HEADER
    ..//09_Greedy/Lib/lib.h
    ..//09_Greedy/Lib/rnd.h
)
set(LIB_TASK9_SOURCE
    ..//09_Greedy/Lib/lib.cpp
    ..//09_Greedy/Lib/rnd.cpp
)
add_library(LibTask9 ${LIB_TASK9_HEADER} ${LIB_TASK9_SOURCE})
target_link_libraries(Task9 LibTask9 gtest_main)


set(TASK10_HEADER
    ..//10_BinarySearchTree/Task10/BST.h

    ..//10_BinarySearchTree/Solution10/BST.h
    ..//10_BinarySearchTree/Solution10/Node.h
    ..//10_BinarySearchTree/Solution10/Receipt.h
)
set(TASK10_SOURCE
    ..//10_BinarySearchTree/Task10/TestTask10.cpp
    ..//10_BinarySearchTree/Task10/BST.cpp

    ..//10_BinarySearchTree/Solution10/BST.cpp
    ..//10_BinarySearchTree/Solution10/Receipt.cpp
)
add_executable(Task10 ${TASK10_HEADER} ${TASK10_SOURCE})

set(LIB_TASK10_HEADER
    ..//10_BinarySearchTree/Lib/lib.h
    ..//10_BinarySearchTree/Lib/rnd.h
)
set(LIB_TASK10_SOURCE
    ..//10_BinarySearchTree/Lib/lib.cpp
    ..//10_BinarySearchTree/Lib/rnd.cpp
)
add_library(LibTask10 ${LIB_TASK10_HEADER} ${LIB_TASK10_SOURCE})
target_link_libraries(Task10 LibTask10 gtest_main)

set(TASK11_HEADER
    ..//11_Tree/TreeSolution.h
    ..//11_Tree/TestNode.h
    ..//11_Tree/Node.h
    ..//11_Tree/Virus.h
)
set(TASK11_SOURCE
    ..//11_Tree/TreeSolution.cpp
    ..//11_Tree/TestNode.cpp
    ..//11_Tree/Node.cpp

    ..//11_Tree/TreeTest.cpp
)
add_executable(Task11 ${TASK11_HEADER} ${TASK11_SOURCE})

add_executable(Task12 ..//12_Heap/Heap.cpp ..//12_Heap/Heap.h ..//12_Heap/HeapTest.cpp)
add_executable(WretchedPriorityQueue ..//12_Heap/WretchedPriorityQueue.h ..//12_Heap/WretchedPriorityQueue.cpp ..//12_Heap/WretchedPriorityQueueTest.cpp)

set(Task13_B_Tree_HEADER
    ..//13_BTree/src/homework/BTree/Node.h
    ..//13_BTree/src/homework/BTree/BTree.h
)
set(Task13_B_Tree_SOURCE
    ..//13_BTree/src/homework/BTree/Node.cpp
    ..//13_BTree/src/homework/BTree/BTree.cpp

    ..//13_BTree/src/homework/BTree/BTreeTest.cpp
)
add_executable(Task13_B_Tree ${Task13_B_Tree_HEADER} ${Task13_B_Tree_SOURCE})

set(Task13_ContactBook_HEADER
    ..//13_BTree/src/homework/ContactBook/Contact.h
    ..//13_BTree/src/homework/ContactBook/ContactBook.h
)
set(Task13_ContactBook_SOURCE
    ..//13_BTree/src/homework/ContactBook/ContactBook.cpp

    ..//13_BTree/src/homework/ContactBook/ContactBookTest.cpp
)
add_executable(Task13_ContactBook ${Task13_ContactBook_HEADER} ${Task13_ContactBook_SOURCE})

set(Task14_Hash_HEADER
    ..//14_Graph/Hash/Array.h
)
set(Task14_Hash_SOURCE
    ..//14_Graph/Hash/Array.cpp

    ..//14_Graph/Hash/ArrayTest.cpp
)
add_executable(Task14_Hash ${Task14_Hash_HEADER} ${Task14_Hash_SOURCE})

set(Task14_Graph_RandomizedAlgorithms_HEADER
    ..//14_Graph/RandomizedAlgorithms/Matrix.h
)
set(Task14_Graph_RandomizedAlgorithms_SOURCE
    ..//14_Graph/RandomizedAlgorithms/Matrix.cpp

    ..//14_Graph/RandomizedAlgorithms/MatrixTest.cpp
)
add_executable(Task14_Graph_RandomizedAlgorithms ${Task14_Graph_RandomizedAlgorithms_HEADER} ${Task14_Graph_RandomizedAlgorithms_SOURCE})

set(Task14_SimpleGraph_HEADER
    ..//14_Graph/SimpleGraph/SimpleGraph.h
)
set(Task14_SimpleGraph_SOURCE
    ..//14_Graph/SimpleGraph/SimpleGraph.cpp

    ..//14_Graph/SimpleGraph/SimpleGraphTest.cpp
)
add_executable(Task14_SimpleGraph ${Task14_SimpleGraph_HEADER} ${Task14_SimpleGraph_SOURCE})
