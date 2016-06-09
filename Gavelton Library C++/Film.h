#ifndef FILM_H
#define FILM_H
#include "Media.h"

using namespace std;

class Film : public Media
{
	private:
	string director, year;
	
	public:
	Film(const string& callNumb, const string& titl, const string& subj, const string& director, 
	const string& notes, const string& year);
	void display() const;
	bool compare_other(const string& strOther) const;
};

#endif
