#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

const int max_word_length = 15;

typedef struct
{
    char wanted_word[max_word_length];
    int word_length;
    int remaining_lives;
    int attempts;
} Meta;

Meta Runtime; // == getter 

Meta reset(Meta *runtime)
{
    strcpy(runtime->wanted_word, "");
    runtime->word_length = 0;
    runtime->remaining_lives = 10;
    runtime->attempts = 0;
    return *runtime;
}

Meta set(Meta *runtime, char *ww, int wl, int rl, int a)
{
    strcpy(runtime->wanted_word, ww);
    runtime->word_length = wl;
    runtime->remaining_lives = rl;
    runtime->attempts = a;
    return *runtime;
}

Meta get() {
    return Runtime;
}

int main(int argc, char const *argv[])
{
    reset(&Runtime);
    set(&Runtime, "Dienstag", 7, 10, 0);

    printf("%s", get().wanted_word);
    printf("\n");
    printf("%d", get().word_length);
    printf("\n");
    printf("%d", get().remaining_lives);
    printf("\n");
    printf("%d", get().attempts);
    printf("\n");

    return 0;
}
