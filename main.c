#include <stdio.h>
#include "just_once.h"
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

    scanf("%100s", str); //ввод текста

    printf("исходный текст: %100s\n", str); //вывод изначального текста

    for (int i = 0; i != 100; i++) // проход по всей строчки. Ищутся все заглавные латинские буквы и заносятся в массив cap_was, если данная буква не находится в нем
    {
        if (str[i + 1] == '\0') // проверка на конец строки
        {
            len = i;
            break;
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'Z') // проверка на то, что является ли нынешний символ из строки заглавной латинской буквой
            {
                if (in_mass(cap_was, count_was, str[i])) // если является, то проверяется, какое значение вернет функция in_mass, если она вернет 1, то в массиве cap_was нет нынешней заглавной латинской буквы, и она заносится в этот массив
                {
                    cap_was[count_was++] = str[i];
                }
            }
        }
    }

    if (in_mass(cap_was, count_was, str[len]) && (str[len] >= 'A' && str[len] <= 'Z')) // проверка на то, входила ли последний символ в строку и является ли она заглавной латинской буквой
    {
        printf("правило: 1\n");
        simetric_change(str); // вызов функции, изменяющей все заглавные латинские буквы на противоположные им в алфавите
    }
    else
    {
        printf("правило: 2\n");
        just_once(str); // вызов функции, оставляющей в строке только символы, которые встречаются в ней 1 раз
    }

    printf("%s", str); // вывод измененной сроки

    return 0;
}
