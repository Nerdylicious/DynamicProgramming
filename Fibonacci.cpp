//Purpose: Compute the nth fibonacci number
//Time complexity: O(2^n)
//Starts to slow down considerably around n=40
#include <iostream>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n = 40;
    int res = fib(n);
    cout << res << endl; 
    return 0;
}
