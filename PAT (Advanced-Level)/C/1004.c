#include <stdio.h>
#include <stdlib.h>

typedef struct child{
    int id;
    int fatherid;
    struct child *nextchild;
}Tchild, *Pchild;
//the fatherid is not necessary, even could use a dyadic-array/vector to slove it

typedef struct node{
    int level;
    struct child *childs;
}Tnode, *Pnode;



int main(int argc, char const *argv[]){
    int N, M;
    scanf("%d %d", &N, &M);
    Tnode nodes[N+1];
    for (int i = 1; i <= N; i++){ //index as the node's id
        nodes[i].level = -1;
        nodes[i].childs = NULL;
    }
    nodes[1].level = 0; //nodes[1] is the root whose level is 0
    int K, id, fatherid;
    for (int i = 0; i < M; i++){ //each non-leaf node's links their childnodes
        scanf("%d %d", &fatherid, &K);
        for (int j = 0; j < K; j++){
            scanf("%d", &id);
            Pchild tempChildNode = (Pchild)malloc(sizeof(Tchild));
            tempChildNode->id = id;
            tempChildNode->fatherid = fatherid;
            tempChildNode->nextchild = nodes[fatherid].childs;
            nodes[fatherid].childs = tempChildNode;
        }
    }

    int maxlevel = 0;   //modify the each node's level, and actually, the i is the fatherid
    for (int i = 1; i <= N; i++){
        int childid, fatherid;
        Pchild temp = nodes[i].childs;
        while(temp != NULL){
            childid = temp->id; fatherid = temp->fatherid;
            nodes[childid].level = nodes[fatherid].level+1;
            if(nodes[childid].level > maxlevel)
                maxlevel = nodes[childid].level;
            temp = temp->nextchild;
        }
    }

    int count = 0;
    for (int i = 0; i <= maxlevel; i++){
        count = 0;
        for (int j = 1; j <= N; j++){
            if(nodes[j].level == i){
                if(nodes[j].childs == NULL)
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
在循环遍历每一个结点，修改其正确的level层次,并记录maxlevel
最后计算每一层的non-leaf数 
*/ 
