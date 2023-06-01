#include "dmanager_module.h"

#include <stdio.h>   // импортируем из door_struct.h !!!
#include <stdlib.h>  // импортируем из dmanager_module.h !!!
#include <time.h>

#include "door_struct.h"  // по идее наследуется из dmanager_module.h и можно не прописывать..

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors);
    close_doors(doors);
    print_doors(doors);
    return 0;
}

// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors) {
    struct door tmp;
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int k = i + 1; k < DOORS_COUNT; k++) {
            if (doors[i].id > doors[k].id) {
                tmp = doors[k];
                doors[k] = doors[i];
                doors[i] = tmp;
            }
        }
    }
}

void close_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void print_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != (DOORS_COUNT - 1)) {
            printf("\n");
        }
    }
}
