// Copyright (C) 2004, 2006 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// $Id: MyNLP.hpp 1861 2010-12-21 21:34:47Z andreasw $
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2004-11-05

#ifndef __MYNLP_HPP__
#define __MYNLP_HPP__

#include "/home/anis/libs/CoinIpopt/build/include/coin/IpTNLP.hpp"
#include <Eigen/Lgsm>
#include <iostream>
#include <time.h>

extern int g_nValue;
extern Eigen::VectorXd tau_final;
extern clock_t global_time;

using namespace Ipopt;



/** C++ Example NLP for interfacing a problem with IPOPT.
 *  MyNLP implements a C++ example showing how to interface with IPOPT
 *  through the TNLP interface. This example is designed to go along with
 *  the tutorial document (see Examples/CppTutorial/).
 *  This class implements the following NLP.
 *
 * min_x f(x) = -(x2-2)^2
 *  s.t.
 *       0 = x1^2 + x2 - 1
 *       -1 <= x1 <= 1
 *
 */
class MyNLP : public TNLP
{
public:
  /** default constructor */
  MyNLP(            Eigen::Matrix<double, 3, 7> J_70_l,         //Partie de J_70 responsable des mouvements linéaires de l'effecteur avec J_70(JAi_7 JLi_7).transpose     
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
		    double V_7_ob_sgn_norm_k2,			     //Projected velocity signed norm in the k2 time step
		    double V_6_ob_sgn_norm_k2,	
		    double V_5_ob_sgn_norm_k2,	
		    double V_4_ob_sgn_norm_k2,	
		    double V_3_ob_sgn_norm_k2,	
		    double V_2_ob_sgn_norm_k2,
                    double dist_07_nrst_ob,    		             //The distance to the nearest obstacle is the minimum of the distances above
                    double dist_06_nrst_ob,
                    double dist_05_nrst_ob,
                    double dist_04_nrst_ob,
                    double dist_03_nrst_ob,
                    double dist_02_nrst_ob,
		    double d_safe,
		    Eigen::Vector3d Vect_dist_nrst_ob_07,            //Vector representing the distance to the nearest obstacle to segment 7
		    Eigen::Vector3d Vect_dist_nrst_ob_06,   
	            Eigen::Vector3d Vect_dist_nrst_ob_05,   
		    Eigen::Vector3d Vect_dist_nrst_ob_04,   
	            Eigen::Vector3d Vect_dist_nrst_ob_03,   
		    Eigen::Vector3d Vect_dist_nrst_ob_02, 
              	    Eigen::Matrix<double, 3, 3> M_cart_7_inv,        //Inertie équivalente inversée pour les mouvements linéaires du segment 7 : 1/mij
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
		    Number* H_L_val27_cpnts);

  /** default destructor */
  virtual ~MyNLP();

