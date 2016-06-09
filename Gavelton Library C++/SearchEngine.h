#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include "Book.h"
#include "Periodic.h"
#include "Video.h"
#include "Film.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class SearchEngine
{
	private:
	vector<Media*> CardCatalog;
	string callNumber, title, subjects, author, description, publisher, city, year, series, notes;
	string film_callNumber, film_title, film_subjects, film_director, film_notes, film_year;
	string video_callNumber, video_title, video_subjects, video_description, video_distributor, video_notes, video_series, 
	video_label;
	string periodic_callNumber, periodic_title , periodic_subjects, periodic_author, periodic_description, periodic_publisher, 
	periodic_publishing_history, periodic_series, periodic_notes, periodic_related_titles, periodic_other_forms_of_title, periodic_govt_doc_number;

	
	public:
	SearchEngine();
	vector<Media*> search_by_callNumber(const string& strCallNumber) const;
	vector<Media*> search_by_title(const string& strTitle) const;
	vector<Media*> search_by_subject(const string& strSubjects) const;
	vector<Media*> search_by_other(const string& strOther) const;
	~SearchEngine();
};

#endif
