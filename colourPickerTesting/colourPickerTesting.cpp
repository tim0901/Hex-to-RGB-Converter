// colourPickerTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
int red;
int green;
int blue;
std::string initArr[6];
std::string compareArr[23]{ "0", "1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","A","B","C","D","E","F" };
int btenArr[6]{};
int goForever = 1;
int uncalculated = 1;
int main()
{
while (goForever == 1)
{
restartLabel:

	uncalculated = 1;
	red = 0;
	green = 0;
	blue = 0;
	while (uncalculated == 1)
	{
		std::cout << "Please enter a HEX colour: ";
		for (int h = 0; h < 6; h++)
		{
			initArr[h] = "0";
			btenArr[h] = 0;
		}
		std::string INPUT("placeholder");
		std::cin >> INPUT;

		if (INPUT.length() == 6)
		{
			int n = 0; //digit number - 1

			for (unsigned i = 0; i < INPUT.length(); ++i) {
				initArr[n] = INPUT.at(i);

				//std::cout << initArr[n] << std::endl;
				for (unsigned j = 16; j < 22; ++j) {
					if (initArr[n] == compareArr[j])
					{
						//std::cout << initArr[n];
						initArr[n] = compareArr[j - 6];
						//std::cout << " has been changed to: " << initArr[n] << std::endl;
					}
				}
				bool valueFound(false);
				for (unsigned k = 0; k < 16; ++k) {
					//std::cout << "k = " << k << std::endl;
					bool equalValue(initArr[n] == compareArr[k]);

					//std::cout << "Bool = " << equalValue <<std::endl;
					if (equalValue == true) {
						btenArr[n] = (k);
						//std::cout << initArr[n] << " is valid." << std::endl;
						//std::cout <<"Value " << n+1 << " in the array is: " << initArr[n] << std::endl;
						valueFound = true;
					}
					if (valueFound == false && k == 15)
					{
						std::cout << "Digit " << n + 1 << " is invalid." << std::endl << "Returning to start." << std::endl << std::endl;
						goto restartLabel;

					}
				}
				++n;
			}
			/*for (unsigned l = 0; l < 6; ++l)
			{
				std::cout << "Digit " << (l+1) << " has the value: " << btenArr[l] << std::endl;
			} */
			uncalculated = 0;
		}
		else
		{
			std::cout << "Hex colours have 6 digits silly" << std::endl << std::endl;

		}

	}
	// THIS WORKS!
	red = (btenArr[0] * 16 + btenArr[1]);
	green = (btenArr[2] * 16 + btenArr[3]);
	blue = (btenArr[4] * 16 + btenArr[5]);
	std::cout << "R: " << red << " G: " << green << " B: " << blue << std::endl << std::endl;

}
	
}