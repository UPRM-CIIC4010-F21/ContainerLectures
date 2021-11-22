#include <iostream>
#include <string>
#include <map>

using namespace std;

// https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem

map<char, int> getLetterHistogram(string text, string alphabet) {

    map<char, int> letterFrequency;

    for (char c : alphabet) {
        letterFrequency[c] = 0;
    }

    for (char c : text) {
        letterFrequency[toupper(c)]++;
    }

    return letterFrequency;
}

int main() {

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    string paragraph = "A planet is an astronomical body orbiting a star or stellar remnant that is massive enough to be rounded by its own gravity";

    map<char,int> result = getLetterHistogram(paragraph, alphabet);

    int sum = 0;
    for (char c : alphabet) {
        sum += result[c];
        cout << "Letter " << c << " appears " << result[c] << " times " << endl;
    }
    cout << "Length of text: " << paragraph.length() << endl;
    cout << "Sum of frecuencies: " << sum << endl;

}