/*************************************************************************
	> File Name: KMP.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  9/ 2 12:53:33 2018
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST(func){\
    printf("%s == %d\n", #func, func);\
}

int KMP(const char *text, const char *pattern){
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    for(int i = 1; i < len2; i++){
        int j = next[i - 1]; 
        while(j != -1 && next[i] != next[j + 1]) j = next[j];
        if(next[i] == next[j + 1]) j += 1;
        else next[i] = j;

}
   int j = -1;
    for(int i = 0; text[i]; i++){
        while(j != -1 && pattern[j + 1] != text[i]) j = next[j];
        if(pattern[j + 1] == text[i]) j += 1;
        if(pattern[j + 1] == 0) return 1;
    }
    return 0;
}

int main(){
    TEST(KMP("hello world", "hello"));
    TEST(KMP("hello world", "wr"));
    return 0;
}

