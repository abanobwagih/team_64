
#include"conio.h"
#include"stdio.h" 
#include"math.h" 

     void main() {    
double theta ; // central angle
double distance; // the distance between the two coordinates
double Xi,Xf,Yi,Yf,X,Y,M,O;//initial and final coordinates of the target 
double displacement;// shortest distance between the initial and final positions double r=6371;
double r=6378;
          // the 2 upcoming lines is to get the distance between latitudes and  longitudes 
 
    M=(110*(Xf-Xi)); 
	O=(110*(Yf-Yi));

X = M*M;
Y = O*O;
displacement = X+Y;
theta=acos((2*r*r - displacement)/(2*r*r)); // cos rule
distance=(theta*r);
       printf("%lf",distance);

     }
