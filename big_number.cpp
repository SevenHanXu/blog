/*************************************************************************
	> File Name: big_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 三 10/10 14:49:50 2018
 ************************************************************************/

#include<stdio.h>

#define MAX_N 100000
#define MAX_K 20

int arr[MAX_N + 5][MAX_K + 5] = {0};

void init(int n){
    for(int k = 1; k <= MAX_K; k++){
        for(int i = 0; i < n; i++){
            int num = 0, ind = i;
            for(int j = k - 1; j >= 0; j--){
                if(ind + (1 << j ) > n) continue;
                do{
                    num = num > arr[ind][j] ? num : arr[ind][j];
                    ind += (1 << j);
                }while(ind + (1 << j) <= n);
            }
            arr[i][k] = num; 
        }
    }
    return ;
}

int find(int a, int b){
   int ind = a, num = 0, len = b - a + 1;
    for(int i = MAX_K; i >= 0; i--){
        if((len & (1 << i)) == 0) continue;
        num = num > arr[ind][i] ? num : arr[ind][i];
        ind += (1 << i);
    }
    return num;
}
int main(){
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i][0]);
    }
    init(n);
    while(scanf("%d%d", &a, &b) != EOF){
        printf("%d\n", find(a, b));
    }
    return 0;
}
