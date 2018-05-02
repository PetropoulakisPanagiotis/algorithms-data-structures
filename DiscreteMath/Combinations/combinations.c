#include <stdio.h>
#include "combinations.h"

// C(n,r) = n!/r!(n - r)! //

int comb(int n, int r){
    int c = 0;
    int i = 0;
    int r_r = 1;
    int tmp = 1;
    
    // Check for errors. //
    if(n < 0 || ((r < 0) && (r <= n))){
        
        return -1;
    }

    if ((n == r) || (r == 0)){

        return 1;
    }
    else if(r == 1){

        return n;
    }
    else if((r > n) && (r < 0)){

        return 0;
    }
    else{
        
        for(i = r; i > 1; i--){ // r_r = r ^ r.
        
            r_r = r_r * i;
        }
        
        for(i = n; i > n - r; i--){ // tmp = n!/(n-r)! = n * (n - 1) * ... * (n - r + 1)
    
            tmp *= i; 
        }
 
        return tmp / r_r;
    }
}
