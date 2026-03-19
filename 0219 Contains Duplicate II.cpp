// 2026/03/19 21:38:46
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> um;
        for(int i=0;i<nums.size();++i){
            if(um.find(nums[i]) != um.end()){
                for(int x: um[nums[i]])
                    if(abs(i-x)<=k)
                        return true;

            }            
            um[nums[i]].push_back(i);
        }
        return false;
    }

void soln()
{
    vector<pair<vector<int>, int>> testSet{
        {{1,2,3,1}, 3},
        {{1,0,1,1}, 1},
        {{1,2,3,1,2,3}, 2},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << containsNearbyDuplicate(testSet[i].first, testSet[i].second)<< endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}

bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]))
            {
                if(i-m[nums[i]]<=k)
                return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }


bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                if (abs(it->second-i) <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }

bool containsNearbyDuplicate3(vector<int>& nums, int k) {
        unordered_set<int>window;
        for(int i=0;i<nums.size();i++){
            if(window.count(nums[i])) return true;
            window.insert(nums[i]);
            if(window.size()>k) window.erase(nums[i-k]);
        }
        return false;
    }

int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}