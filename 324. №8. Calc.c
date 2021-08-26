/* Миникалькулятор. см. стр. 324 №8*/
#include <stdio.h>

#define STOP 'q'
#define ADD 'a'
#define SUB 'b'
#define MUL 'c'
#define DIV 'd'

char get_first(void);
char get_choice(void);
float get_arg(void);
int main() {
    char choice;
    float first_arg, second_arg;
    while ((choice = get_choice()) != STOP)
    {
        printf("Enter first argument\n");
        first_arg = get_arg();
        printf("Enter second argument\n");
        second_arg = get_arg();
        switch (choice) 
        {
            case ADD:
            {
                printf("ADD: %.2f + %.2f = %.2f\n", first_arg, second_arg, first_arg+second_arg);
                break;
            }
            case SUB:
            {
                printf("SUB: %.2f - %.2f = %.2f\n", first_arg, second_arg, first_arg-second_arg);
                break;
            }
            case MUL:
            {
                printf("MUL: %.2f * %.2f = %.2f\n", first_arg, second_arg, first_arg*second_arg);
                break;
            }
            case DIV:
            {
                if(second_arg == 0)
                {
                    printf("You can't divide by zero!\n");
                    break;
                }
                printf("DIV: %.2f : %.2f = %.2f\n", first_arg, second_arg, first_arg/second_arg);
                break;
            }

        }
    }
    printf("Shutdown program\n");
    return 0;
}

char get_first()
{
    int ch;
    while ((ch = getchar()) == '\n')
        printf("Enter command!\n");
    while (getchar() != '\n')
        continue;
    return ch;
}
char get_choice()
{
    int ch;
    printf("Enter yor choice where\n");
    printf("%c. add     %c. sub\n", ADD, SUB);
    printf("%c. mul     %c. div\n", MUL, DIV);
    printf("%c. shutdown program\n", STOP);
    ch = get_first();
    while (ch != ADD && ch != SUB && ch != MUL && ch != DIV && ch != STOP)
    {
        printf("Please, enter %c, %c, %c, %c or %c!\n", ADD, SUB, MUL, DIV, STOP);
        ch = get_first();
    }
    return ch;
}

float get_arg()
{
    float arg;
    while(scanf("%f", &arg) != 1)
    {
        while (getchar() != '\n')
            continue;
        printf("Incorrect input!\n");
        printf("Example: 12.4\n");
    }
}
