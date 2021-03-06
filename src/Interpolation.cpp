#include <iostream>
#include <Eigen/Lgsm>
#include <Eigen/Dense>    
#include <cmath> 
#include "Absolute.h"
#include "save_data_in_txt.h"
#include "Maximum.h"


Eigen::VectorXd compute_poly_coefficients(double x_I, double x_F, double x_dot_I, double x_dot_F, double x_dot_dot_I, double x_dot_dot_F, double x_dot_dot_dot_I, double x_dot_dot_dot_F,  double T){
Eigen::VectorXd a_i(8);
Eigen::Matrix<double, 4, 4> A;
Eigen::VectorXd b(4);
Eigen::VectorXd X(4);

using namespace std;



A << 1,  1,  1, 1,
     4,  5,  6, 7, 
     12, 20, 30, 42, 
     24, 60, 120, 210;


if((x_F - x_I) == 0){
X << 0, 0, 0, 0;
a_i(0) = 0; 
a_i(1) = 0;
a_i(2) = 0;
a_i(3) = 0;
a_i(4) = X(0);
a_i(5) = X(1);
a_i(6) = X(2);
a_i(7) = X(3);
}
else{
b << 1 - (((x_dot_I * T)/(x_F - x_I)) + ((x_dot_dot_I * pow(T, 2))/(2 * (x_F - x_I))) + ((x_dot_dot_dot_I * pow(T, 3))/(6 * (x_F - x_I)))), ((x_dot_F * T)/(x_F - x_I)) - (((x_dot_I * T)/(x_F - x_I)) + ((x_dot_dot_I * pow(T, 2))/(x_F - x_I)) + ((x_dot_dot_dot_I * pow(T, 3))/(2 * (x_F - x_I)))), ((x_dot_dot_F * pow(T, 2))/(x_F - x_I)) - ((x_dot_dot_I * pow(T, 2))/(x_F - x_I)) - ((x_dot_dot_dot_I * pow(T, 3))/(x_F - x_I)), ((x_dot_dot_dot_F * pow(T, 3))/(x_F - x_I)) - ((x_dot_dot_dot_I * pow(T, 3))/(x_F - x_I));
X = A.colPivHouseholderQr().solve(b);

a_i(0) = 0; 
a_i(1) = (x_dot_I * T)/(x_F - x_I);
a_i(2) = (x_dot_dot_I * pow(T, 2))/(2 * (x_F - x_I));
a_i(3) = (x_dot_dot_dot_I * pow(T, 3))/(6 * (x_F - x_I));
a_i(4) = X(0);
a_i(5) = X(1);
a_i(6) = X(2);
a_i(7) = X(3);
}


return a_i;
}




double compute_normalization_coeff_s_dot(Eigen::VectorXd a_i_1){
double t_2;                 //Temps [0:1] pour parcourir le polynôme 
double max_poly;            //The maximum of the polynome
double min_poly;            //The minimum of the polynome
double abs_max_poly;        //Absolute maximum of the polynome
double s_dot_normalization_coeff;
double s_dot_value;
double s_dot_value_prev_max = 0; //The previous maximum value of the polynome
double s_dot_value_prev_min = 0; //The previous minimum value of the polynome

for(t_2 = 0; t_2 < 1; t_2 = t_2+0.001){
s_dot_value = a_i_1(1) + 2*a_i_1(2)*t_2 + 3*a_i_1(3)*pow(t_2, 2) + 4*a_i_1(4)*pow(t_2, 3) + 5*a_i_1(5)*pow(t_2, 4) + 6*a_i_1(6)*pow(t_2, 5) + 7*a_i_1(7)*pow(t_2, 6);
if(s_dot_value > s_dot_value_prev_max){
max_poly = s_dot_value;
s_dot_value_prev_max = max_poly;
}

if(s_dot_value < s_dot_value_prev_min){
min_poly = s_dot_value;
s_dot_value_prev_min = min_poly;
}
}
abs_max_poly = std::max(max_poly, std::abs(min_poly));
s_dot_normalization_coeff = 1/abs_max_poly;
return s_dot_normalization_coeff;
}












double compute_normalization_coeff_s_dot_dot(Eigen::VectorXd a_i_1){
double t_2;                 //Temps [0:1] pour parcourir le polynôme 
double max_poly;            //The maximum of the polynome
double min_poly;            //The minimum of the polynome
double abs_max_poly;        //Absolute maximum of the polynome
double s_dot_dot_normalization_coeff;
double s_dot_dot_value;
double s_dot_dot_value_prev_max = 0; //The previous maximum value of the polynome
double s_dot_dot_value_prev_min = 0; //The previous minimum value of the polynome

for(t_2 = 0; t_2 < 1; t_2 = t_2+0.001){
s_dot_dot_value = 2*a_i_1(2) + 6*a_i_1(3)*t_2 + 12*a_i_1(4)*pow(t_2, 2) + 20*a_i_1(5)*pow(t_2, 3) + 30*a_i_1(6)*pow(t_2, 4) + 42*a_i_1(7)*pow(t_2, 5);
if(s_dot_dot_value > s_dot_dot_value_prev_max){
max_poly = s_dot_dot_value;
s_dot_dot_value_prev_max = max_poly;
}

if(s_dot_dot_value < s_dot_dot_value_prev_min){
min_poly = s_dot_dot_value;
s_dot_dot_value_prev_min = min_poly;
}
}
abs_max_poly = std::max(max_poly, std::abs(min_poly));
s_dot_dot_normalization_coeff = 1/abs_max_poly;
return s_dot_dot_normalization_coeff;
}