  /**@name Overloaded from TNLP */
  //@{
  /** Method to return some info about the nlp */
  virtual bool get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                            Index& nnz_h_lag, IndexStyleEnum& index_style);

  /** Method to return the bounds for my problem */
  virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
                               Index m, Number* g_l, Number* g_u);

  /** Method to return the starting point for the algorithm */
  virtual bool get_starting_point(Index n, bool init_x, Number* x,
                                  bool init_z, Number* z_L, Number* z_U,
                                  Index m, bool init_lambda,
                                  Number* lambda);
  /** Method to return the objective value */
  virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

  /** Method to return the gradient of the objective */
  virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

  /** Method to return the constraint residuals */
  virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

  /** Method to return:
   *   1) The structure of the jacobian (if "values" is NULL)
   *   2) The values of the jacobian (if "values" is not NULL)
   */
  virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
                          Index m, Index nele_jac, Index* iRow, Index *jCol,
                          Number* values);

  /** Method to return:
   *   1) The structure of the hessian of the lagrangian (if "values" is NULL)
   *   2) The values of the hessian of the lagrangian (if "values" is not NULL)
   */
  virtual bool eval_h(Index n, const Number* x, bool new_x,
                      Number obj_factor, Index m, const Number* lambda,
                      bool new_lambda, Index nele_hess, Index* iRow,
                      Index* jCol, Number* values);

  //@}

  /** @name Solution Methods */
  //@{
  /** This method is called when the algorithm is complete so the TNLP can store/write the solution */
  virtual void finalize_solution(SolverReturn status,
                                 Index n, const Number* x, const Number* z_L, const Number* z_U,
                                 Index m, const Number* g, const Number* lambda,
                                 Number obj_value,
				 const IpoptData* ip_data,
				 IpoptCalculatedQuantities* ip_cq);
  //@}

  Eigen::Matrix<double, 3, 7> J_70_l_inj;      //Partie de J_70 responsable des mouvements linéaires de l'effecteur avec J_70(JAi_7 JLi_7).transpose   //inj == injected 
  Eigen::Matrix<double, 3, 7> J_60_l_inj;
  Eigen::Matrix<double, 3, 7> J_50_l_inj;
  Eigen::Matrix<double, 3, 7> J_40_l_inj;
  Eigen::Matrix<double, 3, 7> J_30_l_inj;
  Eigen::Matrix<double, 3, 7> J_20_l_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_inv_inj; 
  Eigen::Matrix<double, 7, 1> b_inj;
  Eigen::Matrix<double, 3, 1> Jdot_qdot_l_inj;
  Eigen::Vector3d X_err_inj;
  Eigen::Twistd V_7_inj;
  double Kp_inj;

  double  E_max_7_inj; 
  double  E_max_6_inj; 
  double  E_max_5_inj; 
  double  E_max_4_inj;
  double  E_max_3_inj; 
  double  E_max_2_inj; 

  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau1_inj;             
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau2_inj; 
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau3_inj;  
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau4_inj;  
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau5_inj;  
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau6_inj;  
  Eigen::Matrix<double, 7, 1> grad_vect_tau_tau7_inj; 
  char* id_nrst_ob_7_inj;
  char* id_nrst_ob_6_inj;
  char* id_nrst_ob_5_inj;
  char* id_nrst_ob_4_inj;
  char* id_nrst_ob_3_inj;
  char* id_nrst_ob_2_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_70_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_60_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_50_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_40_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_30_inj;
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_20_inj;
  Eigen::Matrix<double, 1, 7> J_70_C_proj_inj;
  Eigen::Matrix<double, 1, 7> J_60_C_proj_inj;
  Eigen::Matrix<double, 1, 7> J_50_C_proj_inj;
  Eigen::Matrix<double, 1, 7> J_40_C_proj_inj;
  Eigen::Matrix<double, 1, 7> J_30_C_proj_inj;
  Eigen::Matrix<double, 1, 7> J_20_C_proj_inj;
  Eigen::VectorXd q_dot_inj;
  double dt_inj;
  Number* grad_f_x_inj;
  Number* g_x_inj;
  Number* jac_g_values_inj;
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_ai_inj; 
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_aj_inj; 
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_aj_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_ai_inj;  
  std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_aj_inj;
 
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J7_inv_inj;  
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J6_inv_inj;  
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J5_inv_inj;  
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J4_inv_inj;  
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J3_inv_inj;  
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J2_inv_inj;	
  double m_eq_7_j_inj;	
  double m_eq_6_j_inj;	
  double m_eq_5_j_inj;	
  double m_eq_4_j_inj;	
  double m_eq_3_j_inj;	
  double m_eq_2_j_inj;	
  double V_7_ob_sgn_norm_k2_inj;			//Projected velocity signed norm in the k2 time step
  double V_6_ob_sgn_norm_k2_inj;	
  double V_5_ob_sgn_norm_k2_inj;	
  double V_4_ob_sgn_norm_k2_inj;	
  double V_3_ob_sgn_norm_k2_inj;	
  double V_2_ob_sgn_norm_k2_inj;
  double global_dist_07_nrst_ob;     //The distance to the nearest obstacle is the minimum of the distances above
  double global_dist_06_nrst_ob;
  double global_dist_05_nrst_ob;
  double global_dist_04_nrst_ob;
  double global_dist_03_nrst_ob;
  double global_dist_02_nrst_ob;
  double global_d_safe;
  double global_kp;
  double global_kd;
  Eigen::Vector3d Vect_dist_nrst_ob_07_inj;   //Vector representing the distance to the nearest obstacle to segment 7
  Eigen::Vector3d Vect_dist_nrst_ob_06_inj;   
  Eigen::Vector3d Vect_dist_nrst_ob_05_inj;   
  Eigen::Vector3d Vect_dist_nrst_ob_04_inj;   
  Eigen::Vector3d Vect_dist_nrst_ob_03_inj;   
  Eigen::Vector3d Vect_dist_nrst_ob_02_inj;     
  Eigen::Matrix<double, 3, 3> M_cart_7_inv_inj;        //Inertie équivalente inversée pour les mouvements linéaires du segment 7 : 1/mij
  Eigen::Matrix<double, 3, 3> M_cart_6_inv_inj;
  Eigen::Matrix<double, 3, 3> M_cart_5_inv_inj;
  Eigen::Matrix<double, 3, 3> M_cart_4_inv_inj;
  Eigen::Matrix<double, 3, 3> M_cart_3_inv_inj;
  Eigen::Matrix<double, 3, 3> M_cart_2_inv_inj;

  Number* H_L_val0_cpnts_inj;
  Number* H_L_val1_cpnts_inj;
  Number* H_L_val2_cpnts_inj;
  Number* H_L_val3_cpnts_inj;
  Number* H_L_val4_cpnts_inj;
  Number* H_L_val5_cpnts_inj;
  Number* H_L_val6_cpnts_inj;
  Number* H_L_val7_cpnts_inj;
  Number* H_L_val8_cpnts_inj;
  Number* H_L_val9_cpnts_inj;
  Number* H_L_val10_cpnts_inj;
  Number* H_L_val11_cpnts_inj;
  Number* H_L_val12_cpnts_inj;
  Number* H_L_val13_cpnts_inj;
  Number* H_L_val14_cpnts_inj;
  Number* H_L_val15_cpnts_inj;
  Number* H_L_val16_cpnts_inj;
  Number* H_L_val17_cpnts_inj;
  Number* H_L_val18_cpnts_inj;
  Number* H_L_val19_cpnts_inj;
  Number* H_L_val20_cpnts_inj;
  Number* H_L_val21_cpnts_inj;
  Number* H_L_val22_cpnts_inj;
  Number* H_L_val23_cpnts_inj;
  Number* H_L_val24_cpnts_inj;
  Number* H_L_val25_cpnts_inj;
  Number* H_L_val26_cpnts_inj;
  Number* H_L_val27_cpnts_inj;


private:
  /**@name Methods to block default compiler methods.
   * The compiler automatically generates the following three methods.
   *  Since the default compiler implementation is generally not what
   *  you want (for all but the most simple classes), we usually 
   *  put the declarations of these methods in the private section
   *  and never implement them. This prevents the compiler from
   *  implementing an incorrect "default" behavior without us
   *  knowing. (See Scott Meyers book, "Effective C++")
   *  
   */
  //@{
  //  MyNLP();
  MyNLP(const MyNLP&);
  MyNLP& operator=(const MyNLP&);
  //@}
};


#endif
