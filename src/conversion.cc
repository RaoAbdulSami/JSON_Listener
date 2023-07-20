#include "conversion.hpp"

Convert::Convert()
{

}
Convert::~Convert()
{

}
void Convert::send_to_JSon(int n,string msg)
{
	incoming = msg;
	byts = n;
	ofstream MyFile("EndGame.json",std::ios_base::app );
	for (int i=0;i<byts;i++)
	{
		MyFile << std::hex << (uint8_t)incoming[i]<<" ";
	}
	MyFile << "\t";
	MyFile << byts;
	MyFile.close();
}
