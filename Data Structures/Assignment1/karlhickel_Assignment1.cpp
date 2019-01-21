#include <iostream>
#include <string>
#include <fstream>
#include <cmath>


using namespace std;

//Functions used later on in the code to compute statistical analysis.

int calculateMean (int length ,int numLine)
{
	int mean;
	mean = length / numLine;
	return mean;
}

int calculateStdDev (int variance)
{
	int stdDev;
	stdDev = sqrt(variance);
	return stdDev;

}

int calculateVariance (int sum , int numChar)
{
	int variance;
	variance = sum / numChar;
	return variance;
}

//Broke the calculation into several steps
float calculateC (float a , float b)
{
	float step1;
	float step2;
	float step3;

	step1 = -2 * log10 (a);
	step2 = cos(2*3.14*b);
	step3 = sqrt(step1) * step2;

	return step3;

}

int calculateD (float calculateC , int stdDev , int mean)
{
	int D;

	D = (stdDev * calculateC) + mean;

	return D;
}

//Used for the while loop so that the process repeats.
string userDecision = "yes";
//Inputs the file name.
int main(int argc , char** argv)
{
while(userDecision == "yes")
	{

	string fileName;
	fileName = argv[1];


	ifstream myFile;

	myFile.open(fileName);
	string input;

	float countA = 0;
	float countT = 0;
	float countC = 0;
	float countG = 0;
	float countAT = 0;
	float countAA = 0;
	float countAC = 0;
	float countAG = 0;
	float countCA = 0;
	float countCC = 0;
	float countCT = 0;
	float countCG = 0;
	float countTA = 0;
	float countTC = 0;
	float countTT = 0;
	float countTG = 0;
	float countGA = 0;
	float countGC = 0;
	float countGT = 0;
	float countGG = 0;
	float numLine = -1;
	float length = 0;
	int length2 = 0;
	int power = 2;
	int step1 = 0;
	int step2 = 0;
	int step3 = 0;
	int variance;
	int stddev;
	int mean;

	string userInputDecision;

	float C = 0;
	int D = 0;

	getline(myFile,input);



	while(!myFile.eof())
	{
		//Iterates the number of lines in the file
		numLine++;
		//Counts the number of times each letter shows up
		for (int i = 0; i < input.size(); ++i)
			{
			if(toupper(input[i]) == 'A')
					countA++;
			else if(toupper(input[i]) == 'T')
					 countT++;
			else if(toupper(input[i]) == 'C')
					 countC++;
			else if(toupper(input[i]) == 'G')
					 countG ++;
			}
			//Counts the number of Chars.
			for (int i = 0; i < input.size(); ++i)
			{
				length++;
			}
			//Counts the number of biagrams.
			for (int i = 0; i < input.size(); ++i)
			{
				if(input[i] == 'A' &&  input[i+1] == 'T')
				{
					countAT++;
				}

				else if(input[i] == 'A' && input[i+1] == 'A')
				{
					countAA++;
				}

				else if(input[i] == 'A' && input[i+1] == 'C')
				{
					countAC++;
				}

				else if(input[i] == 'A' && input[i+1] == 'G')
				{
					countAG++;
				}

				else if(input[i] == 'C' && input[i+1] == 'A')
				{
					countCA++;
				}

				else if(input[i] == 'C' && input[i+1] == 'C')
				{
					countCC++;
				}

				else if(input[i] == 'C' && input[i+1] == 'T')
				{
					countCT++;
				}

				else if(input[i] == 'C' && input[i+1] == 'G')
				{
					countCG++;
				}

				else if(input[i] == 'T' && input[i+1] == 'A')
				{
					countTA++;
				}

				else if(input[i] == 'T' && input[i+1] == 'C')
				{
					countTC++;
				}

				else if(input[i] == 'T' && input[i+1] == 'T')
				{
					countTT++;
				}

				else if(input[i] == 'T' && input[i+1] == 'G')
				{
					countTG++;
				}

				else if(input[i] == 'G' && input[i+1] == 'A')
				{
					countGA++;
				}

				else if(input[i] == 'G' && input[i+1] == 'C')
				{
					countGC++;
				}

				else if(input[i] == 'G' && input[i+1] == 'T')
				{
					countGT++;
				}

				else if(input[i] == 'G' && input[i+1] == 'G')
				{
					countGG++;
				}

			}
			cout << input << endl;
			//Gets the lines in the file
		getline(myFile,input);

	}
	//Closes the file so that I can reiterate
	myFile.close();

	//Self explanatory
	float probabilityA = countA/length;
	float probabilityT = countT/length;
	float probabilityC = countC/length;
	float probabilityG = countG/length;

	//Writes to another file.
	ofstream outputFile;
	outputFile.open("karlhickel_out");
	outputFile << "Karl Hickel" << endl;
	outputFile << "2278978" << endl;
	outputFile << "Assignment 1" << endl;
	outputFile << "Renae German" << endl;
	outputFile << "CPSC 350" << endl;
	outputFile << endl;
	outputFile << "The probabilities : " << endl;
	outputFile << "A = " << countA << " Probability = " << probabilityA << endl;
	outputFile << "T = " << countT << " Probability = " << probabilityT << endl;
	outputFile << "C = " << countC << " Probability = " << probabilityC << endl;
	outputFile << "G = " << countG << " Probability = " << probabilityG << endl;
	outputFile << "AT = " << countAT << " Probability = " << countAT/length << endl;
	outputFile << "AA = " << countAA << " Probability = " << countAA/length << endl;
	outputFile << "AC = " << countAC << " Probability = " << countAC/length << endl;
	outputFile << "AG = " << countAG << " Probability = " << countAG/length << endl;
	outputFile << "CA = " << countCA << " Probability = " << countCA/length << endl;
	outputFile << "CT = " << countCT << " Probability = " << countCT/length << endl;
	outputFile << "CC = " << countCC << " Probability = " << countCC/length << endl;
	outputFile << "CG = " << countCG << " Probability = " << countCG/length << endl;
	outputFile << "TA = " << countTA << " Probability = " << countTA/length << endl;
	outputFile << "TC = " << countTC << " Probability = " << countTC/length << endl;
	outputFile << "TT = " << countTT << " Probability = " << countTT/length << endl;
	outputFile << "TG = " << countTG << " Probability = " << countTG/length << endl;
	outputFile << "GA = " << countGA << " Probability = " << countGA/length << endl;
	outputFile << "GC = " << countGC << " Probability = " << countGC/length << endl;
	outputFile << "GT = " << countGT << " Probability = " << countGT/length << endl;
	outputFile << "GG = " << countGG << " Probability = " << countGG/length << endl;



	outputFile << endl;
	outputFile << "Number of lines: " << numLine << endl;
	outputFile << "Number of characters: " << length << endl;
	mean = calculateMean (length,numLine);
	outputFile << "Your mean is " << mean << endl;
	outputFile << endl;



	//I reopened the file to calculate the std dev.
	myFile.open("dna.txt");
	//Calculates the std dev.
	while(!myFile.eof())
	{
		for (int i = 0; i < input.size(); ++i)
			{
				length2++;
				step1 = length2 - mean;
				step2 = pow(step1, power);
				step3 += step2;
			}


			getline(myFile,input);


			length2 = 0;


	}

	//Variables speak for themselves
	variance = calculateVariance(step3 , length);
	stddev = calculateStdDev(variance);
	outputFile << "Your variance is " << variance << endl;
	outputFile << "Your standard deviation is " << stddev << endl;
	outputFile << endl;

	int i;
	double r = 0.0;
	float a = 0.0;
	float b = 0.0;
	//Calculates a random value for variable a
	for (i = 0 ; i <= 1 ; ++i)
	{
		r = ((double) rand() / (RAND_MAX));
		if (r < 1)
		{
			a = r;
		}
	}
	//Calculates a random value for variable b
	for (i = 0 ; i <=1 ; ++i)
	{
		r = ((double) rand() / (RAND_MAX));
		if (r < 1)
		{
			b = r;
		}
	}


	C = calculateC(a , b);
	D = calculateD(C , stddev, mean);
	//Length of each line.
	outputFile << "Your length is " << D << endl;

	int numberOfA;
	int numberOfC;
	int numberOfT;
	int numberOfG;

	numberOfA = D * probabilityA;
	numberOfC = D * probabilityC;
	numberOfT = D * probabilityT;
	numberOfG = D * probabilityG;



	string finalString;


//Inputs the number of As,Cs,Ts,Gs based on their probabilities.
for (i = 0; i <= numberOfA ; ++i)
{
	finalString += "A";
}

for (i = 0 ; i <= numberOfC ; ++i)
{
	finalString += "C";
}

for (i = 0 ; i <= numberOfT ; ++i)
{
	finalString += "T";
}

for (i = 0 ; i <= numberOfG ; ++i)
{
	finalString += "G";
}


for(i = 0; i <= 100; ++i )
{
	r = ((double) rand() / (RAND_MAX));

}
outputFile << endl;
outputFile << "1000 lines" << endl;
outputFile << endl;

//shuffles the lines
string str;
str = finalString;
for (i = 0 ; i <= 1000 ; ++i)
{
	random_shuffle(str.begin(), str.end());
	outputFile << str << '\n';
}
outputFile.close();

//Prompts the user to see if they would like to recalculate
cout << "Would you like to do this again? (yes or no)" << endl;
cin >> userInputDecision;
//Tests the users input
if (userInputDecision == userDecision)
{
	cout << "What is your new file name" << endl;
	cin >> fileName;


}
else
{
	break;
}

}
return 0;

}
