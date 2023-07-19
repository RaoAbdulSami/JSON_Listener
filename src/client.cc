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
		printf("Error! Socket Not Created \n");
		while(1);
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
		printf("Error! Socket Not Created \n");
		while(1);
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
	if(connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
	{
		printf("Connection failed due to port and ip problems\n");
		while(1);
	}
}
void Data_Retrieve::Full_Data()
{
	while((n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1)) > 0)
	{
		dataReceived[n]=0;
		for(int i =0 ;i<n;i++)
		{
			printf("%x ",(uint8_t)dataReceived[i]);
		}
		printf("\n");
	}
}
int Data_Retrieve::bits()
{
	n = read(CreateSocket, dataReceived, sizeof(dataReceived)-1);
	return n;
}
Data_Retrieve::~Data_Retrieve()
{
	close(CreateSocket);
}
