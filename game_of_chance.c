#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "my_lib.h"

#define DATAFILE "./var/chance.data" // Файл для хранения
                                     // пользовательских данных

// Специальная структура user хранит сведения о пользователях

struct user {
    int uid;
    int credits;
    int highscore;
    char name[100];
    int (*current_game) ();
};

// Прототипы функций
int get_player_data();
void register_new_player();
void update_player_data();
void show_highscore();
void jackpot();
void input_name();
void print_cards(char *, char *, int);
int take_wager(int, int);
void play_the_game();
int pick_a_number();
int dealer_no_match();
int find_the_ace();

// Глобальные переменные
struct user player; // Структура с данными игрока
// ############################################################
int main()
{
    int choice, last_game;
    srand(time(0)); // Начальное значение генератора
    // случайных чисел определяются текущим временем.

    if (get_player_data() == -1) { // Попытка прочитать данные игрока из файла.
        register_new_player(); // Если данных нет,
        // зарегистрировать нового игрока.
    }

}

// ############################################################
