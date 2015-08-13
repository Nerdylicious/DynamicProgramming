//Purpose: Use a top down recursive approach to count the number of
//ways a person can climb up n steps if they can climb 1, 2 or 3 steps at a time
//Time complexity: O(3^n)
//Space complexity: O(3^n)
#include <iostream>
using namespace std;

int num_steps(int n){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }
    else{
        return num_steps(n - 1) + num_steps(n - 2) + num_steps(n - 3);
    }
}

int main(){
    int n = 4;
    int res = num_steps(n);
    cout << res << endl;
    return 0;
}
