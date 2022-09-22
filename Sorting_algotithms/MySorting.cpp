//
// Created by Boyang Xiao on 9/21/22.
//

#include "MySorting.h"

int MySorting::Sort(std::vector<float> &input, SortType type) {
    switch(type){
        case SortType::Merge :
            return MergeSort(input);

        case SortType::Bubble :
            return BubbleSort(input);

        case SortType::Select :
            return SelectSort(input);

        case SortType::Quick :
            return QuickSort(input);

        case SortType::Counting :
            printf("Data type not supported! Please use another type...\n");
            return -1;
    }
    return 0;
}

int MySorting::Sort(std::vector<int> &input, SortType type) {
    switch(type){
        case SortType::Merge :
            printf("Data type not supported! Please use another type...\n");
            return -1;

        case SortType::Bubble :
            printf("Data type not supported! Please use another type...\n");
            return -1;

        case SortType::Select :
            printf("Data type not supported! Please use another type...\n");
            return -1;

        case SortType::Quick :
            printf("Data type not supported! Please use another type...\n");
            return -1;

        case SortType::Counting :
            return CountingSort(input);
    }
}

int MySorting::MergeSort(std::vector<float> &input){
    if(input.size() <= 1){
        return 0;
    }
    int mid = input.size()/2 - 1;
    std::vector<float>first(input.begin(), input.begin()+mid+1),
                        second(input.begin()+mid+1, input.end());
    MergeSort(first);
    MergeSort(second);
    input = MergeTwo(first, second);
    return 0;
}

std::vector<float> MySorting::MergeTwo(std::vector<float> input_1, std::vector<float> input_2) {
    int i = 0, j = 0;
    std::vector<float> res;
    while(true){
        if(i == input_1.size() && j == input_2.size()){
            break;
        }else if(i < input_1.size() && j == input_2.size()){
            res.push_back(input_1[i]);
            i++;
        }else if(i == input_1.size() && j < input_2.size()){
            res.push_back(input_2[j]);
            j++;
        }else{
            if(input_1[i] < input_2[j]){
                res.push_back(input_1[i]);
                i++;
            }else{
                res.push_back(input_2[j]);
                j++;
            }
        }
    }
    return res;
}

int MySorting::CountingSort(std::vector<int> &input) {
    int max = INT_MIN, min = INT_MAX;
    for(auto iter = input.begin(); iter!= input.end(); iter++){
        if(*iter >= max)    max = *iter;
        if(*iter <= min)    min = *iter;
    }
    std::vector<int> counter (max-min+1, 0);
    for(auto iter = input.begin(); iter!=input.end(); iter++){
        counter[*iter - min]++;
    }
    int i = 0;
    for(int j = 0; j<counter.size(); ){
        if(counter[j] > 0){
            input[i] = j+min;
            i++;
            counter[j]--;
        }else{
            ++j;
        }
    }
    return 0;
}

int MySorting::BubbleSort(std::vector<float> &input) {
    for(int i = 0; i<input.size(); i++){
        for(int j = i; j>=1; j--){
            if(input[j]<=input[j-1]){
                SwapTwo(input[j], input[j-1]);
            }
        }
    }
    return 0;
}

int MySorting::SelectSort(std::vector<float> &input) {
    return 0;
}

int MySorting::QuickSort(std::vector<float> &input) {
    return 0;
}

void MySorting::SwapTwo(float &val1, float &val2) {
    auto temp = val2;
    val2 = val1;
    val1 = temp;
}


