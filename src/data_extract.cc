/*
 * data_extract.cc
 *
 *  Created on: Jul 19, 2023
 *      Author: rao
 */
#include<iostream>
#include"data_extract.hpp"
#include"data_header.hpp"





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
		data_header*dt1;
		dt1 = (data_header*)buff;
		std::string the_msg;

		if(dt1->delimiter == header && dt1->length == (buf_siz-sizeof(data_header)))
		{
			char * message = new char [buf_siz-sizeof(data_header)];
			memcpy(message, buff+sizeof(data_header),buf_siz-sizeof(data_header));
			for(size_t i=0 ;i<dt1->length;i++)
			{
				the_msg+= message[i];
			}
			delete [] message;
			dt1 = nullptr;

		}

		return the_msg;
	}

