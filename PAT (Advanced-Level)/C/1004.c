#include <stdio.h>
#include <stdlib.h>

typedef struct child{
    int id;
    int fatherid;
    struct child *nextchild;
}Tchild, *Pchild;

typedef struct node{
    int level;
    struct child *childs;
}Tnode, *Pnode;



int main(int argc, char const *argv[]){
    int N, M;
    scanf("%d %d", &N, &M);
    Tnode family[N+1];
    for (int i = 1; i <= N; i++){
        family[i].level = -1;
        family[i].childs = NULL;
    }
    family[1].level = 0;
    int K, id, fatherid;
    int maxlevel = 0;
    for (int i = 0; i < M; i++){ 
        scanf("%d %d", &fatherid, &K);
        for (int j = 0; j < K; j++){
            scanf("%d", &id);
            Pchild node = (Pchild)malloc(sizeof(Tchild));
            node->id = id;
            node->fatherid = fatherid;
            node->nextchild = family[fatherid].childs;
            family[fatherid].childs = node;
        }
    }
    
    for (int i = 1; i <= N; i++){
        int childid, fatherid;
        Pchild temp = family[i].childs;
        while(temp != NULL){
            childid = temp->id; fatherid = temp->fatherid;
            family[childid].level = family[fatherid].level+1;
            if(family[childid].level > maxlevel)
                maxlevel = family[childid].level;
            temp = temp->nextchild;
        }
    }

    int count = 0;
    for (int i = 0; i <= maxlevel; i++){
        count = 0;
        for (int j = 1; j <= N; j++){
            if(family[j].level == i){
            	if(family[j].childs == NULL)
            		count++;
			}
        }
        if(i < maxlevel)
        	printf("%d ", count);   
		else
			printf("%d", count); 
    }
    return 0;
}

/*
先读取每个non-leaf结点的子结点数据，并将其挂在父节点的链表下。
在循环遍历每一个结点，修改其正确的level层次
最后计算每一层的non-leaf数 
*/ 
