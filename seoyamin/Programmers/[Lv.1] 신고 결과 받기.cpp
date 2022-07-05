#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> id_index;
    map<string, vector<int>> report_map;

    
    // report 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    
    // report_map 뼈대 생성
    for(int i=0 ; i<id_list.size() ; i++) {
        vector<int> names;
        report_map.insert(make_pair(id_list[i], names));
        
        id_index.insert(make_pair(id_list[i], i)); // id_index Map
        answer.push_back(0);
    }
    
    
    // report_map insert
    string sender, receiver;
    for(int i=0 ; i<report.size() ; i++) {
        stringstream ss(report[i]);
        ss.str(report[i]);
        
        ss >> sender;
        ss >> receiver;
        
        report_map[receiver].push_back(id_index[sender]);
    }
    
    
    // report_map 채워넣기
    map<string, vector<int>>::iterator iter;
    for(iter = report_map.begin() ; iter != report_map.end() ; iter++) {
        if(iter->second.size() >= k) {
            for(int i=0 ; i<iter->second.size() ; i++) {
                answer[iter->second[i]]++;
            }           
        }  
    }
    
    
    return answer;
}