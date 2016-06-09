#include "Film.h"

Film::Film(const string& callNumb,const string& titl, const string& subj, const string& director, 
	const string& notes, const string& year): Media(callNumb, titl, subj, notes), director(director), year(year)
{

}

void Film::display() const
{
	cout << endl << "--------------------------------------------- Film ---------------------------------------------" << endl;
            Media::display();
            cout << "Director: " << this->director << endl;
            cout << "Year: " << this->year << endl;
}


bool Film::compare_other(const string& strOther) const
{
	if((this->director.find(strOther) !=std::string::npos) || (this->notes.find(strOther) !=std::string::npos)
	|| (this->year.find(strOther) !=std::string::npos))
	{
		return true;
	}
	else
	{
			return false;
	}
}
