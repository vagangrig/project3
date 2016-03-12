/*
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * https://www.stackoverflow.com/
 * https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 * Vagan: 2
 * Areesha:
 * Jedidah:
 * Haresh:
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
 vector <string> s;
 string line;

 while(getline(cin, line))
 {
   if(line != "EOF")
     s.push_back(line);
   else
     break;
 }

 //getCharacters
 int chars;
 for (int i = 0; i < s.size(); i++)
 {
  chars += (int) (s[i].length());
 }

 //getLines
 int lines;
 lines = s.size();

 //get Characters "fix" for \n
 chars += lines;

 int uniqueLines;
 vector <string> uniqueLineVector;
 for(int i = 0; i < lines; i++)
 {
  bool passed = true;
  for(int j = 0; j < uniqueLineVector.size(); j++)
  {
   if(s[i].compare(uniqueLineVector[j]) == 0)
   passed = false;
  }
 if(passed)
 uniqueLineVector.push_back(s[i]);
 }
 uniqueLines = uniqueLineVector.size();
}
