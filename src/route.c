#include "route.h"
#include "sock.h"
#include "http.h"
#include <stdio.h>

st_path		stack[STACK_LEN];
long		sp = -1;

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

void parse(int *fd, char *token, pst_path this) {
	if((this->hash[*token-'!'] != NULL) && (*(token+1) != ' ')) {
		parse(fd, token+1, this->hash[*token-'!']);
	} else if(this->hash[*token-'!']->handler != NULL) {
		this->hash[*token-'!']->handler(fd);
	} else {
		errorPage(fd);
	}
}

void errorPage(int *fd) {
	send(*fd, HTTP_RESPONSE(HTTP_STATUS_LINE_NotFound), sizeof(HTTP_RESPONSE(HTTP_STATUS_LINE_NotFound))-1, 0);
	send(*fd, "<html>Page Not Found</html>", sizeof("<html>Page Not Found</html>")-1, 0);
}