#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <iostream>
#include <cassert>
#include <math.h>       
#include "Compute_energy.h"
#include "Compute_prj_velocity.h"
#include "save_data_in_txt.h"
#include "/home/anis/libs/gurobi563/linux64/include/gurobi_c++.h"
#include "QP.h"

using std::cout;
using std::endl;
using namespace std;
Eigen::VectorXd q_dot_dot_final(7);
int one_time_decl = 1;


Eigen::VectorXd optimize_QP(Eigen::Matrix<double, 3, 7> J_70_l, 
                            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M, 
                            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_inv, 
			    Eigen::Matrix<double, 7, 1> b,
			    Eigen::Matrix<double, 3, 1> Jdot_qdot_l,
			    Eigen::VectorXd X_err,
			    Eigen::Twistd V_7,
			    Eigen::VectorXd V_7_des,
			    Eigen::VectorXd Acc_7_des,
                            double kp,
			    double kd, 
		            double d_safe,
			    double d_max, 
			    double E_safe,
                            double E_max_7, double E_max_6, double E_max_5, double E_max_4, double E_max_3, double E_max_2,
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
			    Eigen::Matrix<double, 7, 1> q_dot,
                            double dt,			  
                            double m_eq_7_j,
                            double m_eq_6_j,
                            double m_eq_5_j,
                            double m_eq_4_j,
                            double m_eq_3_j,
                            double m_eq_2_j,
			    Eigen::Matrix<double, 7, 1> q_dotdot_bounds,
			    double dist_07_nrst_ob,
			    double dist_06_nrst_ob,
			    double dist_05_nrst_ob,
			    double dist_04_nrst_ob,
			    double dist_03_nrst_ob,
			    double dist_02_nrst_ob,
			    Eigen::Matrix<double, 7, 1> gravity_terms)

