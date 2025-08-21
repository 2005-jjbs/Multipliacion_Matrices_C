/**************************************************************************************
 * Fecha:21 de agosto 2025
 * Autor: Juan Ballesteros
 * Materia: Sistemas Operativos
 * Tema: Concurrencia
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
 * La idea principal, es construir paso a paso la implementación para hacer uso de la
 * biblioteca PTHREAD. Se implementa el Algoritmo Clásico de multiplicación de matrices, para
 * matrices cuadradas, es decir, la dimensión de filas es igual a la de columnas.
 * A continuación se describen los paso
 *  - Reserva de memoria
 *      - Creación de punteros para matrices del tipo doble
 *      - Asignación de memoria
 *      - Ingreso de argumentos de entrada (Dimensión matriz, número de hilos)
 *      - Validación argumentos de entrada
 *      - Inicializar las matrices
 *      - Imprimir las matrices
 *      - Función para inicializar las matrices
 *      - Función para imprimir las matrices
 *      - Algoritmo clásico de multiplicación matrices
 *  - Se verifica el resultado
 *      - Función para multiplicación las matrices
 *      - Declaración vector de hilos
 *      - Creación de hilos según tamaño de vector de hilos
 *      - Crear estructura de datos que encapsule los argumentos de entrada de la función MM
 * Implementación de paralelismo: resolución de la multiplicación de matrices
 *  - Se crea el vector de hilos
 *  - Se tiene pendiente la exclusión de los hilos
 *  - Se pasa a globales las matrices
 *  - Encapsular los datos para enviarlos a la función MxM
 *  - Se desencapsulan los datos dentro de la función MxM (descomprimen)
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*Se declaran 3 punteros de tipo double para las matrices*/
double *mA, *mB, *mC;


/*Inicializacion de matrices*/
void iniMatriz(int N, double *matrizA, double *matrizB){
	for(int i =0; i < N*N; i++){
		matrizA[i] = i*5 +1;
		matrizB[i] = i*2 + 3;
	}

};
/*Impresion de matrices*/
void imprMatrices(int N, double *matriz){
    
    if(N<9){
	   for(int i=0; i<N*N; i++){
                if(i%N==0) printf("\n");
        printf(" %f ", matriz[i]);
   	}
        printf("\n#######################################################\n");
    } else {
        printf("\n#######################################################\n");
    }
};

int main(int argc, char *argv[]) {
    /*Se ingresa la dimensión de la matriz*/
    if(argc<2){
        printf("Numero argumentos incorrectos\n");
        printf("\n\t $ejecutable.exe DIM \n");
        return -1;
    }
    /*Se valida que la dimensión sea mayor que cero*/
    int N = (int) atof(argv[1]);
    if(N<=0){
        printf("\n Valores deben ser mayor que cero\n");
        return -1;
    };

    /*Se asigna memoria para las matrices*/
    mA = (double *) malloc(N*N*sizeof(double));
    mB = (double *) malloc(N*N*sizeof(double));
    mC = (double *) calloc(N*N,sizeof(double));

    /*Se inicializan las matrices*/
    iniMatriz(N,mA,mB);
    /*Se imprimen las matrices*/
    printf("\n\tMatriz A\n");
    imprMatrices(N,mA);
    printf("\n\tMatriz B\n");
    imprMatrices(N,mB);
    //imprMatrices(N,mC);   

    /*Se realiza la multiplicación de matrices*/
        for(int i=0; i<N; i++){ /*Se recorre la matriz A*/
        for(int j=0; j<N; j++){ /*Se recorre la matriz B*/
            double sumaTemp, *pA, *pB; 
            sumaTemp = 0.0; 
            pA = mA + i*N; /*Se apunta al inicio de la fila*/
            pB = mB + j; /*Se apunta al inicio de la columna*/
            for(int k=0; k<N; k++, pA++, pB+=N){ /*Se recorre la fila y la columna*/
                sumaTemp += *pA * *pB; /*Se multiplican los elementos y se suman*/
            }
            mC[j+i*N] = sumaTemp; /*Se guarda el resultado en la matriz C*/
        }
    }
    /*Se imprimen la matriz multiplicada*/
    
    printf("\n\tMatriz C (Multiplicacion) \n");
    imprMatrices(N,mC);
    

        printf("\n\tFin del programa.............!\n");
    
        free(mA);
	free(mB);
	free(mC);
        return 0;

}
