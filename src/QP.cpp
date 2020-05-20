#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 
#include <iostream>
#include <cassert>
#include <math.h>       
#include "Compute_energy.h"
#include "Compute_prj_velocity.h"
#include "save_data_in_txt.h"
#include "/home/anis/libs/gurobi563/linux64/include/gurobi_c++.h"
#include "QP.h"
#include "Jacobian_operations.h"
//#include "Absolute.h"


#include "globals.hh"
#include  <complex>
#include "G4AnalyticalPolSolver.hh"
#include "G4_P4_ApproxEqual.h"
#include "G4_P4_Solver.h"
#include "G4_P3_Solver.h"
#include "choose_int_root_n.h" //Donne le n_minimizing et le nn_maximising pour chaque liaison
#include "choose_int_root_n_P3.h" 
#include "compute_n.h"
#include "Maximum.h"
#include "Minimum.h"
#include "choose_q_ddot_final_bounds.h"
#include "round_up.h"
#include "Absolute.h"
#include "comp_constr_generator.h"

typedef Eigen::Matrix<double, 3, 7> Matrix3x7;

using std::cout;
using std::endl;
using namespace std;
extern Eigen::VectorXd q_dot_dot_final;
Eigen::VectorXd q_dot_dot_des(7);
Eigen::Matrix<double, 6, 1> t_tau;  //Matrice c de la partie linéaire de la fonction objectif
int step_count_qp = 0;

int one_time_decl = 1;
extern Eigen::Matrix<double, 3, 1> X_dot_dot; 
Eigen::Matrix<double, 3, 1> X_dot_dot_des_new;      //Accélération désirée après la mise à jour du générateur de trajectoire
Eigen::Matrix<double, 3, 1> X_dot_dot_des;
Eigen::Matrix<double, 6, 1> X_dot_dot_des_rot_posi;
Eigen::Matrix<double, 3, 1> X_dot_dot_des_rot_posi_lin_Ep; //Xdotdot different pour le calcul de l'Ep
Eigen::Matrix<double, 6, 1> Acc_7_des_rot_posi;
Eigen::Matrix<double, 6, 1> V_err_rot_posi;
Eigen::Matrix<double, 6, 1> X_err_rot_posi;
Eigen::Matrix<double, 3, 1> K_d_V_7_err; 
Eigen::Matrix<double, 3, 1> K_p_X_err; 
Eigen::VectorXd Diff_X_dot_dot_Acc_7_des;
Eigen::VectorXd Diff_X_dot_dot_des_Jdot_qdot_rot;
double kp_rot;         
double kd_rot; 
double E_7_reconstructed_with_V_7_t2 = 0;
double d_thres = 0.35;
double dist_to_cnstr;
int initialize_ = 1;
Eigen::Matrix<double, 6, 7> J_7_mixed_dot;
Eigen::Matrix<double, 6, 7> J_7_mixed_previous;


double Ep_7_rebuilt_Xerr;
double Ep_7_rebuilt_x;
double Ep_7_rebuilt_y;
double Ep_7_rebuilt_z;
double Ep_max_Xerr;      //Energy potentielle maximale autorisée à être stockée dans la direction de l'axe X_err
double Ep_max_x;    //Energy potentielle maximale autorisée à être stockée dans la direction de l'axe x
double Ep_max_y;
double Ep_max_z;

int trig = 0; 
int notfirsttime = 1;
double E_7_reconstructed_with_V_7_t2_prev    = 0;  //Va servir à calculer la dérivée de l'énergie cinétique   
double E_7_reconstructed_with_V_7_t2_derived = 0;

double E_p_7_apprx_prev  = 0;
double E_p_7_apprx_sum   = 0;   //Contient la somme de toute les énergies potentielles accumulées à chaque pas de temps
double E_p_7_apprx_deriv = 0; //Dérivée de l'énergie potentielle pour voir dans quelle 
double Acc_7_x_nxt_step = 0;
Eigen::Matrix<double, 7, 7> M_square;
extern Eigen::Vector3d X_err_real;
double Ec_7_rebuilt_QP; //Rebuilt kinetic energy
double Ec_7_rebuilt_lin; //Rebuilt kinetic energy


Eigen::Matrix<double, 1, 7> J_70_l_proj_x_axis_by_M_inv;
Eigen::Matrix<double, 1, 7> J_70_l_proj_y_axis_by_M_inv;
Eigen::Matrix<double, 1, 7> J_70_l_proj_z_axis_by_M_inv;   
Eigen::Matrix<double, 1, 7> L_C_a_7_x;
Eigen::Matrix<double, 1, 7> L_C_a_7_y;
Eigen::Matrix<double, 1, 7> L_C_a_7_z;
Eigen::Matrix<double, 1, 7> J_70_C_proj_by_M_inv;


double Cte_7_part_1; 
double Cte_7_part_1_x;   
double Cte_7_part_1_y;   
double Cte_7_part_1_z;     
double Cte_7_part_2;  
double Cte_7_part_2_x;  
double Cte_7_part_2_y;  
double Cte_7_part_2_z;   
double Cte_7;
double Cte_7_x;
double Cte_7_y;
double Cte_7_z;


double B_Xerr;
double B_x;
double B_y;
double B_z;
Eigen::Matrix<double, 1, 7> U_Xerr;
Eigen::Matrix<double, 1, 7> U_x;
Eigen::Matrix<double, 1, 7> U_y;
Eigen::Matrix<double, 1, 7> U_z;
double B1_Xerr;
double B1_x;
double B1_y;
double B1_z;
double B2_Xerr;
double B2_x;
double B2_y;
double B2_z;

double Real_Ep_7_x         = 0;
double Sum_Real_Ep_7_x     = 0;
double Ep_7_x_nxt_step     = 0;
double Sum_Ep_7_x_nxt_step = 0;

GRBLinExpr constr_7_Lin_Ep_x    = 0;
GRBLinExpr constr_7_Lin_Ep_y    = 0; 
GRBLinExpr constr_7_Lin_Ep_z    = 0;
GRBLinExpr constr_7_Lin_Ep_Xerr = 0;

GRBLinExpr constr_7_Lin_Ec_x = 0;
GRBLinExpr constr_7_Lin_Ec_y = 0;
GRBLinExpr constr_7_Lin_Ec_z = 0;
GRBLinExpr constr_7_Lin_Ec_C_ob = 0;
GRBLinExpr constr_7_Lin_Ec_Xerr = 0;

int Activ_Ec_QP_Cnstr         = 0;
int Activ_Ec_Lin_Cnstr        = 0;
int Activ_Ec_Lin_3axis_Cnstr  = 0;
int Activ_Ep_Xerr_Cnstr       = 0;
int Activ_Ep_x_Cnstr          = 0;
int Activ_Ep_y_Cnstr          = 0;
int Activ_Ep_z_Cnstr          = 0;

double V_7_x_nxt_step         = 0;
double Ec_7_x_nxt_step        = 0;
double V_7_C_ob_nxt_step      = 0;
double Ec_7_C_ob_nxt_step     = 0;
double Real_Ec_7_x            = 0;
double Real_Ec_7_x_prev       = 0;
double Real_Ec_7_x_derived    = 0;

double Ec_max_7_x = 5;
double Ec_max_7_y = 5;
double Ec_max_7_z = 5;
double F_max_x    = 50;
double F_max_y    = 50;
double F_max_z    = 50;

int sgn_7   = 1;
int sgn_7_x = 1;
int sgn_7_y = 1;
int sgn_7_z = 1;

extern Eigen::VectorXd Force_sensor_3dVector;
extern double Time_since_first_impact;

double dt_qp = 0.001;
double dt_lp = 0.001;
int    u     = 0; //Utilisé pour une boucle for
int constr_jerk = 0;


double Force_sensor_z_derived = 0;
double Force_sensor_z_previous = 0;
double m_eq_7_j_z_axis_previous = 0;
double force_z_nxt_step = 0;
double previous_robot_force_z_nxt_step = 0;
double before_previous_robot_force_z_nxt_step = 0;
double previous_robot_force_z_nxt_step_derived = 0;

G4int i_1, k_, n_1, iRoot, iMax = 10000;
G4int iCheck = iMax/10;
Eigen::Matrix<double, 10, 7> p_; //Il y a 14 polynômes en tout. Un pour chaque liaison. Chaque liaison a deux polnômes. 1 pour  val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)
		    //										          1 pour  val_max_de_q_ddot, (q_ddot(t) > val_max_de_q_ddot)
G4double a_1, b_1, c_1, d_1, tmp, range = 10*mm;
Eigen::Matrix<int, 8, 7> rounded_Quartic_roots; //Il ya deux sets de racines pour chaque liaison. 1 set contenant les racines de la dérivée de "val_min_de_q_ddot"
Eigen::Matrix<int, 4, 7> rounded_Quartic_roots_neg_jerk;						   //                                                1 set contenant les racines de la dérivée de "val_max_de_q_ddot" 
Eigen::Matrix<int, 4, 7> rounded_Quartic_roots_pos_jerk;


Eigen::VectorXi n_neg_acc_posi(7); //7 valeurs, 1 pour chaque liaison (Pour comp acc_posi)
Eigen::VectorXi n_pos_acc_posi(7); //7 valeurs, 1 pour chaque liaison (Pour comp acc_posi)
Eigen::VectorXi n_neg_jerk_vel(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_vel)
Eigen::VectorXi n_pos_jerk_vel(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_bel)
Eigen::VectorXi n_neg_jerk_posi(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_pos)
Eigen::VectorXi n_pos_jerk_posi(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_neg)


extern Eigen::VectorXd q_ddot;                               //Accélération articulaire instantannée
extern Eigen::VectorXd q_dddot_bounds_min;                   //Minimum et maximum Jerk
extern Eigen::VectorXd q_dddot_bounds_max;
extern Eigen::VectorXd q_bounds_min;                         //Minimum et maximum posi
extern Eigen::VectorXd q_bounds_max;


Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Posi(7); //Celas sont calculés avec la compatibilité entre le Jerk et la position
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Posi(7);


Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Posi_prev(7);
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Posi_prev(7);

Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Posi_acc(7); //Celas sont calculés avec la compatibilité entre le Jerk, acc et la position
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Posi_acc(7);


Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Vel(7); //Celas sont calculés avec la compatibilité entre le Jerk et la vitesse
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Vel(7);

Eigen::VectorXd  q_dotdot_bounds_max_comp_Acc_Posi(7); //Celas sont calculés avec la compatibilité entre l'accélération et la position
Eigen::VectorXd  q_dotdot_bounds_min_comp_Acc_Posi(7);

Eigen::VectorXd  q_dot_bounds_max_comp_Acc_Posi_vel_cmd(7);
Eigen::VectorXd  q_dot_bounds_min_comp_Acc_Posi_vel_cmd(7);

Eigen::VectorXd  q_n_neg_jerk_posi_reconstr(7);
Eigen::VectorXd  q_n_pos_jerk_posi_reconstr(7);

Eigen::VectorXd  q_n_neg_jerk_posi_reconstr_explored(7);
Eigen::VectorXd  q_n_pos_jerk_posi_reconstr_explored(7);

Eigen::VectorXd  q_n_neg_jerk_acc_posi_reconstr(7);
Eigen::VectorXd  q_n_pos_jerk_acc_posi_reconstr(7);

Eigen::VectorXd  q_dotdot_bounds_finals(2);
//q_dotdot_bounds_max_comp is a 7x1 double matrix

Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_comp_full;
Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_comp_full;
Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_comp_Jerk_Acc_Posi; //Celas sont calculés avec la compatibilité entre le Jerk, l'Acc et la position
Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_comp_Jerk_Acc_Posi;
/*
Eigen::VectorXi n1_neg_jerk_acc_posi(7);
Eigen::VectorXi n1_pos_jerk_acc_posi(7); 
Eigen::VectorXi n_neg_jerk_acc_posi(7);
Eigen::VectorXi n_pos_jerk_acc_posi(7);
*/


//n=(n1+n2) n1=(q_ddot_M - q_ddot)/((q_dddot_M*dt)).  n2 = -q_dot/(q_ddot_M*dt) 
Eigen::VectorXi n1_neg_jerk_acc_posi(7);
Eigen::VectorXi n1_pos_jerk_acc_posi(7); 
Eigen::VectorXi n2_neg_jerk_acc_posi(7);
Eigen::VectorXi n2_pos_jerk_acc_posi(7);
Eigen::VectorXi n_neg_jerk_acc_posi(7);
Eigen::VectorXi n_pos_jerk_acc_posi(7); 

Eigen::VectorXd sum_consec_q_ddot_neg_jerk_acc_posi(7);//The sum of the consecutive accélérations desired for the system during the breaking phase
Eigen::VectorXd sum_consec_q_ddot_pos_jerk_acc_posi(7);//The sum of the consecutive accélérations desired for the system during the breaking phase
double next_q_ddot_neg_jerk_acc_posi = 0; //next q_ddot désiré dans la sum_consec_q_ddot_neg_jerk_acc_posi
double next_q_ddot_pos_jerk_acc_posi = 0; //next q_ddot désiré dans la sum_consec_q_ddot_pos_jerk_acc_posi

Eigen::VectorXd q_dot_k_n1_neg(7);
Eigen::VectorXd q_dot_k_n1_pos(7);

Eigen::VectorXd q_k_n_jerk_const_max(7);
Eigen::VectorXd q_k_n_jerk_const_min(7);

Eigen::VectorXd q_ddot_k_n_jerk_const_max(7);
Eigen::VectorXd q_ddot_k_n_jerk_const_min(7);

Eigen::VectorXd n_pos_jerk_posi_cmpted_dffrntly(7);
Eigen::VectorXd n_neg_jerk_posi_cmpted_dffrntly(7);



Eigen::Matrix<double, 10, 7> p_3; //Il y a 14 polynômes en tout. Un pour chaque liaison. Chaque liaison a deux polnômes. 1 pour  val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)
Eigen::Matrix<int, 6, 7> rounded_Cubic_roots; //Il ya deux sets de racines pour chaque liaison.
Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_neg_jerk;						   //                                                1 set contenant les racines de la dérivée de "val_max_de_q_ddot" 
Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_pos_jerk;

Eigen::VectorXi n_neg_jerk_posi_P3(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_pos), Cela sont calculés différemment que les n_neg_jerk_posi
Eigen::VectorXi n_pos_jerk_posi_P3(7); //7 valeurs, 1 pour chaque liaison (Pour comp Jerk_neg), Cela sont calculés différemment que les n_pos_jerk_posi


double n_pos_jerk_acc_posi_double;
double n_neg_jerk_acc_posi_double;
int i_pos;
int i_neg;
Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_comp_Jerk_Acc_Posi_to_be_compared;
Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_comp_Jerk_Acc_Posi_to_be_compared;
int first_q_dotdot_bounds_min_comp_Jerk_Acc_Posi = 1;
int first_q_dotdot_bounds_max_comp_Jerk_Acc_Posi = 1; //Esque c'est le premier généré ? Oui !


Eigen::VectorXd init_q_dot(7);
Eigen::VectorXd init_q_ddot(7);
Eigen::VectorXd init_q_dddot(7);
Eigen::VectorXd init_q_ddddot(7);
Eigen::VectorXd target_q_dot(7);
Eigen::VectorXd target_q_ddot(7);
Eigen::VectorXd target_q_dddot(7);
Eigen::VectorXd target_q_ddddot(7);
Eigen::VectorXd zero_q_dot(7);
Eigen::VectorXd zero_q_ddot(7);
Eigen::VectorXd zero_q_dddot(7);
Eigen::VectorXd zero_q_ddddot(7);

