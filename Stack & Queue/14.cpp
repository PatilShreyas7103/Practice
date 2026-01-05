// Online Stock Span

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n) per next() call
Space: O(n)

Idea:
For each new price, traverse backwards until a greater price is found.
Count consecutive days where price <= current price.
*/
class StockSpannerBruteForce {
public:
    vector<int> prices;

    StockSpannerBruteForce() {}

    int next(int price) {
        prices.push_back(price);
        int cnt = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] <= price) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};

/*
Approach 2: Monotonic Stack (Optimized)
Time: O(1) amortized per next() call
Space: O(n)

Idea:
Maintain a decreasing stack of indices.
Pop all prices smaller than or equal to current price.
Span = current index - previous greater element index.
*/
class StockSpannerStack {
public:
    vector<int> prices;
    stack<int> st;

    StockSpannerStack() {}

    int next(int price) {
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int prevGreaterIdx = st.empty() ? -1 : st.top();
        st.push(prices.size() - 1);

        return (prices.size() - 1) - prevGreaterIdx;
    }
};