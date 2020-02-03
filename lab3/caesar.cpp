/* COMP11
 * Spring 2017
 * Lab 3 - Caesar Cipher
 * Starter Code */

#include <iostream> 
#include <string> 
using namespace std; 

//function prototype
string encrypt (string, int);

int main()
{
	// Variables for the original message,
	// encrypted message, and shift value 
    string message, encr_message;  
    int shift; 

    cout << "Please enter a message: "; 
	cin >> message;

    cout << "Please enter a shift.\n";
    cin >> shift; 

	// Validate the shift to be > 0
    while (shift < 1)
    {
        cout << "Shift must be > 0.\n";
        cout << "Please enter again. \n"; 
        cin >> shift; 
    }

	// Call the function to encrypt the
	// original message and report
    encr_message = encrypt(message, shift); 

    cout << "\nEncoded message: " 
		 << encr_message << "\n\n"; 

    return 0;
}

string encrypt (string message, int shift)
{
  int len = message.length();
  for (int i = 0; i < len; i++)
    {
      message[i] = message[i] + shift;
      while (message[i] > 122)
	  message[i] = message[i] - 26;
    }
  return message;
}

/*

//EXTRA CREDIT 1

#include <iostream> 
#include <string> 
using namespace std; 

//function prototype
string encrypt (string, int);

int main()
{
	// Variables for the original message,
	// encrypted message, and shift value 
    string message, encr_message;  
    int shift; 

    cout << "Please enter a an encrypted message: "; 
	cin >> message;

    cout << "Please enter a shift.\n";
    cin >> shift; 

	// Validate the shift to be > 0
    while (shift < 1)
    {
        cout << "Shift must be > 0.\n";
        cout << "Please enter again. \n"; 
        cin >> shift; 
    }

	// Call the function to encrypt the
	// original message and report
    encr_message = encrypt(message, shift); 

    cout << "\nEncoded message: " 
		 << encr_message << "\n\n"; 

    return 0;
    }

string encrypt (string message, int shift)
{
  int len = message.length();
  for (int i = 0; i < len; i++)
    {
      message[i] = message[i] - shift;
      while (message[i] < 97)
	  message[i] = message[i] + 26;
    }
  return message;
}
*/
