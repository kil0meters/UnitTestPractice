#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(const string &phrase){
  if (phrase.size() == 0) return 0;

  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
returns whether the phrase has both at least one upper-case letter and
at least one lower-case letter
*/
bool Password::has_mixed_case(const string &phrase) {
    bool hasLowercase = false;
    bool hasUppercase = false;

    for (char c : phrase) {
        if (c >= 'a' && c <= 'z') hasLowercase = true;
        if (c >= 'A' && c <= 'Z') hasUppercase = true;
    }

    return hasLowercase && hasUppercase;
}
