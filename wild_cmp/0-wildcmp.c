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
	/* Base case: if both strings are empty, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If we encounter a '*' in s2 */
	if (*s2 == '*')
	{
		/* Skip over consecutive '*' in s2 */
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* If the current characters match, move on to the next characters */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* If the characters don't match and no '*' could match, return 0 */
	return (0);
}
