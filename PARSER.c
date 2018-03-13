#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FUNC.h"
#include "LIST.h"


//Функция парсинга всей командой строки
CMD_ITEM* parse_line(int argc, char* argv[])
{

	int i,j,n;
	n = 0;
	CMD_ITEM* parsed = (CMD_ITEM*)malloc(argc*sizeof(CMD_ITEM));
	CMD_ITEM temp;
	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-' && argv[i][1]!='h' && i!=(argc-1))
		{
			if(argv[i+1][0]!='-')
			{
				temp = one_arg(argv[i][1],argv[i+1]);
			}else{
				temp = one_arg(argv[i][1],NULL);
			}
			parsed[n] = temp;
			n++;
		}
		if(argv[i][0]=='-' && argv[i][1]!='h' && i==(argc-1)){
			temp = one_arg(argv[i][1],NULL);
			parsed[n] = temp;
		}
		if(argv[i][0] == '+' && argv[i][1]!='a')
		{
			test_a();			
		}
		if(argv[i][0]=='-' && argv[i][1]=='h')
		{
			help();
		}
	}

	return parsed;	
}

//Парсинг отдельного argv
CMD_ITEM one_arg(char _key, char* _val)
{
	int i;
	i = 0;
	while(LIST[i].key!=0)
	{
		if(_key == LIST[i].key)
		{
			LIST[i].value = _val;
			if(LIST[i].value!=NULL)LIST[i].mask = 1;
			return LIST[i];
		}
		i++;
	}
	printf("ERROR. Can't find key %c\n",_key);
	return LIST[i];
}

//Функция help - определение
void help()
{
	int i;
	i = 0;
	printf("");
	while(LIST[i].key!=0)
	{
		printf("%c%c\t%s\n",LIST[i].sgn,LIST[i].key,LIST[i].help);
		i++;
	}
	printf("");

}

//Функция A - определение
void test_a()
{
	printf("test # A\n");
}
