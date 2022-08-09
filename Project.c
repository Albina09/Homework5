/* Динамический телефонный справочник */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "Project.h"
#define N 20   //количество символов в имени, фамилии, номере

int i = 0;     //количество структур с данными

struct subsc {
    char Name[N], Surname[N], Number[N];
};
struct subsc* data;   //данные о контакте

void fil() {
    int c;

    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

void add() {
    int x;
    
    if (i) {
        data = (struct subsc*)realloc(data, sizeof(*data) * (i + 1));
        if (data == NULL)
            perror("error");
    }
    else 
        data = (struct subsc*)malloc(sizeof(*data));
  
    printf("Введите имя\n");
    if(fgets((data + i)->Name, N, stdin)==NULL)
        perror("error");


    printf("Введите фамилию\n");
    if (fgets((data + i)->Surname, N, stdin) == NULL)
        perror("error");

    printf("Введите номер\n");
    if (fgets((data + i)->Number, N, stdin) == NULL)
        perror("error");

    printf("Контакт добавлен\n");
    i++;

    menu();
}

void concl() {

    for (int j = 0; j < i; j++) 
        printf(" Имя:%s Фамилия:%s Номер:%s\n", data[j].Name, data[j].Surname, data[j].Number);

    menu();
}

void search() {
    char t = 1;
    char need[N];

    printf("Для поиска контакта введите имя/фамилию/номер телефона\n");
    if (fgets(need, N, stdin) == NULL)
        perror("error");

    for (int j = 0; j < i; j++) {

        if (strcmp(data[j].Name, need) == 0 || strcmp(data[j].Surname, need) == 0 || strcmp(data[j].Number, need) == 0) {
            printf(" Имя:%s Фамилия:%s Номер:%s\n", data[j].Name, data[j].Surname, data[j].Number);
            t = 0;
        }
    }

    if (t)
        printf("Такого контакта нет в справочнике\n");

    menu();
}

void del() {
    int t = -1;
    int m = 0;
    char need[N];

    printf("Для удаления контакта введите имя/фамилию/номер телефона\n");
    if (fgets(need, N, stdin) == NULL)
        perror("error");

    for (int j = 0; j < i; j++) {

        if (strcmp(data[j].Name, need) == 0 || strcmp(data[j].Surname, need) == 0 || strcmp(data[j].Number, need) == 0) {
            t = j;
            m = 1;
            printf("Контакт %s удалён\n", need);
        }
    }
    if (t != -1) {
        for (int j = t; j < i - 1; j++) {
            data[j] = data[j + 1];
        }

        i--;
        data = (struct subsc*)realloc(data, i * sizeof(*data));
        if (data==NULL)
            perror("error");
    }
    
    if (!m)
        printf("Такого контакта нет в справочнике\n");

    menu();
}

void menu() {
    char input = 0;

    printf("Добавить контакт - 1\n");
    printf("Вывести список контактов - 2\n");
    printf("Поиск контакта - 3\n");
    printf("Удалить контакт - 4\n");
    printf("Выйти - 5\n");

    int top = 0;
    input = getchar();
    fil();


    switch (input) {

    case '1': add();
        break;
    case '2':concl();
          break;
    case '3': search();
          break;
    case '4': del();
            break;
    case '5': top = 0;
        break;
    }

}

int main() {
    setlocale(LC_ALL,"Russian"); 
    
    menu();

    return 0;
}
