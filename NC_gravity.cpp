#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//metodos
double dvdt(double x, double v, double t);
double dxdt(double x, double v, double t);
void RK4(double x, double v, double t, double delta);
//funcion que retorna el valor de la derivada de v respecto a t, dados ciertos parametros.
double dvdt(double x, double v, double t, double M, double G){
  return (-G*M)/(x*x);
}
//funcion que retorna el valor de la derivada de x respecto a t, dados ciertos parametros.
double dxdt(double x, double v, double t){
  return v;
}
//funcion que calcula los valores de x y v aplicando el metodo de runge kutta
void RK4(double *x, double *v, double *t, double delta, double M, double G){
  //se declaran las variables que se van a reutilizar dentro del metodo
  double kx1; double kx2; double kx3; double kx4;
  double kv1; double kv2; double kv3; double kv4;
  //se guardan los valores iniciales de las variables x, v t
  double xTemp = *x; double vTemp = *v; double tTemp = *t;
  //runge kutta para v y x
  kx1 = dxdt(xTemp, vTemp, tTemp);
  kv1 = dvdt(xTemp, vTemp, tTemp,M,G);

  kx2 = dxdt(xTemp + kx1 * delta/2, vTemp + kv1 * delta/2, tTemp + delta/2);
  kv2 = dvdt(xTemp + kx1 * delta/2, vTemp + kv1 * delta/2, tTemp + delta/2,M,G);

  kx3 = dxdt(xTemp + kx2 * delta/2, vTemp + kv2 * delta/2, tTemp + delta/2);
  kv3 = dvdt(xTemp + kx2 * delta/2, vTemp + kv2 * delta/2, tTemp + delta/2,M,G);

  kx4 = dxdt(xTemp + kx3 * delta/2, vTemp + kv3 * delta/2, tTemp + delta/2);
  kv4 = dvdt(xTemp + kx3 * delta/2, vTemp + kv3 * delta/2, tTemp + delta/2,M,G);

  tTemp = tTemp + delta;
  xTemp = xTemp + delta * (kx1 + 2*kx2 + 2*kx3 + kx4)/6.0;
  vTemp = vTemp + delta * (kv1 + 2*kv2 + 2*kv3 + kv4)/6.0;

  //se reasginan los nuevos valores de x, v, t
  *x = xTemp;
  *v = vTemp;
  *t = tTemp;
}
//metodo main
int main() {
  //se definen las condiciones iniciales
  double G=10;
  double M=1000;
  double x=100;
  double v=2;
  double t=0.1;
  double delta=0.001;
  double n= x*0.01;
  //se calculan los valores de x,v, t  hasta que la particula llegue a el 10 % de  su posicion iniciales
  while(x>n){
    cout << x << " " << v << " " << t << endl;
    RK4(&x, &v, &t, delta,M,G);
  }
  return 0;
}
