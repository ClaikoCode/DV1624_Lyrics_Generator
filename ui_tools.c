#include <stdio.h>
#include <string.h>

#include "ui_tools.h"
#include "constants.h"


void Print_Text(char* inquiry)
{
    printf("%s: ", inquiry);
}

void Ask_For_String(char* inquiry, char* answer)
{
    Print_Text(inquiry);

    char console_in[BUFFER_LENGTH];
    scanf("%[^\n]%*c", console_in);

    strcpy(answer, console_in);
}

// Returns integer value typed in by the user.
unsigned int Ask_For_Int(char* inquiry)
{
    Print_Text(inquiry);
    
    unsigned int answer;
    int x = scanf("%d", &answer);

    return answer;
}

// Returns a integer from -1 to 1. 1 means yes, 0 means no and -1 means that there was no valid input.
int Ask_Yes_Or_No(char* inquiry)
{
    Print_Text(inquiry);
    printf("\nInput y/n: ");

    unsigned char char_ans;
    scanf(" %c", &char_ans);

    int return_ans = -1;
    if(char_ans == 'y') { return_ans = 1; }
    if(char_ans == 'n') { return_ans = 0; }

    return return_ans;
}

void Print_Current_Song_Structure()
{

}