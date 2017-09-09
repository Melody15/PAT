#include <stdio.h>
#include <string.h>

typedef struct question
{
    int score;
    int anserNum;
    int rightAnswerNum;
    char answers[5];
    int wrongNum;
}questionInfo;

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    char ch;
    int flat = 0; //0 means no wrong
    questionInfo question[M + 1];
    int maxWrongNum = 0;
    for (int i = 1; i <= M; ++i){
        int j = 0;
        //memset(question[i].answers,'\0',sizeof(question[i].answers));
        scanf("%d %d %d", &question[i].score, &question[i].anserNum, &question[i].rightAnswerNum);
        while((ch = getchar()) != '\n'){
            if(ch >= 'a' && ch <= 'e'){
                question[i].answers[j++] = ch;
            }
        }
        question[i].answers[j] = '\0';
        question[i].wrongNum = 0;
    }
    int studentAnswerNum;
    int studentScore[N];
    char studentAnswers[5];
    for (int i = 0; i < N; ++i){
        memset(studentAnswers,'\0',sizeof(studentAnswers)); //clear
        studentScore[i] = 0; //clear
        for (int j = 1; j <= M; ++j)
        {
            int k = 0;
            getchar();;//clear '('
            scanf("%d ", &studentAnswerNum);
            if(studentAnswerNum != question[j].rightAnswerNum){
                flat = 1; //wrong answer
                question[j].wrongNum++;
                if(question[j].wrongNum > maxWrongNum)
                    maxWrongNum = question[j].wrongNum;
                while((ch = getchar()) != ')') ;
                getchar(); // clear space or enter
            }else if(studentAnswerNum == question[j].rightAnswerNum){
                while((ch = getchar()) != ')'){
                    if(ch >= 'a' && ch <= 'e'){
                        studentAnswers[k++] = ch;
                    }
                }
                studentAnswers[k] = '\0';
                getchar(); // clear space or enter
                if(strcmp(question[j].answers, studentAnswers) == 0){
                    studentScore[i] += question[j].score;
                }else{
                    flat = 1; //wrong answer
                    question[j].wrongNum++;
                    if(question[j].wrongNum > maxWrongNum)
                        maxWrongNum = question[j].wrongNum;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i){
        printf("%d\n", studentScore[i]);
    }
    if(flat == 1){
        printf("%d", maxWrongNum);
        for(int i = 1; i <= M; ++i){
            if(question[i].wrongNum == maxWrongNum)
                printf(" %d", i);
        }
    }else if(flat == 0)
        printf("Too simple");
    
    return 0;
}
