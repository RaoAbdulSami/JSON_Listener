#ifndef INC_CONVERSION_HPP_
#define INC_CONVERSION_HPP_
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Convert
{
	private:
		string incoming;
		int byts;
	protected:
	public:
		Convert();
		~Convert();
		void send_to_JSon(int n,string msg);
};




#endif /* INC_CONVERSION_HPP_ */
