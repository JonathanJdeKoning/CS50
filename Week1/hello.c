#include <stdio.h>
#include <cs50.h>
// Asks the user for their name, and then greets them with the input. 
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
