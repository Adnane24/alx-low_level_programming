#include "main.h"

/**
 * string_nconcat - Concatenates two strings, at most n bytes from s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes from s2 to concatenate.
 *
 * Return: A pointer to the concatenated string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int x, y, z;

	if (s1 == NULL)
		x = 0;
	else
	{
		for (x = 0; s1[x]; ++x)
			;
	}
	if (s2 == NULL)
		y = 0;
	else
	{
		for (y = 0; s2[y]; ++y)
			;
	}
	if (y > n)
		y = n;
	s = malloc(sizeof(char) * (x + y + 1);
	if (s == NULL)
		return (NULL);
	for (z = 0; z < x; z++)
		s[z] = s1[z];
	for (z = 0; z < y; z++)
		s[z + x] = s2[z];
	s[x + y] = '\0';
	return (s);
}
