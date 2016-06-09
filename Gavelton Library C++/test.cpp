#include <iostream>
#include "SearchEngine.h"

using namespace std;

int main()
{
	int option = 1;
	string searchString;
	SearchEngine yahoo;
	vector<Media*> output;

while(option!=5)
{
  cout << endl << "************************************** Library Search **************************************" << endl;
  cout << "Please select the type of search you want to perform by entering the option number:" << endl;
  cout << "1. Search by Call Number" << endl;
  cout << "2. Search by Title" << endl;
  cout << "3. Search by Subject" << endl;
  cout << "4. Search by other" << endl;
  cout << "5. Exit" << endl;
  cin >> option;
  cin.clear();
  cin.ignore();

  switch(option)
  {
	  case 1:
	    cout << "Enter the text to search: " << endl;
	      getline(cin, searchString);
	  output = yahoo.search_by_callNumber(searchString);
	  break;
	  
	  case 2:
	  	    cout << "Enter the text to search: " << endl;
	      getline(cin, searchString);
	  output = yahoo.search_by_title(searchString);
	  break;
	  
	  case 3:
	  	    cout << "Enter the text to search: " << endl;
	      getline(cin, searchString);
	  output = yahoo.search_by_subject(searchString);
	  break;
	  
	  case 4:
	  	    cout << "Enter the text to search: " << endl;
	      getline(cin, searchString);
	  output = yahoo.search_by_other(searchString);
	  break;
	  
	  case 5:
	  return 0;
	  
	  default: 
	  cout << "Incorrect option. Make sure your option is between 1 to 5." << endl;
	  break;

	}
	if(option > 0 && option < 5)
	{
	for(int i = 0;i < output.size();i++)
	{
			output[i]->display();
	} 
	cout << "Number of records = " << output.size() << endl;
}
}
  return 0;
}
