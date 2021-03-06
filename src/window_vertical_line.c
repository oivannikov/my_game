#include "game.h"

static void rotate_str(char *str);
static void change_words(char *str);

void window_vertical_line(char *string, WINDOW *line_window) {
    rotate_str(string);
    change_words(string);
    attron(A_BOLD);
    for (unsigned long i = 0; i < strlen(string); i++) {
        mvwprintw(line_window, i, 0, "%c", string[i]);
    }
    attroff(A_BOLD);
}

 static void rotate_str(char *str) {
     int index = strlen(str) - 1;
     char tmp = str[strlen(str) - 1];
     while (str[index]) {
         str[index] = str[index - 1];
         index--;
     }
     str[0] = tmp;
 }

static void change_words(char *str) {
    int index = 0;

    while (str[index]) {
        if (str[index] != ' ' && str[index + 1] != ' ' && str[index + 2] == ' ' && str[index + 2] && str[index + 1]) {
            str[index] = get_rand_char();
        }
        else if (str[index] != ' ' && str[index + 1] != ' ' && str[index + 1]) {
            str[index] = str[index + 1];
        }
        index++;
    }
}
