# Name - Nikhil Gaud
# username - ngaud
class Media:
	def __init__(self, callNumb, titl, subj, notes):
		self.callNumber = callNumb
		self.title = titl
		self.subjects = subj
		self.notes = notes
		
	def display(self):
		print("Call Number: %s" % self.callNumber)
		print ("Title: %s" % self.title)
		print ("Subjects: %s" % self.subjects)
		print ("Notes: %s" % self.notes)
	
	def compare_title(self, strTitle):
		if self.title.find(strTitle) != -1:
		#if strTitle in self.title:
			return True
		else:
			return False
	
	def compare_call_number(self, strCallNumber):
		if self.callNumber.find(strCallNumber) != -1:
		#if strCallNumber in self.callNumber:
			return True
		else:
			return False
	
	def compare_subject(self, strSubjects):
		if self.subjects.find(strSubjects) != -1:
		#if strSubjects in self.subjects:
			return True
		else:
			return False
	
	# def compare_other(self, var strOther):
		# if strTitle in self.title:
			# return true
		# else:
			# return false
	