double compute_trig_time_posi(Eigen::VectorXd a_i_1, double T, double current_posi, double nxt_step_des, double init_posi, double target_posi){
double t = 0;        //Temps de parcours du polynôme s
double trig_time;    //Temps auquel s'arrête t        
double s;            //Valeur instantannée du polynôme s
double targeted_s;   //Valeur voulue de s pour avoir la continuité au niveau de l'erreur en position
targeted_s = absolute((nxt_step_des - current_posi)/(target_posi - init_posi));

std::cout << "  " <<std::endl;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  absolute: " << absolute(-0.00012) <<std::endl;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  targeted_s: " << targeted_s <<std::endl;

while(t <= 1){
s = a_i_1(0) + a_i_1(1)*t + a_i_1(2)*pow(t, 2) + a_i_1(3)*pow(t, 3) + a_i_1(4)*pow(t, 4) + a_i_1(5)*pow(t, 5) + a_i_1(6)*pow(t, 6) + a_i_1(7)*pow(t, 7);
t = t + 0.001;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  t: " << t <<std::endl;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  s: " << s <<std::endl;
if(s >= targeted_s){
break;
}
}
trig_time = t * T;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  t: " << t <<std::endl;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  T: " << T <<std::endl;
std::cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  trig_time: " << trig_time <<std::endl;
std::cout << "  " <<std::endl;
std::cout << "  " <<std::endl;
std::cout << "  " <<std::endl;
return trig_time;     //Ce temps la lorsuqe placé dans s va entrainé une première valeur désirée de v qui créera la même erreur que ce qu'on avait avant.
}





double compute_trig_time_vel(Eigen::VectorXd a_i_1_d, double T, double V, double nxt_step_des_V, double init_posi, double target_posi){
double t = 0;        //Temps de parcours du polynôme s_dot
double trig_time;    //Temps auquel s'arrête t        
double s_dot;        //Valeur instantannée du polynôme s_dot
double targeted_s_dot;   //Valeur voulue de s pour avoir la continuité au niveau de l'erreur en position
targeted_s_dot = absolute((nxt_step_des_V * T) / (target_posi - init_posi));

while(t <= 1){
s_dot = a_i_1_d(1)  + 2*a_i_1_d(2)*t + 3*a_i_1_d(3)*pow(t, 2) + 4*a_i_1_d(4)*pow(t, 3) + 5*a_i_1_d(5)*pow(t, 4) + 6*a_i_1_d(6)*pow(t, 5) + 7*a_i_1_d(7)*pow(t, 6);
t = t + 0.001;
if(s_dot >= targeted_s_dot){
break;
}
}
trig_time = t * T;
return trig_time;    //Ce temps la lorsuqe placé dans s va entrainé une première valeur désirée de v qui créera la même erreur que ce qu'on avait avant.
}










double compute_trig_s(double prev_posi, double nxt_step_des, double init_posi, double target_posi){  
double trig_s;            //Valeur instantannée du polynôme s
trig_s = (nxt_step_des - prev_posi)/(target_posi - init_posi);
return trig_s;     
}



double compute_trig_s_dot(double T, double prev_V, double nxt_step_des_V, double init_V, double target_V, double init_posi, double target_posi){
double trig_s_dot;            //Valeur instantannée du polynôme s
trig_s_dot = (((nxt_step_des_V - prev_V) + init_V) * T)/(target_posi - init_posi);
return trig_s_dot;     
}
















double compute_trj_time(double init_posi_x, double target_posi_x, double init_posi_y, double target_posi_y, double init_posi_z, double target_posi_z, double v_x_max, double acc_x_max, double v_y_max, double acc_y_max, double v_z_max, double acc_z_max){  
double T; 
double T_x; 
double T_y; 
double T_z;
double T_v_x; 
double T_v_y; 
double T_v_z; 
double T_acc_x; 
double T_acc_y; 
double T_acc_z;
double max_T_x_T_y;

    T_v_x           	=  absolute((1/(v_x_max)) * (target_posi_x - init_posi_x) * (35/16)); 
    T_v_y           	=  absolute((1/(v_y_max)) * (target_posi_y - init_posi_y) * (35/16)); 
    T_v_z           	=  absolute((1/(v_z_max)) * (target_posi_z - init_posi_z) * (35/16)); 

    T_acc_x         	=  sqrt(absolute((1/(acc_x_max)) * (target_posi_x - init_posi_x) * (85*sqrt(5)/25))); 
    T_acc_y         	=  sqrt(absolute((1/(acc_y_max)) * (target_posi_y - init_posi_y) * (85*sqrt(5)/25))); 
    T_acc_z         	=  sqrt(absolute((1/(acc_z_max)) * (target_posi_z - init_posi_z) * (85*sqrt(5)/25)));

    T_x 	    	    =  maximum(T_v_x, T_acc_x); 
    T_y 	    	    =  maximum(T_v_y, T_acc_y); 
    T_z 	     	    =  maximum(T_v_z, T_acc_z); 
/*
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "                <<std::endl;
    std::cout << "v_x_max       :"                << v_x_max <<std::endl;
    std::cout << "target_posi_x :"                << target_posi_x <<std::endl;
    std::cout << "init_posi_x   :"                << init_posi_x <<std::endl;
    std::cout << "  "                <<std::endl;
    std::cout << "  "                <<std::endl;
    std::cout << "T_v_x : "                << (1/(v_x_max)) * (target_posi_x - init_posi_x) * (35/16) <<std::endl;
    std::cout << "T_acc_x : "              << (1/(acc_x_max)) * (target_posi_x - init_posi_x) * (85*sqrt(5)/25) <<std::endl;

    std::cout << "T_v_y : "                << (1/(v_y_max)) * (target_posi_y - init_posi_y) * (35/16) <<std::endl;
    std::cout << "T_acc_y : "              << (1/(acc_y_max)) * (target_posi_y - init_posi_y) * (85*sqrt(5)/25) <<std::endl;
    
    std::cout << "T_v_z : "                << (1/(v_z_max)) * (target_posi_z - init_posi_z) * (35/16) <<std::endl;
    std::cout << "T_acc_z : "              << (1/(acc_z_max)) * (target_posi_z - init_posi_z) * (85*sqrt(5)/25) <<std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "                <<std::endl;
*/
    
    max_T_x_T_y     	=  maximum(T_x, T_y);
    T               	=  maximum(max_T_x_T_y, T_z);
return T;
}





