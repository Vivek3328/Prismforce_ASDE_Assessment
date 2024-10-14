#include <bits/stdc++.h>
using namespace std;

int power;
vector<vector<vector<vector<vector<int>>>>> dp;

bool can_cross_chakravyuha(int k, vector<int> &enemyPower, int ind, int initalPower, int skip, int recharge, int lastSkipped){
    if(ind>=k){
        return true;
    }

    if(initalPower<0){
        return false;
    }

    if(enemyPower[ind]>initalPower && recharge==0 && skip==0){
        return false;
    }

    if((ind==3 || ind==7) && initalPower<(enemyPower[ind]+(enemyPower[ind-1]/2)) && skip==0 && recharge==0){
        return false;
    }

    if(dp[ind][initalPower][skip][recharge][lastSkipped]!=-1){
        return dp[ind][initalPower][skip][recharge][lastSkipped];
    }

    bool ans=false;

    if(skip>0){
        ans = ans | can_cross_chakravyuha(k,enemyPower,ind+1,initalPower,skip-1,recharge, 1);
    }

    if(recharge>0 && initalPower<enemyPower[ind]){
        ans = ans | can_cross_chakravyuha(k,enemyPower,ind,power,skip,recharge-1,lastSkipped);
    }

    if((ind==3 || ind==7) && initalPower>(enemyPower[ind]+(enemyPower[ind-1]/2)) && lastSkipped==0){
        ans = ans | can_cross_chakravyuha(k,enemyPower,ind+1,initalPower-(enemyPower[ind]+enemyPower[ind-1]/2),skip,recharge,0);
    }
    else if(initalPower>enemyPower[ind]){
        ans = ans | can_cross_chakravyuha(k,enemyPower,ind+1,initalPower-enemyPower[ind],skip,recharge,0);
    }

    return dp[ind][initalPower][skip][recharge][lastSkipped] = ans;
}

int main(){
    int k = 11; //Number of circle

    vector<int> enemyPower;

    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        enemyPower.push_back(x);
    }

    int initialPower; // Inital Power of Abhimanyu
    cin>> initialPower;

    power = initialPower;

    int skip;  // Number of times Abhimanyu can skip the circle from fighting the enemy
    cin>> skip;

    int recharge;  // Number of times Abhimanyu can recharge himself with the power.
    cin>> recharge;

    recharge = min(recharge,k);
    skip = min(skip,k);

    dp.resize(12, vector<vector<vector<vector<int>>>>(initialPower+1, vector<vector<vector<int>>>(skip+1, vector<vector<int>>(recharge+1, vector<int>(3, -1)))));

    bool ans = can_cross_chakravyuha(k,enemyPower,0,initialPower,skip,recharge,0);

    if(ans){
        cout<<"Abhimanyu can cross the chakravyuha"<<endl;
    }
    else{
        cout<<"Abhimanyu cannot cross the chakravyuha"<<endl;
    }

    return 0;
}