#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int totalAge = 0;
	double totalScore = 0;
	int maleCount = 0;
	int femaleCount = 0;
	struct student
	{
		string idNumber;
		string name;
		int age;
		char gender = ' ';
		double score = -1;
		char grade;
	};

	student students[5];

	for(int i = 0; i <= 4; i++)
	{
		cout << "Enter student's id number: ";
		cin >> students[i].idNumber;
		cout << "Enter student's name: ";
		cin >> students[i].name;
		cout << "Enter student's age: ";
		cin >> students[i].age;
		// ensure the user enters M or F
		while(true)
		{
			cout << "Enter student's gender: ";
			cin >> students[i].gender;
			if(students[i].gender == 'M' || students[i].gender == 'F')
				break;
		}
		// ensure the user enters a value btn 0 and 100 inclusive
		while(true)
		{
			cout << "Enter student's score: ";
			cin >> students[i].score;
			if(students[i].score >= 0 && students[i].score <= 100)
				break;
		}
		
		// compute student's grade
		if(students[i].score >= 80)
			students[i].grade = 'A';
		else if(students[i].score >= 70)
			students[i].grade = 'B';
		else if(students[i].score >= 60)
			students[i].grade = 'C';
		else if(students[i].score >= 50)
			students[i].grade = 'D';
		else if(students[i].score >= 40)
			students[i].grade = 'E';
		else
			students[i].grade = 'F';
		
		// computations
		totalAge += students[i].age;
		totalScore += students[i].score;
		if(students[i].gender == 'M')
			maleCount += 1;
		else if(students[i].gender == 'F')
			femaleCount += 1;

		cout << endl << endl;
	}
	
	// write records to file
	fstream file;
	file.open("output.txt", ios::out);
	for(int i = 0; i <= 4; i++)
	{
		file << i+1 << ".  ";
		file << students[i].idNumber << "  ";
		file << students[i].name << "  ";
		file << students[i].age << "  ";
		file << students[i].gender << "  ";
		file << students[i].score << "  ";
		file << students[i].grade << endl;
		
		cout << "Record " << i+1 << " was successfully written to file." << endl;
	}
	file << endl << "Average age: " << totalAge / 5 << endl;
	file << "Average score: " << totalScore / 5 << endl;
	file << "Male count: " << maleCount << endl;
	file << "Female count: " << femaleCount << endl;
	return 0;
}
