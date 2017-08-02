#ifndef ROUTE_H
#define ROUTE_H

typedef struct path{
	struct path *hash[90];
	void (*handler)();
} st_path, *pst_path;

#endif