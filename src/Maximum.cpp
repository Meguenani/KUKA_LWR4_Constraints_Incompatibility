#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>


double maximum(double A, double B){
double max;

if(A >= B){
max = A;
}

else{
max = B;
}

return max;
}


double bound_pos(double val){ //Permet de ne garder que la valeur positive de val.
if(val < 0){
val = 0;
}
return val;
}




double maximum_4_values(double val_1, double val_2, double val_3, double val_4){
double max;
Eigen::VectorXd values(4);
values << val_1, val_2, val_3, val_4;
max = val_1;

for(int i=0; i<4; i++){
if(values[i] >= max){
max = values[i];
}
}
return max;
}




//L'entrée c'est la valeur d'accélération max autorisée pour chaque liaison. et la sortie c'est la position de cette valeur dans un vecteur qui . A pour but de trouver le n y correspondant.
int max_in_vector_index_4(Eigen::VectorXd max_q_ddot){  
int max_value_index;
int i;
double max_value;
max_value = max_q_ddot[0];
for(i=0;i<=3;i++){
if(max_q_ddot[i] >= max_value){
max_value = max_q_ddot[i];
max_value_index = i;
}
}
//std::cout<<"max_value = "<< max_value <<std::endl;
return max_value_index;
}



//L'entrée c'est la valeur d'accélération max autorisée pour chaque liaison. et la sortie c'est la position de cette valeur dans un vecteur qui . A pour but de trouver le n y correspondant.
int max_in_vector_index_3(Eigen::VectorXd max_q_ddot){  
int max_value_index;
int i;
double max_value;
max_value = max_q_ddot[0];
for(i=0;i<3;i++){
if(max_q_ddot[i] >= max_value){
max_value = max_q_ddot[i];
max_value_index = i;
}
}
//std::cout<<"max_value = "<< max_value <<std::endl;
return max_value_index;
}




double max_value_3(double value_1, double value_2, double value_3){ //Compute min value between three doubles
double max_value;
Eigen::VectorXd values(3); //Three values 
values << value_1, value_2, value_3;
max_value = values[0];
for(int i=1; i<3; i++){
if(values[i] >= max_value){
max_value = values[i];
}
}

return max_value;
}




Eigen::VectorXd fix_bounds_1(Eigen::VectorXd q_dotdot_bounds_max_trq_derived, Eigen::VectorXd q_dotdot_bounds_min_trq_derived){
int i;
for(i=0;i<7;i++){
if(q_dotdot_bounds_max_trq_derived[i]<q_dotdot_bounds_min_trq_derived[i]){
q_dotdot_bounds_max_trq_derived[i] = q_dotdot_bounds_min_trq_derived[i];
}
}
return q_dotdot_bounds_max_trq_derived;
}



Eigen::VectorXd fix_bounds_2(Eigen::VectorXd q_dotdot_bounds_max_trq_derived, Eigen::VectorXd q_dotdot_bounds_min_trq_derived){
int i;
for(i=0;i<7;i++){
if(q_dotdot_bounds_max_trq_derived[i]<q_dotdot_bounds_min_trq_derived[i]){
q_dotdot_bounds_min_trq_derived[i] = q_dotdot_bounds_max_trq_derived[i];
}
}
return q_dotdot_bounds_min_trq_derived;
}

