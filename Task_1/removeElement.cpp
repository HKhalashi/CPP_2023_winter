#include <iostream>


int removeElement(int[] , int);

int main() {
    int b[] = {1 , 2 , 2 , 3 , 3};
    removeElement(b , 3);
    return 0;
}

int removeElement(int a[] , int val){
    int n = sizeof(a);
    int m = sizeof(int);
    int j = 0;
    for(int i = 0 ; i < (n/m) ; i++){

        if(a[i] != val){
            a[j] = a[i];
            j++;
        }
    }
    for(int i = 0 ; i <= j ; i++){
        std::cout << a[i] << "," ;
    }
    std::cout <<"\n" <<  (n/m)-j << "\n";
}
