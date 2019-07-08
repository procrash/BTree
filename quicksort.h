#pragma once

#include <vector>
#include <iostream>

class Quicksort
{
public:
    Quicksort();

    template<typename T>
    static void sort(std::vector<T>& values) {
        sort(values, 0, values.size()-1);
    }

private:
    template<typename T>
    static void sort(std::vector<T>& values, std::size_t leftIdx, std::size_t rightIdx) {
        if (leftIdx>=rightIdx) return;

        int i=leftIdx;
        int k=rightIdx-1;
        T pivot = values[rightIdx];

        do {
            while (values[i]<=pivot && i<rightIdx) { i++; }
            while (values[k]>=pivot && k>leftIdx) { k--;}

            if (i<k) {
                T tmp = values[i];
                values[i] = values[k];
                values[k] = tmp;
            }

        } while (i<k);

        if (values[i]>pivot) {
            T tmp=values[i];
            values[i] = pivot;
            values[rightIdx] = tmp;
        }

        if (i>0) {
            sort(values, leftIdx, i-1);
        }

        sort(values, i+1, rightIdx);
    }

};

