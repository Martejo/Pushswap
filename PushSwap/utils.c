#include "utils.h"

int my_atoi(char *str, int *verif)
{
    int sign;
    int res;
    int i;
    int lastDigit;

    i = 0;
    res = 0;
    sign = 1;
    if (str[i] == '-')
    {
        sign *= -1;
        lastDigit = 8;
        i++;
    }
    lastDigit =7;
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (res >= 214748364 && (str[i] - '0' > lastDigit))
        {
            *verif = 0;
            return (0);
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] != '\0')
        *verif = 0;
    return (res * sign);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int check_value_duplicate(char **value)
{
    int i;
    int j;

    i = 1;

    while (value[i])
    {
        j = i + 1;
        while (value[j])
        {
            if (ft_strcmp(value[i], value[j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

