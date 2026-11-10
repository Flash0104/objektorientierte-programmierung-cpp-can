#include "Arrays.h"


double average(double list [], int length){
    double sum = 0;
    for(int i = 0; i<length;i++){
        sum += list[i];
    }
    return sum /= length;
}

bool compare(double a, double b){
    if(a<b){
        return (b-a) < 0.00001;
    } else{
        return (a-b) < 0.00001;
    }

}

int contains(double list [], int length, double target){
    for(int i = 0; i < length; i++){
        if(compare(list[i], target)){
            return i;
        }
    }
    return -1;
}

int contains_binary_search(double list[], int length, double target){
    int low = 0;
    int high = length;
    while(low<high){
        int mid = low + (high-low) / 2;
        if(compare(list[mid], target)){
            return mid;
        }
        if(list[mid]<target){
            low = mid + 1;
        }
        if(list[mid]>target){
            high = mid - 1;
        }
    }
    return -1;
}