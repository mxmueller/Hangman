#include <stdio.h>
#include <string.h>

const char *ascii_headline_part[600];
const char *ascii_hangman_part[600];
const char *ascii_dashboard_part[600];
const char *ascii_divider[15];

int loadAscii()
{
    ascii_headline_part[0] = " _   _ ";
    ascii_headline_part[1] = "| | | | ";
    ascii_headline_part[2] = "| |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __";
    ascii_headline_part[3] = "|  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ ";
    ascii_headline_part[4] = "| | | | (_| | | | | (_| | | | | | | (_| | | | |";
    ascii_headline_part[5] = "\\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|";
    ascii_headline_part[6] = "                    __/ |                    ";
    ascii_headline_part[7] = "                   |___/                     ";

    ascii_hangman_part[0] = "  +---+\n";
    ascii_hangman_part[1] = "  |   |\n";
    ascii_hangman_part[2] = "      |\n";
    ascii_hangman_part[3] = "  O   |\n";
    ascii_hangman_part[4] = " /|   |\n";
    ascii_hangman_part[5] = " /|\\  |\n";
    ascii_hangman_part[6] = " /    |\n";
    ascii_hangman_part[7] = " / \\  |\n";
    ascii_hangman_part[8] = "=========\n";

    ascii_dashboard_part[0] = "  ___          _    _                      _ ";
    ascii_dashboard_part[1] = " |   \\ __ _ __| |_ | |__  ___  __ _ _ _ __| |";
    ascii_dashboard_part[2] = " | |) / _` (_-< ' \\| '_ \\/ _ \\/ _` | '_/ _` |";
    ascii_dashboard_part[3] = " |___/\\__,_/__/_||_|_.__/\\___/\\__,_|_| \\__,_|";

    ascii_divider[0] = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    return 1;
}
