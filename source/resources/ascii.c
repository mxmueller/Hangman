#include <stdio.h>
#include <string.h>

const char *ascii_headline_part[600];
const char *ascii_hangman_part[600];

int load_ascii_art()
{
    ascii_headline_part[0] = " _   _ \n";
    ascii_headline_part[1] = "| | | | \n";
    ascii_headline_part[2] = "| |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __\n";
    ascii_headline_part[3] = "|  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n";
    ascii_headline_part[4] = "| | | | (_| | | | | (_| | | | | | | (_| | | | |\n";
    ascii_headline_part[5] = "\\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n";
    ascii_headline_part[6] = "                    __/ |                    \n";
    ascii_headline_part[7] = "                   |___/                     \n";

    ascii_hangman_part[0] = "  +---+\n";
    ascii_hangman_part[1] = "  |   |\n";
    ascii_hangman_part[2] = "      |\n";
    ascii_hangman_part[3] = "  O   |\n";
    ascii_hangman_part[4] = " /|   |\n";
    ascii_hangman_part[5] = " /|\\  |\n";
    ascii_hangman_part[6] = " /    |\n";
    ascii_hangman_part[7] = " / \\  |\n";
    ascii_hangman_part[8] = "=========\n";
    return 1;
}
