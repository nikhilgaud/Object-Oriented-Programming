/*	Name - Nikhil Gaud
* 	username - ngaud
*/
#ifndef STREAMIO_H
#define STREAMIO_H
#include "BufferFile.h"

class StreamIO
{
public:
	StreamIO(std::string search_str, std::string replacement_str, const char* filename);
	StreamIO& get(char& ch_read);
	void put(const char& ch_write);
	bool eof() const;
	void matched_entire_string();
	bool replacing_now() const;
	void matched_partially(int match_count, char ch);

private:
	BufferFile bufferFile;
	int search_start;
	int search_string_count;
	int replacement_string_count;
	std::string search_string;
	std::string replacement_string;
	int replacement_string_length;
	bool got_from_search, got_from_replacement;
};

#endif
