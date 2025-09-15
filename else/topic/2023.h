#include <vector>
#include<stack>
using namespace std;

bool test1(vector<int> array){
    stack<int> S;
    for (int i = 0; i < array.size()/2; i++)
    {
        S.push(array[i]);
    }
    int tag = array.size()%2;
    for(int i = array.size()/2 + tag;i<array.size();i++){
        if (S.top() != array[i])
        {
            return false;
        }
        S.pop();
    }
    return true;
}

