#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> m;
    for(int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]].push_back(clothes[i][0]);
    }

    int clothes_category_num;
    clothes_category_num = m.size();
    //m[i]의 원소의 개수를 저장하는 배열
    // int clothes_num[clothes_category_num];
    vector<int> clothes_num(clothes_category_num);
    int i=0;
    for(auto it=m.begin(); it!=m.end(); it++) {
        clothes_num[i] = it->second.size();
        i++;
    }
    int result =1;
    for(int i=0; i<clothes_category_num; i++) {
        result *= (clothes_num[i]+1);
    }

    return result-1;
}