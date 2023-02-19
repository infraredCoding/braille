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
	uint8_t J_8bit = 28;

	uint8_t alphabets[26] = {
		32, 40, 48, 52, 36, 56, 60,
	//   a   b   c   d   e   f   g
		44, 24, 28, 34, 42, 50, 54,  
	//   h   i   j   k   l   m   n
	    38, 58, 62, 46, 26, 30, 35,
	//   o   p   q   r   s   t   u
	    43, 29, 51, 55, 39
	//   v   w   x   y   z
	};

	printf("Print Braille of A using 2D array\n");
	printf("===========A==========\n");
	print_braille_from_2d_array(A_row_col);
	

	printf("\n\nPrint Braille of alphabets using 8 Bit integer\n");

	for (size_t i = 0; i < 26; i++) {
		printf("\nCharacter: %c\nBraille:\n", (char) (97 + i));
		parse_braille_from_uint(alphabets[i]);
	}	

	return 0;
}

// function implementations
void parse_braille_from_uint(uint8_t character) {
	uint8_t pos = 2;

	// binary representation =  0 0  1   0  0  0  0  0
	uint8_t char_base[6] = {        32, 16, 8, 4, 2, 1       };

	for(size_t i = 0; i < 6; i++) {
		if ((char_base[i] & character) == char_base[i]){
			if (i % 2 == 0) {
				printf("1 ");
			}else {
				printf("1\n");
			}
		}else {
			if (i % 2 == 0) {
				printf("0 ");
			}else {
				printf("0\n");
			}
		}
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
