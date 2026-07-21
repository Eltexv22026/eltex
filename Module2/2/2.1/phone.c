//В этом файле находятся реализации функций

#include <stdio.h>
#include "phone.h"

//Массив указателей на стуктуры контактов
static Contact *phonebook[SIZE_CONTACTS] = {NULL};

//Общее количество уже существующих контактов
static int contact_count = 0;

//Функция основного меню
void Main_menu () {
    char choice;

    while (1)
    {
            printf("\tМеню\n"
        "1. Список\n"
        "2. Добавить\n"
        "3. Редактировать\n"
        "4. Удалить\n"
        "5. Выход\n"
        "Выберите нужную команду: ");
        choice = getchar();

        switch (choice)
        {
        case '1':
            Print_contacts();
            break;

        case '2':
            Add_contact();
            break;

        case '3':
            Edit_contact();
            break;
        
        case '4':
            Del_contact();
            break;

        case '5':
            exit(0);            
            // break;

        default:
            printf("Неверный ввод.");
            break;
        }
    }    
}

//Функция добавления контактов
void Add_contact(){

//Проверка на заполненность телефонной книги
    if(contact_count>=SIZE_CONTACTS){
        printf("Телефонная книга переполнена.\n");
        return;
    }

//Выделяем память в куче под один контакт
Contact *new_contact = (Contact*)malloc(sizeof(Contact));

//Проверка на выделение памяти под контакт
if(new_contact == NULL){
    printf("Память под ячейку контака не выделена");
    return;
}

//Если мы попали сюда, значит уже память выделена
memset(new_contact, 0, sizeof(Contact));



}

