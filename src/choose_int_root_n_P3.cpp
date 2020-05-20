#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>
#include "Maximum.h"
#include "Minimum.h"


//Nombre d'itération final pour chaque liaison 
Eigen::VectorXi int_root_neg_jerk_P3(Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_neg_jerk_poly, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q_k2, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_min, Eigen::VectorXd q_dot, double dt){
int i;
int g;
int n;
int min_min_q_ddot_index;
Eigen::VectorXi n_minimizing(7); //Le vecteur retourné est constitué de int
Eigen::VectorXd min_q_ddot(3);
int min_min_q_ddot; //index de la vameur min de max_q_ddot

for(g=0; g<7; g++){
for(i=0; i<3; i++){
n = rounded_Cubic_roots_neg_jerk_poly(i,g);
if(n <= 3){
n=3;
}
min_q_ddot[i] = ((q_bounds_max[g]-q_k2[g])/(n*dt))-(((n-1)*q_ddot_k2[g]*dt)/2)+(((pow(n,2)/6)-(n/2)+(1/3))*q_dddot_bounds_min[g]*pow(dt,2))-(q_dot[g]/dt);  
}
min_min_q_ddot_index = min_in_vector_index_3(min_q_ddot); //Donne l'index de la valeur de "rounded_Cubic_roots_neg_jerk_poly" qui minimise "min_q_ddot"
if(rounded_Cubic_roots_neg_jerk_poly(min_min_q_ddot_index, g)==0 || rounded_Cubic_roots_neg_jerk_poly(min_min_q_ddot_index, g)==1){rounded_Cubic_roots_neg_jerk_poly(min_min_q_ddot_index, g)=2;}
n_minimizing[g]=rounded_Cubic_roots_neg_jerk_poly(min_min_q_ddot_index, g); //The value of n that minimizez the "val_min_de_q_ddot"

}

return n_minimizing;
}




Eigen::VectorXi int_root_pos_jerk_P3(Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_posi_jerk_poly, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q_k2, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_max, Eigen::VectorXd q_dot, double dt){
int i;
int g;
int n;
int max_max_q_ddot_index;
Eigen::VectorXi n_maximizing(7); //Le vecteur retourné est constitué de int
Eigen::VectorXd max_q_ddot(3);
int max_max_q_ddot; //index de la vameur max de max_q_ddot

for(g=0; g<7; g++){
for(i=0; i<3; i++){
n = rounded_Cubic_roots_posi_jerk_poly(i,g);
if(n <= 3){
n=3;
}
max_q_ddot[i] = ((q_bounds_min[g]-q_k2[g])/(n*dt))-(((n-1)*q_ddot_k2[g]*dt)/2)+(((pow(n,2)/6)-(n/2)+(1/3))*q_dddot_bounds_max[g]*pow(dt,2))-(q_dot[g]/dt);  
}
max_max_q_ddot_index = max_in_vector_index_3(max_q_ddot); //Donne l'index de la valeur de "rounded_Cubic_roots_posi_jerk_poly" qui maximise "max_q_ddot"
if(rounded_Cubic_roots_posi_jerk_poly(max_max_q_ddot_index, g)==0 || rounded_Cubic_roots_posi_jerk_poly(max_max_q_ddot_index, g)==1){rounded_Cubic_roots_posi_jerk_poly(max_max_q_ddot_index, g)=2;}
n_maximizing[g]=rounded_Cubic_roots_posi_jerk_poly(max_max_q_ddot_index, g); //The value of n that maximizez the "val_max_de_q_ddot"

}

return n_maximizing;
}














/*
Eigen::VectorXi int_root_pos_jerk_P3(Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_pos_jerk_poly){
int i;
int g;
int n;
Eigen::VectorXi n_maximizing(7);
for(g=0; g<7; g++){
n = min_value_3(rounded_Cubic_roots_pos_jerk_poly(0,g), rounded_Cubic_roots_pos_jerk_poly(1,g), rounded_Cubic_roots_pos_jerk_poly(2,g));
/*
if(n<2){
   n=2;
}

n_maximizing[g] = n;
}

return n_maximizing;
}
*/
