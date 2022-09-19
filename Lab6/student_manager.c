#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FILENAME "students.txt"
#define BUFFERSIZE 500

struct Database {
	int capacity;
	int size;
	char** data;
};
typedef struct Database Database;

Database* database = NULL;


int cmp(const void *str1, const void *str2) {
    const char *rec1 = *(char**)str1;
    const char *rec2 = *(char**)str2;
    int val = strcmp(rec1, rec2);
	return val;
}



Database* databaseConsructor() {
	if (database != NULL)
		return database;
	Database* db = malloc(sizeof(Database));
	db->capacity = 1;
	db->size = 0;
	db->data = (char**)malloc(sizeof(char*));
	return db;
}

void save(char* record) {
	database = databaseConsructor();
	if (database->capacity <= database->size) {
#ifdef DEBUG
        printf("Database is resizing\n");
#endif
		int newCapacity = database->capacity * 2;
		int newSize = database->size + 1;
		char** newData = (char**)malloc(newSize * sizeof(char*));
        for(int i = 0; i < newCapacity; i++) {
            if (i < database->size) {
                newData[i] = (char*)malloc(BUFFERSIZE * sizeof(char));
                strcpy(newData[i], database->data[i]);
                database->data[i] = NULL;
            }
            else {
                newData[i] = NULL;
            }
        }
        newData[newSize-1] = (char*)malloc(BUFFERSIZE * sizeof(char));
		strcpy(newData[newSize - 1], record);
		database->data = newData;
		database->capacity = newCapacity;
		database->size = newSize;
	}
    else {
        database->data[database->size] = (char*)malloc(sizeof(char) * BUFFERSIZE);
		strcpy(database->data[database->size], record);
        database->size++;
    }
#ifdef DEBUG
    printf("record %s added\n", record);
#endif
}

void showDatabase() {
#ifdef DEBUG
    printf("showDatabase()\n");
#endif
    if (database == NULL) {
#ifdef DEBUG
        printf("NULL\n");
#endif
        return;
    }
	qsort(database->data, database->size, sizeof(database->data), cmp);
    for (int i = 0; i < database->size; i++) {
        printf("record %d: %s\n", i, database->data[i]);
    }
}

void findAll() {
#ifdef DEBUG
    printf("In findAll()\n");
#endif
    FILE* in = fopen(FILENAME, "r");
    if (in == NULL) {
        printf("Error opening database file!\n");
        exit(1);
    }
	char buffer[BUFFERSIZE];
	while (fgets(buffer, sizeof(buffer), in)) {
#ifdef DEBUG
        printf("%s\n", buffer);
#endif
        buffer[strcspn(buffer, "\n")] = 0;
        if (strlen(buffer))
		    save(buffer);
	}
    fclose(in);
}

void commit() {
#ifdef DEBUG
    printf("Writing to database\n");
#endif
	FILE* out = fopen(FILENAME, "w");
    if (out == NULL) {
        printf("Error opening database file!\n");
        exit(1);
    }
	qsort(database->data, database->size, sizeof(database->data), cmp);
	for (int i = 0; i < database->size; i++) {
		fprintf(out, "%s\n", database->data[i]);
	}
    fclose(out);
#ifdef DEBUG
    printf("Writing to database is complited\n");
#endif
	
}

int findByName(char* name) {
    int l = -1, r = database->size, m;
    while (r - l > 1) {
        m = l + (r - l) / 2;
        if (strcmp(database->data[m], name) < 0)
            l = m;
        else
            r = m;
    }
    if (r < database->size && strcmp(database->data[r], name) == 0)
        return r;
    else
        return -1;
}

int main(int argNum, char** args) {
    if (argNum != 3) {
        printf("The number of arguments should be 3\n");
        return 0;
    }
	findAll();
    char* cmd = args[1];
    char* name = args[2];
    if (strcmp(cmd, "add_student") == 0) {
        if (strlen(name) > BUFFERSIZE) {
            printf("Too large name\n");
        }
        else {
            save(name);
#ifdef DEBUG
            showDatabase();
#endif
            commit();
        }
    }
    else if (strcmp(cmd, "find_student") == 0) {
        int idx = findByName(name);
        if (idx == -1) {
            printf("Not found!\n");
        }
        else {
            printf("Index in DB is %d\n", idx);
        }
    }

    else {
        printf("No valid command\n");
    }
	return 0;
}
