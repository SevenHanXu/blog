/*************************************************************************
	> File Name: sunday.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  9/ 2 12:55:44 2018
 ************************************************************************/
#include <stdio.h>
#include <string.h>

#define TEST(func){\
    printf("%s == %d\n", #func, func);\
}

int sunday(const char *text, const char *pattern){
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    int ind[127] = {0};
    for(int i = 0; i < 127; i++) ind[i] = len2 + 1;
    for(int i = 0; pattern[i]; i++) ind[pattern[i]] = len2 - i;
    for(int i = 0; i < len1 - len2 + 1;){
        int j = 0;
        for(; j < len2; j++){
            if(pattern[j] != text[i + j]) break;
        }
        if(j == len2) return 1;
        i += ind[text[i + len2]];
    }
    return 0;
}

int main(){
    TEST(sunday("hello world", "hello"));
    TEST(sunday("hello world", "wr"));

return 0;

}