double compute_angle_time(double init_rot_angle, double target_rot_angle, double v_angle_max, double acc_angle_max){
double T_angle; 
double T_v_angle; 
double T_acc_angle; 

    T_v_angle           	=  abs((1/(v_angle_max)) * (target_rot_angle - init_rot_angle) * (35/16)); 
    T_acc_angle         	=  sqrt(abs((1/(acc_angle_max)) * (target_rot_angle - init_rot_angle) * (85*sqrt(5)/25))); 
    T_angle 	    	        =  maximum(T_v_angle, T_acc_angle); 

return T_angle; 
}




Eigen::VectorXd compute_nxt_step_des_x(double init_posi_x, double target_posi_x, Eigen::VectorXd a_i_x, double Posi_x_curr,double T_x, double t_2_x){
double s_x;  
double s_dot_x; 
double s_dot_dot_x; 
double s_dot_dot_dot_x;
double nxt_step_des_x;
double nxt_step_des_V_7_x;
double nxt_step_des_Acc_7_x;
double nxt_step_des_Jerk_7_x;
Eigen::VectorXd nxt_step_des_trj_x(4); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if(T_x <= 0){
        s_x = 1;
        s_dot_x = 0;
        s_dot_dot_x = 0;  
	}
	else{
        s_x                   = a_i_x(0) + a_i_x(1)*t_2_x + a_i_x(2)*pow(t_2_x, 2) + a_i_x(3)*pow(t_2_x, 3) + a_i_x(4)*pow(t_2_x, 4) + a_i_x(5)*pow(t_2_x, 5) + a_i_x(6)*pow(t_2_x, 6) + a_i_x(7)*pow(t_2_x, 7); 
        s_dot_x               =              a_i_x(1)     + 2*a_i_x(2)*t_2_x + 3*a_i_x(3)*pow(t_2_x, 2) + 4*a_i_x(4)*pow(t_2_x, 3) + 5*a_i_x(5)*pow(t_2_x, 4) + 6*a_i_x(6)*pow(t_2_x, 5) + 7*a_i_x(7)*pow(t_2_x, 6);
        s_dot_dot_x           =                           2*a_i_x(2) + 6*a_i_x(3)*t_2_x + 12*a_i_x(4)*pow(t_2_x, 2) + 20*a_i_x(5)*pow(t_2_x, 3) + 30*a_i_x(6)*pow(t_2_x, 4) + 42*a_i_x(7)*pow(t_2_x, 5);
	s_dot_dot_dot_x       =                                          6*a_i_x(3) + 24*a_i_x(4)*t_2_x + 60*a_i_x(5)*pow(t_2_x, 2) + 120*a_i_x(6)*pow(t_2_x, 3) + 210*a_i_x(7)*pow(t_2_x, 4);
       }



        if(T_x <= 0){
        nxt_step_des_x       = init_posi_x;
	nxt_step_des_V_7_x   = 0;
	nxt_step_des_Acc_7_x = 0;
	}
        else{
	nxt_step_des_x 	      = init_posi_x + (target_posi_x - init_posi_x) * s_x;
	nxt_step_des_V_7_x    = (1/T_x) * (target_posi_x - init_posi_x) * s_dot_x;
	nxt_step_des_Acc_7_x  = (1/pow(T_x, 2)) * (target_posi_x - init_posi_x) * s_dot_dot_x;
	nxt_step_des_Jerk_7_x = (1/pow(T_x, 3)) * (target_posi_x - init_posi_x) * s_dot_dot_dot_x;
	}

save_s_x(s_x);
save_s_dot_x(s_dot_x);
save_s_dot_dot_x(s_dot_dot_x);
save_s_dot_dot_dot_x(s_dot_dot_dot_x);
save_t_2_x(t_2_x);
save_T_x(T_x);

nxt_step_des_trj_x << nxt_step_des_x, nxt_step_des_V_7_x, nxt_step_des_Acc_7_x, nxt_step_des_Jerk_7_x;
return nxt_step_des_trj_x;
}







