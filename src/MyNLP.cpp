// Copyright (C) 2004, 2006 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// $Id: MyNLP.cpp 2005 2011-06-06 12:55:16Z stefan $
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-11-05

#include "/home/anis/ros_workspace/kuka_controller/include/MyNLP.hpp"
#include <Eigen/Lgsm>
#include <iostream>
#include <cassert>
#include "Compute_energy.h"
#include "Compute_prj_velocity.h"
#include "save_data_in_txt.h"



using namespace Ipopt;
using std::cout;
using std::endl;

double g_0;
double g_1;
double g_2;
double g_3;
double g_4;
double g_5;

double g_0_max;
double g_1_max;
double g_2_max;
double g_3_max;
double g_4_max;
double g_5_max;

//Distance entre chaque segment et l'obstacle
double global_dist_safe;          //Distance min autorisée entre chaque segfment et l'obstacle
double global_dist_07_nrst_ob;
double global_dist_06_nrst_ob;
double global_dist_05_nrst_ob;
double global_dist_04_nrst_ob;
double global_dist_03_nrst_ob;
double global_dist_02_nrst_ob;

double global_kp;
double global_kd;


/* Constructor. */
MyNLP::MyNLP(            Eigen::Matrix<double, 3, 7> J_70_l, 
			 Eigen::Matrix<double, 3, 7> J_60_l,
 		         Eigen::Matrix<double, 3, 7> J_50_l,
  		         Eigen::Matrix<double, 3, 7> J_40_l,
  		         Eigen::Matrix<double, 3, 7> J_30_l,
  		         Eigen::Matrix<double, 3, 7> J_20_l,
                         Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_inv, 
			 Eigen::Matrix<double, 7, 1> b,
			 Eigen::Matrix<double, 3, 1> Jdot_qdot_l,
			 Eigen::VectorXd X_err,
			 Eigen::Twistd V_7,
                         double Kp,
                         double E_max_7, double E_max_6, double E_max_5, double E_max_4, double E_max_3, double E_max_2,
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau1,             
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau2,  
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau3,  
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau4,  
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau5,  
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau6,  
			 Eigen::Matrix<double, 7, 1> grad_vect_tau_tau7,  
		         char* id_nrst_ob_7,
		         char* id_nrst_ob_6,
		         char* id_nrst_ob_5,
		         char* id_nrst_ob_4,
		         char* id_nrst_ob_3,
		         char* id_nrst_ob_2,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_70,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_60,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_50,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_40,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_30,
			 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_20,
			 Eigen::Matrix<double, 1, 7> J_70_C_proj,
			 Eigen::Matrix<double, 1, 7> J_60_C_proj,
			 Eigen::Matrix<double, 1, 7> J_50_C_proj,
			 Eigen::Matrix<double, 1, 7> J_40_C_proj,
			 Eigen::Matrix<double, 1, 7> J_30_C_proj,
			 Eigen::Matrix<double, 1, 7> J_20_C_proj,
			 Eigen::VectorXd q_dot,
                         double dt,
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_aj,
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_aj, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_ai, 
			 std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_aj,
             		 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J7_inv,  
              		 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J6_inv,  
                 	 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J5_inv,  
               		 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J4_inv,  
                 	 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J3_inv,  
               		 Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J2_inv, 
                         double m_eq_7_j,
                         double m_eq_6_j,
                         double m_eq_5_j,
                         double m_eq_4_j,
                         double m_eq_3_j,
                         double m_eq_2_j,
			 double V_7_ob_sgn_norm_k2,			//Projected velocity signed norm in the k2 time step
			 double V_6_ob_sgn_norm_k2,	
			 double V_5_ob_sgn_norm_k2,	
			 double V_4_ob_sgn_norm_k2,	
			 double V_3_ob_sgn_norm_k2,	
			 double V_2_ob_sgn_norm_k2,
                	 double dist_07_nrst_ob,     			//The distance to the nearest obstacle is the minimum of the distances above
                	 double dist_06_nrst_ob,
                	 double dist_05_nrst_ob,
                	 double dist_04_nrst_ob,
                	 double dist_03_nrst_ob,
                	 double dist_02_nrst_ob,
			 double d_safe,
			 Eigen::Vector3d Vect_dist_nrst_ob_07,          //Vector representing the distance to the nearest obstacle to segment 7
			 Eigen::Vector3d Vect_dist_nrst_ob_06,   
			 Eigen::Vector3d Vect_dist_nrst_ob_05,   
			 Eigen::Vector3d Vect_dist_nrst_ob_04,   
			 Eigen::Vector3d Vect_dist_nrst_ob_03,   
			 Eigen::Vector3d Vect_dist_nrst_ob_02,     
              		 Eigen::Matrix<double, 3, 3> M_cart_7_inv,       //Inertie équivalente inversée pour les mouvements linéaires du segment 7 : 1/mij
              		 Eigen::Matrix<double, 3, 3> M_cart_6_inv,
            		 Eigen::Matrix<double, 3, 3> M_cart_5_inv,
            		 Eigen::Matrix<double, 3, 3> M_cart_4_inv,
            		 Eigen::Matrix<double, 3, 3> M_cart_3_inv,
             		 Eigen::Matrix<double, 3, 3> M_cart_2_inv, 	
			 Number* H_L_val0_cpnts,
  			 Number* H_L_val1_cpnts,
  			 Number* H_L_val2_cpnts,
  			 Number* H_L_val3_cpnts,
  			 Number* H_L_val4_cpnts,
 			 Number* H_L_val5_cpnts,
 			 Number* H_L_val6_cpnts,
 			 Number* H_L_val7_cpnts,
 			 Number* H_L_val8_cpnts,
  			 Number* H_L_val9_cpnts,
  			 Number* H_L_val10_cpnts,
 			 Number* H_L_val11_cpnts,
 			 Number* H_L_val12_cpnts,
 			 Number* H_L_val13_cpnts,
  			 Number* H_L_val14_cpnts,
  			 Number* H_L_val15_cpnts,
 			 Number* H_L_val16_cpnts,
 			 Number* H_L_val17_cpnts,
 			 Number* H_L_val18_cpnts,
 			 Number* H_L_val19_cpnts,
 			 Number* H_L_val20_cpnts,
  			 Number* H_L_val21_cpnts,
 			 Number* H_L_val22_cpnts,
 			 Number* H_L_val23_cpnts,
  			 Number* H_L_val24_cpnts,
  			 Number* H_L_val25_cpnts,
 			 Number* H_L_val26_cpnts,
			 Number* H_L_val27_cpnts)


