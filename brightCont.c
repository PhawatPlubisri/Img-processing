//นายภวัต พลับศิริ 116510400645-7 SEC 2

#include <stdio.h>
#include <math.h>

//fn brightness
double cal_brightness(int N, int M, int array[N][M]) {
    double sumB = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sumB += array[i][j];
        }
    }
    return sumB / (N * M);
}

//fn contrast
double cal_contrast(int N, int M, int array[N][M], double brightness) {
    double sumC = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sumC += pow(array[i][j] - brightness, 2);
        }
    }
    return sqrt(sumC / (N * M));
}

int main() {
    int N, M;

    printf("Enter number of rows (N) : ");
    scanf("%d", &N);
    printf("Enter number of columns (M) : ");
    scanf("%d", &M);
    printf("----------------------------\n");

    int array[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
              do {
                printf("Enter value for array[%d][%d] : ", i, j);
                scanf("%d", &val);
                  if (val < 0 || val > 255) {
                    printf("Value must be between 0 and 255. Please enter the value again.\n");
                }
            } while (val < 0 || val > 255); 
            array[i][j] = val;
        }
    }

    printf("----------------------------\n");
    //brightness
    double brightness = cal_brightness(N, M, array);
    printf("Brightness : %.2f\n", brightness);

    //contrast
    double contrast = cal_contrast(N, M, array, brightness);
    printf("Contrast : %.2f\n", contrast);

    return 0;
}
