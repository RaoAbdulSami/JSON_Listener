#include "conversion.hpp"

Convert::Convert():Convert("EndGame.json")
{

}

Convert::Convert(string Txt) // @suppress("Class members should be properly initialized")
{
	MyFile.open(Txt.c_str(),ios_base::app | ios_base::binary);
}
Convert::~Convert()
{
	MyFile.close();
}
void Convert::send_to_JSon(string msg)
{
	incoming = msg;
	MyFile << incoming;
	MyFile << "\n";
}
