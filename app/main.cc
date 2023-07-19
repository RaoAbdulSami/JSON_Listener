#include "client.hpp"

int main()
{
	int bts=0;
	Data_Retrieve Client(1500);
	Client.Connection_verify();
	Client.Full_Data();
	bts = Client.bits();
	return 0;
}
