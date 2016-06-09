/*	Name - Nikhil Gaud
* 	username - ngaud
*/
#include "StreamIO.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <oldstring> <newstring> <filename>" << std::endl;
		return 1;
	}
	std::string search_string = argv[1];
	std::string replacement_string = argv[2];
	int search_length = search_string.length();
	StreamIO streamsource(search_string, replacement_string, argv[3]);

	int match_count = 0;
	char ch;
	while (!streamsource.get(ch).eof())
	{
 		if (!streamsource.replacing_now() && ch == search_string[match_count])
		{
			++match_count;
			if (match_count < search_length)
			{
				continue;
			}
		}
		if (match_count == search_length)
		{
			//getting characters from replacement string
			streamsource.matched_entire_string();
			match_count = 0;
		}
		else if (match_count > 0)
		{
			//getting characters from the search string
			streamsource.matched_partially(match_count, ch); //ch is our pushback
			match_count = 0;
		}
		else
		{
			streamsource.put(ch);
		}
	}

	return 0;
}
