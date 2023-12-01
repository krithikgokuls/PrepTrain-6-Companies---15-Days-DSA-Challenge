/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' denotes the length of the string
*/

#include <unordered_map>

char firstNonRepeatingCharacter(string str) {
  // Map to store frequency of each character
  unordered_map < char, int > freqOfCharacters;

  // Loop to calculate frequency of each character
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];

    // Storing the frequency
    if (freqOfCharacters.find(ch) == freqOfCharacters.end()) {
      freqOfCharacters[ch] = 1;
    } else {
      freqOfCharacters[ch] = freqOfCharacters[ch] + 1;
    }
  }
  // Loop to return the first non-repeating character
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (freqOfCharacters[ch] == 1) {
      return ch;
    }
  }
  // Return first character of string if all are repeating characters
  return str[0];

}