Eigen::VectorXd compute_nxt_step_des_y(double init_posi_y, double target_posi_y, Eigen::VectorXd a_i_y, double Posi_y_curr,double T_y, double t_2_y){
double s_y;  
double s_dot_y; 
double s_dot_dot_y; 
double s_dot_dot_dot_y;
double nxt_step_des_y;
double nxt_step_des_V_7_y;
double nxt_step_des_Acc_7_y;
double nxt_step_des_Jerk_7_y;
Eigen::VectorXd nxt_step_des_trj_y(4); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if(T_y <= 0){
        s_y = 1;
        s_dot_y = 0;
        s_dot_dot_y = 0;  
	}
	else{
        s_y                   = a_i_y(0) + a_i_y(1)*t_2_y + a_i_y(2)*pow(t_2_y, 2) + a_i_y(3)*pow(t_2_y, 3) + a_i_y(4)*pow(t_2_y, 4) + a_i_y(5)*pow(t_2_y, 5) + a_i_y(6)*pow(t_2_y, 6) + a_i_y(7)*pow(t_2_y, 7); 
        s_dot_y               =              a_i_y(1)     + 2*a_i_y(2)*t_2_y + 3*a_i_y(3)*pow(t_2_y, 2) + 4*a_i_y(4)*pow(t_2_y, 3) + 5*a_i_y(5)*pow(t_2_y, 4) + 6*a_i_y(6)*pow(t_2_y, 5) + 7*a_i_y(7)*pow(t_2_y, 6);
        s_dot_dot_y           =                           2*a_i_y(2) + 6*a_i_y(3)*t_2_y + 12*a_i_y(4)*pow(t_2_y, 2) + 20*a_i_y(5)*pow(t_2_y, 3) + 30*a_i_y(6)*pow(t_2_y, 4) + 42*a_i_y(7)*pow(t_2_y, 5);
	s_dot_dot_dot_y       =                                          6*a_i_y(3) + 24*a_i_y(4)*t_2_y + 60*a_i_y(5)*pow(t_2_y, 2) + 120*a_i_y(6)*pow(t_2_y, 3) + 210*a_i_y(7)*pow(t_2_y, 4);
       }



        if(T_y <= 0){
        nxt_step_des_y       = init_posi_y;
	nxt_step_des_V_7_y   = 0;
	nxt_step_des_Acc_7_y = 0;
	}
        else{
	nxt_step_des_y 	      = init_posi_y + (target_posi_y - init_posi_y) * s_y;
	nxt_step_des_V_7_y    = (1/T_y) * (target_posi_y - init_posi_y) * s_dot_y;
	nxt_step_des_Acc_7_y  = (1/pow(T_y, 2)) * (target_posi_y - init_posi_y) * s_dot_dot_y;
	nxt_step_des_Jerk_7_y = (1/pow(T_y, 3)) * (target_posi_y - init_posi_y) * s_dot_dot_dot_y;
	}


save_s_y(s_y);
save_s_dot_y(s_dot_y);
save_s_dot_dot_y(s_dot_dot_y);
save_s_dot_dot_dot_y(s_dot_dot_dot_y);
save_t_2_y(t_2_y);
save_T_y(T_y);

nxt_step_des_trj_y << nxt_step_des_y, nxt_step_des_V_7_y, nxt_step_des_Acc_7_y, nxt_step_des_Jerk_7_y;
return nxt_step_des_trj_y;
}









Eigen::VectorXd compute_nxt_step_des_z(double init_posi_z, double target_posi_z, Eigen::VectorXd a_i_z, double Posi_z_curr,double T_z, double t_2_z){
double s_z;  
double s_dot_z; 
double s_dot_dot_z; 
double s_dot_dot_dot_z;
double nxt_step_des_z;
double nxt_step_des_V_7_z;
double nxt_step_des_Acc_7_z;
double nxt_step_des_Jerk_7_z;
Eigen::VectorXd nxt_step_des_trj_z(4); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant




if(T_z <= 0){
        s_z             = 1;
        s_dot_z         = 0;
        s_dot_dot_z     = 0; 
	}
	else{
        s_z                   = a_i_z(0) + a_i_z(1)*t_2_z + a_i_z(2)*pow(t_2_z, 2) + a_i_z(3)*pow(t_2_z, 3) + a_i_z(4)*pow(t_2_z, 4) + a_i_z(5)*pow(t_2_z, 5) + a_i_z(6)*pow(t_2_z, 6) + a_i_z(7)*pow(t_2_z, 7); 
        s_dot_z               =              a_i_z(1)     + 2*a_i_z(2)*t_2_z + 3*a_i_z(3)*pow(t_2_z, 2) + 4*a_i_z(4)*pow(t_2_z, 3) + 5*a_i_z(5)*pow(t_2_z, 4) + 6*a_i_z(6)*pow(t_2_z, 5) + 7*a_i_z(7)*pow(t_2_z, 6);
        s_dot_dot_z           =                           2*a_i_z(2) + 6*a_i_z(3)*t_2_z + 12*a_i_z(4)*pow(t_2_z, 2) + 20*a_i_z(5)*pow(t_2_z, 3) + 30*a_i_z(6)*pow(t_2_z, 4) + 42*a_i_z(7)*pow(t_2_z, 5);
	s_dot_dot_dot_z       =                                          6*a_i_z(3) + 24*a_i_z(4)*t_2_z + 60*a_i_z(5)*pow(t_2_z, 2) + 120*a_i_z(6)*pow(t_2_z, 3) + 210*a_i_z(7)*pow(t_2_z, 4);
       }



        if(T_z <= 0){
        nxt_step_des_z        = init_posi_z;
	nxt_step_des_V_7_z    = 0;
	nxt_step_des_Acc_7_z  = 0;
	}
        else{
	nxt_step_des_z 	      = init_posi_z + (target_posi_z - init_posi_z) * s_z;
	nxt_step_des_V_7_z    = (1/T_z) * (target_posi_z - init_posi_z) * s_dot_z;
	nxt_step_des_Acc_7_z  = (1/pow(T_z, 2)) * (target_posi_z - init_posi_z) * s_dot_dot_z;
	nxt_step_des_Jerk_7_z = (1/pow(T_z, 3)) * (target_posi_z - init_posi_z) * s_dot_dot_dot_z;
	}

save_s_z(s_z);
save_s_dot_z(s_dot_z);
save_s_dot_dot_z(s_dot_dot_z);
save_s_dot_dot_dot_z(s_dot_dot_dot_z);
save_t_2_z(t_2_z);
save_T_z(T_z);

nxt_step_des_trj_z << nxt_step_des_z, nxt_step_des_V_7_z, nxt_step_des_Acc_7_z, nxt_step_des_Jerk_7_z;
return nxt_step_des_trj_z;
}








