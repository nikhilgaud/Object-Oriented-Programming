# Name - Nikhil Gaud
# username - ngaud
from classMedia import Media

class Film(Media):
	def __init__(self, callNumb, titl, subj, director, notes, year):
		Media.__init__(self, callNumb, titl, subj, notes)
		self.director = director
		self.year = year
		
	def display(self):
		print ("--------------------------------------------- Film ---------------------------------------------")
		Media.display(self)
		print ("Director: %s" % self.director)
		print ("Year: %s" % self.year)
	
	def compare_other(self, strOther):
		if self.director.find(strOther) != -1 or self.notes.find(strOther) != -1 or self.year.find(strOther) != -1:
			return True
		else:
			return False
	
