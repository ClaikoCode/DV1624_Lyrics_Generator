#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI_Tools.h"
#include "constants.h"
#include "songparts.h"

// "Starting song creation"
// What part? Verse? Chorus? Intro? ...
// What Song?
// What [choice]? [choice] 1? [choice] 2? [choice] 3? ...
// Write song string: 1652234451

const int TOT_SONG_PARTS = 5;
enum SONG_PARTS {Intro = 1, Verse, Pre_chorus, Chorus, Bridge};

int g_part_capacity = 4;
int g_part_count = 0;

// Allocates more memory for 
char** Expand_Song_Array(char** arr_ptr)
{
  g_part_capacity *= 2;
  char** new_arr_ptr = malloc(g_part_capacity * sizeof(char*));
  memcpy(new_arr_ptr, arr_ptr, g_part_capacity / 2);
  free(arr_ptr);

  return new_arr_ptr;
}

// Prints the final song with formating to distinguish between different parts
void Print_Song(char** arr_ptr, char* song_name)
{
  printf("\n\n--- %s ---\n\n", song_name);
  
  for(int i = 0; i < g_part_count; i++)
  {
    printf("Part %d\n\n", i + 1);
    printf(arr_ptr[i]);
  }
}

// Adds a song part through user inquiry. Expects an array of char pointers.
void Add_Song_Part(char** song_parts)
{
  printf("\nSong options:\n\
  1: Intro\n\
  2: Verse\n\
  3: Pre-chorus\n\
  4: Chorus\n\
  5: Bridge\n");

  char formated_inquiry[BUFFER_LENGTH];
  sprintf(formated_inquiry, "\nPlease pick a number between 1 and %d", TOT_SONG_PARTS);

  unsigned int choice = 0;
  // Infinite loop? Created by reading previous line probably.
  while (choice < 1 || choice > TOT_SONG_PARTS)
  {
    choice = Ask_For_Int(formated_inquiry);
  }

  char *song_part_ptr = NULL;
  switch (choice)
  {
  case Intro:
    printf("\n-- Opening intro creator --\n\n");
    song_part_ptr = create_intro();
    break;

  case Verse:
    printf("\n-- Opening verse creator --\n\n");
    song_part_ptr = create_verse();
    break;

  case Pre_chorus:
    printf("\n-- Opening pre-chorus creator --\n\n");
    song_part_ptr = create_pre_chorus();
    break;

  case Chorus:
    printf("\n-- Opening chorus creator --\n\n");
    song_part_ptr = create_chorus();
    break;

  case Bridge:
    printf("\n-- Opening bridge creator --\n\n");
    song_part_ptr = create_bridge();
    break;

  default:
    // This should never happen.
    printf("Choice is not valid!");
    exit(1);
  }

  if (g_part_count == g_part_capacity)
  {
    Expand_Song_Array(song_parts);
  }

  song_parts[g_part_count++] = song_part_ptr;

  printf("\nSong part added succesfully!\n");
}

int main()
{
  char** song_parts = malloc(g_part_capacity * sizeof(char*));

  printf("\n---- Welcome to the song creator ----\n");

  unsigned int continue_adding = 1;
  while(continue_adding)
  {
    Add_Song_Part(song_parts);

    do
    {
      continue_adding = Ask_Yes_Or_No("Do you want to add an additional part?");
    }while(continue_adding == -1);
  }

  char song_name[BUFFER_LENGTH];
  Ask_For_String("\nChoose a song name", song_name);

  Print_Song(song_parts, song_name);

  for(int i = 0; i < g_part_count; i++)
  {
    free(song_parts[i]);
  }

  free(song_parts);

  return 0;
}
