# Name - Nikhil Gaud
# username - ngaud
from classMedia import Media

class Periodic(Media):
	def __init__(self, callNumb, titl, subj, author, description, publisher, publishing_history, series, notes, related_titles, other_forms_of_title, 
	govt_doc_number):
		Media.__init__(self, callNumb, titl, subj, notes)
		self.author = author
		self.description = description
		self.publisher = publisher
		self.publishing_history = publishing_history
		self.series = series
		self.related_titles = related_titles
		self.other_forms_of_title = other_forms_of_title
		self.govt_doc_number = govt_doc_number
		
	def display(self):
		print ("--------------------------------------------- Periodic ---------------------------------------------")
		Media.display(self)
		print ("Author: %s" % self.author)
		print ("Description: %s" % self.description)
		print ("Publisher: %s" % self.publisher)
		print ("Publishing history: %s" % self.publishing_history)
		print ("Series: %s" % self.series)
		print ("Related titles: %s" % self.related_titles)
		print ("Other forms of title: %s" % self.other_forms_of_title)
		print ("Govt doc number: %s" % self.govt_doc_number)
	
	def compare_other(self, strOther):
		if self.description.find(strOther) != -1 or self.notes.find(strOther) != -1 or self.series.find(strOther) != -1 or self.related_titles.find(strOther) != -1:
			return True
		else:
			return False
	