Eigen::VectorXd compute_nxt_step_des_alpha(double init_orient_alpha, double target_orient_alpha, Eigen::VectorXd a_i_alpha, double T_alpha, double t_1_alpha, double t_2_alpha){
double s_dot_alpha; 
double s_dot_dot_alpha; 
double s_dot_dot_dot_alpha;
double nxt_step_des_alpha;
double nxt_step_des_V_7_alpha;
double nxt_step_des_Acc_7_alpha;
double nxt_step_des_Jerk_7_alpha;
Eigen::VectorXd nxt_step_des_trj_alpha(3); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if((t_1_alpha - T_alpha) < 0.001 && (t_1_alpha - T_alpha) > 0){
        s_dot_alpha         = 0;
        s_dot_dot_alpha     = 0;  
	s_dot_dot_dot_alpha = 0;
	}
	else{
        s_dot_alpha               =                a_i_alpha(1) + 2*a_i_alpha(2)*t_2_alpha + 3*a_i_alpha(3)*pow(t_2_alpha, 2) + 4*a_i_alpha(4)*pow(t_2_alpha, 3) + 5*a_i_alpha(5)*pow(t_2_alpha, 4) + 6*a_i_alpha(6)*pow(t_2_alpha, 5) + 7*a_i_alpha(7)*pow(t_2_alpha, 6);
        s_dot_dot_alpha           =                               2*a_i_alpha(2) + 6*a_i_alpha(3)*t_2_alpha + 12*a_i_alpha(4)*pow(t_2_alpha, 2) + 20*a_i_alpha(5)*pow(t_2_alpha, 3) + 30*a_i_alpha(6)*pow(t_2_alpha, 4) + 42*a_i_alpha(7)*pow(t_2_alpha, 5);
	s_dot_dot_dot_alpha       =                                                6*a_i_alpha(3) + 24*a_i_alpha(4)*t_2_alpha + 60*a_i_alpha(5)*pow(t_2_alpha, 2) + 120*a_i_alpha(6)*pow(t_2_alpha, 3) + 210*a_i_alpha(7)*pow(t_2_alpha, 4);
       }


        if((t_1_alpha - T_alpha) < 0.001 && (t_1_alpha - T_alpha) > 0){
	nxt_step_des_V_7_alpha    = 0;
	nxt_step_des_Acc_7_alpha  = 0;
	nxt_step_des_Jerk_7_alpha = 0;
	}
        else{
             if(T_alpha == 0){
	          nxt_step_des_V_7_alpha    = 0;
                  nxt_step_des_Acc_7_alpha  = 0;
	          nxt_step_des_Jerk_7_alpha = 0;
                 }        
             else{
                  nxt_step_des_V_7_alpha    = (1/T_alpha) * (target_orient_alpha - init_orient_alpha) * s_dot_alpha;
                  nxt_step_des_Acc_7_alpha  = (1/pow(T_alpha, 2)) * (target_orient_alpha - init_orient_alpha) * s_dot_dot_alpha;
	          nxt_step_des_Jerk_7_alpha = (1/pow(T_alpha, 3)) * (target_orient_alpha - init_orient_alpha) * s_dot_dot_dot_alpha;
                 }
	}


save_s_dot_alpha(s_dot_alpha);
save_s_dot_dot_alpha(s_dot_dot_alpha);
save_s_dot_dot_dot_alpha(s_dot_dot_dot_alpha);
save_t_2_alpha(t_2_alpha);
save_T_alpha(T_alpha);

nxt_step_des_trj_alpha <<  nxt_step_des_V_7_alpha, nxt_step_des_Acc_7_alpha, nxt_step_des_Jerk_7_alpha;
return nxt_step_des_trj_alpha;
}








