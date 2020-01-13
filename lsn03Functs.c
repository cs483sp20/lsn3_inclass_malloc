//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lsn03Functs.h"

StudentType* initStudents(long numStudents) {
    char buf[50];

    // Allocate storage for the students
    StudentType* stdPtr = malloc(numStudents * sizeof(StudentType));

    // All user to enter data
    for (int i = 0; i < numStudents; i++) {
        printf("Enter first name (%d): ",i);
        fgets(stdPtr[i].first, 19, stdin);
        stdPtr[i].first[strlen(stdPtr[i].first)-1] = '\0';

        printf("Enter last name (%d): ",i);
        fgets((stdPtr+i)->last, 29, stdin);
        stdPtr[i].last[strlen(stdPtr[i].last)-1] = '\0';

        printf("Enter age (%d): ",i);
        fgets(buf, 10, stdin);
        stdPtr[i].age = strtol(buf, NULL, 10);

        // Allocate storage for grades
        printf("How many grades (%d): ",i);
        fgets(buf, 10, stdin);
        stdPtr[i].numGrades = strtol(buf, NULL, 10);
        stdPtr[i].grades = malloc(stdPtr[i].numGrades * sizeof(long));

        // generate random #'s and assign as a grade
        for (int j = 0; j < stdPtr[i].numGrades; j++) {

            stdPtr[i].grades[j] = random() % 101;
        }

    }

    return stdPtr;
}

void printStudents(StudentType* stdPtr, long numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d ->\n",i);
        printf("\tName: %s %s\n", stdPtr[i].first, stdPtr[i].last);
        printf("\tAge: %ld\n", stdPtr[i].age);
        printf("\tGrades: ");
        for (int j = 0; j < stdPtr[i].numGrades; j++) {
            printf("%ld ",stdPtr[i].grades[j]);
        }
        printf("\n\n");
    }
}

void deallocStudents(StudentType* stdPtr, long numStudents) {
    // Must deallocate grades array in each struct prior
    // to deallocating the array of structs
    for (int i = 0; i < numStudents; i++) {
        free(stdPtr[i].grades);
    }
    // Deallocate array of structs
    free(stdPtr);
}