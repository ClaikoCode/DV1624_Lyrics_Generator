#include "UI_Tools.h"

#include <stdio.h>
#include <string.h>

void Print_Text(char* question)
{
    printf("%s\n", question);
}

void Ask_For_String(char* question, char* answer)
{
    Print_Text(question);

    char* console_in = NULL;
    scanf("%s", console_in);

    strcpy(answer, console_in);
}

int Ask_For_Int(char* question)
{
    Print_Text(question);

    int answer = 5;
    return answer;
}

unsigned char Ask_Yes_Or_No(char* question)
{
    Print_Text(question);
    printf("Input y/n: ");

    return 1;
}

void Print_Current_Song_Structure()
{

}