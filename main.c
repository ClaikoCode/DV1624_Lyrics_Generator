#include <stdio.h>

#include "UI_Tools.h"

// "Starting song creation"
// What part? Verse? Chorus? Intro? ...
// What Song?
// What [choice]? [choice] 1? [choice] 2? [choice] 3? ...
// Write song string: 1652234451

int main()
{

  char* string_ptr = NULL;
  Ask_For_String("Random", string_ptr);

  printf("String generated: %s\n", string_ptr);

  // PRint introduction

  // What part? Verse? Chorus? Intro? ...

  //char textbuffer[512];
  //if(1)
  //{
  //  char verse[64] = create_verse();
  //  memcpy(textbuffer, verse);
  //}
  //else if(2)
  //{
//
  //}

  return 0;
}
