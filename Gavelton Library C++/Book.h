#ifndef BOOK_H
#define BOOK_H
#include "Media.h"

using namespace std;

class Book : public Media
{
	private:
	string author, description, publisher, city, year, series;
	
	public:
	Book(const string& callNumb, const string& titl, const string& subj, const string& author, const string& description, 
	const string& publisher, const string& city, const string& year, const string& series, const string& notes);
	void display() const;
	bool compare_other(const string& strOther) const;
};

#endif
