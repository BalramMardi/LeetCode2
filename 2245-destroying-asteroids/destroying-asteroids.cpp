class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        long long total = mass;

        for(const int ast : asteroids){

            if(total < ast){
                return false;
            }

            total += ast;
        }


        return true;
    }
};