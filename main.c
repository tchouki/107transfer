/*
** EPITECH PROJECT, 2018
** 107transfer
** File description:
** main.c
*/

#include "include/my.h"

int my_strlen(char *str)
{
	int size = 0;

	for (; str[size] != '\0'; size++);
	return (size);
}

int print_help(void)
{
	printf("USAGE\n");
	printf("\t./107transfer [num den]*\n\n");
	printf("DESCRIPTION\n");
	printf("\tnum\tpolynomial numerator defined by its coeficients\n");
	printf("\tden\tpolynomial denominator defined by its coeficients\n");
	return (0);
}

int check_argv(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j] != '\0'; j++)
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '*' && argv[i][j] != '-')
				return (84);
	return (0);
}

double calc2(char *str, double nb)
{
	double result = 0;

	for (int size = my_strlen(str) - 1; size >= 0; size -= 2) {
		for (; size >= 0 && str[size] != '*'; size--);
		size++;
		result = result * nb + (double)(str[size] - '0');
	}
	return (result);
}

int calc(int argc, char **argv)
{
	int x = 1;
	int result1 = 0;
	double result2 = 1;
	int temp = 100;

	for (; result1 <= 100000; result1 += temp) {
		result2 = 1;
		for (x = 1; x < argc; x += 2)
			result2 *= calc2(argv[x], result1 / 100000.0) / calc2(argv[x + 1], result1 / 100000.0);
		printf("%.3lf -> %.5lf\n", result1 / 100000.0, result2);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argc == 2 && argv[1][2] == '\0')
		return (print_help());
	if (argc < 2 || argc % 2 == 0)
		return (84);
	if (check_argv(argc, argv) == 84)
		return (84);
	return (calc(argc, argv));
}