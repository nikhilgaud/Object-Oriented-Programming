#ifndef PERIODIC_H
#define PERIODIC_H
#include "Media.h"

using namespace std;

class Periodic : public Media
{
	private:
	string author, description, publisher, publishing_history, series, 
	related_titles, other_forms_of_title, govt_doc_number;
	
	public:
	Periodic(const string& callNumb, const string& titl, const string& subj, const string& author, const string& description, const string& publisher, const string& publishing_history, 
	const string& series, const string& notes, const string& related_titles, const string& other_forms_of_title, const string& govt_doc_number);
	void display() const;
	bool compare_other(const string& strOther) const;
};

#endif
