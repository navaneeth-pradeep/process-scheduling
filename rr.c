#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int at;
	int wt;
	int tat;
	int bt;
	int bt_const;
}Proc;


Proc init_proc(int bt){
	Proc p;
	p.at = 0;
	p.bt = bt;
	p.wt = 0;
	p.tat = 0;
	p.bt_const = bt;
	return p;
}





int main(void){
	Proc *p;
	int bt,i,n=0,t=0,q=0;
	scanf("%d",&n);
	scanf("%d",&q);
	p = (Proc*) malloc(sizeof(Proc)*n);
	for(i=0;i<n;++i){
		scanf("%d",&bt);
		p[i] = init_proc(bt);	
	}	

	int n1=n,x=q,j;

	while(n1>0){
		for(i=0;i<n;++i){
			if(p[i].bt == 0){
				n1--;
				continue;
			}
			x = p[i].bt < q?p[i].bt:q;
			p[i].bt-=x;
			for(j=0;j<n;++j){
				if(i==j || p[j].bt == 0) continue;
				p[j].wt += x;
			}
		}

	}


	for (i=0;i<n;++i){
		p[i].tat = p[i].wt + p[i].bt_const;
		printf("Burst Time:%d TAT:%d WT:%d\n",p[i].bt_const,p[i].tat,p[i].wt);	
	}
	free(p);
	return 0;
}

