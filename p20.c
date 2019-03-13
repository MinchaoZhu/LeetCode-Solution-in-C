#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define INIT_SIZE 20 //最初初始化栈的存储空间
#define ADD_SIZE 10	//空间不足时，一次性新加入的栈的空间

typedef char _DATA_TYPE;

typedef struct{
	_DATA_TYPE * bottom;
	_DATA_TYPE * top;
	int stacksize;
}stack;

stack * stack_create()//创建一个栈
{
	stack * s;
	s = malloc(sizeof(stack));
	return s;
}

void stack_init(stack * s) //初始化一个栈
{
	s -> bottom = malloc(INIT_SIZE *sizeof(_DATA_TYPE));
	s -> top = s -> bottom;
	s -> stacksize = INIT_SIZE;
}	

_DATA_TYPE push(stack * s, _DATA_TYPE data) //在栈顶压入一个元素
{
	if( s->top - s->bottom >= s->stacksize)
	{
		int n;
		n = s->top - s-> bottom;
		s->bottom = (_DATA_TYPE *) realloc(s->bottom,(ADD_SIZE + s->stacksize) * sizeof(_DATA_TYPE));
		s->top = s->bottom + n;
		s->stacksize = 10 + s->stacksize;
	}	
	*(s -> top) = data;
	s -> top  = s -> top + 1;
	return data;  
}

_DATA_TYPE pop(stack * s) //栈顶取出一个元素并返回
{
	if( s->top > s->bottom)
	{		
		_DATA_TYPE data;
		data = *(s -> top - 1);
		(s -> top)--;
		return data;	
	}
}

void stack_clear(stack * s)//清空栈中的数据
{
	s -> top = s -> bottom;
	s -> stacksize = 0;
}

void stack_del(stack * s)//删除并销毁栈的data存储区
{
	free(s->bottom);
	s->bottom = NULL;
	s->top = NULL;
	s->stacksize = 0;
}

int stack_size(stack * s) //返回栈已被使用的元素个数
{
	int i;
	i = s->top - s->bottom;
	return i;
}

_Bool if_l_bra(char ch) //判断字符是否是左括号，是则返回1，否则返回0
{
	switch(ch){
	case '(': return 1;break;
	case '[': return 1;break;
	case '{': return 1;break;
	default : return 0;
	}

}

_Bool if_r_bra(char ch) //判断字符是否是右括号，是则返回1，否则返回0
{
	switch(ch){
	case ')': return 1;break;
	case ']': return 1;break;
	case '}': return 1;break;
	default : return 0;
	}

}

char r2l(char r_ch) //返回对应右括号的左括号
{
	switch(r_ch){
	case ')': return '(';break;
	case ']': return '[';break;
	case '}': return '{';break;
	}
}







bool isValid(char* s) {
    stack * b_stack = stack_create();
    stack_init (b_stack);
    char str_temp, * p_temp, match_temp;
	_Bool m_v = 1;

	p_temp = s;
	str_temp = *(p_temp);

	do
	{
		if(if_l_bra(str_temp)) //忽略字符串中的非括号
		{			
			push(b_stack, str_temp); //如果字符是左括号，压入栈中
		}	
		else if(if_r_bra(str_temp)) //如果字符是右括号，则取出栈中第一个元素判断是否为对应左括号
		{
			match_temp = pop(b_stack);
			if(r2l(str_temp) != match_temp)
			{
				return 0; //判断失败则括号不匹配
				break;
			}
		} 
		p_temp++;
		str_temp = *(p_temp);
	}while(str_temp != '\0');

	if(stack_size(b_stack) != 0) //最终栈非空则括号不匹配
	{
		return 0;;
	}
	return 1;
}



int main(void){
    char *s = "[(){}]"; 
    int i;
    i = isValid(s);
    printf("%d",i);

    return 0;
}