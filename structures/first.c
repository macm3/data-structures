#include <stdio.h>

int isPrime(int n){
    for(int x = 2; x*x <= n; x++){
        if(n%x == 0){
            return 0;
        }
    }
    return 1;
}

int mod(int a, int b){
    if(b<=0)return -1;
    int div = a/b;
    return a - (div*b);
}

int sumDigits(int n){
    int sum = 0;
    while (n>0){
        sum = sum + (n%10);
        n = n/10;
    }
    return sum;
}

int Msqrt(int n){
    return Msqrt_helper(n, 1, n);
}

int Msqrt_helper(int n, int min, int max){
    if(max<min) return -1;

    int guess = (min+max)/2;
    if(guess*guess==n) return guess;
    else if(guess*guess<n) {
        return Msqrt_helper(n, guess+1, max);
    }
    else {
        return Msqrt_helper(n, min, guess-1);
    }
}

int div(int a, int b){
    int count = 0;
    int sum = b;
    while(sum <= a){
        sum += b;
        count++;
    }
    return count;
}

int main (){
    int a, b;
    printf("%d\n", sumDigits(152));
    //scanf("%d\n%d", &a, &b);
    //int result = mod(a,b);
    //printf("%d", result);
    //printf("\n");
}