#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm> 

using namespace std;

const int ASCII = 256;

void encryptText(const char Key[], const string OriginalText, string& EncryptedText);
void decryptText(const char Key[], const string EncryptedText, string& DecryptedText);
void Random(char Key[]);

int main()
{
    char Key[ASCII];
    string OriginalText;
    string EncryptedText;
    string DecryptedText;

    for (int i = 0; i < ASCII; i++)
    {
        Key[i] = static_cast<char>(i);  
    }

    Random(Key);

    for (int i = 0; i < ASCII; i++)
    {
        cout << "\nASCII " << i << ": " << Key[i];
    }

    cout << "\nEnter original text: ";
    getline(cin, OriginalText);  


    encryptText(Key, OriginalText, EncryptedText);

    decryptText(Key, EncryptedText, DecryptedText);

    cout << endl;
    cout << "Original Text  : " << OriginalText << endl;
    cout << "Encrypted Text : " << EncryptedText << endl;
    cout << "Decrypted Text : " << DecryptedText << endl;

    return 0;
}

void encryptText(const char Key[], const string OriginalText, string& EncryptedText)
{
    int text_length = OriginalText.length();
    EncryptedText.resize(text_length);  

    for (int i = 0; i < text_length; i++)
    {
        EncryptedText[i] = Key[static_cast<unsigned char>(OriginalText[i])];
    }
}

void decryptText(const char Key[], const string EncryptedText, string& DecryptedText)
{
    int text_length = EncryptedText.length();
    DecryptedText.resize(text_length); 

    for (int i = 0; i < text_length; i++)
    {
        for (int j = 0; j < ASCII; j++)
        {
            if (EncryptedText[i] == Key[j])
            {
                DecryptedText[i] = static_cast<char>(j);
                break;
            }
        }
    }
}

void Random(char Key[])
{
    srand(time(0));  
    for (int i = 0; i < ASCII; ++i)
    {
        swap(Key[i], Key[rand() % ASCII]);
    }
}
