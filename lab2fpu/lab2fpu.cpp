#include <iostream>
#include <bitset>
using namespace std;

int main()
{

    float firstfl, secondfl;
    cin >> firstfl;
    cin >> secondfl;
    cout << firstfl<<endl;
    cout << secondfl<<endl;
    //now torture them
    uint32_t firstnum = reinterpret_cast<uint32_t&>(firstfl);
    uint32_t secondnum = reinterpret_cast<uint32_t&>(secondfl);

    if (abs(secondfl) > abs(firstfl))
    {
        cout << "Second number is bigger than first. Swapping." << endl;
        uint32_t buffer = firstnum;
        firstnum = secondnum;
        secondnum = buffer;
    }
    cout << "Number 1 is: " << bitset<32>(firstnum) << endl;
    cout << "Number 2 is: " << bitset<32>(secondnum) << endl;
    uint32_t e1, e2, m1, m2, ediff;
    e1 = (firstnum << 1) >> 24;
    cout << "Exponent 1 is: " << bitset<8>(e1) << endl;
    e2 = (secondnum << 1) >> 24;
    cout << "Exponent 1 is: " << bitset<8>(e2) << endl;
    m1 = ((firstnum << 9) >> 9) | (1 << 23);
    cout << "Mantissa 1 is: " << bitset<23>(m1) << endl;
    m2 = ((secondnum << 9) >> 9) | (1 << 23);
    cout << "Mantissa 2 is: " << bitset<23>(m2) << endl;
    ediff = e1 - e2;
    cout << "Exponent difference is: " << ediff << endl;
    m2 >>= ediff;
    cout << "Shifting mantissa 2 by " << ediff << " bits right: " << bitset<23>(m2) << endl << endl;
    //Binary points aligned.
    cout << "Significands of first:  " << endl << bitset<23>(m1) << endl;
    cout << "Significands of second: " << endl << bitset<23>(m2) << endl;
    uint32_t mresult;

    if (firstnum >> 31 == secondnum >> 31)
    {
        cout << "adding" << endl;
        mresult = m1 + m2;
    }
    else
    {
        cout << "subtracting" << endl;
        mresult = m1 - m2;
    }

    cout << "Mantissa result is: " << bitset<32>(mresult) << endl;
    uint32_t eresult = e1;
    bool flag = false;

    do
    {
        flag = false;
        if (mresult & 0xFF000000)
        {
            cout << "Invisible 1 shifted too far. Shifting mantissa right and increasing exponent.";
            flag = true;
            mresult >>= 1;
            eresult++;
        }
    } while (flag);
    //reassembling number
    uint32_t endresult;
    float endresultf;
    endresult = 0;
    cout << bitset<32>(endresult)<<endl;
    endresult <<= 8;
    cout << bitset<32>(endresult) << endl;
    endresult += e1;
    cout << bitset<32>(endresult) << endl;
    endresult <<= 23;
    cout << bitset<32>(endresult) << endl;
    endresult += (mresult ^ (1 << 23));
    cout << bitset<32>(endresult) << endl;
    endresultf = reinterpret_cast<float&>(endresult);
    cout << "End result is: " << bitset<32>(endresult) << endl;
    cout << "End result is: " << (endresultf);

    return 0;
}