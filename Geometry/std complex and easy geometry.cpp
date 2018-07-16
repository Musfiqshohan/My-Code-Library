#include<iostream>
#include<complex>
#include<bits/stdc++.h>
using namespace std;

/// define x, y as real(), imag()
typedef complex<double> point ;
#define x real()
#define y imag()

int main()
{
    //double num=20;
    point a(5,3);
    point b(6,2);
    point c(1,1);

    cout<< a<<" "<<b<<endl;


    cout<< (conj(b-c)*(a-c)).y<<endl;
    cout<< (conj(a-c)*(b-c)).y<<endl;



///// vector addition and subtraction
//    printf("Addition , subtraction ,Multiplication \n");
//    cout<<a+b<<endl;
//    cout<<a-b<<endl;
//    cout<<a*b<<endl;
//
///// scalar multiplication
//    printf("Scalar multiplication:\n");
//    cout<<3.0*a<<endl;
//    cout<< a/5.0<<endl;
//
/////dot product
//    printf("Dot product:\n");
//    cout<<  (conj(a)*b).x <<endl;
//    cout<<  (conj(b)*a).x <<endl;
//
//    cout<< (conj(a)*b).y<<endl;
//    cout<< cross(a,b)<<endl;
//
//    cout<< norm(a-b)<<endl;
//    cout<< abs(a-b)<<endl;
//
//
//     cout<<arg(b-a)<<endl;
//     cout<<tan(arg(b-a))<<endl;
//
//     cout<<polar(1,90)<<endl;
//     cout<< point(abs(b-a), arg(b-a))<<endl;

    return 0;
}
