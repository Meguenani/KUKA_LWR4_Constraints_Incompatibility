#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>
#include "Maximum.h"
#include "Minimum.h"
#include "round_up.h"

//
Eigen::VectorXi compute_n_neg_acc_posi(Eigen::VectorXd q_dotdot_bounds_min_optimized, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q, double dt){   //compt 1
Eigen::VectorXi n_neg_acc_posi(7);
Eigen::VectorXd n_neg_acc_posi_real(7);
int i;

for(i=0; i<7; i++){
n_neg_acc_posi_real[i] = -sqrt(-2*q_dotdot_bounds_min_optimized[i]*(q_bounds_max[i] - q[i]))/(dt*q_dotdot_bounds_min_optimized[i]);
n_neg_acc_posi[i]      = round_up(n_neg_acc_posi_real[i]);
if(n_neg_acc_posi[i]<=0){n_neg_acc_posi[i]=1;}
}

return n_neg_acc_posi;
}


//
Eigen::VectorXi compute_n_pos_acc_posi(Eigen::VectorXd q_dotdot_bounds_max_optimized, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q, double dt){   //compt 1
Eigen::VectorXi n_pos_acc_posi(7);
Eigen::VectorXd n_pos_acc_posi_real(7); 
int i;

for(i=0; i<7; i++){
n_pos_acc_posi_real[i] = sqrt(-2*q_dotdot_bounds_max_optimized[i]*(q_bounds_min[i] - q[i]))/(dt*q_dotdot_bounds_max_optimized[i]);
n_pos_acc_posi[i]      = round_up(n_pos_acc_posi_real[i]);
if(n_pos_acc_posi[i]<=1){n_pos_acc_posi[i]=1;}
}

return n_pos_acc_posi;
}






//
Eigen::VectorXi compute_n_neg_jerk_vel(Eigen::VectorXd q_dddot_bounds_min, Eigen::VectorXd q_dot_bounds_max, Eigen::VectorXd q_dot, double dt){   //compt 2
Eigen::VectorXi n_neg_jerk_vel(7);
Eigen::VectorXd n_neg_jerk_vel_real(7); 
int i;

for(i=0; i<7; i++){
n_neg_jerk_vel_real[i] = -sqrt(-2*q_dddot_bounds_min[i]*(q_dot_bounds_max[i] - q_dot[i]))/(dt*q_dddot_bounds_min[i]);
n_neg_jerk_vel[i]      = round_up(n_neg_jerk_vel_real[i]);
if(n_neg_jerk_vel[i]<=1){n_neg_jerk_vel[i]=1;}
}

return n_neg_jerk_vel;
}




//
Eigen::VectorXi compute_n_pos_jerk_vel(Eigen::VectorXd q_dddot_bounds_max, Eigen::VectorXd q_dot_bounds_min, Eigen::VectorXd q_dot, double dt){   //compt 2
Eigen::VectorXi n_pos_jerk_vel(7);
Eigen::VectorXd n_pos_jerk_vel_real(7); 
int i;

for(i=0; i<7; i++){
n_pos_jerk_vel_real[i] = sqrt(-2*q_dddot_bounds_max[i]*(q_dot_bounds_min[i] - q_dot[i]))/(dt*q_dddot_bounds_max[i]);
n_pos_jerk_vel[i]      = round_up(n_pos_jerk_vel_real[i]);
if(n_pos_jerk_vel[i]<=1){n_pos_jerk_vel[i]=1;}
}

return n_pos_jerk_vel;
}











