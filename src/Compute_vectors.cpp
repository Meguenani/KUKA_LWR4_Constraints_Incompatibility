#include <iostream>
#include <Eigen/Core>
#include <Eigen/Lgsm>
#include <stdio.h>      
#include <math.h>       
#include "Compute_vectors.h"

using namespace std;

Eigen::Vector3d compute_unit_vect(Eigen::Displacementd C_pt_ob_seg, Eigen::Displacementd C_pt_seg){
Eigen::Vector3d vect_unitaire;

vect_unitaire[0] = (C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x())/sqrt(pow(C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x(),2) + pow(C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y(),2) + pow(C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z(),2));
vect_unitaire[1] = (C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y())/sqrt(pow(C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x(),2) + pow(C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y(),2) + pow(C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z(),2)); 
vect_unitaire[2] = (C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z())/sqrt(pow(C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x(),2) + pow(C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y(),2) + pow(C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z(),2));

return vect_unitaire;
}





//Calcul du vecteur unitaire entre le point désiré et le point actuel de l'effecteur
//H_7 est la position et l'orientation de l'effecteur. X_des, Y_des & Z_des sont les coordonnées du point désiré
Eigen::Vector3d compute_unit_vect_2(double nxt_step_des_x, double nxt_step_des_y, double nxt_step_des_z, double X_des, double Y_des, double Z_des){

Eigen::Vector3d vect_unitaire_2;

vect_unitaire_2[0] = (X_des - nxt_step_des_x)/sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2));
vect_unitaire_2[1] = (Y_des - nxt_step_des_y)/sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2)); 
vect_unitaire_2[2] = (Z_des - nxt_step_des_z)/sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2));
std::cout << "sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2)) " << sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2)) <<std::endl;

return vect_unitaire_2;
}







Eigen::Vector3d compute_unit_vect_3(Eigen::Displacementd H_7, double X_des, double Y_des, double Z_des){

Eigen::Vector3d vect_unitaire_3;

vect_unitaire_3[0] = (X_des - H_7.getTranslation().x())/sqrt(pow(X_des - H_7.getTranslation().x(),2) + pow(Y_des - H_7.getTranslation().y(),2) + pow(Z_des - H_7.getTranslation().z(),2));
vect_unitaire_3[1] = (Y_des - H_7.getTranslation().y())/sqrt(pow(X_des - H_7.getTranslation().x(),2) + pow(Y_des - H_7.getTranslation().y(),2) + pow(Z_des - H_7.getTranslation().z(),2)); 
vect_unitaire_3[2] = (Z_des - H_7.getTranslation().z())/sqrt(pow(X_des - H_7.getTranslation().x(),2) + pow(Y_des - H_7.getTranslation().y(),2) + pow(Z_des - H_7.getTranslation().z(),2));

std::cout << "sqrt(pow(X_des - H_7.getTranslation().x(),2) + pow(Y_des - H_7.getTranslation().y(),2) + pow(Z_des - H_7.getTranslation().z(),2)) " << sqrt(pow(X_des - H_7.getTranslation().x(),2) + pow(Y_des - H_7.getTranslation().y(),2) + pow(Z_des - H_7.getTranslation().z(),2))<<std::endl;
return vect_unitaire_3;
}





int compute_nbr_unit_vect_to_X_des(double nxt_step_des_x, double nxt_step_des_y, double nxt_step_des_z, double X_des, double Y_des, double Z_des, double traj_step_size){

Eigen::Vector3d vect_unitaire_2;
int nbr_unit_vect_to_X_des;
double dist_to_X_circle_des;
double norm_unit_vect;

dist_to_X_circle_des = sqrt(pow(X_des - nxt_step_des_x,2) + pow(Y_des - nxt_step_des_y,2) + pow(Z_des - nxt_step_des_z,2));

vect_unitaire_2[0] = traj_step_size * (X_des - nxt_step_des_x)/dist_to_X_circle_des;
vect_unitaire_2[1] = traj_step_size * (Y_des - nxt_step_des_y)/dist_to_X_circle_des; 
vect_unitaire_2[2] = traj_step_size * (Z_des - nxt_step_des_z)/dist_to_X_circle_des;

norm_unit_vect = sqrt(pow(vect_unitaire_2[0],2) + pow(vect_unitaire_2[1],2) + pow(vect_unitaire_2[2],2));

nbr_unit_vect_to_X_des =dist_to_X_circle_des/norm_unit_vect;

return nbr_unit_vect_to_X_des;
}





Eigen::Vector3d compute_normal_unit_vect(Eigen::Vector3d vect_unitaire){
Eigen::Vector3d normal_unit_vect;

double d = 0;
double e = -vect_unitaire[1];
double f =  vect_unitaire[2];

normal_unit_vect[0] = d;
normal_unit_vect[1] = e/sqrt(pow(d,2) + pow(e,2) + pow(f,2));
normal_unit_vect[2] = f/sqrt(pow(d,2) + pow(e,2) + pow(f,2));

return normal_unit_vect;
}



double compute_angle(Eigen::Twistd V_7, Eigen::Displacementd C_pt_ob_seg, Eigen::Displacementd C_pt_seg){
double norm_dist;
double norm_V_7;
double scal_product; 
double angle;
norm_dist    = sqrt(pow(C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x(),2) + pow(C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y(),2) + pow(C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z(),2));
norm_V_7     = sqrt(pow(V_7[3],2) + pow(V_7[4],2) + pow(V_7[5],2));
scal_product = V_7[3] * (C_pt_ob_seg.getTranslation().x() - C_pt_seg.getTranslation().x()) + V_7[4] * (C_pt_ob_seg.getTranslation().y() - C_pt_seg.getTranslation().y()) + V_7[5] * (C_pt_ob_seg.getTranslation().z() - C_pt_seg.getTranslation().z());
angle        = acos(scal_product/(norm_V_7*norm_dist)); 
/*
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << norm_dist <<std::endl; 
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << norm_V_7 <<std::endl; 
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << norm_V_7*norm_dist <<std::endl; 
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << scal_product <<std::endl; 
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << scal_product/(norm_V_7*norm_dist) <<std::endl; 
std::cout << "ANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLEANGLE : " << angle <<std::endl; 
*/
return angle;
}








