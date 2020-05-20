#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>


double minimum(double A, double B){
double min;

if(A >= B){
min = B;
}

else{
min = A;
}

return min;
}




double bound_neg(double val){ //Permet de ne garder que la valeur negative de val.
if(val > 0){
val = 0;
}
return val;
}

double minimum_4_values(double val_1, double val_2, double val_3, double val_4){
double min;
Eigen::VectorXd values(4);
values << val_1, val_2, val_3, val_4;
min = val_1;

for(int i=0; i<4; i++){
if(values[i] <= min){
min = values[i];
}
}
return min;
}


int min_in_vector_index_4(Eigen::VectorXd min_q_ddot){  
int min_value_index;
int i;
double min_value;
min_value = min_q_ddot[0];
for(i=0;i<=3;i++){
if(min_q_ddot[i] <= min_value){
min_value = min_q_ddot[i];
min_value_index = i;
/*
std::cout<<"min_value = "<< min_value <<std::endl;
std::cout<<"min_value_index = "<< min_value_index <<std::endl;
*/
}
}
//std::cout<<"min_value = "<< min_value <<std::endl;
return min_value_index;
}





int min_in_vector_index_3(Eigen::VectorXd min_q_ddot){  
int min_value_index;
int i;
double min_value;
min_value = min_q_ddot[0];
for(i=0;i<3;i++){
if(min_q_ddot[i] <= min_value){
min_value = min_q_ddot[i];
min_value_index = i;
}
}
//std::cout<<"min_value = "<< min_value <<std::endl;
return min_value_index;
}





double min_value_3(double value_1, double value_2, double value_3){ //Compute min value between three doubles
double min_value;
Eigen::VectorXd values(3); //Three values 
values << value_1, value_2, value_3;
min_value = values[0];
for(int i=1; i<3; i++){
if(values[i] <= min_value){
min_value = values[i];
}
}

return min_value;
}
