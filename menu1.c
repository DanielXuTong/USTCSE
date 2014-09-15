/******************************************************************************/
/*  Copyright (C)sse.ustc.edu.cn,  2014-2015                                  */
/*                                                                            */
/*  FILE NAME              :  menu.c                                          */
/*  PRINCIPAL AUTHOR       :  Xutong                                          */
/*  SUBSYSTM NAME          :  menu                                            */
/*  MODULE NAME            :  menu                                            */
/*  LANGUAGE               :  c                                               */
/*  TARGET ENVIROMENT      :  ANY                                             */
/*  DATE OF FIRST RELEASE  :  2014/09/15                                      */
/*  DESCRIPTION            :  This is a menu program                          */
/******************************************************************************/


/*
* Revision log;
*
* Created by Xutong, 2014/09/15
*
*/

#include<stdio.h>
#include<stdlib.h>


int Help();


#define CMD_MAX_LEN  128
#define DESC_LEN     1024
#define CMD_NUM      10
#define CMD_ROW		 20

/* data struct and its operations*/

typedef struct DataNode
{
	int	   i;
    char*  cmd;
    char*  desc;
    int    (*handler)[CMD_ROW];
    struct DataNode *next;
}tDataNode;

tDataNode* FindCmd(tDataNode * head, char * cmd)
{
	int j=0;
    if(!head || !cmd)
    {
		head->i == 0;
        return NULL;        
    }
    tDataNode *p = head;
    while(p)
    {
        if(!strcmp(p->cmd, cmd))
        {
			p->i == j;
            return p;
        }
		p->i =j++;
        p = p->next;
    }
    return NULL;
}
int ShowAllCmd(tDataNode *head[i])
{
    printf("Menu List:\n");
    tDataNode *p =head[i];
    while(p)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p = p->next;
    }
    return 0;
}


/* menu program*/
static tDataNode head[] =
{
    {"help",				"this is help cmd!",				Help[0],	&head[1]}, 
    {"version",				"menu program v1.0",				Help[1],	&head[2]},
	{"Copyright",			"(C)sse.ustc.edu.cn, 2014-2015",	Help[2],	&head[3]},	
	{"FILE NAME",			"menu.c",							Help[3],	&head[4]}，
	{"PRINCIPAL AUTHOR",	"Xutong",							Help[4],	&head[5]},
	{"SUBSYSTM NAME",		"menu",								Help[4],	&head[6]},
	{"MODULE NAME",			"menu",								Help[5],	&head[7]},
	{"LANGUAGE",			 "C",								Help[6],	&head[8]},
	{"TARGET ENVIROMENT",	 "ANY",								Help[7],	&head[9]},
	{"DATE OF FIRST RELEASE","2014/09/15",						Help[8],	&head[10]},
	{"DESCRIPTION",			"This is a menu program",			Help[9],	NULL    }
};


int Help(int i)
{
    ShowAllCmd(head[i]);
    return 0;
}


main()
{
    /*cmd line begins*/
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number >");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
       if(!p)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n",p->cmd,p->desc);
        if(p->handler[p->next->i]) 
        { 
            p->handler()[p->next->i];
        }
    }
}

