#include "Password.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
constructor sets the default password to "ChicoCA-95929"
*/
Password::Password(){
  set("ChicoCA-95929");
}

/*
receives a password and sets the latest in pass_history to it if and only
if it meets all criteria:
  1. The password is at least 8 letters long
  2. It has no more than 3 of the same leading characters
  3. It has mixed case (at least one upper case and at least one lower case)
  4. It was not a previous password in the history
*/
void Password::set(string phrase){
  if((int)phrase.length() >= 8 && count_leading_characters(phrase) <= 3 && has_mixed_case(phrase)){
    for(int i = 0; i < (int)pass_history.size(); i++){
      if(pass_history[i] == phrase){
        return;
      }
    }
    pass_history.push_back(phrase);
  }
}

/*
receives a string and authenticates it against the latest password in the
pass_history, returning true for an exact match or false when it does not match
or if a password has not been set.
*/
bool Password::authenticate(string phrase){
  if(pass_history[(int)pass_history.size()-1] == phrase){
    return true;
  }
  return false;
}

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
 */
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  while( index < (int)phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  if(repetition > 0){
    repetition++;
  }
  return repetition;
}

/*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
 */
bool Password::has_mixed_case(string phrase) {
  if((int)phrase.length() == 0){
    return false;
  }
  bool has_upper_case = false;
  bool has_lower_case = false;
  int index = 0;
  while(index < (int)phrase.length()){
    if(phrase[index] >= 'A' && phrase[index] <= 'Z'){
      has_upper_case = true;
    }
    if(phrase[index] >= 'a' && phrase[index] <= 'z'){
      has_lower_case = true;
    }
    index++;
  }
  if(has_upper_case && has_lower_case){
    return true;
  }
  return false;
}

// Adams Code
// bool Password::has_mixed_case(string phrase){
//   bool is_mixed_case = false;
//   if(phrase.length() == 0){
//     return false;
//   }
//   int index = 0;
//   while( index < phrase.length()-1){
//     if(isupper(phrase[index]) && islower(phrase[index+1])){
//         is_mixed_case = true;
//     }
//     if(islower(phrase[index]) && isupper(phrase[index+1])){
//       is_mixed_case = true;
//     }
//       index++;
//   }
//   return is_mixed_case;

// }


// Buffardi Code
// bool Password::has_mixed_case(string pass){
//   bool lower = false;
//   bool upper = false;
//   for(int i = 0; i < pass.size(); i++){
//     if( pass[i] >= 'A' && pass[i] <= 'Z' ){
//       upper = true;
//     }
//     else if( pass[i] < 'z'){
//       lower = true;
//     }
//   }
//   return upper && lower;
// }