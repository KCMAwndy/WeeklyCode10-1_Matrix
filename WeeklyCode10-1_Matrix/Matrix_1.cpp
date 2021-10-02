#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int i = 0, j = 0;
double findDet(double [3][3]);
void findAdj(double [3][3], double [3][3]);
void findInverse(double[3][3], double);
void findAplusB(double [3][3], double [3][3]);
void findAminusB(double [3][3], double [3][3]);
void findAmultiplyB(double [3][3], double [3][3]);

int main() {
	double detA = 0, detB = 0, adjA[3][3], adjB[3][3];
	double A[3][3], B[3][3];
	printf("Matrix A :\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Matrix B :\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	printf("\n");
	detA = findDet(A);
	printf("Det A : %.3f\n", detA);
	detB = findDet(B);
	printf("Det B : %.3f\n", detB);
	printf("\n");
	printf("Adjoint A :\n");
	findAdj(A, adjA);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.3f", adjA[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	printf("\n");
	printf("Adjoint B :\n");
	findAdj(B, adjB);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.3f", adjB[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	printf("\n");
	printf("Inverse A :\n");
	findInverse(A, detA);
	printf("\n");
	printf("Inverse B :\n");
	findInverse(B, detB);
	printf("\n");
	printf("A + B :\n");
	findAplusB(A, B);
	printf("\n");
	printf("A - B :\n");
	findAminusB(A, B);
	printf("\n");
	printf("A * B :\n");
	findAmultiplyB(A, B);
	printf("\n");
	return 0;
}

double findDet(double mat[3][3]) {
	double detMat = 0;
	detMat = (mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1]) - (mat[0][2] * mat[1][1] * mat[2][0] + mat[0][0] * mat[1][2] * mat[2][1] + mat[0][1] * mat[1][0] * mat[2][2]);
	return detMat;
}

void findAdj(double mat[3][3], double cMat[3][3]) {
	int k = 2,dMat[3][3];
	//dMat[0][0] = pow(-1, 2) * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]);
	//dMat[0][1] = pow(-1, 3) * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]);
	//dMat[0][2] = pow(-1, 4) * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
	//dMat[1][0] = pow(-1, 3) * (mat[0][1] * mat[2][2] - mat[2][1] * mat[0][2]);
	//dMat[1][1] = pow(-1, 4) * (mat[0][0] * mat[2][2] - mat[2][0] * mat[0][2]);
	//dMat[1][2] = pow(-1, 5) * (mat[0][0] * mat[2][1] - mat[2][0] * mat[0][1]);
	//dMat[2][0] = pow(-1, 4) * (mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2]);
	//dMat[2][1] = pow(-1, 5) * (mat[0][0] * mat[1][2] - mat[1][0] * mat[0][2]);
	//dMat[2][2] = pow(-1, 6) * (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
	dMat[0][0] = (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]);
	dMat[0][1] = (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]);
	dMat[0][2] = (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
	dMat[1][0] = (mat[0][1] * mat[2][2] - mat[2][1] * mat[0][2]);
	dMat[1][1] = (mat[0][0] * mat[2][2] - mat[2][0] * mat[0][2]);
	dMat[1][2] = (mat[0][0] * mat[2][1] - mat[2][0] * mat[0][1]);
	dMat[2][0] = (mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2]);
	dMat[2][1] = (mat[0][0] * mat[1][2] - mat[1][0] * mat[0][2]);
	dMat[2][2] = (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (dMat[i][j] != (double)0) {
				dMat[i][j] = dMat[i][j] * pow(-1, k);
			}
			k++;
			//printf("%d\t", k);
		}
		k-=2;
		//printf("%d\t", k);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cMat[i][j] = dMat[j][i];
		}
	}
}

void findInverse(double mat[3][3], double detMat) {
	double cMat[3][3];
	double invMat[3][3];
	if (detMat == 0) {
		printf("It's singular matrix.\n");
	}
	else {
		findAdj(mat, cMat);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				invMat[i][j] = cMat[i][j] / detMat;
				printf("%.3f ", invMat[i][j]);
				printf("\t");
			}
			printf("\n");
		}
	}
}

void findAplusB(double matA[3][3], double matB[3][3]) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.3f", matA[i][j] + matB[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void findAminusB(double matA[3][3], double matB[3][3]) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.3f", matA[i][j] - matB[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void findAmultiplyB(double matA[3][3], double matB[3][3]) {
	double cMat[3][3];
	cMat[0][0] = (matA[0][0] * matB[0][0] + matA[0][1] * matB[1][0] + matA[0][2] * matB[2][0]);
	cMat[0][1] = (matA[0][0] * matB[0][1] + matA[0][1] * matB[1][1] + matA[0][2] * matB[2][1]);
	cMat[0][2] = (matA[0][0] * matB[0][2] + matA[0][1] * matB[1][2] + matA[0][2] * matB[2][2]);
	cMat[1][0] = (matA[1][0] * matB[0][0] + matA[1][1] * matB[1][0] + matA[1][2] * matB[2][0]);
	cMat[1][1] = (matA[1][0] * matB[0][1] + matA[1][1] * matB[1][1] + matA[1][2] * matB[2][1]);
	cMat[1][2] = (matA[1][0] * matB[0][2] + matA[1][1] * matB[1][2] + matA[1][2] * matB[2][2]);
	cMat[2][0] = (matA[2][0] * matB[0][0] + matA[2][1] * matB[1][0] + matA[2][2] * matB[2][0]);
	cMat[2][1] = (matA[2][0] * matB[0][1] + matA[2][1] * matB[1][1] + matA[2][2] * matB[2][1]);
	cMat[2][2] = (matA[2][0] * matB[0][2] + matA[2][1] * matB[1][2] + matA[2][2] * matB[2][2]);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.3f", cMat[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}