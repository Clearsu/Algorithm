#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void    ft_swap(char *a, char *b)
{
    char    temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int    char_to_int(char str[])
{
    int    i;
    int    result;
    
    i = 0;
    result = 0;
    while (str[i] != 0)
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result);
}

int    main(void)
{
    char    num1[4];
    char    num2[4];
    
    scanf("%s", num1);
    scanf("%s", num2);
    ft_swap(&num1[0], &num1[2]);
    ft_swap(&num2[0], &num2[2]);
    if (char_to_int(num1) > char_to_int(num2))
        printf("%d\n", char_to_int(num1));
    else
        printf("%d\n", char_to_int(num2));
    return (0);
}
