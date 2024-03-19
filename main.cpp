#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;

void countAndWriteDigitsPerLine(string filename, string outputFilename)
{
    int counter = 0;
    string myText;
    ifstream Read(filename);
    ofstream Write(outputFilename);
    while (getline(Read, myText)) {
        for (int i = 0; i < myText.size(); i++) {
            if (isdigit(myText[i])) {
                counter++;
            }
        }
        Write << counter;
        Write << "\n";
        counter = 0;
    }

   
    Read.close();
    Write.close();
}

unsigned int countMaxDigits(string filename)
{
    int counter = 0;
    int max = 0;
    string myText;
    ifstream Read(filename);
    while (getline(Read, myText)) {
        for (int i = 0; i < myText.size(); i++) {
            if (isdigit(myText[i])) {
                counter++;
            }
        }
        if (counter > max) {
            max = counter;
        }
        counter = 0;
    }


    Read.close();
    return max;
}
int main() {
    countAndWriteDigitsPerLine("filename.txt", "outputFilename.txt");
    cout << countMaxDigits("filename.txt");
}
