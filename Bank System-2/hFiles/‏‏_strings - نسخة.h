#pragma once


#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

#define thisAdress = "Saad";

namespace _strings {
         enum CharType {
            lower = 0,
            upper
        };

        int RandomNumber(int From, int To)
        {

            int randNum = rand() % (To - From + 1) + From;
            return randNum;
        }

        string ReadString(string message , bool AddLine) {
            if (AddLine)
                cout << message << endl;
            else
                cout << message;


            string str;
            getline(cin >> ws, str);
            return str;

        }
        char   ReadChar(string message) {
            cout << message << endl;
            char c;
            cin >> c;
            return c;
        }


        void PrintFirstLetterOfEachWord(string str) {

            str = ReadString(" Enter Your String ",true);

            bool isFirstLetter = true;
            // sa d0
            for (int i = 0; i < str.length(); i++) {

                if (str[i] != ' ' && isFirstLetter)
                {
                    cout << str[i] << endl;
                }

                isFirstLetter = (str[i] == ' ' ? true : false);

            }
        }





        char InvertLetter(char letter) {

            return letter = (isupper(letter)) ? tolower(letter) : toupper(letter);
        }

        string InvertString(string& str, CharType type) {
            if (type == CharType::lower) {
                for (char& item : str) {
                    item = tolower(item);
                }
                return str;
            }


            for (char& item : str) {
                item = toupper(item);
            }
            return str;

        }

        string InvertAllLetter(string str) {

            for (int i = 0; i < str.length(); i++) {

                str[i] = InvertLetter(str[i]);
            }

            return str;
        }

        int CountSmallLetter(string str) {
            int counter = 0;
            for (int i = 0; i < str.length(); i++) {

                if (str[i] == islower(str[i]))
                {
                    counter++;
                }
            }

            return counter;
        }

        int CountCapitalLetter(string str) {
            int counter = 0;
            for (int i = 0; i < str.length(); i++) {

                if (str[i] == isupper(str[i])) {
                    counter++;
                }
            }

            return counter;
        }


        int CountLetter(string str, char c, bool matchCase = true) {

            int counter = 0;

            if (matchCase == true)
            {
                for (int i = 0; i < str.length(); i++) {

                    if (str[i] == c) {
                        counter++;
                    }
                }

                return counter;

            }
            else
            {

                for (int i = 0; i < str.length(); i++)
                {

                    if (tolower(str[i]) == tolower(c)) {
                        counter++;
                    }

                }
                return counter;
            }

        }

        bool isVowel(char letter) {

            letter = tolower(letter);

            return (letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'u') || (letter == 'o');
        }


        short CountVowel(string str) {
            short counter = 0;

            for (int i = 0; i < str.length(); i++) {

                if (isVowel(str[i]))
                    counter++;

            }


            return counter;
        }


        void PrintVowels(string& str) {

            for (int i = 0; i < str.length(); i++) {

                if (isVowel(str[i]))
                    cout << str[i] << " ";


            }

        }



        void PrintEachWordInStringMethod1(string& str) {
            bool isFirstLetter = true;
            string word = "";



            for (int i = 0; i < str.length(); i++) {

                // 1. is a letter & not first = skip
                // 2 is empty  & not first
                //3 is a letter & is First letter = dont skip it 

                if (str[i] != ' ' && isFirstLetter)
                {

                    while (str[i] != ' ' && i != str.length())
                    {
                        word += str[i];
                        i++;
                    }

                    cout << word << endl;
                    word = "";
                }

                isFirstLetter = (str[i] ? true : false);
            }




        }


        void PrintEachWordInStringMethod2(string str)
        {
            string FindThis = " ";
            string word = "";
            short pos = 0;
            while ((pos = str.find(FindThis)) != string::npos)
            {
                word = str.substr(0, pos);
                if (word != "") {
                    cout << word << endl;
                }


                str.erase(0, pos + FindThis.length());
            }



            if (str != "") {
                cout << str << endl;
            }

        }



        int CountEachWordInString(string str) {
            string delimer = " ";
            int counter = 0;
            short position = 0;
            string word = "";
            while ((position = str.find(delimer)) != str.npos) // there is an space ' '
            {
                word = str.substr(0, position);
                if (word != "") {
                    counter++;
                }

                str.erase(0, position + delimer.length());
            }

            if (str != "")
            {
                counter++;
            }
            return counter;
        }

