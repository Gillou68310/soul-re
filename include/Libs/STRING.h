#ifndef _STRING_H_
#define _STRING_H_

#ifdef TARGET_PSX
size_t strlen(const char *theString);
char *strpbrk(char *string, char *searchedCharacters);
char *strchr(char *str, int character);
#endif

#endif
