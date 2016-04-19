#include <iostream>

using namespace std;
int getPositionFirstVowel(string);
int main(int argc, char *argv[]) 
{
	string wordInput = "";
	string pigLatinyParts = "";
	int positionOfFirstVowel = 0;
	
	for (int x = 1; x != 0;)
	{
		cout << "Input word to translate to pig latin (enter 0 to stop): ";
		getline(cin, wordInput);
		positionOfFirstVowel = getPositionFirstVowel(wordInput);
		
		if (positionOfFirstVowel == 0) //if first letter is a vowel
		{
			wordInput += "-way";
			cout <<"\n1Pig Latin version:\n" << wordInput << "\n\n";
		}
		else if (positionOfFirstVowel > 0) //if there is a vowel in the string, but no the first letter
		{
			pigLatinyParts = wordInput.substr(0, (positionOfFirstVowel)) + "ay";
			wordInput += "-" + pigLatinyParts;
			wordInput.erase(0, positionOfFirstVowel);
			cout <<"\n2Pig Latin version:\n" << wordInput << "\n\n";
		}
		else if (positionOfFirstVowel == -1) //if there are no vowels in string
		{
			if (wordInput == "0")
			{
				return 0;
			}
			wordInput += "-way";
			cout << "\n3Pig Latin version:\n" << wordInput << "\n\n";
		}		
		
	}
}
int getPositionFirstVowel(string wordInput)
{
    string vowels = "aAeEiIoOuU";
	int testIfVowel = 0;
	
	for (int x = 0; x < wordInput.length(); ++x)
	{
	    size_t found = vowels.find(wordInput.substr(x, 1));
	    if (found != string::npos)
	    {
	    	//cout << wordInput.substr(0, 1) << "  " << vowels[y] << "\n";
	   		x += 100;
		   	--testIfVowel;
	   	}
		++testIfVowel;
	}
	if (testIfVowel == wordInput.length())
	{
		testIfVowel = -1;
	}
	return testIfVowel;
}