Eigen::Matrix<double, 7, 8> a_i_qddot_cnstr_frm_brking_posi_cnstr;
Eigen::VectorXd a_i_qddot_cnstr_frm_brking_posi_cnstr_i(8); //Une ligne de "a_i_qddot_cnstr_frm_brking_posi_cnstr"
Eigen::VectorXd T_for_braking_posi_constr(7);
Eigen::VectorXi breaking_phase_posi(7);
Eigen::VectorXd t_1_for_braking_posi_constr(7);
Eigen::VectorXd T_for_hitting_posi_constr(7);
Eigen::VectorXd t_2_for_braking_posi_constr(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr(4);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr(7);
Eigen::VectorXd t_2_for_braking_posi_constr_k2(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_k2(4);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_k2(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_k2(7);
Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_k2(7);

Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_from_vel_constr(7);

Eigen::VectorXd  q_dotdot_bounds_deriv_max_comp(7);
Eigen::VectorXd  q_dotdot_bounds_deriv_min_comp(7);
Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Posi_previous(7);
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Posi_previous(7);

Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Vel_previous(7);
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Vel_previous(7);

Eigen::VectorXd  q_dotdot_bounds_max_comp_Jerk_Posi_acc_previous(7);
Eigen::VectorXd  q_dotdot_bounds_min_comp_Jerk_Posi_acc_previous(7);

int    n1_neg=3;
int    n1_pos=3;
int    n2_neg=2;
int    n2_pos=2;
int    y=0;
int    p=0;
int    f=0;

double end_count_time;
double start_count_time;
Eigen::VectorXd final_q_dotdot_bounds_max_comp_Jerk_Posi_acc(7);
Eigen::VectorXd final_q_dotdot_bounds_min_comp_Jerk_Posi_acc(7);
Eigen::VectorXd q_dotdot_bounds_max_provizoir(7);
Eigen::VectorXd q_dotdot_bounds_min_provizoir(7);



int n_neg_jerk_posi_exp; 
int n_pos_jerk_posi_exp; 

Eigen::VectorXd final_q_dotdot_bounds_max_comp_Jerk_Posi(7);
Eigen::VectorXd final_q_dotdot_bounds_min_comp_Jerk_Posi(7);
Eigen::VectorXd q_dotdot_bounds_max_comp_Jerk_Posi_provizoir(7);
Eigen::VectorXd q_dotdot_bounds_min_comp_Jerk_Posi_provizoir(7);
Eigen::VectorXi n_neg_jerk_posi_explored(7);
Eigen::VectorXi n_pos_jerk_posi_explored(7);
Eigen::VectorXd q_dddot_gurobi(7); 
Eigen::VectorXd q_dot_dot_final_previous(7);
Eigen::VectorXd q_dot_n_neg_jerk_reconstr(7);                 
Eigen::VectorXd q_dot_n_pos_jerk_reconstr(7);
Eigen::VectorXd q_dotdot_bounds_comp_vel_jerk_deriv_max(7);
Eigen::VectorXd q_dotdot_bounds_comp_vel_jerk_deriv_min(7);
Eigen::VectorXd q_n_neg_acc_reconstr(7);
Eigen::VectorXd q_n_pos_acc_reconstr(7);
Eigen::VectorXd q_dotdot_bounds_comp_posi_jerk_deriv_max(7);
Eigen::VectorXd q_dotdot_bounds_comp_posi_jerk_deriv_min(7);
Eigen::VectorXd q_dotdot_bounds_comp_posi_jerk_acc_deriv_max(7);
Eigen::VectorXd q_dotdot_bounds_comp_posi_jerk_acc_deriv_min(7);
double n_5_neg_jerk_posi_exp;
double n_5_pos_jerk_posi_exp;
double n_6_neg_jerk_posi_exp;
double n_6_pos_jerk_posi_exp;
Eigen::VectorXd n_5_neg_jerk_posi_explored(7);
Eigen::VectorXd n_5_pos_jerk_posi_explored(7);
Eigen::VectorXd n_6_neg_jerk_posi_explored(7);
Eigen::VectorXd n_6_pos_jerk_posi_explored(7);

double epsilon_q_dot_dot = 1e-6; 
double epsilon_tau = 1e-6;
double epsilon_q_des = 1e-3;
int steps_counter = 0;
double kp_q;
double kd_q;

double n1_neg_jerk_posi_exp = 3;
double n1_pos_jerk_posi_exp = 3;
double n2_neg_jerk_posi_exp = 3;
double n2_pos_jerk_posi_exp = 3;
Eigen::VectorXd n1_neg_jerk_posi_explored(7);
Eigen::VectorXd n1_pos_jerk_posi_explored(7);
Eigen::VectorXd n2_neg_jerk_posi_explored(7);
Eigen::VectorXd n2_pos_jerk_posi_explored(7);
Eigen::VectorXd n1_neg_jerk_posi_explored_q(7); //le n rendant q_n1+n2 egal a q_max
Eigen::VectorXd n1_pos_jerk_posi_explored_q(7);
Eigen::VectorXd n2_neg_jerk_posi_explored_q(7);
Eigen::VectorXd n2_pos_jerk_posi_explored_q(7);
double small_err =0;
double n2_neg_jerk_posi_exp_when_qddot_sup_zero;
double counter;

Eigen::VectorXd final_q_dotdot_bounds_max_comp_Jerk_acc_Posi(7);
Eigen::VectorXd final_q_dotdot_bounds_min_comp_Jerk_acc_Posi(7);
double n1_neg_Jerk_acc_Posi_exp;
double n2_neg_Jerk_acc_Posi_exp;
double n3_neg_Jerk_acc_Posi_exp;
double n1_pos_Jerk_acc_Posi_exp;
double n2_pos_Jerk_acc_Posi_exp;
double n3_pos_Jerk_acc_Posi_exp;
Eigen::VectorXd q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir(7);
Eigen::VectorXd q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir(7);
Eigen::VectorXd n1_neg_Jerk_acc_Posi_explored(7);
Eigen::VectorXd n2_neg_Jerk_acc_Posi_explored(7);
Eigen::VectorXd n3_neg_Jerk_acc_Posi_explored(7);
Eigen::VectorXd n1_pos_Jerk_acc_Posi_explored(7);
Eigen::VectorXd n2_pos_Jerk_acc_Posi_explored(7);
Eigen::VectorXd n3_pos_Jerk_acc_Posi_explored(7);
Eigen::VectorXd q_n_neg_Jerk_acc_Posi_reconstr(7);
Eigen::VectorXd q_n_pos_Jerk_acc_Posi_reconstr(7);
Eigen::VectorXd q_n_neg_Jerk_acc_Posi_reconstr_explored(7);
Eigen::VectorXd q_n_pos_Jerk_acc_Posi_reconstr_explored(7);
Eigen::VectorXd n1_neg_Jerk_acc_Posi_explored_q(7);
Eigen::VectorXd n2_neg_Jerk_acc_Posi_explored_q(7);
Eigen::VectorXd n3_neg_Jerk_acc_Posi_explored_q(7);
Eigen::VectorXd n1_pos_Jerk_acc_Posi_explored_q(7);
Eigen::VectorXd n2_pos_Jerk_acc_Posi_explored_q(7);
Eigen::VectorXd n3_pos_Jerk_acc_Posi_explored_q(7);

Eigen::VectorXd q_dotdot_bounds_max_comp_Jerk_acc_Posi(7);
Eigen::VectorXd q_dotdot_bounds_min_comp_Jerk_acc_Posi(7);
Eigen::VectorXd q_dotdot_bounds_max_comp_Jerk_acc_Posi_previous(7);
Eigen::VectorXd q_dotdot_bounds_min_comp_Jerk_acc_Posi_previous(7);
int n1_neg_Jerk_acc_Posi_explored_deja_1 = 0;


Eigen::VectorXd optimize_QP(Eigen::Matrix<double, 3, 7> J_70_l, 
			    Eigen::Matrix<double, 3, 7> J_70_dot_l,
		            Eigen::Matrix<double, 1, 7> J_70_l_proj_Xerr,
		            Eigen::Matrix<double, 1, 7> J_70_l_proj_x_axis,
		            Eigen::Matrix<double, 1, 7> J_70_l_proj_y_axis,		                    
		            Eigen::Matrix<double, 1, 7> J_70_l_proj_z_axis,
			    Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_Xerr,
			    Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_x_axis,			                
			    Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_y_axis,			                
			    Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_z_axis,	
                            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M, 
                            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_inv, 
			    Eigen::Matrix<double, 7, 1> b,
			    Eigen::Matrix<double, 3, 1> Jdot_qdot_r_77,
			    Eigen::Matrix<double, 3, 1> Jdot_qdot_r_70,
			    Eigen::Matrix<double, 3, 1> Jdot_qdot_l,
		            Eigen::Matrix<double, 6, 1> Jdot_qdot,	
			    Eigen::VectorXd X_err,
			    Eigen::VectorXd V_err,
			    Eigen::VectorXd X_err_angle_prj, 
			    Eigen::VectorXd V_err_angle_prj,
			    Eigen::Twistd V_7,
                            Eigen::VectorXd Acc_posi_70,
                            Eigen::VectorXd V_7_posi,
			    Eigen::Twistd V_77,
			    Eigen::VectorXd V_7_des,
			    Eigen::VectorXd Acc_7_des,
			    Eigen::VectorXd Acc_7_orient_des,
                            double kp,
			    double kd, 
		            double d_safe,
			    double d_max, 
			    double E_safe,
                            double Ec_max_7,
			    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_70,
		      	    Eigen::Matrix<double, 1, 7> J_70_C_proj,
                            double dt,			  
                            double m_eq_7_j,
                            double m_eq_7_j_Xerr,
			    double m_eq_7_j_x_axis,			                
			    double m_eq_7_j_y_axis,	
			    double m_eq_7_j_z_axis,	
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds,
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max,
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min,
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_comp,
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_comp,
			    double dist_07_nrst_ob,
			    Eigen::Matrix<double, 7, 1> gravity_terms,
			    Eigen::Matrix<double, 3, 7> J_77_r,
  			    Eigen::VectorXd Acc_7_orient,
			    Eigen::VectorXd Acc_7, 
			    Eigen::VectorXd V_7_posi_proj,
			    Eigen::Displacementd H_disp_70, 
                            Eigen::Matrix<double, 3, 7> J_70_r, 
			    double nxt_step_des_Jerk_7_x, 
			    double Jerk_x_curr, 
			    Eigen::Matrix<double, 7, 1> q,
			    Eigen::Matrix<double, 7, 1> q_dot,
			    Eigen::VectorXd q_ddot, 
			    Eigen::VectorXd q_dddot, 
			    Eigen::VectorXd q_ddddot,
			    Eigen::VectorXd q_bounds_min,
			    Eigen::VectorXd q_bounds_max,
			    Eigen::VectorXd q_dot_bounds_min,
			    Eigen::VectorXd q_dot_bounds_max,
			    Eigen::VectorXd q_dddot_bounds_min,
			    Eigen::VectorXd q_dddot_bounds_max,
                            Eigen::VectorXd q_dotdot_bounds_min_optimized,
                            Eigen::VectorXd q_dotdot_bounds_max_optimized, 
                            Eigen::Matrix<double, 7, 1> tau_min,
                            Eigen::Matrix<double, 7, 1> tau_max, 
			    Eigen::VectorXd q_k2, 
			    Eigen::VectorXd q_ddot_k2,
			    Eigen::VectorXd q_dddot_k2,
			    Eigen::VectorXd q_ddddot_k2,
                            Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_prime_forwrd_backwrd, 
                            Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_prime_forwrd_backwrd,
		            double time_in_second,
 			    double time_in_micsecond, 
			    Eigen::VectorXd q_des_posture, 
                            Eigen::VectorXd q_des)

{
  
  try {



if (initialize_ == 1){
J_7_mixed_previous << 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0;    

sum_consec_q_ddot_neg_jerk_acc_posi << 0, 0, 0, 0, 0, 0, 0;
sum_consec_q_ddot_pos_jerk_acc_posi << 0, 0, 0, 0, 0, 0, 0;
 
zero_q_dot<<   0, 0, 0, 0, 0, 0, 0;
zero_q_ddot<<  0, 0, 0, 0, 0, 0, 0;
zero_q_dddot<< 0, 0, 0, 0, 0, 0, 0;
zero_q_dddot<< 0, 0, 0, 0, 0, 0, 0;
breaking_phase_posi<< 0, 0, 0, 0, 0, 0, 0;
nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr = q_dot_bounds_max;
nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr = q_dotdot_bounds_max_optimized;

nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_from_vel_constr = q_dotdot_bounds_max_optimized;

q_dotdot_bounds_max_comp_Jerk_Posi_previous<<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_min_comp_Jerk_Posi_previous<<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_max_comp_Jerk_Vel_previous <<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_min_comp_Jerk_Vel_previous <<   0, 0, 0, 0, 0, 0, 0;
q_dot_dot_final_previous                   <<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_max_comp_Jerk_Posi_prev    <<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_min_comp_Jerk_Posi_prev    <<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_max_comp_Jerk_Posi_previous<<   0, 0, 0, 0, 0, 0, 0;
q_dotdot_bounds_min_comp_Jerk_Posi_previous<<   0, 0, 0, 0, 0, 0, 0;
q_n_pos_jerk_posi_reconstr                 <<   0, 0, 0, 0, 0, 0, 0;
q_n_pos_jerk_posi_reconstr                 <<   0, 0, 0, 0, 0, 0, 0;
//q_dot_dot_final                            <<   0, 0, 0, 0, 0, 0, 0;
q_n_neg_jerk_posi_reconstr                 <<   0, 0, 0, 0, 0, 0, 0;
q_n_pos_jerk_posi_reconstr                 <<   0, 0, 0, 0, 0, 0, 0;
q_n_neg_jerk_posi_reconstr_explored        <<   0, 0, 0, 0, 0, 0, 0;
q_n_pos_jerk_posi_reconstr_explored        <<   0, 0, 0, 0, 0, 0, 0;

q_n_neg_Jerk_acc_Posi_reconstr             <<   0, 0, 0, 0, 0, 0, 0;
q_n_pos_Jerk_acc_Posi_reconstr             <<   0, 0, 0, 0, 0, 0, 0;
initialize_ = 0;
}



steps_counter++;

/************************************Calcul des bounds sur q_dot_dot rendant l'accélération compatible avec les positions articulaires -1-************************************/

n_neg_acc_posi = compute_n_neg_acc_posi(q_dotdot_bounds_min_optimized, q_bounds_max, q, (dt));
n_pos_acc_posi = compute_n_pos_acc_posi(q_dotdot_bounds_max_optimized, q_bounds_min, q, (dt));

for(u=0; u<7; u++){ 
  q_dotdot_bounds_max_comp_Acc_Posi[u] =  ((q_bounds_max[u]-q[u])/(n_neg_acc_posi[u]*pow((dt),2))) - ((n_neg_acc_posi[u]-1)*q_dotdot_bounds_min_optimized[u]/2) - (q_dot[u]/(dt));  //Ne laisse passer que la partie positive
  q_dotdot_bounds_min_comp_Acc_Posi[u] =  ((q_bounds_min[u]-q[u])/(n_pos_acc_posi[u]*pow((dt),2))) - ((n_pos_acc_posi[u]-1)*q_dotdot_bounds_max_optimized[u]/2) - (q_dot[u]/(dt));
  
  q_dot_bounds_max_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_max[u]-q[u])/(n_neg_acc_posi[u]*(dt))) - ((n_neg_acc_posi[u]-1)*(dt)*q_dotdot_bounds_min_optimized[u]/2); 
  q_dot_bounds_min_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_min[u]-q[u])/(n_pos_acc_posi[u]*(dt))) - ((n_pos_acc_posi[u]-1)*(dt)*q_dotdot_bounds_max_optimized[u]/2);


  q_n_neg_acc_reconstr[u]         =    q[u] + (n_neg_acc_posi[u]*q_dot[u]*dt) + ((pow(n_neg_acc_posi[u],2)-n_neg_acc_posi[u])*q_dotdot_bounds_min_optimized[u]*pow(dt,2)*0.5);
  q_n_pos_acc_reconstr[u]         =    q[u] + (n_pos_acc_posi[u]*q_dot[u]*dt) + ((pow(n_pos_acc_posi[u],2)-n_pos_acc_posi[u])*q_dotdot_bounds_max_optimized[u]*pow(dt,2)*0.5);
}

/*
n_neg_acc_posi = compute_n_neg_acc_posi(q_dotdot_bounds_min_optimized, q_bounds_max, q_k2, dt);
n_pos_acc_posi = compute_n_pos_acc_posi(q_dotdot_bounds_max_optimized, q_bounds_min, q_k2, dt);

for(u=0; u<7; u++){ 
  q_dotdot_bounds_max_comp_Acc_Posi[u] =  ((q_bounds_max[u]-q_k2[u])/(n_neg_acc_posi[u]*pow(dt,2))) - ((n_neg_acc_posi[u]-1)*q_dotdot_bounds_min_optimized[u]/2) - (q_dot[u]/dt);
  q_dotdot_bounds_min_comp_Acc_Posi[u] =  ((q_bounds_min[u]-q_k2[u])/(n_pos_acc_posi[u]*pow(dt,2))) - ((n_pos_acc_posi[u]-1)*q_dotdot_bounds_max_optimized[u]/2) - (q_dot[u]/dt);


  q_dot_bounds_max_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_max[u]-q[u])/(n_neg_acc_posi[u]*(dt))) - ((n_neg_acc_posi[u]-1)*(dt)*q_dotdot_bounds_min_optimized[u]/2); 
  q_dot_bounds_min_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_min[u]-q[u])/(n_pos_acc_posi[u]*(dt))) - ((n_pos_acc_posi[u]-1)*(dt)*q_dotdot_bounds_max_optimized[u]/2);

//q_dotdot_bounds_max_comp_Acc_Posi[u] =  ((q_bounds_max[u]-q_k2[u])/(n_neg_acc_posi[u]*pow(dt,2))) - ((n_neg_acc_posi[u]-1)*(q_dddot_bounds_min[u])/2) - (q_dot[u]/dt);
//q_dotdot_bounds_min_comp_Acc_Posi[u] =  ((q_bounds_min[u]-q_k2[u])/(n_pos_acc_posi[u]*pow(dt,2))) - ((n_pos_acc_posi[u]-1)*(q_dddot_bounds_max[u]*)/2) - (q_dot[u]/dt);
}
*/

/*
//LAST HOPE 
for(u=0; u<7; u++){ 
  q_dotdot_bounds_max_comp_Acc_Posi[u] =  ((2*(q_bounds_max[u]-q[u]))/((pow(n_neg_acc_posi[u], 2)-n_neg_acc_posi[u])*pow((dt),2))) - (2*q_dot[u]/((n_neg_acc_posi[u]-1) * dt));  //Ne laisse passer que la partie positive
  q_dotdot_bounds_min_comp_Acc_Posi[u] =  ((2*(q_bounds_min[u]-q[u]))/((pow(n_pos_acc_posi[u], 2)-n_pos_acc_posi[u])*pow((dt),2))) - (2*q_dot[u]/((n_pos_acc_posi[u]-1) * dt));
  
  q_dot_bounds_max_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_max[u]-q[u])/(n_neg_acc_posi[u]*(dt))) - ((n_neg_acc_posi[u]-1)*(dt)*q_dotdot_bounds_min_optimized[u]/2); 
  q_dot_bounds_min_comp_Acc_Posi_vel_cmd[u] =  ((q_bounds_min[u]-q[u])/(n_pos_acc_posi[u]*(dt))) - ((n_pos_acc_posi[u]-1)*(dt)*q_dotdot_bounds_max_optimized[u]/2);
}
*/

save_q_n_neg_acc_reconstr(q_n_neg_acc_reconstr);
save_q_n_pos_acc_reconstr(q_n_pos_acc_reconstr);

save_q_dotdot_bounds_max_comp_Acc_Posi_0(q_dotdot_bounds_max_comp_Acc_Posi[0]);
save_q_dotdot_bounds_min_comp_Acc_Posi_0(q_dotdot_bounds_min_comp_Acc_Posi[0]);

/************************************Calcul des bounds sur q_dot_dot rendant l'accélération compatible avec les positions articulaires -1-************************************/





/************************************Calcul des bounds sur q_dot_dot rendant le Jerk compatible avec les vitesses articulaires -2-************************************/
//ORIGINAL WORK !!!!!!!
n_neg_jerk_vel = compute_n_neg_jerk_vel(q_dddot_bounds_min, q_dot_bounds_max, q_dot, dt);
n_pos_jerk_vel = compute_n_pos_jerk_vel(q_dddot_bounds_max, q_dot_bounds_min, q_dot, dt);


for(u=0; u<7; u++){ 
  q_dotdot_bounds_max_comp_Jerk_Vel[u] =  (bound_pos(q_dot_bounds_max[u]-q_dot[u])/(n_neg_jerk_vel[u]*dt)) - (((n_neg_jerk_vel[u]-1)*q_dddot_bounds_min[u]*dt)/(2));
  q_dotdot_bounds_min_comp_Jerk_Vel[u] =  (bound_neg(q_dot_bounds_min[u]-q_dot[u])/(n_pos_jerk_vel[u]*dt)) - (((n_pos_jerk_vel[u]-1)*q_dddot_bounds_max[u]*dt)/(2));

/*
  q_dotdot_bounds_comp_vel_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Vel[u] - q_dotdot_bounds_max_comp_Jerk_Vel_previous[u])/dt;
  q_dotdot_bounds_comp_vel_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Vel[u] - q_dotdot_bounds_min_comp_Jerk_Vel_previous[u])/dt;

  if(q_dotdot_bounds_comp_vel_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
     q_dotdot_bounds_max_comp_Jerk_Vel[u] = q_dotdot_bounds_max_comp_Jerk_Vel_previous[u] + q_dddot_bounds_max[u]*dt;
    }

  if(q_dotdot_bounds_comp_vel_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
     q_dotdot_bounds_min_comp_Jerk_Vel[u] = q_dotdot_bounds_min_comp_Jerk_Vel_previous[u] + q_dddot_bounds_min[u]*dt;;
    }
*/


/*
  q_dot_n_neg_jerk_reconstr[u]         =    q_dot[u] + (n_neg_jerk_vel[u]*q_dot_dot_final[u]*dt) + ((pow(n_neg_jerk_vel[u],2)-n_neg_jerk_vel[u])*q_dddot_bounds_min[u]*pow(dt,2)*0.5);
  q_dot_n_pos_jerk_reconstr[u]         =    q_dot[u] + (n_pos_jerk_vel[u]*q_dot_dot_final[u]*dt) + ((pow(n_pos_jerk_vel[u],2)-n_pos_jerk_vel[u])*q_dddot_bounds_max[u]*pow(dt,2)*0.5);
*/
  q_dot_n_neg_jerk_reconstr[u]         =    q_dot[u] + (n_neg_jerk_vel[u]*q_ddot[u]*dt) + ((pow(n_neg_jerk_vel[u],2)-n_neg_jerk_vel[u])*q_dddot_bounds_min[u]*pow(dt,2)*0.5);
  q_dot_n_pos_jerk_reconstr[u]         =    q_dot[u] + (n_pos_jerk_vel[u]*q_ddot[u]*dt) + ((pow(n_pos_jerk_vel[u],2)-n_pos_jerk_vel[u])*q_dddot_bounds_max[u]*pow(dt,2)*0.5);
}

save_q_dot_n_neg_jerk_reconstr(q_dot_n_neg_jerk_reconstr);
save_q_dot_n_pos_jerk_reconstr(q_dot_n_pos_jerk_reconstr);

save_q_dotdot_bounds_max_comp_Jerk_Vel_0(q_dotdot_bounds_max_comp_Jerk_Vel[0]);
save_q_dotdot_bounds_min_comp_Jerk_Vel_0(q_dotdot_bounds_min_comp_Jerk_Vel[0]);
/************************************Calcul des bounds sur q_dot_dot rendant le Jerk compatible avec les positions articulaires -3-************************************/







/************************************Calcul des bounds sur q_dot_dot rendant le Jerk compatible avec les positions articulaires -3-************************************/

//-----------Compute of "n_neg_jerk_posi" & "n_pos_jerk_posi" with P3 -----------// 
//Roots of poly p[0] x^3 + p[1] x^2 + p[2] x +p[3]=0
for(int g=0; g<7; g++){
//ori
  p_3(0, g) =  -((q_dddot_bounds_min[g]*pow(dt, 3))/6);
  p_3(1, g) =  -(((q_ddot[g]*pow(dt,2)) - (q_dddot_bounds_min[g]*pow(dt, 3)))/2);
  p_3(2, g) =  -((q_dot[g]*dt) + ((q_dddot_bounds_min[g] * pow(dt, 3))/3) - (q_ddot[g]*pow(dt,2)/2));
  p_3(3, g) =  -(q[g]-q_bounds_max[g]);
  p_3(4, g) =  0;

  p_3(5, g) =  -((q_dddot_bounds_max[g]*pow(dt, 3))/6);
  p_3(6, g) =  -(((q_ddot[g]*pow(dt,2)) - (q_dddot_bounds_max[g]*pow(dt, 3)))/2);
  p_3(7, g) =  -((q_dot[g]*dt) + ((q_dddot_bounds_max[g] * pow(dt, 3))/3) - (q_ddot[g]*pow(dt,2)/2));
  p_3(8, g) =  -(q[g]-q_bounds_min[g]);
  p_3(9, g) =  0;

/*
  p_3(0, g) =  -(q_dddot_bounds_min[g] * pow(dt, 3))/3;
  p_3(1, g) =  (-q_ddot_k2[g]*pow(dt, 2))+((q_dddot_bounds_min[g]*pow(dt, 3))/(2));
  p_3(2, g) =  0;
  p_3(3, g) =  q_k2[g]-q_bounds_max[g];
  p_3(4, g) =  0;

  p_3(5, g) =  -(q_dddot_bounds_max[g] * pow(dt, 3))/3;
  p_3(6, g) =  (-q_ddot_k2[g]*pow(dt, 2))+((q_dddot_bounds_max[g]*pow(dt, 3))/(2));
  p_3(7, g) =  0;
  p_3(8, g) =  q_k2[g]-q_bounds_min[g];
  p_3(9, g) =  0;
*/
}

  rounded_Cubic_roots          = G4_P3_Solver(p_3);



  rounded_Cubic_roots_neg_jerk = rounded_Cubic_roots.block<3,7>(0,0);
  rounded_Cubic_roots_pos_jerk = rounded_Cubic_roots.block<3,7>(3,0);

  n_neg_jerk_posi_P3 = int_root_neg_jerk_P3(rounded_Cubic_roots_neg_jerk, q_bounds_max, q_k2, q_ddot_k2, q_dddot_bounds_min, q_dot, dt); //number of iterations that minimizes val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)
  n_pos_jerk_posi_P3 = int_root_pos_jerk_P3(rounded_Cubic_roots_pos_jerk, q_bounds_min, q_k2, q_ddot_k2, q_dddot_bounds_max, q_dot, dt); //number of iterations that maximizes val_min_de_q_ddot, (q_ddot(t) > val_max_de_q_ddot)

/*
for(int g=0; g<7; g++){
  n_neg_jerk_posi_P3[g] = absolute(n_neg_jerk_posi_P3[g]); 
  n_pos_jerk_posi_P3[g] = absolute(n_pos_jerk_posi_P3[g]); 
}
*/
//-----------Compute of "n_neg_jerk_posi" & "n_pos_jerk_posi" with P3 -----------// 




//-----------Compute of "n_neg_jerk_posi" & "n_pos_jerk_posi" with P4 -----------//
 G4AnalyticalPolSolver solver;
 G4cout.precision(20);

for(int g=0; g<7; g++){ //Génération des polynôme : "val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)" et "val_min_de_q_ddot, (q_ddot(t) > val_max_de_q_ddot)"
//Ori 
  p_(0, g) = -(q_dddot_bounds_min[g] * pow(dt, 3))/3;
  p_(1, g) =  (q_dddot_bounds_min[g] * pow(dt, 3)) * (2/3);
  p_(2, g) =  (2*q_dot[g]*dt) - (q_dddot_bounds_min[g] * pow(dt, 3))/3;
  p_(3, g) =  (4*(q_bounds_max[g]-q[g]));
  p_(4, g) = -2*(q_bounds_max[g]-q[g]);

  p_(5, g) = -(q_dddot_bounds_max[g] * pow(dt, 3))/3;
  p_(6, g) =  (q_dddot_bounds_max[g] * pow(dt, 3)) * (2/3);
  p_(7, g) =  (2*q_dot[g]*dt) - (q_dddot_bounds_max[g] * pow(dt, 3))/3;
  p_(8, g) =  (4*(q_bounds_min[g]-q[g]));
  p_(9, g) = -2*(q_bounds_min[g]-q[g]);

}


  rounded_Quartic_roots = G4_P4_Solver(p_);              //On donne le tableau des plynômes. 2 pour chaque liaison, en sortie on a les 4 rounded racines pour chaque polynôme. Chaque polynôme est décrit par 5 paramètres. DU coup on a 8 racines pour chaque liaison
  
  rounded_Quartic_roots_neg_jerk = rounded_Quartic_roots.block<4,7>(0,0);
  rounded_Quartic_roots_pos_jerk = rounded_Quartic_roots.block<4,7>(4,0);

  n_neg_jerk_posi = int_root_neg_jerk(rounded_Quartic_roots_neg_jerk, q_bounds_min, q_bounds_max, q, q_dot, q_dddot_bounds_min, q_dddot_bounds_max, dt); //number of iterations that minimizes val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)
  n_pos_jerk_posi = int_root_pos_jerk(rounded_Quartic_roots_pos_jerk, q_bounds_min, q_bounds_max, q, q_dot, q_dddot_bounds_min, q_dddot_bounds_max, dt); //number of iterations that maximizes val_min_de_q_ddot, (q_ddot(t) > val_max_de_q_ddot)


/*
  n_neg_jerk_posi = n_neg_jerk_posi_P3; //number of iterations that minimizes val_min_de_q_ddot, (q_ddot(t) < val_min_de_q_ddot)
  n_pos_jerk_posi = n_pos_jerk_posi_P3;  //number of iterations that maximizes val_min_de_q_ddot, (q_ddot(t) > val_max_de_q_ddot)
*/
 //-----------Compute of "n_neg_jerk_posi" & "n_pos_jerk_posi" with P4 -----------//



//Génération des q_ddot bounds based on q_dddot max and q_dddot min. ORIGINAL
for(u=0; u<7; u++){ 
//Original good
  q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) =  (2*(q_bounds_max[u]-q[u])/((pow(n_neg_jerk_posi[u],2)-n_neg_jerk_posi[u])*pow(dt,2)))-((2*q_dot[u])/((n_neg_jerk_posi[u]-1)*dt))-(((((pow(n_neg_jerk_posi[u],2))/3)-n_neg_jerk_posi[u]+(2/3))*q_dddot_bounds_min[u]*dt)/(n_neg_jerk_posi[u]-1));
  q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) =  (2*(q_bounds_min[u]-q[u])/((pow(n_pos_jerk_posi[u],2)-n_pos_jerk_posi[u])*pow(dt,2)))-((2*q_dot[u])/((n_pos_jerk_posi[u]-1)*dt))-(((((pow(n_pos_jerk_posi[u],2))/3)-n_pos_jerk_posi[u]+(2/3))*q_dddot_bounds_max[u]*dt)/(n_pos_jerk_posi[u]-1));  



  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi[u] - q_dotdot_bounds_max_comp_Jerk_Posi_previous[u])/dt;
  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi[u] - q_dotdot_bounds_min_comp_Jerk_Posi_previous[u])/dt;

  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
     q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
    }

  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
     q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
    }



  //q_n_neg_jerk_posi_reconstr(u, 0)         =  q[u] + (n_neg_jerk_posi[u]*q_dot[u]*dt) + (((pow(n_neg_jerk_posi[u],2)-n_neg_jerk_posi[u])/2)*q_dot_dot_final[u]*pow(dt,2)) + ((pow(n_neg_jerk_posi[u],3)/6)-n_neg_jerk_posi[u]+(2/3))*q_dddot_bounds_min[u]*pow(dt,3);
  //q_n_pos_jerk_posi_reconstr(u, 0)         =  q[u] + (n_pos_jerk_posi[u]*q_dot[u]*dt) + (((pow(n_pos_jerk_posi[u],2)-n_pos_jerk_posi[u])/2)*q_dot_dot_final[u]*pow(dt,2)) + ((pow(n_pos_jerk_posi[u],3)/6)-n_pos_jerk_posi[u]+(2/3))*q_dddot_bounds_max[u]*pow(dt,3);


}
  //save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
  //save_q_n_pos_jerk_posi_reconstr(q_n_pos_jerk_posi_reconstr);
//-----------Compute of "n_neg_jerk_posi" & "n_pos_jerk_posi" with P4 -----------//









//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (NON COMPLETE FRMULA)-----------//

//Avant leur modification les contraintes sont égales aux valeurs max de l'opt
//q_dotdot_bounds_max_comp_Jerk_Posi = q_dotdot_bounds_max_optimized;
//q_dotdot_bounds_min_comp_Jerk_Posi = q_dotdot_bounds_min_optimized;

final_q_dotdot_bounds_max_comp_Jerk_Posi <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
final_q_dotdot_bounds_min_comp_Jerk_Posi << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

for(u=0; u<1; u++){ 
n_neg_jerk_posi_exp = 3; //shoulf be 2
n_pos_jerk_posi_exp = 3;
for(f=0; f<2000; f++){

q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] =  2*(q_bounds_max[u]-q[u])/((pow(n_neg_jerk_posi_exp,2)-n_neg_jerk_posi_exp)*pow(dt,2)) - (((pow(n_neg_jerk_posi_exp,2)/3)-n_neg_jerk_posi_exp+(2/3))*q_dddot_bounds_min[u]*dt)/(n_neg_jerk_posi_exp-1) - (2*q_dot[u])/((n_neg_jerk_posi_exp-1)*dt);
q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] =  2*(q_bounds_min[u]-q[u])/((pow(n_pos_jerk_posi_exp,2)-n_pos_jerk_posi_exp)*pow(dt,2)) - (((pow(n_pos_jerk_posi_exp,2)/3)-n_pos_jerk_posi_exp+(2/3))*q_dddot_bounds_max[u]*dt)/(n_pos_jerk_posi_exp-1) - (2*q_dot[u])/((n_pos_jerk_posi_exp-1)*dt);


//Contrainte sur vitesse transformee en constr sur acc (tjrs pour comp posi jerk)
//q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] =  (q_bounds_max[u]-q[u])/((n_neg_jerk_posi_exp)*pow(dt,2)) - (((pow(n_neg_jerk_posi_exp,2)/6)-(n_neg_jerk_posi_exp/2)+(1/3))*q_dddot_bounds_min[u]*dt) - (q_dot[u])/(dt) - ((n_neg_jerk_posi_exp-1)*0.5*q_ddot[u]);
//q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] =  (q_bounds_min[u]-q[u])/((n_pos_jerk_posi_exp)*pow(dt,2)) - (((pow(n_pos_jerk_posi_exp,2)/6)-(n_pos_jerk_posi_exp/2)+(1/3))*q_dddot_bounds_max[u]*dt) - (q_dot[u])/(dt) - ((n_pos_jerk_posi_exp-1)*0.5*q_ddot[u]);


if(q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] < final_q_dotdot_bounds_max_comp_Jerk_Posi[u]){
final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
n_neg_jerk_posi_explored[u]= n_neg_jerk_posi_exp;
}

if(q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_Posi[u]){
final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
n_pos_jerk_posi_explored[u]= n_pos_jerk_posi_exp;
}


n_neg_jerk_posi_exp=n_neg_jerk_posi_exp+1;
n_pos_jerk_posi_exp=n_pos_jerk_posi_exp+1;
}



//

q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi[u];
q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_Posi[u];


  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi[u] - q_dotdot_bounds_max_comp_Jerk_Posi_previous[u])/dt;
  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi[u] - q_dotdot_bounds_min_comp_Jerk_Posi_previous[u])/dt;

  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
     q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
    }

  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
     q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
    }

//q_n_neg_jerk_posi_reconstr(u, 0)         =  q[u] + (n_neg_jerk_posi[u]*q_dot[u]*dt) + (((pow(n_neg_jerk_posi[u],2)-n_neg_jerk_posi[u])/2)*q_ddot[u]*pow(dt,2)) + ((pow(n_neg_jerk_posi[u],3)/6)-n_neg_jerk_posi[u]+(2/3))*q_dddot_bounds_min[u]*pow(dt,3);
//q_n_pos_jerk_posi_reconstr(u, 0)         =  q[u] + (n_pos_jerk_posi[u]*q_dot[u]*dt) + (((pow(n_pos_jerk_posi[u],2)-n_pos_jerk_posi[u])/2)*q_ddot[u]*pow(dt,2)) + ((pow(n_pos_jerk_posi[u],3)/6)-n_pos_jerk_posi[u]+(2/3))*q_dddot_bounds_max[u]*pow(dt,3);
  q_n_neg_jerk_posi_reconstr(u, 0)         =  q[u] + (n_neg_jerk_posi_explored[u]*q_dot[u]*dt) + (((pow(n_neg_jerk_posi_explored[u],2)-n_neg_jerk_posi_explored[u])/2)*q_ddot[u]*pow(dt,2)) + ((pow(n_neg_jerk_posi_explored[u],3)/6)-n_neg_jerk_posi_explored[u]+(2/3))*q_dddot_bounds_min[u]*pow(dt,3);
  q_n_pos_jerk_posi_reconstr(u, 0)         =  q[u] + (n_pos_jerk_posi_explored[u]*q_dot[u]*dt) + (((pow(n_pos_jerk_posi_explored[u],2)-n_pos_jerk_posi_explored[u])/2)*q_ddot[u]*pow(dt,2)) + ((pow(n_pos_jerk_posi_explored[u],3)/6)-n_pos_jerk_posi_explored[u]+(2/3))*q_dddot_bounds_max[u]*pow(dt,3);


}   
  save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
  save_q_n_pos_jerk_posi_reconstr(q_n_pos_jerk_posi_reconstr);
//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (NON COMPLETE FORMULA)-----------//








//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (COMPLETE FRMULA)-----------//
//final_q_dotdot_bounds_max_comp_Jerk_Posi <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
//final_q_dotdot_bounds_min_comp_Jerk_Posi << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

//for(u=0; u<1; u++){ 
//n1_neg_jerk_posi_exp = 2002;
//n1_pos_jerk_posi_exp = 2002;
//counter              = 2002;
//for(f=0; f<2000; f++){

//if(q_ddot[u]>=0){
//n2_neg_jerk_posi_exp = n1_neg_jerk_posi_exp - absolute(round_up((-q_ddot[u])/(q_dddot_bounds_min[u]*dt)));
//n2_neg_jerk_posi_exp_when_qddot_sup_zero = 190;
//if(n1_neg_jerk_posi_exp <= 3){n1_neg_jerk_posi_exp = 3;}
//if(n2_neg_jerk_posi_exp <= 3){n2_neg_jerk_posi_exp = 3;}
//}
//if(q_ddot[u]<0 && n1_neg_jerk_posi_exp >= 3){
//if(q_dddot[u]<0){
//n2_neg_jerk_posi_exp = 190;
//}

//if(q_dddot[u]>0){
////n1_neg_jerk_posi_exp = 3;
////n2_neg_jerk_posi_exp = counter;
//n2_neg_jerk_posi_exp = absolute(round_up((-q_ddot[u])/(q_dddot_bounds_min[u]*dt)));
//if(n2_neg_jerk_posi_exp <= 3){n2_neg_jerk_posi_exp = 3;}
//}
//}
///*
//n2_pos_jerk_posi_exp = n1_pos_jerk_posi_exp - absolute(round_up((q_ddot[u])/(q_dddot_bounds_max[u]*dt)));
//if(n1_pos_jerk_posi_exp <= 3){n1_pos_jerk_posi_exp = 3;}
//if(n2_pos_jerk_posi_exp <= 3){n2_pos_jerk_posi_exp = 3;}
//*/

//q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*dt) - ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2))));
//q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*dt) - ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))) - (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2))));


//if(q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] < final_q_dotdot_bounds_max_comp_Jerk_Posi[u]){
//final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
//n1_neg_jerk_posi_explored[u] = n1_neg_jerk_posi_exp;
//n2_neg_jerk_posi_explored[u] = n2_neg_jerk_posi_exp;
//if(n2_neg_jerk_posi_explored[u] <= 3){n2_neg_jerk_posi_explored[u] = 3;}
//}

//if(q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_Posi[u]){
//final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
//n1_pos_jerk_posi_explored[u]= n1_pos_jerk_posi_exp;

//n2_pos_jerk_posi_explored[u] = n1_pos_jerk_posi_explored[u] - absolute(round_up((q_ddot[u])/(q_dddot_bounds_max[u]*dt)));
//if(n2_pos_jerk_posi_explored[u] <= 3){n2_pos_jerk_posi_explored[u] = 3;}
//}


//  q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u]*dt) + (((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*pow(dt,3));
//  q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u]*dt) + (((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*pow(dt,3));