{
  J_70_l_inj                 = J_70_l;
  J_60_l_inj                 = J_60_l;
  J_50_l_inj                 = J_50_l;
  J_40_l_inj                 = J_40_l;
  J_30_l_inj                 = J_30_l;
  J_20_l_inj                 = J_20_l;
  M_inv_inj                  = M_inv;
  b_inj                      = b;
  Jdot_qdot_l_inj            = Jdot_qdot_l;
  X_err_inj                  = X_err;
  V_7_inj                    = V_7;
  Kp_inj                     = Kp;
  E_max_7_inj                = E_max_7;
  E_max_6_inj                = E_max_6;
  E_max_5_inj                = E_max_5;
  E_max_4_inj                = E_max_4;
  E_max_3_inj                = E_max_3;
  E_max_2_inj                = E_max_2;
  grad_vect_tau_tau1_inj     = grad_vect_tau_tau1;             
  grad_vect_tau_tau2_inj     = grad_vect_tau_tau2;  
  grad_vect_tau_tau3_inj     = grad_vect_tau_tau3;  
  grad_vect_tau_tau4_inj     = grad_vect_tau_tau4;  
  grad_vect_tau_tau5_inj     = grad_vect_tau_tau5;  
  grad_vect_tau_tau6_inj     = grad_vect_tau_tau6;  
  grad_vect_tau_tau7_inj     = grad_vect_tau_tau7; 
  id_nrst_ob_7_inj           = id_nrst_ob_7;
  id_nrst_ob_6_inj           = id_nrst_ob_6;
  id_nrst_ob_5_inj           = id_nrst_ob_5;
  id_nrst_ob_4_inj           = id_nrst_ob_4;
  id_nrst_ob_3_inj           = id_nrst_ob_3;
  id_nrst_ob_2_inj           = id_nrst_ob_2;
  J_70_inj     		     = J_70;
  J_60_inj      	     = J_60;
  J_50_inj      	     = J_50;
  J_40_inj      	     = J_40;
  J_30_inj      	     = J_30;
  J_20_inj      	     = J_20;
  J_70_C_proj_inj            = J_70_C_proj;
  J_60_C_proj_inj            = J_60_C_proj;
  J_50_C_proj_inj            = J_50_C_proj;
  J_40_C_proj_inj            = J_40_C_proj;
  J_30_C_proj_inj            = J_30_C_proj;
  J_20_C_proj_inj            = J_20_C_proj;
  q_dot_inj                  = q_dot;
  dt_inj                     = dt;  
  nr_pt_07_gr_ai_inj	     = nr_pt_07_gr_ai; 
  nr_pt_07_gr_aj_inj	     = nr_pt_07_gr_aj; 
  nr_pt_06_gr_ai_inj	     = nr_pt_06_gr_ai;  
  nr_pt_06_gr_aj_inj	     = nr_pt_06_gr_aj;  
  nr_pt_05_gr_ai_inj	     = nr_pt_05_gr_ai;  
  nr_pt_05_gr_aj_inj	     = nr_pt_05_gr_aj;  
  nr_pt_04_gr_ai_inj	     = nr_pt_04_gr_ai;  
  nr_pt_04_gr_aj_inj	     = nr_pt_04_gr_aj;  
  nr_pt_03_gr_ai_inj	     = nr_pt_03_gr_ai;  
  nr_pt_03_gr_aj_inj	     = nr_pt_03_gr_aj;  
  nr_pt_02_gr_ai_inj	     = nr_pt_02_gr_ai;  
  nr_pt_02_gr_aj_inj	     = nr_pt_02_gr_aj;  
  nr_pt_07_ob1_ai_inj	     = nr_pt_07_ob1_ai;  
  nr_pt_07_ob1_aj_inj	     = nr_pt_07_ob1_aj;  
  nr_pt_06_ob1_ai_inj	     = nr_pt_06_ob1_ai;  
  nr_pt_06_ob1_aj_inj	     = nr_pt_06_ob1_aj;  
  nr_pt_05_ob1_ai_inj	     = nr_pt_05_ob1_ai;  
  nr_pt_05_ob1_aj_inj	     = nr_pt_05_ob1_aj;  
  nr_pt_04_ob1_ai_inj	     = nr_pt_04_ob1_ai;  
  nr_pt_04_ob1_aj_inj	     = nr_pt_04_ob1_aj;  
  nr_pt_03_ob1_ai_inj	     = nr_pt_03_ob1_ai;  
  nr_pt_03_ob1_aj_inj	     = nr_pt_03_ob1_aj;  
  nr_pt_02_ob1_ai_inj	     = nr_pt_02_ob1_ai;  
  nr_pt_02_ob1_aj_inj	     = nr_pt_02_ob1_aj;  
  nr_pt_07_ob2_ai_inj	     = nr_pt_07_ob2_ai;  
  nr_pt_07_ob2_aj_inj	     = nr_pt_07_ob2_aj;  
  nr_pt_06_ob2_ai_inj	     = nr_pt_06_ob2_ai;  
  nr_pt_06_ob2_aj_inj	     = nr_pt_06_ob2_aj;  
  nr_pt_05_ob2_ai_inj	     = nr_pt_05_ob2_ai;  
  nr_pt_05_ob2_aj_inj	     = nr_pt_05_ob2_aj;  
  nr_pt_04_ob2_ai_inj	     = nr_pt_04_ob2_ai;  
  nr_pt_04_ob2_aj_inj	     = nr_pt_04_ob2_aj;  
  nr_pt_03_ob2_ai_inj	     = nr_pt_03_ob2_ai;  
  nr_pt_03_ob2_aj_inj	     = nr_pt_03_ob2_aj;  
  nr_pt_02_ob2_ai_inj	     = nr_pt_02_ob2_ai;  
  nr_pt_02_ob2_aj_inj	     = nr_pt_02_ob2_aj;  
  nr_pt_07_sph_ai_inj	     = nr_pt_07_sph_ai;  
  nr_pt_07_sph_aj_inj	     = nr_pt_07_sph_aj;  
  nr_pt_06_sph_ai_inj	     = nr_pt_06_sph_ai;  
  nr_pt_06_sph_aj_inj	     = nr_pt_06_sph_aj;  
  nr_pt_05_sph_ai_inj	     = nr_pt_05_sph_ai;  
  nr_pt_05_sph_aj_inj	     = nr_pt_05_sph_aj;  
  nr_pt_04_sph_ai_inj	     = nr_pt_04_sph_ai;  
  nr_pt_04_sph_aj_inj	     = nr_pt_04_sph_aj;  
  nr_pt_03_sph_ai_inj	     = nr_pt_03_sph_ai;   
  nr_pt_03_sph_aj_inj	     = nr_pt_03_sph_aj;  
  nr_pt_02_sph_ai_inj	     = nr_pt_02_sph_ai;  
  nr_pt_02_sph_aj_inj	     = nr_pt_02_sph_aj; 
  M_cart_J7_inv_inj	     = M_cart_J7_inv;  
  M_cart_J6_inv_inj	     = M_cart_J6_inv;  
  M_cart_J5_inv_inj	     = M_cart_J5_inv;  
  M_cart_J4_inv_inj	     = M_cart_J4_inv;  
  M_cart_J3_inv_inj	     = M_cart_J3_inv;  
  M_cart_J2_inv_inj	     = M_cart_J2_inv; 
  m_eq_7_j_inj               = m_eq_7_j;
  m_eq_6_j_inj               = m_eq_6_j;
  m_eq_5_j_inj               = m_eq_5_j;
  m_eq_4_j_inj               = m_eq_4_j;
  m_eq_3_j_inj               = m_eq_3_j;
  m_eq_2_j_inj               = m_eq_2_j;
  V_7_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;			//Projected velocity signed norm in the k2 time step
  V_6_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;	
  V_5_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;	
  V_4_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;	
  V_3_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;	
  V_2_ob_sgn_norm_k2_inj     = V_7_ob_sgn_norm_k2;
  global_dist_07_nrst_ob        = dist_07_nrst_ob;             	//The distance to the nearest obstacle is the minimum of the distances above
  global_dist_06_nrst_ob        = dist_06_nrst_ob;
  global_dist_05_nrst_ob        = dist_05_nrst_ob;
  global_dist_04_nrst_ob        = dist_04_nrst_ob;
  global_dist_03_nrst_ob        = dist_03_nrst_ob;
  global_dist_02_nrst_ob        = dist_02_nrst_ob;
  global_d_safe                 = d_safe;
  Vect_dist_nrst_ob_07_inj   = Vect_dist_nrst_ob_07;            //Vector representing the distance to the nearest obstacle to segment 7
  Vect_dist_nrst_ob_06_inj   = Vect_dist_nrst_ob_07;   
  Vect_dist_nrst_ob_05_inj   = Vect_dist_nrst_ob_07;   
  Vect_dist_nrst_ob_04_inj   = Vect_dist_nrst_ob_07;   
  Vect_dist_nrst_ob_03_inj   = Vect_dist_nrst_ob_07;   
  Vect_dist_nrst_ob_02_inj   = Vect_dist_nrst_ob_07; 
  M_cart_7_inv_inj           = M_cart_7_inv;          		 //Inertie équivalente inversée pour les mouvements linéaires du segment 7 : 1/mij
  M_cart_6_inv_inj    	     = M_cart_6_inv;
  M_cart_5_inv_inj           = M_cart_5_inv;
  M_cart_4_inv_inj           = M_cart_4_inv;
  M_cart_3_inv_inj           = M_cart_3_inv;
  M_cart_2_inv_inj           = M_cart_2_inv;

  H_L_val0_cpnts_inj 	     = H_L_val0_cpnts;
  H_L_val1_cpnts_inj	     = H_L_val1_cpnts;
  H_L_val2_cpnts_inj 	     = H_L_val2_cpnts;
  H_L_val3_cpnts_inj 	     = H_L_val3_cpnts;
  H_L_val4_cpnts_inj 	     = H_L_val4_cpnts;
  H_L_val5_cpnts_inj 	     = H_L_val5_cpnts;
  H_L_val6_cpnts_inj 	     = H_L_val6_cpnts;
  H_L_val7_cpnts_inj 	     = H_L_val7_cpnts;
  H_L_val8_cpnts_inj 	     = H_L_val8_cpnts;
  H_L_val9_cpnts_inj 	     = H_L_val9_cpnts;
  H_L_val10_cpnts_inj 	     = H_L_val10_cpnts;
  H_L_val11_cpnts_inj 	     = H_L_val11_cpnts;
  H_L_val12_cpnts_inj 	     = H_L_val12_cpnts;
  H_L_val13_cpnts_inj 	     = H_L_val13_cpnts;
  H_L_val14_cpnts_inj 	     = H_L_val14_cpnts;
  H_L_val15_cpnts_inj 	     = H_L_val15_cpnts;
  H_L_val16_cpnts_inj 	     = H_L_val16_cpnts;
  H_L_val17_cpnts_inj 	     = H_L_val17_cpnts;
  H_L_val18_cpnts_inj 	     = H_L_val18_cpnts;
  H_L_val19_cpnts_inj 	     = H_L_val19_cpnts;
  H_L_val20_cpnts_inj 	     = H_L_val20_cpnts;
  H_L_val21_cpnts_inj 	     = H_L_val21_cpnts;
  H_L_val22_cpnts_inj 	     = H_L_val22_cpnts;
  H_L_val23_cpnts_inj 	     = H_L_val23_cpnts;
  H_L_val24_cpnts_inj 	     = H_L_val24_cpnts;
  H_L_val25_cpnts_inj 	     = H_L_val25_cpnts;
  H_L_val26_cpnts_inj 	     = H_L_val26_cpnts;
  H_L_val27_cpnts_inj 	     = H_L_val27_cpnts;

  global_kp = 80;
  global_kd = 17.88;
}





