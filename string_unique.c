#include<stdio.h>
#include<stdlib.h>

short unsigned int has_unique_char(char *str);


/* main test driver */
int main(int argc, char **argv){
	if(argc != 2){
		printf("\n Wrong number of arguments\n");
		exit(0);
	}

	has_unique_char( argv[1])? (printf("Yes this string has duplicate characters\n")): (printf("NO this string has no duplicates\n"));
}


/* this uses extra space of 255 short unsigned int and can process any ASCII char
 * if will not work for any other character set e.g. UNICODE
 * it returns 0 if string has no duplicates other wise it returns 1
 */
short unsigned int has_unique_char(char *str){

	if( !str)
		return 0;

	/* by default zero means no duplicates */
	short unsigned int ascii_array[255] = {0}; /* an array corresponding to each char in ASCII table, initialized to zero */

	for(int i=0; str[i] != '\0'; i++){

		/* if the array already has the char, return */
		if(ascii_array[str[i]] != 0)
			return 1;
		

		/* flag the corresponding position in array */
		ascii_array[str[i]] = 1;
	}
	
	/* we reached here means no duplicate were found */
	return 0;
}
