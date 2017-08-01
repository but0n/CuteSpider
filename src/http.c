#include "http.h"
#include <stdio.h>

#define STACK_LEN		1024
#define PATH_MAX_LEN	2038

st_path	stack[STACK_LEN];
long	sp = -1;

#define NEW() do{\
	stack[++sp].handler = NULL;\
	for(unsigned char i = 0; i< 90; i++) {\
		stack[sp].hash[i] = NULL;\
	}\
}while(0);

int route(char *c, void (*func)()) {
	pst_path	this = &stack[0]; // Root of list
	for(unsigned int n = 0; (*c)&&(n < PATH_MAX_LEN); n++) {
		if(this->hash[*c-'!'] == NULL) {
			if(sp+1 < STACK_LEN) {
				NEW();
				this->hash[*c-'!'] = &stack[sp];
			} else {
				printf("Stack Overflow!");
				return 1;
			}
		}
		this = this->hash[*c-'!'];
		c++;
	}
	this->handler = func;
	return 0;
}