MyNLP::~MyNLP()
{}





bool MyNLP::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                         Index& nnz_h_lag, IndexStyleEnum& index_style)
{

  // The problem described in MyNLP.hpp has 7 variables, tau1...tau7,
  n = 7;

  // one equality constraint,
  m = 6;

  // nonzeros in the jacobian of g,
  nnz_jac_g = 42;

  // and 2 nonzeros in the hessian of the lagrangian
  // (one in the hessian of the objective for x2,
  //  and one in the hessian of the constraints for x1)
  nnz_h_lag = 28;

  // We use the standard fortran index style for row/col entries
  index_style = C_STYLE;
//std::cout << "!!!!!!!!!!!AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!!!!!"<<std::endl;
  return true;
}





bool MyNLP::get_bounds_info(Index n, Number* x_l, Number* x_u,
                            Index m, Number* g_l, Number* g_u)
{

  // here, the n and m we gave IPOPT in get_nlp_info are passed back to us.
  // If desired, we could assert to make sure they are what we think they are.
     assert(n == 7);        //If n is not == 7 --> Then die
     assert(m == 6);
  // Constraints on the torques
  // Constraints on the torques


  // Constraints on the torques
  x_u[0] =  3;
  x_u[1] =  3;
  x_u[2] =  3;
  x_u[3] =  3;
  x_u[4] =  3;
  x_u[5] =  3;
  x_u[6] =  3;
  
  x_l[0] = -3;
  x_l[1] = -3;
  x_l[2] = -3;
  x_l[3] = -3;
  x_l[4] = -3;
  x_l[5] = -3;
  x_l[6] = -3;

  // Contraints on the kinetic energy 
  g_u[0] =  E_max_7_inj;
  g_u[1] =  E_max_6_inj; 
  g_u[2] =  E_max_5_inj;
  g_u[3] =  E_max_4_inj; 
  g_u[4] =  E_max_3_inj;
  g_u[5] =  E_max_2_inj; 

  g_l[0] = -2e19; 
  g_l[1] = -2e19;
  g_l[2] = -2e19; 
  g_l[3] = -2e19;
  g_l[4] = -2e19; 
  g_l[5] = -2e19; 
 
  g_0_max = E_max_7_inj;
  g_1_max = E_max_6_inj;
  g_2_max = E_max_5_inj;
  g_3_max = E_max_4_inj;
  g_4_max = E_max_3_inj;
  g_5_max = E_max_2_inj;


/*
std::cout << "g_u[0] " << g_u[0]<<"    &   g_0 "<<  g_0 << std::endl;
std::cout << "g_u[1] " << g_u[1]<<"    &   g_1 "<<  g_1 << std::endl;
std::cout << "g_u[2] " << g_u[2]<<"    &   g_2 "<<  g_2 << std::endl;
std::cout << "g_u[3] " << g_u[3]<<"    &   g_3 "<<  g_3 << std::endl;
std::cout << "g_u[4] " << g_u[4]<<"    &   g_4 "<<  g_4 << std::endl;
std::cout << "g_u[5] " << g_u[5]<<"    &   g_5 "<<  g_5 << std::endl;
std::cout << "V_C_seg_7 " << J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)<< std::endl;
std::cout << "signe V_C_seg_7" << know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) << std::endl;
*/
//std::cout << "!!!!!!!!!!!BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB!!!!!!!!!!"<<std::endl;
  return true;
}





