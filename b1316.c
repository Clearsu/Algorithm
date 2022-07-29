#include <stdio.h>

void    init_arr(int arr[])
{
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
}

int    is_group_word(char word[])
{
    char   curr;
    int    alpha_map[26];
    int    i;
    
    i = 0;
    init_arr(alpha_map);
    while (word[i] != '\0')
    {
        curr = word[i];
        if (alpha_map[curr - 'a'] == 1)
            return (0);
        alpha_map[curr - 'a']++;
        while (word[i] == curr)
            i++;
    }
    return (1);
}

int    main(void)
{
    int    test_num;
    int    cnt;
    char   word[101];
    
    cnt = 0;
    scanf("%d", &test_num);
    for (int i = 0; i < test_num; i++)
    {
        scanf("%s", word);
        if (is_group_word(word))
            cnt++;
    }
    printf("%d\n", cnt);
    return (0);
}
