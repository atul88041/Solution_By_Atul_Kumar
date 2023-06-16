#include <stdio.h>

int find_biggest_if_else(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    int num1, num2, biggest;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    biggest = find_biggest_if_else(num1, num2);
    printf("The biggest number is: %d\n", biggest);

    return 0;
}
