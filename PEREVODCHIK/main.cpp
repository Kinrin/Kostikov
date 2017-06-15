#include <iostream>
#include<string>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
int ruseng(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;

    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][0]){
                words[i]=slovar[j][1];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int engrus(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;
    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][1]){
                words[i]=slovar[j][0];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int rusbel(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;
    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][0]){
                words[i]=slovar[j][2];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int belrus(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;
    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][2]){
                words[i]=slovar[j][0];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int engbel(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;
    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][1]){
                words[i]=slovar[j][2];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int beleng(std::vector<std::string>& words,std::vector<std::vector<std::string>>& slovar){
    std::vector<std::string> tmp;
    tmp=words;
    for(unsigned int i=0;i<words.size();i++){
        for(unsigned int j=0;j<slovar.size();j++){

            if(words[i]==slovar[j][2]){
                words[i]=slovar[j][1];
            }
        }
    }
    if(words==tmp){
        std::cout<<"некорректный язык"<<std::endl;
        return 0;
    }
    for(unsigned int i=0;i<words.size();i++)
        std::cout << words[i] << " ";
    std::cout<<std::endl;
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<std::string> words;
    std::vector<std::vector<std::string>> slovar{{"мама","mom","мама"},
                                                 {"маму","mother","маму"},
                                                 {"папа","dad","тата"},
                                                 {"папу","father","тату"},
                                                 {"окно","window","акно"},
                                                 {"и","and","i"},
                                                 {"моет","washes","мые"},
                                                 {"моют","wash","мыюць"},
                                                };
    std::cout<<"Введите предложение"<<std::endl;
    std::string s;
    std::getline ( std::cin, s );
    std::istringstream ist(s);
    std::string tmp;
    while ( ist >> tmp )
        words.push_back(tmp);
    std::cout<<"1-Перевод с русского на английский"<<std::endl;
    std::cout<<"2-Перевод с английского на русский"<<std::endl;
    std::cout<<"3-Перевод с русского на белорусский"<<std::endl;
    std::cout<<"4-Перевод с белорусского на русский"<<std::endl;
    std::cout<<"5-Перевод белорусского  на английский"<<std::endl;
    std::cout<<"6-перевод с английского на белорусский"<<std::endl;
    int choice;
    std::cin>>choice;
    switch(choice){
    case 1:
        ruseng(words,slovar);
        break;
    case 2:
        engrus(words,slovar);
        break;
    case 3:
        rusbel(words,slovar);
        break;
    case 4:
        belrus(words,slovar);
        break;
    case 5:
        beleng(words,slovar);
        break;
    case 6:
        engbel(words,slovar);
        break;
    }
    return 0;
}
