

//member 1
#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class capacityExceeded {
public:
	string what() {
		return "Capacity Exceeded";
	})
};
class overDue {
private:
	doube fine;
public:
	overDue(double f) {
		fine = f;
	}
	string what() {
		return "Over Due. Fine: ";
	}
	double getFine() {
		return fine;
	}

};

class Person {
private:
	string name;
	string CNIC;
	string contact;
	int age;
public:
	Person(string n, string c, string con, int a) :
		name(n), CNIC(c), contact(cont), age(a) {
	}
		
	virtual ~Person(){}
	virtual void displayInfo()=0
	string getName() {
		return name;
	}
	string getCNIC() {
		return CNIC;
	}
	string getContact() {
		return contact;
	}
	int getAge() {
		return age;
	}
};

class Student :public Person {
private:
	int rollNo;
	int semester;
	double GPA;
	string enrolledCourses[6];
	int courseCount;
	public
		Student(string n, string c, string con, int a, int r, int s, double g)
		:Person(n, c, cont, a), rollNo(r), semester(s), GPA(g), courseCount(0) {
	}
	void displayInfo(){
		cout << "Student: " << name << " | Roll Np: " << rollNo << " | GPA: " << GPA << " |Semester: " << semester << endl;
	}
	void calculateGrade() {
		if (GPA >= 3.5) {
			cout << "Grade: A" << endl;
		}
		else if (GPA >= 3.0) {
			cout << "Grade: B" << endl;
		}
		else if (GPA >= 2.0) {
			cout << "Grade: C" << endl;
		}
		else {
			cout << "Grade: F" << endl;
		}
		int getRollNo() {
			return rollNo;
		}
		double getGPA() {
			return GPA;
		}
		void setGPA(double g) {
			GPA = g;
		}
		void addCourse(string course) {
			if (courseCount < 6) {
				enrolledCourses[courseCount++] = course;
			}

		}
	};
	class Faculty :public Person {
	private:
		int employeeID;
		string department;
		string designation;
	public:
		Faculty(string n, string c, string con, int a, int eID, string dept, string desig)
			:Person(n, c, cont, a), employeeID(eID), department(dept), designation(desig) {
		}
		void displayInfo() {
			cout << "Faculty: " << name << " | Employee ID: " << employeeID << " | Department: " << department << " | Designation: " << designation << endl;
		}
		int getEmployeeID() {
			return employeeID;
		}
		string getDepartment() {
			return department;
		}
		string getDesignation() {
			return designation;
		}
	};
	class GraduateStudent :public Student {
	private:
		string researchTopic;
		string supervisor;
	public:
		GraduateStudent(string n, string c, string con, int a, int r, int s, double g, string topic, string sup)
			:Student(n, c, cont, a, r, s, g), researchTopic(topic), supervisor(sup) {
		}
		void displayInfo() {
			cout << "Graduate Student: " << name << " | Roll No: " << getRollNo() << " | GPA: " << getGPA() << " | Semester: " << semester << " | Research Topic: " << researchTopic << " | Supervisor: " << supervisor << endl;
		}
		string getResearchTopic() {
			return researchTopic;
		}
		string getSupervisor() {
			return supervisor;
		}
	};

	//member 2







	//member 1
	class LibraryItem {
	private:
		string itemID, title, author;
		int publicationYear;
	public:
		LibraryItem(string id, string t, string a, int year) : itemID(id), title(t), author(a), publicationYear(year) {}
		virtual ~LibraryItem() {}
		virtual void displayInfo() = 0;
		string getItemID() { return itemID; }
		string getTitle() { return title; }
		string getAuthor() { return author; }
		int getPublicationYear() { return publicationYear; }
	};
	class Book :public LibraryItem {
	private:
		string ISBN, genre;
		int copiesAvailable;
	public:
		Book(string id, string t, string a, int year, string isbn, string g, int copies)
			:LibraryItem(id, t, a, year), ISBN(isbn), genre(g), copiesAvailable(copies) {
		}
		void displayInfo() {
			cout << "Book: " << getTitle() << " | Author: " << getAuthor() << " | Year: " << getPublicationYear() << " | ISBN: " << ISBN << " | Genre: " << genre << " | Copies Available: " << copiesAvailable << endl;
		}
		string getISBN() { return ISBN; }
		string getGenre() { return genre; }
		int getCopiesAvailable() { return copiesAvailable; }
		 setCopiesAvailable(int copies) { copiesAvailable = copies; }
		 void checkOut() {
			 if (copiesAvailable > 0) {
				 copiesAvailable--;
			 }
			 else {
				 throw capacityExceeded();
			 }
		 
		 }
		 void returnItem() {
			 copiesAvailable++;
		 }
	};
	class Journal :public LibraryItem {
	private:
		string ISSN;
		int volume, issueNo;
		public
			Journal(string id, string t, string a, int year, string issn, int vol, int issue)
			:LibraryItem(id, t, a, year), ISSN(issn), volume(vol), issueNo(issue) {
		}
		void displayInfo() {
			cout << "Journal: " << getTitle() << " | Author: " << getAuthor() << " | Year: " << getPublicationYear() << " | ISSN: " << ISSN << " | Volume: " << volume << " | Issue No: " << issueNo << endl;
		}
		string getISSN() { return ISSN; }
		int getVolume() { return volume; }
		int getIssueNo() { return issueNo; }
		
	};
	struct issueItem {
		int rollNo;
		string itemID;
	};
	class Library{
	private:
		LibraryItem* catalog[10];
		int itemCount;
		issueItem issuedItems[15];
		int issuedCount;
	public:
		Library() : itemCount(0), issuedCount(0) {}

		~Library() {
			for (int i = 0;i < itemCount;i++) {
				delete catalog[i];
			}
		}
		void addItem(LibraryItem* item) {
			if (itemCount < 20) {
				catalog[itemCount] = item;
				itemCount++;
			}
		}
		void searchByTitle(string title) {
			for (int i = 0;i < itemCount;i++) {
				if (catalog[i]->getTitle() == title) {
					catalog[i]->displayInfo();
					return;
				}
			}
			cout << "Item not found." << endl;
		}
		void saveTofile(string filename) {
			ofstream outFile(filename);
			if (outFile.is_open()) {
				for (int i = 0;i < itemCount;i++) {
					outFile << catalog[i]->getItemID() << "," << catalog[i]->getTitle() << "," << catalog[i]->getAuthor() << "," << catalog[i]->getPublicationYear() << endl;
				}
				outFile.close();
			}
		}

		void loadFromFile(string filename) {
			ifstream inFile(filename);
			if (inFile.is_open()) {
				string line;
				while (getline(inFile, line)) {
					// Parse line and create LibraryItem objects
				}
				inFile.close();
			}
		}
		void issueItemToStudent(int rollNo, string itemID) {
			for (int i = 0;i < itemCount;i++) {
				if (catalog[i]->getItemID() == itemID) {
					try {
						catalog[i]->checkOut();
						issuedItems[issuedCount++] = { rollNo, itemID };
						cout << "Item issued successfully." << endl;
						return;
					}
					catch (capacityExceeded& e) {
						cout << e.what() << endl;
						return;
					}
				}
			}
			cout << "Item not found." << endl;
		}
		void displayIssuedItems() {
			for (int i = 0;i < issuedCount;i++) {
				cout << "Roll No: " << issuedItems[i].rollNo << " | Item ID: " << issuedItems[i].itemID << endl;
			}
		}
	};




