// Design Twitter
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

class TwitterPriorityQueue {
public:
    int tweetIdCounter;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollowing;

    TwitterPriorityQueue() : tweetIdCounter(0) {}

    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(tweetIdCounter++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> recentTweets;
        unordered_set<int> followedUsers;
        
        followedUsers.insert(userId);
        for (int followee : userFollowing[userId]) {
            followedUsers.insert(followee);
        }

        for (int u : followedUsers) {
            for (auto& tweet : userTweets[u]) {
                recentTweets.emplace(tweet.first, tweet.second);
            }
        }

        vector<int> feed;
        while (feed.size() < 10 && !recentTweets.empty()) {
            feed.push_back(recentTweets.top().second);
            recentTweets.pop();
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }
};

