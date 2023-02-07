#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int    get_duration(char str[])
{
    int    i;
    int    result;
    
    i = 0;
    result = 0;
    while (str[i] != 0)
    {
        if (str[i] >= 'A' && str[i] <= 'O')
            result = result + (str[i] - 'A') / 3 + 3;
        else if (str[i] >= 'P' && str[i] <= 'S')
            result += 8;
        else if (str[i] >= 'T' && str[i] <= 'V')
            result += 9;
        else if (str[i] >= 'W' && str[i] <= 'Z')
            result += 10;
        i++;
    }
    return (result);
}

int    main(void)
{
    char    str[16];
    
    scanf("%s", str);
    printf("%d\n", get_duration(str));
    return (0);
}
