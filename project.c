#include <stdio.h>
#include <stdlib.h>



typedef struct edge{
    int a1;
    int a2;
    int c;

} edge;



typedef struct returnVal{
    int cost;
    int numr;
    int numa;

} returnVal;



int cmp(const void * a, const void * b)
{
    
    edge *a1  =(edge *)a;
    edge *a2  = (edge *)b;
    if(a1->c > a2->c){
        return(1);
    }
    else{
        return(-1);
    }
   
    }



int find(int i, int subgraphs[]){
    while(i!= subgraphs[i]){
        i = subgraphs[i];
    }
    return(i);
}

void unionf(int a, int b, int subgraphs[]){
    int i = find(a,  subgraphs);
    int j = find(b,  subgraphs);
    subgraphs[i] = j;
}





returnVal kruskalRailway(int N , edge l[], int len1){
int len2 = 0;
edge *list1 = l;
int i = 0;


int subgraphs[N];

qsort(list1, len1, sizeof(struct edge),cmp);

i=0;
int visited[N];
 while(i<N){
    visited[i] = 0;
    subgraphs[i] = i;
    i+=1;
    
 }

returnVal r;
r.cost = 0;
int len_visited =0;
i = 0;
while(i<len1){
edge next = list1[i];
int a = find( next.a1,  subgraphs);
int b = find( next.a2,  subgraphs);
if(a!=b){
unionf(a, b, subgraphs);
    if(visited[ next.a1]==0){
        visited[ next.a1]= 1;
        len_visited +=1;
    }
    if(visited[next.a2]==0){
        visited[next.a2]= 1;
        len_visited +=1;
    }
r.cost +=next.c;
len2 +=1;
}
i+=1;
}
if(len_visited!= N){
    returnVal r;
    r.cost = -1;
    r.numa = 0;
    r.numr = 0;
    return(r);
}
else{
r.numr = len2;
r.numa = 0;
return(r);

}
}

returnVal kruskalAirport(int N , edge l[], int len1){
int len2 = 0;
edge *list1 = l;
int i = 0;
int subgraphs[N];
qsort(list1, len1, sizeof(struct edge),cmp);

i=0;
int visited[N];
 while(i<N){
    visited[i] = 0;
    subgraphs[i] = i;
    i+=1;
    
 }

returnVal r;
r.cost = 0;
r.numa = 0;
int len_visited =0;
i = 0;
while(i<len1){
edge next = list1[i];
int a = find( next.a1,  subgraphs);
int b = find( next.a2,  subgraphs);
if(a!=b){
unionf(a, b, subgraphs);
    if(visited[ next.a1]==0){
        visited[ next.a1]= 1;
        len_visited +=1;
    }
    if(visited[next.a2]==0){
        visited[next.a2]= 1;
        len_visited +=1;
    }
r.cost +=next.c;
if(next.a2 == N-1){
    r.numa +=1;
}
len2 +=1;
}
i+=1;
}


if(len_visited!= N){
    returnVal r;
    r.cost = -1;
    r.numa = 0;
    r.numr = 0;
    return(r);
}

else{
r.numr = len2-r.numa;
return(r);

}
}



int main(){
    
int N = 0;
scanf("%d\n", &N);

int i = 0;
int n1=0;
int air=0;
int cost=0;
scanf("%d\n", &n1);

int costsA[n1];
int a1a[n1];

i=0;
while(i<n1){ 
    scanf("%d %d\n", &air, &cost);
    costsA[i] = cost;
    a1a[i] = air;

    i+=1;
}



int n2=0;
int a1=0;
int a2=0;
int cost1=0;
scanf("%d\n", &n2);

edge list1[n1+n2];


i = 0;
while(i<n2) {
    scanf("%d %d %d\n", &a1, &a2, &cost1);
    list1[i].a1 = a1-1;
    list1[i].a2 = a2-1;
    list1[i].c = cost1;
    i+=1;

}

returnVal r;
r = kruskalRailway(N, list1, n2);

i=0;
while(i<n1){
list1[n2+i].a1 = a1a[i]-1;
list1[n2+i].a2 = N;
list1[n2+i].c = costsA[i];
i+=1;

}
/*DFS*/

returnVal a;

a = kruskalAirport(N+1, list1, n1+n2);

if(r.cost==-1 && a.cost ==-1){
    printf("Impossible\n");
}
else if((r.cost<= a.cost &&  r.cost != -1 )|| a.cost == -1){
printf("%d\n%d %d\n", r.cost,r.numa,r.numr);
}
else{
printf("%d\n%d %d\n", a.cost,a.numa,a.numr);
}

return(0);
}

