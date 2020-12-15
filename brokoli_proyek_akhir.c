#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USER_INPUT 5

void error_arguments();

typedef struct {
	char name[100];
	int age;
	char domisili[20];
	bool isTestRequired;
} User;

int main(int argc, char *argv[]) {
	// File Handler
	FILE *fptr;
	pFile = fopen("user_database.txt", "w");
	
	// Untuk menghitung banyak data yang sudah tersimpan
	int user_count = 0;
	
	if (pFile != NULL) {
		if (argc == 2) {
			int user_number = argc - 1;
			if (strcmp(argv[2], "input") == 0) {
				if (user_number < MAX_USER_INPUT) {
					int i, j;
					User user[user_number];
					// Loop for inputting value to struct
					for (i = 0; i < user_number; i++) {
						int count_left = user_number - i;
						printf("Ada %i data tersisa yang perlu diisi.\n", count_left);
						
						printf("Masukkan nama user\t: "); scanf("%[^/n]", &user[i].name);
						printf("Masukkan umur user\t: "); scanf("%i", &user[i].age);
						printf("Masukkan domisili user\t: "); scanf("%[^/n]", &user[i].domisili);
						user[i].isTestRequired = false;
					}
					
					// Loop for storing struct value to file
					//for (i = 0; i < user_number; i++) {
						
					//}
				}
			}
			
		} else if (argc > 2) {
			// Jika argument yang dimasukkan lebih dari dua
			error_message();
			printf("Error: Terlalu banyak argument yang dimasukkan!");
			printf("Usage: ./<project_name> 'input|read|count' ");
		}
		
		//Close file syntax
		fclose(pFile);
	} else {
		error_message();
		printf("Could not open user_database.txt file!");
	}
	
	return 0;
}

void error_message() {
	printf("Terjadi kesalahan pada program:");
}

