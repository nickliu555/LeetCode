class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        for (int asteroid: asteroids) {
            if (mass < asteroid) return false;
            mass += asteroid;
        }
        return true;
    }
};