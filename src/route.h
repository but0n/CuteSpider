#ifndef ROUTE_H
#define ROUTE_H

#define STACK_LEN		1024
#define PATH_MAX_LEN	2038

typedef struct path{
	struct path *hash[90];
	void (*handler)();
} st_path, *pst_path;

int route(char *c, void (*func)());
void parse(char *token, pst_path this);

#endif