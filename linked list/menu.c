#include <stdio.h>
#include <stdlib.h>

void add() {
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);
    printf("The sum of your numbers is : %d\n", a + b);
}

void mul() {
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);
    printf("The multiplication of your numbers is : %d\n", a * b);
}

void sub() {
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);
    printf("The subtraction of your numbers is : %d\n", a - b);
}

void divide() {
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);
    if (b != 0) {
        printf("The division of your numbers is: %d\n", a / b);
    } else {
        printf("Cannot divide by zero.\n");
    }
}

int main() {
    int ch;
    printf("Menu\n");
    printf("1. Add\n2. Subtract\n3. Multiplication\n4. Division\n5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                add();
                break;
            case 2:
                sub();
                break;
            case 3:
                mul();
                break;
            case 4:
                divide();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice, try again\n");
        }

    } while (ch != 5);

    return 0;
}
