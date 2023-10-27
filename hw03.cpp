#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

const double me = 9.1093837e-31;
const double eV = 1.60217662e-19;

const double a_0 = 5.29e-11;
const double hbar = 1.054571817e-34;

const double V = -13.6 * eV;
const double a = 20 * a_0;

double f_even(double E) {
    double tmp1 = sqrt(-E);
    double tmp2 = sqrt(E - V);
    double tmp3 = a/hbar *sqrt(2*me*(E - V));

    return -tmp1 + tmp2 * tan(tmp3);
}


double df_even(double E){
    double term_1 = tan(sqrt(2*me*(E-V))*a/hbar)/sqrt(E-V);
    double term_2 = sqrt(2*me*(E-V)*a/hbar/sqrt(E-V)/pow(cos(sqrt(2*me*(E-V))*a/hbar),2));
    double term_3 = 1/sqrt(-E);

    return (term_1 + term_2 + term_3)/2;
    }

double newton(double (*f)(double),double (*df)(double),double tolerance ,double init_guess ){

    int counter = 0;
    double x = init_guess;
    double x_new = 0.0;
    while (abs(f(x))> tolerance){
        cout << "x = " << x << endl;
        cout << "df(x) = " << df(x) << endl;
        cout << "f(x_new) = " << f(x_new) << endl;
        
        x_new = x - f(x)/df(x);
        x = x_new;
        counter++;

        if (counter > 10000){
            cout<< "not converge" << endl;
            return 0.0;
        }   
    }

    return x;
}

int main (){
    cout << setprecision(20);
    double root = newton(f_even,df_even, 1e-10,-12.5*eV);
    
    cout << setprecision(20)<< "root = " << root/eV << endl;
}

