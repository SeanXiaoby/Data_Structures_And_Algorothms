//
// Created by Sean on 2022/9/18.
//

#include <vector>
#include <algorithm>
#include <string>

struct TreeNode {
    int val;            // Data
    TreeNode* left;     // Left child
    TreeNode* right;    // Right child
    TreeNode* parent;

    TreeNode(): val(-1), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int val,TreeNode* parent = nullptr, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr):
            val(val), left(leftNode), right(rightNode), parent(parent) {}
};


class MyMaxHeap {
public:
    MyMaxHeap() {}
    MyMaxHeap(std::vector<int> input);
    MyMaxHeap(MyMaxHeap &obj) {data = obj.GetData();}
    ~MyMaxHeap() {data.clear();}


public:
    void push(int val);
    void pop();
    int GetMaxVal();
    void printHeap();
    void printData();
    std::vector<int> GetData();
    bool isMaxHeap();

private:
    void TrickleUp(int curr);
    void TrickleDown(int curr);

    int GetLeft(int curr);
    int GetRight(int curr);
    int GetParent(int curr);
    int GetMaxChild(int curr);
    void SwapTwo(int index1, int index2);

    void ConstructMaxHeap();
    void ConvertVectorToMaxheap(std::vector<int> &input);

public:
    static void HeapSort(std::vector<int>& input);

private:
    std::vector<int> data;
};