//
// Created by Boyang Xiao on 9/21/22.
//

#ifndef SORTING_ALGOTITHMS_MYSORTING_H
#define SORTING_ALGOTITHMS_MYSORTING_H

#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

enum SortType {Merge, Bubble, Select, Quick, Counting};

class MySorting{

//Driver func: Sorting selection
public:
    static int Sort(std::vector<float> &input, SortType type = SortType::Merge);
    static int Sort(std::vector<int> &input, SortType type = SortType::Counting);

// Non-linear complexity sorting algorithms
public:
    static int MergeSort(std::vector<float> &input);
    static int BubbleSort(std::vector<float> &input);
    static int SelectSort(std::vector<float> &input);
    static int QuickSort(std::vector<float> &input);

// Linear complexity sorting algorithms
public:
    static int CountingSort(std::vector<int> &input);

// Utility functions to support the sorting algorithms above
private:
    static std::vector<float> MergeTwo(std::vector<float> input_1, std::vector<float> input_2);
    static void SwapTwo(float &val1, float &val2);
};

#endif //SORTING_ALGOTITHMS_MYSORTING_H

