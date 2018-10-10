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

int find(int a, int b, int k){
   int ind = a, num = arr[a][0]; 
    for(int i = k; i >= 0; i--){
        if(ind == b) break;
        if(ind + (1 << i) - 1 > b) continue;
        do{
            num = num > arr[ind][i] ? num : arr[ind][i];
            ind += (1 << i);
        }while(ind + (1 << i) - 1 <= b);
    }
    return num;
}

void init(int n){
    for(int k = 1; k <= MAX_K; k++){
        for(int i = 0; i < n && i + (1 << k) <= n; i++){
            arr[i][k] = find(i, i+ (1 << k) - 1, k - 1); 
        }
    }
    return ;
}


int main(){
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i][0]);
    }
    init(n);
    while(scanf("%d%d", &a, &b) != EOF){
        printf("%d\n", find(a, b, MAX_K));
    }
    return 0;
}
