#ifndef GAME_H
#    define GAME_H
#    include <stdio.h>
#    include <stdlib.h>
#    include <string.h>

#    define DATAFILE "./var/chance.data" // Файл для хранения
// пользовательских данных

// Специальная структура user хранит сведения о пользователях

struct user {
    int  uid;
    int  credits;
    int  highscore;
    char name[100];
    int (*current_game)();
};

// Прототипы функций
int   game_of_chance();
int   get_player_data();
void  register_new_player();
void  update_player_data();
void  show_highscore();
void  jackpot();
void  input_name();
void  print_cards(char *, char *, int);
int   take_wager(int, int);
void  play_the_game();
int   pick_a_number();
int   dealer_no_match();
int   find_the_ace();
void  fatal(char *);
void *ec_malloc(unsigned int);

// Функция для вывода сообщения об ошибке и завершения работы программы
void
fatal(char *message)
{
    char error_message[100];
    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

// Оболочка для malloc() с проверкой ошибки
void *
ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        fatal("in ec_malloc() on memory allocation");
    }
    return ptr;
}
#endif
#pragma once
