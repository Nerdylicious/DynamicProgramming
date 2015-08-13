//Purpose: Compute the nth fibonacci number using dynamic programming (caching intermediate results)
//Time complexity: O(n)
//Space complexity: O(n), the amount of stack space
//Since fib now runs in linear time, we can calculate very large fibonnaci numbers under reasonable time
//We can get to a point where the int starts to overflow
#include <iostream>
using namespace std;

#define MAX 1000

int fib(int n, int temp[]){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(temp[n] != -1){
        return temp[n];
    }
    temp[n] = fib(n - 1, temp) + fib(n - 2, temp);
    return temp[n];
}

int main(){
    int i;
    int temp[MAX];
    for(i = 0; i < MAX; i ++){
        temp[i] = -1;
    }
    int n = 80;
    int res = fib(n, temp);
    cout << res << endl;
    return 0;
}
