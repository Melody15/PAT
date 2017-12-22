#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int N, fullScore;
    scanf("%d %d", &N, &fullScore);
    for (int i = 0; i < N; i++){
        int score, scoreSum = 0, count = 0;
        int maxScore = INT_MIN, minScore = INT_MAX, teacherScore, result;
        scanf("%d", &teacherScore);
        for (int i = 0; i < N-1; i++){
            scanf("%d", &score);
            if(score >= 0 && score <= fullScore){
                count++;
                if(score >= maxScore)
                    maxScore = score;
                if(score <= minScore)
                    minScore = score;
                scoreSum += score;
            }
        }
        scoreSum -= maxScore;
        scoreSum -= minScore;
        result = (int)round((double)((scoreSum/(count-2)) + teacherScore)/2);
        printf("%d\n", result);
    }
    return 0;
}