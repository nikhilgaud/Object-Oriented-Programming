/*
Name - Nikhil A. Gaud
username - ngaud
*/
#include "stampbuf.h"

stampbuf::stampbuf(int cols, int rows) : max_columns(cols), max_rows(rows), currentCol(0), currentRow(0),buf(new char[max_columns/2])
{
	//buf = new char[max_columns/2];
	stamping_press::insert_plate(cols, rows);//check whether this sequence matters
	setp(buf, buf + (max_columns/2));
}

int stampbuf::sync()
{
	/////loop on this
	//how do we take buffer[0] and actually cause that character to stamp
	for(char* i = pbase();i < pptr();i++)
	{
		try
		{
			stamping_press::set_die(*i);
		}
		catch(...)
		{
			
		}
		if(isalnum(*i) || *i=='*' || *i=='#')
		{
			try
			{
				stamping_press::stamp(currentCol, currentRow);
				//			++currentCol;
			}
			catch(...)
			{
				//			continue;
			}
		}
		++currentCol;
	}
	setp(buf, buf + (max_columns/2));
	return 0;
	/////
}

int stampbuf::overflow(int c)
{
	sync();
	sputc(c);
	return 0;
}

void stampbuf::setRow(int row)
{
	sync();
	currentCol = 0;//************************CHECK BY SETTING 0/1********************
	currentRow = row;
}

int stampbuf::getRow()
{
	return currentRow;
}


stampbuf::~stampbuf()
{
	sync();
	stamping_press::eject_plate();
	delete buf;
}