//  if(absolute(q_bounds_max[u] - q_n_neg_jerk_posi_reconstr(u, 0)) < 0.01){ 
//     q_n_neg_jerk_posi_reconstr_explored(u, 0) = q_n_neg_jerk_posi_reconstr(u, 0);
///*
//std::cout<<"je suis la !!!"<<std::endl;
//std::cout<<"f : "<< f <<std::endl;
//std::cout<<" "<<std::endl;
//std::cout<<" "<<std::endl;
//*/
//     n1_neg_jerk_posi_explored_q[u] = n1_neg_jerk_posi_exp;
//     n2_neg_jerk_posi_explored_q[u] = n2_neg_jerk_posi_exp;
//     q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_explored_q[u]+n2_neg_jerk_posi_explored_q[u])*q_dot[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_neg_jerk_posi_explored_q[u]*(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u])+n2_neg_jerk_posi_explored_q[u]*(pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u]))/(2))+((pow(n1_neg_jerk_posi_explored_q[u],3)/6)-(pow(n1_neg_jerk_posi_explored_q[u],2)/2)+(n1_neg_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_neg_jerk_posi_explored_q[u],3)/6)-(pow(n2_neg_jerk_posi_explored_q[u],2)/2)+(n2_neg_jerk_posi_explored_q[u]/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2))));
//     //final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
//     small_err = 2;
//    }
///*
//  if(absolute(q_n_neg_jerk_posi_reconstr(u, 0) - q_bounds_max[u]) > 0.01){ 
//     small_err = 0;    
//std::cout<<"et la en meme temps !!!"<<std::endl;
//std::cout<<"f : "<< f <<std::endl;
//     q_n_neg_jerk_posi_reconstr_explored(u, 0) = 1.5;
//      }
//*/

//  if(absolute(q_n_pos_jerk_posi_reconstr(u, 0) - q_bounds_min[u]) < 0.01){ 
//     q_n_pos_jerk_posi_reconstr_explored(u, 0) = q_n_pos_jerk_posi_reconstr(u, 0);
//     n1_pos_jerk_posi_explored_q[u] = n1_pos_jerk_posi_exp;
//     n2_pos_jerk_posi_explored_q[u] = n2_pos_jerk_posi_exp;
//     q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_explored_q[u]+n2_pos_jerk_posi_explored_q[u])*q_dot[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_pos_jerk_posi_explored_q[u]*(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u])+n2_pos_jerk_posi_explored_q[u]*(pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u]))/(2))+((pow(n1_pos_jerk_posi_explored_q[u],3)/6)-(pow(n1_pos_jerk_posi_explored_q[u],2)/2)+(n1_pos_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_pos_jerk_posi_explored_q[u],3)/6)-(pow(n2_pos_jerk_posi_explored_q[u],2)/2)+(n2_pos_jerk_posi_explored_q[u]/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2))));
//     //final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
//    }


//n1_neg_jerk_posi_exp--;
//n1_pos_jerk_posi_exp--;
//counter--;
//}






////

//q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi[u];
//q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_Posi[u];


//  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi[u] - q_dotdot_bounds_max_comp_Jerk_Posi_previous[u])/dt;
//  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi[u] - q_dotdot_bounds_min_comp_Jerk_Posi_previous[u])/dt;

//  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
//     q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
//    }

//  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
//     q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
//    }

//  //q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_explored[u]+n2_neg_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_neg_jerk_posi_explored[u]*n2_neg_jerk_posi_explored[u])+(((pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_explored[u]*(pow(n2_neg_jerk_posi_explored[u],2)-n2_neg_jerk_posi_explored[u])+n2_neg_jerk_posi_explored[u]*(pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u]))/(2))+((pow(n1_neg_jerk_posi_explored[u],3)/6)-(pow(n1_neg_jerk_posi_explored[u],2)/2)+(n1_neg_jerk_posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_explored[u],3)/6)-(pow(n2_neg_jerk_posi_explored[u],2)/2)+(n2_neg_jerk_posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3));
//  //q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_explored[u]+n2_pos_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_pos_jerk_posi_explored[u]*n2_pos_jerk_posi_explored[u])+(((pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_explored[u]*(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u])+n2_pos_jerk_posi_explored[u]*(pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u]))/(2))+((pow(n1_pos_jerk_posi_explored[u],3)/6)-(pow(n1_pos_jerk_posi_explored[u],2)/2)+(n1_pos_jerk_posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_explored[u],3)/6)-(pow(n2_pos_jerk_posi_explored[u],2)/2)+(n2_pos_jerk_posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3));

//}   
//  save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
//  save_q_n_pos_jerk_posi_reconstr(q_n_pos_jerk_posi_reconstr);
//  save_q_n_neg_jerk_posi_reconstr_explored(q_n_neg_jerk_posi_reconstr_explored);
//  save_q_n_pos_jerk_posi_reconstr_explored(q_n_pos_jerk_posi_reconstr_explored);

//  save_n1_neg_jerk_posi_explored(n1_neg_jerk_posi_explored);
//  save_n1_pos_jerk_posi_explored(n1_pos_jerk_posi_explored);
//  save_n2_neg_jerk_posi_explored(n2_neg_jerk_posi_explored);
//  save_n2_pos_jerk_posi_explored(n2_pos_jerk_posi_explored);

//  save_n1_neg_jerk_posi_explored_q(n1_neg_jerk_posi_explored_q);
//  save_n1_pos_jerk_posi_explored_q(n1_pos_jerk_posi_explored_q);
//  save_n2_neg_jerk_posi_explored_q(n2_neg_jerk_posi_explored_q);
//  save_n2_pos_jerk_posi_explored_q(n2_pos_jerk_posi_explored_q);

//  save_small_err(small_err);
//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (COMPLETE FORMULA)-----------//






//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI EXPLOR n1 & n2 (tahta are related numerically)-----------------------------------------//

//Avant leur modification les contraintes sont égales aux valeurs max de l'opt
//q_dotdot_bounds_max_comp_Jerk = q_dotdot_bounds_max_optimized;
//q_dotdot_bounds_min_comp_Jerk = q_dotdot_bounds_min_optimized;

//start_count_time = time_in_micsecond;
//final_q_dotdot_bounds_max_comp_Jerk_Posi <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
//final_q_dotdot_bounds_min_comp_Jerk_Posi << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

//for(u=0; u<1; u++){ 
//n1_neg_jerk_posi_exp = 3;
//n1_pos_jerk_posi_exp = 3;
//for(y=0; y<500; y++){        //POUR PAPIER : 1800
//n2_neg_jerk_posi_exp = 3;
//n2_pos_jerk_posi_exp = 3;
//for(p=0; p<500; p++){        //500

//q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*dt) - ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2))));
//q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*dt) - ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))) - (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2))));



//if(q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] < final_q_dotdot_bounds_max_comp_Jerk_Posi[u]){
//final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
//n1_neg_jerk_posi_explored[u] = n1_neg_jerk_posi_exp;
//n2_neg_jerk_posi_explored[u] = n2_neg_jerk_posi_exp;
//if(n2_neg_jerk_posi_explored[u] <= 3){n2_neg_jerk_posi_explored[u] = 3;}
//}

//if(q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_Posi[u]){
//final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = -100;
//n1_pos_jerk_posi_explored[u] = n1_pos_jerk_posi_exp;
//n2_pos_jerk_posi_explored[u] = n2_neg_jerk_posi_exp;
//if(n2_pos_jerk_posi_explored[u] <= 3){n2_pos_jerk_posi_explored[u] = 3;}
//}


//q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*dt) - ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2))));
//q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*dt) - ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))) - (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2))));




//  if(absolute(q_bounds_max[u] - q_n_neg_jerk_posi_reconstr(u, 0)) < 0.01){ 
//     q_n_neg_jerk_posi_reconstr_explored(u, 0) = q_n_neg_jerk_posi_reconstr(u, 0);
//     n1_neg_jerk_posi_explored_q[u] = n1_neg_jerk_posi_exp;
//     n2_neg_jerk_posi_explored_q[u] = n2_neg_jerk_posi_exp;
//     //q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_explored_q[u]+n2_neg_jerk_posi_explored_q[u])*q_dot[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_neg_jerk_posi_explored_q[u]*(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u])+n2_neg_jerk_posi_explored_q[u]*(pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u]))/(2))+((pow(n1_neg_jerk_posi_explored_q[u],3)/6)-(pow(n1_neg_jerk_posi_explored_q[u],2)/2)+(n1_neg_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_neg_jerk_posi_explored_q[u],3)/6)-(pow(n2_neg_jerk_posi_explored_q[u],2)/2)+(n2_neg_jerk_posi_explored_q[u]/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2))));
//     //final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
//    }


//  if(absolute(q_n_pos_jerk_posi_reconstr(u, 0) - q_bounds_min[u]) < 0.01){ 
//     q_n_pos_jerk_posi_reconstr_explored(u, 0) = q_n_pos_jerk_posi_reconstr(u, 0);
//     n1_pos_jerk_posi_explored_q[u] = n1_pos_jerk_posi_exp;
//     n2_pos_jerk_posi_explored_q[u] = n2_pos_jerk_posi_exp;
//     //q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_explored_q[u]+n2_pos_jerk_posi_explored_q[u])*q_dot[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_pos_jerk_posi_explored_q[u]*(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u])+n2_pos_jerk_posi_explored_q[u]*(pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u]))/(2))+((pow(n1_pos_jerk_posi_explored_q[u],3)/6)-(pow(n1_pos_jerk_posi_explored_q[u],2)/2)+(n1_pos_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_pos_jerk_posi_explored_q[u],3)/6)-(pow(n2_pos_jerk_posi_explored_q[u],2)/2)+(n2_pos_jerk_posi_explored_q[u]/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2))));
//     //final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
//    }


//n2_neg_jerk_posi_exp=n2_neg_jerk_posi_exp+1;
//n2_pos_jerk_posi_exp=n2_pos_jerk_posi_exp+1;
//}
//n1_neg_jerk_posi_exp = n1_neg_jerk_posi_exp+1;
//n1_pos_jerk_posi_exp = n1_pos_jerk_posi_exp+1;
//}   


//q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi[u];
//q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_Posi[u];


//  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi[u] - q_dotdot_bounds_max_comp_Jerk_Posi_previous[u])/dt;
//  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi[u] - q_dotdot_bounds_min_comp_Jerk_Posi_previous[u])/dt;

///*
//  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
//     q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
//    }

//  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
//     q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
//    }
//*/

//  q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u]*dt) + (((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*pow(dt,3));
//  q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u]*dt) + (((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*pow(dt,3));


//}
//  save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
//  save_q_n_pos_jerk_posi_reconstr(q_n_pos_jerk_posi_reconstr);
//  save_q_n_neg_jerk_posi_reconstr_explored(q_n_neg_jerk_posi_reconstr_explored);
//  save_q_n_pos_jerk_posi_reconstr_explored(q_n_pos_jerk_posi_reconstr_explored);
//  save_n1_neg_jerk_posi_explored(n1_neg_jerk_posi_explored);
//  save_n1_pos_jerk_posi_explored(n1_pos_jerk_posi_explored);
//  save_n2_neg_jerk_posi_explored(n2_neg_jerk_posi_explored);
//  save_n2_pos_jerk_posi_explored(n2_pos_jerk_posi_explored);
//  save_n1_neg_jerk_posi_explored_q(n1_neg_jerk_posi_explored_q);
//  save_n1_pos_jerk_posi_explored_q(n1_pos_jerk_posi_explored_q);
//  save_n2_neg_jerk_posi_explored_q(n2_neg_jerk_posi_explored_q);
//  save_n2_pos_jerk_posi_explored_q(n2_pos_jerk_posi_explored_q);
//  save_small_err(small_err);
//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI EXPLOR n1 & n2 (tahta are related numerically)-----------------------------------------//






//BONNE VOIE
//if(q_dot_dot_final[u]>=0){
//n2_neg_jerk_posi_exp = n1_neg_jerk_posi_exp - absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_min[u]*dt)));
//if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 1;}
//if(n2_neg_jerk_posi_exp <= 1){n2_neg_jerk_posi_exp = 1;}
//small_err = 5;
//}


//if(q_dot_dot_final[u]<0){

//n2_neg_jerk_posi_exp = (n1_neg_jerk_posi_exp) + absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
//if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 0;}
//if(n2_neg_jerk_posi_exp <= 2){n2_neg_jerk_posi_exp = 2;}
///*
//if(n1_neg_jerk_posi_exp <= 1){
//n2_neg_jerk_posi_exp = absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
//if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 1;}
//if(n2_neg_jerk_posi_exp <= 2){n2_neg_jerk_posi_exp = 2;}
//}
//*/
//small_err = 4;
//}












//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (COMPLETE FRMULA)-----------//
final_q_dotdot_bounds_max_comp_Jerk_Posi <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
final_q_dotdot_bounds_min_comp_Jerk_Posi << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

for(u=0; u<1; u++){ 
n1_neg_jerk_posi_exp = 1;
n1_pos_jerk_posi_exp = 1;
for(f=0; f<=2000; f++){

if(q_dot_dot_final[u]>=0){
//n2_neg_jerk_posi_exp = round_up(n1_neg_jerk_posi_exp - absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_min[u]*dt))));
n2_neg_jerk_posi_exp = n1_neg_jerk_posi_exp - absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_min[u]*dt)));
if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 1;}
if(n2_neg_jerk_posi_exp <= 2){n2_neg_jerk_posi_exp = 2;}
small_err = 5;
}


if(q_dot_dot_final[u]<0){
//n2_neg_jerk_posi_exp = round_up((n1_neg_jerk_posi_exp) + absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt))));
n2_neg_jerk_posi_exp = (n1_neg_jerk_posi_exp) + absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 1;}
if(n2_neg_jerk_posi_exp <= 2){n2_neg_jerk_posi_exp = 2;}

if(n1_neg_jerk_posi_exp <= 1){
//n2_neg_jerk_posi_exp = round_up(absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt))));
n2_neg_jerk_posi_exp = absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
if(n1_neg_jerk_posi_exp <= 1){n1_neg_jerk_posi_exp = 1;}
if(n2_neg_jerk_posi_exp <= 2){n2_neg_jerk_posi_exp = 2;}
}

small_err = 4;
}


//if(n1_neg_jerk_posi_exp <= 3){n1_neg_jerk_posi_exp = 3;}
//if(n2_neg_jerk_posi_exp <= 3){n2_neg_jerk_posi_exp = 3;}
//n2_pos_jerk_posi_exp = n1_pos_jerk_posi_exp - absolute(round_up((q_ddot[u])/(q_dddot_bounds_max[u]*dt)));
//n2_neg_jerk_posi_exp = n1_neg_jerk_posi_exp - absolute(round_up(absolute(-q_ddot[u])/absolute(q_dddot_bounds_min[u]*dt)));


q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*dt) - ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2))));
q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u])/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*dt) - ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))) - (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2))));
/*
if(q_dot_dot_final[u]<0 && n1_neg_jerk_posi_exp == 1){
q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*dt) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2))));
//q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = 2*(q_bounds_max[u]-q[u])/((pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)*pow(dt,2)) - (((pow(n2_neg_jerk_posi_exp,2)/3)-n2_neg_jerk_posi_exp+(2/3))*q_dddot_bounds_max[u]*dt)/(n2_neg_jerk_posi_exp-1) - (2*q_dot[u])/((n2_neg_jerk_posi_exp-1)*dt);
}
*/





if(q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] <= final_q_dotdot_bounds_max_comp_Jerk_Posi[u]){
//if(q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] <= final_q_dotdot_bounds_max_comp_Jerk_Posi[u] && absolute((q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u]-q_dotdot_bounds_max_comp_Jerk_Posi[u])/dt)<=q_dddot_bounds_max[u]){
final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
n1_neg_jerk_posi_explored[u] = n1_neg_jerk_posi_exp;
n2_neg_jerk_posi_explored[u] = n2_neg_jerk_posi_exp;
//q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_explored[u]+n2_neg_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_neg_jerk_posi_explored[u]*n2_neg_jerk_posi_explored[u])+(((pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_explored[u]*(pow(n2_neg_jerk_posi_explored[u],2)-n2_neg_jerk_posi_explored[u])+n2_neg_jerk_posi_explored[u]*(pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u]))/(2))+((pow(n1_neg_jerk_posi_explored[u],3)/6)-(pow(n1_neg_jerk_posi_explored[u],2)/2)+(n1_neg_jerk_posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_explored[u],3)/6)-(pow(n2_neg_jerk_posi_explored[u],2)/2)+(n2_neg_jerk_posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3));
/*
if(q_dot_dot_final[u]<0){
n1_neg_jerk_posi_exp = n1_neg_jerk_posi_exp + 1;
n2_neg_jerk_posi_exp = n1_neg_jerk_posi_exp + absolute(round_up((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u])/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))*dt) - ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2)))) - (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp))/(2))));
final_q_dotdot_bounds_max_comp_Jerk_Posi[u]     = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
n1_neg_jerk_posi_explored[u] = n1_neg_jerk_posi_exp;
}
*/
  q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_explored[u]+n2_neg_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_neg_jerk_posi_explored[u]*n2_neg_jerk_posi_explored[u])+(((pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_explored[u]*(pow(n2_neg_jerk_posi_explored[u],2)-n2_neg_jerk_posi_explored[u])+n2_neg_jerk_posi_explored[u]*(pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u]))/(2))+((pow(n1_neg_jerk_posi_explored[u],3)/6)-(pow(n1_neg_jerk_posi_explored[u],2)/2)+(n1_neg_jerk_posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_explored[u],3)/6)-(pow(n2_neg_jerk_posi_explored[u],2)/2)+(n2_neg_jerk_posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3));
}


if(q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_Posi[u]){
//final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = -100;
n1_pos_jerk_posi_explored[u] = n1_pos_jerk_posi_exp;
n2_pos_jerk_posi_explored[u] = n2_pos_jerk_posi_exp;
//q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_explored[u]+n2_pos_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_pos_jerk_posi_explored[u]*n2_pos_jerk_posi_explored[u])+(((pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_explored[u]*(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u])+n2_pos_jerk_posi_explored[u]*(pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u]))/(2))+((pow(n1_pos_jerk_posi_explored[u],3)/6)-(pow(n1_pos_jerk_posi_explored[u],2)/2)+(n1_pos_jerk_posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_explored[u],3)/6)-(pow(n2_pos_jerk_posi_explored[u],2)/2)+(n2_pos_jerk_posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3));
}


  //q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_exp+n2_neg_jerk_posi_exp)*q_dot[u]*dt) + (((n1_neg_jerk_posi_exp*n2_neg_jerk_posi_exp)+(((pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_exp*(pow(n2_neg_jerk_posi_exp,2)-n2_neg_jerk_posi_exp)+n2_neg_jerk_posi_exp*(pow(n1_neg_jerk_posi_exp,2)-n1_neg_jerk_posi_exp))/(2))+((pow(n1_neg_jerk_posi_exp,3)/6)-(pow(n1_neg_jerk_posi_exp,2)/2)+(n1_neg_jerk_posi_exp/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_exp,3)/6)-(pow(n2_neg_jerk_posi_exp,2)/2)+(n2_neg_jerk_posi_exp/3))*q_dddot_bounds_max[u]*pow(dt,3));
  //q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_exp+n2_pos_jerk_posi_exp)*q_dot[u]*dt) + (((n1_pos_jerk_posi_exp*n2_pos_jerk_posi_exp)+(((pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp)+(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_exp*(pow(n2_pos_jerk_posi_exp,2)-n2_pos_jerk_posi_exp)+n2_pos_jerk_posi_exp*(pow(n1_pos_jerk_posi_exp,2)-n1_pos_jerk_posi_exp))/(2))+((pow(n1_pos_jerk_posi_exp,3)/6)-(pow(n1_pos_jerk_posi_exp,2)/2)+(n1_pos_jerk_posi_exp/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_exp,3)/6)-(pow(n2_pos_jerk_posi_exp,2)/2)+(n2_pos_jerk_posi_exp/3))*q_dddot_bounds_min[u]*pow(dt,3));



  if(absolute(q_bounds_max[u] - q_n_neg_jerk_posi_reconstr(u, 0)) < 0.01){ 
     q_n_neg_jerk_posi_reconstr_explored(u, 0) = q_n_neg_jerk_posi_reconstr(u, 0);
     n1_neg_jerk_posi_explored_q[u] = n1_neg_jerk_posi_exp;
     n2_neg_jerk_posi_explored_q[u] = n2_neg_jerk_posi_exp;
     q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_neg_jerk_posi_explored_q[u]+n2_neg_jerk_posi_explored_q[u])*q_dot[u])/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_neg_jerk_posi_explored_q[u]*(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u])+n2_neg_jerk_posi_explored_q[u]*(pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u]))/(2))+((pow(n1_neg_jerk_posi_explored_q[u],3)/6)-(pow(n1_neg_jerk_posi_explored_q[u],2)/2)+(n1_neg_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_neg_jerk_posi_explored_q[u],3)/6)-(pow(n2_neg_jerk_posi_explored_q[u],2)/2)+(n2_neg_jerk_posi_explored_q[u]/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_jerk_posi_explored_q[u]*n2_neg_jerk_posi_explored_q[u])+(((pow(n1_neg_jerk_posi_explored_q[u],2)-n1_neg_jerk_posi_explored_q[u])+(pow(n2_neg_jerk_posi_explored_q[u],2)-n2_neg_jerk_posi_explored_q[u]))/(2))));
     //final_q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_provizoir[u];
     }


  if(absolute(q_n_pos_jerk_posi_reconstr(u, 0) - q_bounds_min[u]) < 0.01){ 
     q_n_pos_jerk_posi_reconstr_explored(u, 0) = q_n_pos_jerk_posi_reconstr(u, 0);
     n1_pos_jerk_posi_explored_q[u] = n1_pos_jerk_posi_exp;
     n2_pos_jerk_posi_explored_q[u] = n2_pos_jerk_posi_exp;
     q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = -100;
     //q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_pos_jerk_posi_explored_q[u]+n2_pos_jerk_posi_explored_q[u])*q_dot[u])/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))*dt) - ((((n1_pos_jerk_posi_explored_q[u]*(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u])+n2_pos_jerk_posi_explored_q[u]*(pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u]))/(2))+((pow(n1_pos_jerk_posi_explored_q[u],3)/6)-(pow(n1_pos_jerk_posi_explored_q[u],2)/2)+(n1_pos_jerk_posi_explored_q[u]/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2)))) - (((pow(n2_pos_jerk_posi_explored_q[u],3)/6)-(pow(n2_pos_jerk_posi_explored_q[u],2)/2)+(n2_pos_jerk_posi_explored_q[u]/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_jerk_posi_explored_q[u]*n2_pos_jerk_posi_explored_q[u])+(((pow(n1_pos_jerk_posi_explored_q[u],2)-n1_pos_jerk_posi_explored_q[u])+(pow(n2_pos_jerk_posi_explored_q[u],2)-n2_pos_jerk_posi_explored_q[u]))/(2))));
     //final_q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_provizoir[u];
    }


n1_neg_jerk_posi_exp++;
n1_pos_jerk_posi_exp++;
}



//
//q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi[u];
//q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_Posi[u];


//  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi[u] - q_dotdot_bounds_max_comp_Jerk_Posi_previous[u])/dt;
//  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi[u] - q_dotdot_bounds_min_comp_Jerk_Posi_previous[u])/dt;
///*
//  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
//     q_dotdot_bounds_max_comp_Jerk_Posi[u] = q_dotdot_bounds_max_comp_Jerk_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
//    }

//  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
//     q_dotdot_bounds_min_comp_Jerk_Posi[u] = q_dotdot_bounds_min_comp_Jerk_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
//    }
//*/
///*
//if(q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) <= q_dot_dot_final[u]){
//std::cout<<"batata !!" <<std::endl;
//  q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_explored[u]+n2_neg_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_neg_jerk_posi_explored[u]*n2_neg_jerk_posi_explored[u])+(((pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_explored[u]*(pow(n2_neg_jerk_posi_explored[u],2)-n2_neg_jerk_posi_explored[u])+n2_neg_jerk_posi_explored[u]*(pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u]))/(2))+((pow(n1_neg_jerk_posi_explored[u],3)/6)-(pow(n1_neg_jerk_posi_explored[u],2)/2)+(n1_neg_jerk_posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_explored[u],3)/6)-(pow(n2_neg_jerk_posi_explored[u],2)/2)+(n2_neg_jerk_posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3));
//  save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
//}
//else{
//q_n_neg_jerk_posi_reconstr << 0, 0, 0, 0, 0, 0, 0;
// save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
//}
//*/
///*
//if(q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) > q_dot_dot_final[u]{
//  q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_explored[u]+n2_pos_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_pos_jerk_posi_explored[u]*n2_pos_jerk_posi_explored[u])+(((pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_explored[u]*(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u])+n2_pos_jerk_posi_explored[u]*(pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u]))/(2))+((pow(n1_pos_jerk_posi_explored[u],3)/6)-(pow(n1_pos_jerk_posi_explored[u],2)/2)+(n1_pos_jerk_posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_explored[u],3)/6)-(pow(n2_pos_jerk_posi_explored[u],2)/2)+(n2_pos_jerk_posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3));
//}
//*/

//  //q_n_neg_jerk_posi_reconstr(u, 0) = q[u] + ((n1_neg_jerk_posi_explored[u]+n2_neg_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_neg_jerk_posi_explored[u]*n2_neg_jerk_posi_explored[u])+(((pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_neg_jerk_posi_explored[u]*(pow(n2_neg_jerk_posi_explored[u],2)-n2_neg_jerk_posi_explored[u])+n2_neg_jerk_posi_explored[u]*(pow(n1_neg_jerk_posi_explored[u],2)-n1_neg_jerk_posi_explored[u]))/(2))+((pow(n1_neg_jerk_posi_explored[u],3)/6)-(pow(n1_neg_jerk_posi_explored[u],2)/2)+(n1_neg_jerk_posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_posi_explored[u],3)/6)-(pow(n2_neg_jerk_posi_explored[u],2)/2)+(n2_neg_jerk_posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3));
//  //q_n_pos_jerk_posi_reconstr(u, 0) = q[u] + ((n1_pos_jerk_posi_explored[u]+n2_pos_jerk_posi_explored[u])*q_dot[u]*dt) + (((n1_pos_jerk_posi_explored[u]*n2_pos_jerk_posi_explored[u])+(((pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u])+(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u]))/(2)))*q_ddot[u]*pow(dt,2)) + ((((n1_pos_jerk_posi_explored[u]*(pow(n2_pos_jerk_posi_explored[u],2)-n2_pos_jerk_posi_explored[u])+n2_pos_jerk_posi_explored[u]*(pow(n1_pos_jerk_posi_explored[u],2)-n1_pos_jerk_posi_explored[u]))/(2))+((pow(n1_pos_jerk_posi_explored[u],3)/6)-(pow(n1_pos_jerk_posi_explored[u],2)/2)+(n1_pos_jerk_posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_posi_explored[u],3)/6)-(pow(n2_pos_jerk_posi_explored[u],2)/2)+(n2_pos_jerk_posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3));

}   

  save_q_n_neg_jerk_posi_reconstr(q_n_neg_jerk_posi_reconstr);
  save_q_n_pos_jerk_posi_reconstr(q_n_pos_jerk_posi_reconstr);
  save_q_n_neg_jerk_posi_reconstr_explored(q_n_neg_jerk_posi_reconstr_explored);
  save_q_n_pos_jerk_posi_reconstr_explored(q_n_pos_jerk_posi_reconstr_explored);

  save_n1_neg_jerk_posi_explored(n1_neg_jerk_posi_explored);
  save_n1_pos_jerk_posi_explored(n1_pos_jerk_posi_explored);
  save_n2_neg_jerk_posi_explored(n2_neg_jerk_posi_explored);
  save_n2_pos_jerk_posi_explored(n2_pos_jerk_posi_explored);

  save_n1_neg_jerk_posi_explored_q(n1_neg_jerk_posi_explored_q);
  save_n1_pos_jerk_posi_explored_q(n1_pos_jerk_posi_explored_q);

  save_n2_neg_jerk_posi_explored_q(n2_neg_jerk_posi_explored_q);
  save_n2_pos_jerk_posi_explored_q(n2_pos_jerk_posi_explored_q);

  save_small_err(small_err);

//-----------Compute of "n_neg_jerk_posi" PAR EXPLORATION (COMPLETE FORMULA)-----------//














//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI TEST WORK ORIGINAL-----------------------------------------//
//int    n1_neg=3;
//int    n1_pos=3;
//int    n2_neg=0;
//int    n2_pos=0;
//double final_q_dotdot_bounds_max_comp_Jerk_Posi_0 = 4000;
//double q_dotdot_bounds_max_provizoir;
//double q_dotdot_bounds_min_provizoir;

//for(int y=0; y<200; y++){
//n2_neg=0;
//n2_pos=0;
//for(int p=0; p<100; p++){
////n2_neg=0;

