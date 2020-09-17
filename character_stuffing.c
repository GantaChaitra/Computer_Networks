#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char s[30],start,end;
	printf("Enter the starting and ending delimiters: \n");
	scanf("%c",&start);
	scanf(" %c",&end);	
	printf("Enter the message: \n");
	scanf("%s",s);
	int l = strlen(s);
	printf("%c ",start);
	for(int i=0; i<l; i++) {
		if(s[i] == start) {
			printf(" esc ");
		}
		else if(s[i] == end) {
			printf(" esc ");
		}
		
		printf(" %c ",s[i]);
		
	}
	printf(" %c \n",end);
	return 0;
  
}
