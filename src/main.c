#include <stddef.h>
#include <stdio.h>

// define unsigned char (8 bit int) as uint8_t
typedef unsigned char uint8_t;

// parse function definitions (using 2D array and 8 bit int)
void print_braille_from_2d_array(uint8_t character[3][2]);
void parse_braille_from_uint(uint8_t character);

int main() {
	uint8_t A_row_col[3][2] = {
		{1, 0},
		{0, 0},
		{0, 0}
	};

	uint8_t A_8bit = 32;
	uint8_t B_8bit = 40;

	printf("Print Braille of A using 2D array\n");
	printf("===========A==========\n");
	print_braille_from_2d_array(A_row_col);
	
	printf("\n\nPrint Braille of A & B using 8 Bit integer\n");
	printf("===========A==========\n");
	parse_braille_from_uint(A_8bit);

	printf("===========B==========\n");
	parse_braille_from_uint(B_8bit);
	return 0;
}

// function implementations
void parse_braille_from_uint(uint8_t character) {
	int i = 5;
	uint8_t pos = 2;

	// binary representation = 0 0 1 0 0 0 0 0
	uint8_t char_base = 32;

	while (i >= 0) {
		if ((char_base & character) == 32){
			if (pos % 2 == 0) {
				printf("1 ");
			}else {
				printf("1\n");
			}
		}else {
			if (pos % 2 == 0) {
				printf("0 ");
			}else {
				printf("0\n");
			}
		}

		character <<= 1;
		pos++;
		i--;
	}
}

void print_braille_from_2d_array(uint8_t character[3][2]) {
	for (size_t i =0; i < 3; i++) {
		for (size_t j = 0; j < 2; j++) {
			printf("%d ", character[i][j]);
		}
		printf("\n");
	}
}
