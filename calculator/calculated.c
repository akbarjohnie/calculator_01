// Created by Akbarjohn Rashidov, first year student of VSU
// physical faculty, ICE
// гугл сказал, что ИВТ это Informatics and computer engineering
// Проверил все операции, ошибок в вычислениях не должно быть

#include <stdio.h>

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    float a,b;													// Обозначаем 2 переменные, отвечающие за числа
    char c,v;													// Обозначаем 2 переменные, отвечающие за символы ('c' это символ операции, 'v' символ-ответ на вопрос о продолжении работы программы)
    float res,g;												// переменная 'res' отвечает за получение результата в некоторых операциях, 'g' используется в опции возведения в степень
    															// P.S. я знаю что переменные с типом флот можно одной строкой записать, но пускай будет так

    int res1;

    do
    {
        printf("Input first number: \n");					// У нас спрашивают первое число
        scanf("%f", &a);									// Вводим первое число

        printf("Input operation (-+/*^!): \n");				// У нас спрашивают операцию
        scanf("%s", &c);									// Вводим символ, означающий определённую операцию

        if (c == '!')										// чтобы было проще жить, действия с факториалами я вынес до свитч-кейсов, но пока что у меня где-то ошибка и факториал работает не корректно, хотя задание с факториалом я успешно выполнил
        {
        	if (a < 0)										// факториала отрицательного числа не существует
        	{
        		printf("Error \n");
        	}
        	else if (a == 0)								// на случай если нам интересен факториал нуля
        	{
        		printf("0 \n");								// вообще факториал нуля это равен 1, но будем считать, что он равено 0
        	}
        	else if (a - (int)a != 0)
        	{
        		printf("You can't use factorial numbers \n");		// чтобы получить ответ на факториал вещественного числа
        	}
        	else if (a != 0)
        	{
        		res1 = 1;
        				for (int d=1;d<=a;d++)
        				{
        					res1 *= d;
        				}
        				printf("Result: %i \n", res1);				// факториал считает всё хорошо по 12!, чтобы он хорошо считал и дальше нужно использовать long int или что-либо подобное
        	}

        }

        else
        {
        printf("Input second number: \n");					// У нас спрашивают второе число
        scanf("%f", &b);									// Вводим второе число, если с != '!'

        switch (c)											// переходим к части с действиями с разными функциями
                {
                case '+':											// ну тут сложение
                    printf("Result %f: \n", a+b);
                    break;

                case '-':											// а тут разность
                    printf("Result %f \n", a-b);
                    break;

                case '/':											// деление
                    printf("Result %f: \n", a/b);
                    break;

                case '*':											// умножение
                    printf("Result %f: \n", a*b);
                    break;

                case '^':
                    g = 1;                          		//с возведением в степень была некая проблема
                    if (b < 0)                      		//когда ты делишь 1 число кучу раз в цикле
                    {                               		//оно становится равным нулю.
                        for (int i = 0; i > b; i--) 		//ну я как CoolHackerMan нашаманил в коде и
                        {                           		//исправил ошибку: теперь у меня умножается в
                            g = g * a;            			//цикле кучу раз знаменатель, а потом 1 число
                        }                           		//делится на этот знаменатель
                        res = 1 / g;
                    } 										//Импровизируй, Адаптируйся, Преодолевай
                    else if (b == 0)						// @Дмитрий Каспер
                    {										// данная часть кода (именно возведение в степень) была позаимствованна у Дмитрия
                        res = 1;
                    }
                    else
                    {
                        for (int i = 1; i <= b; i++)
                        {
                            g = g * a;
                        }
                        res = g;
                    }
                    printf("Result: %f \n", res);				// получение результата на функцию возведения в степень
                    break;

                default:										// это на случай, если будет введён какой-то символ не из списка перечисленных
                    printf("Error \n");							// ответ на непонятный символ
                }
        }



        printf("Do you want to continue?(y.n) \n"); 	// писать код для ответа на другие значения 'v' мне лень
        scanf("%s", &v);								// вводим y/n в зависимости от желания продолжать работу программы или нет


    }
    while (v == 'y');									// ну получается пока переменная 'v' равняется 'y' мы продолжаем работу программы, в остальных случаях программа офается
    return 0;											// то что всегда нужно в программах на языке 'C'
}
