#include <string>
#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int result = x; 
    while (n--) {
        answer.push_back(result); 
        result += x; 
    }
    return answer;
}