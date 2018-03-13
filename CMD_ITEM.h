#pragma once
struct CMD_ITEM {
	char sgn;
	char key;
	int mask;
	char* value;
	char* help;
};

typedef struct CMD_ITEM CMD_ITEM;
