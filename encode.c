/*
 *
 * PSET 1: Pig Esperanto
 * Kazemi Adachi
 * CPSC 223, Prof James Aspnes
 *
 * A program which translates text into "Pig Esperanto",
 * a language which is derived from "Pig Latin" via "Pig Elvish".
 * 
 * For each input, alphabetical word:
 * 1. Move the first letter to the end.
 * 2. Add the letters "an" to the end of any word of three letters or less,
 *    and "o" to the end of any longer word.
 * 3. Make the new first letter of the word match the case of the old first letter of the word.
 *    Make the letter that was moved lowercase if it is not still the first letter.
 *    Do not change the capitalization of any other letters.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define WORDLEN (3)

int main(int argc, char **argv) {

	// initializations: 
	// c is the character being processed
	// first_letter stores the first alpha character of a word
	// first_letter_capitalization stores the capitalization state of the first letter: 1 for uppercase, 0 for lowercase
	// letter_count stores the number of letters in the current word
	
	char c;
	char first_letter;
	int first_letter_capitalization;
	int letter_count = 0;
	
	while((c = getchar()) != EOF) {
		if(isalpha(c) && letter_count == 0) {			// the character is alphabetical and is the first letter in a word
			// saves the first letter of a word, it's capitalization, and increments the letter count (to 1) for that word
			first_letter = c;
			first_letter_capitalization = isupper(c);
			letter_count++;
		} else if(isalpha(c)) {							// the character is alphabetical, but not the first letter of the word
			letter_count++;
			if(letter_count == 2) {						// if the character is the new first letter in the word, print it in the case-state that the first letter had
				first_letter_capitalization ? putchar(toupper(c)) :	putchar(tolower(c));
			} else {									// else print it without affecting the case
				putchar(c);
			}
		} else {										// non alphabetical characters signal the end of the word
			letter_count == 1 ? putchar(first_letter) : putchar(tolower(first_letter));					// if the word is one letter long, print the first letter as is, else, print the formerly first letter lowercase
			if(letter_count <= WORDLEN) {				// if the word length is three letters or shorter, add 'an' to the end
				putchar('a');
				putchar('n');
			} else {									// else, add 'o' to the end of the word
				putchar('o');
			}
			putchar('c');								// print the non-alphabetical character
			letter_count = 0;							// reset the letter count
		}
	}
	return 0;
}
	