Eigen::VectorXi compute_n_neg_jerk_acc_posi(Eigen::VectorXi n1_neg_jerk_acc_posi, Eigen::VectorXd q_dotdot_bounds_min_optimized, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q, Eigen::VectorXd q_k2, Eigen::VectorXd q_dot, Eigen::VectorXd q_ddot, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_min, double dt){   //compt 2
Eigen::VectorXi n_neg_jerk_acc_posi(7);
Eigen::VectorXd n_neg_jerk_acc_posi_real(7); 
Eigen::Matrix<int, 7, 2> n_neg_jerk_acc_posi_two_sol;              //pour chaque joint il y a deux solutions "n"
Eigen::Matrix<double, 7, 2> n_neg_jerk_acc_posi_real_two_sol;        //pour chaque joint il y a deux solutions "n"
Eigen::VectorXd  delta_n_neg_jerk_acc_posi(7);
Eigen::Matrix<double, 7, 1>  q_dotdot_bounds_max_comp_Jerk_Acc_Posi; //Celas sont calculés avec la compatibilité entre le Jerk, l'Acc et la position
Eigen::Matrix<double, 7, 2>  q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values; //Celui la contiendra deux valeurs correspondant à chaqun des "n"
int u;

//std::cout<<"000000000000000000000000000"<<std::endl;
for(u=0; u<7; u++){
delta_n_neg_jerk_acc_posi[u]          = pow((4*n1_neg_jerk_acc_posi[u]*q_dotdot_bounds_min_optimized[u]*dt*dt), 2) + ((8*q_dotdot_bounds_min_optimized[u]*pow(dt,2))*((-4*(q_bounds_max[u]-q[u]))+(-2*q_ddot[u]*pow(dt,2)*(pow(n1_neg_jerk_acc_posi[u],2)+n1_neg_jerk_acc_posi[u]))+((4/3)*(n1_neg_jerk_acc_posi[u]-pow(n1_neg_jerk_acc_posi[u],3))*q_dddot_bounds_min[u]*pow(dt,3))+(2*n1_neg_jerk_acc_posi[u]*q_dotdot_bounds_min_optimized[u]*pow(dt,2))));
n_neg_jerk_acc_posi_real_two_sol(u,0) = ((4*n1_neg_jerk_acc_posi[u]*q_dotdot_bounds_min_optimized[u]*pow(dt,2)) + sqrt(delta_n_neg_jerk_acc_posi[u]))/(-4*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
n_neg_jerk_acc_posi_real_two_sol(u,1) = ((4*n1_neg_jerk_acc_posi[u]*q_dotdot_bounds_min_optimized[u]*pow(dt,2)) - sqrt(delta_n_neg_jerk_acc_posi[u]))/(-4*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
/*
std::cout<<"delta_n_neg_jerk_acc_posi[u] : "<< delta_n_neg_jerk_acc_posi[u] << std::endl;
std::cout<<" "<<std::endl;
std::cout<<"n_neg_jerk_acc_posi_real_two_sol(u,0) : "<< n_neg_jerk_acc_posi_real_two_sol(u,0) <<std::endl;
std::cout<<" "<<std::endl;
std::cout<<"n_neg_jerk_acc_posi_real_two_sol(u,1) : "<< n_neg_jerk_acc_posi_real_two_sol(u,1) <<std::endl;
std::cout<<"111111111111111111111111111"<<std::endl;
*/
if(n_neg_jerk_acc_posi_real_two_sol(u,0)>0){
n_neg_jerk_acc_posi_two_sol(u,0) = round_up(n_neg_jerk_acc_posi_real_two_sol(u,0));
}
else{n_neg_jerk_acc_posi_two_sol(u,0) = 10e6;}

//std::cout<<"222222222222222222222222222"<<std::endl;

if(n_neg_jerk_acc_posi_real_two_sol(u,1)>0){
n_neg_jerk_acc_posi_two_sol(u,1) = round_up(n_neg_jerk_acc_posi_real_two_sol(u,1));
}
else{n_neg_jerk_acc_posi_two_sol(u,1) = 10e6;}

//std::cout<<"3333333333333333333333333333"<<std::endl;

q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 0) = ((q_bounds_max[u]-q_k2[u])/((n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,0))*pow(dt,2))) + ((-pow(n1_neg_jerk_acc_posi[u],2)+n1_neg_jerk_acc_posi[u]-2*n1_neg_jerk_acc_posi[u]*n_neg_jerk_acc_posi_two_sol(u,0))/(2*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,0))))*q_ddot_k2[u] + ((-pow(n1_neg_jerk_acc_posi[u],3)+3*pow(n1_neg_jerk_acc_posi[u],2)-2*n1_neg_jerk_acc_posi[u]-3*n_neg_jerk_acc_posi_two_sol(u,0)*(pow(n1_neg_jerk_acc_posi[u],2)-n1_neg_jerk_acc_posi[u]))/(6*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,0))))*q_dddot_bounds_min[u]*dt + ((n_neg_jerk_acc_posi_two_sol(u,0)-pow(n_neg_jerk_acc_posi_two_sol(u,0),2))/(2*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,0))))*q_dotdot_bounds_min_optimized[u] - (q_dot[u]/dt);
q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 1) = ((q_bounds_max[u]-q_k2[u])/((n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,1))*pow(dt,2))) + ((-pow(n1_neg_jerk_acc_posi[u],2)+n1_neg_jerk_acc_posi[u]-2*n1_neg_jerk_acc_posi[u]*n_neg_jerk_acc_posi_two_sol(u,1))/(2*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,1))))*q_ddot_k2[u] + ((-pow(n1_neg_jerk_acc_posi[u],3)+3*pow(n1_neg_jerk_acc_posi[u],2)-2*n1_neg_jerk_acc_posi[u]-3*n_neg_jerk_acc_posi_two_sol(u,1)*(pow(n1_neg_jerk_acc_posi[u],2)-n1_neg_jerk_acc_posi[u]))/(6*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,1))))*q_dddot_bounds_min[u]*dt + ((n_neg_jerk_acc_posi_two_sol(u,1)-pow(n_neg_jerk_acc_posi_two_sol(u,1),2))/(2*(n1_neg_jerk_acc_posi[u]+n_neg_jerk_acc_posi_two_sol(u,1))))*q_dotdot_bounds_min_optimized[u] - (q_dot[u]/dt);
q_dotdot_bounds_max_comp_Jerk_Acc_Posi(u,0)             = minimum(q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 0), q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 1));

