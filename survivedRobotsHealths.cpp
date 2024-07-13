#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        stack<int> stack;
        vector<int> indices(n), res;
        for(int i=0; i<n; ++i){
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        vector<int> robotHealth(n, 0);
        vector<bool> survived(n, true);
        for(int i=0; i<n; ++i){
            int idx = indices[i];
            if(directions[idx] == 'R'){
                stack.push(idx);
            } else{
                while(!stack.empty() && healths[idx] > 0){
                    int right_idx = stack.top();
                    if(healths[right_idx] > 0){
                        if(healths[right_idx] > healths[idx]){
                            --healths[right_idx];
                            healths[idx] = 0;
                            survived[idx] = false;
                        } else if(healths[right_idx] < healths[idx]){
                            --healths[idx];
                            healths[right_idx] = 0;
                            stack.pop();
                            survived[right_idx] = false;
                        } else{
                            healths[right_idx] = 0;
                            healths[idx] = 0;
                            survived[right_idx] = false;
                            survived[idx] = false;
                            stack.pop();
                        }
                    } else{
                        stack.pop();
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(survived[i] && healths[i] > 0){
                robotHealth[i] = healths[i];
            } else{
                robotHealth[i] = 0;
            }
        }
        for(int i=0; i<n; ++i){
            if(robotHealth[i] > 0){
                res.push_back(robotHealth[i]);
            }
        }
        return res;
    }
};
