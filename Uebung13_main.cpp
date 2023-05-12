#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Student.h"
 
using namespace std;
 
int main()
{
	string fname = "students.csv";
 
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
	vector<Student> Studenten;
	vector<string> Matrikelnummern;
	for(int i=0; i < content.size(); i++)
	{
		string Vorname = content[i][1];
		string Nachname = content[i][2];

		if ( std::find(Matrikelnummern.begin(), Matrikelnummern.end(), content[i][0]) == Matrikelnummern.end())
		{
			Studenten.push_back(Student(content[i][0], Vorname, Nachname, 0.00));
			Matrikelnummern.push_back(content[i][0]);
		}
	} 

	for(int i = 0; i < Studenten.size(); i++)
	{
		for(int j = 0; j < content.size();j++)
		{
			if(content[j][0] == Studenten[i].getMatrikelNr())
			{
				Studenten[i].VorlesungsNote(stod(content[j][4]));
			}
		}
	}

	for(int i = 0; i < Studenten.size(); i++)
	{
		if(Studenten[i].getSchnitt() >= 5.0)
		{
			Studenten.erase(Studenten.begin()+i);
		}
	}
	for(int i = 0; i < Studenten.size(); i++)
	{
		Studenten[i].print();
	}
	return 0;
}