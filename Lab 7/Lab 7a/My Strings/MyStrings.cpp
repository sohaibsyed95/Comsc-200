// Lab 7a, Demonstrating the string find member functions
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
  string string1("noon is 12 pm; midnight is not.");
  int location;

  cout << "Original string: \n" << string1
       << "\n\n(find) \"is\" was found at: "<<string1.find("is")
       << "\n(rfind) \"is\" was found at: " << string1.rfind("is");

  location = string1.find_first_of("misop");
  cout << "\n\n(find_first_of) found" << string1[location]
       << "'from the group \"misop\" at "<< location;

  location = string1.find_last_of("misop");
  cout << "\n\n(find_last_of) found " << string1[location] << "'from the group \"misop\" at : " << location;

  location = string1.find_first_not_of( "noi spm");
  cout << "\n\n(find_first_not_of) '" << string1[ location]
       << "' is not contained in \"noi spm\" and was found at : "
       << location;

  location = string1.find_first_not_of("12 noi spm");
  cout << "\n\n(find_first_not_of)'" << string1[location]
       << "' is not contained in \"12noi spm\" and was "
       << "found at: " << location << endl;

  location = string1.find_first_not_of("noon is 12pm: midnight is not.");
  cout << "\nfind_first_not_of(\"noon is 12pm; midnight is not.\")"
       << " returned: " << location << endl;

}
