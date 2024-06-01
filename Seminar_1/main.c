#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


int main() {
    FILE *file = fopen("D:\\PC Laboratory\\Lectii\\Problema_seminar\\sales.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    Node *head = NULL;
    read_units(file, &head);
    fclose(file);

    display_menu(head);


    free_list(head);

    return 0;
}


