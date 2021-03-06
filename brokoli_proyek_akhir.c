#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "brokoli.h"

void read_file(FILE *fptr);

struct User {
	char name[100];
	unsigned int age;
	char domisili[30];
	int test_status;							// 0 Normal, 1 Perlu Tes, 2 OTG
	int common_symptoms;
	int uncommon_symptoms;
	int serious_symptoms;
};

int main(void) {
	char answer_buffer[1];
	
	menu:
		main_menu();
	
		int input = 0;
		printf("Masukkan input action: ");
		scanf("%i", &input);
		
		if (input == 1) {
			goto input_data;
		} else if (input == 2) {
			FILE *fread;
			fread = fopen("user.txt", "r");
			// Jika file ada maka lanjutkan
			if (fread != NULL) {
				printf("Memuat user.txt...\n");
				puts("");
				
				// Membaca file
				read_file(fread);
				
				printf("\nData berhasil dimuat!");
				
				printf("");
				char answer;
				make_question("\nApakah anda ingin melanjutkan ke main menu? (Y/N)\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'Y') {
					goto menu;
				} else {
					return 0;
				}
			// Apabila file tidak ada	
			} else {
				error_message();
				printf("File database tidak berhasil dibuka, Menghentikan program.\n");
				return 0;
			}
		} else if (input == 3) {
			print_help();
			char answer;
			printf("\n");
			make_question("\nApakah anda ingin melanjutkan ke main menu? (Y/N)\n", answer_buffer, sizeof(answer_buffer));
			printf(">> %s", answer_buffer);
			scanf("%s", &answer);
			if (answer == 'Y') {
				goto menu;
			} else {
				return 0;
			}
		} else if (input == 4) {
			print_credits();
			printf("\n");
			char answer;
			make_question("\nApakah anda ingin melanjutkan ke main menu? (Y/N)\n", answer_buffer, sizeof(answer_buffer));
			printf(">> %s", answer_buffer);
			scanf("%s", &answer);
			if (answer == 'Y') {
				goto menu;
			} else {
				return 0;
			}
		} else if (input == 0) {
			return 0;
		} else {
			error_message();
			printf("Anda memasukkan input yang invalid!\n");
			return 0;
		}
	
	input_data:
		system("cls");
		int dma_size = 0;
		
		// Menginput jumlah user sesuai dengan keinginan pengguna
		printf("\nMasukkan banyak user yang ingin diinput: "); scanf("%i", &dma_size);
		
		// Membuat variabel pointer untuk dynamic memory allocation
		struct User *dma_pointer;
		// Mengalokasikan memori sesuai input user
		dma_pointer = (struct User *) malloc(dma_size * sizeof(struct User));
		
		int i;
		// Pengulangan untuk input data
		for (i = 0; i < dma_size; i++) {
			system("cls");
			if (i >= 1) {
				system("pause");
			}
			
			// Menghitung sisa user yang perlu diisi setelah input saat ini
			int count_left = dma_size - (i+1);
			printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=- Input User #%i -=-=-=-=-=-=-=-=-=-=-=-=-=-\n", i+1);
			printf("\n");
			printf("Ada %i data tersisa yang perlu diisi.\n", count_left);
			puts("");
			
			getchar();
			printf("Masukkan nama user\t\t: ");
			gets(dma_pointer[i].name);
			
			printf("Masukkan umur user\t\t: ");
			scanf("%i", &dma_pointer[i].age);
			
			getchar();
			printf("Masukkan tempat domisili user\t: ");
			gets(dma_pointer[i].domisili);
			fflush(stdin);
			
			// Tidak diinput oleh user, melainkan untuk akses algoritma
			dma_pointer[i].test_status = 0;
			dma_pointer[i].common_symptoms = 0;
			dma_pointer[i].uncommon_symptoms = 0;
			dma_pointer[i].serious_symptoms = 0;
			
			// Questions Section
			puts("");
			char answer;
			make_question("\nApakah anda pergi ke luar daerah dalam 2 bulan terakhir?\n", answer_buffer, sizeof(answer_buffer));
			printf(">> %s", answer_buffer);
			scanf("%s", &answer);
			if (answer == 'Y') {
				make_question("Apakah anda merasakan demam tinggi dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
				
				make_question("Apakah anda mengalami batuk kering dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
				
				make_question("Apakah anda dapat mencium bau dan mengecap rasa dengan normal?\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'N') dma_pointer[i].uncommon_symptoms+=1;
				
				make_question("Apakah anda merasa nyeri di area dada?\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'Y') dma_pointer[i].serious_symptoms+=1;
				
				// Pertanyaan untuk kemungkinan OTG
			} else if (answer == 'N') {
				dma_pointer[i].test_status = 2;
				make_question("Apakah ada anggota keluarga anda yang sering berpergian?\n", answer_buffer, sizeof(answer_buffer));
				printf(">> %s", answer_buffer);
				scanf("%s", &answer);
				if (answer == 'Y') {
					puts("");
					make_question("Apakah anda merasakan demam tinggi dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
					
					make_question("Apakah anda mengalami batuk kering dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
					
					make_question("Apakah anda dapat mencium bau dan mengecap rasa dengan normal?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'N') dma_pointer[i].uncommon_symptoms+=1;
					
					make_question("Apakah anda merasa nyeri di area dada?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].serious_symptoms+=1;
					
				} else if (answer == 'N') {
					make_question("Apakah anda merasakan demam tinggi dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
					
					make_question("Apakah anda mengalami batuk kering dalam 7 hari terakhir?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].common_symptoms+=1;
					
					make_question("Apakah anda dapat mencium bau dan mengecap rasa dengan normal?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'N') dma_pointer[i].uncommon_symptoms+=1;
					
					make_question("Apakah anda merasa nyeri di area dada?\n", answer_buffer, sizeof(answer_buffer));
					printf(">> %s", answer_buffer);
					scanf("%s", &answer);
					if (answer == 'Y') dma_pointer[i].serious_symptoms+=1;
				}	
			}
			
			//Perhitungan untuk hasil akhir
			// Parameter user memerlukan tes: 1 gejala umum dan 1 gejala serius
			// Parameter OTG: status user bernilai 2
			check_result:
				if ((dma_pointer[i].common_symptoms >= 1) && (dma_pointer[i].serious_symptoms >= 1)) {
					dma_pointer[i].test_status = 1;
				} else if ((dma_pointer[i].common_symptoms == 0) && (dma_pointer[i].serious_symptoms == 0)) {
					dma_pointer[i].test_status = 0;
				}
				
				if (dma_pointer[i].test_status == 2) {
					if ((dma_pointer[i].common_symptoms == 0) && (dma_pointer[i].serious_symptoms == 0)) {
						goto check_result;
					} else if ((dma_pointer[i].common_symptoms >= 1) && (dma_pointer[i].serious_symptoms >= 1)) {
						dma_pointer[i].test_status = 1;
					}
				}
	
		}
		
		// FILE Handler (pointer)
		FILE *fptr;
		// Membuka file "user.txt" dan menambahkan data menggunakan mode "a" (append)
		fptr = fopen("user.txt", "a");
		// Jika file ada maka lanjutkan
		if (fptr != NULL) {
			// Pengulangan untuk input data dari structure ke file user.txt
			for (i = 0; i < dma_size; ++i) {
				fprintf(fptr, "Nama\t\t: %s\n", dma_pointer[i].name);
				fprintf(fptr, "Umur\t\t: %i\n", dma_pointer[i].age);
				fprintf(fptr, "Domisili\t: %s\n", dma_pointer[i].domisili);
				fprintf(fptr, "-=-=-=-=-=-=-=-=-=-=-=-=-=- Info Gejala -=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				fprintf(fptr, "Umum\t\t: %i\n", dma_pointer[i].common_symptoms);
				fprintf(fptr, "Tak Umum\t: %i\n", dma_pointer[i].uncommon_symptoms);
				fprintf(fptr, "Serius\t\t: %i\n", dma_pointer[i].serious_symptoms);
				fprintf(fptr, "-=-=-=-=-=-=-=-=-=-=-=-=-=- Hasil Analisa -=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				if (dma_pointer[i].test_status == 1) {
					fprintf(fptr, "%s sangat disarankan untuk mengambil SWAB Test di rumah sakit terdekat.", dma_pointer[i].name);
				} else if (dma_pointer[i].test_status == 2) {
					fprintf(fptr, "%s berpotensi OTG (Orang Tanpa Gejala) disarankan untuk mengambil SWAB Test\n", dma_pointer[i].name);
					fprintf(fptr, "di rumah sakit/puskesmas terdekat.\n");
				} else if (dma_pointer[i].test_status == 0) {
					fprintf(fptr, "%s tidak memiliki gejala umum dan serius. Mungkin tidak terjangkit\n", dma_pointer[i].name);
					fprintf(fptr, "Namun tetap disarankan untuk menjaga protokol kesehatan dan social distancing.\n");
				}
				fprintf(fptr, "\n");
			}
			// Menutup file jika transfer data sudah selesai 
			fclose(fptr);
		} else {
			// Jika file tidak dibuka maka print pesan eror
			error_message();
			printf("File database tidak berhasil dibuka, Menghentikan program.\n");
			return 1;
		}
		
		// Mengembalikan memori yang dialokasikan kembali ke memori
		free(dma_pointer);
		char answer;
		printf("\n");
		
		//Pengecekan terakhir sebelum menghentikan program
		make_question("\nAnda telah menyelesaikan input data, Apakah anda ingin melanjutkan ke main menu? (Y/N)\n", answer_buffer, sizeof(answer_buffer));
		printf(">> %s", answer_buffer);
		scanf("%s", &answer);
		if (answer == 'Y') goto menu;
	
	return 0;
}

// Membaca isi user.txt secara char by char
void read_file(FILE *fptr) {
	char ch;
	
	do {
		ch = fgetc(fptr);
		putchar(ch);
	} while (ch != EOF);
}
