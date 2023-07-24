/*
 * data_extract.hpp
 *
 *  Created on: Jul 19, 2023
 *      Author: rao
 */


#ifndef INCLUDE_DATA_EXTRACT_HPP_
#define INCLUDE_DATA_EXTRACT_HPP_
#include <cstring>
#include"data_header.hpp"

class data_extract :public data_header
{
	protected:
		uint64_t header;

	public:
		data_extract();
		void set_header(unsigned long long int upd_header);
		std::string extract_data(int buf_siz , char *buff);
};
#endif /* INCLUDE_DATA_EXTRACT_HPP_ */
