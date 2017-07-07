#include "sock.h"
#include <stdio.h>
#include <signal.h>
#include <curl/curl.h>



int main(int argc, char const *argv[]) {
	signal(SIGCHLD,SIG_IGN);
	CURL	*curl = curl_easy_init();
	if(curl!=NULL) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.zhihu.com/people/but0n/activities");
		CURLcode result = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	// int sock_fd = socketServer(HOST_TCP_PORT);
	// if(sock_fd == -1)
	// 	return 1;
	//
	// // Cearte socket for listen
	// while(handleServer(sock_fd));
	return 0;
}