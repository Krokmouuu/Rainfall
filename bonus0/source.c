#include <stdlib.h>
#include <string.h>

char	*p(char *str1, char *str2){
	char	buffer[4096];

	puts(str2);
	read(0, buffer, 4096);
	*strchr(buffer, '\n') = 0;
	return (strncpy(str1, buffer, 20));
}

char	*pp(char *buffer){
	char	a[20];
	char	b[20];
	unsigned int len;

	p(a, " - ");
	p(b, " - ");
	strcpy(buffer, a);
	len = strlen(buffer);
	buffer[len] = ' ';
	buffer[len + 1] = 0;
	return (strcat(buffer, b));
}

int main(void){
	char	buffer[42];

	pp(buffer);
	puts(buffer);
	return ;
}
