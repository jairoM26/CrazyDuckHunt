/*
 * Client.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#include "Client.h"


int Client::_SendPort = 0;
char* Client::_IP;
LinkedList<string>* Client::messages_list;
pthread_mutex_t Client::mutex = PTHREAD_MUTEX_INITIALIZER;

Client::Client(char* pIP,int pPort) {
	// TODO Auto-generated constructor stub
	_SendPort = pPort;
	_IP = pIP;
	messages_list = new LinkedList<string>();
	pthread_t hilo;
	pthread_create(&hilo,0,Client::threadSendToPort,(void*)this);
}

Client::~Client() {
	// TODO Auto-generated destructor stub
	delete messages_list;

}


void* Client::threadSendToPort(void* pData){
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	server = gethostbyname(_IP);
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
			(char *)&serv_addr.sin_addr.s_addr,
	         server->h_length);
	serv_addr.sin_port = htons(_SendPort);
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	while(true){
		sleep(0.3);

		bzero(buffer,256);
		//fgets(buffer,255,stdin);
		while(messages_list->getLen()>0){
			pthread_mutex_unlock(&mutex);
			const char *cstr = messages_list->getHead()->getData().c_str();
			//const char* data = _MessagesList->getHead()->getData().c_str();
			n = write(sockfd, cstr ,strlen(cstr));
			if (n < 0)
				error("ERROR writing to socket");
			cout<<"El mensaje a enviado: "<<messages_list->getHead()->getData()<<"\n";
			//n = read(sockfd,buffer,255);
			//cout<<"El mensaje a recibido: "<<buffer<<"\n";
			messages_list->deleteData(messages_list->getHead()->getData());
			pthread_mutex_unlock(&mutex);
		}

		bzero(buffer,256);
		if (n < 0)
			error("ERROR reading from socket");
			//printf("%s\n",buffer);

	}
	close(sockfd);
	pthread_exit(NULL);
}

void Client::error(const char *msg)
{
    perror(msg);
    exit(1);
}

void Client::receiveMessage(string pMsj){
	pthread_mutex_unlock(&mutex);
	messages_list->insertData(pMsj);
	pthread_mutex_unlock(&mutex);
}

