/*	Name - Nikhil Gaud
* 	username - ngaud
*/
#ifndef BUFFERFILE_H
#define BUFFERFILE_H
#include <fstream>
#include "TrackingDeque.h"

class BufferFile : public std::fstream
{
public:
	BufferFile(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out);
	void get(char& ch_read, bool isRawGet);
	void put(const char& ch_write);
	void addToDeque(char ch_read);
	bool eof() const;
	bool clearEOF();
	~BufferFile();

private:
	std::string filename;
	std::streampos accessor;
	std::streampos mutator;
	TrackingDeque<char> bufferQueue;
	bool checkEOF;
};

#endif
