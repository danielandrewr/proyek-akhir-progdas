#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "brokoli.h"

typedef struct {
	char name[100];
	int age;
	char domisili[30];
	int test_status;
	int common_symptoms;
	int uncommon_symptoms;
	int serious_symptoms;
} User;

int main(void) {
	int MAX_USER_INPUT = 5; // default
	int user_number;
	char answer_buffer[1];
	
	int input;
	
	menu:
		main_menu();
	
	printf("Masukkan input action: ");
	scanf("%i", &input);
	
	if (input == 1) {
		goto input_data;
	} else if (input == 2) {
		goto lihat_data;
	} else if (input == 0) {
		return 0;
	} else {
		return 0;
	}
		
	input_data:
		system("cls");
		printf("\nMasukkan banyak user yang ingin diinput (max: 5 user): "); scanf("%i", &user_number);
		
		if (user_number <= MAX_USER_INPUT) {	
			User user[user_number];
			int i, j;
			while (i < user_number) {
				int count_left = user_number - i;
				printf("\nData Input User #%i\n", i+1);
				printf("\n");
				printf("Ada %i data tersisa yang perlu diisi.\n", count_left);
				if (i >= 1) {
					system("pause");
				}
				
				getchar();
				printf("Masukkan nama user\t: ");
				gets(user[i].name);
				
				printf("Masukkan umur user\t: "); 
				scanf("%i", &user[i].age);
				
				getchar();
				printf("Masukkan domisili user\t: ");
				gets(user[i].domisili);
				fflush(stdin);
				
				user[i].test_status = 0;
				user[i].common_symptoms = 0;
				user[i].uncommon_symptoms = 0;
				user[i].serious_symptoms = 0;
				
				i++;
			}
			
			printf("\nOutput\n");
			for (i = 0; i < user_number; i++) {
				printf("\nData User #%i\n", i+1);
				
				printf("Nama\t\t: %s\n", user[i].name);
				printf("Umur\t\t: %i\n", user[i].age);
				printf("Domisili\t: %s\n", user[i].domisili);
				
			}
		} else {
			error_message();
			printf("User tidak bisa melebihi batas yang ditentukan.");	
		}
		
		char answer;
		make_question("\nAnda telah menyelesaikan input data, Apakah anda ingin melanjutkan ke main menu? (Y/N)\n", answer_buffer, sizeof(answer_buffer));
		printf(">> %s", answer_buffer);
		scanf("%s", &answer);
		if (answer == 'Y') goto menu;
	
	
	lihat_data:
		return 1;
			
	return 0;
}
