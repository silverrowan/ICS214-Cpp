//HEADER GUARDS
#ifndef TEXTINPUT_H
#define TEXTINPUT_H

// Clears all characters remaining in the stream buffer
// input parameters: none; output: none
void clearExcessCharacters();

// Collects a user response within the terminal and checks
// the response for a valid integer. Outputs message to 
// terminal and repeats if no valid integer provided.
// NOTE: does not include the prompt to the user
// input parameters: none; output: int of user response
int getIntFromUser();

// In addition to standard validation of above function getIntFromUser()
// checks that the integer is within a valid range, changes response when
// integer overflows.
// input parameters: int min - smallest acceptable integer (inclusive)
//                  int max - largest acceptable integer (inclusive)
// output: int of user response
int getIntFromUserInRange(int min, int max);

int promptUserForInt(std::string prompt);

//std::string promptUserForString(std::string prompt);

#endif // !TEXTINPUT_H