# Name - Nikhil Gaud
# username - ngaud
from classMedia import Media
from classBook import Book
from classVideo import Video
from classFilm import Film
from classPeriodic import Periodic

class SearchEngine:
	def __init__(self):
		self.__CardCatalog = []
		inputStreamBook = open('book.txt')
		for line in inputStreamBook.readlines():
			#print(line.split("|"))
			parameters = line.split("|")
			objBook = Book(parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5],parameters[6],parameters[7],parameters[8],parameters[9].strip())
			self.__CardCatalog.append(objBook)
		inputStreamBook.close()
		
		inputStreamPeriodic = open('periodic.txt')
		for line in inputStreamPeriodic.readlines():
			parameters = line.split("|")
			objPeriodic = Periodic(parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5],parameters[6],parameters[7],parameters[8],parameters[9],parameters[10],parameters[11])
			self.__CardCatalog.append(objPeriodic)
		inputStreamPeriodic.close()
		
		inputStreamVideo = open('video.txt')
		for line in inputStreamVideo.readlines():
			parameters = line.split("|")
			objVideo = Video(parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5],parameters[6],parameters[7])
			self.__CardCatalog.append(objVideo)
		inputStreamVideo.close()
		
		inputStreamFilm = open('film.txt')
		for line in inputStreamFilm.readlines():
			parameters = line.split("|")
			objFilm = Film(parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5])
			self.__CardCatalog.append(objFilm)
		inputStreamFilm.close()
		
	def search_by_callNumber(self, strCallNumber):
		searchResults = []
		for item in self.__CardCatalog:
			if item.compare_call_number(strCallNumber):
				searchResults.append(item)
		return searchResults
		
	def search_by_title(self, strTitle):
		searchResults = []
		for item in self.__CardCatalog:
			if item.compare_title(strTitle):
				searchResults.append(item)
		return searchResults
		
	def search_by_subject(self, strSubjects):
		searchResults = []
		for item in self.__CardCatalog:
			if item.compare_subject(strSubjects):
				searchResults.append(item)
		return searchResults				
	
	def search_by_other(self, strOther):
		searchResults = []
		for item in self.__CardCatalog:
			if item.compare_other(strOther):
				searchResults.append(item)
		return searchResults
	
