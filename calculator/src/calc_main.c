/*
	  Created by Akbarjon Rashidov, first year student of VSU
	  physical faculty, Informatics and computer engineering (ICE)

  	  В начале программы предлагается выбрать режим работы программы:
  	  (l - списки, s - стек, q - очередь).

  	  Формат входных данных для списков и очереди:
  	  + c 17 9
  	  - v 3 17 23 18 30 11 11

  	  Формат входных данных для стека:
  	  18 13 + 11 - 3 ^ n
  	  17 2 * 2 - n
  	  (в конце каждой строки необходимо писать "n")
 */

#include <stdio.h>
#include <stdlib.h>

#include "math.h"
#include "list.h"
#include "queue.h"
#include "stack.h"



int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char choose;
	char str[50], t = '0';
	int i = 0;
	float num, x, y;
	char in[50], out[50];

	FILE *input, *output;
	stack *head_stack = NULL;

	printf("l - list, s - stack, q - queue \n");
	scanf(" %c", &choose);

	switch (choose) {

/////////////////////////////////////////////////////
/////				Списки						/////
/////////////////////////////////////////////////////
	case 'l':

		printf("Input file name: ");
		scanf(" %s", in);

		printf("Output file name: ");
		scanf(" %s", out);

		input = fopen(in, "r");
		if (feof(input) == 0) {
			head = malloc(sizeof(struct list1)); 			// память для первого элемента списка
			fscanf(input, " %c", &head->sign);
			fscanf(input, " %c", &head->choose);
			if (head->choose == 'v') {
				fscanf(input, " %i", &head->size);
			} else {
				head->size = 1;
			}
			if (head->sign != '!') {
				head->x = add_numb(input, head->size);
				head->y = add_numb(input, head->size);
			} else {
				head->x = add_numb(input, head->size);
				head->y = NULL;
			}
			current = head;

			while (feof(input) == 0) { 						// добавление элементов списка, пока не закончится файл
				add_el(current, input);
				current = current->next;

			}
			head_res = malloc(sizeof(struct list2)); 		// память для первого элемента списка для вывода
			current = head;
			if (current->choose == 'v') {
				head_res->res = vect_l(current->sign, current->size, current->x,
						current->y);
			} else {
				head_res->res = numb_l(current->sign, current->x, current->y);
			}
			head_res->res_next = NULL;
			current = current->next;
			current_res = head_res;
			while (current != NULL) { 				// пока элемент списка не последниий
				res_add_el(current_res, current);
													// переустановка указателей на следующий элемент
				current = current->next;
				current_res = current_res->res_next;
			}
			current = head;
			current_res = head_res;
			fclose(input);
			output = fopen(out, "w");
			while (current != NULL) 				//запись ответа в output
			{
				if (current->choose == 'v') {
					fprintf(output, "(");
					for (int i = 0; i < current->size; i++) {
						fprintf(output, " %.2f", current->x[i]);
					}
					fprintf(output, ") %c (", current->sign);
					for (int i = 0; i < current->size; i++) {
						fprintf(output, " %.2f", current->y[i]);
					}
					fprintf(output, " ) = ");
					if (current->sign != '*') {
						fprintf(output, "( ");
						for (int i = 0; i < current->size; i++) {
							fprintf(output, "%.2f ", current_res->res[i]);
						}
						fprintf(output, ")\n");
					} else {
						fprintf(output, "%.2f\n", current_res->res[0]);
					}
				} else if (current->choose == 'c') {
					if (current->sign != '!') {
						fprintf(output, " %.2f %c %.2f = %.2lf\n",
								current->x[0], current->sign, current->y[0],
								current_res->res[0]);
					} else {
						fprintf(output, " %.2f %c = %.2lf\n", current->x[0],
								current->sign, current_res->res[0]);
					}
				}
				current = current->next;
				current_res = current_res->res_next;
			}
			fclose(output);
		}
		return 0;
		break;

/////////////////////////////////////////////////////
/////				Oчередь						/////
/////////////////////////////////////////////////////
	case 'q':

		printf("Input file name: ");
		scanf("%s", in);
		input = fopen(in, "r");
		queue_t queue = init_queue(); 						// создаём пустую очередь

		while (!feof(input))
			enqueue(&queue, read_string(input)); 			// добавляем в очередь строки

		fclose(input);

		printf("Output file name: ");
		scanf("%s", out);

		output = fopen(out, "w");

		while (!is_empty(queue)) { 							// пока не кончится очередь
			calc_q(output, dequeue(&queue)); 				// вычисляем выражение
		}
		fclose(output);
		return 0;
		break;

/////////////////////////////////////////////////////
/////					Cтек					/////
/////////////////////////////////////////////////////

	case 's':
		printf("Input file name: ");
		scanf(" %s", in);
		printf("Output file name: ");
		scanf(" %s", out);
		input = fopen(in, "r");
		output = fopen(out, "w");
		while (feof(input) == 0) {
			fscanf(input, "%c", &str[i]);
			if (str[i] == ' ') {
				if (t == '0') {
					num = strtof(str, NULL); 				// разделяет строку на отдельные элементы
					push_element(&head_stack, num);
					i = 0;

				}
			} else if (str[i] == '*' || str[i] == '+' || str[i] == '-'
					|| str[i] == '/' || str[i] == '^') {
				y = pop_element(&head_stack);
				x = pop_element(&head_stack);
				push_element(&head_stack, numb_s(str[i], x, y));
				fprintf(output, "%.2f  ", numb_s(str[i], x, y));
				t = '1';
			} else if (str[i] == 'n') {
				while (head_stack != NULL)
					pop_element(&head_stack);
				fprintf(output, "\n");
			} else {
				t = '0';
				i = i + 1;
			}
		}

		fclose(input);
		fclose(output);
		return 0;
		break;
	}

}
