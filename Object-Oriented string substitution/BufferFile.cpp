/*	Name - Nikhil Gaud
* 	username - ngaud
*/
#include "BufferFile.h"
#include <unistd.h>

BufferFile::BufferFile(const char* filename, 
	ios_base::openmode mode) : std::fstream(filename, mode), filename(filename), accessor(0), mutator(0), checkEOF(false)
{

}

//This function checks whether the end of file has been reached. If yes, clears the stream and sets checkEOF variable to true
bool BufferFile::clearEOF()
{
	if(std::fstream::eof())
	{
		this->clear();
		return (checkEOF = true);
	}
	else
	{
		return false;
	}
}

//This function is used to do a raw get from the file or a get from the Deque
void BufferFile::get(char& ch_read, bool isRawGet)
{
	//check if raw get
	if(!isRawGet)
	{
		if (!bufferQueue.empty())
		{
			ch_read = bufferQueue.front();
			bufferQueue.pop_front();
		}
		else
		{
			std::fstream::seekg(accessor);
			std::fstream::get(ch_read);
			if(!clearEOF())
			{
				accessor += 1;
			}
		}
	}
	else
	{
		std::fstream::seekg(accessor);
		std::fstream::get(ch_read);
		accessor += 1;
	}
}

//This function is used to write a character to the file.
void BufferFile::put(const char& ch_write)
{
	if(!checkEOF && accessor == mutator)
	{
		char ch;
		this->get(ch, true);
		bufferQueue.push_back(ch);
	}
	std::fstream::seekp(mutator);
	//If end of file is reached, clear the stream and set checkEOF to true
	clearEOF();
	std::fstream::put(ch_write);
	mutator += 1;
	
	/*if (accessor == mutator && (this->tellg()!=-1))
	{
		char ch;
		this->get(ch);
		//bufferQueue.push_back(ch);
		if(int(tellp()) != -1)
		{
			bufferQueue.push_back(ch);
			accessor += 1;
		}
	}
	if (int(tellp()) != -1)
	{
		std::fstream::seekp(mutator);
		std::fstream::put(ch_write);
		mutator += 1;
	}
	else
	{
		std::fstream::clear();
		std::fstream::seekp(mutator);
		std::fstream::put(ch_write);
		std::fstream::setstate(std::ios::eofbit);
		mutator += 1;
	}*/
}

void BufferFile::addToDeque(char ch_read)
{
	bufferQueue.push_back(ch_read);
}

bool BufferFile::eof() const
{
	/*if (std::fstream::eof() && bufferQueue.empty())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	
	if (!bufferQueue.empty())
	{
		return false;
	}
	else
	{
		return checkEOF;
	}
}

BufferFile::~BufferFile()
{
	//closes file
	this->close();
	//truncates at the putter
	truncate(filename.c_str(), mutator);
}
