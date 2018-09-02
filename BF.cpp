/*************************************************************************
	> File Name: BF.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  9/ 2 12:51:34 2018
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST(func){\
    printf("%s == %d\n", #func, func);\
}

int BF(const char *text, const char *pattern){
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    for(int i = 0; i < len1 - len2 + 1; i++){
        int flag = 1;
        for(int j = 0; j < len2 && flag; j++){
            if(pattern[j] == text[i + j]) continue;
            flag = 0;
        }
        if(flag) return 1;
    }
    return 0;
}

int main(){
    TEST(BF("hello world", "hello"));
    TEST(BF("hello world", "wr"));
    return 0;
}

