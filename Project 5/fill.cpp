
//C:/Users/josee/OneDrive/Documents/Engineering/Project5/data.txt
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>

#include <cassert>

#include <cctype>

#include <fstream>

using namespace std;



int fill(int lineLength, istream& inf, ostream& outf);

bool isMaxLenAtMin(int lineLength);

bool doesWordFitOneLine(int linelength, int counter, int consec, istream& inf);

bool doesWordFitOnthisLine(int linelength, int counter, int consec, int charsOnThisLineCounter, istream& inf);

bool isparagraphBreak(int linelength, int counter, istream& inf);

bool containSentenceEnd(int linelength, int counter, int consec, istream& inf);

int main()

{

    const int MAX_FILENAME_LENGTH = 100;

    for (;;)

    {

        cout << "Enter input file name (or q to quit): ";

        char filename[MAX_FILENAME_LENGTH];

        cin.getline(filename, MAX_FILENAME_LENGTH);

        if (strcmp(filename, "q") == 0)

            break;

        ifstream infile(filename);

        if (!infile)

        {

            cerr << "Cannot open " << filename << "!" << endl;

            continue;

        }

        cout << "Enter maximum line length: ";

        int len;

        cin >> len;

        cin.ignore(10000, '\n');

        int returnCode = fill(len, infile, cout);

        cout << "Return code is " << returnCode << endl;

    }

}



int fill(int lineLength, istream& inf, ostream& outf)

{

    if (isMaxLenAtMin(lineLength))

    {

        return 2;

    }



    char c;

    int consec = 0; //consecutive characters counter

    int counter = 0; //counts characters in istream

    int consecParBreaks = 0; //flag for paragraph breaks

    int charsOnThislineCounter = 0; //characters on current line

    bool parBreak = false;

    int remainingSpace;

    int flagputSpace = 0;

    int spacing = 0;

    int count;

    while (inf.get(c))

    {

        if (!isspace(c))

        {

            //cout <<endl;

            //cout << c << endl;

            consec++;



        }

        else if (consec > 0)

        {

            if (spacing > 1)

            {

                if (spacing % 2 != 0)

                {

                    counter += spacing - 1;

                }

                else

                {

                    counter += spacing;

                }



            }

            spacing = 0;



            if (consec == 3 && isparagraphBreak(lineLength, counter, inf))

            {

                if (consecParBreaks || counter == 0)

                {

                    consecParBreaks++;



                }

                else

                {

                    parBreak = true;



                }



                counter += consec;

                consec = 0;

                counter++;

                continue;

            }

            if (parBreak == true)

            {

                outf << endl;

                outf << endl;

                flagputSpace = 0;

                charsOnThislineCounter = 0;

                parBreak = false;

            }





            if (!doesWordFitOneLine(lineLength, counter, consec, inf))

            {

                flagputSpace = 0;

                int remainingConsecChar = consec;

                int startCounter = counter;

                while (remainingConsecChar >= lineLength)

                {

                    charsOnThislineCounter = 0;

                    outf << endl;

                    char l;

                    inf.seekg(startCounter);

                    while (lineLength <= charsOnThislineCounter && inf.get(l))

                    {

                        outf << l;

                        charsOnThislineCounter++;

                    }

                    startCounter += lineLength;

                    remainingConsecChar = remainingConsecChar - lineLength;

                }



            }

            else if (!doesWordFitOnthisLine(lineLength, counter, charsOnThislineCounter + flagputSpace, consec, inf))

            {

                flagputSpace = 0;

                charsOnThislineCounter = 0;

                outf << endl;



            }

            if (flagputSpace == 2)

            {

                outf << "  ";

                charsOnThislineCounter += 2;

            }

            else if (flagputSpace == 1)

            {

                outf << " ";

                charsOnThislineCounter++;

            }

            char ch;

            inf.seekg(counter);

            int tempCounter = 0;

            while (inf.get(ch) && tempCounter < consec)

            {

                outf << ch;

                tempCounter++;

                charsOnThislineCounter++;



            }





            if (containSentenceEnd(lineLength, counter, consec, inf))

            {



                remainingSpace = lineLength - charsOnThislineCounter;

                if (remainingSpace >= 2)

                {

                    flagputSpace = 2;



                }

            }

            else

            {

                flagputSpace = 1;

            }

            consecParBreaks = 0;

            counter += consec;

            consec = 0;

            counter++;

        }

        else

        {

            spacing++;

        }



    }

    if (consec > 0)

    {

        if (!doesWordFitOneLine(lineLength, counter, consec, inf))

        {

            flagputSpace = 0;

            int remainingConsecChar = consec;

            int startCounter = counter;

            while (remainingConsecChar >= lineLength)

            {

                charsOnThislineCounter = 0;

                outf << endl;

                char l;

                inf.seekg(startCounter);

                while (lineLength <= charsOnThislineCounter && inf.get(l))

                {

                    outf << l;

                    charsOnThislineCounter++;

                }

                startCounter += lineLength;

                remainingConsecChar = remainingConsecChar - lineLength;

            }

        }

        else if (!doesWordFitOnthisLine(lineLength, counter, charsOnThislineCounter + flagputSpace, consec, inf))

        {

            flagputSpace = 0;

            charsOnThislineCounter = 0;

            outf << endl;

        }

        if (flagputSpace == 2)

        {

            outf << "  ";

            charsOnThislineCounter++;

        }

        else if (flagputSpace == 1)

        {

            outf << " ";

            charsOnThislineCounter++;

        }

        char ch;

        inf.clear();

        inf.seekg(counter);

        int tempCounter = 0;

        while (inf.get(ch) && tempCounter < consec)

        {

            outf << ch;

            tempCounter++;

            charsOnThislineCounter++;



        }



        if (parBreak == true)

        {

            outf << endl;

            parBreak = false;

        }



    }

    //ofstream outf1();

    //outfile<<

    return 0;

}





bool isMaxLenAtMin(int lineLength)

{

    if (lineLength < 1)

    {

        return true;

    }

    return false;

}

bool isparagraphBreak(int linelength, int counter, istream& inf)

{

    char c;

    char par[] = "#P#";

    char word[4] = "";

    inf.seekg(counter);

    int WordRange = counter + 2;

    while (counter <= WordRange && inf.get(c))

    {



        char temp[2] = { c };

        strcat(word, temp);

        counter++;

    }

    return strcmp(par, word) == 0;

}

bool containSentenceEnd(int linelength, int counter, int consec, istream& inf)

{

    char c;

    inf.seekg(counter + consec - 1);

    inf.get(c);

    if (c == '.' || c == '?')

    {

        return true;

    }

    inf.seekg(counter + consec + 1);

    return false;



}

bool doesWordFitOneLine(int linelength, int counter, int consec, istream& inf)

{

    if (linelength > consec)

    {

        return true;

    }

    return false;

}

bool doesWordFitOnthisLine(int linelength, int counter, int consec, int charsOnThisLineCounter, istream& inf)

{

    if (consec > linelength - charsOnThisLineCounter)

    {

        return false;

    }

    return true;
 
}

