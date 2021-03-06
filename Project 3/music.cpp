#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

bool hasCorrectForm(string song);                                     //function to check if song has correct syntax
int convertSong(string song, string& instructions, int& badBeat);        //function to translate song
char convertNote(int octave, char noteLetter, char accidentalSign);      //function to translate notes
int main()
{
    cout << "Enter song: ";
    string t;
    string inst;

    int bad;

    getline(cin, t);
    hasCorrectForm(t);
    convertSong(t, inst, bad);
    if (hasCorrectForm(t))
        cout << true << endl;
    else
        cout << false << endl;
    cout << convertSong(t, inst, bad) << endl;

    cout << inst;
    //assert(hasCorrectForm("D5//D/"));
    //assert(!hasCorrectForm("D5//Z/"));
    //string instrs;
    //int badb;
    //instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    //assert(convertSong("D5//D/", instrs, badb) == 0 && instrs == "d y" && badb == -999);
    //instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    //assert(convertSong("D5//Z/", instrs, badb) == 1 && instrs == "xxx" && badb == -999);
    //assert(convertSong("D5//D8/", instrs, badb) == 2 && instrs == "xxx" && badb == 3);
    //
    //cerr << "All tests succeeded" << endl;
}

bool hasCorrectForm(string song)
{
    if (song.empty())
        return true;
    if (song.size() == 1)
    {
        if (song.at(0) == '/')
            return true;
        else
            return false;
    }
    if (song.at(0) == '/')
    {
        if (!(song.at(0) == song.at(1)))
        {
            return false;
        }
    }
    int l = song.size();
    if (!(song.at(l - 1) == '/'))
        return false;
    for (int k = 0; song[k]; k++)
    {
        if ((!isdigit(song.at(k))) && !(song.at(k) == 'A') && !(song.at(k) == 'B') && !(song.at(k) == 'C') && !(song.at(k) == 'D')
            && !(song.at(k) == 'E') && !(song.at(k) == 'F') && !(song.at(k) == 'G') && !(song.at(k) == '#') && !(song.at(k) == '/') && !(song.at(k) == 'b'))
            return false;
    }
    return true;
}

int convertSong(string song, string& instructions, int& badTick)
{
    if (hasCorrectForm(song))
    {
        char noteLetter = ' ';
        char accidentalSign = ' ';
        bool samechord = false;
        int tick = 1;
        int octave = 4;
        string temp = "";
        for (int k = 0; song[k]; k++)
        {
            if (isupper(song.at(k)) && isupper(noteLetter))
            {
                if (samechord != true)
                {
                    temp += "[";
                    samechord = true;
                }

                if (convertNote(octave, noteLetter, accidentalSign) == ' ')
                {
                    badTick = tick;
                    return 2;
                }
                temp += convertNote(octave, noteLetter, accidentalSign);
                noteLetter = song.at(k);
                accidentalSign = ' ';
                octave = 4;
            }
            else if (isupper(song.at(k)))
            {
                noteLetter = song.at(k);
            }
            else if (song.at(k) == '/')
            {
                tick++;
                if (isupper(noteLetter))
                {

                    if (convertNote(octave, noteLetter, accidentalSign) == ' ')
                    {
                        badTick = tick;
                        return 2;
                    }
                    temp += convertNote(octave, noteLetter, accidentalSign);
                    if (samechord == true)
                    {
                        temp += "]";
                    }
                    accidentalSign = ' ';
                    noteLetter = ' ';
                    octave = 4;
                    samechord = false;
                }
                else
                {
                    temp += ' ';
                }
            }
            else if (isupper(noteLetter))
            {
                if (isdigit(song.at(k)) || accidentalSign == '#' || accidentalSign == 'b')
                {
                    octave = song.at(k) - 48;

                }
                else if (song.at(k) == '#' || song.at(k) == 'b')
                {
                    accidentalSign = song.at(k);
                }
            }

        }
        instructions = temp;
        return 0;
    }
    return 1;

}

char convertNote(int octave, char noteLetter, char accidentalSign)
{
    // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** convertNote was called with first argument = "
            << octave << endl;
    }

    // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
    //      to -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
    case 'C':  note = 0; break;
    case 'D':  note = 2; break;
    case 'E':  note = 4; break;
    case 'F':  note = 5; break;
    case 'G':  note = 7; break;
    case 'A':  note = 9; break;
    case 'B':  note = 11; break;
    default:   return ' ';
    }
    switch (accidentalSign)
    {
    case '#':  note++; break;
    case 'b':  note--; break;
    case ' ':  break;
    default:   return ' ';
    }

    // Convert ..., A#1, B1, C2, C#2, D2, ... to
    //         ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "1!2@34$5%6^78*9(0qQwWeErtTyYuiIoOpPasSdDfgGhHjJklLzZxcCvVbBnm";
    if (sequenceNumber < 0 || sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}
