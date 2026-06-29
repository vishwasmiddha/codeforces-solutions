#include <iostream>
#include <string>
int main(){
    int n;
    std::cin >> n;
    for(int i = 0;i<n;i++){
        std::string word;
        std::cin >> word;
        if (word.length()>10){
            std::cout << word[0] << word.length()-2 << word[word.length()-1] << "
";
        } else {
            std::cout << word << "
";
        }
    }
}