#include <iostream>
#include <vector>
#include <algorithm> // for sort and upper_bound
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> prices;
    prices.reserve(n); // Reserve space to avoid multiple reallocations
    int price;
    for (int i = 0; i < n; ++i) {
        cin >> price;
        prices.push_back(price);
    }
 
    sort(prices.begin(), prices.end());
 
    int days;
    cin >> days;
    int budget;
    for (int i = 0; i < days; ++i) {
        cin >> budget;
        // Use upper_bound to find the first element greater than budget
        int pshops = upper_bound(prices.begin(), prices.end(), budget) - prices.begin();
        cout << pshops << "
";
    }
 
    return 0;
}