#ifndef mystr_h
#define mystr_h

#include <stdlib.h>

/* Given a string pointed to by 'str'
put the next word in 'word'. "words" are defined as sequence of
alphabetic characters separated by blanks.
The function must return a pinter to the char after the 'word'
Return NULL if no word was found.
'str' only characters: 'a' - 'z', 'A' - 'Z', and ' '
*/
char * next_word(char *str, char *word);

/* replace all duplicate consecutive blanks with a
single blank character.
*/
void remove_dup_blanks(char *str);

#endif /* mystr_h */
