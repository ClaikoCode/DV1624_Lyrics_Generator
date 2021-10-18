#include <stdio.h>
#include <string.h>

#include "ui_tools.h"
#include "constants.h"

// This function should be called after each scanf call.
void Clear_Input_Buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Print_Text(char* inquiry)
{
    printf("%s: ", inquiry);
}

void Ask_For_String(char* inquiry, char* answer)
{
    Print_Text(inquiry);

    char console_in[BUFFER_LENGTH];
    scanf("%s", console_in);

    Clear_Input_Buffer();

    strcpy(answer, console_in);
}

// Returns integer value typed in by the user.
unsigned int Ask_For_Int(char* inquiry)
{
    Print_Text(inquiry);
    
    unsigned int answer;
    scanf("%d", &answer);

    Clear_Input_Buffer();
    return answer;
}

// Returns a integer from -1 to 1. 1 means yes, 0 means no and -1 means that there was no valid input.
int Ask_Yes_Or_No(char* inquiry)
{
    printf(inquiry);
    printf("\nInput y/n: ");

    unsigned char char_ans;
    scanf("%c", &char_ans);

    Clear_Input_Buffer();

    int return_ans = -1;
    if(char_ans == 'y') { return_ans = 1; }
    if(char_ans == 'n') { return_ans = 0; }

    return return_ans;
}