{
 
  try {
//---------------------------------------------------------------Create the environment and the variables------------------------------------------//
  GRBEnv env = GRBEnv();
  GRBModel model = GRBModel(env);

  // Create variables
  int cols = 7; //Nombre de variables

  /* Add variables to the model */
  GRBVar* vars = model.addVars(14, GRB_CONTINUOUS);


  vars[0] = model.addVar(-200, 200, 0.0, GRB_CONTINUOUS, "tau_0");
  vars[1] = model.addVar(-200, 200, 0.0, GRB_CONTINUOUS, "tau_1");
  vars[2] = model.addVar(-100, 100, 0.0, GRB_CONTINUOUS, "tau_2");
  vars[3] = model.addVar(-100, 100, 0.0, GRB_CONTINUOUS, "tau_3");
  vars[4] = model.addVar(-100, 100, 0.0, GRB_CONTINUOUS, "tau_4");
  vars[5] = model.addVar(-30, 30, 0.0, GRB_CONTINUOUS, "tau_5");
  vars[6] = model.addVar(-30, 30, 0.0, GRB_CONTINUOUS, "tau_6");



  vars[7]  = model.addVar(-abs(q_dotdot_bounds(0, 0)), abs(q_dotdot_bounds(0, 0)), 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(-abs(q_dotdot_bounds(1, 0)), abs(q_dotdot_bounds(1, 0)), 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(-abs(q_dotdot_bounds(2, 0)), abs(q_dotdot_bounds(2, 0)), 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(-abs(q_dotdot_bounds(3, 0)), abs(q_dotdot_bounds(3, 0)), 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(-abs(q_dotdot_bounds(4, 0)), abs(q_dotdot_bounds(4, 0)), 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(-abs(q_dotdot_bounds(5, 0)), abs(q_dotdot_bounds(5, 0)), 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(-abs(q_dotdot_bounds(6, 0)), abs(q_dotdot_bounds(6, 0)), 0.0, GRB_CONTINUOUS, "q_dd_6");

/*
  vars[7]  = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_0");
  vars[8]  = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_1");
  vars[9]  = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_2");
  vars[10] = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_3");
  vars[11] = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_4");
  vars[12] = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_5");
  vars[13] = model.addVar(-1e12, 1e12, 0.0, GRB_CONTINUOUS, "q_dd_6");
*/

  model.update();
     

  int i, j;
//---------------------------------------------------------------Create the environment and the variables------------------------------------------//







//--------------------------------------------------------------------Construction de la fonction objectif-----------------------------------------//
    //La fonction objectif est de la forme : f(tau)   = tau.tranpose() * Q * tau + (2 * t.transpose() * J_70_l * M_inv) * tau + t.transpose() * t;
    //                                       With : Q = (J_70_l * M_inv).transpose() * (J_70_l * M_inv)
    //                                              t = (Jdot_qdot_l - (J_70_l * M_inv * b)) - X_dotdot_des
double epsilon_q_dot_dot = 1e-6; 
double epsilon_tau = 1e-6;
/*
kp = 2200; //for maxAcc 5.0 ou 10.0
kd = 70;
*/


kp = 2450;   //for maxAcc 30.0
kd = 45;

    Eigen::Matrix<double, 3, 7> J_70_l_by_M_inv;
    J_70_l_by_M_inv = J_70_l * M_inv;               				  //size 3*7
    Eigen::Matrix<double, 7, 7> Q_tau;          				  //Matrice Q de la fonction objectif
    Q_tau = J_70_l_by_M_inv.transpose() * J_70_l_by_M_inv;


    Eigen::Matrix<double, 3, 1> X_dot_dot_des; 
      X_dot_dot_des = kp* X_err - kd * V_7.block<3,1>(3,0);
     //X_dot_dot_des = kp* X_err + kd * (V_7_des - V_7.block<3,1>(3,0));
    //X_dot_dot_des = Acc_7_des + kp* X_err + kd * (V_7_des - V_7.block<3,1>(3,0));

    Eigen::Matrix<double, 3, 1> t_tau;           				  //Matrice c de la partie linéaire de la fonction objectif
    t_tau =  (Jdot_qdot_l - (J_70_l_by_M_inv * b)) - X_dot_dot_des;  		  //3*1

    Eigen::Matrix<double, 1, 7> b_tau;                   			  //Matrice c de la partie linéaire de la fonction objectif
    b_tau = 2 * t_tau.transpose() * J_70_l_by_M_inv;


   //Ecriture de la fonction quadratique de l'objectif
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


     for (j = 0; i < cols; j++){
         obj_Quad += epsilon_q_dot_dot * vars[7+i] * vars[7+i];                  //Pas important
         }


     for (j = 0; i < cols; j++){
         obj_Quad += epsilon_tau * vars[i] * vars[i];                             //Pas important
         }




   double obj_cte = t_tau.transpose() * t_tau;
   model.setObjective(obj_Quad + obj_lin + obj_cte, GRB_MINIMIZE);



/*
   //Compute Eigen Values just to verify PSD
   Eigen::EigenSolver<Eigen::MatrixXd> es_Q(Q_eigen, false);
   cout << "   " << endl;
   cout << "M_inv" << endl;
   cout <<  M_inv << endl;
   cout << "   " << endl;
   cout << "J_70_l" << endl;
   cout <<  J_70_l << endl;
   cout << "   " << endl;
   cout << "J_70_l_by_M_inv" << endl;
   cout <<  J_70_l_by_M_inv << endl;
   cout << "   " << endl;
   cout << "Q_eigen" << endl;
   cout <<  Q_eigen << endl;
   cout << "   " << endl;
   cout << "The eigenvalues of Q:"
   << endl << es_Q.eigenvalues() << endl;
   cout << "   " << endl;
*/
//-------------------------------------------------------------------- Construction de la fonction objectif -----------------------------------------//



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
    int sgn_7 =know_sign(J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());


    GRBLinExpr J_60_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_60_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_60_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    int sgn_6 =know_sign(J_60_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());
 


    GRBLinExpr J_50_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_50_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_50_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    int sgn_5 =know_sign(J_50_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());
 



    GRBLinExpr J_40_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_40_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_40_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    int sgn_4 =know_sign(J_40_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());
 



    GRBLinExpr J_30_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_30_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_30_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    int sgn_3 =know_sign(J_30_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());




    GRBLinExpr J_20_C_proj_by_q_dot_plus_M_inv_by_tau_b;
    for(int i=0; i<7; i++){
        J_20_C_proj_by_q_dot_plus_M_inv_by_tau_b += J_20_C_proj(i) * q_dot_plus_M_inv_by_tau_b[i];
    }
    int sgn_2 =know_sign(J_20_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant());

//----------------------------------------------------------- Calcul de la vitesse de l'efecteur et de son signe ------------------------------------//



//Contraintes égalitaires du model dynamique
    model.addConstr(M(0, 0) * vars[7] + M(0, 1) * vars[8] + M(0, 2) * vars[9] + M(0, 3) * vars[10] + M(0, 4) * vars[11] + M(0, 5) * vars[12] + M(0, 6) * vars[13]  + b(0, 0) == vars[0], "c0");
    model.update();

    model.addConstr(M(1, 0) * vars[7] + M(1, 1) * vars[8] + M(1, 2) * vars[9] + M(1, 3) * vars[10] + M(1, 4) * vars[11] + M(1, 5) * vars[12] + M(1, 6) * vars[13]  + b(1, 0) == vars[1], "c1");
    model.update();


    model.addConstr(M(2, 0) * vars[7] + M(2, 1) * vars[8] + M(2, 2) * vars[9] + M(2, 3) * vars[10] + M(2, 4) * vars[11] + M(2, 5) * vars[12] + M(2, 6) * vars[13]  + b(2, 0) == vars[2], "c2");
    model.update();


    model.addConstr(M(3, 0) * vars[7] + M(3, 1) * vars[8] + M(3, 2) * vars[9] + M(3, 3) * vars[10] + M(3, 4) * vars[11] + M(3, 5) * vars[12] + M(3, 6) * vars[13]  + b(3, 0) == vars[3], "c3");
    model.update();


    model.addConstr(M(4, 0) * vars[7] + M(4, 1) * vars[8] + M(4, 2) * vars[9] + M(4, 3) * vars[10] + M(4, 4) * vars[11] + M(4, 5) * vars[12] + M(4, 6) * vars[13]  + b(4, 0) == vars[4], "c4");
    model.update();


    model.addConstr(M(5, 0) * vars[7] + M(5, 1) * vars[8] + M(5, 2) * vars[9] + M(5, 3) * vars[10] + M(5, 4) * vars[11] + M(5, 5) * vars[12] + M(5, 6) * vars[13]  + b(5, 0) == vars[5], "c5");
    model.update();


    model.addConstr(M(6, 0) * vars[7] + M(6, 1) * vars[8] + M(6, 2) * vars[9] + M(6, 3) * vars[10] + M(6, 4) * vars[11] + M(6, 5) * vars[12] + M(6, 6) * vars[13]  + b(6, 0) == vars[6], "c6");
    model.update();





/*
if(one_time_decl == 1){
q_dot_dot_final << 0, 0, 0, 0, 0, 0, 0;
one_time_decl = 0;
}


//Contraintes sur le Jerk articulaire
    model.addConstr((vars[7] - q_dot_dot_final[0]) / dt <=  10000 , "c7");
    model.addConstr((vars[7] - q_dot_dot_final[0]) / dt >= -10000 , "c8");
    model.update();

    model.addConstr((vars[8] - q_dot_dot_final[1]) / dt <=  10000 , "c9");
    model.addConstr((vars[8] - q_dot_dot_final[1]) / dt >= -10000 , "c10");
    model.update();

    model.addConstr((vars[9] - q_dot_dot_final[2]) / dt <=  10000 , "c11");
    model.addConstr((vars[9] - q_dot_dot_final[2]) / dt >= -10000 , "c12");
    model.update();

    model.addConstr((vars[10] - q_dot_dot_final[3]) / dt <=  10000 , "c13");
    model.addConstr((vars[10] - q_dot_dot_final[3]) / dt >= -10000 , "c14");
    model.update();

    model.addConstr((vars[11] - q_dot_dot_final[4]) / dt <=  10000 , "c15");
    model.addConstr((vars[11] - q_dot_dot_final[4]) / dt >= -10000 , "c16");
    model.update();

    model.addConstr((vars[12] - q_dot_dot_final[5]) / dt <=  10000 , "c17");
    model.addConstr((vars[12] - q_dot_dot_final[5]) / dt >= -10000 , "c18");
    model.update();

    model.addConstr((vars[13] - q_dot_dot_final[6]) / dt <=  10000 , "c19");
    model.addConstr((vars[13] - q_dot_dot_final[6]) / dt >= -10000 , "c20");
    model.update();
*/


//Contraintes sur les vitesses articulaires

/*
    model.addConstr(q_dot[0] + dt * vars[7] <=  1.9, "c7"); 
    model.addConstr(q_dot[0] + dt * vars[7] >= -1.9, "c8"); 
    model.update();

    model.addConstr(q_dot[1] + dt * vars[8]  <=  1.9, "c9");
    model.addConstr(q_dot[1] + dt * vars[8]  >= -1.9, "c10"); 
    model.update();


    model.addConstr(q_dot[2] + dt * vars[9]  <=  1.9, "c11");
    model.addConstr(q_dot[2] + dt * vars[9]  >= -1.9, "c45");  
    model.update();


    model.addConstr(q_dot[3] + dt * vars[10]  <=  1.9, "c13");
    model.addConstr(q_dot[3] + dt * vars[10]  >= -1.9, "c14");  
    model.update();


    model.addConstr(q_dot[4] + dt * vars[11]  <=  3.14, "c15");
    model.addConstr(q_dot[4] + dt * vars[11]  >= -3.14, "c16");  
    model.update();


    model.addConstr(q_dot[5] + dt * vars[12]  <=  1.9, "c17");
    model.addConstr(q_dot[5] + dt * vars[12]  >= -1.9, "c18");  
    model.update();


    model.addConstr(q_dot[6] + dt * vars[13]  <=  1.9, "c19");
    model.addConstr(q_dot[6] + dt * vars[13]  >= -1.9, "c20");  
    model.update();
*/


/*
    model.addConstr(q_dot(0, 0) + dt *   <=  1.9, "c7"); 
    model.addConstr(q_dot(0, 0) + dt *   >= -1.9, "c8"); 
    model.update();

    model.addConstr(q_dot(1, 0) + dt * (M_inv(1, 0) * (vars[0] - b(0, 0)) + M_inv(1, 1) * (vars[1] - b(1, 0)) + M_inv(1, 2) * (vars[2] - b(2, 0)) + M_inv(1, 3) * (vars[3] - b(3, 0)) + M_inv(1, 4) * (vars[4] - b(4, 0)) + M_inv(1, 5) * (vars[5] - b(5, 0)) + M_inv(1, 6) * (vars[6] - b(6, 0)))  <=  1.9, "c9");
    //model.addConstr(q_dot(1, 0) + dt * (M_inv(1, 0) * (vars[0] - b(0, 0)) + M_inv(1, 1) * (vars[1] - b(1, 0)) + M_inv(1, 2) * (vars[2] - b(2, 0)) + M_inv(1, 3) * (vars[3] - b(3, 0)) + M_inv(1, 4) * (vars[4] - b(4, 0)) + M_inv(1, 5) * (vars[5] - b(5, 0)) + M_inv(1, 6) * (vars[6] - b(6, 0)))  >= -1.9, "c10"); ; 
    model.update();


    model.addConstr(q_dot(2, 0) + dt * (M_inv(2, 0) * (vars[0] - b(0, 0)) + M_inv(2, 1) * (vars[1] - b(1, 0)) + M_inv(2, 2) * (vars[2] - b(2, 0)) + M_inv(2, 3) * (vars[3] - b(3, 0)) + M_inv(2, 4) * (vars[4] - b(4, 0)) + M_inv(2, 5) * (vars[5] - b(5, 0)) + M_inv(2, 6) * (vars[6] - b(6, 0)))  <=  1.9, "c11");
    //model.addConstr(q_dot(2, 0) + dt * (M_inv(2, 0) * (vars[0] - b(0, 0)) + M_inv(2, 1) * (vars[1] - b(1, 0)) + M_inv(2, 2) * (vars[2] - b(2, 0)) + M_inv(2, 3) * (vars[3] - b(3, 0)) + M_inv(2, 4) * (vars[4] - b(4, 0)) + M_inv(2, 5) * (vars[5] - b(5, 0)) + M_inv(2, 6) * (vars[6] - b(6, 0)))  >= -1.9, "c45");  
    model.update();


    model.addConstr(q_dot(3, 0) + dt * (M_inv(3, 0) * (vars[0] - b(0, 0)) + M_inv(3, 1) * (vars[1] - b(1, 0)) + M_inv(3, 2) * (vars[2] - b(2, 0)) + M_inv(3, 3) * (vars[3] - b(3, 0)) + M_inv(3, 4) * (vars[4] - b(4, 0)) + M_inv(3, 5) * (vars[5] - b(5, 0)) + M_inv(3, 6) * (vars[6] - b(6, 0)))  <=  1.9, "c13");
    //model.addConstr(q_dot(3, 0) + dt * (M_inv(3, 0) * (vars[0] - b(0, 0)) + M_inv(3, 1) * (vars[1] - b(1, 0)) + M_inv(3, 2) * (vars[2] - b(2, 0)) + M_inv(3, 3) * (vars[3] - b(3, 0)) + M_inv(3, 4) * (vars[4] - b(4, 0)) + M_inv(3, 5) * (vars[5] - b(5, 0)) + M_inv(3, 6) * (vars[6] - b(6, 0)))  <= -1.9, "c14");  
    model.update();


    model.addConstr(q_dot(4, 0) + dt * (M_inv(4, 0) * (vars[0] - b(0, 0)) + M_inv(4, 1) * (vars[1] - b(1, 0)) + M_inv(4, 2) * (vars[2] - b(2, 0)) + M_inv(4, 3) * (vars[3] - b(3, 0)) + M_inv(4, 4) * (vars[4] - b(4, 0)) + M_inv(4, 5) * (vars[5] - b(5, 0)) + M_inv(4, 6) * (vars[6] - b(6, 0)))  <=  3.14, "c15");
    //model.addConstr(q_dot(4, 0) + dt * (M_inv(4, 0) * (vars[0] - b(0, 0)) + M_inv(4, 1) * (vars[1] - b(1, 0)) + M_inv(4, 2) * (vars[2] - b(2, 0)) + M_inv(4, 3) * (vars[3] - b(3, 0)) + M_inv(4, 4) * (vars[4] - b(4, 0)) + M_inv(4, 5) * (vars[5] - b(5, 0)) + M_inv(4, 6) * (vars[6] - b(6, 0)))  >= -3.14, "c16");  
    model.update();


    model.addConstr(q_dot(5, 0) + dt * (M_inv(5, 0) * (vars[0] - b(0, 0)) + M_inv(5, 1) * (vars[1] - b(1, 0)) + M_inv(5, 2) * (vars[2] - b(2, 0)) + M_inv(5, 3) * (vars[3] - b(3, 0)) + M_inv(5, 4) * (vars[4] - b(4, 0)) + M_inv(5, 5) * (vars[5] - b(5, 0)) + M_inv(5, 6) * (vars[6] - b(6, 0)))  <=  1.9, "c17");
    //model.addConstr(q_dot(5, 0) + dt * (M_inv(5, 0) * (vars[0] - b(0, 0)) + M_inv(5, 1) * (vars[1] - b(1, 0)) + M_inv(5, 2) * (vars[2] - b(2, 0)) + M_inv(5, 3) * (vars[3] - b(3, 0)) + M_inv(5, 4) * (vars[4] - b(4, 0)) + M_inv(5, 5) * (vars[5] - b(5, 0)) + M_inv(5, 6) * (vars[6] - b(6, 0)))  >= -1.9, "c18");  
    model.update();


    model.addConstr(q_dot(6, 0) + dt * (M_inv(6, 0) * (vars[0] - b(0, 0)) + M_inv(6, 1) * (vars[1] - b(1, 0)) + M_inv(6, 2) * (vars[2] - b(2, 0)) + M_inv(6, 3) * (vars[3] - b(3, 0)) + M_inv(6, 4) * (vars[4] - b(4, 0)) + M_inv(6, 5) * (vars[5] - b(5, 0)) + M_inv(6, 6) * (vars[6] - b(6, 0)))  <=  1.9, "c19");
    //model.addConstr(q_dot(6, 0) + dt * (M_inv(6, 0) * (vars[0] - b(0, 0)) + M_inv(6, 1) * (vars[1] - b(1, 0)) + M_inv(6, 2) * (vars[2] - b(2, 0)) + M_inv(6, 3) * (vars[3] - b(3, 0)) + M_inv(6, 4) * (vars[4] - b(4, 0)) + M_inv(6, 5) * (vars[5] - b(5, 0)) + M_inv(6, 6) * (vars[6] - b(6, 0)))  >= -1.9, "c20");  
    model.update();
*/


//-------------------------------------------------------------------Add of the quadratic constrains------------------------------------------------//


/*
Eigen::Matrix<double, 7, 7> A_eigen_7;           							            //Matrice Q de la premiere fonction de contraite
  A_eigen_7 = (sgn * 0.5 * m_eq_7_j * dt * J_70_C_proj * M_inv).transpose() * (dt * J_70_C_proj * M_inv);

  double g_7;
  g_7 = J_70_C_proj * M_inv * b;
  double a_7 = ((J_70_C_proj * q_dot) - (g_7 * dt));                                                                //g_7 est une variable intermédiaire qui ne sert qu'au calcul. Sinon error lors de la compile                                            
  double Cte_7 = sgn * 0.5 * m_eq_7_j * pow(a_7, 2);
  Eigen::Matrix<double, 1, 7> w_eigen_7;                     							    //Matrice c de la partie linéaire de la premiere fonction de contrainte
  w_eigen_7 = 2 * sgn * 0.5 * m_eq_7_j * a_7  * dt * J_70_C_proj * M_inv;                                           //2 * h * a_7 * a  ; a_7 ici c'est le cte dans le ppapier

  GRBQuadExpr QC_7 = 0;

  for (j = 0; j < cols; j++){
     QC_7 += w_eigen_7(0, j)*vars[j];
     }
  for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         QC_7 += A_eigen_7(i, j) * vars[i] * vars[j];
         }
        }

   QC_7 += sgn * 0.5 * m_eq_7_j * pow(Cte_7, 2);

   //if(E_max_7 >= 0){
      model.addQConstr(QC_7 , '<', E_max_7);
  /* }

   if(E_max_7 < 0){
      model.addQConstr(-QC_7 , '>', E_max_7);
   }*/




//******************************************Contrainte énergétique sur le segment 7******************************************//
/*
    double h_7 = 1 * 0.5 * m_eq_7_j;
    Eigen::Matrix<double, 1, 7> J_70_C_proj_by_M_inv;
    J_70_C_proj_by_M_inv = J_70_C_proj * M_inv; 
    double Cte_7_part_1 = J_70_C_proj * q_dot;   
    double Cte_7_part_2 = dt * J_70_C_proj_by_M_inv  * b;   
    double Cte_7 = Cte_7_part_1 - Cte_7_part_2;
 			
    Eigen::Matrix<double, 7, 7> Q_C_7;          				              //Matrice Q de la fonction objectif
    Q_C_7 = h_7 * dt * (J_70_C_proj_by_M_inv.transpose() * J_70_C_proj_by_M_inv) * dt;        //a(1, 7) ici est = J_70_C_proj_by_M_inv * dt

    Eigen::Matrix<double, 1, 7> b_C_7;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_7 = 2 * h_7 * Cte_7 * (dt * J_70_C_proj_by_M_inv)   ;


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

    //constr_7_Quad = constr_7_Quad;

    model.addQConstr(constr_7_Quad , '<', E_max_7);
    model.update();


  /*cout <<"E_max "<< E_max_7  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_7, false);
 cout << "   " << endl;
 cout << "A_eigen_7" << endl;
 cout <<  A_eigen_7 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_7  << endl;
  cout << " sign :" << know_sign(J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 7******************************************//






//******************************************Contrainte énergétique sur le segment 7******************************************//
/*
    double h_7 = sgn_7 * 0.5 * m_eq_7_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_7;          				              //Matrice Q de la fonction objectif
    Q_C_7 = h_7 * dt * (J_70_C_proj.transpose() * J_70_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_7;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_7 = 2 * h_7 *(q_dot.transpose() * J_70_C_proj.transpose()) * J_70_C_proj * dt;


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

    double constr_7_Cte = h_7 * (q_dot.transpose() * J_70_C_proj.transpose()) * (J_70_C_proj * q_dot);
    constr_7_Quad = constr_7_Quad + constr_7_Cte;

    model.addQConstr(constr_7_Quad , '<', E_max_7);
    model.update();


  /*cout <<"E_max "<< E_max_7  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_7, false);
 cout << "   " << endl;
 cout << "A_eigen_7" << endl;
 cout <<  A_eigen_7 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_7  << endl;
  cout << " sign :" << know_sign(J_70_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 7******************************************//






//******************************************Contrainte énergétique sur le segment 6******************************************//
/*
    double h_6 = sgn_6 * 0.5 * m_eq_6_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_6;          				              //Matrice Q de la fonction objectif
    Q_C_6 = h_6 * dt * (J_60_C_proj.transpose() * J_60_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_6;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_6 = 2 * h_6 *(q_dot.transpose() * J_60_C_proj.transpose()) * J_60_C_proj * dt;


   //Ecriture de la fonction quadratique de la contrainte 6


    GRBQuadExpr constr_6_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_6_Quad += Q_C_6(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_6_Quad += b_C_6(0,j) * vars[j];
     }

    double constr_6_Cte = h_6 * (q_dot.transpose() * J_60_C_proj.transpose()) * (J_60_C_proj * q_dot);
    constr_6_Quad = constr_6_Quad + constr_6_Cte;

    model.addQConstr(constr_6_Quad , '<', E_max_6);
    model.update();


  cout <<"E_max "<< E_max_6  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_6, false);
 cout << "   " << endl;
 cout << "A_eigen_6" << endl;
 cout <<  A_eigen_6 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_6  << endl;
  cout << " sign :" << know_sign(J_60_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 6******************************************//




//******************************************Contrainte énergétique sur le segment 5******************************************//
/*
    double h_5 = sgn_5 * 0.5 * m_eq_5_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_5;          				              //Matrice Q de la fonction objectif
    Q_C_5 = h_5 * dt * (J_50_C_proj.transpose() * J_50_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_5;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_5 = 2 * h_5 *(q_dot.transpose() * J_50_C_proj.transpose()) * J_50_C_proj * dt;


   //Ecriture de la fonction quadratique de la contrainte 5


    GRBQuadExpr constr_5_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_5_Quad += Q_C_5(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_5_Quad += b_C_5(0,j) * vars[j];
     }

    double constr_5_Cte = h_5 * (q_dot.transpose() * J_50_C_proj.transpose()) * (J_50_C_proj * q_dot);
    constr_5_Quad = constr_5_Quad + constr_5_Cte;

    model.addQConstr(constr_5_Quad , '<', E_max_5);
    model.update();


 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_5, false);
 cout << "   " << endl;
 cout << "A_eigen_5" << endl;
 cout <<  A_eigen_5 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_5  << endl;
  cout << " sign :" << know_sign(J_50_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 5******************************************//




//******************************************Contrainte énergétique sur le segment 4******************************************//
/*
    double h_4 = sgn_4 * 0.5 * m_eq_4_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_4;          				              //Matrice Q de la fonction objectif
    Q_C_4 = h_4 * dt * (J_40_C_proj.transpose() * J_40_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_4;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_4 = 2 * h_4 *(q_dot.transpose() * J_40_C_proj.transpose()) * J_40_C_proj * dt;


   //Ecriture de la fonction quadratique de la contrainte 4


    GRBQuadExpr constr_4_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_4_Quad += Q_C_4(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_4_Quad += b_C_4(0,j) * vars[j];
     }

    double constr_4_Cte = h_4 * (q_dot.transpose() * J_40_C_proj.transpose()) * (J_40_C_proj * q_dot);
    constr_4_Quad = constr_4_Quad + constr_4_Cte;

    model.addQConstr(constr_4_Quad , '<', E_max_4);
    model.update();


  /*cout <<"E_max "<< E_max_4  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_4, false);
 cout << "   " << endl;
 cout << "A_eigen_4" << endl;
 cout <<  A_eigen_4 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_4  << endl;
  cout << " sign :" << know_sign(J_40_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 4******************************************//






//******************************************Contrainte énergétique sur le segment 3******************************************//
/*
    double h_3 = sgn_3 * 0.5 * m_eq_3_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_3;          				              //Matrice Q de la fonction objectif
    Q_C_3 = h_3 * dt * (J_30_C_proj.transpose() * J_30_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_3;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_3 = 2 * h_3 *(q_dot.transpose() * J_30_C_proj.transpose()) * J_30_C_proj * dt;


   //Ecriture de la fonction quadratique de la contrainte 3


    GRBQuadExpr constr_3_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_3_Quad += Q_C_3(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_3_Quad += b_C_3(0,j) * vars[j];
     }

    double constr_3_Cte = h_3 * (q_dot.transpose() * J_30_C_proj.transpose()) * (J_30_C_proj * q_dot);
    constr_3_Quad = constr_3_Quad + constr_3_Cte;

    model.addQConstr(constr_3_Quad , '<', E_max_3);
    model.update();


  /*cout <<"E_max "<< E_max_3  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_3, false);
 cout << "   " << endl;
 cout << "A_eigen_3" << endl;
 cout <<  A_eigen_3 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_3  << endl;
  cout << " sign :" << know_sign(J_30_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 3******************************************//






//******************************************Contrainte énergétique sur le segment 2******************************************//
/*
    double h_2 = sgn_2 * 0.5 * m_eq_2_j;
              			
    Eigen::Matrix<double, 7, 7> Q_C_2;          				              //Matrice Q de la fonction objectif
    Q_C_2 = h_2 * dt * (J_20_C_proj.transpose() * J_20_C_proj) * dt;

    Eigen::Matrix<double, 1, 7> b_C_2;                   			              //Matrice c de la partie linéaire de la fonction objectif
    b_C_2 = 2 * h_2 *(q_dot.transpose() * J_20_C_proj.transpose()) * J_20_C_proj * dt;


   //Ecriture de la fonction quadratique de la contrainte 2


    GRBQuadExpr constr_2_Quad = 0;
    for (i = 0; i < cols; i++){
     for (j = 0; j < cols; j++){
         constr_2_Quad += Q_C_2(i, j) * vars[i] * vars[j];
         }
        }

    for (j = 0; j < cols; j++){
     constr_2_Quad += b_C_2(0,j) * vars[j];
     }

    double constr_2_Cte = h_2 * (q_dot.transpose() * J_20_C_proj.transpose()) * (J_20_C_proj * q_dot);
    constr_2_Quad = constr_2_Quad + constr_2_Cte;

    model.addQConstr(constr_2_Quad , '<', E_max_2);
    model.update();


  /*cout <<"E_max "<< E_max_2  << endl;
 /*
 //Compute Eigen Values just to verify PSD
 Eigen::EigenSolver<Eigen::MatrixXd> es_A(A_eigen_2, false);
 cout << "   " << endl;
 cout << "A_eigen_2" << endl;
 cout <<  A_eigen_2 << endl;
 cout << "   " << endl;
 cout << "   " << endl;
 cout << "The eigenvalues of A:"
 << endl << es_A.eigenvalues() << endl;
 cout << "   " << endl;
  model.write("dense.lp");
  cout <<"E_max "<< E_max_2  << endl;
  cout << " sign :" << know_sign(J_20_C_proj_by_q_dot_plus_M_inv_by_tau_b.getConstant()) << endl;
 */
 //******************************************Contrainte énergétique sur le segment 2******************************************//




//-------------------------------------------------------------------Add of the quadratic constrains------------------------------------------------//










//---------------------------------------------------------------------------Optimization-----------------------------------------------------------//
    //Optimize model
/*
    model.getEnv().set(GRB_IntParam_Presolve, -1);
    model.getEnv().set(GRB_IntParam_PreQLinearize , 0);
    model.getEnv().set(GRB_IntParam_NumericFocus , 3);
    model.getEnv().set(GRB_IntParam_IISMethod , 0);
*/
    model.getEnv().set(GRB_IntParam_BarHomogeneous, 1);

    model.optimize();
    int status = model.get(GRB_IntAttr_Status);		//Pour debug
//---------------------------------------------------------------------------Optimization-----------------------------------------------------------//










//-----------------------------------------------------------------------------Save data------------------------------------------------------------//
/*
save_E_7(QC_7.getValue());
save_E_7_max(E_max_7);


save_E_6(QC_6.getValue());
save_E_6_max(E_max_6);


save_E_5(QC_5.getValue());
save_E_5_max(E_max_5);

save_E_4(QC_4.getValue());
save_E_4_max(E_max_4);

save_E_3(QC_3.getValue());
save_E_3_max(E_max_3);

save_E_2(QC_2.getValue());
save_E_2_max(E_max_2);
*/



/*
save_d_07_ob(dist_07_nrst_ob);
save_E_7(constr_7_Quad.getValue());
save_E_7_max(E_max_7);

save_d_06_ob(dist_06_nrst_ob);
save_E_6(constr_7_Quad.getValue());
save_E_6_max(E_max_7);

save_d_05_ob(dist_05_nrst_ob);
save_E_5(constr_7_Quad.getValue());
save_E_5_max(E_max_7);

save_d_04_ob(dist_04_nrst_ob);
save_E_4(constr_7_Quad.getValue());
save_E_4_max(E_max_7);

save_d_03_ob(dist_03_nrst_ob);
save_E_3(constr_7_Quad.getValue());
save_E_3_max(E_max_7);


save_d_02_ob(dist_02_nrst_ob);
save_E_2(constr_7_Quad.getValue());
save_E_2_max(E_max_7);
*/


save_q_dotdot_0_max(abs(q_dotdot_bounds(0, 0)));
save_q_dotdot_1_max(abs(q_dotdot_bounds(1, 0)));
save_q_dotdot_2_max(abs(q_dotdot_bounds(2, 0)));
save_q_dotdot_3_max(abs(q_dotdot_bounds(3, 0)));
save_q_dotdot_4_max(abs(q_dotdot_bounds(4, 0)));
save_q_dotdot_5_max(abs(q_dotdot_bounds(5, 0)));
save_q_dotdot_6_max(abs(q_dotdot_bounds(6, 0)));


save_q_dotdot_0_min(-abs(q_dotdot_bounds(0, 0)));
save_q_dotdot_1_min(-abs(q_dotdot_bounds(1, 0)));
save_q_dotdot_2_min(-abs(q_dotdot_bounds(2, 0)));
save_q_dotdot_3_min(-abs(q_dotdot_bounds(3, 0)));
save_q_dotdot_4_min(-abs(q_dotdot_bounds(4, 0)));
save_q_dotdot_5_min(-abs(q_dotdot_bounds(5, 0)));
save_q_dotdot_6_min(-abs(q_dotdot_bounds(6, 0)));




/*
save_q_dotdot_0_max(500);
save_q_dotdot_1_max(600);
save_q_dotdot_2_max(600);
save_q_dotdot_3_max(600);
save_q_dotdot_4_max(600);
save_q_dotdot_5_max(600);
save_q_dotdot_6_max(600);


save_q_dotdot_0_min(-500);
save_q_dotdot_1_min(-600);
save_q_dotdot_2_min(-600);
save_q_dotdot_3_min(-600);
save_q_dotdot_4_min(-600);
save_q_dotdot_5_min(-600);
save_q_dotdot_6_min(-600);
*/



/*
save_d_07_ob(dist_07_nrst_ob);
save_E_7(constr_7_Quad.getValue());
save_E_7_max(E_max_7);


save_d_06_ob(dist_06_nrst_ob);
save_E_6(constr_7_Quad.getValue());
save_E_6_max(E_max_7);

save_d_05_ob(dist_05_nrst_ob);
save_E_5(constr_7_Quad.getValue());
save_E_5_max(E_max_7);

save_d_04_ob(dist_04_nrst_ob);
save_E_4(constr_7_Quad.getValue());
save_E_4_max(E_max_7);

save_d_03_ob(dist_03_nrst_ob);
save_E_3(constr_7_Quad.getValue());
save_E_3_max(E_max_7);


save_d_02_ob(dist_02_nrst_ob);
save_E_2(constr_7_Quad.getValue());
save_E_2_max(E_max_7);
*/




save_d_07_ob(dist_07_nrst_ob);
save_E_7(E_max_7);
save_E_7_max(E_max_7);

save_d_06_ob(dist_06_nrst_ob);
save_E_6(E_max_7);
save_E_6_max(E_max_7);

save_d_05_ob(dist_05_nrst_ob);
save_E_5(E_max_7);
save_E_5_max(E_max_7);

save_d_04_ob(dist_04_nrst_ob);
save_E_4(E_max_7);
save_E_4_max(E_max_7);

save_d_03_ob(dist_03_nrst_ob);
save_E_3(E_max_7);
save_E_3_max(E_max_7);

save_d_02_ob(dist_02_nrst_ob);
save_E_2(E_max_7);
save_E_2_max(E_max_7);

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
      if (cs[i].get(GRB_IntAttr_IISQConstr) == 1)
      {
        cout << cs[i].get(GRB_StringAttr_QCName) << endl;
      }
    }
    }
//-------------------------------------------------------------------------------Debug--------------------------------------------------------------//


    cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;


    Eigen::VectorXd tau_final(7);
    tau_final << vars[0].get(GRB_DoubleAttr_X), vars[1].get(GRB_DoubleAttr_X), vars[2].get(GRB_DoubleAttr_X), vars[3].get(GRB_DoubleAttr_X), vars[4].get(GRB_DoubleAttr_X), vars[5].get(GRB_DoubleAttr_X), vars[6].get(GRB_DoubleAttr_X);
    q_dot_dot_final << vars[7].get(GRB_DoubleAttr_X), vars[8].get(GRB_DoubleAttr_X), vars[9].get(GRB_DoubleAttr_X), vars[10].get(GRB_DoubleAttr_X), vars[11].get(GRB_DoubleAttr_X), vars[12].get(GRB_DoubleAttr_X), vars[13].get(GRB_DoubleAttr_X);
    //tau_final = (M * q_dot_dot_final) + b;

   



//-----------------------------------------------------------------------------Save more data------------------------------------------------------------//
    double V_7_C_ob_t2 = J_70_C_proj * (q_dot + (dt * M_inv * (tau_final - b)));       //Vitesse au point de contact potentiel dans la direction de l'obstacle au pas de temps suivant
    int sgn_V_7_C_ob_t2 = know_sign(V_7_C_ob_t2);
    save_V_7_C_ob_t2(V_7_C_ob_t2);
    save_E_7_reconstructed_with_V_7_t2(0.5 *  m_eq_7_j *  V_7_C_ob_t2 * V_7_C_ob_t2);
    save_sgn_V_7_C_ob_t2(0.1 * sgn_V_7_C_ob_t2);


    double V_7_C_ob_QP_side  = J_70_C_proj * q_dot; 
    save_V_7_C_ob_QP_side(V_7_C_ob_QP_side); 




    save_tau_6(tau_final(6));
    save_tau_5(tau_final(5));
    save_tau_4(tau_final(4));
    save_tau_3(tau_final(3));
    save_tau_2(tau_final(2));
    save_tau_1(tau_final(1));
    save_tau_0(tau_final(0));
    save_tau_6_max(30);
    save_tau_5_max(30);
    save_tau_4_max(100);
    save_tau_3_max(100);
    save_tau_2_max(100);
    save_tau_1_max(200);
    save_tau_0_max(200);
    save_tau_6_min(-30);
    save_tau_5_min(-30);
    save_tau_4_min(-100);
    save_tau_3_min(-100);
    save_tau_2_min(-100);
    save_tau_1_min(-200);
    save_tau_0_min(-200);

    save_q_dotdot_6(q_dot_dot_final(6));
    save_q_dotdot_5(q_dot_dot_final(5));
    save_q_dotdot_4(q_dot_dot_final(4));
    save_q_dotdot_3(q_dot_dot_final(3));
    save_q_dotdot_2(q_dot_dot_final(2));
    save_q_dotdot_1(q_dot_dot_final(1));
    save_q_dotdot_0(q_dot_dot_final(0));

    double dynamic_1 = M(0, 0) * q_dot_dot_final[0] + M(0, 1) * q_dot_dot_final[1] + M(0, 2) * q_dot_dot_final[2] + M(0, 3) * q_dot_dot_final[3] + M(0, 4) * q_dot_dot_final[4] + M(0, 5) * q_dot_dot_final[5] + M(0, 6) * q_dot_dot_final[6]  + b(0, 0) - tau_final[0];
    double dynamic_2 = M(1, 0) * q_dot_dot_final[0] + M(1, 1) * q_dot_dot_final[1] + M(1, 2) * q_dot_dot_final[2] + M(1, 3) * q_dot_dot_final[3] + M(1, 4) * q_dot_dot_final[4] + M(1, 5) * q_dot_dot_final[5] + M(1, 6) * q_dot_dot_final[6]  + b(1, 0) - tau_final[1];
    double dynamic_3 = M(2, 0) * q_dot_dot_final[0] + M(2, 1) * q_dot_dot_final[1] + M(2, 2) * q_dot_dot_final[2] + M(2, 3) * q_dot_dot_final[3] + M(2, 4) * q_dot_dot_final[4] + M(2, 5) * q_dot_dot_final[5] + M(2, 6) * q_dot_dot_final[6]  + b(2, 0) - tau_final[2];
    double dynamic_4 = M(3, 0) * q_dot_dot_final[0] + M(3, 1) * q_dot_dot_final[1] + M(3, 2) * q_dot_dot_final[2] + M(3, 3) * q_dot_dot_final[3] + M(3, 4) * q_dot_dot_final[4] + M(3, 5) * q_dot_dot_final[5] + M(3, 6) * q_dot_dot_final[6]  + b(3, 0) - tau_final[3];
    double dynamic_5 = M(4, 0) * q_dot_dot_final[0] + M(4, 1) * q_dot_dot_final[1] + M(4, 2) * q_dot_dot_final[2] + M(4, 3) * q_dot_dot_final[3] + M(4, 4) * q_dot_dot_final[4] + M(4, 5) * q_dot_dot_final[5] + M(4, 6) * q_dot_dot_final[6]  + b(4, 0) - tau_final[4];
    double dynamic_6 = M(5, 0) * q_dot_dot_final[0] + M(5, 1) * q_dot_dot_final[1] + M(5, 2) * q_dot_dot_final[2] + M(5, 3) * q_dot_dot_final[3] + M(5, 4) * q_dot_dot_final[4] + M(5, 5) * q_dot_dot_final[5] + M(5, 6) * q_dot_dot_final[6]  + b(5, 0) - tau_final[5];
    double dynamic_7 = M(6, 0) * q_dot_dot_final[0] + M(6, 1) * q_dot_dot_final[1] + M(6, 2) * q_dot_dot_final[2] + M(6, 3) * q_dot_dot_final[3] + M(6, 4) * q_dot_dot_final[4] + M(6, 5) * q_dot_dot_final[5] + M(6, 6) * q_dot_dot_final[6]  + b(6, 0) - tau_final[6]; 
    save_dynamic(dynamic_1, dynamic_2, dynamic_3, dynamic_4, dynamic_5, dynamic_6, dynamic_7); //Pour vérifier que l'équation dynamique du système est bien respectée
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


