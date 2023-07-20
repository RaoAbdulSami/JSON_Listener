/*
 * data_extract.cc
 *
 *  Created on: Jul 19, 2023
 *      Author: rao
 */
#include<iostream>
#include"data_extract.hpp"
#include"data_header.hpp"


//data_extract::data_extract():data_extract(0,0){}

data_extract::data_extract()
	{
		header = 0xDEADBEEFBEEFFEED;
	}
void data_extract::set_header(unsigned long long int upd_header)
	{
		header = upd_header;
	}


std::string data_extract:: extract_data(int buf_siz , char *buff)
	{
		data_header dt1;
		std::string the_msg;
		memcpy(&dt1 , buff, sizeof(data_header));
		if(dt1.delimiter == header && dt1.length == (buf_siz-sizeof(dt1)))
		{
			char * message = new char [buf_siz-sizeof(dt1)];
			memcpy(message, buff+sizeof(dt1),buf_siz-sizeof(dt1));
			for(size_t i=0 ;i<dt1.length;i++)
			{
				std::cout<< message[i];
				the_msg+= message[i];
			}
			delete [] message;

		}

		return the_msg;
	}

