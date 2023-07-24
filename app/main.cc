#include "conversion.hpp"
#include "client.hpp"
#include "data_extract.hpp"

int main(int argc , char *argv[])
{
	int bts=0
	char* Msg;
	std::string fetched_msg;
	Data_Retrieve Client(1500);
	Convert Disp;
	data_extract fetch;
	Client.Connection_verify();
	if (argc == 1)
	{
		while(1)
		{
			bts = Client.Poll_Server();
			if (bts > 0)
			{
				Msg = Client.Get_Buffer();
				fetched_msg = fetch.extract_data(bts,Msg);
				Disp.send_to_JSon(fetched_msg);
			}
		}
	}
	else
	{
		for(int i = 0 ; i< stoi(argv[1]) ; i++)
		{
			bts = Client.Poll_Server();
			if (bts > 0)
			{
				Msg = Client.Get_Buffer();
				fetched_msg = fetch.extract_data(bts,Msg);
				Disp.send_to_JSon(fetched_msg);
			}
		}
	}
	return 0;
}