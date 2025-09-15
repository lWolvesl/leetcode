//
// Created by 李洋 on 2023/10/7.
//

#ifndef LEECODE_C_Q901_H
#define LEECODE_C_Q901_H

#include <stack>

using namespace std;

class trendSpanner {
public:
    trendSpanner() {}

    int next(int price) {
        count = 1;

        if (trend.size() == 0 || price < trend.top()->value) {
            trend.push(new stock{price, 1});
            return count;
        }

        while (!trend.empty() && price >= trend.top()->value) {
            count += trend.top()->value;
            stock *temp = trend.top();
            trend.pop();
            delete (temp);
        }

        trend.push(new stock{price, count});
        return count;
    }

private:
    struct stock {
        int key;
        int value;
    };
    stack<stock *> trend;
    int count;
};
/**
 * Your trendSpanner object will be instantiated and called as such:
 * trendSpanner* obj = new trendSpanner();
 * int param_1 = obj->next(price);
 */

#endif LEECODE_C_Q901_H