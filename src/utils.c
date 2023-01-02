#include "../include/utils.h"
#include "../include/tty.h"

void print_logo()
{
    printf("\t                                                                \n");
    printf("\t .88b  d88. d888888b d8888b. d888888b db    db  .d88b.  .d8888. \n");
    printf("\t 88'YbdP`88   `88'   88  `8D   `88'   `8b  d8' .8P  Y8. 88'  YP \n");
    printf("\t 88  88  88    88    88oobY'    88     `8bd8'  88    88 `8bo.   \n");
    printf("\t 88  88  88    88    88`8b      88     .dPYb.  88    88   `Y8b. \n");
    printf("\t 88  88  88   .88.   88 `88.   .88.   .8P  Y8. `8b  d8' db   8D \n");
    printf("\t YP  YP  YP Y888888P 88   YD Y888888P YP    YP  `Y88P'  `8888Y' \n");
    printf("\t                                                                \n");
    printf("\t                                                                \n");
}

void about(char *version)
{
    printf("\n\tMirixOS - v%s - My biggest operating system\n", version);
    printf("\n\tMade by Louiml at 04/11/2022");
}