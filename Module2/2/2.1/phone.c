//В этом файле находятся реализации функций

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "phone.h"

//Массив указателей на стуктуры контактов
static Contact *phonebook[SIZE_CONTACTS] = {NULL};

//Общее количество уже существующих контактов
static int contact_count = 0;

//Очистка буфера от символа перехода на следующую строку
static void Clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' $$ c !=EOF);    
}

//Функция обработки строки
void Read_string(char *buffer, int max_len) {
    fgets(buffer, max_len, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

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
void Add_contact() {

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

printf("=========Добавление контакта========== \n");

//Очищаем буфер ввода
Clear_buffer();

//Т.к. поле обязательные делаем бесконечный цикл, пока пользователь не введёт хотябы одну букву
do
{
    printf("Введите фамилию (Обязательное поле не менее 2х символов): ");
    Read_string(new_contact->lfn.lastname, STR_LEN);

} while (strlen(new_contact->lfn.lastname) < 2);

do
{
    printf("Введите имя (Обязательное поле не менее 1 символа): ");
    Read_string(new_contact->lfn.firstname, STR_LEN);
    
} while (strlen(new_contact->lfn.firstname) == 0);

//Далее просто просим пользователя ввести данные. Но они не обязательные
printf("Введите отчество: "); Read_string(new_contact->middlename, STR_LEN);
printf("Введите место работы: "); Read_string(new_contact->workplace, STR_LEN);
printf("Введите должность: "); Read_string(new_contact->position, STR_LEN);
printf("Введите номер телефона: "); Read_string(new_contact->phone, STR_LEN);
printf("Введите e-mail: "); Read_string(new_contact->email, STR_LEN);
printf("Введите ссылку на соц сети: "); Read_string(new_contact->vk, STR_LEN);
printf("Введите профиль в мессенджере: "); Read_string(new_contact->messenger, STR_LEN);

//Сохраняем указатель на память в куче в массив
phonebook[contact_count++] = new_contact;
printf("Контакт с фамилией %s создан.\n", new_contact->lfn.lastname);

}

void Free_phonebook(){
    for (int i = 0; i < contact_count; i++)
    {
        if (phonebook[i] != NULL)
        {
            free(phonebook[i]);
            phonebook[i] = NULL;
        }        
    }
    contact_count = 0;
}

void Edit_contact(){
    printf("Тут будет функция редактирования контакта");
    
}


void Print_contacts(){
    //Проверка на существование контактов
    if (contact_count == 0)
    {
        printf("Телефонная книга пуста\n");
        return;
    }
    
    //Если мы попали сюда, значит в книге чтото есть. Выводим
    printf("==========Список контактов==========\n");

    for (int i = 0; i < contact_count; i++)
    {
        //Получаем доступ через указатель, который лежит в массиве
        Contact *c = phonebook[i];

        //Печатаем порядковый номер, чтото типа айди. Фамилию, имя и отчество.
        printf("#пп: %d | %s, %s, %s\n", i+1, c->lfn.firstname, c->lfn.lastname, c->middlename);

        //Заглядываем в каждую ячейку структуры и, если там чтото написано, печатаем
        if (strlen(c->workplace)>0) printf("Место работы: %s", c->workplace);
        if (strlen(c->position)>0) printf("Должность: %s", c->position);
        if (strlen(c->phone)>0) printf("Тел.: %s", c->phone);
        if (strlen(c->email)>0) printf("Почта: %s", c->email);
        if (strlen(c->vk)>0) printf("Страница: %s", c->vk);
        if (strlen(c->messenger)>0) printf("Мессенджер: %s", c->messenger);
    }
    

}

void Del_contact(){
    printf("Тут будет функция удаления контакта");
}

