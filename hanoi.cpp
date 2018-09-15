/*************************************************************************
	> File Name: hanoi.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  9/15 10:29:49 2018
 ************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void output(char a, char b){
    cout << a << "-->" << b << endl;
}

void hanoi(char a, char b, char c, int n){
    if(n == 1){
        output(a, c);
    }else{
        hanoi(a, c, b, n - 1);
        output(a, c);
        hanoi(b, a, c, n - 1);
    }
    return ;
}

int main(){
    int n;
    cin >> n;
    hanoi('A', 'B', 'C', n);
    return 0;
}
