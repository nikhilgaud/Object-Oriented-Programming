/*
Name - Nikhil A. Gaud
username - ngaud
*/
#include "stampstream.h"

row::row(int row_num) :  row_number(row_num)
{
	
}

int row::getCurrentRow() const
{
	return row_number;
}

//endrow should flush (that is, sync) the buffer and then set the current column to 1 and add 1 to the current row.
std::ostream& endrow(std::ostream& os)
{
	//set col = 0, row = currentRow + 1
	stampbuf* stampBufPtr = static_cast<stampbuf*>(os.rdbuf());
	stampBufPtr->sync();
	stampBufPtr->setRow(stampBufPtr->getRow() + 1);

	return os;
}

std::ostream& operator<<(std::ostream& os, const row& row)
{
	stampbuf* stampBufPtr = static_cast<stampbuf*>(os.rdbuf());
	stampBufPtr->setRow(row.getCurrentRow());
	return os;
}

stampstream::stampstream(int cols, int rows): std::ostream(new stampbuf(cols, rows))
{

}

stampstream::~stampstream()
{
	delete rdbuf();
}
