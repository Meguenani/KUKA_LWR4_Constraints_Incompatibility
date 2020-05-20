#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>
#include "Maximum.h"
#include "Minimum.h"
#include "choose_q_ddot_final_bounds.h" 
#include "save_data_in_txt.h"


//Check if two domains of q_ddot are disconnected
int check_domaines_1_and_2_disconnected(double domaine_1_max, double domaine_1_min, double domaine_2_max, double domaine_2_min){
int disconnected = 0;
double dumb_connected_domain_max = minimum(domaine_1_max, domaine_2_max);
double dumb_connected_domain_min = maximum(domaine_1_min, domaine_2_min);

if(dumb_connected_domain_max <= dumb_connected_domain_min){
disconnected = 1;
}

else{
disconnected = 0;
}

return disconnected;
}







//Sert à régler le problème des domaines de q_ddot_comp disjoints. //Pour 3 domaines
Eigen::VectorXd choose_q_ddot_final_bounds_3(double q_dot_u, double q_dotdot_bounds_max_comp_Jerk_Posi_u, double q_dotdot_bounds_min_comp_Jerk_Posi_u, double q_dotdot_bounds_max_comp_Jerk_Vel_u, double q_dotdot_bounds_min_comp_Jerk_Vel_u, double q_dotdot_bounds_max_comp_Acc_Posi_u, double q_dotdot_bounds_min_comp_Acc_Posi_u){
Eigen::VectorXd q_ddot_final_bounds(2);   //Case "0" max et case "1" min.
double connected_jerk_posi_and_Jerk_Vel_domaines_max;
double connected_jerk_posi_and_Jerk_Vel_domaines_min;

double connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_max;
double connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_min;

int domaines_jerk_posi_and_Jerk_Vel_disconnected       = 0; //To know if the domaines_jerk_posi_and_Jerk_Vel_disconnected are disconnected or not
int domaines_connected_jerk_posi_Jerk_Vel_and_Acc_Posi = 0; //To know if the domaines connected_jerk_posi_Jerk_Vel and Acc_Posi are connected

//case 1
//Intersection 1
domaines_jerk_posi_and_Jerk_Vel_disconnected  = check_domaines_1_and_2_disconnected(q_dotdot_bounds_max_comp_Jerk_Posi_u, q_dotdot_bounds_min_comp_Jerk_Posi_u, q_dotdot_bounds_max_comp_Jerk_Vel_u, q_dotdot_bounds_min_comp_Jerk_Vel_u);

if(domaines_jerk_posi_and_Jerk_Vel_disconnected == 1 && q_dot_u >= 0){ //On bouge vers les contraintes q et q_dot positives
connected_jerk_posi_and_Jerk_Vel_domaines_max = minimum(q_dotdot_bounds_max_comp_Jerk_Posi_u, q_dotdot_bounds_max_comp_Jerk_Vel_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_jerk_posi_and_Jerk_Vel_domaines_min = minimum(q_dotdot_bounds_min_comp_Jerk_Posi_u, q_dotdot_bounds_min_comp_Jerk_Vel_u);
}


else if(domaines_jerk_posi_and_Jerk_Vel_disconnected == 1 && q_dot_u <= 0){ //On bouge vers les contraintes q et q_dot negatives
connected_jerk_posi_and_Jerk_Vel_domaines_max = maximum(q_dotdot_bounds_max_comp_Jerk_Posi_u, q_dotdot_bounds_max_comp_Jerk_Vel_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_jerk_posi_and_Jerk_Vel_domaines_min = maximum(q_dotdot_bounds_min_comp_Jerk_Posi_u, q_dotdot_bounds_min_comp_Jerk_Vel_u);
}

else if(domaines_jerk_posi_and_Jerk_Vel_disconnected == 0){ //Les domaines jerk_posi_and_Jerk_Vel ne sont pas déconnectés (Ils sont joints !)
connected_jerk_posi_and_Jerk_Vel_domaines_max = minimum(q_dotdot_bounds_max_comp_Jerk_Posi_u, q_dotdot_bounds_max_comp_Jerk_Vel_u);
connected_jerk_posi_and_Jerk_Vel_domaines_min = maximum(q_dotdot_bounds_min_comp_Jerk_Posi_u, q_dotdot_bounds_min_comp_Jerk_Vel_u);
}



//Intersection 2
domaines_connected_jerk_posi_Jerk_Vel_and_Acc_Posi     = check_domaines_1_and_2_disconnected(connected_jerk_posi_and_Jerk_Vel_domaines_max, connected_jerk_posi_and_Jerk_Vel_domaines_min, q_dotdot_bounds_max_comp_Acc_Posi_u, q_dotdot_bounds_min_comp_Acc_Posi_u);

if(domaines_connected_jerk_posi_Jerk_Vel_and_Acc_Posi == 1 && q_dot_u >= 0){ //On bouge vers les contraintes q et q_dot positives
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_max = minimum(connected_jerk_posi_and_Jerk_Vel_domaines_max, q_dotdot_bounds_max_comp_Acc_Posi_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_min = minimum(connected_jerk_posi_and_Jerk_Vel_domaines_min, q_dotdot_bounds_min_comp_Acc_Posi_u);
}


else if(domaines_connected_jerk_posi_Jerk_Vel_and_Acc_Posi == 1 && q_dot_u <= 0){ //On bouge vers les contraintes q et q_dot negatives
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_max = maximum(connected_jerk_posi_and_Jerk_Vel_domaines_max, q_dotdot_bounds_max_comp_Acc_Posi_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_min = maximum(connected_jerk_posi_and_Jerk_Vel_domaines_min, q_dotdot_bounds_min_comp_Acc_Posi_u);
}

else if(domaines_connected_jerk_posi_Jerk_Vel_and_Acc_Posi == 0){ //Les domaines jerk_posi_and_Jerk_Vel ne sont pas déconnectés (Ils sont joints !)
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_max = minimum(connected_jerk_posi_and_Jerk_Vel_domaines_max, q_dotdot_bounds_max_comp_Acc_Posi_u);
connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_min = maximum(connected_jerk_posi_and_Jerk_Vel_domaines_min, q_dotdot_bounds_min_comp_Acc_Posi_u);
}


q_ddot_final_bounds[0] = connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_max;
q_ddot_final_bounds[1] = connected_jerk_posi_Jerk_Vel_and_Acc_Posi_domaines_min;

return q_ddot_final_bounds;
}









//Sert à régler le problème des domaines de q_ddot_comp disjoints. //JUSTE POUR 2 	DOMAINES
Eigen::VectorXd choose_q_ddot_final_bounds_2(int u, double q_dot_u, double q_dotdot_bounds_max_comp_Jerk_Vel_u, double q_dotdot_bounds_min_comp_Jerk_Vel_u, double q_dotdot_bounds_max_comp_Acc_Posi_u, double q_dotdot_bounds_min_comp_Acc_Posi_u, double q_dotdot_bounds_max_optimized_u, double q_dotdot_bounds_min_optimized_u){
Eigen::VectorXd q_ddot_final_bounds(2);   //Case "0" max et case "1" min.
double connected_Jerk_Vel_and_Acc_Posi_domaines_max;
double connected_Jerk_Vel_and_Acc_Posi_domaines_min;

int domaines_Jerk_Vel_and_Acc_Posi_disconnected; //To know if the domaines_jerk_posi_and_Jerk_Vel_disconnected are disconnected or not
//std::cout<<"domaines_Jerk_Vel_and_Acc_Posi_disconnected : "<< domaines_Jerk_Vel_and_Acc_Posi_disconnected <<std::endl;


//case 1
//Intersection 1
domaines_Jerk_Vel_and_Acc_Posi_disconnected  = check_domaines_1_and_2_disconnected(q_dotdot_bounds_max_comp_Jerk_Vel_u, q_dotdot_bounds_min_comp_Jerk_Vel_u, q_dotdot_bounds_max_comp_Acc_Posi_u, q_dotdot_bounds_min_comp_Acc_Posi_u);

if(u==0){
save_domaines_Jerk_Vel_and_Acc_Posi_disconnected(domaines_Jerk_Vel_and_Acc_Posi_disconnected);
}

if(domaines_Jerk_Vel_and_Acc_Posi_disconnected == 1 && q_dot_u > 0){ //On bouge vers les contraintes q et q_dot positives
//std::cout<<"cas 1"<<std::endl;
connected_Jerk_Vel_and_Acc_Posi_domaines_max = minimum(q_dotdot_bounds_max_comp_Jerk_Vel_u, q_dotdot_bounds_max_comp_Acc_Posi_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
//connected_Jerk_Vel_and_Acc_Posi_domaines_min = minimum(q_dotdot_bounds_min_comp_Jerk_Vel_u, q_dotdot_bounds_min_comp_Acc_Posi_u);
connected_Jerk_Vel_and_Acc_Posi_domaines_min = q_dotdot_bounds_min_optimized_u;


}

else if(domaines_Jerk_Vel_and_Acc_Posi_disconnected == 1 && q_dot_u < 0){ //On bouge vers les contraintes q et q_dot négatives
//std::cout<<"cas 2"<<std::endl;
//connected_Jerk_Vel_and_Acc_Posi_domaines_max = maximum(q_dotdot_bounds_max_comp_Jerk_Vel_u, q_dotdot_bounds_max_comp_Acc_Posi_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_Jerk_Vel_and_Acc_Posi_domaines_max = q_dotdot_bounds_max_optimized_u;
connected_Jerk_Vel_and_Acc_Posi_domaines_min = maximum(q_dotdot_bounds_min_comp_Jerk_Vel_u, q_dotdot_bounds_min_comp_Acc_Posi_u);
}

else if(domaines_Jerk_Vel_and_Acc_Posi_disconnected == 1 && q_dot_u == 0){ //On bouge vers les contraintes q et q_dot négatives
connected_Jerk_Vel_and_Acc_Posi_domaines_max = q_dotdot_bounds_max_optimized_u;
connected_Jerk_Vel_and_Acc_Posi_domaines_min = q_dotdot_bounds_min_optimized_u;
}

else if(domaines_Jerk_Vel_and_Acc_Posi_disconnected == 0){ //Les domaines jerk_posi_and_Jerk_Vel ne sont pas déconnectés (Ils sont joints !)
//std::cout<<"cas 3"<<std::endl;

connected_Jerk_Vel_and_Acc_Posi_domaines_max = minimum(q_dotdot_bounds_max_comp_Jerk_Vel_u, q_dotdot_bounds_max_comp_Acc_Posi_u);//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_Jerk_Vel_and_Acc_Posi_domaines_min = maximum(q_dotdot_bounds_min_comp_Jerk_Vel_u, q_dotdot_bounds_min_comp_Acc_Posi_u);

/*
connected_Jerk_Vel_and_Acc_Posi_domaines_max = q_dotdot_bounds_max_optimized_u;//Domaine résultant de la connexion des deux domaines "jerk_posi_and_Jerk_Vel"
connected_Jerk_Vel_and_Acc_Posi_domaines_min = q_dotdot_bounds_min_optimized_u;
*/
}


/*
std::cout<<" "<<std::endl;
std::cout<<"domaines_Jerk_Vel_and_Acc_Posi_disconnected : "<< domaines_Jerk_Vel_and_Acc_Posi_disconnected <<std::endl;
std::cout<<"q_dot_u : "<< q_dot_u <<std::endl;
std::cout<<"connected_Jerk_Vel_and_Acc_Posi_domaines_max : "<< domaines_Jerk_Vel_and_Acc_Posi_disconnected <<std::endl;
std::cout<<"connected_Jerk_Vel_and_Acc_Posi_domaines_min : "<< domaines_Jerk_Vel_and_Acc_Posi_disconnected <<std::endl;
*/
q_ddot_final_bounds[0] = connected_Jerk_Vel_and_Acc_Posi_domaines_max;
q_ddot_final_bounds[1] = connected_Jerk_Vel_and_Acc_Posi_domaines_min;

return q_ddot_final_bounds;
}









