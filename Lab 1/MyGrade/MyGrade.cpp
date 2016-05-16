// Lab 1a, MyGrade
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

int main()
{
  //Sohaib Syed, MyGrade
  cout << "Lab 1a, MyGrade\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: CodeBlocks\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  int total;
  int gradeCounter;
  int grade;
  int average;
  char buf[100];

  total = 0;
  gradeCounter = 1;

  while(gradeCounter <= 10)
  {
    cout << "Enter Grade: ";
    cin >> buf;
    grade = atoi(buf);
    total += grade;
    gradeCounter = gradeCounter + 1;
  }
  average = total/gradeCounter;

  cout << "\nThe total of the grades is: " << total << endl;
  cout << "The average of the scores is:" << average << endl;
}
