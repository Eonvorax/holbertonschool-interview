#include "holberton.h"

/**
 * wildcmp - Compares two strings, with possible '*' wildcards in s2
 * @s1: string 1
 * @s2: string 2, can contain asterisk wildcards representing any substring
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	int i = 0, j = 0;
	int star_index = -1, s1_index = -1;

	while (s1[i] != '\0') /* While we are not at the end of s1 */
	{
		if (s2[j] == '*') /* If we encounter a '*' in s2 */
		{
			star_index = j; /* Record the position of '*' in s2 */
			s1_index = i;   /* Record the position in s1 */
			j++;            /* Move past the '*' in s2 */
		}
		else if (s2[j] == s1[i]) /* Characters match, keep going */
		{
			i++;
			j++;
		}
		else if (star_index != -1) /* If there was a previous '*' */
		{
			j = star_index + 1; /* Move past '*' in s2 */
			i = s1_index + 1;   /* Try matching the next character in s1 */
			s1_index = i;       /* Update the position in s1 */
		}
		else
		{
			return (0); /* Mismatch without '*' in s2 */
		}
	}

	/* Skip any remaining '*' characters in s2 */
	while (s2[j] == '*')
		j++;

	/* Return 1 if both strings are completely processed */
	return (s1[i] == '\0' && s2[j] == '\0');
}
