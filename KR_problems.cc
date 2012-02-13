#include<stdio.h>

int any(char*, char*);
char *sequeeze(char*, char*);
short int escape(char*, char*);
short int expand(char*, char*);
void itoa(char*, int);

main(){
	//char s1[] = "Vineet \n Garg	S/O Dharam Pal";
	char s1[] = "-A-F8-9sd-";
	char s2[100] ;

	//printf("\nFirst occurance: %d\n", any(s1, s2) );

	//printf("\n After Sequeezing: %s\n", sequeeze(s1, s2) );
	//expand(s1, s2);
	//printf("\nAfter expanding: %s\n", s2);
	itoa("a", 5);
}


/* This will find a first occurance of any character of s2 in s1 
 * Limitation - because of signed integer return type string shouldn't
   be greater than MAX_INT */

int any(char *s1, char *s2){
	if( !s1 || !s2)
		return -1;

	for(int i=0; s2[i] != '\0'; i++){
		for(int j=0; s1[j] != '\0'; j++)
			if( s1[j] == s2[i])
				return j;
	}

	return -1;
}

/* This will delete each char in s1 that will match with any
 * char in s2
 */
char* sequeeze(char *s1, char *s2){
	if( !s1 || !s2)
		return s1;

	int k=0;

	for(int i=0; s2[i] != '\0'; i++){
		for(int j=0; s1[j] != '\0'; j++){
			if( !(s1[j] == s2[i]) ) {/*if it doesn't match */
				s1[k] = s1[j];
				k++;
			}

		}

		s1[k] = '\0';
		k=0;
	}

	return s1;

}



/* escape(s, t) - It replaces the various escacpe seq in s with the characters they are respresented with and copy the string in t
 * Assumptions - it assumes t has enough space to hold s
 * Return value - short int. 1 on success, 0 on failure
 */

short int escape( char *s, char *t){
	if( !s || !t)
		return 0;
	int j=0;
	for(int i=0; s[i] != '\0'; i++){
		switch(s[i]){
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;

			case '\b':
				t[j++] = '\\';
				t[j++] = 'b';
				break;

			default:
				t[j++] = s[i];
		}
	}

	t[j] = '\0';
	return 1;

}

/* expand(s1, s2) 
 * maintains three states in SHORTHAND - IN, MID & OUT
 * Assumption - assumes that s2 has enough memory to hold the expanded string
 * Return Value - short int. 1 on success 0 on failure
 */

short int expand(char *s1, char *s2){
	if( !s1 || !s2)
		return -1;

	enum SHORTHAND {IN, MID, OUT};
	char first_char;

	SHORTHAND state = OUT; /* initialize the state to OUT */
	int j=0;

	for(int i=0; s1[i] != '\0'; i++){

		if( (s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= '0' && s1[i] <= '9') ){ /* could be the first state or last */
			if( state == OUT){
				state = IN;
				first_char = s1[i];
				s2[j++] = s1[i];
			}

			else if (state == IN){
				first_char = s1[i];
				s2[j++] = s1[i];
			}

			else if (state == MID){
				/* expand from first_char to s[i]*/
				/* lets not consider case such as a-9 */ //TODO
				for(++first_char; ( (s2[j++] = first_char) < s1[i] ); first_char++);
				/* change the state and first char */
				state = IN;
				first_char  = s1[i];
			}

			/*else Don't change the IN state */

			/* store the first_char */
			
		}

		else if( s1[i] == '-'){
			if(state == IN)
				state = MID;
			else if(state == MID){
				state = OUT;
				s2[j++] = '-'; /* because it was initially in MID so it parsed - */
				s2[j++]  = s1[i];
			}
			else {
				state = OUT ; /*redundant */
				s2[j++]  = s1[i];
			}
		}

		else {
			if(state == MID) /* because it already parsed and ignored '-' */
				s2[j++] = '-';

			s2[j++] = s1[i];	

			state = OUT;
		}


	}

	if(state == MID) /* it means it ignored - */
		s2[j++] = '-';


	s2[j] = '\0';

}


void itoa(char *s, int n){
	char a = 0xA+ '0';
	printf("%c\n", a);
}
