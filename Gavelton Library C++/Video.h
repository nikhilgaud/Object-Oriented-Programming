#ifndef VIDEO_H
#define VIDEO_H
#include "Media.h"

using namespace std;

class Video : public Media
{
	private:
	string description, distributor, series, label;
	
	public:
	Video(const string& callNumb, const string& titl, const string& subj, const string& description, const string& distributor, 
	const string& notes, const string& series, const string& label);
	void display() const;
	bool compare_other(const string& strOther) const;
};

#endif
