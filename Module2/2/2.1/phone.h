//Это заголовочный файл, тут находятся данные
#pragma once

//Записываем константы
#define SIZE_CONTACTS 5
#define STR_LEN 10

typedef struct {
    char lastname[STR_LEN];
    char firstname[STR_LEN];
} LastFirstNames;

typedef struct {
    char middlename[STR_LEN];
    char workplace[STR_LEN];
    char position[STR_LEN];
    char phone[STR_LEN];
    char email[STR_LEN];
    char vk[STR_LEN];
    char messenger[STR_LEN];
} Contact;

//Функции
void Main_menu();
void Print_contact();
void Add_contact();
void Edit_contact();
void Del_contact();

