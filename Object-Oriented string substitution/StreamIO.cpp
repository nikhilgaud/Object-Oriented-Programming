/*	Name - Nikhil Gaud
* 	username - ngaud
*/
#include "StreamIO.h"

StreamIO::StreamIO(std::string search_str, std::string replacement_str, const char* filename) 
: bufferFile(filename, std::fstream::ios_base::in | std::fstream::ios_base::out), search_start(0), search_string_count(0), 
replacement_string_count(0), search_string(search_str), replacement_string(replacement_str)
{

}

bool StreamIO::replacing_now() const
{
	//return got_from_replacement;
	return (((replacement_string_count > 0) || got_from_replacement)? true : false);
}

void StreamIO::matched_entire_string()
{
	replacement_string_count = replacement_string_length = replacement_string.length();
}

bool StreamIO::eof() const
{
	return (got_from_search || got_from_replacement)? false : bufferFile.eof();
}

StreamIO& StreamIO::get(char& ch_read)
{
	if (replacement_string_count > 0)
	{
		//get character from replacement string
		ch_read = replacement_string[replacement_string_length - replacement_string_count];
		replacement_string_count--;
		got_from_replacement = true;
	}
	else if(search_string_count > 0)
	{
		//get character from search string,
		ch_read = search_string[replacement_string_length - search_string_count];
		search_string_count--;
		got_from_search = true;
	}	
	else
	{
		got_from_search = got_from_replacement = false;
		bufferFile.get(ch_read, false);
	}
	return *this;
}

void StreamIO::matched_partially(int match_count, char ch)
{
	if (got_from_search)
	{
		++search_start;
	}
	else
	{
		search_start = 0;
		replacement_string_length = match_count;
		bufferFile.addToDeque(ch);
	}
	bufferFile.put(search_string[search_start]);
	search_string_count = replacement_string_length - 1 - search_start;
}

void StreamIO::put(const char& ch_write)
{
	bufferFile.put(ch_write);
}
