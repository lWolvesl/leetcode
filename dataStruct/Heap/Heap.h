//
// Created by 李洋 on 2023/8/12.
//

#ifndef LEECODE_C_HEAP_H
#define LEECODE_C_HEAP_H

#include "vector"
template<typename T>
class Heap {
private:
    std::vector<T> array;
public:
    int length;

    Heap(std::vector<T> &array) : array(array){
        length = array.size();
    }

    typedef void (Heap::*compare(T a,T b))(bool);
};

#endif //LEECODE_C_HEAP_H
