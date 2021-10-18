#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI_Tools.h"
#include "constants.h"

#include <ftw.h>
struct Options
{
    char** array;
    int size;
    int capacity;
}options;

int OnOpen(const char *fpath, const struct stat *sb, int typeflag)
{
    if (typeflag == FTW_F)
    {
        char* ptr = strrchr(fpath, '_');
        *ptr = 0;
        
        if (strcmp(ptr - 6, "chorus") == 0)
        {
            *ptr = '_';
            ptr = strchr(fpath, '/');
            printf("Option %i: %s\n", options.size + 1, ptr + 1);

            if (options.size == options.capacity)
            {
                options.capacity = options.capacity * 2;
                char** temp = malloc(sizeof(char*) * options.capacity);
                memcpy(temp, options.array, sizeof(char*) * options.size);
                free(options.array);
                options.array = temp;
            }
            
            options.array[options.size] = malloc(strlen(fpath));
            strcpy(options.array[options.size], fpath);
            
            options.size++;
        }
    }
    return 0;
}

void get_song_options()
{
    ftw("Songs", &OnOpen, FOPEN_MAX);
}

void free_options()
{
    for (int i = 0; i < options.size; i++)
    {
        free(options.array[i]);
    }
    free(options.array);
}

char * create_chorus()
{
    char* song_text = malloc(BUFFER_LENGTH);

    options.size = 0;
    options.capacity = 10;

    options.array = malloc(sizeof(char*) * options.capacity);

    get_song_options();

    if (options.size == 0)
    {
        free_options();
        return NULL;
    }

    unsigned int choice;

    do
    {
        choice = Ask_For_Int("Enter choice number");
    } while (choice <= 0 || choice > options.size);
    
    FILE *file_ptr = fopen(options.array[choice - 1], "r");

    if (file_ptr == NULL)
    {
        return NULL;
    }

    char* song_writer = song_text;

    char next = getc(file_ptr);

    if (next == EOF)
    {
        return NULL;
    }

    int repeats;
    do
    {
        repeats = Ask_For_Int("Number of repeats");
    } while (choice <= 0);

    int j = 0;

    for (int i = 0; i < repeats; i++)
    {
        if (i != 0)
        {
            file_ptr = fopen(options.array[choice - 1], "r");
            next = getc(file_ptr);
        }
        
        do
        {
            *song_writer = next;
            song_writer++;
            next = getc(file_ptr);
            j++;
            if (j >= BUFFER_LENGTH - 1)
            {
                break;
            }
        } while (next != EOF);
        
        fclose(file_ptr);
        

        if (j >= BUFFER_LENGTH - 1)
        {
            break;
        }
        else
        {
            *song_writer = '\n';
            song_writer++;
        }
    }
    
    *song_writer = 0;

    free_options();

    return song_text;
}

int main()
{
    char * temp = create_chorus();

    printf("%s\n", temp);
    free(temp);
    return 0;
}