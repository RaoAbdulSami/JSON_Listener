/*
 * data_header.hpp
 *
 *  Created on: Jul 19, 2023
 *      Author: rao
 */

#ifndef INCLUDE_DATA_HEADER_HPP_
#define INCLUDE_DATA_HEADER_HPP_
#include <stdint.h>
#include <array>

struct data_header
		{
			uint64_t delimiter;
			uint32_t type;
			uint32_t length;
		};

#endif /* INCLUDE_DATA_HEADER_HPP_ */
