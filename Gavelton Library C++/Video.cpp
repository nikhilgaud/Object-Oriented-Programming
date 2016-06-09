#include "Video.h"

Video::Video(const string& callNumb,const string& titl, const string& subj, const string& description, const string& distributor, 
	const string& notes, const string& series, const string& label): Media(callNumb, titl, subj, notes), description(description), 
	distributor(distributor), series(series), label(label)
{
	
}

void Video::display() const
{
	cout << endl << "--------------------------------------------- Video ---------------------------------------------" << endl;
            Media::display();
            cout << "Description: " << this->description << endl;
            cout << "Distributor: " << this->distributor << endl;
            cout << "Series: " << this->series << endl;
            cout << "Label: " << this->label << endl;
}


bool Video::compare_other(const string& strOther) const
{
	if((this->description.find(strOther) !=std::string::npos) || (this->notes.find(strOther) !=std::string::npos)
	|| (this->distributor.find(strOther) !=std::string::npos))
	{
		return true;
	}
	else
	{
			return false;
	}
}
