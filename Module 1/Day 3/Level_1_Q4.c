#include <stdio.h>

int findLargestNumber(int num) {
    int maxNum = 0;
    int divisor = 1;

    while (divisor <= num) {
        int newNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (newNum > maxNum) {
            maxNum = newNum;
        }
        divisor *= 10;
    }

    return maxNum;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    if (num < 1000 || num > 9999) {
        printf("Invalid input. Please enter a valid 4-digit number.\n");
        return 0;
    }

    int largestNum = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largestNum);
    return 0;
}

