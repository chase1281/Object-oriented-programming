#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Keyword {
public:
    string word;
    vector<int> lines;
};

vector<Keyword> indices;
vector<string> lines;
void makeIndex(string& fileName);
void addWord(string& word, int lineNum);
vector<Keyword>::iterator findWord(string& keyword);
void handle_find(string& keywword);
vector<string> split_line(string& line);

int main() {
    string command;
    while (true) {
        cout << "$ ";
        cin >> command;
        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "find") {
            string keyword;
            do {
                cin >> keyword;
            } while (keyword.length() < 3);
            handle_find(keyword);
        }
        else if (command == "exit")
            break;
    }
    return 0;
}

void makeIndex(string& fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        lines.push_back(line);
        vector<string> tokens = split_line(line);
        for (auto& s : tokens) {
            string temp;
            for (auto c : s) {
                if (isalnum(c))
                    temp += tolower(c);
            }
            if (temp.length() >= 3)
                addWord(temp, lineNum);
        }
        lineNum++;
    }
    theFile.close();
    sort(indices.begin(), indices.end(), [](const Keyword& a, const Keyword& b) {
        return a.word < b.word;
    });
}

vector<string> split_line(string& line)
{
    vector <string> tokens;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, ' '))
        tokens.push_back(str);
    return tokens;
}

void addWord(string& word, int lineNum) {
    auto it = findWord(word);
    if (it != indices.end() && it->word == word) {
        if (find(it->lines.begin(), it->lines.end(), lineNum) == it->lines.end())
            it->lines.push_back(lineNum);
    }
    else {
        Keyword tmp;
        tmp.word = word;
        tmp.lines.push_back(lineNum);
        indices.push_back(tmp);
    }
}

vector<Keyword>::iterator findWord(string& keyword) {
    auto it = indices.begin();
    while (it != indices.end()) {
        string lowerKeyword = keyword;
        for (auto& x : lowerKeyword)
            x = tolower(x);
        if (it->word == lowerKeyword)
            return it;
        it++;
    }
    return it;
}

void handle_find(string& keyword) {
    for (auto& x : keyword)
        x = tolower(x);
    auto it = findWord(keyword);
    if (it != indices.end()) {
        cout << "The word " << it->word << " appears " <<
            it->lines.size() << " times in lines: " << endl;
        for (auto v : it->lines)
            cout << v << ": " << lines[v] << endl;
    }
    else
        cout << "The word " << keyword << " doesn¡¯t appear." << endl;
}