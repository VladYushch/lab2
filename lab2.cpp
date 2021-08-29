#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int32_t divisor = 0, quotient = 0,dividend=0,remainder=0;
    int64_t product = 0,temp=0;
    cout << "Input dividend:" << endl;
    cin >> dividend;
    cout << "Input divisor:" << endl;
    cin >> divisor;
    cout <<"Divisor:" << bitset<32>(divisor) << endl <<"Dividend" << bitset<32>(dividend) << endl;
    product += dividend;
    product <<= 1;
    cout << bitset<64>(product);
    temp += divisor;
    temp <<= 32;
    for (int i = 1; i <= 32; i++) {
        cout<<"Iteration:"<<i<<endl;
        product -= temp;
        if (product < 0 )
        {
            cout << "Left part of Remainder < Divisor. Left shift remainder on 1" << endl;
            product = product + temp;
            product <<= 1;
            cout << "Remainder: " << bitset<64>(product) << endl;

        }
        else
        {
            cout << "Left part of Remainder >= Divisor. Shift left reminder on 1 with rightmost bit to 1"<<endl;
            product = (product <<=1 )|1;

            cout<< "Remainder with quotient: " << bitset<64>(product) << endl ;
        }
    }
    
    cout << "Our result is: " << bitset<64>(product) << " ";
    temp = product ;
    temp <<= 32;
    temp >>= 32;
    quotient = temp;
    product >>= 33;
    remainder = product;
    cout << "where remainder is: " << bitset<32>(remainder) << " and quotient is: " << bitset<32>(quotient) << endl;
    cout << "Remainder: " << remainder << endl;
    cout << "Qutient: " << quotient << endl;




    return 0;
  
}
