#include <iostream>


int searchInsert(int[] , int);
int main() {

    int a[] = {1 , 3 , 4 , 5};
    std:: cout << searchInsert(a , 2);
    return 0;
}

int searchInsert(int a[] , int target){
    int n = sizeof(a);
    int m = sizeof(int);
    int size = n/m;

    for(int i = 0 ; i < size ; i++){

        if(a[i] == target) return i;
    }
    int j = 0;
    for(int i = 0 ; i < size ; i++){

        if(target < a[i]) {
            j++;
        }
        else return ++j;
    }
}