//std::cout<<"4444444444444444444444444444"<<std::endl;

if(q_dotdot_bounds_max_comp_Jerk_Acc_Posi(u,0) == q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 0)){
/*
std::cout<<"55555555555555555555555555555"<<std::endl;
std::cout<<"n_neg_jerk_acc_posi_two_sol(u,0) : "<<std::endl;
std::cout<< n_neg_jerk_acc_posi_two_sol(u,0) <<std::endl;
*/
n_neg_jerk_acc_posi[u] = n_neg_jerk_acc_posi_two_sol(u,0);
}
if(q_dotdot_bounds_max_comp_Jerk_Acc_Posi(u,1) == q_dotdot_bounds_max_comp_Jerk_Acc_Posi_two_values(u, 1)){
//std::cout<<"66666666666666666666666666666"<<std::endl;
n_neg_jerk_acc_posi[u] = n_neg_jerk_acc_posi_two_sol(u,1);
}



}



return n_neg_jerk_acc_posi;
}












Eigen::VectorXi compute_n_pos_jerk_acc_posi(Eigen::VectorXi n1_pos_jerk_acc_posi, Eigen::VectorXd q_dotdot_bounds_max_optimized, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q, Eigen::VectorXd q_k2, Eigen::VectorXd q_dot, Eigen::VectorXd q_ddot, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_max, double dt){   //compt 2
Eigen::VectorXi n_pos_jerk_acc_posi(7);
Eigen::VectorXd n_pos_jerk_acc_posi_real(7);
Eigen::Matrix<int, 7, 2> n_pos_jerk_acc_posi_two_sol; //pour chaque joint il y a deux solutions "n" 
Eigen::Matrix<double, 7, 2> n_pos_jerk_acc_posi_real_two_sol; //pour chaque joint il y a deux solutions "n"
Eigen::VectorXd delta_n_pos_jerk_acc_posi(7);
Eigen::VectorXd q_dotdot_bounds_min_comp_Jerk_Acc_Posi(7);
Eigen::Matrix<double, 7, 2> q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values;
int u;

for(u=0; u<7; u++){
delta_n_pos_jerk_acc_posi[u]          = pow((4*n1_pos_jerk_acc_posi[u]*q_dotdot_bounds_max_optimized[u]*dt*dt), 2) + ((8*q_dotdot_bounds_max_optimized[u]*pow(dt,2))*((-4*(q_bounds_min[u]-q[u]))+(-2*q_ddot[u]*pow(dt,2)*(pow(n1_pos_jerk_acc_posi[u],2)+n1_pos_jerk_acc_posi[u]))+((4/3)*(n1_pos_jerk_acc_posi[u]-pow(n1_pos_jerk_acc_posi[u],3))*q_dddot_bounds_max[u]*pow(dt,3))+(2*n1_pos_jerk_acc_posi[u]*q_dotdot_bounds_max_optimized[u]*pow(dt,2))));
n_pos_jerk_acc_posi_real_two_sol(u,0) = ((4*n1_pos_jerk_acc_posi[u]*q_dotdot_bounds_max_optimized[u]*pow(dt,2)) + sqrt(delta_n_pos_jerk_acc_posi[u]))/(-4*q_dotdot_bounds_max_optimized[u]*pow(dt,2));
n_pos_jerk_acc_posi_real_two_sol(u,1) = ((4*n1_pos_jerk_acc_posi[u]*q_dotdot_bounds_max_optimized[u]*pow(dt,2)) - sqrt(delta_n_pos_jerk_acc_posi[u]))/(-4*q_dotdot_bounds_max_optimized[u]*pow(dt,2));


if(n_pos_jerk_acc_posi_real_two_sol(u,0)>0){
n_pos_jerk_acc_posi_two_sol(u,0) = round_up(n_pos_jerk_acc_posi_real_two_sol(u,0));
}
else{n_pos_jerk_acc_posi_two_sol(u,0) = 10e6;}

if(n_pos_jerk_acc_posi_real_two_sol(u,1)>0){
n_pos_jerk_acc_posi_two_sol(u,1) = round_up(n_pos_jerk_acc_posi_real_two_sol(u,1));
}
else{n_pos_jerk_acc_posi_two_sol(u,1) = 10e6;}


q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 0) = ((q_bounds_min[u]-q_k2[u])/((n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,0))*pow(dt,2))) + ((-pow(n1_pos_jerk_acc_posi[u],2)+n1_pos_jerk_acc_posi[u]-2*n1_pos_jerk_acc_posi[u]*n_pos_jerk_acc_posi_two_sol(u,0))/(2*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,0))))*q_ddot_k2[u] + ((-pow(n1_pos_jerk_acc_posi[u],3)+3*pow(n1_pos_jerk_acc_posi[u],2)-2*n1_pos_jerk_acc_posi[u]-3*n_pos_jerk_acc_posi_two_sol(u,0)*(pow(n1_pos_jerk_acc_posi[u],2)-n1_pos_jerk_acc_posi[u]))/(6*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,0))))*q_dddot_bounds_max[u]*dt + ((n_pos_jerk_acc_posi_two_sol(u,0)-pow(n_pos_jerk_acc_posi_two_sol(u,0),2))/(2*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,0))))*q_dotdot_bounds_max_optimized[u] - (q_dot[u]/dt);
q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 1) = ((q_bounds_min[u]-q_k2[u])/((n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,1))*pow(dt,2))) + ((-pow(n1_pos_jerk_acc_posi[u],2)+n1_pos_jerk_acc_posi[u]-2*n1_pos_jerk_acc_posi[u]*n_pos_jerk_acc_posi_two_sol(u,1))/(2*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,1))))*q_ddot_k2[u] + ((-pow(n1_pos_jerk_acc_posi[u],3)+3*pow(n1_pos_jerk_acc_posi[u],2)-2*n1_pos_jerk_acc_posi[u]-3*n_pos_jerk_acc_posi_two_sol(u,1)*(pow(n1_pos_jerk_acc_posi[u],2)-n1_pos_jerk_acc_posi[u]))/(6*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,1))))*q_dddot_bounds_max[u]*dt + ((n_pos_jerk_acc_posi_two_sol(u,1)-pow(n_pos_jerk_acc_posi_two_sol(u,1),2))/(2*(n1_pos_jerk_acc_posi[u]+n_pos_jerk_acc_posi_two_sol(u,1))))*q_dotdot_bounds_max_optimized[u] - (q_dot[u]/dt);
q_dotdot_bounds_min_comp_Jerk_Acc_Posi(u,0)             = maximum(q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 0), q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 1));



if(q_dotdot_bounds_min_comp_Jerk_Acc_Posi(u,0) == q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 0)){
n_pos_jerk_acc_posi[u] = n_pos_jerk_acc_posi_two_sol(u,0);
}
if(q_dotdot_bounds_min_comp_Jerk_Acc_Posi(u,1) == q_dotdot_bounds_min_comp_Jerk_Acc_Posi_two_values(u, 1)){
n_pos_jerk_acc_posi[u] = n_pos_jerk_acc_posi_two_sol(u,1);
}

}


return n_pos_jerk_acc_posi;
}





