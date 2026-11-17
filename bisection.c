
#include<stdio.h>
#include<math.h>

double f(double x ){return x*sin(x) +cos(x);}
int main(){
    double a,b ,E ,c ;

     printf("enter the initial interval (a,b):");
     scanf("%lf %lf",&a ,&b);

     printf("Enter the tolerance (E):");
     scanf("%lf",&E);

     if(f(a)* f(b)>0){
        printf("Error:no root in the given interval");
        return 0;
     }

     do{
        c= (a+b)/2;
        if(f(c)*f(a)>0){
            a=c;
        }
        else{
            b=c;
        }
        
     }while(fabs(f(c))>E);
    printf("the root is %lf\n",c);
    return 0;
}