bool MyNLP::get_starting_point(Index n, bool init_x, Number* x,
                               bool init_z, Number* z_L, Number* z_U,
                               Index m, bool init_lambda,
                               Number* lambda)
{

  // Here, we assume we only have starting values for x, if you code
  // your own NLP, you can provide starting values for the others if
  // you wish.
  assert(init_x == true);
  assert(init_z == false);
  assert(init_lambda == false);

  // we initialize x in bounds, in the upper right quadrant
  x[0] = 0;
  x[1] = 0;
  x[2] = 0;
  x[3] = 0;
  x[4] = 0;
  x[5] = 0;
  x[6] = 0;
//std::cout << "!!!!!!!!!!!CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCc!!!!!!!!!!"<<std::endl;
  return true;
}





bool MyNLP::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
  Eigen::VectorXd tau(7);
  tau(0) = x[0];
  tau(1) = x[1];
  tau(2) = x[2];
  tau(3) = x[3];
  tau(4) = x[4];
  tau(5) = x[5];
  tau(6) = x[6];


obj_value  = pow(((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp* X_err_inj - global_kd * V_7_inj.block<3,1>(3,0))).norm(),2);
/*
std::cout << "!!!!!!!!!!!X_err_inj!!!!!!!!!!"<<std::endl;
std::cout << " "<< X_err_inj <<std::endl;
std::cout << "!!!!!!!!!!!X_err_inj!!!!!!!!!!"<<std::endl;
*/

//std::cout << "!!!!!!!!!!!DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDd!!!!!!!!!!"<<std::endl;
  return true;
}





bool MyNLP::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
  Eigen::VectorXd tau(7);
  tau(0) = x[0];
  tau(1) = x[1];
  tau(2) = x[2];
  tau(3) = x[3];
  tau(4) = x[4];
  tau(5) = x[5];
  tau(6) = x[6];

  // return the gradient of the objective function grad_{x} f(x)
