#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

    double VS,R,C,w,VR;
    int n;

    while(cin>>VS>>R>>C>>n){
        for (int i = n; i > 0; i--){
            cin>>w;
            VR = C * R * w * VS * sqrt(1/(1 + (C * R * w)*(C * R * w)));
            cout<<fixed<<setprecision(3)<<VR<<endl;
        }
    }

    return 0;
}
