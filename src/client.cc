#include "client.hpp"

Data_Retrieve::Data_Retrieve():Data_Retrieve(1500,"127.0.0.1")
{

}
Data_Retrieve::Data_Retrieve(int port, std::string && ip)
{
	memset(dataReceived, '0' ,sizeof(dataReceived));
	CreateSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (CreateSocket < 0)
	{
		throw std::runtime_error("Error! Socket Not Created");

	}
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_port = htons(port);
	ipOfServer.sin_addr.s_addr = inet_addr(ip.c_str());
}
Data_Retrieve::Data_Retrieve(int port)
{
	memset(dataReceived, '0' ,sizeof(dataReceived));
	CreateSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (CreateSocket < 0)
	{
		throw std::runtime_error("Error! Socket Not Created");
	}
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_port = htons(port);
	ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
}

		/*void Create(int port)
		{
			memset(dataReceived, '0' ,sizeof(dataReceived));
			CreateSocket = socket(AF_INET, SOCK_STREAM, 0);
			if (CreateSocket < 0)
			{
				printf("Error! Socket Not Created \n");
				while(1);
			}
			ipOfServer.sin_family = AF_INET;
			ipOfServer.sin_port = htons(port);
			ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
		}*/
void Data_Retrieve::Connection_verify()
{
	//connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer));
	if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) < 0)
	{
		throw std::runtime_error("Connection failed due to port and ip problems");
	}
}

int Data_Retrieve::Poll_Server()
{
	n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1);
	if (n > 0)
	{
		return n;
	}
	else
	{
		return -1;
	}
}

char* Data_Retrieve::Get_Buffer()
{
	return &dataReceived[0];
}

Data_Retrieve::~Data_Retrieve()
{
	close(CreateSocket);
}
