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
 * Areesha:2
 * Jedidah: 2
 * Haresh:2
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

 vector <string> wordVector;
 int words = 0;
 for(int i = 0; i < s.size(); i++)
 {
  string cLine;
  string cWord;
  for(int j = 0; j < s[i].length(); j++)
  {
   cLine = s[i];
   if(cLine[j] == ' ' || cLine[j] == '\t')
   {
    if(cWord != "" && cWord != " ")
    {
    wordVector.push_back(cWord);
    words++;
    cWord = "";
    }
   }
   else
   {
    cWord += cLine[j];
   }
  }
  if(cWord != "" && cWord != " ")
  {
   wordVector.push_back(cWord);
   words++;
   cWord = "";
  }
 }

 int uniqueWords;
 vector <string> uniqueWordVector;
 for(int i = 0; i < words; i++)
 {
  bool passed = true;
  for(int j = 0; j < uniqueWordVector.size(); j++)
  {
   if(wordVector[i].compare(uniqueWordVector[j]) == 0)
  passed = false;
  }
  if(passed)
   uniqueWordVector.push_back(wordVector[i]);
 }
 uniqueWords = uniqueWordVector.size();

 cout << lines << " " << words << " " << chars << " " << uniqueLines << " " << uniqueWords << endl;
}