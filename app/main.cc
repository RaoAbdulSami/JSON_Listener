#include "client.hpp"

int main()
{
	int bts=0,x=0;
	char* Msg;
	Data_Retrieve Client(1500);
	Client.Connection_verify();
	while(x<400)
	{
		bts = Client.Poll_Server();
		if (bts>0)
		{
			Msg = Client.Get_Buffer();
			for(int i=0 ;i<bts;i++)
			{
				printf("%x ",(uint8_t)Msg[i]);
			}
			printf("\n");
			x++;
		}
	}
	return 0;
}
