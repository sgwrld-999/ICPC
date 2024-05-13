#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern3(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j >= 0 ; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            cout << j ;
        }
        cout << endl;
    }
}

void pattern5(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            cout << "*" ;
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j >= 0 ; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j > 0 ; j--)
        {
            cout << " " ;
        }
        for (int  k = 1; k < i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern7(int n){
    for (int i = 1 ; i <= n ; i++)
    {
        for (int k = 1 ; k < i ; k++)
        {
            cout << " " ;
        }
        for (int j = n-i+1 ; j > 0 ; j--)
        {
            cout << "*" ;
        }
        
        cout << endl;
    }
}

void pattern8(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j > 0 ; j--)
        {
            cout << " " ;
        }
        for (int  k = 1; k <= i; k++)
        {
            cout << "*";
        }
        for (int  l = 1; l <= i-1; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern9(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int  k = 1; k <= i-1; k++)
        {
            cout << " ";
        }
        for (int j = n-i+1; j > 0 ; j--)
        {
            cout << "*" ;
        }
        for (int  l = 1; l < n-i+1; l++)
        {
            cout << "*";
        }
        
        
        cout << endl;
    }
}

void pattern10(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for (int k =  1; k <= i ; k++)
        {
            bool flag = false;
            if(!flag && (k%2 != 0 || k == 1)){
                cout << "*";
                flag = true;
            }
            else{
                cout << " ";
                flag = false;
            }
        }
        for (int l = 1; l <= i ; l++)
        {
            if(i%2 != 0 && l%2 == 0){
                cout << "*";
            }
            else if(i%2 != 0 && l%2 != 0){
                cout << " ";
            }
            else if(i%2 == 0 && l%2 != 0){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    int n = 5;
    pattern10(n);
    return 0;
}
