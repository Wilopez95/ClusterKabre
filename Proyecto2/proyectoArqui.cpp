#include<omp.h>
#include<iostream>
#include<sys/time.h>
#include<stdio.h>

using namespace std;
void suma(){//empesamos con el metodo suma 
int m = 500;//dimension de las matrices 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);

  //omp_set_num_threads(32);//colocamos este comando para el numero de hilos 


  int  A[m][m],B[m][m],C[m][m];//declaramos las matrices con una dimencion de m 
  
  //en los sigues linias de codigo llenamos las matriz A con la suma de j+i 
  for( int i=0;i<m;i++){
     for(int j=0;j<m;j++){
           A[i][j]=j+i;
      }
  }
  //en las siguientes linias de codigo llenamos las matriz B con la multiplicacion j*i
   for( int i=0;i<m;i++){
      for(int j=0;j<m;j++){
            B[i][j]=j*i;
      }
   }
 
#pragma omp parallel for //este comando se ejecuta la programacion paralela en el proceso de la suma de la matriz A +B y almacenamos en C
	for( int i=0;i<m;i++){
		for(int j=0;j<m;j++){
            C[i][j]=A[i][j]+B[i][j];
		}
	}

cout<<endl;
cout<<"---------------------"<<endl;
cout<<"suma de matrices "<<endl;
cout<<"---------------------"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
//Se limita a imprimir solamente 10 elementos ya que 200 son muchos
 for( int i=0;i<10;i++){
        cout<<"      "<<endl;
     for(int j=0;j<10;j++){

            cout<<"      "<<C[i][j];
      }
  }
  
cout<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion  
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*2000+usecons/2000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tiempo duro "<<mtime<<" mili segundo de la suma de matrices";//imprimimos el tiempo de ejecucion 

}

void resta(){
int m = 500;//dimension de las matrices 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);

  //omp_set_num_threads(32);//colocamos este comando para el numero de hilos para la programacion paralela
  

  int  A[m][m],B[m][m],C[m][m];//declaramos las matrices con una dimencion de m 
  
  //en los sigues linias de codigo llenamos las matriz A con la suma de j+i 
  for( int i=0;i<m;i++){
     for(int j=0;j<m;j++){
           A[i][j]=j+i;
      }
  }
  //en las siguientes linias de codigo llenamos las matriz B con la multiplicacion j*i
   for( int i=0;i<m;i++){
      for(int j=0;j<m;j++){
            B[i][j]=j*i;
      }
   }
 
#pragma omp parallel for //este comando se ejecuta la programacion paralela en el proceso de la suma de la matriz A +B y almacenamos en C
	for( int i=0;i<m;i++){
		for(int j=0;j<m;j++){
            C[i][j]=A[i][j]-B[i][j];
		}
	}

cout<<endl;
cout<<"---------------------"<<endl;
cout<<"resta de matrices "<<endl;
cout<<"---------------------"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
//Se limita a imprimir solamente 10 elementos ya que 200 son muchos
 for( int i=0;i<10;i++){
        cout<<"      "<<endl;
     for(int j=0;j<10;j++){

            cout<<"      "<<C[i][j];
      }
  }
  
cout<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion  
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*2000+usecons/2000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tiempo duro "<<mtime<<" mili segundo de la resta de matrices";//imprimimos el tiempo de ejecucion 
cout<<"\n";


}

void multi(){
int m = 500,i,j,k;//declaramos variables 
struct timeval start, end;//declaramos esta variable para controlar el tiempo de ejecucion 
long mtime, seconds, usecons;//variable de long para definir rangos de segundos y mili segundos 
gettimeofday(&start,NULL);


omp_set_num_threads(1);//colocamos este comando para el numero de hilos para la programacion paralela



int A[m][m],B[m][m],C[m][m];//declaracion de las matrices
//con los siguientes codigos empesamos a llenar las matriz A con la i+j
for (i=0;i<m;i++)
{
	for (j=0;j<m;j++)
	{ 
	A[i][j]=i+j;
	}
}
//con los siguientes codigos empesamos a llenar las matriz B con la i*j
for (i=0;i<m;i++)
	{
   for (j=0;j<m;j++)
    { 
		B[i][j]=i*j;
    }
}

//este comando se ejecuta la programacion paralela en el proceso de la multiplicacion de la matriz A*B y almacenamos en C

#pragma omp parallel for
	for (i=0;i<m;i++)
	{
			for (j=0;j<m;j++)
			{
				C[i][j]=0;
			for (k=0;k<m;k++)
			{
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	

cout<<"-----------------------------"<<endl;
cout<<"multiplicaion de matrices"<<endl;
cout<<"-----------------------------"<<endl;
//en las siguientes linias de codigo estamos imprimiendo la matriz C
//Se limita a imprimir solamente 10 elementos ya que 200 son muchos
  for (i=0;i<10;i++)
  {
	cout<<"      "<<endl;
   for (j=0;j<10;j++)
    { 
		cout<<"     "<<C[i][j];
    }
  }
cout<<"  "<<endl;
gettimeofday(&end, NULL);
seconds=end.tv_sec  -start.tv_sec;//almacenamos el tiempo de ejecucion 
usecons=end.tv_usec - start.tv_usec;//almacenamos el tiempo de ejecucion
mtime=((seconds)*2000+usecons/2000.0)+0.5;//hacemos el calcula del tiempo de ejecucion para que nos imprima en milisegundos
cout<<"el tiempo duro "<<mtime<<" mili segundo de la multiplicacion de matrices";//imprimimos el tiempo de ejecucion 
cout<<"\n";
}
 
	

int main(){
    cout<<"--------------------------"<<endl;
    cout<<"Operaciones matriciales"<<endl;
    cout<<"---------------------------"<<endl;
    suma();//en la primera opcion tenemos a la suma y por tanto instanciamos al metodo suma
		resta();//en la segunda opcion tenemos a la resta y por tanto instanciamos al metodo resta
		multi();



return 0;
}

