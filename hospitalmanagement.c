#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient queue[MAX];
int size = 0;

void addPatient(char name[], int priority) {
    int i = size - 1;

    while (i >= 0 && queue[i].priority > priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    strcpy(queue[i + 1].name, name);
    queue[i + 1].priority = priority;
    size++;

    printf("Added: %s (Priority %d)\n", name, priority);
}

void treatNextPatient() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    printf("Treating: %s (Priority %d)\n",
           queue[0].name, queue[0].priority);

    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

int main() {
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreatment order:\n");

    treatNextPatient();
    treatNextPatient();
    treatNextPatient();

    printf("\nNew emergency patient arrives:\n");
    addPatient("P7", 1);

    printf("\nRemaining treatment order:\n");

    while (size > 0) {
        treatNextPatient();
    }

    return 0;
}