/*
Name - Nikhil A. Gaud
username - ngaud
*/
#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include <iostream>
#include "stampbuf.h"

class row
{
	private:
	int row_number;
	
	public:
	//row(someint) should flush (that is, sync) the buffer and then set the current column to 1 and set the current row to someint.
	row(int row_num);
	int getCurrentRow() const;
	//void set_row(row_number);
};

std::ostream& operator<<(std::ostream& os, const row& row);
std::ostream& endrow(std::ostream& os);

class stampstream : public std::ostream
{
	public:
	stampstream(int cols, int rows);
	~stampstream();
};

#endif
