#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // For parsing lines
using namespace std;

void parseCSV(const string&);          //function declaration

int main() {
   parseCSV("students.csv");        //call with filename

   return 0;
}

void parseCSV(const string& filename)
{
   ifstream inFile(filename);    //open the CSV file

   if (!inFile.is_open())           //check if file opened
   {
      cout << "Error: Could not open "
            << filename << endl;
            return;           //exit if filie not found
   }

   string line;
   int lineNum = 0;

   while (getline(inFile, line))
{
   lineNum++;
   stringstream ss(line);
   string field;

   cout << "Row " << lineNum << ": ";

   while (getline(ss, field, ','))
   {
      cout << field << " ";
   }
   cout << endl;
}

   inFile.close();
   cout << "\nTotal rows read: " << lineNum << endl;
}