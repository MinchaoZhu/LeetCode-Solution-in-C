#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***
KMP match
*/

int strStr(char* hs, char* ne) 
{
    if (!strlen(hs) && !strlen(ne))
		return 0;
	if (!hs || !ne )
		return -1;
	if (strlen(hs) < strlen(ne))
		return -1;
	if (!strlen(ne))
		return 0;
	int p = 0;
	int cur=0;
	int op=0;
	int pos=-1;
	int flag=1;
	for (cur=0; hs[cur];)
	{
		if (hs[cur] == ne[0])
		{
			flag = 1;
			op = cur;
			p = 0;
			pos = -1;
			for (; ne[p];++p,++op)
			{
				if (!hs[op])
					return -1;
				if (ne[0] == hs[op] && op != cur && pos == -1)
					pos = op; 
				if (ne[p] != hs[op])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				return cur;
			else
			{
				if (pos != -1)
					cur = pos;
				else
					++cur;
			}
		}
		else
			++cur;
	}
	return -1;
}

int main(void){
    char * haystack = "aaabaaabcabaaabdc";
    char * needle = "aaabd";
    int pos = strStr(haystack,needle);
    printf("%d", pos);
    return 0;
}