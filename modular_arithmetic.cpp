#include <iostream>
using namespace std;
typedef long long ll;

ll modularExponentiation(ll x,ll n, const ll& M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

ll modularAddition(const ll& a, const ll& b, const ll& M)
{
	return ((a%M)+(b%M))%M;
}

ll modularSubtraction(const ll& a, const ll& b, const ll& M)
{
	return ((a%M)-(b%M) + M)%M;
}

ll modularMultiplication(const ll& a, const ll& b, const ll& M)
{
	return ((a%M)*(b%M))%M;
}

ll gcd(ll a, ll b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}

class extended_euclid
{
	ll d,x,y;
	void extendedEuclid(ll A, ll B) {
		if(B == 0) {
			d = A;
			x = 1;
			y = 0;
		}
		else {
			extendedEuclid(B, A%B);
			int temp = x;
			x = y;
			y = temp - (A/B)*y;
		}
	}
public:	
	pair<ll,ll> calculate(ll a, ll b)
	{
		extendedEuclid(a,b);
		return make_pair(x,y);
	}
};
ll modInverse(ll A, ll M)
{
    pair<ll,ll> result = extended_euclid().calculate(A,M);
    ll x = result.first;
    return (x%M+M)%M;    //x may be negative
}

ll modularDivision(const ll& a, const ll& b, const ll& M)
{
	return ((a%M)*(modInverse(b,M)%M))%M;
}

int main() {
	ll m = 1000000007;
	ll a = -90000000;
	ll b =  80000000;
	
    cout << modularAddition(a,b,m) << endl;
    cout << modularSubtraction(a,b,m) << endl;
    cout << modularDivision(a,b,m) << endl;
    cout << modularMultiplication(a,b,m) << endl;
    cout << modularExponentiation(a,b,m) << endl;
    

	return 0;
}
