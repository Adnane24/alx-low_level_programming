#include <stdlib.h>
#include "main.h"

int count_word(char *s);
void copy_word(char *str, char **matrix, int *k, int start, int end);

char **strtow(char *str)
{
    char **matrix;
    int i, k = 0, len = 0, words, c = 0, start, end;

    while (*(str + len))
        len++;

    words = count_word(str);

    if (words == 0)
        return (NULL);

    matrix = (char **)malloc(sizeof(char *) * (words + 1));

    if (matrix == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (c)
            {
                end = i;
                copy_word(str, matrix, &k, start, end);
                c = 0;
            }
        }
        else if (c++ == 0)
            start = i;
    }

    matrix[k] = NULL;

    return (matrix);
}

int count_word(char *s)
{
    int flag, c, w;

    flag = 0;
    w = 0;

    for (c = 0; s[c] != '\0'; c++)
    {
        if (s[c] == ' ')
            flag = 0;
        else if (flag == 0)
        {
            flag = 1;
            w++;
        }
    }

    return (w);
}

void copy_word(char *str, char **matrix, int *k, int start, int end)
{
    char *tmp = (char *)malloc(sizeof(char) * (end - start + 1));

    if (tmp == NULL)
        return;

    for (int i = start, j = 0; i < end; i++, j++)
    {
        tmp[j] = str[i];
    }

    tmp[end - start] = '\0';
    matrix[*k] = tmp;
    (*k)++;
}
