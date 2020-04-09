#include <iostream>
#include <string>

using namespace std;

const string VOWELS = "aeiou";

string pigLatinify(const string s)
{
    // Must NOT have an empty string.
    if(s.size() == 0)
    {
        return s;
    }
    
    if(s.find("qu") == 0) // Starts with "qu".
    {
        return s.substr(2, s.size()-2) + "-" + s.substr(0, 2) + "ay";
    }
    // str.find() returns string::npos (=-1) if str char/substr is found
    else if(VOWELS.find(s[0]) != string::npos)  // Starts with vowel.
    {
        return s + "-way";
    }
    else
    {
        return s.substr(1, s.size()-1) + "-" + s[0] + "ay";
    }  
}

int main()
{
    string str, pigStr;
    cout << "Enter a string: ";
    getline(cin, str);
    pigStr = pigLatinify(str);
    cout << pigStr << endl;
    return 0;
}

