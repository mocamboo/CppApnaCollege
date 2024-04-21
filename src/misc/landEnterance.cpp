#include <bits/stdc++.h>
using namespace std;
// _________________NUMToWords>>geeksforgeeks__________________________________________
string one[] = {"", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "};
string ten[] = {"", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "};
string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}
string convertToWords(int n)
{
    // stores word representation of given number n
    string out;

    // handles digits at ten millions and hundred
    // millions places (if any)
    out += numToWords((n / 10000000), "crore ");

    // handles digits at hundred thousands and one
    // millions places (if any)
    out += numToWords(((n / 100000) % 100), "lakh ");

    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) % 100), "thousand ");

    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100) % 10), "hundred ");

    if (n > 100 && n % 100)
        out += "and ";

    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");

    // Handling the n=0 case
    if (out == "")
        out = "zero";

    return out;
}
// ______________________Prime Check____________________________________
bool checkPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U');
}

// Returns count of vowels in str
int countVowels(string str)
{
    int count = 0;

    for (auto i : str)
        if (isVowel(i))
            ++count;
    return count;
}
int main()
{

    int n;
    cin >> n;
    string ele[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ele[i];
    }
    int emo[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        switch (s.size())
        {
        case 10:
            emo[i] = 10;
            break;
        case 3:
            emo[i] = 5;
            break;
        case 7:
            emo[i] = 2;
            break;
        case 4:
            emo[i] = 1;
            break;
        }
    }
    int totalVowels = 0;
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        int k = ((ele[i])[0] - '0') * emo[i];
        string strr = ele[i].substr(1);
        // cout << strr << "__________";
        score += k;
        // cout << k << " ";
        int vowels = countVowels(strr) * ((ele[i])[0] - '0');
        totalVowels += vowels;
    }
    int areaScore = 0;
    if (score > totalVowels)
    {
        areaScore = floor(score / totalVowels);
    }
    else
        areaScore = floor(totalVowels / score);
    // cout << areaScore << endl;
    string inwords = convertToWords(areaScore);
    // inwords[0] = toupper(inwords[0]);
    // transform(inwords.begin(), inwords.end(), inwords.begin(), ::toupper);
    if (checkPrime(areaScore))
    {
        cout << "Yes " << inwords << endl;
    }
    else
        cout << "No " << inwords << endl;

    return 0;
}