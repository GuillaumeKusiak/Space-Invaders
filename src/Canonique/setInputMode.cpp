/*!
 * @file    setInputMode.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Configuration du mode non canonique
 * @version 1.0
 */

#include <unistd.h>
#include <termios.h>
#include "../../headers/Canonique/setInputMode.h"

struct termios saved_attributes;

void nsSetInputMode::reset_input_mode(void)
{
    tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void nsSetInputMode::set_input_mode(){
    struct termios tattr;
    char *name;

    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }
    tcgetattr (STDIN_FILENO, &saved_attributes);
    atexit (reset_input_mode);

    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON|ECHO);
    tattr.c_cc[VMIN] = 0;
    tattr.c_cc[VTIME] = 1;
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}

