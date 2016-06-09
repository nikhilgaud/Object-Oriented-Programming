#include "Periodic.h"

Periodic::Periodic(const string& callNumb,const string& titl, const string& subj, const string& author, const string& description, 
	const string& publisher, const string& publishing_history, const string& series, const string& notes, 
	const string& related_titles, const string& other_forms_of_title, const string& govt_doc_number): Media(callNumb, titl, subj, notes), 
	author(author), description(description), publisher(publisher), publishing_history(publishing_history), series(series), 
	related_titles(related_titles), other_forms_of_title(other_forms_of_title), govt_doc_number(govt_doc_number)
{

}

void Periodic::display() const
{
	cout << endl << "--------------------------------------------- Periodical ---------------------------------------------" << endl;
            Media::display();
            cout << "Author: " << this->author << endl;
            cout << "Description: " << this->description << endl;
            cout << "Publisher: " << this->publisher << endl;
            cout << "Publishing history: " << this->publishing_history << endl;
            cout << "Series: " << this->series << endl;
            cout << "Related titles: " << this->related_titles << endl;
            cout << "Other forms of title: " << this->other_forms_of_title << endl;
            cout << "Govt doc number: " << this->govt_doc_number << endl;
}


bool Periodic::compare_other(const string& strOther) const
{
	if((this->description.find(strOther) !=std::string::npos) || (this->notes.find(strOther) !=std::string::npos)
	|| (this->series.find(strOther) !=std::string::npos) || (this->related_titles.find(strOther) !=std::string::npos))
	{
		return true;
	}
	else
	{
		return false;
	}
}
