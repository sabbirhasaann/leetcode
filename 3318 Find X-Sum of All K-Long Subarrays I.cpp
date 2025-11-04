#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum4(vector<int>& nums, int k, int x) {
         unordered_map<int,int> mpp;
         int n =nums.size();
         priority_queue<pair<int,int>>pq;// we have to add frequency,element
         int sumt=0;
         for(int i=0;i<k && i<n;i++){
            mpp[nums[i]]++;
            sumt+=nums[i];
         }
         // we only have to take the x largest , so use a min heap
         vector<int> ans;
         if(mpp.size()<x) ans.push_back(sumt);
          else {
           for(auto it:mpp){
            pq.push({it.second,it.first});
           }
           int sum=0;
           int temp =x;
           while(!pq.empty() && temp>0){
            sum+=(pq.top().second*pq.top().first);
            pq.pop();
            temp--;
          }
          ans.push_back(sum);
    }

    // now we have to run a loop from k to n
    for(int i=k;i<n;i++){
        mpp[nums[i]]++;
        mpp[nums[i-k]]--;
        if(mpp[nums[i-k]]==0) mpp.erase(nums[i-k]);
        // empty the whole priority queue
        while(!pq.empty()) {
            pq.pop();
        }
        sumt+=nums[i];
        sumt-=nums[i-k];// add this to ans
        // traverse the map and get teh pq again
        int t =x;
        if(mpp.size()<x){

            ans.push_back(sumt);
        }
        else{
            for(auto it:mpp){
                pq.push({it.second,it.first});
            }
            int t=x;
            int sum =0;
            while(!pq.empty() && t>0){
                sum+=(pq.top().second*pq.top().first);
                pq.pop();
                t--;
            }
            ans.push_back(sum);// add this sum to our ans vector
        }
    }

    return ans;




    }

vector<int> findXSum3(vector<int> &nums, int k, int x)
{
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[nums[i]]++;
    }
    vector<pair<int, int>> p;
    for (auto it : mp)
    {
        p.push_back({it.first, it.second});
    }
    sort(p.begin(), p.end(), [&](auto &x, auto &y)
         {
            if(x.second==y.second)
                return x.first>y.first;
            return x.second>y.second; });

    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < min((int)p.size(), x); i++)
        sum += p[i].second * p[i].first;
    ans.push_back(sum);
    for (int i = k; i < nums.size(); i++)
    {
        mp[nums[i - k]]--;
        mp[nums[i]]++;
        sum = 0;
        p.clear();
        for (auto it : mp)
        {
            p.push_back({it.first, it.second});
        }
        sort(p.begin(), p.end(), [&](auto &x, auto &y)
             {
                 if (x.second == y.second)
                     return x.first > y.first;
                 return x.second > y.second;
             });

        for (int j = 0; j < min((int)p.size(), x); j++)
            sum += p[j].second * p[j].first;
        ans.push_back(sum);
    }

    return ans;
}

vector<int> findXSum2(vector<int> &nums, int k, int x)
{
    vector<int> ans;
    unordered_map<int, int> freq;
    int n = nums.size();

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        freq[nums[j]]++;

        if (j - i + 1 > k)
        {
            freq[nums[i]]--;
            if (freq[nums[i]] == 0)
                freq.erase(nums[i]);
            i++;
        }

        if (j - i + 1 == k)
        {
            // Convert map into vector for sorting
            vector<pair<int, int>> temp;
            for (auto &it : freq)
            {
                temp.push_back({it.first, it.second}); // {value, freq}
            }

            // Sort by freq desc, value desc
            sort(temp.begin(), temp.end(), [](auto &a, auto &b)
                 {
                    if (a.second == b.second) return a.first > b.first;
                    return a.second > b.second; });

            long long sum = 0;
            for (int t = 0; t < x && t < temp.size(); t++)
            {
                sum += temp[t].first * temp[t].second;
            }
            ans.push_back(sum);
        }
    }
    return ans;
}

vector<int> findXSum1(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    vector<int> freq(51, 0);
    vector<int> ans(n - k + 1, 0);
    // different treatment for first subarray
    for (int i = 0; i < k; i++)
        freq[nums[i]]++;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i <= 50; i++)
    {
        if (freq[i] > 0)
            pq.push(pair<int, int>(freq[i], i));
    }
    pair<int, int> tmp;
    int sm = 0;
    for (int i = 0; i < x && pq.size(); i++)
    {
        tmp = pq.top();
        pq.pop();
        sm += tmp.first * tmp.second;
    }
    ans[0] = sm;
    // second subarray onwards
    for (int i = 1; i < n - k + 1; i++)
    {
        freq[nums[i - 1]]--;
        freq[nums[k + i - 1]]++;
        priority_queue<pair<int, int>> pqn;
        for (int i = 0; i <= 50; i++)
        {
            if (freq[i] > 0)
                pqn.push(pair<int, int>(freq[i], i));
        }
        pair<int, int> tmp;
        int sm = 0;
        for (int i = 0; i < x && pqn.size(); i++)
        {
            tmp = pqn.top();
            pqn.pop();
            sm += tmp.first * tmp.second;
        }
        ans[i] = sm;
    }
    return ans;
}

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i + k <= n; ++i)
    {

        int freq[51] = {0};
        for (int j = i; j < i + k; ++j)
            freq[nums[j]]++;

        vector<pair<int, int>> pairs;
        for (int val = 1; val <= 50; ++val)
        {
            if (freq[val] > 0)
                pairs.emplace_back(freq[val], val);
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second; });

        long long sum = 0;
        for (int l = 0; l < (int)pairs.size() && l < x; ++l)
        {
            sum += 1LL * pairs[l].first * pairs[l].second;
        }
        res.push_back((int)sum);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;

    // nums = {3,8,7,8,7,5}, k = 2, x = 2
    vector<int> ans = findXSum(nums, k, x);
    for (int v : ans)
        cout << v << " ";
    cout << "\n";
    return 0;
}