Eigen::VectorXd compute_nxt_step_des_beta(double init_orient_beta, double target_orient_beta, Eigen::VectorXd a_i_beta, double T_beta, double t_1_beta, double t_2_beta){
double s_dot_beta; 
double s_dot_dot_beta; 
double s_dot_dot_dot_beta;
double nxt_step_des_beta;
double nxt_step_des_V_7_beta;
double nxt_step_des_Acc_7_beta;
double nxt_step_des_Jerk_7_beta;
Eigen::VectorXd nxt_step_des_trj_beta(3); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if((t_1_beta - T_beta) < 0.001 && (t_1_beta - T_beta) > 0){
        s_dot_beta         = 0;
        s_dot_dot_beta     = 0;  
	s_dot_dot_dot_beta = 0;
	}
	else{
        s_dot_beta               =                a_i_beta(1) + 2*a_i_beta(2)*t_2_beta + 3*a_i_beta(3)*pow(t_2_beta, 2) + 4*a_i_beta(4)*pow(t_2_beta, 3) + 5*a_i_beta(5)*pow(t_2_beta, 4) + 6*a_i_beta(6)*pow(t_2_beta, 5) + 7*a_i_beta(7)*pow(t_2_beta, 6);
        s_dot_dot_beta           =                               2*a_i_beta(2) + 6*a_i_beta(3)*t_2_beta + 12*a_i_beta(4)*pow(t_2_beta, 2) + 20*a_i_beta(5)*pow(t_2_beta, 3) + 30*a_i_beta(6)*pow(t_2_beta, 4) + 42*a_i_beta(7)*pow(t_2_beta, 5);
	s_dot_dot_dot_beta       =                                                6*a_i_beta(3) + 24*a_i_beta(4)*t_2_beta + 60*a_i_beta(5)*pow(t_2_beta, 2) + 120*a_i_beta(6)*pow(t_2_beta, 3) + 210*a_i_beta(7)*pow(t_2_beta, 4);
       }


        if((t_1_beta - T_beta) < 0.001 && (t_1_beta - T_beta) > 0){
	nxt_step_des_V_7_beta    = 0;
	nxt_step_des_Acc_7_beta  = 0;
	nxt_step_des_Jerk_7_beta = 0;
	}
        else{
             if(T_beta == 0){
	          nxt_step_des_V_7_beta    = 0;
	          nxt_step_des_Acc_7_beta  = 0;
	          nxt_step_des_Jerk_7_beta = 0;
                 }        
             else{
	          nxt_step_des_V_7_beta    = (1/T_beta) * (target_orient_beta - init_orient_beta) * s_dot_beta;
	          nxt_step_des_Acc_7_beta  = (1/pow(T_beta, 2)) * (target_orient_beta - init_orient_beta) * s_dot_dot_beta;
	          nxt_step_des_Jerk_7_beta = (1/pow(T_beta, 3)) * (target_orient_beta - init_orient_beta) * s_dot_dot_dot_beta;
                 }
	}


save_s_dot_beta(s_dot_beta);
save_s_dot_dot_beta(s_dot_dot_beta);
save_s_dot_dot_dot_beta(s_dot_dot_dot_beta);
save_t_2_beta(t_2_beta);
save_T_beta(T_beta);

nxt_step_des_trj_beta <<  nxt_step_des_V_7_beta, nxt_step_des_Acc_7_beta, nxt_step_des_Jerk_7_beta;
return nxt_step_des_trj_beta;
}



Eigen::VectorXd compute_nxt_step_des_gamma(double init_orient_gamma, double target_orient_gamma, Eigen::VectorXd a_i_gamma, double T_gamma, double t_1_gamma, double t_2_gamma){
double s_dot_gamma; 
double s_dot_dot_gamma; 
double s_dot_dot_dot_gamma;
double nxt_step_des_gamma;
double nxt_step_des_V_7_gamma;
double nxt_step_des_Acc_7_gamma;
double nxt_step_des_Jerk_7_gamma;
Eigen::VectorXd nxt_step_des_trj_gamma(3); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if((t_1_gamma - T_gamma) < 0.001 && (t_1_gamma - T_gamma) > 0){
        s_dot_gamma         = 0;
        s_dot_dot_gamma     = 0;  
	s_dot_dot_dot_gamma = 0;
	}
	else{
        s_dot_gamma               =                a_i_gamma(1) + 2*a_i_gamma(2)*t_2_gamma + 3*a_i_gamma(3)*pow(t_2_gamma, 2) + 4*a_i_gamma(4)*pow(t_2_gamma, 3) + 5*a_i_gamma(5)*pow(t_2_gamma, 4) + 6*a_i_gamma(6)*pow(t_2_gamma, 5) + 7*a_i_gamma(7)*pow(t_2_gamma, 6);
        s_dot_dot_gamma           =                               2*a_i_gamma(2) + 6*a_i_gamma(3)*t_2_gamma + 12*a_i_gamma(4)*pow(t_2_gamma, 2) + 20*a_i_gamma(5)*pow(t_2_gamma, 3) + 30*a_i_gamma(6)*pow(t_2_gamma, 4) + 42*a_i_gamma(7)*pow(t_2_gamma, 5);
	s_dot_dot_dot_gamma       =                                                6*a_i_gamma(3) + 24*a_i_gamma(4)*t_2_gamma + 60*a_i_gamma(5)*pow(t_2_gamma, 2) + 120*a_i_gamma(6)*pow(t_2_gamma, 3) + 210*a_i_gamma(7)*pow(t_2_gamma, 4);
       }


        if((t_1_gamma - T_gamma) < 0.001 && (t_1_gamma - T_gamma) > 0){
	nxt_step_des_V_7_gamma    = 0;
	nxt_step_des_Acc_7_gamma  = 0;
	nxt_step_des_Jerk_7_gamma = 0;
	}
        else{
             if(T_gamma == 0){
	          nxt_step_des_V_7_gamma    = 0;
	          nxt_step_des_Acc_7_gamma  = 0;
	          nxt_step_des_Jerk_7_gamma = 0;
                 }        
             else{
	          nxt_step_des_V_7_gamma    = (1/T_gamma) * (target_orient_gamma - init_orient_gamma) * s_dot_gamma;
	          nxt_step_des_Acc_7_gamma  = (1/pow(T_gamma, 2)) * (target_orient_gamma - init_orient_gamma) * s_dot_dot_gamma;
	          nxt_step_des_Jerk_7_gamma = (1/pow(T_gamma, 3)) * (target_orient_gamma - init_orient_gamma) * s_dot_dot_dot_gamma;
                 }
	}


save_s_dot_gamma(s_dot_gamma);
save_s_dot_dot_gamma(s_dot_dot_gamma);
save_s_dot_dot_dot_gamma(s_dot_dot_dot_gamma);
save_t_2_gamma(t_2_gamma);
save_T_gamma(T_gamma);

nxt_step_des_trj_gamma <<  nxt_step_des_V_7_gamma, nxt_step_des_Acc_7_gamma, nxt_step_des_Jerk_7_gamma;
return nxt_step_des_trj_gamma;
}















