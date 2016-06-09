#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>

using namespace std;

class Media
{
	private:
	string callNumber, title, subjects;
	
	protected:
	string notes;
	
	public:	
	Media(const string& callNumb, const string& titl, const string& subj, const string& notes);
	virtual void display() const;
	bool compare_title(const string& strTitle) const;
	bool compare_call_number(const string& strCallNumber) const;
	bool compare_subject(const string& strSubjects) const;
	virtual bool compare_other(const string& strOther) const;
	virtual ~Media();
};

#endif
