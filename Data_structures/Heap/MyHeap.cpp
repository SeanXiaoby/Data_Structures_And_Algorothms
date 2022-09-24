//
// Created by Sean on 2022/9/18.
//

#include "./MyHeap.h"

MyMaxHeap::MyMaxHeap(std::vector<int> input){
    data = input;
    ConstructMaxHeap();
    printHeap();
}

void MyMaxHeap::push(int val){
    data.push_back(val);
    TrickleUp(data.size()-1);
}


void MyMaxHeap::pop(){
    if(data.empty()){
        printf("MyMaxHeap is empty. Pop failed...\n\n");
        return;
    }

    data[0] = data[data.size()-1];
    data.pop_back();
    TrickleDown(0);
}


int MyMaxHeap::GetMaxVal(){
    if(data.empty()){
        printf("MyMaxHeap is empty. No max val...\n\n");
        return INT_MIN;
    }

    return data[0];
}


void MyMaxHeap::printHeap(){
    std::vector<std::vector<int> > printStruct;

}

int MyMaxHeap::GetLeft(int curr) {
    int Left = curr * 2 + 1;
    return Left<data.size()? Left:-1;
}

int MyMaxHeap::GetRight(int curr) {
    int Right = curr * 2 + 2;
    return Right<data.size()? Right:-1;
}

int MyMaxHeap::GetParent(int curr) {
    int Parent = (curr+1) /2 -1;
    return Parent>=0?Parent:-1;
}

int MyMaxHeap::GetMaxChild(int curr) {
    int Left = GetLeft(curr), Right = GetRight(curr);
    if(Left == -1 && Right == -1){
        return -1;
    }else if(Left != -1 && Right == -1){
        return Left;
    }else{
        return data[Left]>data[Right]? Left:Right;
    }
}

void MyMaxHeap::SwapTwo(int index1, int index2) {
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

void MyMaxHeap::ConstructMaxHeap() {
    ConvertVectorToMaxheap(data);
}

void MyMaxHeap::ConvertVectorToMaxheap(std::vector<int> &input) {
    if(input.size() <= 1)   return;

    for(int i = (data.size()/2-1); i>= 0; --i){
        TrickleDown(i);
    }
}

std::vector<int> MyMaxHeap::GetData() {
    return std::vector<int>();
}

void MyMaxHeap::TrickleUp(int curr) {
    if(curr == 0 || curr == -1)   return;

    if(data[curr] <= data[GetParent(curr)]) {
        return;
    }else{
        SwapTwo(curr, GetParent(curr));
        TrickleUp(GetParent(curr));
    }
}

void MyMaxHeap::TrickleDown(int curr) {
    if(curr == -1 || curr >= data.size())   return;

    int maxChild = GetMaxChild(curr);
    if(-1 == maxChild) return;

    if(data[curr] >= data[maxChild]){
        return;
    }else{
        SwapTwo(curr, maxChild);
        TrickleDown(maxChild);
    }
}

void MyMaxHeap::printData() {
    if(data.empty())    printf("MyMaxHeap data is empty...\n\n");
    printf("Index\t|Val\n-------------------\n");
    for(int i = 0; i < data.size(); i++){
        printf("%d\t|%d\n", i, data[i]);
    }
    printf("---End of data---\n\n");
}

bool MyMaxHeap::isMaxHeap() {
    if(data.size() <=1 )    return true;

    for(int i = 0; i <= (data.size()/2 -1); ++i){
        if(data[i] < data[GetMaxChild(i)]){
            int left = GetLeft(i), right = GetRight(i), Max = GetMaxChild(i);
            printf("Node at index %d does not accor with a Max heap!\n\n", i);
            return false;
        }
    }

    printf("This is a Max heap!\n\n");
    return true;
}

void MyMaxHeap::HeapSort(std::vector<int> &input) {
    std::vector<int> res;
    MyMaxHeap temp(input);
    while(res.size() != input.size()){
        res.push_back(temp.GetMaxVal());
        temp.pop();
    }

    input = res;
}


