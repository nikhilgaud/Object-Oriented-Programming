#include "Media.h"

Media::Media(const string& callNumb, const string& titl, const string& subj, const string& notes): callNumber(callNumb), title(titl), 
subjects(subj), notes(notes)
{
    /*this->callNumber = callNumb;
    this->title = titl;
    this->subjects = subj;
    this->notes = notes;*/
}

void Media::display() const
{
    cout << "Call Number: " << this->callNumber << endl;
    cout << "Title: " << this->title << endl;
    cout << "Subjects: " << this->subjects << endl;
    cout << "Notes: " << this->notes << endl;
}

bool Media::compare_title(const string& strTitle) const
{
	if(this->title.find(strTitle) !=std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Media::compare_call_number(const string& strCallNumber) const
{
	if(this->callNumber.find(strCallNumber) !=std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::compare_subject(const string& strSubjects) const
{
	if(this->subjects.find(strSubjects) !=std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Media::compare_other(const string& strOther) const
{
    
}

Media::~Media()
{
	
}
