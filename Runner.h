//
// Created by Kyle on 6/14/2020.
//
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#ifndef CS1342_DECBINHEX_RUNNER_H
#define CS1342_DECBINHEX_RUNNER_H
using namespace std;
class Runner{
public:
    explicit Runner(vector<string>& input);
    void determineNumberType(string & line);
    void readHex(string& line);
    void readBin(string& line);
    void readDec(string& line);
    vector<string> splitString(string&line);
    int hexToDec(string num);
    void decToHex(int num);


};

Runner::Runner(vector<string>& input) {
    string numLines = input[0];
    int intNumLines = stoi(numLines);
    for(int i = 1; i <= intNumLines; i++)
    {
        string readLine = input[i];
        determineNumberType(readLine);
    }
}

void Runner::determineNumberType(string &line) {
    string sub = line.substr(0, 1);
    line.erase(0, 2);
    //cout << "Line is: " << line << endl;
    if(sub == "H"){
        readHex(line);
    } else if (sub == "B")
    {
        readBin(line);
    } else
    {
        readDec(line);
    }
}

void Runner::readHex(string &line) {
    vector<string> splittedString = splitString(line);
    int first = hexToDec(splittedString[1]);
    int sec = hexToDec(splittedString[2]);
    if(splittedString[0] == "+")
    {
        int sum = first + sec;
        decToHex(sum);
    } else
    {
        int product = first * sec;
        decToHex(product);
    }
}

void Runner::readBin(string &line) {
    vector<string> splittedString = splitString(line);
}

void Runner::readDec(string &line) {
    vector<string> splittedString = splitString(line);

    int first = stoi(splittedString[1]);
    int sec = stoi(splittedString[2]);
    if(splittedString[0] == "+")
    {
        cout << first + sec << endl;
    } else
    {
        cout << first * sec << endl;
    }
}

vector<string> Runner::splitString(string &line) {
    //Reference: http://www.cplusplus.com/reference/string/string/find/
    vector<string> returner;
    string str2("+");
    std::size_t found = line.find(str2);
    if (found!=std::string::npos){
        //std::cout << "+ found at: " << found << endl;
        returner.emplace_back("+");
        string first = line.substr(0, found);
        //cout << "First: " << first << endl;
        string second = line.substr(found+2, line.size()-found);
        //cout << "Second: " << second << endl;
        returner.push_back(first);
        returner.push_back(second);
    }
    else{
        string str3("*");
        std::size_t found2 = line.find(str3);
        //std::cout << "* found at: " << found2 << endl;
        returner.emplace_back("*");
        string first = line.substr(0, found2);
        //cout << "First: " << first << endl;
        string second = line.substr(found2+2, line.size()-found2);
        //cout << "Second: " << second << endl;
        returner.push_back(first);
        returner.push_back(second);
    }
    return returner;
}

int Runner::hexToDec(string num) {
    int sum =0;
    int count = 0;
    for(int i = num.size()-1; i >= 0; i --){
        int multiplier = pow(16, count);
        if(num[i] == 'A')
        {
            sum += 10 * multiplier;
            count++;
        } else if(num[i] == 'B') {
            sum += 11 * multiplier;
            count++;
        } else if (num[i] == 'C') {
            sum += 12 * multiplier;
            count++;
        } else if (num[i] == 'D') {
            sum += 13 * multiplier;
            count++;
        } else if(num[i] == 'E') {
            sum += 14 * multiplier;
            count++;
        } else if (num[i] == 'F') {
            sum += 15 * multiplier;
            count++;
        } else{
            int intForm = num[i];
            sum += intForm * multiplier;
            count++;
        }
    }
    return sum;
}

void Runner::decToHex(int num) {
    cout << "Need to turn " << num << " into hex" << endl;
    /*
     * Conversion steps simplified from: https://www.rapidtables.com/convert/number/decimal-to-hex.html
     * Divide the number by 16.
     * Get the integer quotient for the next iteration.
     * Get the remainder for the hex digit.
     * Repeat the steps until the quotient is equal to 0.
     */

}

#endif //CS1342_DECBINHEX_RUNNER_H
