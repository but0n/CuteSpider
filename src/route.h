#ifndef ROUTE_H
#define ROUTE_H

#define STACK_LEN		1024
#define PATH_MAX_LEN	2038

typedef void(*func_handle)(int*);

typedef struct path{
	struct path *hash[90];
	void (*handler)(int*);
} st_path, *pst_path;

extern st_path	stack[STACK_LEN];


int			route(char *c, void (*func)());
func_handle parse(char *token, pst_path this);
void		errorPage(int *fd);

#endif