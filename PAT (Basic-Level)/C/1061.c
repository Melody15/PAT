#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    int score[M];
    int answer[M];
    int answerByStudent;
    int studentScore[N];
    int tempScore;
    for (int i = 0; i < M; ++i){
        scanf("%d", &score[i]);
    }
    for (int i = 0; i < M; ++i){
        scanf("%d", &answer[i]);
    }
    for (int j = 0; j < N; ++j)
    {
        tempScore = 0;
        for (int i = 0; i < M; ++i)
        {
            scanf("%d", &answerByStudent);
            if(answerByStudent == answer[i]){
                tempScore += score[i];
            }
        }
        studentScore[j] = tempScore;
    }
    for (int i = 0; i < N; ++i)
    {
        printf("%d\n", studentScore[i]);
    }
    return 0;
}