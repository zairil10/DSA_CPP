#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void gale_shapley(int n, const vector<vector<int>>& men_pref, const vector<vector<int>>& women_pref, vector<int>& wife, vector<int>& husband);

// n: number of men/women
// men_pref[m][i] = ith preference (woman idx) of man m
// women_pref[w][i] = ith preference (man idx) of woman w
// Output: wife[m] = the woman matched to man m; husband[w] = man matched to woman w
void gale_shapley(int n, const vector<vector<int>>& men_pref, const vector<vector<int>>& women_pref, vector<int>& wife, vector<int>& husband) {
    // For each woman, create a man preference ranking: woman_rank[w][m] = rank of man m in woman w's list
    vector<vector<int>> woman_rank(n, vector<int>(n));
    for (int w = 0; w < n; ++w)
        for (int rank = 0; rank < n; ++rank)
            woman_rank[w][women_pref[w][rank]] = rank;

    wife.assign(n, -1);    
    husband.assign(n, -1);
    vector<int> next_proposal(n, 0); // Next woman each man will propose

    queue<int> free_men;
    for (int m = 0; m < n; ++m)
        free_men.push(m);

    while (!free_men.empty()) {
        int m = free_men.front();
        free_men.pop();
        int w = men_pref[m][next_proposal[m]++];
        if (husband[w] == -1) {
            // Woman is free
            wife[m] = w;
            husband[w] = m;
        } else {
            int m_prime = husband[w];
            if (woman_rank[w][m] < woman_rank[w][m_prime]) {
                // Woman prefers new man
                wife[m] = w;
                husband[w] = m;
                free_men.push(m_prime); // old fiancé becomes free
                wife[m_prime] = -1;
            } else {
                free_men.push(m); // try next woman next time
            }
        }
    }
}

int main() {
    int n = 3;
    // Example preference lists (customize input as needed)
    vector<vector<int>> men_pref = {
        {0, 1, 2}, // man 0's preferences
        {2, 1, 0}, // man 1's preferences
        {1, 2, 0}  // man 2's preferences
    };
    vector<vector<int>> women_pref = {
        {2, 1, 0}, // woman 0's preferences
        {0, 1, 2}, // woman 1's preferences
        {2, 0, 1}  // woman 2's preferences
    };

    vector<int> wife(n), husband(n);
    gale_shapley(n, men_pref, women_pref, wife, husband);

    cout << "Matches:\n";
    for (int m = 0; m < n; ++m)
        cout << "Man " << m << " is engaged to Woman " << wife[m] << endl;
    return 0;
}