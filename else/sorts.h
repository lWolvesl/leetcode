//
// Created by 李洋 on 2023/10/19.
//

#ifndef LEECODE_C_SHELLSORT_H
#define LEECODE_C_SHELLSORT_H

#include <vector>
#include <random>
#include <iostream>

using namespace std;

void shellSort(vector<int> &arr) {
    int n = arr.size();

    // 选择增量序列，可以根据需要选择不同的序列
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 使用插入排序对每个子数组进行排序
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// 快速排序 - start
int partition(vector<int> &arr,int left,int right){
    int sign = arr[left];
    while(left < right){
        while(left < right && sign <= arr[right]){
            right--;
        }
        swap(arr[left],arr[right]);
        while(left < right && arr[left] <= sign){
            left++;
        }
        swap(arr[left],arr[right]);
    }
    return left;
}

void splits(vector<int> &arr,int left,int right){
    if (left < right)
    {
        int norm = partition(arr,left,right);
        splits(arr,left,norm - 1);
        splits(arr,norm + 1,right);
    }
}

void quickSort(vector<int> &arr) {
    splits(arr, 0, arr.size() - 1);
}
// 快速排序 - end

// 堆排序 - start small -> large
void maxHeapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    auto n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
// 堆排序 - end small -> large

// 归并排序
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}


void runS() {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<int> dis(1, 100);
    vector<int> nums;
    nums.reserve(10);
//    for (int i = 0; i < 10; ++i) {
//        nums.push_back(dis(gen));
//    }
    nums.push_back(11);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(23);
    nums.push_back(6);
    nums.push_back(11);
    nums.push_back(26);
    nums.push_back(40);
    nums.push_back(8);
    nums.push_back(95);
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
    shellSort(nums);
    for (int i: nums) {
        cout << i << " ";
    }
}

#endif //LEECODE_C_SHELLSORT_H