Eigen::VectorXd compute_nxt_step_des_angle(double init_posi_angle, double target_posi_angle, Eigen::VectorXd a_i_angle, double Posi_angle_curr, double nxt_step_des_angle_prev, double T_angle, double t_1_angle, double t_2_angle){
double s_angle;  
double s_dot_angle; 
double s_dot_dot_angle; 
double s_dot_dot_dot_angle;
double nxt_step_des_angle;
double nxt_step_des_V_7_angle;
double nxt_step_des_Acc_7_angle;
double nxt_step_des_Jerk_7_angle;
Eigen::VectorXd nxt_step_des_trj_angle(4); //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant

if((t_1_angle - T_angle) < 0.001 && (t_1_angle - T_angle) > 0){
        s_angle             = 1;
        s_dot_angle         = 0;
        s_dot_dot_angle     = 0;  
	s_dot_dot_dot_angle = 0;
	}
	else{
        s_angle                   = a_i_angle(0) + a_i_angle(1)*t_2_angle + a_i_angle(2)*pow(t_2_angle, 2) + a_i_angle(3)*pow(t_2_angle, 3) + a_i_angle(4)*pow(t_2_angle, 4) + a_i_angle(5)*pow(t_2_angle, 5) + a_i_angle(6)*pow(t_2_angle, 6) + a_i_angle(7)*pow(t_2_angle, 7); 
        s_dot_angle               =                a_i_angle(1) + 2*a_i_angle(2)*t_2_angle + 3*a_i_angle(3)*pow(t_2_angle, 2) + 4*a_i_angle(4)*pow(t_2_angle, 3) + 5*a_i_angle(5)*pow(t_2_angle, 4) + 6*a_i_angle(6)*pow(t_2_angle, 5) + 7*a_i_angle(7)*pow(t_2_angle, 6);
        s_dot_dot_angle           =                               2*a_i_angle(2) + 6*a_i_angle(3)*t_2_angle + 12*a_i_angle(4)*pow(t_2_angle, 2) + 20*a_i_angle(5)*pow(t_2_angle, 3) + 30*a_i_angle(6)*pow(t_2_angle, 4) + 42*a_i_angle(7)*pow(t_2_angle, 5);
	s_dot_dot_dot_angle       =                                                6*a_i_angle(3) + 24*a_i_angle(4)*t_2_angle + 60*a_i_angle(5)*pow(t_2_angle, 2) + 120*a_i_angle(6)*pow(t_2_angle, 3) + 210*a_i_angle(7)*pow(t_2_angle, 4);
       }

/*
	std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "  <<std::endl; 
	std::cout << "s_angle : "  << s_angle <<std::endl;
	std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "  <<std::endl; 
*/

        if((t_1_angle - T_angle) < 0.001 && (t_1_angle - T_angle) > 0){
        nxt_step_des_angle        = nxt_step_des_angle_prev;
	nxt_step_des_V_7_angle    = 0;
	nxt_step_des_Acc_7_angle  = 0;
	nxt_step_des_Jerk_7_angle = 0;
	}
        else{
	nxt_step_des_angle 	  = init_posi_angle + (target_posi_angle - init_posi_angle) * s_angle;
	nxt_step_des_V_7_angle    = (1/T_angle) * (target_posi_angle - init_posi_angle) * s_dot_angle;
	nxt_step_des_Acc_7_angle  = (1/pow(T_angle, 2)) * (target_posi_angle - init_posi_angle) * s_dot_dot_angle;
	nxt_step_des_Jerk_7_angle = (1/pow(T_angle, 3)) * (target_posi_angle - init_posi_angle) * s_dot_dot_dot_angle;
	}


save_s_angle(s_angle);
save_s_dot_angle(s_dot_angle);
save_s_dot_dot_angle(s_dot_dot_angle);
save_s_dot_dot_dot_angle(s_dot_dot_dot_angle);
save_t_2_angle(t_2_angle);
save_T_angle(T_angle);

nxt_step_des_trj_angle << nxt_step_des_angle, nxt_step_des_V_7_angle, nxt_step_des_Acc_7_angle, nxt_step_des_Jerk_7_angle;
return nxt_step_des_trj_angle;
}
















