#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
   
    // 1. 첫 글자를 모두 대문자로 변환   
    if(islower(s[0])){  // 첫 글자가 소문자면
        s[0] = toupper(s[0]);   // 대문자로 변환
    }
    
    // 2. 공백 뒤 첫글자를 모두 대문자로 변환
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {  // 공백을 만나면 
            s[i + 1] = toupper(s[i + 1]);  // 다음 글자를 대문자로 변환
        }
    }
    
    // 3. 공백 뒤 첫글자가 아닌 대문자들을 소문자로 변환
    for(int i = 1; i < s.size(); i++) {
        // 대문자이고, 앞 글자가 공백이 아니면
        if(isupper(s[i]) && s[i - 1] != ' '){
            s[i] = tolower(s[i]);  // 해당 글자를 소문자로 변환
        }
    }
    
    // 변환된 s를 answer 값에 대입
    answer = s;
    
    return answer;
}