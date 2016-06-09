/*
Name - Nikhil A. Gaud
username - ngaud
*/
#include "stampstream.h"
#include <stdexcept>

int main()
{
	try
	{
		stampstream s(30,10);
		s << "hi th#re planetoid humans" << endrow
		  << "  how's all the fish" << row(5) << "one more";
		s << row(4) << "   two more" << 3.1415;
		s << row(8) << "The quick brown fox jumped over the lazy dog's back.";
		s << row(3) << "the end";
		
		//s << "1" << row(2) << "2" << row(3) << "3";
		//s << "1" << endrow << "2" << endrow << "3";
		
		/*s << "hi th#re plane$toid humans" << endrow
		  << "  how's all the fi!sh" << row(5) << "one more";*/
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0; 
}
