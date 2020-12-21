void error_message() {
	printf("\nTerjadi kesalahan pada program:\n");
}

int check_user_test_status(const char *answer, int common, int uncommon, int serious) {
	int status = 0;
	// write algorithms here
	
	return status;
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
	printf("-=-=-=-=-=-=- <Program Name> -=-=-=-=-=-=-=\n");
	printf("Tolong input nomor berikut ini untuk akses\n");
	printf("fitur-fitur di dalam program ini.\n");
	printf("\n");
	printf("1. Input Data\n");
	printf("2. Lihat Data\n");
	printf("-=-=-=-=-=-=- <Program Name> -=-=-=-=-=-=-=\n");
}
