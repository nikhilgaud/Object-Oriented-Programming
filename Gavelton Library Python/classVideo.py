# Name - Nikhil Gaud
# username - ngaud
from classMedia import Media

class Video(Media):
	def __init__(self, callNumb, titl, subj, description, distributor, notes, series, label):
		Media.__init__(self, callNumb, titl, subj, notes)
		self.description = description
		self.distributor = distributor
		self.series = series
		self.label = label
		
	def display(self):
		print ("--------------------------------------------- Video ---------------------------------------------")
		Media.display(self)
		print ("Description: %s" % self.description)
		print ("Distributor: %s" % self.distributor)
		print ("Series: %s" % self.series)
		print ("Label: %s" % self.label)
	
	def compare_other(self, strOther):
		if self.description.find(strOther) != -1 or self.notes.find(strOther) != -1 or self.distributor.find(strOther) != -1:
			return True
		else:
			return False
	