        vector<string> SplitString(string str, string delimiter)
        {
            vector<string> vec;
            string word;
            short pos = 0;

            while ((pos = str.find(delimiter)) != std::string::npos)
            {
                word = str.substr(0, pos);

                if (word != "")
                    vec.push_back(word);



                str.erase(0, pos + delimiter.length());
            }

            if (str != "")
                vec.push_back(str);


            return vec;
        }



        string TrimLeft(string str) {
            //: " saad        " 
            // TrimLeft = " saad"



            for (int i = 0; i < str.length(); i++) {

                if (str[i] != ' ')
                {
                    return  str.substr(i, str.length() - i);
                }
            }


            return str;

        }



        string TrimRight(string str) {
            //: " saad        " 
            // TrimLeft = "saad     "



            for (int i = str.length() - 1; i != 0; i--)
            {

                if (str[i] != ' ')
                {
                    return str.substr(0, i + 1);

                }
            }

            return str;

        }
        string TrimedString(string str) {

            return (TrimLeft(TrimRight(str)));
        }

        string JoinString(vector<string> vStr, string Delimiter)
        {
            string JoinedString = "";

            for (string& item : vStr)
            {
                JoinedString += item + Delimiter;
            }

            return JoinedString.substr(0, JoinedString.length() - Delimiter.length());
        }

        string JoinString(string strArr[], string Delimiter, short Length)
        {
            string JoinedString = "";

            for (int i = 0; i <= Length - 1; i++)
            {
                JoinedString += strArr[i] + Delimiter;
            }

            return JoinedString.substr(0, JoinedString.length() - Delimiter.length());
        }



        string ReversedString(string str)
        {
            vector<string> vString = SplitString(str, " ");
            string revString = "";

            vector<string>::iterator it = vString.end(); // iterator



            while (it != vString.begin()) {
                it--;

                revString += *it + " ";
            }

            revString = revString.substr(0, revString.length() - 1); // remove last space
            return revString;
        }

        string ReplaceString_BuiltIn(string str, string _target, string replacedWord)
        {
            short Pos = str.find(_target);

            while ((Pos = str.find(_target)) != string::npos)
            {
                // Saaddwdsadaw ? = replace it by length
                str = str.replace(Pos, _target.length(), replacedWord);
                Pos = str.find(_target); // Find Next
            }


            return str;
        }


        bool IsUpperOrLower(string str1, string str2) {

            for (int i = 0; i <= str1.length(); i++)
            {
                if (tolower(str1[i]) != tolower(str2[i]) || toupper(str1[i]) != toupper(str2[i])) {
                    return false;
                }


            }

            return true;
        }


        string Replace_Custom_1(string& str, string target_to_replace, string  replacedWord, bool matchCase)
        {
            int pos = 0;
            if (matchCase == true)
            {

                while ((pos = str.find(target_to_replace)) != string::npos)
                {
                    str = str.erase(pos, target_to_replace.length());
                    str = str.insert(pos, replacedWord);
                }

            }
            else
            {

                // use The IsUpperOrLower Function
                // or you can lower or upper both the strings and then compare them
                //am saad

#pragma region  Invert the strigns
                str = InvertString(str, lower);
                target_to_replace = InvertString(target_to_replace, lower);
#pragma endregion

                while ((pos = str.find(target_to_replace)) != string::npos)
                {
#pragma region  erase and insert
                    str = str.erase(pos, target_to_replace.length());
                    str = str.insert(pos, replacedWord);

#pragma endregion
                }

            }
            return str;
        }
        string Replace_Custom_2(string& str, string target_to_replace, string replacedWord, bool mathchcase) {

            vector<string> vec = SplitString(str, " ");

            if (mathchcase)
            {
                for (string& item : vec)
                {

                    if (item == target_to_replace)
                    {
                        item = replacedWord;
                    }

                }
            }
            else
            {
                for (string& item : vec) {

                    if (InvertString(item, lower) == InvertString(target_to_replace, lower))
                    {
                        item = replacedWord;
                    }
                }

            }


            return str;


        }

        bool IsPunctuation(char letter) {

            return ((letter == ';') || (letter == ',') || (letter == '!') || (letter == '.') || (letter == ':') || (letter == '$') || (letter == '?') ||
                (letter == '*'));
        }

        string RemovePunctuation(string& str) {

            string S2 = "";

            for (int i = 0; i <= str.length(); i++)
            {
                if (!IsPunctuation(str[i]))
                    S2 += str[i];

            }



            return S2;
        }


    
}

#pragma once