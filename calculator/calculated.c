//Created by Akbarjon Rashidov, first year student of VSU
//physical faculty, Informatics and computer engineering (ICE)
#include <stdio.h>  //
#include <stdlib.h> //code needs this libraries to work

int main(int argc, char *argv[]) //
{
    setvbuf(stdout, NULL, _IONBF, 0); //
    setvbuf(stderr, NULL, _IONBF, 0); //this lines are necessary for correct work of program

    float a, b, *c, *d, res, g;
    char y, x, z, t;
    int res1, i, j;
    do
    {
        printf("Do you want to use classic or vector calculator? (c/v):\n "); //here we ask user "what calculator he wants to use"
        scanf(" %c", &x);                                                    //answer that move user to one of two variant
        switch (x)
        {
        case 'a': //algebra calculator

            printf("Input first number:\n"); //user inputs first number
            scanf("%f", &a);
            printf("Input operation (-+/*^!):\n"); //user is making his choice
            scanf(" %c", &z);

            if (z == '!') //operation "!" (factorial) needs only one number, so I moved this operation to the top
            {
                if (a < 0) //factorial of a negative number doesn't exist
                {
                    printf("Error \n");
                }
                else if (a == 0)
                {
                    printf("Result: 1 \n"); //factorial of 0 is 1 (0! = 1)
                }
                else if (a - (int)a != 0) //we cannot find the factorial of a real number (переводчик выдал: вещественное число --> real number)
                {
                    printf("You can't use factorial of this number \n");
                }
                else if (a != 0) //
                {
                    res1 = 1;
                    for (int r = 1; r <= a; r++)
                    {
                        res1 *= r;
                    }
                    printf("Result: %i \n", res1);
                }
            }
            else
            {
                printf("Input second number: \n"); 	//if operation was not a factorial, user input second number
                scanf("%f", &b);
                switch (z) 							//there goes usual operations
                {
                case '+':
                    printf("Result %f: \n", a + b);
                    break;
                case '-':
                    printf("Result %f: \n", a - b);
                    break;
                case '/':
                    printf("Result %f: \n", a / b);
                    break;
                case '*':
                    printf("Result %f: \n", a * b);
                    break;
                case '^':
                    g = 1;
                    if (b < 0)
                    {
                        for (int i = 0; i > b; i--)
                        {
                            g = g * a;
                        }
                        res = 1 / g;
                    }
                    else if (b == 0)
                    {
                        res = 1;
                    }
                    else if (b - (int)b != 0)
                    {
                        printf("Error \n");
                    }
                    else
                    {
                        for (int i = 1; i <= b; i++)
                        {
                            g = g * a;
                        }
                        res = g;
                    }
                    printf("Result: %f \n", res);
                    break;
                default:
                    printf("Error \n");
                }
            }
            break;

        case 'v': //vector calculator
        {
        	printf("Input size of vectors: \n");
        	scanf("%i", &i);
        	c=malloc(i * sizeof(float));	//allocating the required amount of memory for vector№1
            d=malloc(i * sizeof(float));	//allocating the required amount of memory for vector№2
            printf("Input first vector: \n ");	//считывание первого вектора
            for (j = 0; j < i; j++)
            {
            	scanf("%f", &c[j]);
            }
            printf("Input operation (-+*): \n");
            scanf(" %c", &t);
            printf("Input second vector: \n ");
            for (j = 0; j < i; j++)		//считывание второго вектора
            {
            	scanf("%f", &d[j]);
            }
            switch (t)
            {
            case '-':
            	printf("Result: \n");
            	for (j = 0; j < i; j++)			//цикл вывода разности соответствующих координат вектора
            	{
            		printf("%f ", c[j]-d[j]);
            	}
            	break;
            case '+':
            	printf("Result: \n");			//цикл вывода разности соответствующих координат вектора
            	for (j = 0; j < i; j++)
            	{
            		printf("%f ", c[j]+d[j]);
            	}
            	break;
            case '*':							//цикл вывода скалярного произведения
            	printf("Result: \n");
            	for (j = 0; j < i; j++)
            	{
            		printf("%f ", c[j]*d[j]);
            	}
           		break;
           	default:
            	printf("WRONG OPERATION");		//стоило бы сделать так, чтобы это выводилось сразу после вывода операции, которой нет в перечисленном списке
            }
        free(c);
        free(d);
        }
        }
        printf("Do you want to continue? (y/n) \n");
        scanf(" %c", &y);
    } while (y == 'y');
    return 0;
}
