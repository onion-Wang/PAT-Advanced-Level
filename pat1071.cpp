//
// Created by conion on 2020-02-17.
//  从一串字符中读取单词， map的使用
//
#include <iostream>
#include <map>

using namespace std;

bool isPartOfWord(char c);

int main(){
    string input;
    getline(cin, input);
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = input[i] - 'A' + 'a';   //大写转小写
        }
    }
    map<string, int> wordMap;
    for(int i = 0; i < input.length(); i++){
        if(!isPartOfWord(input[i])){
            continue;
        }
        int j = i;
        while(isPartOfWord(input[j])){
            j++;
        }
        wordMap[input.substr(i, j - i)]++;
        i = j;
    }
    string result;
    int count = 0;
    for(map<string, int>::iterator it = wordMap.begin(); it != wordMap.end(); it++){
        if(it->second > count){
            result = it->first;
            count = it->second;
        }
    }
    cout << result << " " << count;

    return 0;
}

bool isPartOfWord(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return true;
    }
    return false;
}