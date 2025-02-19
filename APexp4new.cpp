//Name:- Jain Aman
//UID:- 22BCs14831
//Section:-637
//Goup:-"B"



//Problem:-01

#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> result = {1};
    while (result.size() < n) {
        vector<int> temp;
        for (int num : result) {
            if (num * 2 - 1 <= n) temp.push_back(num * 2 - 1);
        }
        for (int num : result) {
            if (num * 2 <= n) temp.push_back(num * 2);
        }
        result = temp;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = beautifulArray(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}



// Problem:-02

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    for (auto& b : buildings) {
        events.emplace_back(b[0], -b[2]); // Start of a building (negative height)
        events.emplace_back(b[1], b[2]);  // End of a building (positive height)
    }
    
    sort(events.begin(), events.end());
    
    multiset<int> heights = {0};
    vector<vector<int>> result;
    int prevMaxHeight = 0;
    
    for (auto& e : events) {
        int x = e.first, h = e.second;
        if (h < 0) {
            heights.insert(-h); // Add the height
        } else {
            heights.erase(heights.find(h)); // Remove the height
        }
        
        int currentMaxHeight = *heights.rbegin();
        if (currentMaxHeight != prevMaxHeight) {
            result.push_back({x, currentMaxHeight});
            prevMaxHeight = currentMaxHeight;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> skyline = getSkyline(buildings);
    
    for (auto& point : skyline) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;
}

