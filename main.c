/* 

hi 

*/

#include "drivers/display.h"

static int volatile a;

int main(){
	int x = 1;
	int y = 2;
	int z = display();

	a = x + y + z;
}
