#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./hello your name");
        return 1;
    }
    char *name = argv[1];
    printf("hello %s", name);
    return 0;
}