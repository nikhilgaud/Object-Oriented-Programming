#include "Book.h"

Book::Book(const string& callNumb,const string& titl, const string& subj, const string& author, const string& description, const string& publisher, const string& city, 
	const string& year, const string& series, const string& notes): Media(callNumb, titl, subj, notes), author(author), description(description), 
	publisher(publisher), city(city), year(year), series(series)
{
    /*this->author = author;
    this->description = description;
    this->publisher = publisher;
    this->city = city;
    this->year = year;
    this->series = series;*/
}

void Book::display() const
{
			cout << endl << "--------------------------------------------- Book ---------------------------------------------" << endl;
            Media::display();
            cout << "Author: " << this->author << endl;
            cout << "Description: " << this->description << endl;
            cout << "Publisher: " << this->publisher << endl;
            cout << "City: " << this->city << endl;
            cout << "Year: " << this->year << endl;
            cout << "Series: " << this->series << endl;
}


bool Book::compare_other(const string& strOther) const
{
	if((this->description.find(strOther) !=std::string::npos) || (this->notes.find(strOther) !=std::string::npos)
	|| (this->year.find(strOther) !=std::string::npos))
	{
		return true;
	}
	else
	{
		return false;
	}			
}
