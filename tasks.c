#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int size, left, right;

    printf("Задания 1 - 3:\n");
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));

    printf("Введите диапазон генерируемых чисел [min, max]: ");
    scanf("%d %d", &left, &right);

    printf("Одномерный массив: ");
    for (int i = 0; i < size; i++){
        array[i] = left + rand() % (right - left + 1);
        printf("%4d", array[i]);
    }
    printf("\n");

    int min = array[0], max = array[0];
    for (int i = 0; i < size; i++){
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    printf("Разница между max (%d) и min (%d): %d\n\n", max, min, max - min);

    printf("Задание 4:\n");
    int arr[10][10];
    printf("Двумерный массив 10x10:\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = left + rand() % (right - left + 1);
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int sumRow, sumCol;
    for (int i = 0; i < 10; i++){
        sumRow = 0;
        for (int j = 0; j < 10; j++){
            sumRow += arr[i][j];
        }
        printf("Строка %d: %d\n", i + 1, sumRow);
    }
    
    printf("\n");

    for (int j = 0; j < 10; j++){
        sumCol = 0;
        for (int i = 0; i < 10; i++){
            sumCol += arr[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, sumCol);
    }

    free(array);

    printf("\nЗадание 5:\n");
    int i;
    struct student
    {
        char famil[20];
        char name[20], facult[20];
        int Nomzach;
    } stud[3];
 
    for(i=0; i<3; i++)
    {
        printf("Введите фамилию студента: "); 
        scanf("%20s", stud[i].famil);
    }
    for(i=0; i<3; i++)
    {
        printf("Введите имя студента %s: ", stud[i].famil);
        scanf("%20s", stud[i].name);
    }
    for(i=0; i<3; i++)
    {
        printf("Введите название факультета студента %s %s: ", stud[i].famil, stud[i].name); 
        scanf("%20s", stud[i].facult);
    }
    for(i=0; i<3; i++)
    {
        printf("Введите номер зачётной книжки студента %s %s: ", stud[i].famil, stud[i].name); 
        scanf("%d", &stud[i].Nomzach);
    }
 
    int choice;
    char searchFamil[20], searchName[20], searchFacult[20];
    int searchNomzach;
    int found = 0;

    while (!found)
    {
        printf("\nВыберите параметр для поиска:\n");
        printf("1. Фамилия\n");
        printf("2. Имя\n");
        printf("3. Факультет\n");
        printf("4. Номер зачетной книжки\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Введите фамилию для поиска: ");
                scanf("%20s", searchFamil);
                for(i = 0; i < 3; i++)
                {
                    if(strcmp(stud[i].famil, searchFamil) == 0)
                    {
                        printf("Найден студент: %s %s, факультет: %s, номер зачётной книжки: %d\n", 
                            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                        found = 1;
                    }
                }
                break;

            case 2:
                printf("Введите имя для поиска: ");
                scanf("%20s", searchName);
                for(i = 0; i < 3; i++)
                {
                    if(strcmp(stud[i].name, searchName) == 0)
                    {
                        printf("Найден студент: %s %s, факультет: %s, номер зачётной книжки: %d\n", 
                            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                        found = 1;
                    }
                }
                break;

            case 3:
                printf("Введите факультет для поиска: ");
                scanf("%20s", searchFacult);
                for(i = 0; i < 3; i++)
                {
                    if(strcmp(stud[i].facult, searchFacult) == 0)
                    {
                        printf("Найден студент: %s %s, факультет: %s, номер зачётной книжки: %d\n", 
                            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                        found = 1;
                    }
                }
                break;

            case 4:
                printf("Введите номер зачетной книжки для поиска: ");
                scanf("%d", &searchNomzach);
                for(i = 0; i < 3; i++)
                {
                    if(stud[i].Nomzach == searchNomzach)
                    {
                        printf("Найден студент: %s %s, факультет: %s, номер зачётной книжки: %d\n", 
                            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                        found = 1;
                    }
                }
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                continue;
        }

        if (!found)
        {
            printf("Студент с такими данными не найден. Попробуйте еще раз.\n");
        }
    }

    return 0;
}