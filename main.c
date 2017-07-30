#include "donate.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
	struct college_info *college = create_with_console();
	print(college); 
	return 0;
}

