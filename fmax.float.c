#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h> // Для функции isdigit

int fMax(FILE *file);

int main(void)
{
    const char *file_path = "numbers_nope.txt";
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
        {
            printf("Open error.\n");
            return 0;
        }
    fMax(file);
    fclose(file);
}

int fMax(FILE *file)
{
    int max_value = INT_MIN;
    int current_value;
    int has_numbers = 0;
    char current_str[20];
    while (fscanf(file, "%s", current_str) == 1)
    {
        int is_number = 1; // предполагаем, что в current_str число
        for (int i = 0; current_str[i] != '\0'; i++)
        {
            if (!isdigit(current_str[i]) && !(i == 0 && current_str[i] == '-')) // Проверка на отрицательное число
            {
                is_number = 0;
                break;
            }
        }

        if (!is_number)
        {
            printf("Error: invalid syntax.\n");
            return -1;
        }

        current_value = atoi(current_str);

        if ((current_value > INT_MAX) || (current_value < INT_MIN))
        {
            printf("Error: out of interval\n");
            fclose(file);
            return -1;
        }

        if (current_value > max_value)
        {
            max_value = current_value;
        }
        has_numbers = 1;
    }

    if (has_numbers)
    {
        printf("Max num: %d\n", max_value);
    }
    else
    {
        printf("No numbers found.\n");
    }
    return 1;
}



