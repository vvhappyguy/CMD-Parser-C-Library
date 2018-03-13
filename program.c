#include "FUNC.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	int i;	//счётчик
	CMD_ITEM* cmd_lines = parse_line(argc,argv);
	for(i=0;i < argc; i++){
		CMD_ITEM cmd_line = cmd_lines[i];
	if(cmd_line.key!=0)
		printf("Key %c has been found with value: %s\n", cmd_line.key, cmd_line.value);
	}
	return 0;
}
