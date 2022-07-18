#include <stdio.h>

void    init_char_zero(char res[])
{
    for (int i = 0; i < 10002; i++)
        res[i] = '0';
    res[i] = '\0';
}

int    get_last_idx(char *str)
{
    int    i;
    
    i = 0;
    while (*(str + i))
        i++;
    i--;
    return (i);
}

char    *add_big_nbr(char num1[], char num2[])
{
    char    res[10003];
    char    temp;
    int     i1;
    int     i2;
    int     i_res;
    
    init_char_zero(res);
    i1 = get_last_idx(num1);
    i2 = get_last_idx(num2);
    i_res = 10001;
    while (i1 != -1 || i2 != -1)
    {
        temp = res[i_res] + num1[i1] + num1[i2] - 96;
        if (temp > '9')
        {
            res[i_res - 1] += 1;
            temp -= 10;
        }
        res[i_res] = res[i_res] + 
    }
}

int    main(void)
{
    char    num1[10002];
    char    num2[10002];
    
    scanf("%s %s", num1, num2);
    printf("%s\n", add_big_nbr(num1, num2));
}
