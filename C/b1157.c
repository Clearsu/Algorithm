#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 26

void    put_zero(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = 0;
}

int    get_max_idx(int arr[])
{
    int    max;
    int    max_idx;
    
    max = arr[0];
    max_idx = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_idx = i;
        }
    }
    return (max_idx);
}

int    is_duplicate(int arr[], int max_idx)
{
    int    max_cnt;
    
    max_cnt = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == arr[max_idx])
            max_cnt++;
        if (max_cnt > 1)
            return (1);
    }
    return (0);
}

char    get_most_used(char str[])
{
    int    arr[SIZE];
    int    i;
    int    max_idx;
    
    i = 0;
    put_zero(arr);
    while (str[i] != 0)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            arr[str[i] - 'a']++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            arr[str[i] - 'A']++;
        i++;
    }
    max_idx = get_max_idx(arr);
    if (is_duplicate(arr, max_idx))
        return (0);
    return (max_idx + 'A');
}

int    main(void)
{
    char    str[1000001];
    char    res;
    
    scanf("%s", str);
    if (!(res = get_most_used(str)))
        printf("?\n");
    else
        printf("%c\n", res);
    return (0);
}
