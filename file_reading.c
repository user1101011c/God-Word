#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH  1000
char bible[MAX_LENGTH][MAX_LENGTH];

int file_reading() {
    FILE *file = fopen("bible.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    int num_bible = 0;
    while (fgets(bible[num_bible], MAX_LENGTH, file)) {
        num_bible++;
    }

    srand(time(NULL));
    int random_index = rand() % num_bible;
    printf("%s", bible[random_index]);

    fclose(file);
    return 0;
}