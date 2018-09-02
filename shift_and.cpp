/*************************************************************************
	> File Name: shift_and.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  9/ 2 12:57:33 2018
 ************************************************************************/
#include <stdio.h>

#define TEST(func){\
    printf("%s == %d\n", #func, func);\
}

int shift_and(const char *text, const char *pattern){
    int n = 0;
    int d[127] = {0};
    for(; pattern[n]; n++){
        d[pattern[n]] |= (1 << n);
    }
    int p = 0;
    for(int i = 0; text[i]; i++){
        p = (p << 1 | 1) & d[text[i]];
        if(p & (1 << (n - 1))) return 1;
    }
    return 0;
}

int main(){
    TEST(shift_and("hello world", "hello"));
    TEST(shift_and("hello world", "wr"));
    return 0;
}

