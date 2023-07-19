/*
 * client.hpp
 *
 *  Created on: Jul 19, 2023
 *      Author: wamiq714
 */
#ifndef INC_CLIENT_HPP_
#define INC_CLIENT_HPP_
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string>

class Data_Retrieve
{
	private:
	int CreateSocket = 0,n = 0;
	struct sockaddr_in ipOfServer;
	protected:
		char dataReceived[2048];
	public:
		Data_Retrieve(int port, std::string && ip);
		Data_Retrieve(int port);
		Data_Retrieve();
		void Connection_verify();
		void Full_Data();
		int bits();
		~Data_Retrieve();
};





#endif /* INC_CLIENT_HPP_ */
