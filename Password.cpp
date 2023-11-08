#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
 */
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
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
  if(phrase.length() == 0){
    return false;
  }
  bool has_upper_case = false;
  bool has_lower_case = false;
  int index = 0;
  while(index < phrase.length()){
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