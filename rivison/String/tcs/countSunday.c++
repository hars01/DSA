#include<bits/stdc++.h>
using namespace std;

int main() {
    string startDay;
    int n;

    cin >> startDay;   // starting day (mon, tue, wed, ...)
    cin >> n;          // number of days

    unordered_map<string, int> dayIndex = {
        {"mon", 0}, {"tue", 1}, {"wed", 2},
        {"thu", 3}, {"fri", 4}, {"sat", 5},
        {"sun", 6}
    };

    int start = dayIndex[startDay];

    // Days to reach first Sunday
    int daysToFirstSunday = (7 - start) % 7;

    int count = 0;

    if (daysToFirstSunday < n) {
        count = 1; // first Sunday
        int remainingDays = n - daysToFirstSunday - 1;
        count += remainingDays / 7;
    }

    cout << count;
    return 0;
}
