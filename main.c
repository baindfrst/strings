#include <stdio.h>
#include "simetric_change.h"

int in_mass(char mass[], int len, char check) // возвращает 1, усли в массиве нет такого элемента, иначе 0
{
    for (int j = 0; j != len; j++)
    {
        if (mass[j] == check)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    char str[100];
    
    char cap_was[25];
    int count_was = 0;
    int len = 0;

    scanf("%100s", str);

    for (int i = 0; i != 100; i++)
    {
        if (str[i] == '\0')
        {
            len = i;
            break;
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                if (in_mass(cap_was, count_was, str[i]))
                {
                    cap_was[count_was++] = str[i];
                }
            }
        }
    }

    if (in_mass(cap_was, count_was, str[len-1]));
    {
        simetric_change(str);
    }

    printf("%s", str);

    return 0;
}
