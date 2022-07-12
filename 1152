#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int    count_words(char str[])
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    while (str[i] != 0)
    {
        if (str[i] == 32)
            i++;
        if (str[i] != 32 && str[i] != 0)
            cnt++;
        while (str[i] != 32 && str[i] != 0)
            i++;
    }
    return (cnt);
}

int    main(void)
{
    char    str[1000001];

    gets(str);
    printf("%d\n", count_words(str));
    return (0);
}