///*
//  q_dotdot_bounds_max_provizoir =  (2*(q_bounds_max[0]-q[0])/((pow(n1_neg,2)-n1_neg)*pow(dt,2)))-((2*q_dot[0])/((n1_neg-1)*dt))-(((((pow(n1_neg,2))/3)-n1_neg+(2/3))*q_dddot_bounds_min[0]*dt)/(n1_neg-1));
//  q_dotdot_bounds_min_provizoir =  (2*(q_bounds_min[0]-q[0])/((pow(n1_pos,2)-n1_pos)*pow(dt,2)))-((2*q_dot[0])/((n1_pos-1)*dt))-(((((pow(n1_pos,2))/3)-n1_pos+(2/3))*q_dddot_bounds_max[0]*dt)/(n1_pos-1));  
//*/
//  q_dotdot_bounds_max_provizoir =  (q_bounds_max[0]-q[0])/((((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg)*pow(dt,2)) - (((pow(n1_neg,3)/6)-(pow(n1_neg,2)/2)+(n1_neg/3)+((n2_neg*(pow(n1_neg,2)-n1_neg))/2))*q_dddot_bounds_min[0]*dt)/(((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg) - (((pow(n2_neg,2)-n2_neg)/2)*q_dotdot_bounds_min_optimized[0])/(((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg) - ((n1_neg+n2_neg)*q_dot[0])/((((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg)*dt);
//  q_dotdot_bounds_min_provizoir =  (q_bounds_min[0]-q[0])/((((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos)*pow(dt,2)) - (((pow(n1_pos,3)/6)-(pow(n1_pos,2)/2)+(n1_pos/3)+((n2_pos*(pow(n1_pos,2)-n1_pos))/2))*q_dddot_bounds_max[0]*dt)/(((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos) - (((pow(n2_pos,2)-n2_pos)/2)*q_dotdot_bounds_max_optimized[0])/(((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos) - ((n1_pos+n2_pos)*q_dot[0])/((((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos)*dt);

//if(q_dotdot_bounds_max_provizoir < final_q_dotdot_bounds_max_comp_Jerk_Posi_0){
//final_q_dotdot_bounds_max_comp_Jerk_Posi_0 = q_dotdot_bounds_max_provizoir;

//}

//n2_neg=n2_neg+1;
//}

//n1_neg = n1_neg+1;
//}   

//q_dotdot_bounds_max_comp_Jerk_Posi(0, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi_0;
//std::cout<<"q_dotdot_bounds_max_comp_Jerk_Posi(0, 0) 55555555555555555555555555555555 : " << q_dotdot_bounds_max_comp_Jerk_Posi(0, 0) <<std::endl;
//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI TEST WORK ORIGINAL-----------------------------------------//










//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI TEST WORK ORIGINAL-----------------------------------------//

//Avant leur modification les contraintes sont égales aux valeurs max de l'opt
q_dotdot_bounds_max_comp_Jerk_Posi_acc = q_dotdot_bounds_max_optimized;
q_dotdot_bounds_min_comp_Jerk_Posi_acc = q_dotdot_bounds_min_optimized;

start_count_time = time_in_micsecond;
final_q_dotdot_bounds_max_comp_Jerk_Posi_acc <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
final_q_dotdot_bounds_min_comp_Jerk_Posi_acc << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

for(u=0; u<1; u++){ 
n1_neg = 3;
n1_pos = 3;
for(y=0; y<100; y++){        //POUR PAPIER : 1800
n2_neg = 1;
n2_pos = 1;
for(p=0; p<50; p++){        //500

q_dotdot_bounds_max_provizoir[u] =  (q_bounds_max[u]-q[u])/((((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg)*pow(dt,2)) - (((pow(n1_neg,3)/6)-(pow(n1_neg,2)/2)+(n1_neg/3)+((n2_neg*(pow(n1_neg,2)-n1_neg))/2))*q_dddot_bounds_min[u]*dt)/(((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg) - (((pow(n2_neg,2)-n2_neg)/2)*q_dotdot_bounds_min_optimized[u])/(((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg) - ((n1_neg+n2_neg)*q_dot[u])/((((pow(n1_neg,2)-n1_neg)/2)+n1_neg*n2_neg)*dt);
q_dotdot_bounds_min_provizoir[u] =  (q_bounds_min[u]-q[u])/((((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos)*pow(dt,2)) - (((pow(n1_pos,3)/6)-(pow(n1_pos,2)/2)+(n1_pos/3)+((n2_pos*(pow(n1_pos,2)-n1_pos))/2))*q_dddot_bounds_max[u]*dt)/(((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos) - (((pow(n2_pos,2)-n2_pos)/2)*q_dotdot_bounds_max_optimized[u])/(((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos) - ((n1_pos+n2_pos)*q_dot[u])/((((pow(n1_pos,2)-n1_pos)/2)+n1_pos*n2_pos)*dt);

if(q_dotdot_bounds_max_provizoir[u] < final_q_dotdot_bounds_max_comp_Jerk_Posi_acc[u]){
final_q_dotdot_bounds_max_comp_Jerk_Posi_acc[u] = q_dotdot_bounds_max_provizoir[u];
n1_neg_jerk_acc_posi[u]= n1_neg;
n2_neg_jerk_acc_posi[u]= n2_neg;
}

if(q_dotdot_bounds_min_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_Posi_acc[u]){
final_q_dotdot_bounds_min_comp_Jerk_Posi_acc[u] = q_dotdot_bounds_min_provizoir[u];
n1_pos_jerk_acc_posi[u]= n1_pos;
n2_pos_jerk_acc_posi[u]= n2_pos;
}


n2_neg=n2_neg+1;
n2_pos=n2_pos+1;
}
n1_neg = n1_neg+1;
n1_pos = n1_pos+1;
}   


/*
q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_Posi_acc[u];
q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_Posi_acc[u];
*/


  q_dotdot_bounds_comp_posi_jerk_acc_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0) - q_dotdot_bounds_max_comp_Jerk_Posi_acc_previous(u, 0))/dt;
  q_dotdot_bounds_comp_posi_jerk_acc_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0) - q_dotdot_bounds_min_comp_Jerk_Posi_acc_previous(u, 0))/dt;
/*
  if(q_dotdot_bounds_comp_posi_jerk_acc_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
     q_dotdot_bounds_max_comp_Jerk_Posi_acc[u] = q_dotdot_bounds_max_comp_Jerk_Posi_acc_previous[u] + q_dddot_bounds_max[u]*dt;
    }

  if(q_dotdot_bounds_comp_posi_jerk_acc_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
     q_dotdot_bounds_min_comp_Jerk_Posi_acc[u] = q_dotdot_bounds_min_comp_Jerk_Posi_acc_previous[u] + q_dddot_bounds_min[u]*dt;;
    }
*/

q_n_neg_jerk_acc_posi_reconstr(u, 0)         =  q[u] + ((n1_neg_jerk_acc_posi[u]+n2_neg_jerk_acc_posi[u])*q_dot[u]*dt) + ((((pow(n1_neg_jerk_acc_posi[u],2)-n1_neg_jerk_acc_posi[u])/2)+n1_neg_jerk_acc_posi[u]*n2_neg_jerk_acc_posi[u])*q_ddot[u]*pow(dt,2)) + ((((pow(n1_neg_jerk_acc_posi[u],3))/6)-((pow(n1_neg_jerk_acc_posi[u],2))/2)+((n1_neg_jerk_acc_posi[u])/3)+((n2_neg_jerk_acc_posi[u]*(pow(n1_neg_jerk_acc_posi[u],2)-n1_neg_jerk_acc_posi[u]))/2))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n2_neg_jerk_acc_posi[u],2)-n2_neg_jerk_acc_posi[u])/2)*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
q_n_pos_jerk_acc_posi_reconstr(u, 0)         =  q[u] + ((n1_pos_jerk_acc_posi[u]+n2_pos_jerk_acc_posi[u])*q_dot[u]*dt) + ((((pow(n1_pos_jerk_acc_posi[u],2)-n1_pos_jerk_acc_posi[u])/2)+n1_pos_jerk_acc_posi[u]*n2_pos_jerk_acc_posi[u])*q_ddot[u]*pow(dt,2)) + ((((pow(n1_pos_jerk_acc_posi[u],3))/6)-((pow(n1_pos_jerk_acc_posi[u],2))/2)+((n1_pos_jerk_acc_posi[u])/3)+((n2_pos_jerk_acc_posi[u]*(pow(n1_pos_jerk_acc_posi[u],2)-n1_pos_jerk_acc_posi[u]))/2))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n2_pos_jerk_acc_posi[u],2)-n2_pos_jerk_acc_posi[u])/2)*q_dotdot_bounds_max_optimized[u]*pow(dt,2));
}
  //save_q_n_neg_jerk_acc_posi_reconstr(q_n_neg_jerk_acc_posi_reconstr);
  //save_q_n_pos_jerk_acc_posi_reconstr(q_n_pos_jerk_acc_posi_reconstr);
  save_n1_pos_jerk_acc_posi(n1_pos_jerk_acc_posi);
  save_n2_pos_jerk_acc_posi(n2_pos_jerk_acc_posi);

//-----------------------------------CONSTRAINTES COMP JOINT 0 ACC JERK POSI TEST WORK ORIGINAL-----------------------------------------//






/*
for(u=0; u<7; u++){
//Calcul des n de manière différente
n_pos_jerk_posi_cmpted_dffrntly[u] = 2;
n_neg_jerk_posi_cmpted_dffrntly[u] = 2;


q_k_n_jerk_const_min[u] = q[u] + n_neg_jerk_posi_cmpted_dffrntly[u]*q_dot[u]*dt + ((pow(n_neg_jerk_posi_cmpted_dffrntly[u],2)-n_neg_jerk_posi_cmpted_dffrntly[u])/2)*q_ddot[u]*pow(dt,2);
q_k_n_jerk_const_max[u] = q[u] + n_pos_jerk_posi_cmpted_dffrntly[u]*q_dot[u]*dt + ((pow(n_pos_jerk_posi_cmpted_dffrntly[u],2)-n_pos_jerk_posi_cmpted_dffrntly[u])/2)*q_ddot[u]*pow(dt,2);

int z = 0;
while(q_k_n_jerk_const_min[u] < q_bounds_max[u]){
n_neg_jerk_posi_cmpted_dffrntly[u]  = n_neg_jerk_posi_cmpted_dffrntly[u] +1;
z = z+1;
q_k_n_jerk_const_min[u] = q[u] + n_neg_jerk_posi_cmpted_dffrntly[u]*q_dot[u]*dt + ((pow(n_neg_jerk_posi_cmpted_dffrntly[u],2)-n_neg_jerk_posi_cmpted_dffrntly[u])/2)*q_ddot[u]*pow(dt,2);

if(z>100){
break;
}
}

z = 0;

while(q_k_n_jerk_const_max[u] > q_bounds_min[u]){
n_pos_jerk_posi_cmpted_dffrntly[u]  = n_pos_jerk_posi_cmpted_dffrntly[u] +1;
z = z+1; 
q_k_n_jerk_const_max[u] = q[u] + n_pos_jerk_posi_cmpted_dffrntly[u]*q_dot[u]*dt + ((pow(n_pos_jerk_posi_cmpted_dffrntly[u],2)-n_pos_jerk_posi_cmpted_dffrntly[u])/2)*q_ddot[u]*pow(dt,2);

if(z>100){
break;
}
}

//n_pos_jerk_posi[u] = n_pos_jerk_posi_cmpted_dffrntly[u];
//n_neg_jerk_posi[u] = n_neg_jerk_posi_cmpted_dffrntly[u];

q_k_n_jerk_const_max[u] = q[u] + n_pos_jerk_posi[u]*q_dot[u]*dt + ((pow(n_pos_jerk_posi[u],2)-n_pos_jerk_posi[u])/2)*q_ddot[u]*pow(dt,2);
q_k_n_jerk_const_min[u] = q[u] + n_neg_jerk_posi[u]*q_dot[u]*dt + ((pow(n_neg_jerk_posi[u],2)-n_neg_jerk_posi[u])/2)*q_ddot[u]*pow(dt,2);

q_ddot_k_n_jerk_const_max[u]           = ((pow(n_pos_jerk_posi[u],2)-n_pos_jerk_posi[u])/2)*q_ddot[u] + ((pow(n_pos_jerk_posi[u],3)/6)-(pow(n_pos_jerk_posi[u],2)/2)+(n_pos_jerk_posi[u]/3))*q_dddot_bounds_min[u]*dt; 
q_ddot_k_n_jerk_const_min[u]           = ((pow(n_neg_jerk_posi[u],2)-n_neg_jerk_posi[u])/2)*q_ddot[u] + ((pow(n_neg_jerk_posi[u],3)/6)-(pow(n_neg_jerk_posi[u],2)/2)+(n_neg_jerk_posi[u]/3))*q_dddot_bounds_min[u]*dt;  

}

save_q_k_n_jerk_const_max(q_k_n_jerk_const_max);
save_q_k_n_jerk_const_min(q_k_n_jerk_const_min);
*/
/************************************Calcul des bounds sur q_dot_dot rendant le Jerk compatible avec les positions articulaires -3-************************************/

















/*
q_dotdot_bounds_min_optimized[0] = -2.95;
q_dotdot_bounds_max_optimized[0] = 100;
*/
//-----------Compute of "n_neg_Jerk_acc_Posi" PAR EXPLORATION (COMPLETE FRMULA)-----------//
final_q_dotdot_bounds_max_comp_Jerk_acc_Posi <<  4000000,  4000000,  4000000,  4000000,  4000000,  4000000,  4000000;
final_q_dotdot_bounds_min_comp_Jerk_acc_Posi << -4000000, -4000000, -4000000, -4000000, -4000000, -4000000, -4000000;

for(u=0; u<1; u++){ 
n1_neg_Jerk_acc_Posi_exp = 1;
n1_pos_Jerk_acc_Posi_exp = 1;
for(f=0; f<=60; f++){         //600
n2_neg_Jerk_acc_Posi_exp = 0;
n2_neg_Jerk_acc_Posi_exp = 0;
for(p=0; p<2; p++){          //1200

if(q_dot_dot_final[u]>=0){
//n3_neg_Jerk_acc_Posi_exp = round_up(n1_neg_Jerk_acc_Posi_exp - absolute(((-q_dot_dot_final[u])/(2.95q_dddot_bounds_min[u]*dt))));
n3_neg_Jerk_acc_Posi_exp = n1_neg_Jerk_acc_Posi_exp - absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_min[u]*dt)));
if(n1_neg_Jerk_acc_Posi_exp <= 1){n1_neg_Jerk_acc_Posi_exp = 1;}
if(n3_neg_Jerk_acc_Posi_exp <= 2){n3_neg_Jerk_acc_Posi_exp = 2;}
small_err = 5;
}


if(q_dot_dot_final[u]<0){
//n3_neg_Jerk_acc_Posi_exp = round_up((n1_neg_Jerk_acc_Posi_exp) + absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt))));
n3_neg_Jerk_acc_Posi_exp = (n1_neg_Jerk_acc_Posi_exp) + absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
if(n1_neg_Jerk_acc_Posi_exp <= 1){n1_neg_Jerk_acc_Posi_exp = 1;}
if(n3_neg_Jerk_acc_Posi_exp <= 2){n3_neg_Jerk_acc_Posi_exp = 2;}

if(n1_neg_Jerk_acc_Posi_exp <= 1){
//n3_neg_Jerk_acc_Posi_exp = round_up(absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt))));
n3_neg_Jerk_acc_Posi_exp = absolute(((-q_dot_dot_final[u])/(q_dddot_bounds_max[u]*dt)));
if(n1_neg_Jerk_acc_Posi_exp <= 1){n1_neg_Jerk_acc_Posi_exp = 1;}
if(n3_neg_Jerk_acc_Posi_exp <= 2){n3_neg_Jerk_acc_Posi_exp = 2;}
}
small_err = 4;
}



//V1
q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/((n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2)))*pow(dt,2)) - (((n1_neg_Jerk_acc_Posi_exp+n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dot[u]/dt)) - (((((((n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)*(pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp))+n1_neg_Jerk_acc_Posi_exp*(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))+((pow(n1_neg_Jerk_acc_Posi_exp,3)/6)-(pow(n1_neg_Jerk_acc_Posi_exp,2)/2)+(n1_neg_Jerk_acc_Posi_exp/3)))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_min[u]*dt)) - ((((pow(n3_neg_Jerk_acc_Posi_exp,3)/6)-(pow(n3_neg_Jerk_acc_Posi_exp,2)/2)+(n3_neg_Jerk_acc_Posi_exp/3))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_max[u]*dt)) - ((((n2_neg_Jerk_acc_Posi_exp*n3_neg_Jerk_acc_Posi_exp)+((pow(n2_neg_Jerk_acc_Posi_exp,2)-n2_neg_Jerk_acc_Posi_exp)/2))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dotdot_bounds_min_optimized[u]));
q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/((n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2)))*pow(dt,2)) - (((n1_pos_Jerk_acc_Posi_exp+n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dot[u]/dt)) - (((((((n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)*(pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp))+n1_pos_Jerk_acc_Posi_exp*(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))+((pow(n1_pos_Jerk_acc_Posi_exp,3)/6)-(pow(n1_pos_Jerk_acc_Posi_exp,2)/2)+(n1_pos_Jerk_acc_Posi_exp/3)))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_max[u]*dt)) - ((((pow(n3_pos_Jerk_acc_Posi_exp,3)/6)-(pow(n3_pos_Jerk_acc_Posi_exp,2)/2)+(n3_pos_Jerk_acc_Posi_exp/3))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_min[u]*dt)) - ((((n2_pos_Jerk_acc_Posi_exp*n3_pos_Jerk_acc_Posi_exp)+((pow(n2_pos_Jerk_acc_Posi_exp,2)-n2_pos_Jerk_acc_Posi_exp)/2))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dotdot_bounds_min_optimized[u]));

/*
//V2
q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/((n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2)))*pow(dt,2)) - (((n1_neg_Jerk_acc_Posi_exp+n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dot[u]/dt)) - (((((((n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)*(pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp))+n1_neg_Jerk_acc_Posi_exp*(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))+((pow(n1_neg_Jerk_acc_Posi_exp,3)/6)-(pow(n1_neg_Jerk_acc_Posi_exp,2)/2)+(n1_neg_Jerk_acc_Posi_exp/3)))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_min[u]*dt)) - ((((pow(n3_neg_Jerk_acc_Posi_exp,3)/6)-(pow(n3_neg_Jerk_acc_Posi_exp,2)/2)+(n3_neg_Jerk_acc_Posi_exp/3))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_max[u]*dt)) - ((((n2_neg_Jerk_acc_Posi_exp*n3_neg_Jerk_acc_Posi_exp)+(((pow(n2_neg_Jerk_acc_Posi_exp,2)-n2_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/2))/(n1_neg_Jerk_acc_Posi_exp*(n2_neg_Jerk_acc_Posi_exp+n3_neg_Jerk_acc_Posi_exp)+(((pow(n1_neg_Jerk_acc_Posi_exp,2)-n1_neg_Jerk_acc_Posi_exp)+(pow(n3_neg_Jerk_acc_Posi_exp,2)-n3_neg_Jerk_acc_Posi_exp))/(2))))*(q_dotdot_bounds_min_optimized[u]));
q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/((n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2)))*pow(dt,2)) - (((n1_pos_Jerk_acc_Posi_exp+n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dot[u]/dt)) - (((((((n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)*(pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp))+n1_pos_Jerk_acc_Posi_exp*(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))+((pow(n1_pos_Jerk_acc_Posi_exp,3)/6)-(pow(n1_pos_Jerk_acc_Posi_exp,2)/2)+(n1_pos_Jerk_acc_Posi_exp/3)))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_max[u]*dt)) - ((((pow(n3_pos_Jerk_acc_Posi_exp,3)/6)-(pow(n3_pos_Jerk_acc_Posi_exp,2)/2)+(n3_pos_Jerk_acc_Posi_exp/3))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dddot_bounds_min[u]*dt)) - ((((n2_pos_Jerk_acc_Posi_exp*n3_pos_Jerk_acc_Posi_exp)+(((pow(n2_pos_Jerk_acc_Posi_exp,2)-n2_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/2))/(n1_pos_Jerk_acc_Posi_exp*(n2_pos_Jerk_acc_Posi_exp+n3_pos_Jerk_acc_Posi_exp)+(((pow(n1_pos_Jerk_acc_Posi_exp,2)-n1_pos_Jerk_acc_Posi_exp)+(pow(n3_pos_Jerk_acc_Posi_exp,2)-n3_pos_Jerk_acc_Posi_exp))/(2))))*(q_dotdot_bounds_max_optimized[u]));
*/

if(q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u] <= final_q_dotdot_bounds_max_comp_Jerk_acc_Posi[u]){
final_q_dotdot_bounds_max_comp_Jerk_acc_Posi[u] = q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u];
n1_neg_Jerk_acc_Posi_explored[u] = n1_neg_Jerk_acc_Posi_exp;
n2_neg_Jerk_acc_Posi_explored[u] = n2_neg_Jerk_acc_Posi_exp;
n3_neg_Jerk_acc_Posi_explored[u] = n3_neg_Jerk_acc_Posi_exp;
q_n_neg_Jerk_acc_Posi_reconstr(u, 0) = q[u] + ((n1_neg_Jerk_acc_Posi_explored[u]+n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])*q_dot[u]*dt) + (((n1_neg_Jerk_acc_Posi_explored[u]*(n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u]))+(((pow(n1_neg_Jerk_acc_Posi_explored[u],2)-n1_neg_Jerk_acc_Posi_explored[u])+(pow(n3_neg_Jerk_acc_Posi_explored[u],2)-n3_neg_Jerk_acc_Posi_explored[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])*(pow(n1_neg_Jerk_acc_Posi_explored[u],2)-n1_neg_Jerk_acc_Posi_explored[u])+n1_neg_Jerk_acc_Posi_explored[u]*(pow(n3_neg_Jerk_acc_Posi_explored[u],2)-n3_neg_Jerk_acc_Posi_explored[u]))/2)+((pow(n1_neg_Jerk_acc_Posi_explored[u],3)/6)-(pow(n1_neg_Jerk_acc_Posi_explored[u],2)/2)+(n1_neg_Jerk_acc_Posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n3_neg_Jerk_acc_Posi_explored[u],3)/6)-(pow(n3_neg_Jerk_acc_Posi_explored[u],2)/2)+(n3_neg_Jerk_acc_Posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3)) + (((n2_neg_Jerk_acc_Posi_explored[u]*n3_neg_Jerk_acc_Posi_explored[u])+((pow(n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u],2)-n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])/2))*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
}

if(q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u] > final_q_dotdot_bounds_min_comp_Jerk_acc_Posi[u]){
final_q_dotdot_bounds_min_comp_Jerk_acc_Posi[u] = -100;
n1_pos_Jerk_acc_Posi_explored[u] = n1_pos_Jerk_acc_Posi_exp;
n2_pos_Jerk_acc_Posi_explored[u] = n2_pos_Jerk_acc_Posi_exp;
n3_pos_Jerk_acc_Posi_explored[u] = n3_pos_Jerk_acc_Posi_exp;
q_n_pos_Jerk_acc_Posi_reconstr(u, 0) = q[u] + ((n1_pos_Jerk_acc_Posi_explored[u]+n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])*q_dot[u]*dt) + (((n1_pos_Jerk_acc_Posi_explored[u]*(n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u]))+(((pow(n1_pos_Jerk_acc_Posi_explored[u],2)-n1_pos_Jerk_acc_Posi_explored[u])+(pow(n3_pos_Jerk_acc_Posi_explored[u],2)-n3_pos_Jerk_acc_Posi_explored[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])*(pow(n1_pos_Jerk_acc_Posi_explored[u],2)-n1_pos_Jerk_acc_Posi_explored[u])+n1_pos_Jerk_acc_Posi_explored[u]*(pow(n3_pos_Jerk_acc_Posi_explored[u],2)-n3_pos_Jerk_acc_Posi_explored[u]))/2)+((pow(n1_pos_Jerk_acc_Posi_explored[u],3)/6)-(pow(n1_pos_Jerk_acc_Posi_explored[u],2)/2)+(n1_pos_Jerk_acc_Posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n3_pos_Jerk_acc_Posi_explored[u],3)/6)-(pow(n3_pos_Jerk_acc_Posi_explored[u],2)/2)+(n3_pos_Jerk_acc_Posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3)) + (((n2_pos_Jerk_acc_Posi_explored[u]*n3_pos_Jerk_acc_Posi_explored[u])+((pow(n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u],2)-n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])/2))*q_dotdot_bounds_max_optimized[u]*pow(dt,2));
}



//q_n_neg_Jerk_acc_Posi_reconstr(u, 0) = q[u] + ((n1_neg_Jerk_acc_Posi_explored[u]+n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])*q_dot[u]*dt) + (((n1_neg_Jerk_acc_Posi_explored[u]*(n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u]))+(((pow(n1_neg_Jerk_acc_Posi_explored[u],2)-n1_neg_Jerk_acc_Posi_explored[u])+(pow(n3_neg_Jerk_acc_Posi_explored[u],2)-n3_neg_Jerk_acc_Posi_explored[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])*(pow(n1_neg_Jerk_acc_Posi_explored[u],2)-n1_neg_Jerk_acc_Posi_explored[u])+n1_neg_Jerk_acc_Posi_explored[u]*(pow(n3_neg_Jerk_acc_Posi_explored[u],2)-n3_neg_Jerk_acc_Posi_explored[u]))/2)+((pow(n1_neg_Jerk_acc_Posi_explored[u],3)/6)-(pow(n1_neg_Jerk_acc_Posi_explored[u],2)/2)+(n1_neg_Jerk_acc_Posi_explored[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n3_neg_Jerk_acc_Posi_explored[u],3)/6)-(pow(n3_neg_Jerk_acc_Posi_explored[u],2)/2)+(n3_neg_Jerk_acc_Posi_explored[u]/3))*q_dddot_bounds_max[u]*pow(dt,3)) + (((n2_neg_Jerk_acc_Posi_explored[u]*n3_neg_Jerk_acc_Posi_explored[u])+((pow(n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u],2)-n2_neg_Jerk_acc_Posi_explored[u]+n3_neg_Jerk_acc_Posi_explored[u])/2))*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
//q_n_pos_Jerk_acc_Posi_reconstr(u, 0) = q[u] + ((n1_pos_Jerk_acc_Posi_explored[u]+n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])*q_dot[u]*dt) + (((n1_pos_Jerk_acc_Posi_explored[u]*(n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u]))+(((pow(n1_pos_Jerk_acc_Posi_explored[u],2)-n1_pos_Jerk_acc_Posi_explored[u])+(pow(n3_pos_Jerk_acc_Posi_explored[u],2)-n3_pos_Jerk_acc_Posi_explored[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])*(pow(n1_pos_Jerk_acc_Posi_explored[u],2)-n1_pos_Jerk_acc_Posi_explored[u])+n1_pos_Jerk_acc_Posi_explored[u]*(pow(n3_pos_Jerk_acc_Posi_explored[u],2)-n3_pos_Jerk_acc_Posi_explored[u]))/2)+((pow(n1_pos_Jerk_acc_Posi_explored[u],3)/6)-(pow(n1_pos_Jerk_acc_Posi_explored[u],2)/2)+(n1_pos_Jerk_acc_Posi_explored[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n3_pos_Jerk_acc_Posi_explored[u],3)/6)-(pow(n3_pos_Jerk_acc_Posi_explored[u],2)/2)+(n3_pos_Jerk_acc_Posi_explored[u]/3))*q_dddot_bounds_min[u]*pow(dt,3)) + (((n2_pos_Jerk_acc_Posi_explored[u]*n3_pos_Jerk_acc_Posi_explored[u])+((pow(n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u],2)-n2_pos_Jerk_acc_Posi_explored[u]+n3_pos_Jerk_acc_Posi_explored[u])/2))*q_dotdot_bounds_max_optimized[u]*pow(dt,2));


  if(absolute(q_bounds_max[u] - q_n_neg_Jerk_acc_Posi_reconstr(u, 0)) < 0.001){ 
     //q_n_neg_Jerk_acc_Posi_reconstr_explored(u, 0) = q_n_neg_Jerk_acc_Posi_reconstr(u, 0);
     n1_neg_Jerk_acc_Posi_explored_q[u] = n1_neg_Jerk_acc_Posi_exp;
     n2_neg_Jerk_acc_Posi_explored_q[u] = n2_neg_Jerk_acc_Posi_exp;
     n3_neg_Jerk_acc_Posi_explored_q[u] = n3_neg_Jerk_acc_Posi_exp;
     //q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_max[u]-q[u])/(((n1_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])*q_dot[u])/(((n1_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/(2)))*dt) - ((((n1_neg_Jerk_acc_Posi_explored_q[u]*(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u])+n3_neg_Jerk_acc_Posi_explored_q[u]*(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u]))/(2))+((pow(n1_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n1_neg_Jerk_acc_Posi_explored_q[u]/3)))*q_dddot_bounds_min[u]*dt)/(((n1_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/(2)))) - (((pow(n3_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n3_neg_Jerk_acc_Posi_explored_q[u]/3))*q_dddot_bounds_max[u]*dt)/(((n1_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/(2))));
     //final_q_dotdot_bounds_max_comp_Jerk_acc_Posi[u] = q_dotdot_bounds_max_comp_Jerk_acc_Posi_provizoir[u];
     }


  if(absolute(q_n_pos_Jerk_acc_Posi_reconstr(u, 0) - q_bounds_min[u]) < 0.001){ 
     //q_n_pos_Jerk_acc_Posi_reconstr_explored(u, 0) = q_n_pos_Jerk_acc_Posi_reconstr(u, 0);
     n1_pos_Jerk_acc_Posi_explored_q[u] = n1_pos_Jerk_acc_Posi_exp;
     n2_pos_Jerk_acc_Posi_explored_q[u] = n2_pos_Jerk_acc_Posi_exp;
     n3_pos_Jerk_acc_Posi_explored_q[u] = n3_pos_Jerk_acc_Posi_exp;
     //q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u] = -100;
     //q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u] = (q_bounds_min[u]-q[u])/(((n1_pos_Jerk_acc_Posi_explored_q[u]*n3_pos_Jerk_acc_Posi_explored_q[u])+(((pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/(2)))*pow(dt,2)) - ((n1_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u])*q_dot[u])/(((n1_pos_Jerk_acc_Posi_explored_q[u]*n3_pos_Jerk_acc_Posi_explored_q[u])+(((pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/(2)))*dt) - ((((n1_pos_Jerk_acc_Posi_explored_q[u]*(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u])+n3_pos_Jerk_acc_Posi_explored_q[u]*(pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u]))/(2))+((pow(n1_pos_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)/2)+(n1_pos_Jerk_acc_Posi_explored_q[u]/3)))*q_dddot_bounds_max[u]*dt)/(((n1_pos_Jerk_acc_Posi_explored_q[u]*n3_pos_Jerk_acc_Posi_explored_q[u])+(((pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/(2)))) - (((pow(n3_pos_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)/2)+(n3_pos_Jerk_acc_Posi_explored_q[u]/3))*q_dddot_bounds_min[u]*dt)/(((n1_pos_Jerk_acc_Posi_explored_q[u]*n3_pos_Jerk_acc_Posi_explored_q[u])+(((pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/(2))));
     //final_q_dotdot_bounds_min_comp_Jerk_acc_Posi[u] = q_dotdot_bounds_min_comp_Jerk_acc_Posi_provizoir[u];
    }


