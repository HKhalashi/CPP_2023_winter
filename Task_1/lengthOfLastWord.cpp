#include <iostream>
#include <string>
int lengthOfLastWord(std::string);
void reverseStr(std::string&);

int main() {
    std::string str = "   book apple null   ";
    std::cout << lengthOfLastWord(str);
    return 0;
}

void reverseStr(std::string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
}
int lengthOfLastWord(std::string str){
    int i = 0;
    int len =0;
    reverseStr(str);
    while(true){
        if(!isspace(str[i])){
           len++;
        }
        else if( isspace(str[i]) and len > 0){
            return len ;
        }
        i++;
    }
}
