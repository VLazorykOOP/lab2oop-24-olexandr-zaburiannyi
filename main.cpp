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

void secondTask() {
    string paddedText = padText();
    string encryptedText = encryptText(paddedText);
    for (char c : encryptedText) {
        cout << (int)c << " ";
    }
    cout << endl;
}

int main() {
   firstTask();
   secondTask();
    return 0;
}