grad_f[0] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau1_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));	//(J_70_l(3,7) * M_inv(7,7) * grad_vect_tau_tau1(7,1)).transpose() * (Xddot - Xddot_des)(3,1)
grad_f[1] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau2_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
grad_f[2] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau3_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
grad_f[3] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau4_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
grad_f[4] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau5_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
grad_f[5] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau6_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
grad_f[6] = 2 * ((J_70_l_inj * M_inv_inj * grad_vect_tau_tau7_inj).transpose()) * ((J_70_l_inj * M_inv_inj * (tau - b_inj) + Jdot_qdot_l_inj) - (global_kp * X_err_inj - global_kd * V_7_inj.block<3,1>(3,0)));
/*

std::cout << "!!!!!!!!!!!grad_f[0]!!!!!!!!!!"<<std::endl;
std::cout << " grad_f[0]"<< grad_f[0] <<std::endl;
std::cout << " grad_f[1]"<< grad_f[1] <<std::endl;
std::cout << " grad_f[2]"<< grad_f[2] <<std::endl;
std::cout << " grad_f[3]"<< grad_f[3] <<std::endl;
std::cout << " grad_f[4]"<< grad_f[4] <<std::endl;
std::cout << " grad_f[5]"<< grad_f[5] <<std::endl;
std::cout << " grad_f[6]"<< grad_f[6] <<std::endl;
std::cout << "!!!!!!!!!!!grad_f[0]!!!!!!!!!!"<<std::endl;
*/
//std::cout << "!!!!!!!!!!!FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF!!!!!!!!!!"<<std::endl;
return true;
}





bool MyNLP::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)   //x contient les couples--> Ce sont nos variables
{
  Eigen::VectorXd tau(7);
  tau(0) = x[0];
  tau(1) = x[1];
  tau(2) = x[2];
  tau(3) = x[3];
  tau(4) = x[4];
  tau(5) = x[5];
  tau(6) = x[6];

  

  g[0] = know_sign((J_70_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_7_j_inj * (J_70_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_70_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));		//V_7_ob_sgn_norm is the velocity signed norm 

  g[1] = know_sign((J_60_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_6_j_inj * (J_60_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_60_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));

  g[2] = know_sign((J_50_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_5_j_inj * (J_50_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_50_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));

  g[3] = know_sign((J_40_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_4_j_inj * (J_40_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_40_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));

  g[4] = know_sign((J_30_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_3_j_inj * (J_30_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_30_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));

  g[5] = know_sign((J_20_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))))) * 0.5 * m_eq_2_j_inj * (J_20_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj)))) * (J_20_C_proj_inj * (q_dot_inj + (dt_inj * M_inv_inj * (tau-b_inj))));

g_0 = g[0];
g_1 = g[1];
g_2 = g[2];
g_3 = g[3];
g_4 = g[4];
g_5 = g[5];

//save energy for plot
global_time = clock();
save_E_7(g_0);
save_E_7_max(g_0_max);

save_E_6(g_1);
save_E_6_max(g_1_max);

save_E_5(g_2);
save_E_5_max(g_2_max);

save_E_4(g_3);
save_E_4_max(g_3_max);

save_E_3(g_4);
save_E_3_max(g_4_max);

save_E_2(g_5);
save_E_2_max(g_5_max);

save_dist_07(global_dist_07_nrst_ob);
save_dist_06(global_dist_06_nrst_ob);
save_dist_05(global_dist_05_nrst_ob);
save_dist_04(global_dist_04_nrst_ob);
save_dist_03(global_dist_03_nrst_ob);
save_dist_02(global_dist_02_nrst_ob);
save_d_safe(global_d_safe);

save_global_time(global_time);
//std::cout << "!!!!!!!!!!!GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG!!!!!!!!!!"<<std::endl;
  return true;
}





