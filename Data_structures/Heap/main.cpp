#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include "./MyHeap.h"


void printVector(std::vector<int>(data)) {
    if(data.empty())    printf("MyMaxHeap data is empty...\n\n");
    printf("Index\t|Val\n-------------------\n");
    for(int i = 0; i < data.size(); i++){
        printf("%d\t|%d\n", i, data[i]);
    }
    printf("---End of data---\n\n");
}

bool isTwoVectorSame(std::vector<int> input1, std::vector<int> input2){
    if(input1.size() != input2.size())  return false;

    for(int i = 0; i<input1.size(); ++i){
        if(input1[i]!=input2[i])    return false;
    }
    return true;
}

int main() {
    std::cout << "-------Program Started!--------" << std::endl;

    std::vector<int> input;
    for(int i = 0; i<1000; i++){
        for(int j = 0; j<1000; j++){
            input.push_back(i*1000+j);
        }
    }
    //auto check = input;
    clock_t start = clock();
    MyMaxHeap::HeapSort(input);
    clock_t end = clock();
    std::cout<<"Duration = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<std::endl;  //输出时间（单位：ｓ）
    //std::sort(check.begin(), check.end(), std::greater<int>());

    printf("Is sorted? --- ");
    printf(std::is_sorted(input.begin(),input.end(),std::greater<int>())?"True\n":"False\n");

    //printVector(check);

    return 0;
}
