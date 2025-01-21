#include <stdio.h>

// Function to calculate the sum of even numbers up to n
int sumEven(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumEven(n - 2);
}

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the series 1/1! + 2/2! + 3/3! + ... + n/n!
double sumSeries(int n) {
    if (n == 0) {
        return 0;
    }
    return (double)n / factorial(n) + sumSeries(n - 1);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Ensure n is even for the sum of even numbers
    if (n % 2 != 0) {
        n--;
    }

    int sum_even = sumEven(n);
    double sum_series = sumSeries(n);

    printf("Sum of even numbers up to %d: %d\n", n, sum_even);
    printf("Sum of series 1/1! + 2/2! + ... + %d/%d!: %lf\n", n, n, sum_series);

    return 0;
}