bool MyNLP::eval_jac_g(Index n, const Number* x, bool new_x,
                       Index m, Index nele_jac, Index* iRow, Index *jCol,
                       Number* values)
{

  if (values == NULL) {
// this particular jacobian is dense
    iRow[0]  = 0;   				//for g[0]
    jCol[0]  = 0;
    iRow[1]  = 0;
    jCol[1]  = 1;
    iRow[2]  = 0;
    jCol[2]  = 2;
    iRow[3]  = 0;
    jCol[3]  = 3;
    iRow[4]  = 0;
    jCol[4]  = 4;
    iRow[5]  = 0;
    jCol[5]  = 5;
    iRow[6]  = 0;
    jCol[6]  = 6;

    iRow[7]  = 1;				//for g[1]
    jCol[7]  = 0;
    iRow[8]  = 1;
    jCol[8]  = 1;
    iRow[9]  = 1;
    jCol[9]  = 2;
    iRow[10] = 1;
    jCol[10] = 3;
    iRow[11] = 1;
    jCol[11] = 4;
    iRow[12] = 1;
    jCol[12] = 5;
    iRow[13] = 1;
    jCol[13] = 6;

    iRow[14]  = 2;
    jCol[14]  = 0;
    iRow[15]  = 2;
    jCol[15]  = 1;
    iRow[16]  = 2;
    jCol[16]  = 2;
    iRow[17]  = 2;
    jCol[17]  = 3;
    iRow[18]  = 2;
    jCol[18]  = 4;
    iRow[19]  = 2;
    jCol[19]  = 5;
    iRow[20]  = 2;
    jCol[20]  = 6;


    iRow[21]  = 3;
    jCol[21]  = 0;
    iRow[22]  = 3;
    jCol[22]  = 1;
    iRow[23]  = 3;
    jCol[23]  = 2;
    iRow[24]  = 3;
    jCol[24]  = 3;
    iRow[25]  = 3;
    jCol[25]  = 4;
    iRow[26]  = 3;
    jCol[26]  = 5;
    iRow[27]  = 3;
    jCol[27]  = 6;

    iRow[28]  = 4;
    jCol[28]  = 0;
    iRow[29]  = 4;
    jCol[29]  = 1;
    iRow[30]  = 4;
    jCol[30]  = 2;
    iRow[31]  = 4;
    jCol[31]  = 3;
    iRow[32]  = 4;
    jCol[32]  = 4;
    iRow[33]  = 4;
    jCol[33]  = 5;
    iRow[34]  = 4;
    jCol[34]  = 6;

    iRow[35]  = 5;					//for g[5]
    jCol[35]  = 0;
    iRow[36]  = 5;
    jCol[36]  = 1;
    iRow[37]  = 5;
    jCol[37]  = 2;
    iRow[38]  = 5;
    jCol[38]  = 3;
    iRow[39]  = 5;
    jCol[39]  = 4;
    iRow[40]  = 5;
    jCol[40]  = 5;
    iRow[41]  = 5;
    jCol[41]  = 6;

//std::cout << "!!!!!!!!!!HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!!!!!!!!!!"<<std::endl;
  }


  else {
  Eigen::VectorXd tau(7);
  tau(0) = x[0];
  tau(1) = x[1];
  tau(2) = x[2];
  tau(3) = x[3];
  tau(4) = x[4];
  tau(5) = x[5];
  tau(6) = x[6];


// return the values of the jacobian of the constraints
                             //""""""""""d g[0] / d tau1, d g[0] / d tau2 .....d g[0] / d tau7 """""""""""//
values[0] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
		  	  										       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[1] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
		  			  		   		  		   		       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[2] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
		   		   									       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[3] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
													       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[4] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
												               (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[5] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
				   									       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[6] =      know_sign(J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_7_j_inj) * (J_70_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   									       (J_70_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 
                             //""""""""""d g[0] / d tau1, d g[0] / d tau2 .....d g[0] / d tau7 """""""""""//



                             //""""""""""d g[1] / d tau1, d g[1] / d tau2 .....d [g1] / d tau7 """""""""""//
values[7] =        know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
		  		  										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[8] =        know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
				  										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[9] =        know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
				  										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[10] =       know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
				   										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[11] =       know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
				   										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[12] =       know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
		 		   										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[13] =       know_sign(J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_6_j_inj) * (J_60_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   										 (J_60_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 
                             //""""""""""d g[1] / d tau1, d g[1] / d tau2 .....d g[1] / d tau7 """""""""""//



                             //""""""""""d g[2] / d tau1, d g[2] / d tau2 .....d g[2] / d tau7 """""""""""//
values[14] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[15] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[16] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[17] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[18] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[19] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[20] =       know_sign(J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_5_j_inj) * (J_50_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   										 (J_50_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 
                             //""""""""""d g[2] / d tau1, d g[2] / d tau2 .....d g[2] / d tau7 """""""""""//



                             //""""""""""d g[3] / d tau1, d g[3] / d tau2 .....d g[3] / d tau7 """""""""""//
values[21] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[22] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[23] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[24] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[25] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[26] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[27] =       know_sign(J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_4_j_inj) * (J_40_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   										 (J_40_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));
                             //""""""""""d g[3] / d tau1, d g[3] / d tau2 .....d g[3] / d tau7 """""""""""//



                             //""""""""""d g[4] / d tau1, d g[4] / d tau2 .....d g[4] / d tau7 """""""""""//
values[28] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));

values[29] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[30] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[31] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[32] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[33] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 

values[34] =       know_sign(J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_3_j_inj) * (J_30_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   										 (J_30_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj))); 
                             //""""""""""d g[4] / d tau1, d g[4] / d tau2 .....d g[4] / d tau7 """""""""""//



                             //""""""""""d g[5] / d tau1, d g[5] / d tau2 .....d g[5] / d tau7 """""""""""//
values[35] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau1_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[36] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau2_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[37] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau3_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[38] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau4_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[39] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau5_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[40] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau6_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  

values[41] =       know_sign(J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * (m_eq_2_j_inj) * (J_20_C_proj_inj * (dt_inj * M_inv_inj * grad_vect_tau_tau7_inj)) * 
				   										 (J_20_C_proj_inj * (dt_inj * M_inv_inj * (tau-b_inj)));  
                             //""""""""""d g[5] / d tau1, d g[5] / d tau2 .....d g[5] / d tau7 """""""""""//
//std::cout << "!!!!!!!!!!!IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII!!!!!!!!!!"<<std::endl;
  }
//std::cout << "!!!!!!!!!!!JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ!!!!!!!!!!"<<std::endl;
  return true;
}







bool MyNLP::eval_h(Index n, const Number* x, bool new_x,
                   Number obj_factor, Index m, const Number* lambda,
                   bool new_lambda, Index nele_hess, Index* iRow,
                   Index* jCol, Number* values)
{


  if (values == NULL) {
    // return the structure. This is a symmetric matrix, fill the lower left
    // triangle only.
    // the hessian for this problem is actually dense. On écrit seulement la moitié gauche de la matrice 
    Index idx=0;
    for (Index row = 0; row < 7; row++) {
      for (Index col = 0; col <= row; col++) {
        iRow[idx] = row;
        jCol[idx] = col;
        idx++;
      }
    }
  }

  else {

    // return the values --> Les valeurs de la Hessienne ne dépendent pas de tau

values[0] =   obj_factor * H_L_val0_cpnts_inj[0]  + lambda[0]*H_L_val0_cpnts_inj[1] + lambda[1]*H_L_val0_cpnts_inj[2] + lambda[2]*H_L_val0_cpnts_inj[3] + 
                                                    lambda[3]*H_L_val0_cpnts_inj[4] + lambda[4]*H_L_val0_cpnts_inj[5] + lambda[5]*H_L_val0_cpnts_inj[6];

values[1] =   obj_factor * H_L_val1_cpnts_inj[0]  + lambda[0]*H_L_val1_cpnts_inj[1] + lambda[1]*H_L_val1_cpnts_inj[2] + lambda[2]*H_L_val1_cpnts_inj[3] + 
                                    		    lambda[3]*H_L_val1_cpnts_inj[4] + lambda[4]*H_L_val1_cpnts_inj[5] + lambda[5]*H_L_val1_cpnts_inj[6];

values[2] =   obj_factor * H_L_val2_cpnts_inj[0]  + lambda[0]*H_L_val2_cpnts_inj[1] + lambda[1]*H_L_val2_cpnts_inj[2] + lambda[2]*H_L_val2_cpnts_inj[3] + 
                                    		    lambda[3]*H_L_val2_cpnts_inj[4] + lambda[4]*H_L_val2_cpnts_inj[5] + lambda[5]*H_L_val2_cpnts_inj[6];

values[3] =   obj_factor * H_L_val3_cpnts_inj[0]  + lambda[0]*H_L_val3_cpnts_inj[1] + lambda[1]*H_L_val3_cpnts_inj[2] + lambda[2]*H_L_val3_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val3_cpnts_inj[4] + lambda[4]*H_L_val3_cpnts_inj[5] + lambda[5]*H_L_val3_cpnts_inj[6];

values[4] =   obj_factor * H_L_val4_cpnts_inj[0]  + lambda[0]*H_L_val4_cpnts_inj[1] + lambda[1]*H_L_val4_cpnts_inj[2] + lambda[2]*H_L_val4_cpnts_inj[3] + 
                                 	            lambda[3]*H_L_val4_cpnts_inj[4] + lambda[4]*H_L_val4_cpnts_inj[5] + lambda[5]*H_L_val4_cpnts_inj[6];

values[5] =   obj_factor * H_L_val5_cpnts_inj[0]  + lambda[0]*H_L_val5_cpnts_inj[1] + lambda[1]*H_L_val5_cpnts_inj[2] + lambda[2]*H_L_val5_cpnts_inj[3] + 
                                  	            lambda[3]*H_L_val5_cpnts_inj[4] + lambda[4]*H_L_val5_cpnts_inj[5] + lambda[5]*H_L_val5_cpnts_inj[6];


values[6] =   obj_factor * H_L_val6_cpnts_inj[0]  + lambda[0]*H_L_val6_cpnts_inj[1] + lambda[1]*H_L_val6_cpnts_inj[2] + lambda[2]*H_L_val6_cpnts_inj[3] + 
                                	            lambda[3]*H_L_val6_cpnts_inj[4] + lambda[4]*H_L_val6_cpnts_inj[5] + lambda[5]*H_L_val6_cpnts_inj[6];

values[7] =   obj_factor * H_L_val7_cpnts_inj[0]  + lambda[0]*H_L_val7_cpnts_inj[1] + lambda[1]*H_L_val7_cpnts_inj[2] + lambda[2]*H_L_val7_cpnts_inj[3] + 
                           	                    lambda[3]*H_L_val7_cpnts_inj[4] + lambda[4]*H_L_val7_cpnts_inj[5] + lambda[5]*H_L_val7_cpnts_inj[6];

values[8] =   obj_factor * H_L_val8_cpnts_inj[0]  + lambda[0]*H_L_val8_cpnts_inj[1] + lambda[1]*H_L_val8_cpnts_inj[2] + lambda[2]*H_L_val8_cpnts_inj[3] + 
                           	                    lambda[3]*H_L_val8_cpnts_inj[4] + lambda[4]*H_L_val8_cpnts_inj[5] + lambda[5]*H_L_val8_cpnts_inj[6];

values[9] =   obj_factor * H_L_val9_cpnts_inj[0]  + lambda[0]*H_L_val9_cpnts_inj[1] + lambda[1]*H_L_val9_cpnts_inj[2] + lambda[2]*H_L_val9_cpnts_inj[3] + 
                         		            lambda[3]*H_L_val9_cpnts_inj[4] + lambda[4]*H_L_val9_cpnts_inj[5] + lambda[5]*H_L_val9_cpnts_inj[6];

values[10] =  obj_factor * H_L_val10_cpnts_inj[0] + lambda[0]*H_L_val10_cpnts_inj[1] + lambda[1]*H_L_val10_cpnts_inj[2] + lambda[2]*H_L_val10_cpnts_inj[3] + 
                                      		    lambda[3]*H_L_val10_cpnts_inj[4] + lambda[4]*H_L_val10_cpnts_inj[5] + lambda[5]*H_L_val10_cpnts_inj[6];

values[11] =  obj_factor * H_L_val11_cpnts_inj[0] + lambda[0]*H_L_val11_cpnts_inj[1] + lambda[1]*H_L_val11_cpnts_inj[2] + lambda[2]*H_L_val11_cpnts_inj[3] + 
                                      		    lambda[3]*H_L_val11_cpnts_inj[4] + lambda[4]*H_L_val11_cpnts_inj[5] + lambda[5]*H_L_val11_cpnts_inj[6];

values[12] =  obj_factor * H_L_val12_cpnts_inj[0] + lambda[0]*H_L_val12_cpnts_inj[1] + lambda[1]*H_L_val12_cpnts_inj[2] + lambda[2]*H_L_val12_cpnts_inj[3] + 
                                     		    lambda[3]*H_L_val12_cpnts_inj[4] + lambda[4]*H_L_val12_cpnts_inj[5] + lambda[5]*H_L_val12_cpnts_inj[6];

values[13] =  obj_factor * H_L_val13_cpnts_inj[0] + lambda[0]*H_L_val13_cpnts_inj[1] + lambda[1]*H_L_val13_cpnts_inj[2] + lambda[2]*H_L_val13_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val13_cpnts_inj[4] + lambda[4]*H_L_val13_cpnts_inj[5] + lambda[5]*H_L_val13_cpnts_inj[6];

values[14] =  obj_factor * H_L_val14_cpnts_inj[0] + lambda[0]*H_L_val14_cpnts_inj[1] + lambda[1]*H_L_val14_cpnts_inj[2] + lambda[2]*H_L_val14_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val14_cpnts_inj[4] + lambda[4]*H_L_val14_cpnts_inj[5] + lambda[5]*H_L_val14_cpnts_inj[6];

values[15] =  obj_factor * H_L_val15_cpnts_inj[0] + lambda[0]*H_L_val15_cpnts_inj[1] + lambda[1]*H_L_val15_cpnts_inj[2] + lambda[2]*H_L_val15_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val15_cpnts_inj[4] + lambda[4]*H_L_val15_cpnts_inj[5] + lambda[5]*H_L_val15_cpnts_inj[6];

values[16] =  obj_factor * H_L_val16_cpnts_inj[0] + lambda[0]*H_L_val16_cpnts_inj[1] + lambda[1]*H_L_val16_cpnts_inj[2] + lambda[2]*H_L_val16_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val16_cpnts_inj[4] + lambda[4]*H_L_val16_cpnts_inj[5] + lambda[5]*H_L_val16_cpnts_inj[6];

values[17] =  obj_factor * H_L_val17_cpnts_inj[0] + lambda[0]*H_L_val17_cpnts_inj[1] + lambda[1]*H_L_val17_cpnts_inj[2] + lambda[2]*H_L_val17_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val17_cpnts_inj[4] + lambda[4]*H_L_val17_cpnts_inj[5] + lambda[5]*H_L_val17_cpnts_inj[6];

values[18] =  obj_factor * H_L_val18_cpnts_inj[0] + lambda[0]*H_L_val18_cpnts_inj[1] + lambda[1]*H_L_val18_cpnts_inj[2] + lambda[2]*H_L_val18_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val18_cpnts_inj[4] + lambda[4]*H_L_val18_cpnts_inj[5] + lambda[5]*H_L_val18_cpnts_inj[6];

values[19] =  obj_factor * H_L_val19_cpnts_inj[0] + lambda[0]*H_L_val19_cpnts_inj[1] + lambda[1]*H_L_val19_cpnts_inj[2] + lambda[2]*H_L_val19_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val19_cpnts_inj[4] + lambda[4]*H_L_val19_cpnts_inj[5] + lambda[5]*H_L_val19_cpnts_inj[6];

values[20] =  obj_factor * H_L_val20_cpnts_inj[0] + lambda[0]*H_L_val20_cpnts_inj[1] + lambda[1]*H_L_val20_cpnts_inj[2] + lambda[2]*H_L_val20_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val20_cpnts_inj[4] + lambda[4]*H_L_val20_cpnts_inj[5] + lambda[5]*H_L_val20_cpnts_inj[6];

values[21] =  obj_factor * H_L_val21_cpnts_inj[0] + lambda[0]*H_L_val21_cpnts_inj[1] + lambda[1]*H_L_val21_cpnts_inj[2] + lambda[2]*H_L_val21_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val21_cpnts_inj[4] + lambda[4]*H_L_val21_cpnts_inj[5] + lambda[5]*H_L_val21_cpnts_inj[6];

values[22] =  obj_factor * H_L_val22_cpnts_inj[0] + lambda[0]*H_L_val22_cpnts_inj[1] + lambda[1]*H_L_val22_cpnts_inj[2] + lambda[2]*H_L_val22_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val22_cpnts_inj[4] + lambda[4]*H_L_val22_cpnts_inj[5] + lambda[5]*H_L_val22_cpnts_inj[6];

values[23] =  obj_factor * H_L_val23_cpnts_inj[0] + lambda[0]*H_L_val23_cpnts_inj[1] + lambda[1]*H_L_val23_cpnts_inj[2] + lambda[2]*H_L_val23_cpnts_inj[3] + 
                                   		    lambda[3]*H_L_val23_cpnts_inj[4] + lambda[4]*H_L_val23_cpnts_inj[5] + lambda[5]*H_L_val23_cpnts_inj[6];

values[24] =  obj_factor * H_L_val24_cpnts_inj[0] + lambda[0]*H_L_val24_cpnts_inj[1] + lambda[1]*H_L_val24_cpnts_inj[2] + lambda[2]*H_L_val24_cpnts_inj[3] + 
                                  		    lambda[3]*H_L_val24_cpnts_inj[4] + lambda[4]*H_L_val24_cpnts_inj[5] + lambda[5]*H_L_val24_cpnts_inj[6];

values[25] =  obj_factor * H_L_val25_cpnts_inj[0] + lambda[0]*H_L_val25_cpnts_inj[1] + lambda[1]*H_L_val25_cpnts_inj[2] + lambda[2]*H_L_val25_cpnts_inj[3] + 
                                 		    lambda[3]*H_L_val25_cpnts_inj[4] + lambda[4]*H_L_val25_cpnts_inj[5] + lambda[5]*H_L_val25_cpnts_inj[6];

values[26] =  obj_factor * H_L_val26_cpnts_inj[0] + lambda[0]*H_L_val26_cpnts_inj[1] + lambda[1]*H_L_val26_cpnts_inj[2] + lambda[2]*H_L_val26_cpnts_inj[3] + 
                                 		    lambda[3]*H_L_val26_cpnts_inj[4] + lambda[4]*H_L_val26_cpnts_inj[5] + lambda[5]*H_L_val26_cpnts_inj[6];

values[27] =  obj_factor * H_L_val27_cpnts_inj[0] + lambda[0]*H_L_val27_cpnts_inj[1] + lambda[1]*H_L_val27_cpnts_inj[2] + lambda[2]*H_L_val27_cpnts_inj[3] + 
                                 		    lambda[3]*H_L_val27_cpnts_inj[4] + lambda[4]*H_L_val27_cpnts_inj[5] + lambda[5]*H_L_val27_cpnts_inj[6];


  }

  return true;
}





void MyNLP::finalize_solution(SolverReturn status,
                              Index n, const Number* x, const Number* z_L, const Number* z_U,
                              Index m, const Number* g, const Number* lambda,
                              Number obj_value,
			      const IpoptData* ip_data,
			      IpoptCalculatedQuantities* ip_cq)
{
  // here is where we would store the solution to variables, or write to a file, etc
  // so we could use the solution. Since the solution is displayed to the console,
  // we currently do nothing here.

g_nValue = 5; 
tau_final(0) = x[0];
tau_final(1) = x[1];
tau_final(2) = x[2];
tau_final(3) = x[3];
tau_final(4) = x[4];
tau_final(5) = x[5];
tau_final(6) = x[6];

/*
std::cout << "!!!!!!!!!!!RESULTAT FINAL!!!!!!!!!!"<<std::endl;
std::cout << "     x1    "<< x[0] <<std::endl;
std::cout << "     x2    "<< x[1] <<std::endl;
std::cout << "     x3    "<< x[2] <<std::endl;
std::cout << "     x4    "<< x[3] <<std::endl;
std::cout << "     x5    "<< x[4] <<std::endl;
std::cout << "     x6    "<< x[5] <<std::endl;
std::cout << "     x7    "<< x[6] <<std::endl;
std::cout << "!!!!!!!!!!!RESULTAT FINAL!!!!!!!!!!"<<std::endl;*/
}

