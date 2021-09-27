#include <stdio.h>

#include "UI_Tools.h"
#include "constants.h"

// "Starting song creation"
// What part? Verse? Chorus? Intro? ...
// What Song?
// What [choice]? [choice] 1? [choice] 2? [choice] 3? ...
// Write song string: 1652234451

int main()
{

  char string_ptr[BUFFER_LENGTH] = "";
  char single = 'a';
  Ask_For_String("What part?", string_ptr);

  printf("String generated: %s\n", string_ptr);
  printf("Character %d\n", single);

  unsigned int int_ans;
  int_ans = Ask_For_Int("Give me a number");
  printf("Integer given back: %u\n", int_ans);

  int char_ans;
  char_ans = Ask_Yes_Or_No("Would you like cheese with that?");

  printf("Bool ans: %d\n", char_ans);

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
