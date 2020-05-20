#include <iostream>
#include <Eigen/Core>
#include <Eigen/Lgsm>
#include <stdio.h>      
#include <math.h>       
#include "Compute_energy.h"

double compute_E(double V_seg_sgn_norm, Eigen::Vector3d V_seg, double m_eq_i_j){
double E;
E = know_sign(V_seg_sgn_norm) * 0.5 * m_eq_i_j * V_seg.transpose() * V_seg;
return E;
}



double compute_E_f(double V_pt_C_seg, double m_eq_i_j){      //E_f is the kinetic energy in the future    //V_pt_C_seg is the velocity of the potential contact point in the direction of the nearest distance to the obstacle
double E;
E = know_sign(V_pt_C_seg) * 0.5 * m_eq_i_j * V_pt_C_seg * V_pt_C_seg;
return E;
}



double compute_E6(double V_seg_sgn_norm, Eigen::Vector3d V_seg, double m_eq_i_j){
double E;
E = know_sign(V_seg_sgn_norm) * 0.5 * m_eq_i_j * V_seg.transpose() * V_seg;
/*
std::cout << "E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6 "<< std::endl;
std::cout << "E6 " << E << std::endl;
std::cout << "m_eq_i_j " << m_eq_i_j << std::endl;
std::cout << "V_seg.transpose() * V_seg  " << V_seg.transpose() * V_seg  << std::endl;
std::cout << "E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6 "<< std::endl;
*/
return E;
}




double compute_E2(double V_seg_sgn_norm, Eigen::Vector3d V_seg, Eigen::Matrix<double, 3, 3> M_cart_inv, int segment_number){
double E;
E = know_sign(V_seg_sgn_norm) * 0.5 * V_seg.transpose() * M_cart_inv.inverse() * V_seg;
//E = 0.5 * V_seg.transpose() * M_cart_inv.inverse() * V_seg;


Eigen::Matrix<double, 3, 3> M_test;
Eigen::Matrix<double, 3, 3> M_test_inverse;
/*
M_test << M_cart_inv(0,0),   M_cart_inv(0,1),   M_cart_inv(0,2),
          M_cart_inv(1,0),   M_cart_inv(1,1),   M_cart_inv(1,2),
          M_cart_inv(2,0),   M_cart_inv(2,1),   M_cart_inv(2,2);

M_test << 2.49599,   0.426575,      0.0403622,
  	  0.426575,  0.0729036,     0.00689808,
 	  0.0403622, 0.00689808,    2.69529;


bool invertible;
double determinant;
M_test.computeInverseAndDetWithCheck(M_test_inverse,determinant,invertible);

std::cout << "E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2 "<< std::endl;
std::cout << "E2 " << E << std::endl;
std::cout << "M_cart_inv "<< std::endl << M_cart_inv << std::endl;

std::cout << "M_cart_inv(0,0) " << M_cart_inv(0,0) << std::endl;
std::cout << "M_cart_inv(0,1) " << M_cart_inv(0,1) << std::endl;
std::cout << "M_cart_inv(0,2) " << M_cart_inv(0,2) << std::endl;
std::cout << "M_cart_inv(1,0) " << M_cart_inv(1,0) << std::endl;
std::cout << "M_cart_inv(1,1) " << M_cart_inv(1,1) << std::endl;
std::cout << "M_cart_inv(1,2) " << M_cart_inv(1,2) << std::endl;
std::cout << "M_cart_inv(2,0) " << M_cart_inv(2,0) << std::endl;
std::cout << "M_cart_inv(2,1) " << M_cart_inv(2,1) << std::endl;
std::cout << "M_cart_inv(2,2) " << M_cart_inv(2,2) << std::endl;


std::cout << "M_cart_inv.inverse() "<< std::endl << M_cart_inv.inverse() << std::endl;
std::cout << "M_test.inverse() "<< std::endl << M_test.inverse() << std::endl;

std::cout << "Its determinant is " << determinant << std::endl;
if(invertible) {
std::cout << "It is invertible, and its inverse is:" << std::endl << M_test_inverse << std::endl;
}
else {
std::cout << "It is not invertible." << std::endl;
}
std::cout << "E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2 "<< std::endl;
*/

return E;
}



double compute_E_max(double d, double d_safe, double E_safe, double d_max, double F_max){
double E_max;
int cas;


	if(d<d_max && d>d_safe){ 
		E_max = (F_max*(d-d_safe)) +  E_safe;
cas = 1;
		   }

        if(d <= d_safe){
		E_max =  E_safe;
cas = 2;
	           }

        if(d >= d_max){
		E_max  = F_max*(d_max-d_safe) +  E_safe;
cas = 3;
	           }

return E_max;
}





double compute_E_limit(double d, double d_safe, double E_safe, double d_max, double F_max){
double E_max = F_max*(d_max-d_safe) +  E_safe;
double E_limit;

if(d <= d_safe){
d = d_safe;
}
double t = (d - d_safe)/(d_max - d_safe);
E_limit = (10*pow(t, 3)-15*pow(t, 4)+6*pow(t, 5)) * (E_max - E_safe) + E_safe;
//E_limit = (10*pow(t, 3)-15*pow(t, 4)+6*pow(t, 5));
return E_limit;
}





double compute_jerk_pond(double d, double d_safe, double d_thres){
double alpha;
double t = (d - d_thres)/(d_safe - d_thres);

	if(d<d_thres && d>d_safe){ 
		alpha =  (10*pow(t, 3)-15*pow(t, 4)+6*pow(t, 5)) * 9 + 1;
		   }

        if(d <= d_safe){
		alpha =  1;
	           }

        if(d >= d_thres){
		alpha  = 10;
	           }

return alpha;
}

/*
double compute_E_max(double d, double d_safe, double E_safe, double d_max, double F_max){
double E_max;


		if(E_safe == 0){
		E_max = (F_max*(d-d_safe)) +  E_safe;
		}


		if(E_safe > 0){

                if(d <= d_safe){
                E_max =  E_safe; 
                }

                if(d > d_safe){
                E_max = (F_max*(d-d_safe)) +  E_safe;

                }
		}

return E_max;
}
*/





int know_sign(double V){
int sign;

if(V < 0){
sign = -1;
}

if(V > 0){
sign = 1;
}

if(V == 0){
sign = 1;
}      
                                                                     
return sign; 
}




	

