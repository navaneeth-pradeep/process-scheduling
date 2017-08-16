#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int at;
	int wt;
	int tat;
	int bt;
	int p;
}Proc;


Proc init_proc(int bt,int pr){
	Proc p;
	p.at = 0;
	p.bt = bt;
	p.wt = 0;
	p.tat = 0;
	p.p = pr;
	return p;
}


void swap_proc(Proc* p1, Proc* p2){
	Proc temp;
	temp.at = p1->at;
	temp.bt = p1->bt;
	temp.wt = p1->wt;
	temp.tat = p1->tat;
	temp.p = p1->p;
	p1->at = p2->at;
	p1->bt = p2->bt;
	p1->wt = p2->wt;
	p1->tat = p2->tat;
	p1->p = p2->p;
	p2->at = temp.at;
	p2->bt = temp.bt;
	p2->wt = temp.wt;
	p2->tat = temp.tat;
	p2->p = temp.p;
}



void sort_procs(Proc p[],int n){
	int i,j;
	for(i=0;i<n-1;++i){
		for(j=0;j<n-i-1;++j)
			if(p[j].p > p[j+1].p){
				swap_proc(&p[j],&p[j+1]);			
			}	
	}
}



int main(void){
	Proc *p;
	int at,bt,i,n=0,t=0;
	scanf("%d",&n);
	p = (Proc*) malloc(sizeof(Proc)*n);
	for(i=0;i<n;++i){
		scanf("%d",&at);
		scanf("%d",&bt);
		p[i] = init_proc(at,bt);	
	}	
	sort_procs(p,n);
	
	for(i=0;i<n;++i){
		p[i].wt = t;	
		t+=p[i].bt;
		p[i].tat = p[i].wt + p[i].bt;
	}
		
	
	for (i=0;i<n;++i){
		printf("Priority:%d Burst Time:%d TAT:%d WT:%d\n",p[i].p,p[i].bt,p[i].tat,p[i].wt);	
	}
	free(p);
	return 0;
}

