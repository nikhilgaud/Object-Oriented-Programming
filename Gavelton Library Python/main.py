# Name - Nikhil Gaud
# username - ngaud
from classSearchEngine import SearchEngine
import sys

def main():
	option = 1
	yahoo = SearchEngine()
	output = []
	while option!=5:
		print("************************************** Library Search **************************************")
		print("Please select the type of search you want to perform by entering the option number:")
		print("1. Search by Call Number")
		print("2. Search by Title")
		print("3. Search by Subject")
		print("4. Search by other")
		print("5. Exit")
		try:
			option = int(input('Input: '))
		except ValueError:
			print("Incorrect option. Make sure your option is between 1 to 5.\n")
			continue
		
		if option == 1:
			print("\nEnter the text to search: ")
			searchString = input('Input: ')			
			output = yahoo.search_by_callNumber(searchString)
		elif option == 2:
			print("\nEnter the text to search: ")
			searchString = input('Input: ')			
			output = yahoo.search_by_title(searchString)
		elif option == 3:
			print("\nEnter the text to search: ")
			searchString = input('Input: ')			
			output = yahoo.search_by_subject(searchString)
		elif option == 4:
			print("\nEnter the text to search: ")
			searchString = input('Input: ')			
			output = yahoo.search_by_other(searchString)
		elif option == 5:
			return
		else:
			print("Incorrect option. Make sure your option is between 1 to 5.\n")
			
		if (option > 0) and (option < 5):
			for obj in output:
					obj.display()
			print("Number of records = %d\n" % len(output))

if __name__ == "__main__":
    main()