n2_neg_Jerk_acc_Posi_exp++;
n2_pos_Jerk_acc_Posi_exp++;
}
n1_neg_Jerk_acc_Posi_exp++;
n1_pos_Jerk_acc_Posi_exp++;
}

//

q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0) = final_q_dotdot_bounds_max_comp_Jerk_acc_Posi[u];
q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0) = final_q_dotdot_bounds_min_comp_Jerk_acc_Posi[u];



  q_dotdot_bounds_comp_posi_jerk_deriv_max[u] = (q_dotdot_bounds_max_comp_Jerk_acc_Posi[u] - q_dotdot_bounds_max_comp_Jerk_acc_Posi_previous[u])/dt;
  q_dotdot_bounds_comp_posi_jerk_deriv_min[u] = (q_dotdot_bounds_min_comp_Jerk_acc_Posi[u] - q_dotdot_bounds_min_comp_Jerk_acc_Posi_previous[u])/dt;

/*
  if(q_dotdot_bounds_comp_posi_jerk_deriv_max[u] >= q_dddot_bounds_max[u] && steps_counter >= 2){
     q_dotdot_bounds_max_comp_Jerk_acc_Posi[u] = q_dotdot_bounds_max_comp_Jerk_acc_Posi_previous[u] + q_dddot_bounds_max[u]*dt;
    }

  if(q_dotdot_bounds_comp_posi_jerk_deriv_min[u] <= q_dddot_bounds_min[u]  && steps_counter >= 2){
     q_dotdot_bounds_min_comp_Jerk_acc_Posi[u] = q_dotdot_bounds_min_comp_Jerk_acc_Posi_previous[u] + q_dddot_bounds_min[u]*dt;;
    }
*/
q_n_neg_Jerk_acc_Posi_reconstr_explored(u, 0) = q[u] + ((n1_neg_Jerk_acc_Posi_explored_q[u]+n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])*q_dot[u]*dt) + (((n1_neg_Jerk_acc_Posi_explored_q[u]*(n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u]))+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])*(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+n1_neg_Jerk_acc_Posi_explored_q[u]*(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/2)+((pow(n1_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n1_neg_Jerk_acc_Posi_explored_q[u]/3)))*q_dddot_bounds_min[u]*pow(dt,3)) + (((pow(n3_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n3_neg_Jerk_acc_Posi_explored_q[u]/3))*q_dddot_bounds_max[u]*pow(dt,3)) + (((n2_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+((pow(n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u],2)-n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])/2))*q_dotdot_bounds_min_optimized[u]*pow(dt,2));
q_n_pos_Jerk_acc_Posi_reconstr_explored(u, 0) = q[u] + ((n1_pos_Jerk_acc_Posi_explored_q[u]+n2_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u])*q_dot[u]*dt) + (((n1_pos_Jerk_acc_Posi_explored_q[u]*(n2_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u]))+(((pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/2))*q_dot_dot_final[u]*pow(dt,2)) + (((((n2_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u])*(pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)-n1_pos_Jerk_acc_Posi_explored_q[u])+n1_pos_Jerk_acc_Posi_explored_q[u]*(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)-n3_pos_Jerk_acc_Posi_explored_q[u]))/2)+((pow(n1_pos_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n1_pos_Jerk_acc_Posi_explored_q[u],2)/2)+(n1_pos_Jerk_acc_Posi_explored_q[u]/3)))*q_dddot_bounds_max[u]*pow(dt,3)) + (((pow(n3_pos_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n3_pos_Jerk_acc_Posi_explored_q[u],2)/2)+(n3_pos_Jerk_acc_Posi_explored_q[u]/3))*q_dddot_bounds_min[u]*pow(dt,3)) + (((n2_pos_Jerk_acc_Posi_explored_q[u]*n3_pos_Jerk_acc_Posi_explored_q[u])+((pow(n2_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u],2)-n2_pos_Jerk_acc_Posi_explored_q[u]+n3_pos_Jerk_acc_Posi_explored_q[u])/2))*q_dotdot_bounds_max_optimized[u]*pow(dt,2));

/*
G: ((n1_neg_Jerk_acc_Posi_explored_q[u]*(n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u]))+(((pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/2))
A: (n1_neg_Jerk_acc_Posi_explored_q[u]+n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])
B: ((((n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])*(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)-n1_neg_Jerk_acc_Posi_explored_q[u])+n1_neg_Jerk_acc_Posi_explored_q[u]*(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)-n3_neg_Jerk_acc_Posi_explored_q[u]))/2)+((pow(n1_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n1_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n1_neg_Jerk_acc_Posi_explored_q[u]/3)))
C: ((pow(n3_neg_Jerk_acc_Posi_explored_q[u],3)/6)-(pow(n3_neg_Jerk_acc_Posi_explored_q[u],2)/2)+(n3_neg_Jerk_acc_Posi_explored_q[u]/3))
D: ((n2_neg_Jerk_acc_Posi_explored_q[u]*n3_neg_Jerk_acc_Posi_explored_q[u])+((pow(n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u],2)-n2_neg_Jerk_acc_Posi_explored_q[u]+n3_neg_Jerk_acc_Posi_explored_q[u])/2))
*/

}   

if(n1_neg_Jerk_acc_Posi_explored[0] == 1){
n1_neg_Jerk_acc_Posi_explored_deja_1 = 1;
}
 save_q_n_neg_jerk_acc_posi_reconstr(q_n_neg_Jerk_acc_Posi_reconstr);
 save_q_n_pos_jerk_acc_posi_reconstr(q_n_pos_Jerk_acc_Posi_reconstr);
 save_q_n_neg_Jerk_acc_Posi_reconstr_explored(q_n_neg_Jerk_acc_Posi_reconstr_explored);
 save_q_n_pos_Jerk_acc_Posi_reconstr_explored(q_n_pos_Jerk_acc_Posi_reconstr_explored);
 save_n1_neg_Jerk_acc_Posi_explored(n1_neg_Jerk_acc_Posi_explored);
 save_n1_pos_Jerk_acc_Posi_explored(n1_pos_Jerk_acc_Posi_explored);
 save_n2_neg_Jerk_acc_Posi_explored(n2_neg_Jerk_acc_Posi_explored);
 save_n2_pos_Jerk_acc_Posi_explored(n2_pos_Jerk_acc_Posi_explored);
 save_n3_neg_Jerk_acc_Posi_explored(n3_neg_Jerk_acc_Posi_explored);
 save_n3_pos_Jerk_acc_Posi_explored(n3_pos_Jerk_acc_Posi_explored);
 save_n1_neg_Jerk_acc_Posi_explored_q(n1_neg_Jerk_acc_Posi_explored_q);
 save_n1_pos_Jerk_acc_Posi_explored_q(n1_pos_Jerk_acc_Posi_explored_q);
 save_n2_neg_Jerk_acc_Posi_explored_q(n2_neg_Jerk_acc_Posi_explored_q);
 save_n2_pos_Jerk_acc_Posi_explored_q(n2_pos_Jerk_acc_Posi_explored_q);
 save_n3_neg_Jerk_acc_Posi_explored_q(n3_neg_Jerk_acc_Posi_explored_q);
 save_n3_pos_Jerk_acc_Posi_explored_q(n3_pos_Jerk_acc_Posi_explored_q);


  save_small_err(small_err);

//-----------Compute of "n_neg_Jerk_acc_Posi" PAR EXPLORATION (COMPLETE FORMULA)-----------//
/*
q_dotdot_bounds_min_optimized[0] = -3;
q_dotdot_bounds_max_optimized[0] =  100;
*/









/************************************Choix des valeurs min et max des bounds sur q_dot_dot calculés************************************/
/*
//Classic formulation for constraints on q and q_dot
for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max(u, 0);
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min(u, 0);
}
*/



/*
//Max/min producible q_ddots
for(u=0; u<7; u++){
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_optimized[u];
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_optimized[u];
}
*/


/*
//Posi comp with Acc
for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Acc_Posi[u]; 
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Acc_Posi[u];

}
save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));
*/







/*
//Jerk comp with Vel
for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Jerk_Vel[u]; 
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Jerk_Vel[u]; 

q_dotdot_bounds_deriv_max_comp(u, 0) = (q_dotdot_bounds_max_comp_Jerk_Vel(u, 0) - q_dotdot_bounds_max_comp_Jerk_Vel_previous(u, 0))/dt;
q_dotdot_bounds_deriv_min_comp(u, 0) = (q_dotdot_bounds_min_comp_Jerk_Vel(u, 0) - q_dotdot_bounds_min_comp_Jerk_Vel_previous(u, 0))/dt;
}


save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));

save_q_dotdot_bounds_deriv_max_comp(q_dotdot_bounds_deriv_max_comp);
save_q_dotdot_bounds_deriv_min_comp(q_dotdot_bounds_deriv_min_comp);

for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp_Jerk_Vel_previous(u, 0) = q_dotdot_bounds_max_comp_Jerk_Vel(u, 0);
q_dotdot_bounds_min_comp_Jerk_Vel_previous(u, 0) = q_dotdot_bounds_min_comp_Jerk_Vel(u, 0);
}
*/






/*
//Comp "Posi & Jerk" 
for(u=0; u<1; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi(u, 0); //Choose the max value of the three
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi(u, 0); //Choose the min value of the three

q_dotdot_bounds_deriv_max_comp(u, 0) = (q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0))/dt;
q_dotdot_bounds_deriv_min_comp(u, 0) = (q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0))/dt;
}

save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));

save_q_dotdot_bounds_deriv_max_comp(q_dotdot_bounds_deriv_max_comp);
save_q_dotdot_bounds_deriv_min_comp(q_dotdot_bounds_deriv_min_comp);

for(u=0; u<1; u++){ 
q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi(u, 0);
q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi(u, 0);
}
*/






/*
//Comp "Posi Jerk et Acc"
for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0); //Choose the max value of the three
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0); //Choose the min value of the three

q_dotdot_bounds_deriv_max_comp(u, 0) = (q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0) - q_dotdot_bounds_max_comp_Jerk_Posi_acc_previous(u, 0))/dt;
q_dotdot_bounds_deriv_min_comp(u, 0) = (q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0) - q_dotdot_bounds_min_comp_Jerk_Posi_acc_previous(u, 0))/dt;
}

save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));

save_q_dotdot_bounds_deriv_max_comp(q_dotdot_bounds_deriv_max_comp);
save_q_dotdot_bounds_deriv_min_comp(q_dotdot_bounds_deriv_min_comp);

for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp_Jerk_Posi_acc_previous(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0);
q_dotdot_bounds_min_comp_Jerk_Posi_acc_previous(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0);
}
*/






//FULL CONSTRAINTS ON EVERYTHING
for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_optimized[u];
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_optimized[u];
}

////Comp Posi Jerk et Acc avec Vel et Jerk
//for(u=0; u<1; u++){ 
// 
//q_dotdot_bounds_finals         = choose_q_ddot_final_bounds_2(u, q_dot[u], q_dotdot_bounds_max_comp_Jerk_Posi(u, 0), q_dotdot_bounds_min_comp_Jerk_Posi(u, 0), q_dotdot_bounds_max_comp_Jerk_Vel[u], q_dotdot_bounds_min_comp_Jerk_Vel[u], q_dotdot_bounds_max_optimized[u], q_dotdot_bounds_min_optimized[u]); //Choose the max value of the three
////q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_finals[0];
////q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_finals[1];



//if((absolute(q_dotdot_bounds_finals[0]) - absolute(q_ddot[u])) < 10){
//q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_finals[0];
//}

//if((absolute(q_dotdot_bounds_finals[1]) - absolute(q_ddot[u])) < 10){
//q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_finals[1];
//}


//q_dotdot_bounds_deriv_max_comp(u, 0) = (q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0))/dt;
//q_dotdot_bounds_deriv_min_comp(u, 0) = (q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0))/dt;
//}

save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));

save_q_dotdot_bounds_deriv_max_comp(q_dotdot_bounds_deriv_max_comp);
save_q_dotdot_bounds_deriv_min_comp(q_dotdot_bounds_deriv_min_comp);

for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi(u, 0);
q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi(u, 0);
}










//Compute final bounds 
//FULL CONSTRAINTS ON EVERYTHING

/*
//Comp Posi Jerk et Acc avec Vel et Jerk
for(u=0; u<1; u++){ 

q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_optimized[u];
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_optimized[u];


////q_dotdot_bounds_finals         = choose_q_ddot_final_bounds_2(u, q_dot[u], q_dotdot_bounds_max_comp_Jerk_Posi(u, 0), q_dotdot_bounds_min_comp_Jerk_Posi(u, 0), q_dotdot_bounds_max_comp_Jerk_Vel[u],         q_dotdot_bounds_min_comp_Jerk_Vel[u],         q_dotdot_bounds_max_optimized[u], q_dotdot_bounds_min_optimized[u]); //Choose the max value of the three
//q_dotdot_bounds_finals           = choose_q_ddot_final_bounds_2(u, q_dot[u], q_dotdot_bounds_max_comp_Jerk_Vel[u],    q_dotdot_bounds_max_comp_Jerk_Vel[u],      q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0), q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0), q_dotdot_bounds_max_optimized[u], q_dotdot_bounds_min_optimized[u]); //Choose the max value of the three
////q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_finals[0];
////q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_finals[1];
//if((absolute(q_dotdot_bounds_finals[0]) - absolute(q_ddot[u])) < 1){
//q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_finals[0];
//}
//if((absolute(q_dotdot_bounds_finals[1]) - absolute(q_ddot[u])) < 1){
//q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_finals[1];
//}





//q_dotdot_bounds_max_comp(u, 0) = minimum(q_dotdot_bounds_max_comp_Jerk_Vel[u], q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0));
//q_dotdot_bounds_min_comp(u, 0) = maximum(q_dotdot_bounds_min_comp_Jerk_Vel[u], q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0));

//q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0);
//q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0);

//q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_max_comp_Jerk_Vel[u];
//q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_min_comp_Jerk_Vel[u];

q_dotdot_bounds_finals[0] = min_value_3(q_dotdot_bounds_max_comp_Jerk_Vel[u], q_dotdot_bounds_max_comp_Jerk_Posi_acc(u, 0), q_dotdot_bounds_max_optimized[u]);
q_dotdot_bounds_finals[1] = max_value_3(q_dotdot_bounds_min_comp_Jerk_Vel[u], q_dotdot_bounds_min_comp_Jerk_Posi_acc(u, 0), q_dotdot_bounds_min_optimized[u]);

if((absolute(q_dotdot_bounds_finals[0]) - absolute(q_ddot[u])) < 1){
q_dotdot_bounds_max_comp(u, 0) = q_dotdot_bounds_finals[0];
}
if((absolute(q_dotdot_bounds_finals[1]) - absolute(q_ddot[u])) < 1){
q_dotdot_bounds_min_comp(u, 0) = q_dotdot_bounds_finals[1];
}


q_dotdot_bounds_deriv_max_comp(u, 0) = (q_dotdot_bounds_max_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0))/dt;
q_dotdot_bounds_deriv_min_comp(u, 0) = (q_dotdot_bounds_min_comp_Jerk_Posi(u, 0) - q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0))/dt;
}

save_q_dotdot_bounds_max_comp_0(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_bounds_min_comp_0(q_dotdot_bounds_min_comp(0, 0));

save_q_dotdot_bounds_deriv_max_comp(q_dotdot_bounds_deriv_max_comp);
save_q_dotdot_bounds_deriv_min_comp(q_dotdot_bounds_deriv_min_comp);

for(u=0; u<7; u++){ 
q_dotdot_bounds_max_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_max_comp_Jerk_Posi(u, 0);
q_dotdot_bounds_min_comp_Jerk_Posi_previous(u, 0) = q_dotdot_bounds_min_comp_Jerk_Posi(u, 0);
}
*/


/************************************Choix des valeurs min et max des bounds sur q_dot_dot calculés************************************/








//---------------------------------------------------------------Create the environment and the variables------------------------------------------//
  GRBEnv env = GRBEnv();
  GRBModel model = GRBModel(env);

  // Create variables
  int cols = 7; //Nombre de variables

  /* Add variables to the model */
  GRBVar* vars = model.addVars(14, GRB_CONTINUOUS);

  vars[0] = model.addVar(tau_min(0, 0), tau_max(0, 0), 0.0, GRB_CONTINUOUS, "tau_0");
  vars[1] = model.addVar(tau_min(1, 0), tau_max(1, 0), 0.0, GRB_CONTINUOUS, "tau_1");
  vars[2] = model.addVar(tau_min(2, 0), tau_max(2, 0), 0.0, GRB_CONTINUOUS, "tau_2");
  vars[3] = model.addVar(tau_min(3, 0), tau_max(3, 0), 0.0, GRB_CONTINUOUS, "tau_3");
  vars[4] = model.addVar(tau_min(4, 0), tau_max(4, 0), 0.0, GRB_CONTINUOUS, "tau_4");
  vars[5] = model.addVar(tau_min(5, 0), tau_max(5, 0), 0.0, GRB_CONTINUOUS, "tau_5");
  vars[6] = model.addVar(tau_min(6, 0), tau_max(6, 0), 0.0, GRB_CONTINUOUS, "tau_6");


/*
  vars[7]  = model.addVar(q_dotdot_bounds_min_comp(0, 0), q_dotdot_bounds_max_comp(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(q_dotdot_bounds_min(1, 0), q_dotdot_bounds_max(1, 0), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(q_dotdot_bounds_min(2, 0), q_dotdot_bounds_max(2, 0), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(q_dotdot_bounds_min(3, 0), q_dotdot_bounds_max(3, 0), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(q_dotdot_bounds_min(4, 0), q_dotdot_bounds_max(4, 0), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(q_dotdot_bounds_min(5, 0), q_dotdot_bounds_max(5, 0), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(q_dotdot_bounds_min(6, 0), q_dotdot_bounds_max(6, 0), 0.0, GRB_CONTINUOUS, "q_dd_6");
*/

