#include <stdio.h>

int    alpha_len(char str[])
{
    int    i;
    int    len;

    i = 0;
    len = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            len++;
        i++;
    }
    return (len);
}

int    get_kro_num(char str[])
{
    int    cnt;
    int    i;

    i = 0;
    cnt = alpha_len(str);
    while (str[i] != '\0')
    {
        if ((str[i] == 'l' || str[i] == 'n') && str[i + 1] == 'j')
            cnt--;
        else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
            cnt--;
        i++;
    }
    return (cnt);
}

int    main(void)
{
    char    str[101];

    scanf("%s", str);
    printf("%d\n", get_kro_num(str));
}
