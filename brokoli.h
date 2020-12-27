void error_message() {
	printf("\nTerjadi kesalahan pada program:\n");
}

bool check_input_validity(char input[2]) {
	bool valid = true;
	fgets(input, sizeof(input), stdin);
	int length = strlen(input);
	while ((length > 0) && (isspace(input[length - 1]))) {					// Mengecek apakah ada whitespace diantara input
		length--;															// Kurangkan panjang length jika terdapat whitespace
	}
	
	if (length > 0) {
		int i;
		for (i = 0; i < length; ++i) {
			if (!isdigit(input[i])) {										// Jika tidak, maka set variabel boolean ke false dan break dari loop
				valid = false;
				break;
			}
		}
	}
	
	return valid;
}

int make_question(const char *question, char *answer, const size_t answer_length) {
	int input = 1;
	
	printf("%s", question);
	
	fflush(stdin);
	
	if (fgets(answer, answer_length, stdin) == NULL) {
		input = 0;
	}
	
	return input;
}

void main_menu() {
	system("cls");
	printf("-=-=-=-=-=-=- Proyek Akhir ProgDas -=-=-=-=-=-=-=\n");
	printf("Harap input nomor berikut ini untuk akses\n");
	printf("fitur-fitur di dalam program ini.\n");
	printf("\n");
	printf("1. Input Data\n");
	printf("2. Lihat Data\n");
	printf("3. Bantuan Penggunaan\n");
	printf("4. Tentang Kelompok\n");
	printf("0. Exit Program\n");
	printf("-=-=-=-=-=-=- Proyek Akhir ProgDas -=-=-=-=-=-=-=\n");
}

void print_help() {
	system("cls");
	printf("Program ini ditujukan untuk menganalisis gejala user untuk\n");
	printf("mendapatkan hasil apakah user memerlukan tes SWAB atau tidak.\n");
	printf("Pembuatan program ini berdasarkan data yang didapatkan dari Kemenkes\n");
	printf("dan WHO.\n");
	printf("User dapat memasukkan data beberapa kasus sekaligus dan data akan\n");
	printf("tersimpan di dalam database 'user.txt'.\n");
	printf("Saat menjawab pertanyaan harap gunakan Y atau N (case sensitive).");
}

void print_credits() {
	system("cls");
	printf("Program ini dibuat oleh Kelompok Brokoli:\n");
	printf("Aleandro Farrel Rivaldi / 2006577271\n");
	printf("Josephus Daniel A. R / 2006577284\n");
	printf("M. Darrel Tristan / 2006577302\n");
	printf("Steven Yosua S. / 2006577290");
}