/*
  vars[7]  = model.addVar(q_dotdot_bounds_min_comp(0, 0), q_dotdot_bounds_max_comp(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(q_dotdot_bounds_min_comp(1, 0), q_dotdot_bounds_max_comp(1, 0), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(q_dotdot_bounds_min_comp(2, 0), q_dotdot_bounds_max_comp(2, 0), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(q_dotdot_bounds_min_comp(3, 0), q_dotdot_bounds_max_comp(3, 0), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(q_dotdot_bounds_min_comp(4, 0), q_dotdot_bounds_max_comp(4, 0), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(q_dotdot_bounds_min_comp(5, 0), q_dotdot_bounds_max_comp(5, 0), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(q_dotdot_bounds_min_comp(6, 0), q_dotdot_bounds_max_comp(6, 0), 0.0, GRB_CONTINUOUS, "q_dd_6");
*/



  vars[7]  = model.addVar(q_dotdot_bounds_min_optimized(0, 0), q_dotdot_bounds_max_optimized(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  //vars[7]  = model.addVar(q_dotdot_bounds_min_comp(0, 0), q_dotdot_bounds_max_comp(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(q_dotdot_bounds_min_optimized(1, 0), q_dotdot_bounds_max_optimized(1, 0), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(q_dotdot_bounds_min_optimized(2, 0), q_dotdot_bounds_max_optimized(2, 0), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(q_dotdot_bounds_min_optimized(3, 0), q_dotdot_bounds_max_optimized(3, 0), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(q_dotdot_bounds_min_optimized(4, 0), q_dotdot_bounds_max_optimized(4, 0), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(q_dotdot_bounds_min_optimized(5, 0), q_dotdot_bounds_max_optimized(5, 0), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(q_dotdot_bounds_min_optimized(6, 0), q_dotdot_bounds_max_optimized(6, 0), 0.0, GRB_CONTINUOUS, "q_dd_6");



/*
  vars[7]  = model.addVar(q_dotdot_bounds_min_comp_full(0, 0), q_dotdot_bounds_max_comp_full(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(q_dotdot_bounds_min_comp_full(1, 0), q_dotdot_bounds_max_comp_full(1, 0), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(q_dotdot_bounds_min_comp_full(2, 0), q_dotdot_bounds_max_comp_full(2, 0), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(q_dotdot_bounds_min_comp_full(3, 0), q_dotdot_bounds_max_comp_full(3, 0), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(q_dotdot_bounds_min_comp_full(4, 0), q_dotdot_bounds_max_comp_full(4, 0), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(q_dotdot_bounds_min_comp_full(5, 0), q_dotdot_bounds_max_comp_full(5, 0), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(q_dotdot_bounds_min_comp_full(6, 0), q_dotdot_bounds_max_comp_full(6, 0), 0.0, GRB_CONTINUOUS, "q_dd_6");
*/

/*
  vars[7]  = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(0, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(0, 0), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(1, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(1, 0), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(2, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(2, 0), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(3, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(3, 0), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(4, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(4, 0), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(5, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(5, 0), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(q_dotdot_bounds_min_prime_forwrd_backwrd(6, 0), q_dotdot_bounds_max_prime_forwrd_backwrd(6, 0), 0.0, GRB_CONTINUOUS, "q_dd_6");
*/
  model.update();
     

  int i, j;
//---------------------------------------------------------------Create the environment and the variables------------------------------------------//







//--------------------------------------------------------------------Construction de la fonction objectif-----------------------------------------//
    //La fonction objectif est de la forme : f(tau)   = tau.tranpose() * Q * tau + (2 * t.transpose() * J_70_l * M_inv) * tau + t.transpose() * t;
    //                                       With : Q = (J_70_l * M_inv).transpose() * (J_70_l * M_inv)
    //                                              t = (Jdot_qdot_l - (J_70_l * M_inv * b)) - X_dotdot_des


Eigen::Matrix<double, 7, 7> Q_I           = Eigen::MatrixXd::Identity(7,7);
Eigen::Matrix<double, 7, 7> Q_epsilon_qdd = epsilon_q_dot_dot * Q_I;
Eigen::Matrix<double, 7, 7> Q_epsilon_tau = epsilon_tau * Q_I;
Eigen::Matrix<double, 7, 7> Q_total;

/*
Eigen::Matrix<double, 7, 7> W;         //Matrice de poids pour le lissage des sortie du QP
double E_nrml_dist_to_Emax;
dist_to_cnstr = Ec_max_7 - E_7_reconstructed_with_V_7_t2;
double alpha = compute_jerk_pond(dist_07_nrst_ob, d_safe, d_thres);

W << alpha,   0,     0,     0,     0,     0,     0, 
       0,   alpha,   0,     0,     0,     0,     0, 
       0,     0,   alpha,   0,     0,     0,     0,
       0,     0,     0,   alpha,   0,     0,     0, 
       0,     0,     0,     0,   alpha,   0,     0,
       0,     0,     0,     0,     0,   alpha,   0,
       0,     0,     0,     0,     0,     0,   alpha;   
*/

    kp = 400;     //400 c'est excellent
    kd = 2*sqrt(kp);
    //kd = 2*sqrt(kp);
    kp_rot = 85;         //85
    kd_rot = 2*sqrt(kp_rot);  

    kp_q = 150;
    kd_q = 2*sqrt(kp_q);












//-------------------------------------------------------------------- Xdotdot-Xdotdot_ddes -----------------------------------------//
    Eigen::Matrix<double, 6, 7> J_7_mixed_by_M_inv;
    Eigen::Matrix<double, 6, 7> J_7_mixed;
    J_7_mixed << J_77_r, J_70_l;
    J_7_mixed_dot = derive(J_7_mixed, J_7_mixed_previous, 0.001); 
    J_7_mixed_by_M_inv = J_7_mixed * M_inv;  


    Eigen::Matrix<double, 7, 7> Q_tau;          				  //Matrice Q de la fonction objectif
    Q_tau = J_7_mixed_by_M_inv.transpose() * J_7_mixed_by_M_inv;

    Q_total = Q_tau + Q_epsilon_qdd + Q_epsilon_tau;

    Acc_7_des_rot_posi << Acc_7_orient_des(0),        Acc_7_orient_des(1),        Acc_7_orient_des(2),       Acc_7_des(0), Acc_7_des(1), Acc_7_des(2);
    X_err_rot_posi     << kp_rot*X_err_angle_prj(0),  kp_rot*X_err_angle_prj(1),  kp_rot*X_err_angle_prj(2), kp*X_err(0),  kp*X_err(1),  kp*X_err(2);
    V_err_rot_posi     << kd_rot*V_err_angle_prj(0),  kd_rot*V_err_angle_prj(1),  kd_rot*V_err_angle_prj(2), kd*V_err(0),  kd*V_err(1),  kd*V_err(2);

    X_dot_dot_des_rot_posi = Acc_7_des_rot_posi + X_err_rot_posi + V_err_rot_posi;
    X_dot_dot_des_rot_posi_lin_Ep << (Acc_7_des(0) + 0.5*kp*X_err(0) + kd*V_err(0)),  (Acc_7_des(1) + 0.5*kp*X_err(1) + kd*V_err(0)),  (Acc_7_des(2) + 0.5*kp*X_err(2) + kd*V_err(2)); 

    Eigen::Matrix<double, 6, 1> Jdot_qdot_mixed;
    Jdot_qdot_mixed << Jdot_qdot_r_77, Jdot_qdot_l;
              				  
    t_tau =  (Jdot_qdot_mixed - (J_7_mixed_by_M_inv * b)) - X_dot_dot_des_rot_posi;  		  //3*1

    Eigen::Matrix<double, 1, 7> b_tau;  
    Eigen::Matrix<double, 1, 7> b_q_ddot_q;                  			  //Matrice c de la partie linéaire de la fonction objectif
    b_tau = 2 * t_tau.transpose() * J_7_mixed_by_M_inv;
/*
   //Ecriture de la fonction quadratique de l'objectif pour l'asservissement de la pose de l'effecteur
    GRBLinExpr obj_lin = 0;
   for (j = 0; j < cols; j++){
     obj_lin += b_tau(0,j)*vars[j];
     }

    GRBQuadExpr obj_Quad = 0;
   for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         obj_Quad += Q_tau(i, j) * vars[i] * vars[j];
         }
        }
*/

    b_q_ddot_q = -2*(kp_q*(q_des.transpose()-q.transpose())-kd_q*q_dot.transpose());

   //Ecriture de la fonction quadratique de l'objectif pour l'asservissement de la pose de l'effecteur
    GRBLinExpr obj_lin = 0;
   for (j = 0; j < cols; j++){
     obj_lin += b_q_ddot_q(0,j)*vars[j+7];
     }

    GRBQuadExpr obj_Quad = 0;
   for (i = 0; i < cols; i++){
         obj_Quad += vars[i+7] * vars[i+7];
       }







J_7_mixed_previous = J_7_mixed;


//M_square = M;
M_square = M_inv;
//M_square = Q_I;


obj_Quad += epsilon_q_dot_dot * (                        vars[7+0]*M_square(0,0)*vars[7+0]+vars[7+1]*M_square(1,0)*vars[7+0]+vars[7+2]*M_square(2,0)*vars[7+0]+vars[7+3]*M_square(3,0)*vars[7+0]+vars[7+4]*M_square(4,0)*vars[7+0]+vars[7+5]*M_square(5,0)*vars[7+0]+vars[7+6]*M_square(6,0)*vars[7+0]+
						         vars[7+0]*M_square(0,1)*vars[7+1]+vars[7+1]*M_square(1,1)*vars[7+1]+vars[7+2]*M_square(2,1)*vars[7+1]+vars[7+3]*M_square(3,1)*vars[7+1]+vars[7+4]*M_square(4,1)*vars[7+1]+vars[7+5]*M_square(5,1)*vars[7+1]+vars[7+6]*M_square(6,1)*vars[7+1]+
						         vars[7+0]*M_square(0,2)*vars[7+2]+vars[7+1]*M_square(1,2)*vars[7+2]+vars[7+2]*M_square(2,2)*vars[7+2]+vars[7+3]*M_square(3,2)*vars[7+2]+vars[7+4]*M_square(4,2)*vars[7+2]+vars[7+5]*M_square(5,2)*vars[7+2]+vars[7+6]*M_square(6,2)*vars[7+2]+
						         vars[7+0]*M_square(0,3)*vars[7+3]+vars[7+1]*M_square(1,3)*vars[7+3]+vars[7+2]*M_square(2,3)*vars[7+3]+vars[7+3]*M_square(3,3)*vars[7+3]+vars[7+4]*M_square(4,3)*vars[7+3]+vars[7+5]*M_square(5,3)*vars[7+3]+vars[7+6]*M_square(6,3)*vars[7+3]+
						         vars[7+0]*M_square(0,4)*vars[7+4]+vars[7+1]*M_square(1,4)*vars[7+4]+vars[7+2]*M_square(2,4)*vars[7+4]+vars[7+3]*M_square(3,4)*vars[7+4]+vars[7+4]*M_square(4,4)*vars[7+4]+vars[7+5]*M_square(5,4)*vars[7+4]+vars[7+6]*M_square(6,4)*vars[7+4]+
						         vars[7+0]*M_square(0,5)*vars[7+5]+vars[7+1]*M_square(1,5)*vars[7+5]+vars[7+2]*M_square(2,5)*vars[7+5]+vars[7+3]*M_square(3,5)*vars[7+5]+vars[7+4]*M_square(4,5)*vars[7+5]+vars[7+5]*M_square(5,5)*vars[7+5]+vars[7+6]*M_square(6,5)*vars[7+5]+
						         vars[7+0]*M_square(0,6)*vars[7+6]+vars[7+1]*M_square(1,6)*vars[7+6]+vars[7+2]*M_square(2,6)*vars[7+6]+vars[7+3]*M_square(3,6)*vars[7+6]+vars[7+4]*M_square(4,6)*vars[7+6]+vars[7+5]*M_square(5,6)*vars[7+6]+vars[7+6]*M_square(6,6)*vars[7+6]);
		  
	


				  
/*
obj_Quad += epsilon_tau * (vars[0]*M_square(0,0)*vars[0]+vars[1]*M_square(1,0)*vars[0]+vars[2]*M_square(2,0)*vars[0]+vars[3]*M_square(3,0)*vars[0]+vars[4]*M_square(4,0)*vars[0]+vars[5]*M_square(5,0)*vars[0]+vars[6]*M_square(6,0)*vars[0]+
						   vars[0]*M_square(0,1)*vars[1]+vars[1]*M_square(1,1)*vars[1]+vars[2]*M_square(2,1)*vars[1]+vars[3]*M_square(3,1)*vars[1]+vars[4]*M_square(4,1)*vars[1]+vars[5]*M_square(5,1)*vars[1]+vars[6]*M_square(6,1)*vars[1]+
						   vars[0]*M_square(0,2)*vars[2]+vars[1]*M_square(1,2)*vars[2]+vars[2]*M_square(2,2)*vars[2]+vars[3]*M_square(3,2)*vars[2]+vars[4]*M_square(4,2)*vars[2]+vars[5]*M_square(5,2)*vars[2]+vars[6]*M_square(6,2)*vars[2]+
						   vars[0]*M_square(0,3)*vars[3]+vars[1]*M_square(1,3)*vars[3]+vars[2]*M_square(2,3)*vars[3]+vars[3]*M_square(3,3)*vars[3]+vars[4]*M_square(4,3)*vars[3]+vars[5]*M_square(5,3)*vars[3]+vars[6]*M_square(6,3)*vars[3]+
						   vars[0]*M_square(0,4)*vars[4]+vars[1]*M_square(1,4)*vars[4]+vars[2]*M_square(2,4)*vars[4]+vars[3]*M_square(3,4)*vars[4]+vars[4]*M_square(4,4)*vars[4]+vars[5]*M_square(5,4)*vars[4]+vars[6]*M_square(6,4)*vars[4]+
						   vars[0]*M_square(0,5)*vars[5]+vars[1]*M_square(1,5)*vars[5]+vars[2]*M_square(2,5)*vars[5]+vars[3]*M_square(3,5)*vars[5]+vars[4]*M_square(4,5)*vars[5]+vars[5]*M_square(5,5)*vars[5]+vars[6]*M_square(6,5)*vars[5]+
						   vars[0]*M_square(0,6)*vars[6]+vars[1]*M_square(1,6)*vars[6]+vars[2]*M_square(2,6)*vars[6]+vars[3]*M_square(3,6)*vars[6]+vars[4]*M_square(4,6)*vars[6]+vars[5]*M_square(5,6)*vars[6]+vars[6]*M_square(6,6)*vars[6]);
*/

/*
//Tache de posture pour le coude 
obj_Quad += epsilon_q_des * (                            ((q[0]+q_dot[0]*dt+0.5*vars[7+0]*pow(dt,2))-q_des_posture[0])*((q[0]+q_dot[0]*dt+0.5*vars[7+0]*pow(dt,2))-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+0.5*vars[7+1]*pow(dt,2))-q_des_posture[1])*((q[1]+q_dot[1]*dt+0.5*vars[7+1]*pow(dt,2))-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+0.5*vars[7+2]*pow(dt,2))-q_des_posture[2])*((q[2]+q_dot[2]*dt+0.5*vars[7+2]*pow(dt,2))-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+0.5*vars[7+3]*pow(dt,2))-q_des_posture[3])*((q[3]+q_dot[3]*dt+0.5*vars[7+3]*pow(dt,2))-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+0.5*vars[7+4]*pow(dt,2))-q_des_posture[4])*((q[4]+q_dot[4]*dt+0.5*vars[7+4]*pow(dt,2))-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+0.5*vars[7+5]*pow(dt,2))-q_des_posture[5])*((q[5]+q_dot[5]*dt+0.5*vars[7+5]*pow(dt,2))-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+0.5*vars[7+6]*pow(dt,2))-q_des_posture[6])*((q[6]+q_dot[6]*dt+0.5*vars[7+6]*pow(dt,2))-q_des_posture[6]));
*/

/*
//ou
obj_Quad += epsilon_q_des * (                            ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2))-q_des_posture[0])*M_square(0,0)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2))-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2))-q_des_posture[1])*M_square(1,1)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2))-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2))-q_des_posture[2])*M_square(2,2)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2))-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2))-q_des_posture[3])*M_square(3,3)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2))-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2))-q_des_posture[4])*M_square(4,4)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2))-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2))-q_des_posture[5])*M_square(5,5)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2))-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2))-q_des_posture[6])*M_square(6,6)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2))-q_des_posture[6]));
*/

/*
int n_beta = 2;
//ou
obj_Quad += epsilon_q_des * (                            ((q[0]+n_beta*q_dot[0]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+0]*pow(dt,2))-q_des_posture[0])*((q[0]+n_beta*q_dot[0]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+0]*pow(dt,2))-q_des_posture[0])+
							 ((q[1]+n_beta*q_dot[1]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+1]*pow(dt,2))-q_des_posture[1])*((q[1]+n_beta*q_dot[1]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+1]*pow(dt,2))-q_des_posture[1])+
							 ((q[2]+n_beta*q_dot[2]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+2]*pow(dt,2))-q_des_posture[2])*((q[2]+n_beta*q_dot[2]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+2]*pow(dt,2))-q_des_posture[2])+
							 ((q[3]+n_beta*q_dot[3]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+3]*pow(dt,2))-q_des_posture[3])*((q[3]+n_beta*q_dot[3]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+3]*pow(dt,2))-q_des_posture[3])+
							 ((q[4]+n_beta*q_dot[4]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+4]*pow(dt,2))-q_des_posture[4])*((q[4]+n_beta*q_dot[4]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+4]*pow(dt,2))-q_des_posture[4])+
							 ((q[5]+n_beta*q_dot[5]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+5]*pow(dt,2))-q_des_posture[5])*((q[5]+n_beta*q_dot[5]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+5]*pow(dt,2))-q_des_posture[5])+
							 ((q[6]+n_beta*q_dot[6]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+6]*pow(dt,2))-q_des_posture[6])*((q[6]+n_beta*q_dot[6]*dt+0.5*(pow(n_beta,2)-n_beta)*vars[7+6]*pow(dt,2))-q_des_posture[6]));
*/

/*
obj_Quad += epsilon_q_des * (                            ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,0)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,0)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,0)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,0)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,0)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,0)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,0)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+

							 ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,1)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,1)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,1)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,1)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,1)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,1)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,1)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+ 

                                                         ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,2)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,2)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,2)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,2)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,2)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,2)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,2)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+ 

							 ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,3)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,3)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,3)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,3)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,3)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,3)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,3)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+ 

							 ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,4)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,4)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,4)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,4)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,4)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,4)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,4)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+

							 ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,5)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,5)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,5)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,5)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,5)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,5)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,5)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])+

							 ((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])*M_square(0,6)*((q[0]+q_dot[0]*dt+vars[7+0]*pow(dt,2)*0.5)-q_des_posture[0])+
							 ((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])*M_square(1,6)*((q[1]+q_dot[1]*dt+vars[7+1]*pow(dt,2)*0.5)-q_des_posture[1])+
							 ((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])*M_square(2,6)*((q[2]+q_dot[2]*dt+vars[7+2]*pow(dt,2)*0.5)-q_des_posture[2])+
							 ((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])*M_square(3,6)*((q[3]+q_dot[3]*dt+vars[7+3]*pow(dt,2)*0.5)-q_des_posture[3])+
							 ((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])*M_square(4,6)*((q[4]+q_dot[4]*dt+vars[7+4]*pow(dt,2)*0.5)-q_des_posture[4])+
							 ((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])*M_square(5,6)*((q[5]+q_dot[5]*dt+vars[7+5]*pow(dt,2)*0.5)-q_des_posture[5])+
							 ((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6])*M_square(6,6)*((q[6]+q_dot[6]*dt+vars[7+6]*pow(dt,2)*0.5)-q_des_posture[6]));

*/





//Q is PSD if and only if the eigenvalues of A are non-negative.
   Eigen::EigenSolver<Eigen::MatrixXd> es_Q(Q_total, false);

   //cout << "The eigenvalues of Q_tau:"
   //<< endl << es_Q.eigenvalues() << endl;

complex<double> lambda_0 = es_Q.eigenvalues()[0];
complex<double> lambda_1 = es_Q.eigenvalues()[1];
complex<double> lambda_2 = es_Q.eigenvalues()[2];
complex<double> lambda_3 = es_Q.eigenvalues()[3];
complex<double> lambda_4 = es_Q.eigenvalues()[4];
complex<double> lambda_5 = es_Q.eigenvalues()[5];
complex<double> lambda_6 = es_Q.eigenvalues()[6];
int PSD = 1; //Q_tau PSD

if(lambda_0.real() < 0 || lambda_1.real() < 0 || lambda_2.real() < 0 || lambda_3.real() < 0 || lambda_4.real() < 0 || lambda_5.real() < 0 || lambda_6.real() < 0){
PSD = 2; //Q_tau not PSD
}
save_PSD(PSD);
save_lambda(lambda_0.real(), lambda_1.real(), lambda_2.real(), lambda_3.real(), lambda_4.real(), lambda_5.real(), lambda_6.real());
//-------------------------------------------------------------------- Xdotdot-Xdotdot_ddes -----------------------------------------//















/*
//-------------------------------------------------------------------------Taudes---------------------------------------------------------------//    
Eigen::Matrix<double, 7, 7> Q_tau;          				  //Matrice Q de la fonction objectif
Eigen::Matrix<double, 1, 7> b_tau;                   			  //Matrice c de la partie linéaire de la fonction objectif
Eigen::Matrix<double, 3, 1> K_p_X_err_rot_temp; 
Eigen::Matrix<double, 6, 1> Jdot_qdot_mixed;
Eigen::Matrix<double, 3, 3> transf_7_0;
Eigen::Matrix<double, 3, 1> K_p_X_err_rot; 
GRBLinExpr obj_lin = 0;
GRBQuadExpr obj_Quad = 0;

Eigen::Matrix<double, 6, 7> J_7_mixed_by_M_inv;
Eigen::Matrix<double, 6, 7> J_7_mixed;

J_7_mixed << J_70_r, J_70_l;

J_7_mixed_dot = derive(J_7_mixed, J_7_mixed_previous, 0.001); 
J_7_mixed_by_M_inv = J_7_mixed * M_inv; 
1


    Q_tau     << 1, 0, 0, 0, 0, 0, 0,
                 0, 1, 0, 0, 0, 0, 0,
                 0, 0, 1, 0, 0, 0, 0,
                 0, 0, 0, 1, 0, 0, 0,
                 0, 0, 0, 0, 1, 0, 0,
                 0, 0, 0, 0, 0, 1, 0,
                 0, 0, 0, 0, 0, 0, 1;    


    //Q_tau = M;
    
    //K_p_X_err_rot_temp     << kp_rot*X_err_angle_prj(0),  kp_rot*X_err_angle_prj(1),  kp_rot*X_err_angle_prj(2);
    K_p_X_err_rot_temp     << X_err_angle_prj(0),  X_err_angle_prj(1),  X_err_angle_prj(2);
    transf_7_0             = Eigen::Quaterniond(H_disp_70.getRotation().w(), H_disp_70.getRotation().x(), H_disp_70.getRotation().y(), H_disp_70.getRotation().z());
    K_p_X_err_rot          = transf_7_0 * K_p_X_err_rot_temp;
    K_p_X_err_rot          = kp_rot * K_p_X_err_rot;
    
    
    Acc_7_des_rot_posi     << Acc_7_orient_des(0),        Acc_7_orient_des(1),        Acc_7_orient_des(2),       Acc_7_des(0), Acc_7_des(1), Acc_7_des(2);
    X_err_rot_posi         << K_p_X_err_rot(0),           K_p_X_err_rot(1),           K_p_X_err_rot(2),          kp*X_err(0),  kp*X_err(1),  kp*X_err(2);
    V_err_rot_posi         << kd_rot*V_err_angle_prj(0),  kd_rot*V_err_angle_prj(1),  kd_rot*V_err_angle_prj(2), kd*V_err(0),  kd*V_err(1),  kd*V_err(2);   
    //X_dot_dot_des_rot_posi = Acc_7_des_rot_posi + X_err_rot_posi + V_err_rot_posi;
    X_dot_dot_des_rot_posi =  X_err_rot_posi + V_err_rot_posi;

    std::cout<< "X_dot_dot_des_rot_posi : " << X_dot_dot_des_rot_posi <<std::cout;   
    
    
    
    Jdot_qdot_mixed << Jdot_qdot_r_70, Jdot_qdot_l;             				  
    //t_tau         =  (Jdot_qdot_mixed - (J_7_mixed_by_M_inv * b)) - X_dot_dot_des_rot_posi;  		  //3*1
    t_tau           =   X_dot_dot_des_rot_posi;  		  //Normalement isi c'est la force
    b_tau           =   -2  * J_7_mixed.transpose() * t_tau;


   //Ecriture de la fonction quadratique de l'objectif
   for (j = 0; j < cols; j++){
     obj_lin += b_tau(0,j)*vars[j];
     }


   for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         obj_Quad += Q_tau(i, j) * vars[i] * vars[j];
         }
        }E_max_7

//M_square = M;
M_square = M_inv;
//M_square = Q_I;

//obj_Quad                         += epsilon_tau * (vars[0]*M_square(0,0)*vars[0]+vars[1]*M_square(1,0)*vars[0]+vars[2]*M_square(2,0)*vars[0]+vars[3]*M_square(3,0)*vars[0]+vars[4]*M_square(4,0)*vars[0]+vars[5]*M_square(5,0)*vars[0]+vars[6]*M_square(6,0)*vars[0]+
//						   vars[0]*M_square(0,1)*vars[1]+vars[1]*M_square(1,1)*vars[1]+vars[2]*M_square(2,1)*vars[1]+vars[3]*M_square(3,1)*vars[1]+vars[4]*M_square(4,1)*vars[1]+vars[5]*M_square(5,1)*vars[1]+vars[6]*M_square(6,1)*vars[1]+
//						   vars[0]*M_square(0,2)*vars[2]+vars[1]*M_square(1,2)*vars[2]+vars[2]*M_square(2,2)*vars[2]+vars[3]*M_square(3,2)*vars[2]+vars[4]*M_square(4,2)*vars[2]+vars[5]*M_square(5,2)*vars[2]+vars[6]*M_square(6,2)*vars[2]+
//						   vars[0]*M_square(0,3)*vars[3]+vars[1]*M_square(1,3)*vars[3]+vars[2]*M_square(2,3)*vars[3]+vars[3]*M_square(3,3)*vars[3]+vars[4]*M_square(4,3)*vars[3]+vars[5]*M_square(5,3)*vars[3]+vars[6]*M_square(6,3)*vars[3]+
//						   vars[0]*M_square(0,4)*vars[4]+vars[1]*M_square(1,4)*vars[4]+vars[2]*M_square(2,4)*vars[4]+vars[3]*M_square(3,4)*vars[4]+vars[4]*M_square(4,4)*vars[4]+vars[5]*M_square(5,4)*vars[4]+vars[6]*M_square(6,4)*vars[4]+
//						   vars[0]*M_square(0,5)*vars[5]+vars[1]*M_square(1,5)*vars[5]+vars[2]*M_square(2,5)*vars[5]+vars[3]*M_square(3,5)*vars[5]+vars[4]*M_square(4,5)*vars[5]+vars[5]*M_square(5,5)*vars[5]+vars[6]*M_square(6,5)*vars[5]+
//						   vars[0]*M_square(0,6)*vars[6]+vars[1]*M_square(1,6)*vars[6]+vars[2]*M_square(2,6)*vars[6]+vars[3]*M_square(3,6)*vars[6]+vars[4]*M_square(4,6)*vars[6]+vars[5]*M_square(5,6)*vars[6]+vars[6]*M_square(6,6)*vars[6]);

//-------------------------------------------------------------------------Taudes---------------------------------------------------------------//
*/












//----------------------------------------------------------- Calcul de la vitesse de l'efecteur et de son signe ------------------------------------//
    std::vector<GRBLinExpr> i_tau_b(7);            				//Sert juste à initialiser le pointeur "GRBLinExpr *tau_b" --> i_ c'est pout initializer         
    GRBLinExpr* tau_b = &i_tau_b[0];
    for(int i=0; i<7; i++){
        tau_b[i] = vars[i] - b(i,0);
    }

						       			 	//La vitesse considérée ici est une vitesse dans le futur
    std::vector<GRBLinExpr> i_M_inv_by_tau_b(7);
    GRBLinExpr* M_inv_by_tau_b = &i_M_inv_by_tau_b[0];
    for(int i=0; i<7; i++){
       for(int j=0; j<7; j++){
           M_inv_by_tau_b[i] += dt * M_inv(i, j) * tau_b[j];
       }
    }

    std::vector<GRBLinExpr> i_q_dot_plus_M_inv_by_tau_b(7);
    GRBLinExpr* q_dot_plus_M_inv_by_tau_b = &i_q_dot_plus_M_inv_by_tau_b[0];
    for(int i=0; i<7; i++){
        q_dot_plus_M_inv_by_tau_b[i] = q_dot(i) + M_inv_by_tau_b[i];
    }

    GRBLinExpr J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_70_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    sgn_7 =know_sign(J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());


//-----------------------------------------------1------------ Calcul de la vitesse de l'efecteur et de son signe FIN------------------------------------//

     model.setObjective(obj_Quad + obj_lin, GRB_MINIMIZE);

//Contraintes égalitaires du model dynamique (sans contacts)
    model.addConstr(M(0, 0) * vars[7] + M(0, 1) * vars[8] + M(0, 2) * vars[9] + M(0, 3) * vars[10] + M(0, 4) * vars[11] + M(0, 5) * vars[12] + M(0, 6) * vars[13]  + b(0, 0) == vars[0], "c0");
    model.addConstr(M(1, 0) * vars[7] + M(1, 1) * vars[8] + M(1, 2) * vars[9] + M(1, 3) * vars[10] + M(1, 4) * vars[11] + M(1, 5) * vars[12] + M(1, 6) * vars[13]  + b(1, 0) == vars[1], "c1");
    model.addConstr(M(2, 0) * vars[7] + M(2, 1) * vars[8] + M(2, 2) * vars[9] + M(2, 3) * vars[10] + M(2, 4) * vars[11] + M(2, 5) * vars[12] + M(2, 6) * vars[13]  + b(2, 0) == vars[2], "c2");
    model.addConstr(M(3, 0) * vars[7] + M(3, 1) * vars[8] + M(3, 2) * vars[9] + M(3, 3) * vars[10] + M(3, 4) * vars[11] + M(3, 5) * vars[12] + M(3, 6) * vars[13]  + b(3, 0) == vars[3], "c3");
    model.addConstr(M(4, 0) * vars[7] + M(4, 1) * vars[8] + M(4, 2) * vars[9] + M(4, 3) * vars[10] + M(4, 4) * vars[11] + M(4, 5) * vars[12] + M(4, 6) * vars[13]  + b(4, 0) == vars[4], "c4");
    model.addConstr(M(5, 0) * vars[7] + M(5, 1) * vars[8] + M(5, 2) * vars[9] + M(5, 3) * vars[10] + M(5, 4) * vars[11] + M(5, 5) * vars[12] + M(5, 6) * vars[13]  + b(5, 0) == vars[5], "c5");
    model.addConstr(M(6, 0) * vars[7] + M(6, 1) * vars[8] + M(6, 2) * vars[9] + M(6, 3) * vars[10] + M(6, 4) * vars[11] + M(6, 5) * vars[12] + M(6, 6) * vars[13]  + b(6, 0) == vars[6], "c6");

/*
//Contraintes égalitaires du model dynamique (Avec contacts)
    model.addConstr(M(0, 0) * vars[7] + M(0, 1) * vars[8] + M(0, 2) * vars[9] + M(0, 3) * vars[10] + M(0, 4) * vars[11] + M(0, 5) * vars[12] + M(0, 6) * vars[13]  + b(0, 0) == vars[0] + ((J_70_l.transpose()).block<1,3>(0,0) * Force_sensor_3dVector), "c0");
    model.addConstr(M(1, 0) * vars[7] + M(1, 1) * vars[8] + M(1, 2) * vars[9] + M(1, 3) * vars[10] + M(1, 4) * vars[11] + M(1, 5) * vars[12] + M(1, 6) * vars[13]  + b(1, 0) == vars[1] + ((J_70_l.transpose()).block<1,3>(1,0) * Force_sensor_3dVector), "c1");
    model.addConstr(M(2, 0) * vars[7] + M(2, 1) * vars[8] + M(2, 2) * vars[9] + M(2, 3) * vars[10] + M(2, 4) * vars[11] + M(2, 5) * vars[12] + M(2, 6) * vars[13]  + b(2, 0) == vars[2] + ((J_70_l.transpose()).block<1,3>(2,0) * Force_sensor_3dVector), "c2");
    model.addConstr(M(3, 0) * vars[7] + M(3, 1) * vars[8] + M(3, 2) * vars[9] + M(3, 3) * vars[10] + M(3, 4) * vars[11] + M(3, 5) * vars[12] + M(3, 6) * vars[13]  + b(3, 0) == vars[3] + ((J_70_l.transpose()).block<1,3>(3,0) * Force_sensor_3dVector), "c3");
    model.addConstr(M(4, 0) * vars[7] + M(4, 1) * vars[8] + M(4, 2) * vars[9] + M(4, 3) * vars[10] + M(4, 4) * vars[11] + M(4, 5) * vars[12] + M(4, 6) * vars[13]  + b(4, 0) == vars[4] + ((J_70_l.transpose()).block<1,3>(4,0) * Force_sensor_3dVector), "c4");
    model.addConstr(M(5, 0) * vars[7] + M(5, 1) * vars[8] + M(5, 2) * vars[9] + M(5, 3) * vars[10] + M(5, 4) * vars[11] + M(5, 5) * vars[12] + M(5, 6) * vars[13]  + b(5, 0) == vars[5] + ((J_70_l.transpose()).block<1,3>(5,0) * Force_sensor_3dVector), "c5");
    model.addConstr(M(6, 0) * vars[7] + M(6, 1) * vars[8] + M(6, 2) * vars[9] + M(6, 3) * vars[10] + M(6, 4) * vars[11] + M(6, 5) * vars[12] + M(6, 6) * vars[13]  + b(6, 0) == vars[6] + ((J_70_l.transpose()).block<1,3>(6,0) * Force_sensor_3dVector), "c6");
*/







/*
//Contraintes sur le Jerk articulaire
if((q_dddot_bounds_max[0]-q_dddot[0])>5 && not constr){
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt <= q_dddot_bounds_max[0],  "c7");
}

if((q_dddot_bounds_min[0]-q_dddot[0])<-5 && not constr){
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt >= q_dddot_bounds_min[0] , "c8");
}
*/


/*
if(absolute(q[0]-q_bounds_max[0])<0.1 || absolute(q[0]-q_bounds_min[0])<0.1 || absolute(q_dot[0]-q_dot_bounds_max[0])<0.05 || absolute(q_dot[0]-q_dot_bounds_min[0])<0.05 ||
   absolute(q[1]-q_bounds_max[1])<0.1 || absolute(q[1]-q_bounds_min[1])<0.1 || absolute(q_dot[1]-q_dot_bounds_max[1])<0.05 || absolute(q_dot[1]-q_dot_bounds_min[1])<0.05 ||
   absolute(q[2]-q_bounds_max[2])<0.1 || absolute(q[2]-q_bounds_min[2])<0.1 || absolute(q_dot[2]-q_dot_bounds_max[2])<0.05 || absolute(q_dot[2]-q_dot_bounds_min[2])<0.05 ||
   absolute(q[3]-q_bounds_max[3])<0.1 || absolute(q[3]-q_bounds_min[3])<0.1 || absolute(q_dot[3]-q_dot_bounds_max[3])<0.05 || absolute(q_dot[3]-q_dot_bounds_min[3])<0.05 ||
   absolute(q[4]-q_bounds_max[4])<0.1 || absolute(q[4]-q_bounds_min[4])<0.1 || absolute(q_dot[4]-q_dot_bounds_max[4])<0.05 || absolute(q_dot[4]-q_dot_bounds_min[4])<0.05 ||
   absolute(q[5]-q_bounds_max[5])<0.1 || absolute(q[5]-q_bounds_min[5])<0.1 || absolute(q_dot[5]-q_dot_bounds_max[5])<0.05 || absolute(q_dot[5]-q_dot_bounds_min[5])<0.05 ||
   absolute(q[6]-q_bounds_max[6])<0.1 || absolute(q[6]-q_bounds_min[6])<0.1 || absolute(q_dot[6]-q_dot_bounds_max[6])<0.05 || absolute(q_dot[6]-q_dot_bounds_min[6])<0.05)
{
int mama = 0;
}
else{
*/


//Contraintes sur le Jerk
/*
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt <= q_dddot_bounds_max[0]+20,  "c7");
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt >= q_dddot_bounds_min[0]-20 , "c8");

    model.addConstr((vars[8] - q_dot_dot_final[1])/dt <= q_dddot_bounds_max[1]+20 , "c9");
    model.addConstr((vars[8] - q_dot_dot_final[1])/dt >= q_dddot_bounds_min[1]-20 , "c10");

    model.addConstr((vars[9] - q_dot_dot_final[2])/dt <= q_dddot_bounds_max[2]+20 , "c11");
    model.addConstr((vars[9] - q_dot_dot_final[2])/dt >= q_dddot_bounds_min[2]-20 , "c12");

    model.addConstr((vars[10] - q_dot_dot_final[3])/dt <= q_dddot_bounds_max[3]+20 , "c13");
    model.addConstr((vars[10] - q_dot_dot_final[3])/dt >= q_dddot_bounds_min[3]-20 , "c14");

    model.addConstr((vars[11] - q_dot_dot_final[4])/dt <= q_dddot_bounds_max[4]+20 , "c15");
    model.addConstr((vars[11] - q_dot_dot_final[4])/dt >= q_dddot_bounds_min[4]-20 , "c16");

    model.addConstr((vars[12] - q_dot_dot_final[5])/dt <= q_dddot_bounds_max[5]+20 , "c17");
    model.addConstr((vars[12] - q_dot_dot_final[5])/dt >= q_dddot_bounds_min[5]-20 , "c18");

    model.addConstr((vars[13] - q_dot_dot_final[6])/dt <= q_dddot_bounds_max[6]+20 , "c19");
    model.addConstr((vars[13] - q_dot_dot_final[6])/dt >= q_dddot_bounds_min[6]-20 , "c20");
    model.update();
*/



//}










/*
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt <=  q_dddot_bounds_max[0]+2,  "c7");
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt >=  q_dddot_bounds_min[0]-2, "c8");
*/




/*
//Pour la comp vel_jerk
if((q_dotdot_bounds_comp_vel_jerk_deriv_max[0] >= q_dddot_bounds_min[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt >=  q_dddot_bounds_min[0], "c8");
   constr_jerk = 10;
}

if((q_dotdot_bounds_comp_vel_jerk_deriv_min[0] <= q_dddot_bounds_max[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt <=  q_dddot_bounds_max[0], "c7");
   constr_jerk = 10;
}

else{
constr_jerk = 0;
}
*/



/*
//Pour la comp POsi_jerk 1 avec q_dot_dot_final
if((q_dotdot_bounds_comp_posi_jerk_deriv_max[0] >= q_dddot_bounds_min[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt >=  q_dddot_bounds_min[0], "c8");
   constr_jerk = 10;
}
if((q_dotdot_bounds_comp_posi_jerk_deriv_min[0] <= q_dddot_bounds_max[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt <=  q_dddot_bounds_max[0], "c7");
   constr_jerk = 10;
}
else{
constr_jerk = 0;
}
save_constr_jerk(constr_jerk);
*/

constr_jerk = 0;
save_constr_jerk(constr_jerk);





/*
//Pour la comp POsi_jerk_acc 1 avec q_dot_dot_final
if((q_dotdot_bounds_comp_posi_jerk_acc_deriv_max[0] >= q_dddot_bounds_min[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt >=  q_dddot_bounds_min[0], "c8");
   constr_jerk = 10;
}
if((q_dotdot_bounds_comp_posi_jerk_acc_deriv_min[0] <= q_dddot_bounds_max[0])){
//if((q_dotdot_bounds_deriv_max_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_max_comp[0] <=q_dddot_bounds_max[0]) && (q_dotdot_bounds_deriv_min_comp[0]>=q_dddot_bounds_min[0] && q_dotdot_bounds_deriv_min_comp[0]<=q_dddot_bounds_max[0])){
   model.addConstr((vars[7] - q_dot_dot_final[0])/dt <=  q_dddot_bounds_max[0], "c7");
   constr_jerk = 10;
}
else{
constr_jerk = 0;
}
save_constr_jerk(constr_jerk);
*/






/*
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt <=  q_dddot_bounds_max[0]+3, "c7");
    model.addConstr((vars[7] - q_dot_dot_final[0])/dt >=  q_dddot_bounds_min[0]-3, "c8");
*/
/*
    model.addConstr((vars[8] - q_dot_dot_final[1])/dt <=  q_dddot_bounds_max[1] , "c9");
    model.addConstr((vars[8] - q_dot_dot_final[1])/dt >=  q_dddot_bounds_min[1], "c10");

    model.addConstr((vars[9] - q_dot_dot_final[2])/dt <=  q_dddot_bounds_max[2] , "c11");
    model.addConstr((vars[9] - q_dot_dot_final[2])/dt >=  q_dddot_bounds_min[2], "c12");

    model.addConstr((vars[10] - q_dot_dot_final[3])/dt <=  q_dddot_bounds_max[3] , "c13");
    model.addConstr((vars[10] - q_dot_dot_final[3])/dt >=  q_dddot_bounds_min[3] , "c14");

    model.addConstr((vars[11] - q_dot_dot_final[4])/dt <=  q_dddot_bounds_max[4] , "c15");
    model.addConstr((vars[11] - q_dot_dot_final[4])/dt >=  q_dddot_bounds_min[4] , "c16");

    model.addConstr((vars[12] - q_dot_dot_final[5])/dt <=  q_dddot_bounds_max[5] , "c17");
    model.addConstr((vars[12] - q_dot_dot_final[5])/dt >=  q_dddot_bounds_min[5] , "c18");

    model.addConstr((vars[13] - q_dot_dot_final[6])/dt <=  q_dddot_bounds_max[6] , "c19");
    model.addConstr((vars[13] - q_dot_dot_final[6])/dt >=  q_dddot_bounds_min[6] , "c20");
*/
    model.update();

//-------------------------------------------------------------------Add of the quadratic constrains------------------------------------------------//


//******************************************Contrainte énergétique sur le segment 7******************************************//

/*
//QP KINETIC ENERGY CONSTRAINT
    Ec_max_7 = 0.0200;
    sgn_7 = 1;
    //double h_7 = sgn_7 * 0.5 * m_eq_7_j;
    double h_7 = 1 * 0.5 * m_eq_7_j;
    Eigen::Matrix<double, 1, 7> J_70_C_proj_by_M_inv;
    J_70_C_proj_by_M_inv = J_70_C_proj * M_inv; 
    double Cte_7_part_1 = J_70_C_proj * q_dot;   
    double Cte_7_part_2 = dt_qp * J_70_C_proj_by_M_inv  * b;   
    double Cte_7 = Cte_7_part_1 - Cte_7_part_2;
 			
    Eigen::Matrix<double, 7, 7> Q_C_7;          				              //Matrice Q de la fonction objectif
    Q_C_7 = h_7 * dt_qp * (J_70_C_proj_by_M_inv.transpose() * J_70_C_proj_by_M_inv) * dt_qp;        //a(1, 7) ici est = J_70_C_proj_by_M_inv * dt_qp

    Eigen::Matrix<double, 1, 7> b_C_7;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_7 = 2 * h_7 * Cte_7 * (dt_qp * J_70_C_proj_by_M_inv)   ;

   //Ecriture de la fonction quadratique de la contrainte 7
    GRBQuadExpr constr_7_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_7_Quad += Q_C_7(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_7_Quad += b_C_7(0,j) * vars[j];
     }

    double constr_7_Cte = h_7 * pow(Cte_7, 2);
    constr_7_Quad = constr_7_Quad + constr_7_Cte;

    //model.addQConstr(constr_7_Quad <= 50, "QC");
    model.addQConstr(constr_7_Quad <= Ec_max_7, "QC");
*/




//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
//..................Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT................//
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
/*
//LINEAR KINETIC ENERGY CONSTRAINT dans le direction de l'obstacle
//µµµµµµµµµ
Ec_max_7 = 0.0200; 

    //La contrainte sur l'énergie cinétique est linéaire sous la forme (L_C_a_7 tau + Cte_7)
    J_70_C_proj_by_M_inv;
    J_70_C_proj_by_M_inv = J_70_C_proj * M_inv; 
    Cte_7_part_1 = J_70_C_proj * q_dot;   
    Cte_7_part_2 = dt_lp * J_70_C_proj_by_M_inv  * b;   
    Cte_7 = Cte_7_part_1 - Cte_7_part_2;
 			
    Eigen::Matrix<double, 1, 7> L_C_a_7;          				              //Matrice Q de la fonction objectif
    L_C_a_7 = J_70_C_proj_by_M_inv * dt_lp;        //a(1, 7) ici est = J_70_C_proj_by_M_inv * dt_qp

    constr_7_Lin_Ec_C_ob = L_C_a_7[0] * vars[0] + L_C_a_7[1] * vars[1] + L_C_a_7[2] * vars[2] + L_C_a_7[3] * vars[3] + L_C_a_7[4] * vars[4] + L_C_a_7[5] * vars[5] + L_C_a_7[6] * vars[6] + Cte_7;
   //Ecriture de la fonction quadratique de la contrainte 7
    model.addConstr(constr_7_Lin_Ec_C_ob <= sqrt((2*Ec_max_7)/m_eq_7_j), "LC_Ec");
*/




/*
//Contrainte sur l'énergie cinétique de l'effecteur selon les trois axes. 
//µµµµµµµµµ
Ec_max_7_x                  = 0.1;
sgn_7_x                     = know_sign(J_70_l_proj_x_axis * q_dot);
J_70_l_proj_x_axis_by_M_inv = J_70_l_proj_x_axis * M_inv;
Cte_7_part_1_x              = J_70_l_proj_x_axis * q_dot; 
Cte_7_part_2_x              = dt_lp * J_70_l_proj_x_axis_by_M_inv  * b;   
Cte_7_x                     = Cte_7_part_1_x - Cte_7_part_2_x;
L_C_a_7_x                   = J_70_l_proj_x_axis_by_M_inv * dt_lp;  

constr_7_Lin_Ec_x = L_C_a_7_x[0] * vars[0] + L_C_a_7_x[1] * vars[1] + L_C_a_7_x[2] * vars[2] + L_C_a_7_x[3] * vars[3] + L_C_a_7_x[4] * vars[4] + L_C_a_7_x[5] * vars[5] + L_C_a_7_x[6] * vars[6] + Cte_7_x;
model.addConstr(sgn_7_x * constr_7_Lin_Ec_x <= sqrt((2*Ec_max_7_x)/m_eq_7_j_x_axis), "LC");
*/



/*
//µµµµµµµµµ
Ec_max_7_y                  = Ec_max_7;
sgn_7_y                     = know_sign(J_70_l_proj_y_axis * q_dot);
J_70_l_proj_y_axis_by_M_inv = J_70_l_proj_y_axis * M_inv;
Cte_7_part_1_y              = J_70_l_proj_y_axis * q_dot; 
Cte_7_part_2_y              = dt_lp * J_70_l_proj_y_axis_by_M_inv  * b;   
Cte_7_y                     = Cte_7_part_1_y - Cte_7_part_2_y;
L_C_a_7_y                   = J_70_l_proj_y_axis_by_M_inv * dt_lp;  

constr_7_Lin_Ec_y = L_C_a_7_y[0] * vars[0] + L_C_a_7_y[1] * vars[1] + L_C_a_7_y[2] * vars[2] + L_C_a_7_y[3] * vars[3] + L_C_a_7_y[4] * vars[4] + L_C_a_7_y[5] * vars[5] + L_C_a_7_y[6] * vars[6] + Cte_7_y;

model.addConstr(sgn_7_y * constr_7_Lin_Ec_y <= sqrt((2*Ec_max_7_y)/m_eq_7_j_y_axis), "LC");


//µµµµµµµµµ
Ec_max_7_z                  = Ec_max_7;
sgn_7_z                     = know_sign(J_70_l_proj_z_axis * q_dot);
J_70_l_proj_z_axis_by_M_inv = J_70_l_proj_z_axis * M_inv;
Cte_7_part_1_z              = J_70_l_proj_z_axis * q_dot; 
Cte_7_part_2_z              = dt_lp * J_70_l_proj_z_axis_by_M_inv  * b;   
Cte_7_z                     = Cte_7_part_1_z - Cte_7_part_2_z;
L_C_a_7_z                   = J_70_l_proj_z_axis_by_M_inv * dt_lp;  

constr_7_Lin_Ec_z = L_C_a_7_z[0] * vars[0] + L_C_a_7_z[1] * vars[1] + L_C_a_7_z[2] * vars[2] + L_C_a_7_z[3] * vars[3] + L_C_a_7_z[4] * vars[4] + L_C_a_7_z[5] * vars[5] + L_C_a_7_z[6] * vars[6] + Cte_7_z;

model.addConstr(sgn_7_z * constr_7_Lin_Ec_z <= sqrt((2*Ec_max_7_z)/m_eq_7_j_z_axis), "LC");
*/
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
//..................Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT Ec CONSTRAINT................//
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//












//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
//..................Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT................//
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
/*
 //µµµµµµµµµ
//Contrainte sur l'énergie potentielle dans la direction de X_err
    Ep_max_Xerr = 0.00;

    U_Xerr  = (J_70_l_proj_Xerr) * M_inv;
    B1_Xerr = (J_70_dot_l_proj_Xerr * q_dot);
    B2_Xerr = (U_Xerr * b); 
    B_Xerr  = B1_Xerr - B2_Xerr;

    constr_7_Lin_Ep_Xerr            = U_Xerr[0] * vars[0] + U_Xerr[1] * vars[1] + U_Xerr[2] * vars[2] + U_Xerr[3] * vars[3] + U_Xerr[4] * vars[4] + U_Xerr[5] * vars[5] + U_Xerr[6] * vars[6] + B_Xerr;

sgn_7 = -1;
if(notfirsttime == 0 && abs(X_err.norm()) != 0){

    //model.addConstr(constr_7_Lin_Ep >= sgn_7 * (Ep_max/(m_eq_7_j_Xerr * abs(X_err[0]))), "LC_Ep");   //L'activation de cette contrainte empèche la soustraction d'énergie du system (on ne freine plus)
    //model.addConstr(constr_7_Lin_Ep <=  (Ep_max/(m_eq_7_j_Xerr * abs(X_err[0]))), "LC_Ep");           //L'activation de cette contraine empèche l'ajout d'énergie dans le système.

    if(E_7_reconstructed_with_V_7_t2 > 0.02){
    model.addConstr(constr_7_Lin_Ep_Xerr >= sgn_7 * (Ep_max_Xerr/(m_eq_7_j_Xerr * abs(X_err.norm()))), "LC_Ep_Xerr");
    model.addConstr(constr_7_Lin_Ep_Xerr <=         (Ep_max_Xerr/(m_eq_7_j_Xerr * abs(X_err.norm()))), "LC_Ep_Xerr_2");
}
}
*/



//************************************Contrainte sur l'Energie cinétique écrite avec l'énergie Potentielle************************************//
/*
Real_Ec_7_x       = 0.5 *  m_eq_7_j_x_axis *  V_7[3] * V_7[3];
save_Real_Ec_7_x(Real_Ec_7_x);
Real_Ec_7_x_derived = (Real_Ec_7_x - Real_Ec_7_x_prev)/dt;

//Contrainte sur la somme de l'énergie potentielle dans la direction de x_axis
    Ep_max_x = 0.001;    
    F_max_x  = 5;    

    U_x = (J_70_l_proj_x_axis * M_inv);
    B1_x = J_70_dot_l_proj_x_axis * q_dot;
    B2_x = (J_70_l_proj_x_axis * M_inv) * b;
    B_x = B1_x - B2_x;

    constr_7_Lin_Ep_x = U_x[0] * vars[0] + U_x[1] * vars[1] + U_x[2] * vars[2] + U_x[3] * vars[3] + U_x[4] * vars[4] + U_x[5] * vars[5] + U_x[6] * vars[6] + B_x;

sgn_7 = -1;

//Contrainte sur Ec en utilisant Ep A GARDER, NE PAS MODIFIER
if(notfirsttime == 0 && abs(X_err(0)) != 0){
      model.addConstr(constr_7_Lin_Ep_x * (m_eq_7_j_x_axis * abs(X_err_real[0])) <= (Ec_max_7 - Real_Ec_7_x) - (0.000001 * Real_Ec_7_x_derived), "LC_Ep_x_2");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
}
Real_Ec_7_x_prev = Real_Ec_7_x;
*/
//************************************Contrainte sur l'Energie cinétique écrite avec l'énergie Potentielle************************************//


//*************************************************Contrainte sur L'effort de contact selon l'axe X*******************************************************//
/*
//Energie cinétique réelle selon x 
Real_Ec_7_x       = 0.5 *  m_eq_7_j_x_axis *  V_7[3] * V_7[3];
save_Real_Ec_7_x(Real_Ec_7_x);
Real_Ec_7_x_derived = (Real_Ec_7_x - Real_Ec_7_x_prev)/dt;

    Ep_max_x = 0.001;    
    F_max_x  = 3.0;    

    U_x = (J_70_l_proj_x_axis * M_inv);
    B1_x = J_70_dot_l_proj_x_axis * q_dot;
    B2_x = (J_70_l_proj_x_axis * M_inv) * b;
    B_x = B1_x - B2_x;

    constr_7_Lin_Ep_x = U_x[0] * vars[0] + U_x[1] * vars[1] + U_x[2] * vars[2] + U_x[3] * vars[3] + U_x[4] * vars[4] + U_x[5] * vars[5] + U_x[6] * vars[6] + B_x;

sgn_7 = -1;

if(notfirsttime == 0 && Time_since_first_impact > 20){
//if(notfirsttime == 0 && abs(X_err(0)) != 0){
//Contrainte sur les efforts de Contact
        //model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis <=   F_max_x , "LC_F_x_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
        model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis ==   F_max_x , "LC_F_x_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
        //model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis >=  -F_max_x , "LC_F_x_2"); 

      //model.addConstr((constr_7_Lin_Ep_x * m_eq_7_j_x_axis - Force_sensor_3dVector[0]) <=   (F_max_x - Force_sensor_3dVector[0]) , "LC_F_x_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
      //model.addConstr((constr_7_Lin_Ep_x * m_eq_7_j_x_axis - Force_sensor_3dVector[0]) <=   (F_max_x - Force_sensor_3dVector[0]) , "LC_F_x_2");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
//Contrainte sur les efforts de Contact 
 std::cout<<"constr 1 ACTIV !"<<std::endl;
}
Real_Ec_7_x_prev = Real_Ec_7_x;
*/
//*************************************************Contrainte sur L'effort de contact selon l'axe X*******************************************************//





//Asservissement de l'effort verticale selon l'axe z
//*************************************************Contrainte sur L'effort de contact selon l'axe z*******************************************************//
/*
//Energie cinétique réelle selon x 
Real_Ec_7_x       = 0.5 *  m_eq_7_j_x_axis *  V_7[3] * V_7[3];
save_Real_Ec_7_x(Real_Ec_7_x);
Real_Ec_7_x_derived = (Real_Ec_7_x - Real_Ec_7_x_prev)/dt;
Force_sensor_z_derived = (Force_sensor_3dVector[2] - Force_sensor_z_previous)/(dt);

    F_max_z  = 50.0;    
    
    U_z = (J_70_l_proj_z_axis * M_inv);
    B1_z = J_70_dot_l_proj_z_axis * q_dot;
    B2_z = (J_70_l_proj_z_axis * M_inv) * b;
    B_z = B1_z - B2_z;

    constr_7_Lin_Ep_z = U_z[0] * vars[0] + U_z[1] * vars[1] + U_z[2] * vars[2] + U_z[3] * vars[3] + U_z[4] * vars[4] + U_z[5] * vars[5] + U_z[6] * vars[6] + B_z;

sgn_7 = -1;

if(notfirsttime == 0 && Time_since_first_impact > 5){
//if(notfirsttime == 0 && time_in_second > 80){
//if(notfirsttime == 0 && abs(X_err(0)) != 0){
//Contrainte sur les efforts de Contact
        //model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis <=   F_max_x , "LC_F_x_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
        //model.addConstr(constr_7_Lin_Ep_z * m_eq_7_j_z_axis <=   -F_max_z , "LC_F_z_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
       

        //model.addConstr(constr_7_Lin_Ep_z * m_eq_7_j_z_axis >=   -F_max_z , "LC_F_z_1"); /////////A GARDER CAR MARCHE DEJA PAS MAL !!!!
        //model.addConstr(((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - previous_robot_force_z_nxt_step) >=   0.2*(-F_max_z + Force_sensor_3dVector[2]) - (0.000001 * Force_sensor_z_derived), "LC_F_z_1"); //A GARDER CAR MARCHE DEJA PAS MAL !!!
        //model.addConstr(((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - previous_robot_force_z_nxt_step) >=   0.1*(-F_max_z + Force_sensor_3dVector[2]) - (0.00001 * previous_robot_force_z_nxt_step_derived), "LC_F_z_1"); //Pour developpement
          model.addConstr(((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - previous_robot_force_z_nxt_step) >=   0.2*(-F_max_z + Force_sensor_3dVector[2]) - (0.000001 * Force_sensor_z_derived), "LC_F_z_1"); //Pour developpement   




        //model.addConstr(((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - (Force_sensor_3dVector[2])) >=   -F_max_z + Force_sensor_3dVector[2] - (0.00001 * Force_sensor_z_derived), "LC_F_z_1");

        //model.addConstr(Force_sensor_3dVector[2] + ((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - previous_robot_force_z_nxt_step) <=  F_max_z, "LC_F_x_2"); 
        //model.addConstr(Force_sensor_3dVector[2] + ((constr_7_Lin_Ep_z * m_eq_7_j_z_axis) - previous_robot_force_z_nxt_step) >= -F_max_z, "LC_F_x_2"); 

       //model.addConstr((constr_7_Lin_Ep_x * m_eq_7_j_x_axis - Force_sensor_3dVector[0]) <=   (F_max_x - Force_sensor_3dVector[0]) , "LC_F_x_1");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
       //model.addConstr((constr_7_Lin_Ep_x * m_eq_7_j_x_axis - Force_sensor_3dVector[0]) <=   (F_max_x - Force_sensor_3dVector[0]) , "LC_F_x_2");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
//Contrainte sur les efforts de Contact 
std::cout<<"constr 1 ACTIV !"<<std::endl;
}
Real_Ec_7_x_prev = Real_Ec_7_x;
Force_sensor_z_previous = Force_sensor_3dVector[2];
m_eq_7_j_z_axis_previous = m_eq_7_j_z_axis;
*/
//*************************************************Contrainte sur L'effort de contact selon l'axe z*******************************************************//




//*************************************************Contrainte sur l'énergie Potentielle selon l'axe X*******************************************************//
/*
 //µµµµµµµµµ
//Energie cinétique réelle selon x 
Real_Ec_7_x       = 0.5 *  m_eq_7_j_x_axis *  V_7[3] * V_7[3];
save_Real_Ec_7_x(Real_Ec_7_x);
Real_Ec_7_x_derived = (Real_Ec_7_x - Real_Ec_7_x_prev)/dt;

    Ep_max_x = 0.000;    
    F_max_x  = 5;    

    U_x = (J_70_l_proj_x_axis * M_inv);
    B1_x = J_70_dot_l_proj_x_axis * q_dot;
    B2_x = (J_70_l_proj_x_axis * M_inv) * b;
    B_x = B1_x - B2_x;

    constr_7_Lin_Ep_x = U_x[0] * vars[0] + U_x[1] * vars[1] + U_x[2] * vars[2] + U_x[3] * vars[3] + U_x[4] * vars[4] + U_x[5] * vars[5] + U_x[6] * vars[6] + B_x;

sgn_7 = -1;

//if(notfirsttime == 0 && Time_since_first_impact > 400 && Time_since_first_impact <= 3400){ 
if(notfirsttime == 0 && abs(X_err(0)) != 0 && Time_since_first_impact > 100){
//Contraintes sur l'énergie potentielle
      model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis <=  Ep_max_x/abs(X_err[0]) , "LC_Ep_x");  //Contrainte SUR Ec en utilisant injected Ep OK; FAIRE LA MEME CHOSE POUR L'ASSERVISSEMENT DE LA FORCE
      model.addConstr(constr_7_Lin_Ep_x * m_eq_7_j_x_axis >= -Ep_max_x/abs(X_err[0]) , "LC_Ep_x");   
//Contraintes sur l'énergie potentielle
}
Real_Ec_7_x_prev = Real_Ec_7_x;
*/
//*************************************************Contrainte sur l'énergie Potentielle selon l'axe X*******************************************************//





/*
 //µµµµµµµµµ
 //Contrainte sur l'énergie potentielle dans la direction de y_axis
    Ep_max_y = 0.000;
         
    U_y = (J_70_l_proj_y_axis * M_inv);
    B1_y = J_70_dot_l_proj_y_axis * q_dot;
    B2_y = (J_70_l_proj_y_axis * M_inv) * b;
    B_y = B1_y - B2_y;

    constr_7_Lin_Ep_y = U_y[0] * vars[0] + U_y[1] * vars[1] + U_y[2] * vars[2] + U_y[3] * vars[3] + U_y[4] * vars[4] + U_y[5] * vars[5] + U_y[6] * vars[6] + B_y;
    
sgn_7 = -1;
if(notfirsttime == 0 && abs(X_err[1])  != 0){
    model.addConstr(constr_7_Lin_Ep_y >= sgn_7 * (Ep_max_y/(m_eq_7_j_y_axis * abs(X_err[1]))), "LC_Ep_y");
    model.addConstr(constr_7_Lin_Ep_y <=         (Ep_max_y/(m_eq_7_j_y_axis * abs(X_err[1]))), "LC_Ep_y_2");
}


   

//µµµµµµ
 //Contrainte sur l'énergie potentielle dans la direction de z_axis
    Ep_max_z = 0.000;    
    
    U_z = (J_70_l_proj_z_axis * M_inv);
    B1_z = J_70_dot_l_proj_z_axis * q_dot;
    B2_z = (J_70_l_proj_z_axis * M_inv) * b;
    B_z = B1_z - B2_z;

    constr_7_Lin_Ep_z = U_z[0] * vars[0] + U_z[1] * vars[1] + U_z[2] * vars[2] + U_z[3] * vars[3] + U_z[4] * vars[4] + U_z[5] * vars[5] + U_z[6] * vars[6] + B_z;

sgn_7 = -1;
if(notfirsttime == 0 && abs(X_err[2]) != 0){
    model.addConstr(constr_7_Lin_Ep_z >= sgn_7 * (Ep_max_z/(m_eq_7_j_z_axis * abs(X_err[2]))), "LC_Ep_z");
    model.addConstr(constr_7_Lin_Ep_z <=         (Ep_max_z/(m_eq_7_j_z_axis * abs(X_err[2]))), "LC_Ep_z_2");
       
}
*/

notfirsttime = 0;
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
//..................Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT Ep CONSTRAINT................//
//.............................................................................................................................................................................//
//.............................................................................................................................................................................//
 //******************************************Contrainte énergétique sur le segment 7******************************************//





















//---------------------------------------------------------------------------Optimization-----------------------------------------------------------//
    //Optimize model
/*
    model.getEnv().set(GRB_IntParam_Presolve, 1);
    model.getEnv().set(GRB_IntParam_PreQLinearize , 1);
    model.getEnv().set(GRB_IntParam_NumericFocus , 3);
    model.getEnv().set(GRB_IntParam_IISMethod , 0);
    model.getEnv().set(GRB_DoubleParam_PSDTol  , 1e-6);
    model.getEnv().set(GRB_IntParam_BarHomogeneous, -1);
*/

    //model.getEnv().set(GRB_DoubleParam_PSDTol  , 2);
    model.getEnv().set(GRB_IntParam_NumericFocus , 3);
    model.getEnv().set(GRB_IntParam_OutputFlag  , 0);
    model.getEnv().set(GRB_DoubleParam_PSDTol  , 1e-2);
/*
    model.getEnv().set(GRB_IntParam_Presolve, 1);
    model.getEnv().set(GRB_IntParam_PreQLinearize , 0);
    model.getEnv().set(GRB_IntParam_NumericFocus , 3);
    model.getEnv().set(GRB_IntParam_IISMethod , 0);
    model.getEnv().set(GRB_DoubleParam_PSDTol  , 1);

    //model.getEnv().set(GRB_IntParam_Threads , 1);
    model.getEnv().set(GRB_IntParam_BarHomogeneous, 1);
 */
/*
    model.getEnv().set(GRB_IntParam_DualReductions , 1);
    model.getEnv().set(GRB_DoubleParam_PSDTol  , 1);
    model.getEnv().set(GRB_IntParam_BarHomogeneous, 1);
*/
    //model.getEnv().set(GRB_IntParam_BarHomogeneous, 1);
/*
    GRBEnv menv = model.getEnv();
  
    // Set the TuneResults parameter to 1

    menv.set(GRB_IntParam_TuneResults, 1);

    // Tune the model

    model.tune();

    // Get the number of tuning results

    int resultcount = model.get(GRB_IntAttr_TuneResultCount);



      // Load the tuned parameters into the model's environment

      model.getTuneResult(0);

      // Write tuned parameters to a file

      model.write("tune.prm");
*/



      // Solve the model using the tuned parameters
    model.optimize();

   // model.optimize();
    int status = model.get(GRB_IntAttr_Status);		//Pour debug
        save_status(status);



//---------------------------------------------------------------------------Optimization-----------------------------------------------------------//










//-----------------------------------------------------------------------------Save data------------------------------------------------------------//

save_q_dotdot_0_max(q_dotdot_bounds_max(0, 0));
save_q_dotdot_1_max(q_dotdot_bounds_max(1, 0));
save_q_dotdot_2_max(q_dotdot_bounds_max(2, 0));
save_q_dotdot_3_max(q_dotdot_bounds_max(3, 0));
save_q_dotdot_4_max(q_dotdot_bounds_max(4, 0));
save_q_dotdot_5_max(q_dotdot_bounds_max(5, 0));
save_q_dotdot_6_max(q_dotdot_bounds_max(6, 0));

save_q_dotdot_0_min(q_dotdot_bounds_min(0, 0));
save_q_dotdot_1_min(q_dotdot_bounds_min(1, 0));
save_q_dotdot_2_min(q_dotdot_bounds_min(2, 0));
save_q_dotdot_3_min(q_dotdot_bounds_min(3, 0));
save_q_dotdot_4_min(q_dotdot_bounds_min(4, 0));
save_q_dotdot_5_min(q_dotdot_bounds_min(5, 0));
save_q_dotdot_6_min(q_dotdot_bounds_min(6, 0));



//Celas sont calculés avec les couples maximaux
save_q_dotdot_bounds_max_optimized(q_dotdot_bounds_max_optimized);
save_q_dotdot_bounds_min_optimized(q_dotdot_bounds_min_optimized);




//For the compatible acceleration constraints
save_q_dotdot_0_max_comp(q_dotdot_bounds_max_comp(0, 0));
save_q_dotdot_1_max_comp(q_dotdot_bounds_max_comp(1, 0));
save_q_dotdot_2_max_comp(q_dotdot_bounds_max_comp(2, 0));
save_q_dotdot_3_max_comp(q_dotdot_bounds_max_comp(3, 0));
save_q_dotdot_4_max_comp(q_dotdot_bounds_max_comp(4, 0));
save_q_dotdot_5_max_comp(q_dotdot_bounds_max_comp(5, 0));
save_q_dotdot_6_max_comp(q_dotdot_bounds_max_comp(6, 0));

save_q_dotdot_0_min_comp(q_dotdot_bounds_min_comp(0, 0));
save_q_dotdot_1_min_comp(q_dotdot_bounds_min_comp(1, 0));
save_q_dotdot_2_min_comp(q_dotdot_bounds_min_comp(2, 0));
save_q_dotdot_3_min_comp(q_dotdot_bounds_min_comp(3, 0));
save_q_dotdot_4_min_comp(q_dotdot_bounds_min_comp(4, 0));
save_q_dotdot_5_min_comp(q_dotdot_bounds_min_comp(5, 0));
save_q_dotdot_6_min_comp(q_dotdot_bounds_min_comp(6, 0));

save_q_dot_bounds_max_comp_Acc_Posi_vel_cmd(q_dot_bounds_max_comp_Acc_Posi_vel_cmd(0, 0));
save_q_dot_bounds_min_comp_Acc_Posi_vel_cmd(q_dot_bounds_min_comp_Acc_Posi_vel_cmd(0, 0));

save_n_neg_acc_posi(n_neg_acc_posi);
save_n_pos_acc_posi(n_pos_acc_posi);
save_n_neg_jerk_vel(n_neg_jerk_vel);
save_n_pos_jerk_vel(n_pos_jerk_vel);
save_n_neg_jerk_posi(n_neg_jerk_posi);
save_n_pos_jerk_posi(n_pos_jerk_posi);
save_n_neg_jerk_posi_explored(n_neg_jerk_posi_explored);
save_n_pos_jerk_posi_explored(n_pos_jerk_posi_explored);
save_n_neg_jerk_posi_P3(n_neg_jerk_posi_P3);
save_n_pos_jerk_posi_P3(n_pos_jerk_posi_P3);


save_n1_neg_jerk_acc_posi(n1_neg_jerk_acc_posi);     
save_n1_pos_jerk_acc_posi(n1_pos_jerk_acc_posi);
save_n2_neg_jerk_acc_posi(n2_neg_jerk_acc_posi);     
save_n2_pos_jerk_acc_posi(n2_pos_jerk_acc_posi);
save_n_neg_jerk_acc_posi(n_neg_jerk_acc_posi);
save_n_pos_jerk_acc_posi(n_pos_jerk_acc_posi);


/*
//Plot lorsque la contrainte sur l'énergie cinétique est exprimée sous forme quadratique 
save_E_7(constr_7_Quad.getValue());
save_E_7_max(Ec_max_7);

save_d_06_ob(dist_07_nrst_ob);
save_E_6(constr_7_Quad.getValue());
save_E_6_max(Ec_max_7);

save_d_05_ob(dist_07_nrst_ob);
save_E_5(constr_7_Quad.getValue());
save_E_5_max(Ec_max_7);

save_d_04_ob(dist_07_nrst_ob);
save_E_4(constr_7_Quad.getValue());
save_E_4_max(Ec_max_7);

save_d_03_ob(dist_07_nrst_ob);
save_E_3(constr_7_Quad.getValue());
save_E_3_max(Ec_max_7);

save_d_02_ob(dist_07_nrst_ob);
save_E_2(constr_7_Quad.getValue());
save_E_2_max(Ec_max_7);
*/







/*
double E_7_rebuilt = 0.5 * m_eq_7_j * pow(constr_7_Lin_Ec_C_ob.getValue(), 2);
//Plot lorsque la contrainte sur l'énergie cinétique est exprimée sous forme linéaire
save_E_7(E_7_rebuilt);
save_E_7_max(E_max_7);

save_d_06_ob(dist_07_nrst_ob);
save_E_6(E_7_rebuilt);
save_E_6_max(E_max_7);

save_d_05_ob(dist_07_nrst_ob);
save_E_5(E_7_rebuilt);
save_E_5_max(E_max_7);

save_d_04_ob(dist_07_nrst_ob);
save_E_4(E_7_rebuilt);
save_E_4_max(E_max_7);

save_d_03_ob(dist_07_nrst_ob);
save_E_3(E_7_rebuilt);
save_E_3_max(E_max_7);Ep_max

save_d_02_ob(dist_07_nrst_ob);
save_E_2(E_7_rebuilt);
save_E_2_max(E_max_7);
*/












/*
save_d_07_ob(dist_07_nrst_ob);
save_E_7(E_max_7);
save_E_7_max(E_max_7);

save_d_06_ob(dist_07_nrst_ob);
save_E_6(E_max_7);
save_E_6_max(E_max_7);

save_d_05_ob(dist_07_nrst_ob);
save_E_5(E_max_7);
save_E_5_max(E_max_7);

save_d_04_ob(dist_07_nrst_ob);
save_E_4(E_max_7);
save_E_4_max(E_max_7);

save_d_03_ob(dist_07_nrst_ob);
save_E_3(E_max_7);Ep_max
save_E_3_max(E_max_7);

save_d_02_ob(dist_07_nrst_ob);
save_E_2(E_max_7);
save_E_2_max(E_max_7);
*/
//-----------------------------------------------------------------------------Save data------------------------------------------------------------//




//-------------------------------------------------------------------------------Debug--------------------------------------------------------------//

   GRBConstr* cs = 0;
   if (status == GRB_INFEASIBLE)
    {
    // do IIS
    cout << "The model is infeasible; computing IIS" << endl;
    model.computeIIS();
    model.write("model.ilp");
    cout << "\nThe following constraint(s) "
    << "cannot be satisfied:" << endl;
    cs = model.getConstrs();
    for (int i = 0; i < model.get(GRB_IntAttr_NumConstrs); ++i)
    {
      if (cs[i].get(GRB_IntAttr_IISConstr) == 1)
      {
        cout << cs[i].get(GRB_StringAttr_ConstrName) << endl;
      }
    }
    for(int appp=0; appp<100000000000; appp++){int toto=5;}
    }
/*
if(status =!2){
while(status =! 2){

int aaa = 1;

}
}
*/
//-------------------------------------------------------------------------------Debug--------------------------------------------------------------//

/*
    //cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;
    cout << "0: " <<  vars[0].get(GRB_DoubleAttr_X) << endl;
    cout << "1: " <<  vars[1].get(GRB_DoubleAttr_X) << endl;
    cout << "2: " <<  vars[2].get(GRB_DoubleAttr_X) << endl;
    cout << "3: " <<  vars[3].get(GRB_DoubleAttr_X) << endl;
    cout << "4: " <<  vars[4].get(GRB_DoubleAttr_X) << endl;
    cout << "5: " <<  vars[5].get(GRB_DoubleAttr_X) << endl;
    cout << "6: " <<  vars[6].get(GRB_DoubleAttr_X) << endl;
    cout << "7: " <<  vars[7].get(GRB_DoubleAttr_X) << endl;
    cout << "8: " <<  vars[8].get(GRB_DoubleAttr_X) << endl;
    cout << "9: " <<  vars[9].get(GRB_DoubleAttr_X) << endl;
    cout << "10: " <<  vars[10].get(GRB_DoubleAttr_X) << endl;
    cout << "11: " <<  vars[11].get(GRB_DoubleAttr_X) << endl;
    cout << "12: " <<  vars[12].get(GRB_DoubleAttr_X) << endl;
    cout << "13: " <<  vars[13].get(GRB_DoubleAttr_X) << endl;
*/
    Eigen::VectorXd tau_final(7);
if(status == GRB_OPTIMAL){

    tau_final << vars[0].get(GRB_DoubleAttr_X), vars[1].get(GRB_DoubleAttr_X), vars[2].get(GRB_DoubleAttr_X), vars[3].get(GRB_DoubleAttr_X), vars[4].get(GRB_DoubleAttr_X), vars[5].get(GRB_DoubleAttr_X), vars[6].get(GRB_DoubleAttr_X);
    q_dot_dot_final << vars[7].get(GRB_DoubleAttr_X), vars[8].get(GRB_DoubleAttr_X), vars[9].get(GRB_DoubleAttr_X), vars[10].get(GRB_DoubleAttr_X), vars[11].get(GRB_DoubleAttr_X), vars[12].get(GRB_DoubleAttr_X), vars[13].get(GRB_DoubleAttr_X);




}
else{
tau_final = gravity_terms;
}  

//-----------------------------------------------------------------------------Save more data------------------------------------------------------------//



/*
Ec_7_rebuilt_QP = constr_7_Quad.getValue();
save_Ec_7(Ec_7_rebuilt_QP);
save_Ec_7_max(Ec_max_7);
*/


/*
Ec_7_rebuilt_lin = 0.5 * m_eq_7_j * pow(constr_7_Lin_Ec_C_ob.getValue(), 2);
save_Ec_7(Ec_7_rebuilt_lin);
save_Ec_7_max(Ec_max_7);
*/

/*
Ep_7_rebuilt_Xerr = constr_7_Lin_Ep_Xerr.getValue() * (m_eq_7_j_Xerr * abs(X_err.norm()));
//µµµµµµ
Ep_7_rebuilt_x    = constr_7_Lin_Ep_x.getValue() * (m_eq_7_j_x_axis * abs(X_err[0]));
//µµµµµµ
Ep_7_rebuilt_y    = constr_7_Lin_Ep_y.getValue() * (m_eq_7_j_y_axis * abs(X_err[1]));
//µµµµµµ
Ep_7_rebuilt_z    = constr_7_Lin_Ep_z.getValue() * (m_eq_7_j_z_axis * abs(X_err[2]));
*/




//Energie cinétique prédite selon x 
V_7_x_nxt_step    = J_70_l_proj_x_axis * (q_dot + (dt * M_inv * (tau_final - b)));
Ec_7_x_nxt_step   = 0.5 *  m_eq_7_j_x_axis *  V_7_x_nxt_step * V_7_x_nxt_step;
double Ec_7_x     = 0.5 *  m_eq_7_j_x_axis *  V_7_posi[0] * V_7_posi[0];
save_Ec_7_x(Ec_7_x);
save_Ec_7_x_nxt_step(Ec_7_x_nxt_step);
save_Ec_max_7_x(Ec_max_7);  //Seuil variable dépendant de la distance à l'obstacl
//save_Ec_max_7_x(Ec_max_7_x);

/*
//Energie cinétique prédite dans la direction de l'obstacle  
V_7_C_ob_nxt_step = J_70_C_proj * (q_dot + (dt * M_inv * (tau_final - b)));
Ec_7_C_ob_nxt_step = 0.5 *  m_eq_7_j *  V_7_C_ob_nxt_step * V_7_C_ob_nxt_step;
save_Ec_7_C_ob_nxt_step(Ec_7_C_ob_nxt_step);
*/




//Energie potentielle réelle selon x et la somme de l'énergie potentielle réelle selon x
Real_Ep_7_x        = Acc_posi_70[0] * (m_eq_7_j_x_axis * abs(X_err_real[0]));
Sum_Real_Ep_7_x    = Sum_Real_Ep_7_x + Real_Ep_7_x; 
save_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x(Sum_Real_Ep_7_x);



//Energie potentielle prédite selon l'axe x et la somme de l'énergie potentielle prédite selon x
Ep_7_x_nxt_step        =  constr_7_Lin_Ep_x.getValue() * (m_eq_7_j_x_axis * abs(X_err_real[0]));
Sum_Ep_7_x_nxt_step    =  Sum_Ep_7_x_nxt_step + Ep_7_x_nxt_step; 
save_Ec_7_x_rcnsrcted_wth_small_Ep_7_x_nxt_step(Sum_Ep_7_x_nxt_step);
save_Ep_7_x_max(Ep_max_x);
save_Ep_real_during_and_before_contact_x(Ep_7_x_nxt_step);

save_m_eq_7_j_Xerr(m_eq_7_j_Xerr);
save_X_err_x_0(abs(X_err[0]));


//next_step Acc_x
Acc_7_x_nxt_step         = constr_7_Lin_Ep_x.getValue();  //constr_7_Lin_Ep_x ne contient en réalité que l'accélération linéaire selon x
save_Acc_7_x_nxt_step(Acc_7_x_nxt_step);
save_Acc_7_x_nxt_step_limit((0.1 - Real_Ec_7_x)/(m_eq_7_j_x_axis * abs(X_err_real[0])));


/*
//Save Force_x nxt_step  (Cas ou les courbes sont tracées avec les contraintes sur l'Ep)
save_force_x_nxt_step(constr_7_Lin_Ep_x.getValue() * m_eq_7_j_x_axis);
save_force_x_nxt_step_limit_max(Ep_max_x/abs(X_err[0]));
save_force_x_nxt_step_limit_min(-Ep_max_x/abs(X_err[0]));
*/

//Save Force_x nxt_step  (Cas ou les courbes sont tracées avec les contraintes sur F directement)
save_Real_robot_force_estimated_x(Acc_posi_70[0] * m_eq_7_j_x_axis); //Force estimée tirant le robot dans la direction X
save_robot_force_x_nxt_step(constr_7_Lin_Ep_x.getValue() * m_eq_7_j_x_axis);
save_robot_force_x_nxt_step_limit_max(F_max_x);
save_robot_force_x_nxt_step_limit_min(-F_max_x);


//Save Force_z nxt_step  (Cas ou les courbes sont tracées avec les contraintes sur F directement)
save_Real_robot_force_estimated_z(Acc_posi_70[2] * m_eq_7_j_z_axis); //Force estimée tirant le robot dans la direction X

before_previous_robot_force_z_nxt_step = previous_robot_force_z_nxt_step;   //Second position in the buffer...this will be used to compute the derivation of pvious_robot_force_z_nxt_step
previous_robot_force_z_nxt_step        = constr_7_Lin_Ep_z.getValue() * m_eq_7_j_z_axis;  //The predicted force during this time step for the next time step.
previous_robot_force_z_nxt_step_derived = (previous_robot_force_z_nxt_step - before_previous_robot_force_z_nxt_step)/dt;

save_robot_force_z_nxt_step(previous_robot_force_z_nxt_step);
save_robot_force_z_nxt_step_limit_max(F_max_z);
save_robot_force_z_nxt_step_limit_min(-F_max_z);

 
//Calcul du jerk en derivant les acc en sortie du colveur
for(u=0; u<7; u++){ 
q_dddot_gurobi[u] = (q_dot_dot_final[u] - q_dot_dot_final_previous[u])/dt;
}
save_q_dotdotdot_gurobi(q_dddot_gurobi);
for(u=0; u<7; u++){ 
q_dot_dot_final_previous[u] = q_dot_dot_final[u];
}





//Save Ep_x_nxt_step
save_Ep_x_nxt_step(constr_7_Lin_Ep_x.getValue() * m_eq_7_j_x_axis * abs(X_err[0]));
save_Ep_x_nxt_step_limit_max(Ep_max_x);
save_Ep_x_nxt_step_limit_min(-Ep_max_x);
save_Real_Ep_x(Force_sensor_3dVector[0] * abs(X_err[0]));

    save_tau_6(tau_final(6) + gravity_terms(6));
    save_tau_5(tau_final(5) + gravity_terms(5));
    save_tau_4(tau_final(4) + gravity_terms(4));
    save_tau_3(tau_final(3) + gravity_terms(3));
    save_tau_2(tau_final(2) + gravity_terms(2));
    save_tau_1(tau_final(1) + gravity_terms(1));
    save_tau_0(tau_final(0) + gravity_terms(0));


    save_tau_6_max(tau_max(6, 0));
    save_tau_5_max(tau_max(5, 0));
    save_tau_4_max(tau_max(4, 0));
    save_tau_3_max(tau_max(3, 0));
    save_tau_2_max(tau_max(2, 0));
    save_tau_1_max(tau_max(1, 0));
    save_tau_0_max(tau_max(0, 0));
    save_tau_6_min(tau_min(6, 0));
    save_tau_5_min(tau_min(5, 0));
    save_tau_4_min(tau_min(4, 0));
    save_tau_3_min(tau_min(3, 0));
    save_tau_2_min(tau_min(2, 0));
    save_tau_1_min(tau_min(1, 0));
    save_tau_0_min(tau_min(0, 0));

    save_q_dotdot_6(q_dot_dot_final(6));
    save_q_dotdot_5(q_dot_dot_final(5));
    save_q_dotdot_4(q_dot_dot_final(4));
    save_q_dotdot_3(q_dot_dot_final(3));
    save_q_dotdot_2(q_dot_dot_final(2));
    save_q_dotdot_1(q_dot_dot_final(1));
    save_q_dotdot_0(q_dot_dot_final(0));

    save_q_dotdot_real_6(q_ddot[6]);
    save_q_dotdot_real_5(q_ddot[5]);
    save_q_dotdot_real_4(q_ddot[4]);
    save_q_dotdot_real_3(q_ddot[3]);
    save_q_dotdot_real_2(q_ddot[2]);
    save_q_dotdot_real_1(q_ddot[1]);
    save_q_dotdot_real_0(q_ddot[0]);



    double dynamic_1 = M(0, 0) * q_dot_dot_final[0] + M(0, 1) * q_dot_dot_final[1] + M(0, 2) * q_dot_dot_final[2] + M(0, 3) * q_dot_dot_final[3] + M(0, 4) * q_dot_dot_final[4] + M(0, 5) * q_dot_dot_final[5] + M(0, 6) * q_dot_dot_final[6]  + b(0, 0) - tau_final[0];
    double dynamic_2 = M(1, 0) * q_dot_dot_final[0] + M(1, 1) * q_dot_dot_final[1] + M(1, 2) * q_dot_dot_final[2] + M(1, 3) * q_dot_dot_final[3] + M(1, 4) * q_dot_dot_final[4] + M(1, 5) * q_dot_dot_final[5] + M(1, 6) * q_dot_dot_final[6]  + b(1, 0) - tau_final[1];
    double dynamic_3 = M(2, 0) * q_dot_dot_final[0] + M(2, 1) * q_dot_dot_final[1] + M(2, 2) * q_dot_dot_final[2] + M(2, 3) * q_dot_dot_final[3] + M(2, 4) * q_dot_dot_final[4] + M(2, 5) * q_dot_dot_final[5] + M(2, 6) * q_dot_dot_final[6]  + b(2, 0) - tau_final[2];
    double dynamic_4 = M(3, 0) * q_dot_dot_final[0] + M(3, 1) * q_dot_dot_final[1] + M(3, 2) * q_dot_dot_final[2] + M(3, 3) * q_dot_dot_final[3] + M(3, 4) * q_dot_dot_final[4] + M(3, 5) * q_dot_dot_final[5] + M(3, 6) * q_dot_dot_final[6]  + b(3, 0) - tau_final[3];
    double dynamic_5 = M(4, 0) * q_dot_dot_final[0] + M(4, 1) * q_dot_dot_final[1] + M(4, 2) * q_dot_dot_final[2] + M(4, 3) * q_dot_dot_final[3] + M(4, 4) * q_dot_dot_final[4] + M(4, 5) * q_dot_dot_final[5] + M(4, 6) * q_dot_dot_final[6]  + b(4, 0) - tau_final[4];
    double dynamic_6 = M(5, 0) * q_dot_dot_final[0] + M(5, 1) * q_dot_dot_final[1] + M(5, 2) * q_dot_dot_final[2] + M(5, 3) * q_dot_dot_final[3] + M(5, 4) * q_dot_dot_final[4] + M(5, 5) * q_dot_dot_final[5] + M(5, 6) * q_dot_dot_final[6]  + b(5, 0) - tau_final[5];
    double dynamic_7 = M(6, 0) * q_dot_dot_final[0] + M(6, 1) * q_dot_dot_final[1] + M(6, 2) * q_dot_dot_final[2] + M(6, 3) * q_dot_dot_final[3] + M(6, 4) * q_dot_dot_final[4] + M(6, 5) * q_dot_dot_final[5] + M(6, 6) * q_dot_dot_final[6]  + b(6, 0) - tau_final[6]; 
    save_dynamic(dynamic_1, dynamic_2, dynamic_3, dynamic_4, dynamic_5, dynamic_6, dynamic_7); //Pour vérifier que l'équation dynamique du système est bien respectée

    save_M_q_dotdot_0(M(0, 0) * q_dot_dot_final[0] + M(0, 1) * q_dot_dot_final[1] + M(0, 2) * q_dot_dot_final[2] + M(0, 3) * q_dot_dot_final[3] + M(0, 4) * q_dot_dot_final[4] + M(0, 5) * q_dot_dot_final[5] + M(0, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_1(M(1, 0) * q_dot_dot_final[0] + M(1, 1) * q_dot_dot_final[1] + M(1, 2) * q_dot_dot_final[2] + M(1, 3) * q_dot_dot_final[3] + M(1, 4) * q_dot_dot_final[4] + M(1, 5) * q_dot_dot_final[5] + M(1, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_2(M(2, 0) * q_dot_dot_final[0] + M(2, 1) * q_dot_dot_final[1] + M(2, 2) * q_dot_dot_final[2] + M(2, 3) * q_dot_dot_final[3] + M(2, 4) * q_dot_dot_final[4] + M(2, 5) * q_dot_dot_final[5] + M(2, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_3(M(3, 0) * q_dot_dot_final[0] + M(3, 1) * q_dot_dot_final[1] + M(3, 2) * q_dot_dot_final[2] + M(3, 3) * q_dot_dot_final[3] + M(3, 4) * q_dot_dot_final[4] + M(3, 5) * q_dot_dot_final[5] + M(3, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_4(M(4, 0) * q_dot_dot_final[0] + M(4, 1) * q_dot_dot_final[1] + M(4, 2) * q_dot_dot_final[2] + M(4, 3) * q_dot_dot_final[3] + M(4, 4) * q_dot_dot_final[4] + M(4, 5) * q_dot_dot_final[5] + M(4, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_5(M(5, 0) * q_dot_dot_final[0] + M(5, 1) * q_dot_dot_final[1] + M(5, 2) * q_dot_dot_final[2] + M(5, 3) * q_dot_dot_final[3] + M(5, 4) * q_dot_dot_final[4] + M(5, 5) * q_dot_dot_final[5] + M(5, 6) * q_dot_dot_final[6]);
    save_M_q_dotdot_6(M(6, 0) * q_dot_dot_final[0] + M(6, 1) * q_dot_dot_final[1] + M(6, 2) * q_dot_dot_final[2] + M(6, 3) * q_dot_dot_final[3] + M(6, 4) * q_dot_dot_final[4] + M(6, 5) * q_dot_dot_final[5] + M(6, 6) * q_dot_dot_final[6]);

    save_b_0(b(0, 0));
    save_b_1(b(1, 0));
    save_b_2(b(2, 0));
    save_b_3(b(3, 0));
    save_b_4(b(4, 0));
    save_b_5(b(5, 0));
    save_b_6(b(6, 0));

    save_X_dot_dot(sqrt(pow(X_dot_dot(0, 0),2) + pow(X_dot_dot(1, 0),2) + pow(X_dot_dot(2, 0),2)));
    save_X_dot_dot_x(X_dot_dot(0, 0));
    save_X_dot_dot_y(X_dot_dot(1, 0));
    save_X_dot_dot_z(X_dot_dot(2, 0));

    save_X_dot_dot_des(sqrt(pow(X_dot_dot_des_rot_posi(3, 0),2) + pow(X_dot_dot_des_rot_posi(4, 0),2) + pow(X_dot_dot_des_rot_posi(5, 0),2)));
    save_X_dot_dot_des_x(X_dot_dot_des_rot_posi(3, 0));
    save_X_dot_dot_des_y(X_dot_dot_des_rot_posi(4, 0));
    save_X_dot_dot_des_z(X_dot_dot_des_rot_posi(5, 0));


    save_kp_X_err_0(kp * X_err(0));
    save_kp_X_err_1(kp * X_err(1));
    save_kp_X_err_2(kp * X_err(2));

    save_kd_V_7_l_0(kd * V_7[3]);
    save_kd_V_7_l_1(kd * V_7[4]);
    save_kd_V_7_l_2(kd * V_7[5]);


Eigen::FullPivLU<Matrix3x7>  lu_decomp(J_70_l);
//cout << "The rank of J_70_l is " << lu_decomp.rank() << endl;

    save_rank_J_70_l(lu_decomp.rank());


    save_K_p_X_err(sqrt(pow(K_p_X_err(0, 0),2) + pow(K_p_X_err(1, 0),2) + pow(K_p_X_err(2, 0),2)));
    save_K_p_X_err_0(K_p_X_err(0, 0));
    save_K_p_X_err_1(K_p_X_err(1, 0));
    save_K_p_X_err_2(K_p_X_err(2, 0));


    save_K_d_V_7_err(sqrt(pow(K_d_V_7_err(0, 0),2) + pow(K_d_V_7_err(1, 0),2) + pow(K_d_V_7_err(2, 0),2)));
    save_K_d_V_7_err_0(K_d_V_7_err(0, 0));
    save_K_d_V_7_err_1(K_d_V_7_err(1, 0));
    save_K_d_V_7_err_2(K_d_V_7_err(2, 0));


    save_Acc_7_des(sqrt(pow(Acc_7_des[0],2) + pow(Acc_7_des[1],2) + pow(Acc_7_des[2],2)));
    save_Acc_7_des_x(Acc_7_des[0]);
    save_Acc_7_des_y(Acc_7_des[1]);
    save_Acc_7_des_z(Acc_7_des[2]);
//-----------------------------------------------------------------------------Save more data------------------------------------------------------------//


    return tau_final;
} 


    catch(GRBException e) {
    cout << "Error code = " << e.getErrorCode() << endl;
    cout << e.getMessage() << endl;
    } 


    catch(...) {
    cout << "Exception during optimization" << endl;
    }







}




