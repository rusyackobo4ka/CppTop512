#include <iostream> 
#include <fstream> 
#include <filesystem> 
#include <string> 

using namespace std;

void searchAndReplace(string& folderPath,string& word, string& newWord, bool flag)
{
    int count = 0;

    for (const auto& entry : filesystem::recursive_directory_iterator(folderPath)) 
    {
        if (!entry.is_regular_file()) 
        {
            continue;
        }

        string filePath = entry.path().string();

        ifstream File(filePath);
        ofstream newFile(filePath + ".tmp");

        string line;

        while (getline(File, line))
        {

            size_t pos = line.find(word);

            if (pos != string::npos) 
            {

                ++count;

                if (flag) 
                {
                    line.erase(pos, word.length());
                }

                else 
                {
                    line.replace(pos, word.length(), newWord);
                }

            }

            newFile << line << endl; 
        }

        File.close();
        newFile.close();

        filesystem::rename(filePath + ".tmp", filePath);
    }

        cout << "Count: " << count << endl;
    
}

int main() 
{
    string folderPath;
    string word = { "LOL" };
    string newWord = { "KEK" };

    bool flag = false;
    char choice;

    cout << "Enter path: ";
    cin >> folderPath;

    cout << "Enter word: ";
    cin >> word;

    cout << "Delete or replace word? (1/2): ";
    cin >> choice;

    if (choice == '1') 
    {
        flag = true;
    }
    else 
    {
        cout << "Enter new word: ";
        cin >> newWord;
    }

    searchAndReplace(folderPath, word, newWord, flag);

    return 0;
}