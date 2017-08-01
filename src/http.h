#ifndef HTTP_H
#define HTTP_H

typedef struct path{
	struct path *hash[90];
	void (*handler)();
} st_path, *pst_path;

#endif