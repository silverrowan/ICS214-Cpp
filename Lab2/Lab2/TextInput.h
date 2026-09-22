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

/// <summary>
/// In addition to standard validation of above function getIntFromUser()
/// checks that the integer is within a specified range. 
/// </summary>
/// <param name="min">smallest acceptable integer (inclusive)</param>
/// <param name="max">largest acceptable integer (inclusive)</param>
/// <returns>int of user response</returns>
int getIntFromUserInRange(int min, int max);

/// <summary>
/// Prompts user with param prompt, and validates response is a valid integer.
/// </summary>
/// <param name="prompt">String to prompt the user with</param>
/// <returns>int of user response</returns>
int promptUserForInt(std::string prompt);

/// <summary>
/// Prompts user with param prompt, and validates response is both: 
/// a valid integer, and within specified range.
/// </summary>
/// <param name="prompt">String to prompt the user with</param>
/// <param name="min">Lowest acceptable int value</param>
/// <param name="max">Greatest acceptable int value</param>
/// <returns>int of user response</returns>
int promptUserForIntInRange(std::string prompt, int min, int max);

//std::string promptUserForString(std::string prompt);

#endif // !TEXTINPUT_H