//
// Created by zhao on 19-4-7.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_heap_test()
{
    srand((unsigned)time(NULL));

    vector<int> a(9,0);
    for(int i=0;i!=9;++i)
    {
        a[i]=rand()%(8+1)+1;
    }
    for(int i:a)
        cout<<i<<" ";
    cout<<endl;

    make_heap(a.begin(),a.end());
    for(int i:a)
        cout<<i<<" ";
    cout<<endl;

    pop_heap(a.begin(),a.end());
    for(int i:a)
        cout<<i<<" ";
    cout<<endl;

    sort_heap(a.begin(),a.end());
    for(int i:a)
        cout<<i<<" ";
    cout<<endl;



    return 0;
}


