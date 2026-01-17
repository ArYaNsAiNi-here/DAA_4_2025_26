#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string c1;
    int i1, i2;
    vector<pair<string, pair<int,int>>> Inp;
    Inp.reserve(n);

    for(int i = 0;i<n;i++){
        cout << "Jod ID: ";
        cin >> c1;
        cout << "Job Profit: ";
        cin >> i1;
        cout << "Job Deadline: ";
        cin >> i2;
        Inp.push_back({c1,{i1,i2}});
    }

    sort(Inp.begin(),Inp.end(),[](const auto& a, const auto& b){
        return a.second.second > b.second.second;
    });

    int max_time;
    max_time = Inp.front().second.second;
    
    sort(Inp.begin(),Inp.end(),[](const auto& a, const auto& b){
        return a.second.first > b.second.first;
    });

    vector<string> job;
    job.reserve(max_time);
    int max_profit = 0;

    for(int i=0;i<Inp.size();i++){
        if(Inp[i].second.second >= i+1){
            job.push_back(Inp[i].first);
            max_profit += Inp[i].second.first;
        }
    }
    cout << "\nMax Profit: " << max_profit;
}