for (int k = n - i - 1; k >= 0; k--)
        {
            if((i%2 != 0 && k%2 == 0) || (i%2 == 0 && k%2 != 0)){
            cout << "*";
            }else{
            cout << " ";
            }
        }