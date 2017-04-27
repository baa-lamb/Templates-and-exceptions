#include "17.h"
#include "classPOINT.h"

int main()
{
	int n = 3;
	try {
		Point c(1,1,1);
		Point v(2,2,2);
		Point g(3,3,3);
		Matrix <Point> a(n,n);
		a.set_line(c,0);
		a.set_line(v,1);
		a.set_line(g,2);	

		a.print();
	}
	catch (char *str) {
		cout <<"Your result is:\n";		
		cout<<str;
	}
	return 0;
}