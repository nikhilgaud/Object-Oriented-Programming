# Name - Nikhil Gaud
# username - ngaud
from classMedia import Media

class Book(Media):
	def __init__(self, callNumb, titl, subj, author, description, publisher, city, year, series, notes):
		Media.__init__(self, callNumb, titl, subj, notes)
		self.author = author
		self.description = description
		self.publisher = publisher
		self.city = city
		self.year = year
		self.series = series
		
	def display(self):
		print ("--------------------------------------------- Book ---------------------------------------------")
		Media.display(self)
		print ("Author: %s" % self.author)
		print ("Description: %s" % self.description)
		print ("Publisher: %s" % self.publisher)
		print ("City: %s" % self.city)
		print ("Year: %s" % self.year)
		print ("Series: %s" % self.series)
	
	def compare_other(self, strOther):
		if self.description.find(strOther) != -1 or self.notes.find(strOther) != -1 or self.year.find(strOther) != -1:
			return True
		else:
			return False
	