double compute_quat_cosHalfTheta(Eigen::Displacementd::Rotation3D q_I, Eigen::Displacementd::Rotation3D q_F){
// Calculate angle between the two orientation
	double cosHalfTheta = q_I.w() * q_F.w() + q_I.x() * q_F.x() + q_I.y() * q_F.y() + q_I.z() * q_F.z();
	if (cosHalfTheta < 0) {

 	 q_F.w() = -q_F.w();
         q_F.x() = -q_F.x();
         q_F.y() = -q_F.y();
         q_F.z() = -q_F.z();

 	 cosHalfTheta = -cosHalfTheta;
	}
return cosHalfTheta;
}




Eigen::Displacementd::Rotation3D compute_nxt_step_des_quat(Eigen::Displacementd::Rotation3D q_I, Eigen::Displacementd::Rotation3D q_F, Eigen::VectorXd a_i_angle, double cosHalfTheta, double T_angle, double t_1_angle, double t_2_angle){
Eigen::Displacementd::Rotation3D nxt_step_des_quat;
double Theta;
double halfTheta;
double sinHalfTheta;
double cosTheta;
double sinTheta;
double ratioA;
double ratioB;
double s_angle; //Angle équivalent aux à la rotation due aux quaternions

	// if q_I=q_F or q_I=-q_F then theta = 0 and we can return q_I
	if (absolute(cosHalfTheta) >= 1.0){

		nxt_step_des_quat.w() = q_I.w();
                nxt_step_des_quat.x() = q_I.x();
                nxt_step_des_quat.y() = q_I.y();
                nxt_step_des_quat.z() = q_I.z();

		return nxt_step_des_quat;
	}


	// Calculate temporary values.
	halfTheta    = acos(cosHalfTheta);
        Theta        = 2 * halfTheta;
	sinHalfTheta = sqrt(1.0 - (cosHalfTheta * cosHalfTheta));
	cosTheta     = cos(Theta);
        sinTheta     = sqrt(1.0 - (cosTheta * cosTheta)); 
        





	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to q_I or q_F
	if (absolute(sinHalfTheta) < 0.001){ // fabs is floating point absolute       --> This will make cosHalfTheta positif so 0 < theta < 180

		nxt_step_des_quat.w() = (q_I.w() * 0.5 + q_F.w() * 0.5);
		nxt_step_des_quat.x() = (q_I.x() * 0.5 + q_F.x() * 0.5);
		nxt_step_des_quat.y() = (q_I.y() * 0.5 + q_F.y() * 0.5);
		nxt_step_des_quat.z() = (q_I.z() * 0.5 + q_F.z() * 0.5);
		return nxt_step_des_quat;
	}



        s_angle = a_i_angle(0) + a_i_angle(1)*t_2_angle + a_i_angle(2)*pow(t_2_angle, 2) + a_i_angle(3)*pow(t_2_angle, 3) + a_i_angle(4)*pow(t_2_angle, 4) + a_i_angle(5)*pow(t_2_angle, 5) + a_i_angle(6)*pow(t_2_angle, 6) + a_i_angle(7)*pow(t_2_angle, 7); 


        if((t_1_angle - T_angle) < 0.001 && (t_1_angle - T_angle) > 0){
        s_angle             = 1;
	}

	ratioA = sin((1 - s_angle) * Theta) / sinTheta;
	ratioB = sin(s_angle * Theta) / sinTheta; 



        if((t_1_angle - T_angle) < 0.001 && (t_1_angle - T_angle) > 0){
	nxt_step_des_quat.w() = nxt_step_des_quat.w();
	nxt_step_des_quat.x() = nxt_step_des_quat.x();
	nxt_step_des_quat.y() = nxt_step_des_quat.y();
	nxt_step_des_quat.z() = nxt_step_des_quat.z();
	}


	//calculate Quaternion.
	nxt_step_des_quat.w() = (q_I.w() * ratioA + q_F.w() * ratioB);
	nxt_step_des_quat.x() = (q_I.x() * ratioA + q_F.x() * ratioB);
	nxt_step_des_quat.y() = (q_I.y() * ratioA + q_F.y() * ratioB);
	nxt_step_des_quat.z() = (q_I.z() * ratioA + q_F.z() * ratioB);

/*
	  std::cout << "   "  << std::endl; 
	  std::cout << "   "  << std::endl; 
	  std::cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤"  << std::endl; 
	  std::cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤nxt_step_des_quat¤¤¤¤¤¤¤¤¤¤¤¤¤¤"  << std::endl; 
	  std::cout << "halfTheta : "  << halfTheta << std::endl; 
	  std::cout << "Theta : "  << Theta << std::endl; 
	  std::cout << "sinHalfTheta : "  << sinHalfTheta << std::endl; 
	  std::cout << "cosTheta : "  << cosTheta << std::endl; 
	  std::cout << "sinTheta : "  << sinTheta << std::endl; 
	  std::cout << "s_angle : "  << s_angle << std::endl; 
	  std::cout << "t_2_angle : "  << t_2_angle << std::endl; 
	  std::cout << "a_i_angle : "  << a_i_angle << std::endl; 
	  std::cout << "ratioA nxt_step_des_quat: "  << ratioA << std::endl; 
	  std::cout << "ratioB nxt_step_des_quat: "  << ratioB << std::endl; 
	  std::cout << "q_I : "         << q_I << std::endl; 
	  std::cout << "nxt_step_des_quat : "         << nxt_step_des_quat << std::endl; 
	  std::cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤nxt_step_des_quat¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤"  << std::endl; 
	  std::cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤"  << std::endl; 
	  std::cout << "   "  << std::endl; 
	  std::cout << "   "  << std::endl; 
*/
	return nxt_step_des_quat;
}














