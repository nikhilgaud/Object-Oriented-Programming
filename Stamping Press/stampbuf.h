/*
Name - Nikhil A. Gaud
username - ngaud
*/
#ifndef STAMPBUF_H
#define STAMPBUF_H
#include <streambuf>
#include "stamp.h"

class stampbuf : public std::streambuf
{
	private:
		char* buf;
		int max_columns, max_rows;
		int currentCol, currentRow;
		
	public:
		stampbuf(int, int);
		//override sync()
		int sync();//empty the buffer, Each character is stamped by the stamping press		
		int overflow(int c);
		void setRow(int row);
		int getRow();
		~stampbuf();
};

#endif
