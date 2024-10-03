#include "holberton.h"


/**
 * error_handler - Prints "Error" then a newline, and exits with status 98
 * Only uses the _putchar function
 *
 * Returns: Nothing
 */
void error_handler(void)
{
	char error[] = "Error\n";

	for (int i = 0; error[i] != '\0'; i++)
	{
		_putchar(error[i]);
	}
	exit(98);
}

/**
 * is_string_digits - Checks that the given string is made of digits only
 * @str: given string to check for non-digit characters
 *
 * Return: 1 if the string is made only of digits, 0 otherwise
 */
int is_string_digits(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		/* If we find a non-digit character, return 0 */
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _strlen - Basic rewrite of strlen
 * @str: given string
 *
 * Return: int length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * multiply - Multiplies two positive ints and prints the result
 * @num1: string format number 1
 * @num2: string format number 2
 *
 */
void multiply(char *num1, char *num2)
{
	int len_num1 = _strlen(num1);
	int len_num2 = _strlen(num2);
	int len_result = len_num1 + len_num2; /* Maximum possible length of result */
	int i_leading_zero = 0;
	char *result = malloc(len_result + 1); /*allocate memory, + 1 for '\0' */

	if (result == NULL)
		error_handler();

	/* Initialize the result string with '0's */
	for (int i_result = 0; i_result < len_result; i_result++)
		result[i_result] = '0';

	result[len_result] = '\0'; /* Null terminator */

	for (int i_num1 = len_num1 - 1; i_num1 >= 0; i_num1--)
	{
		int carry = 0;
		int digit_num1 = num1[i_num1] - '0'; /*Convert current digit to int*/

		for (int i_num2 = len_num2 - 1; i_num2 >= 0; i_num2--)
		{
			int digit_num2 = num2[i_num2] - '0';
			/* Sum of the multiplication of digits, plus the carry */
			int sum = (result[i_num1 + i_num2 + 1] - '0') +
			digit_num1 * digit_num2 + carry;
			carry = sum / 10; /* Keep the carry over for the next digit */
			/* Store the digit as a char */
			result[i_num1 + i_num2 + 1] = (sum % 10) + '0';
		}
		/* Store any remaining carry in the next position */
		result[i_num1] += carry;
	}
	/* Skip any leading '0's in the result */
	while (i_leading_zero < len_result - 1 && result[i_leading_zero] == '0')
		i_leading_zero++;
	for (int i = i_leading_zero; result[i] != '\0'; i++)
		_putchar(result[i]);
	_putchar('\n');
	free(result);
}

/**
 * main - Main function that handles arguments and calls the calc. functions
 * @argc: (int) argument count
 * @argv: (char *) array of string arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_string_digits(argv[1]) || !is_string_digits(argv[2]))
	{
		error_handler();
	}

	multiply(argv[1], argv[2]);

	return (0);
}
