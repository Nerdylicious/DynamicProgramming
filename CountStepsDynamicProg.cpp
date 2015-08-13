//Purpose: Use a top down recursive approach to count the number of
//ways a person can climb up n steps if they can climb 1, 2 or 3 steps
//at a time. Since the same results are calculated multiple times, use dynamic programming.
#include <iostream>
using namespace std;

//int starts to overflow at N=37 since num_steps > (2^32 - 1) at N=37
//int is 32 bit and can only hold values up to 2^32 - 1
#define N 36

int num_steps(int n, int temp[]){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }
    else if(temp[n] != -1){
        return temp[n];
    }
    else{
        temp[n] = num_steps(n - 1, temp) + num_steps(n - 2, temp) + num_steps(n - 3, temp);
        return temp[n];
    }
}

int main(){
    int i;
    int temp[N + 1];
    for(i = 0; i < N + 1; i ++){
        temp[i] = -1;
    }
    int res = num_steps(N, temp);
    cout << res << endl;
    return 0;
}
