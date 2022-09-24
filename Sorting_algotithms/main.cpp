#include <iostream>
#include <vector>
#include "MySorting.h"

int main() {
    std::vector<float> input;
    for(int i = 10000; i>=0; --i)
    {
        input.push_back(i);
    }
    MySorting::Sort(input);
//    for(auto iter = input.begin(); iter!=input.end(); iter++){
//        std::cout<<*iter<<std::endl;
//    }

    std::cout<<std::is_sorted(input.begin(), input.end())<<std::endl;
    return 0;
}
