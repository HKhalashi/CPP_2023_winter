#include <iostream>
#include <string>
#include <cmath>


int* plusOne(int[] ,int);

int main() {
    int a[] = {1 , 4 , 9};
    int size = sizeof(a) / sizeof(int);
    int* b = plusOne(a , size);
    std::cout << "\n";
    return 0;
}

int* plusOne(int a[] , int size){
    std::string str ;
    for(int i =0; i < size ; i++){
        str = str + std::to_string(a[i]);
    }
    int temp = std::stoi(str);
    temp++;
    std::string str_1 = std::to_string(temp);
    int new_size = floor(log10(temp)) + 1 ;
    int a_1[new_size];
    for(int i = 0 ; i < new_size ; i++ ){
        char curr_char = str_1[i];
        a_1[i] = int(curr_char) - 48;
    }
    for(int i = 0 ; i < new_size ; i++ ){

        std::cout << a_1[i] << ",";
    }
    return a_1;
}
