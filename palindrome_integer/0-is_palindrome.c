#include "palindrome.h"

/**
 * is_palindrome - Checks if a a given unsigned integer is a palindrome.
 * @n: The number to be checked for a palindrome
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_n = n;
	unsigned long reversed_n = 0;

	/* Reverse the digits of n one by one, and store them in reversed_n */
	while (n > 0)
	{
		reversed_n = reversed_n * 10 + (n % 10);
		n /= 10;
	}

	/* Compare the original number with the reversed one */
	return (original_n == reversed_n);
}
