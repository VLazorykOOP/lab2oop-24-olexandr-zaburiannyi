#include <iostream>
#include <string>
using namespace std;

void firstTask() {
    int a,b,c,d;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Enter c: " << endl;
    cin >> c;
    cout << "Enter d: " << endl;
    cin >> d;
    int result = ( (b << 5) + (((d << 3) + (a << 3)) >> 9) - (c << 6) + (d << 3)) << 1;


    int checking = 3*b + (13*d + 12*a)/512 - 65*c + d*14;


    cout << result << endl;
    cout << "checking" << checking<< endl;
}

string padText(){
    int maxLength = 128;
    string text;
    cout << "Enter text: " << endl;
    cin >> text;
    if (text.length() >= maxLength){
        return text;
    }
    return text + string(maxLength - text.length(), ' ');
}
string encryptText(const string& text) {
    string encryptedText;
    for (char c : text) {

        int asciiValue = (int)c;

        int parityBit = 0;
        for (int i = 0; i < 7; ++i) {
            if ((asciiValue >> i) & 1) {
                parityBit ^= 1;
            }
        }

        int firstByte = (parityBit << 7) | asciiValue;

        int position = c - ' ';
        int secondByte = position & 0x7F;

        int combinedBytes = (firstByte << 8) | secondByte;

        encryptedText += (char)(combinedBytes >> 8);
        encryptedText += (char)(combinedBytes & 0xFF);
    }
    return encryptedText;
}


string decryptText(const string& encryptedText) {
    string decryptedText;
    for (int i = 0; i < encryptedText.length(); i += 2) {

        int firstByte = (int)encryptedText[i];
        int secondByte = (int)encryptedText[i + 1];

        int parityBit = (firstByte >> 7) & 1;
        int asciiValue = firstByte & 0x7F;

        char c = (char)asciiValue;


        int parityCheck = 0;
        for (int j = 0; j < 7; ++j) {
            if ((asciiValue >> j) & 1) {
                parityCheck ^= 1;
            }
        }

        if (parityCheck != parityBit) {

            cerr << "Wrong parity bit '" << c << "'" << endl;
        }

        decryptedText += c;
    }
    return decryptedText;
}

void secondTask() {
    string paddedText = padText();
    string encryptedText = encryptText(paddedText);
   string decryptedText = decryptText(encryptedText);
    cout<< decryptedText << endl;
}

int main() {
   firstTask();
   secondTask();
    return 0;
}
