#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ui_tools.h"
#include "constants.h"

#include <ftw.h>

struct options
{
    char** paths;
    int size;
    int capacity;
}options;

int on_open(const char* fpath, const struct stat* sb, int typeflag)
{
    if (typeflag == FTW_F)
    {
        char* ptr = strrchr(fpath, '_');
        *ptr = 0;

        if (strcmp(ptr - 6, "bridge") == 0)
        {
            *ptr = '_';
            ptr = strchr(fpath, '/');
            printf("option %i: %s\n", options.size + 1, ptr + 1);

            // Dynamically enlarge options
            if (options.size == options.capacity)
            {
                options.capacity = options.capacity * 2;
                char** temp = malloc(sizeof(char*) * options.capacity);
                memcpy(temp, options.paths, sizeof(char*) * options.size);
                free(options.paths);
                options.paths = temp;
            }

            options.paths[options.size] = malloc(strlen(fpath));
            strcpy(options.paths[options.size], fpath);

            options.size++;
        }
    }
    return 0;
}

void get_song_options()
{
    ftw("Songs", &on_open, FOPEN_MAX);
}

void free_options()
{
    for (int i = 0; i < options.size; i++)
    {
        free(options.paths[i]);
    }
}

char* create_bridge()
{
    char* bridge_text = malloc(BUFFER_LENGTH);

    options.size = 0;
    options.capacity = 10;
    options.paths = malloc(sizeof(char*) * options.capacity);

    get_song_options();

    if (options.size == 0)
    {
        free_options();
        return NULL;
    }

    unsigned int choice;

    do
    {
        choice = Ask_For_Int("Enter number of choice");
    } while (choice <= 0 || choice > options.size);

    FILE* file_ptr = fopen(options.paths[choice - 1], "r");

    if (file_ptr == NULL)
    {
        return NULL;
    }

    char* song_writer = bridge_text;

    char next = getc(file_ptr);

    if (next == EOF)
    {
        return NULL;
    }

    int i = 0;
    do
    {
        *song_writer = next;
        song_writer++;
        next = getc(file_ptr);
        i++;
    } while (next != EOF && i < BUFFER_LENGTH - 1);

    *song_writer = 0;

    fclose(file_ptr);

    return bridge_text;
}