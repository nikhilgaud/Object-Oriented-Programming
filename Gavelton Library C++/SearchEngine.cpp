#include "SearchEngine.h"

SearchEngine::SearchEngine()
{
	//read book records from book.txt and take in 10 pipe separated fields 
	ifstream book("book.txt");
      while(!getline(book, callNumber,'|').eof())
      {
        getline(book, title,'|');
        getline(book, subjects,'|');
        getline(book, author,'|');
        getline(book, description,'|');
        getline(book, publisher,'|');
        getline(book, city,'|');
        getline(book, year,'|');
        getline(book, series,'|');
        getline(book, notes, '\n');
            Book* objBook = new Book(callNumber, title, subjects, author, description, publisher, city, year, series, notes);
            CardCatalog.push_back(objBook);
      }
      book.close();
      
      //read periodic records from periodic.txt and take in 12 pipe separated fields
      ifstream periodic("periodic.txt");
      while(!getline(periodic, periodic_callNumber,'|').eof())
      {
        getline(periodic, periodic_title,'|');
        getline(periodic, periodic_subjects,'|');
        getline(periodic, periodic_author,'|');
        getline(periodic, periodic_description,'|');
        getline(periodic, periodic_publisher,'|');
        getline(periodic, periodic_publishing_history,'|');
        getline(periodic, periodic_series,'|');
        getline(periodic, periodic_notes,'|');
        getline(periodic, periodic_related_titles,'|');
        getline(periodic, periodic_other_forms_of_title,'|');
        getline(periodic, periodic_govt_doc_number, '\n');
            Periodic* objPeriodic = new Periodic(periodic_callNumber, periodic_title, periodic_subjects, periodic_author, 
            periodic_description, periodic_publisher, periodic_publishing_history, periodic_series, periodic_notes, 
            periodic_related_titles, periodic_other_forms_of_title, periodic_govt_doc_number);
            CardCatalog.push_back(objPeriodic);

      }
      periodic.close();
      
      //read video records from video.txt and take in 8 pipe separated fields
      ifstream video("video.txt");
      while(!getline(video, video_callNumber,'|').eof())
      {
        getline(video, video_title,'|');
        getline(video, video_subjects,'|');
        getline(video, video_description,'|');
        getline(video, video_distributor,'|');
        getline(video, video_notes,'|');
        getline(video, video_series,'|');
        getline(video, video_label, '\n');
            Video* objVideo = new Video(video_callNumber, video_title, video_subjects, video_description, 
            video_distributor, video_notes, video_series, video_label);
            CardCatalog.push_back(objVideo);
	
      }
      video.close();
      
      //read film records from periodic.txt and take in 6 pipe separated fields
      ifstream film("film.txt");
      while(!getline(film, film_callNumber,'|').eof())
      {
        getline(film, film_title,'|');
        getline(film, film_subjects,'|');
        getline(film, film_director,'|');
        getline(film, film_notes,'|');
        getline(film, film_year, '\n');
            Film* objFilm = new Film(film_callNumber, film_title, film_subjects, film_director, film_notes, film_year);
            CardCatalog.push_back(objFilm);

      }
      film.close();
}

vector<Media*> SearchEngine::search_by_callNumber(const string& strCallNumber) const
{
	vector<Media*> searchResults;
	for(std::vector<Media*>::const_iterator it = CardCatalog.begin(); it != CardCatalog.end(); ++it)
	{
		if((*it)->compare_call_number(strCallNumber))
		{
			searchResults.push_back(*it);
		}
	}
	return searchResults;
}

vector<Media*> SearchEngine::search_by_title(const string& strTitle) const
{
	vector<Media*> searchResults;
	for(std::vector<Media*>::const_iterator it = CardCatalog.begin(); it != CardCatalog.end(); ++it)
	{
		if((*it)->compare_title(strTitle))
		{
			searchResults.push_back(*it);
		}
	}
	return searchResults;
}

vector<Media*> SearchEngine::search_by_subject(const string& strSubjects) const
{
	vector<Media*> searchResults;
	for(std::vector<Media*>::const_iterator it = CardCatalog.begin(); it != CardCatalog.end(); ++it)
	{
		if((*it)->compare_subject(strSubjects))
		{
			searchResults.push_back(*it);
		}
	}
	return searchResults;
}

vector<Media*> SearchEngine::search_by_other(const string& strOther) const
{
	vector<Media*> searchResults;
	for(std::vector<Media*>::const_iterator it = CardCatalog.begin(); it != CardCatalog.end(); ++it)
	{
		if((*it)->compare_other(strOther))
		{
			searchResults.push_back(*it);
		}
	}
	return searchResults;
}

SearchEngine::~SearchEngine()
{
	for(std::vector<Media*>::iterator it = CardCatalog.begin(); it != CardCatalog.end(); ++it)
	{
		delete(*it);
	}
}
