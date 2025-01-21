//// Part b . Write a recursive function to obtain the running sum of first 25 natural numbers.
#include <stdio.h>

int runningSum(int n) {
    if (n == 1) {
        return 1;
    
    }
    else if (n==0){
        return 0;
    } else {
        return n + runningSum(n - 1);
    }
}

int main() {
    int sum = runningSum(25);
    printf("The running sum of the first 25 natural numbers is: %d\n", sum);
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int sum2 = runningSum(n);
    printf("The running sum of the first %d natural numbers is: %d\n", n, sum2);
    return 0;
}
