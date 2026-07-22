//В этом файле находятся реализации функций

#include <stdio.h>
#include <regex.h>
#include "phone.h"

//Массив указателей на стуктуры контактов
static Contact *phonebook[SIZE_CONTACTS] = {NULL};

//Общее количество уже существующих контактов
static int contact_count = 0;

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

//Создаём буферные массивы, для хранения введённых данных пользователя
char ln[STR_LEN], fn[STR_LEN], mn[STR_LEN], wp[STR_LEN], pos[STR_LEN], phone[STR_LEN], eml[STR_LEN], vk[STR_LEN], messgr[STR_LEN];

printf("=========Добавление контакта========== \n");

//Т.к. поле обязательные делаем бесконечный цикл, пока пользователь не введёт хотябы одну букву
do
{
    printf("Введите фамилию (Обязательное поле): ");
    Read_string(ln, STR_LEN);

} while (strlen(ln) == 0);

do
{
    printf("Введите имя (Обязательное поле): ");
    Read_string(fn, STR_LEN);
    
} while (strlen(fn) == 0);

//Далее просто просим пользователя ввести данные. Но они не обязательные
printf("Введите отчество: "); Read_string(mn, STR_LEN);
printf("Введите место работы: "); Read_string(wp, STR_LEN);
printf("Введите должность: "); Read_string(pos, STR_LEN);
printf("Введите номер телефона: "); Read_string(phone, STR_LEN);
printf("Введите e-mail: "); Read_string(eml, STR_LEN);
printf("Введите ссылку на соц сети: "); Read_string(vk, STR_LEN);
printf("Введите профиль в мессенджере: "); Read_string(messgr, STR_LEN);





}

