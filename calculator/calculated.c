/*
Created by Akbarjon Rashidov, first year student of VSU
physical faculty, Informatics and computer engineering (ICE)
так нам нужен файл из которого берём значения и файл в который мы записываем результаты

прежде чем начать работу с кодом прочтите файл "readme.txt"
*/

#include <stdio.h>  //
#include <stdlib.h> //code needs this libraries to work
float a, b, *c, *d, res, g;
char y, x, z, t, input[50], output[50], yy;
int res1, i, j;

int main(int argc, char *argv[]) //
{
	setvbuf(stdout, NULL, _IONBF, 0); //
	setvbuf(stderr, NULL, _IONBF, 0); //this lines are necessary for correct work of program

	do {

		printf("Input input file name: \n");
		scanf(" %s", &input);
		printf("Input output file name: \n");
		scanf(" %s", &output);

		FILE *in, *out; //указываем на то, что у нас будут использоваться файлы
		in = fopen(input, "r"); //открываем файл 'input', из которого будем читать входные данные
		out = fopen(output, "w"); //открываем файл 'output', в который будем в дальнейшем записывать данные
		do {
			printf(
					"Do you want to use classic or vector calculator? (c/v):\n "); //here we ask user "what calculator he wants to use"
			fscanf(in, " %c", &x); //answer that move user to one of two variant
			switch (x) {
			case 'a': //algebra calculator

				printf("Input first number:\n"); //user inputs first number
				fscanf(in, "%f", &a);
				printf("Input operation (-+/*^!):\n"); //user is making his choice
				fscanf(in, " %c", &z);

				if (z == '!') //operation "!" (factorial) needs only one number, so I moved this operation to the top
						{
					if (a < 0) //factorial of a negative number doesn't exist
							{
						fprintf(out, "Error \n");
					} else if (a == 0) {
						fprintf(out, "1! = 1 \n"); //factorial of 0 is 1 (0! = 1)
					} else if (a - (int) a != 0) //we cannot find the factorial of a real number (переводчик выдал: вещественное число --> real number)
							{
						fprintf(out,
								"You can't use factorial of this number \n");
					} else if (a != 0) //
							{
						res1 = 1;
						for (int r = 1; r <= a; r++) {
							res1 *= r;
						}
						fprintf(out, "%f ! = ", a);
						fprintf(out, "%i \n", res1);
					}
				} else {
					printf("Input second number: \n"); //if operation was not a factorial, user input second number
					fscanf(in, "%f", &b);
					switch (z) 					//there goes usual operations
					{
					case '+':
						fprintf(out, "%f + ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a + b);
						break;
					case '-':
						fprintf(out, "%f - ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a - b);
						break;
					case '/':
						fprintf(out, "%f / ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a / b);
						break;
					case '*':
						fprintf(out, "%f * ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", a * b);
						break;
					case '^':
						g = 1;
						if (b < 0) {
							for (int i = 0; i > b; i--) {
								g = g * a;
							}
							res = 1 / g;
						} else if (b == 0) {
							res = 1;
						} else if (b - (int) b != 0) {
							fprintf(out, "Error \n");
						} else {
							for (int i = 1; i <= b; i++) {
								g = g * a;
							}
							res = g;
						}
						fprintf(out, "%f ^ ", a);
						fprintf(out, "%f = ", b);
						fprintf(out, " %f \n", res);
						break;
					default:
						fprintf(out, "Error \n");
					}
				}
				break;

			case 'v': //vector calculator
			{
				printf("Input size of vectors: \n");
				fscanf(in, "%i", &i);
				c = malloc(i * sizeof(float)); //allocating the required amount of memory for vector№1
				d = malloc(i * sizeof(float)); //allocating the required amount of memory for vector№2
				printf("Input first vector: \n ");	//считывание первого вектора

				for (j = 0; j < i; j++) {
					fscanf(in, "%f", &c[j]);
				}
				printf("Input operation (-+*): \n");
				fscanf(in, " %c", &t);
				printf("Input second vector: \n ");
				for (j = 0; j < i; j++)		//считывание второго вектора
						{
					fscanf(in, "%f", &d[j]);
				}
				switch (t) {
				case '-': 								//выглядит это как-то не очень зато работает
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '-');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '=');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
							{
						fprintf(out, "%f ", c[j] - d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				case '+':
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, "%c", '+');
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c", '=');
					fprintf(out, "%c", '(');
					for (j = 0; j < i; j++) {
						fprintf(out, "%f ", c[j] + d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				case '*':				//цикл вывода скалярного произведения
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ", c[j]);
					}
					fprintf(out, "%c", ')');
					fprintf(out, " %c ", '*');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++)
					{
						fprintf(out, "%f ",  d[j]);
					}
					fprintf(out, "%c ", ')');
					fprintf(out, "%c ", '=');
					fprintf(out, "%c ", '(');
					for (j = 0; j < i; j++) {
						fprintf(out, "%f ", c[j] * d[j]);
					}
					fprintf(out, "%c", ')');
					break;
				default:
					fprintf(out, "WRONG OPERATION");	//стоило бы сделать так, чтобы это выводилось сразу после вывода операции, которой нет в перечисленном списке
				}
				free(c);
				free(d);

			}
			}
			fscanf(in, " %c", &y);
		} while (y == 'y');
		fclose(in);
		fclose(out);
		printf("Do you want to continue? (y/n) \n");
		scanf(" %c", &yy);
	} while (yy == 'y');
	return 0;
}
