#include "Move.h"

int main()
{
	Move a(2, 3);
	a.showmove();
	Move b(4, 6);
	Move c = b.add(a);
	c.showmove();
}