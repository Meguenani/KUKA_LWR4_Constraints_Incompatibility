#include "XDESimpleController.h"
#include <rtt/FlowStatus.hpp>
#include <rtt/TaskContext.hpp>
#include <orocos/ocl/DeploymentComponent.hpp>
#include <Eigen/Lgsm>
#include <iostream>
#include <fstream>
#include "Compute_distance.h"
#include "Compute_energy.h"
#include "Compute_prj_velocity.h"
#include "Compute_vectors.h"
#include "save_data_in_txt.h"
#include "Jacobian_operations.h"
#include "QP.h"
#include "Interpolation.h"
#include <cmath> 
#include <Eigen/Geometry> 
#include "/home/anis/libs/gurobi563/linux64/include/gurobi_c++.h"
//#include "/home/anis/libs/gurobi600/linux64/include/gurobi_c++.h"
#include <ctime>
#include <ReflexxesAPI.h>
#include <RMLPositionFlags.h>
#include <RMLPositionInputParameters.h>
#include <RMLPositionOutputParameters.h>

#include <cassert>
#include <time.h>
#include <Absolute.h>
#include "Minimum.h"
#include "Maximum.h"
#include "optimize_q_ddot.h"

/*
struct timeval tbegin,tend;
gettimeofday(&tbegin,NULL); // time debut
// Some code
gettimeofday(&tend,NULL); // time end
double elapsed = 1000.*(tend.tv_sec-tbegin.tv_sec)+(tend.tv_usec-tbegin.tv_usec)/1000.;
*/





#define PI 3.14159265
#define NUMBER_OF_DOFS 3
#define  CYCLE_time_in_secondONDS 0.001

Eigen::Matrix<double, 3, 1> X_dot_dot; 
int g_nValue;
Eigen::VectorXd tau_final(7);
std::ifstream inFile_x("/home/anis/ros_workspace/kuka_controller/python/saved_trajectory/trajectory_x.txt"); 
std::ifstream inFile_y("/home/anis/ros_workspace/kuka_controller/python/saved_trajectory/trajectory_y.txt"); 
std::ifstream inFile_z("/home/anis/ros_workspace/kuka_controller/python/saved_trajectory/trajectory_z.txt"); 

int one_time_declaration   = 1;
int one_time_declaration_1 = 1;
int one_time_declaration_2 = 1;
int one_time_declaration_3 = 1;
int one_time_declaration_4 = 1;


int one_time_declaration_10 = 1;
int one_time_declaration_20 = 1;
int one_time_declaration_30 = 1;
int one_time_declaration_40 = 1;
int one_time_declaration_50 = 1;
int one_time_declaration_60 = 1;
int one_time_declaration_70 = 1;
int one_time_declaration_80 = 1;
int initialize = 1;


double t1_micro = 0;  		  //Present time
double t2_micro = 0;  		  //Previous time
double step_time_micro;
double time_step;
double dt = 0.001;       //Step time for the integration operation (peut être mi à 0.001 comme la période du controleur) 
int step_count = 0;
int divider = 200;
double dvser = 0.6;                   //POUR PAPIER COMP CONTR comp q with q_ddot and q_dddot (mettre 0.4) //Diviseur pour les vitesses max et Acc max ORI 1    (0.6 pas assez de deceleration capabilities pour freiner et coper avec la contrainte sur la position pour la joint 0---> vitesse top grande pour freiner en un seul pas de temps)

boost::posix_time::ptime start_time = boost::posix_time::microsec_clock::local_time();       //Time at which we start the simulation
boost::posix_time::time_duration time_diff; //Va contenir la différence de temps entre le début                     
double time_in_second;  	 //Temps en secondes depuis le début de la simulation
double time_in_msecond; 	 //Temps en ms depuis le début de la simulation
double time_in_micsecond;
double first_time_on_pt1;        //Temps pris lors de l'arrvée de l'effecteur sur le point 1 de la trajectoire
double first_time_on_pt2;
double first_time_on_pt3;
double first_time_on_pt4;

int save_first_time_on_pt1 = 1;     //Flag de la prise de temps de l'arriver de l'effecteur sur le point 1 
int save_first_time_on_pt2 = 1;
int save_first_time_on_pt3 = 1;
int save_first_time_on_pt4 = 1;
int seg2_activated = 0; 
int seg3_activated = 0;
int seg4_activated = 0;


bool aller             = true;
bool retour            = false;
bool rotation          = false;
double err_to_pt       = 0.1;
double err_to_pt_10_cm = 0.01;
double t_1             = 0;

double t_1_x_0 = 0;
double t_1_y_0 = 0;
double t_1_z_0 = 0;
double t_1_v_x_0 = 0;
double t_1_v_y_0 = 0;
double t_1_v_z_0 = 0;
double t_1_acc_x_0 = 0;
double t_1_acc_y_0 = 0;
double t_1_acc_z_0 = 0;
double t_1_jerk_x_0 = 0;
double t_1_jerk_y_0 = 0;
double t_1_jerk_z_0 = 0;

double t_2_x      = 0;
double t_2_y      = 0;
double t_2_z      = 0;
double t_2_angle  = 0;
double t_2_v_x    = 0;
double t_2_v_y    = 0;
double t_2_v_z    = 0;
double t_2_acc_x  = 0;
double t_2_acc_y  = 0;
double t_2_acc_z  = 0;
double t_2_jerk_x = 0;
double t_2_jerk_y = 0;
double t_2_jerk_z = 0;
double angle_7_to_des_rot = 0;         //C'est la variable à discrétiser
double angle_curr_rot = 0;             //Représente l'angle courant de l'effecteur par rapport à sa position initiale lorsque le contrôleur démarre
double angle_curr_rot_prev = 0;
double V_angle_curr_rot = 0;
double V_angle_curr_rot_prev = 0;
double Acc_angle_curr_rot = 0;
double Acc_angle_curr_rot_prev = 0;
double Jerk_angle_curr_rot = 0;

double Acc_angle_7_to_des_rot  = 0;
double Jerk_angle_7_to_des_rot  = 0;


double t_1_x = 0;
double t_1_y = 0;
double t_1_z = 0;
double t_1_angle = 0;
double t_1_v_x = 0;
double t_1_v_y = 0;
double t_1_v_z = 0;
double t_1_acc_x = 0;
double t_1_acc_y = 0;
double t_1_acc_z = 0;
double t_1_jerk_x = 0;
double t_1_jerk_y = 0;
double t_1_jerk_z = 0;


Eigen::VectorXd V_7_posi_prev(3); 	 //Linear velocity during the precedent time step
Eigen::VectorXd V_7_posi(3); 	         //Linear velocity
Eigen::VectorXd V_7_posi_proj(3);
Eigen::VectorXd V_7_orient_prev(3); 	 //Angular velocity during the precedent time step
double V_x_curr    = 0;
double V_y_curr    = 0;
double V_z_curr    = 0;
double Acc_x_curr  = 0;
double Acc_y_curr  = 0;
double Acc_z_curr  = 0;
double Acc_x_prev  = 0;
double Acc_y_prev  = 0;
double Acc_z_prev  = 0;
double Jerk_x_curr = 0;
double Jerk_y_curr = 0;
double Jerk_z_curr = 0;

double Acc_alpha_curr  = 0;
double Acc_beta_curr   = 0;
double Acc_gamma_curr  = 0;
double Acc_alpha_prev  = 0;
double Acc_beta_prev   = 0;
double Acc_gamma_prev  = 0;
double Jerk_alpha_curr = 0;
double Jerk_beta_curr  = 0;
double Jerk_gamma_curr = 0;


double v_x_max;
double v_y_max;
double v_z_max;
double v_angle_max;
double acc_x_max;
double acc_y_max;
double acc_z_max;
double acc_angle_max;
double T; 
double T_angle; 
double T_x; 
double T_y; 
double T_z;
double T_alpha; 
double T_beta; 
double T_gamma;
double T_v_x; 
double T_v_y; 
double T_v_z; 
double T_acc_x; 
double T_acc_y; 
double T_acc_z;
double T_jerk_x; 
double T_jerk_y; 
double T_jerk_z; 
double max_T_x_T_y;
int contact_phy = 0;
double first_impact_instant;
double Time_since_first_impact;
int count_time_since_first_impact = 0;
int already_acquired_first_impact_instant = 0;
double time_in_msecond_of_first_iter = 0;      //C'est parceque time_in_msecond à la première itération n'est pas zéro, on l'enregistre pour avoir le temps dès la première itération
double time_in_msecond_since_first_iter = 0;  //Time since the first iteration of the programme
double trq_mltper = 1.0;
double Kp_kernel;


        std::vector<double> q_fri(7);
        std::vector<double> q_dot_fri(7);

	Eigen::VectorXd x_axis(3);			             //World x axis
	Eigen::VectorXd y_axis(3);			             //World y axis
	Eigen::VectorXd z_axis(3);			             //World z axis

	Eigen::VectorXd tau(7);			                     //Couples articulaires
	Eigen::VectorXd tau_bounds(7);
        Eigen::VectorXd X_err(3); 			             //Erreur sur la position cartésienne de l'effecteur
        Eigen::Vector3d X_err_real;                                  //Erreur reélle entre l'état courant et l'état courant précédant
        Eigen::VectorXd X_err_orient(3); 			     //Erreur sur l'orientation de l'effecteur
        Eigen::VectorXd V_err(3); 			             //Erreur sur la vitesse cartésienne de l'effecteur
        Eigen::VectorXd V_err_angle_prj(3); 
        Eigen::VectorXd V_7_des(3); 			             //Velocity tracking for the trajectory
        Eigen::VectorXd Acc_7_des(3); 			             //Acceleration désirée 
        Eigen::VectorXd Acc_7_err(3); 			             //Erreur d'accéleration
        Eigen::VectorXd Jerk_7_des(3); 			             //Jerk désiré
        Eigen::VectorXd Acc_7(3); 			             //Acceleration réelle de l'effecteur 
        Eigen::VectorXd Jerk_7(3); 			             //Jerk de l'effecteur 
        Eigen::VectorXd angle_rot_7(3);			             //Porte les trois angles résultants de l'angle courant équivalent aux quaternions courants interpolé et projeté sur l'axe de rot
        Eigen::VectorXd angle_rot_7_des(3);			     //Porte les trois angles résultants de l'angle désiré équivalent aux quaternions désirés interpolé et projeté sur l'axe de rot
        Eigen::VectorXd angle_curr_rot_prj(3);                       //Projection de l'angle courant (équivalent aux quaternions) sur l'axe de rotation
        Eigen::VectorXd angle_7_to_des_rot_prj(3);                   //Projection de l'angle désirée (équivalent aux quaternions désirés) sur l'axe de rotation qui lui est associé            
        Eigen::VectorXd V_7_orient(3);
        Eigen::VectorXd V_7_orient_des(3);
        Eigen::VectorXd Acc_posi_70(3);
        Eigen::VectorXd Acc_7_orient(3);
        Eigen::VectorXd Acc_7_orient_des(3);
        Eigen::VectorXd Jerk_7_orient(3);
        Eigen::VectorXd Jerk_7_orient_des(3);
        Eigen::VectorXd Xddot(3);				     //Accélération de l'effecteur
        Eigen::VectorXd Xddot_complete(6);		             //Vecteur contenant les accélérations linéaires et angulaires de l'effecteur
        Eigen::VectorXd Xddot_des(3);				     //Accélération désirée de l'effecteur 
        Eigen::VectorXd q_des(7); 
     	Eigen::VectorXd q_dot(7); 			             //Joint velocities
     	Eigen::VectorXd q_dot_prev(7);                               //Used to compute articular acceleration
     	Eigen::VectorXd q_ddot(7);                                   //Accélération articulaire instantannée
     	Eigen::VectorXd q_ddot_prev(7);                              //Previous articular acceleration. Used for the Jerk computation 
        Eigen::VectorXd q_dddot(7);                                  //Articular Jerk. 
        Eigen::VectorXd q_dddot_prev(7);
        Eigen::VectorXd q_ddddot(7);                                 //Utilisé exclusivement pour la génération des contraintes sur q_ddot.
        Eigen::VectorXd q_dddot_bounds_min(7);                       //Minimum et maximum Jerk
        Eigen::VectorXd q_dddot_bounds_max(7);
        Eigen::VectorXd q_bounds_min(7);                             //Minimum et maximum posi
        Eigen::VectorXd q_bounds_max(7);
        Eigen::VectorXd q_dot_bounds_min(7);                         //Minimum et maximum vel
        Eigen::VectorXd q_dot_bounds_max(7);

        Eigen::VectorXd q_dddot_bounds_min_prime(7);                 //Minimum et maximum Jerk recalculés à chaque pas de temps.
        Eigen::VectorXd q_dddot_bounds_max_prime(7);
        Eigen::VectorXd q_bounds_min_prime(7);                       //Minimum et maximum posi recalculés à chaque pas de temps.
        Eigen::VectorXd q_bounds_max_prime(7);
        Eigen::VectorXd q_dot_bounds_min_prime(7);                   //Minimum et maximum vel recalculés à chaque pas de temps.
        Eigen::VectorXd q_dot_bounds_max_prime(7);
	Eigen::VectorXd q_dotdot_bounds_min_prime(7);
	Eigen::VectorXd q_dotdot_bounds_max_prime(7);                //

	Eigen::VectorXd q_dotdot_bounds_min_optimized(7); //fixed c'est après avoir fixé le infixed. 
	Eigen::VectorXd q_dotdot_bounds_max_optimized(7); //Articular acceleration bound : q_dotdot_bounds_max_optimized = M_inv*(tau_max-b)
     	Eigen::VectorXd q_k2(7);                          //position au pas de temps suivant. C'est intégré
     	Eigen::VectorXd q_dotdot_bounds_optimized(7);     //Contient les deux vecteurs au dessus. 
     	Eigen::VectorXd q_ddot_k2(7);                     //Accélération articulaire au pas de temps suivant. 
     	Eigen::VectorXd q_dddot_k2(7);                     //Accélération articulaire au pas de temps suivant. 
     	Eigen::VectorXd q_ddddot_k2(7);                     //Accélération articulaire au pas de temps suivant. 

	Eigen::VectorXd q(7); 			                     //Joint positions
     	Eigen::VectorXd q_dot_k2(7); 			             //Joint velocities on the next step time
        Eigen::VectorXd X_des(3); 			             //Position désirée
	Eigen::VectorXd nxt_step_des_trj_x(4);                       //Vecteur contenant les "poisition, vitesse, accélération et jerk" désirés pour le pas de temps suivant selon l'axe x
	Eigen::VectorXd nxt_step_des_trj_y(4); 
	Eigen::VectorXd nxt_step_des_trj_z(4); 
	Eigen::VectorXd nxt_step_des_trj_angle(4); 
	Eigen::VectorXd nxt_step_des_trj_alpha(4); 
	Eigen::VectorXd nxt_step_des_trj_beta(4); 
	Eigen::VectorXd nxt_step_des_trj_gamma(4); 
        Eigen::Matrix<double, 6, 7> J_70_desordonated;              //Partie linéaire au dessus de la partie rotationnelle & Jacobienne éxprimée dans le repère monde    
        Eigen::Matrix<double, 6, 7> J_77_desordonated;
	Eigen::Matrix<double, 3, 7> J_70_dot_l;                     //Partie linéaire de la dérivée de la Jacobienne
        Eigen::Matrix<double, 6, 7> J_77_dot;                       //Dérivée de la jacobienne
        Eigen::Matrix<double, 6, 7> J_77_previous;                  //Utilisé pour la dérivation de la jacobienne

	Eigen::VectorXd Cond_V_1(3);
	Eigen::VectorXd Cond_V_2(3);
	Eigen::VectorXd Cond_V_3(3);
	Eigen::VectorXd Cond_V_4(3);
	   
	Eigen::VectorXd Cond_A_1(3);
	Eigen::VectorXd Cond_A_2(3);
	Eigen::VectorXd Cond_A_3(3);
	Eigen::VectorXd Cond_A_4(3);

        Eigen::VectorXd Force_sensor_3dVector(3);   //Vecteur contenant les données du capteur d'effort selon x, y et z
        Eigen::VectorXd Null_3D_Vect(3);

	Eigen::VectorXd q_dot_dot_final(7); //La sortie du solver

	Eigen::VectorXd q_dotdot_bounds_from_q_dddot_bounds_max_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_dddot_bounds_min_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_dotdot_bounds_max_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_dotdot_bounds_min_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_dot_bounds_max_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_dot_bounds_min_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_bounds_max_prime(7);
	Eigen::VectorXd q_dotdot_bounds_from_q_bounds_min_prime(7);
	Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_prime_forwrd_backwrd;
 	Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_prime_forwrd_backwrd;
        Eigen::VectorXd q_des_posture(7);
 	Eigen::Matrix<double, 7, 7> I;
	Eigen::VectorXd tau_external(7);
using namespace std;





XDE_SimpleController::XDE_SimpleController(const std::string& name) : TaskContext(name) , dynModel(NULL) //Initialisation du constructeur
{
//On déclare les ports et les opérations de l'orocos coponent


//////////////////////////////////// Distances ports ////////////////////////////////////////
    this->addEventPort("nr_pt_07_ob1_ai", in_nr_pt_07_ob1_ai);
    this->addEventPort("nr_pt_07_ob1_aj", in_nr_pt_07_ob1_aj);
//////////////////////////////////// Distances ports ////////////////////////////////////////

    //this->addPort("clock", in_clock);
    this->addEventPort("q", in_q);  //q est le nom du port rajouté et in_q est le port 
    this->addEventPort("qdot", in_qdot);
    this->addEventPort("d", in_d);
    this->addEventPort("t", in_t);
    this->addPort("tau", out_tau);

    this->addPort("kp", in_kp);
    this->addPort("kd", in_kd);
    this->addPort("d_safe", in_d_safe);
    this->addPort("d_max", in_d_max);
    this->addPort("E_safe", in_E_safe);

    this->addPort("X_des_x", in_X_des_x);
    this->addPort("X_des_y", in_X_des_y);
    this->addPort("X_des_z", in_X_des_z);

    this->addPort("tau_0_sensor", in_tau_0_sensor);

    this->addOperation("setDynModel", &XDE_SimpleController::setDynModelPointerStr, this, RTT::OwnThread); 
    this->addOperation("loadPhy", &XDE_SimpleController::loadAgent, this, RTT::OwnThread);

    this->addPort("displacementd_obst_1", in_displacementd_obst_1);    //Position du capteur d'effort

    q_ok = false;
    qdot_ok = false;
    d_ok = false;
    t_ok = false;
}


XDE_SimpleController::~XDE_SimpleController() //Destructeur
{

}



bool XDE_SimpleController::startHook(){
    return true;
}

void XDE_SimpleController::stopHook(){
    Eigen::VectorXd output = Eigen::VectorXd::Zero(dynModel->nbDofs());
    out_tau.write(output);
}

bool XDE_SimpleController::configureHook(){
    return true;
}









void XDE_SimpleController::updateHook(){         //Ici le controleur récupère les donnée de la physique et travaille 

    RTT::FlowStatus flowStatus;




if (initialize == 1){
x_axis << 1, 0, 0;
y_axis << 0, 1, 0;
z_axis << 0, 0, 1;

J_70_previous << 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0;  

q_dot_prev  << 0, 0, 0, 0, 0, 0, 0;
q_ddot_prev << 0, 0, 0, 0, 0, 0, 0;

Force_sensor_3dVector<< 0, 0, 0;    
q_dot_dot_final << 0, 0, 0, 0, 0, 0, 0;                      
q_des_posture << 2.1, 0.681166, 0.0204106, 1.52916, -0.0344, 0.0291525, 0.0584338;   



I <<             1, 0, 0, 0, 0, 0, 0,
                 0, 1, 0, 0, 0, 0, 0,
                 0, 0, 1, 0, 0, 0, 0,
                 0, 0, 0, 1, 0, 0, 0,
                 0, 0, 0, 0, 1, 0, 0,
                 0, 0, 0, 0, 0, 1, 0,
                 0, 0, 0, 0, 0, 0, 1;

                       
initialize = 0;
}




//////////////////////////////////// Distances actualisation ////////////////////////////////////////
    flowStatus = in_nr_pt_07_ob1_ai.read(nr_pt_07_ob1_ai);
    if (flowStatus == RTT::NewData && nr_pt_07_ob1_ai_ok == false)
    {
	nr_pt_07_ob1_ai_ok = true;
    }

    flowStatus = in_nr_pt_07_ob1_aj.read(nr_pt_07_ob1_aj);
    if (flowStatus == RTT::NewData && nr_pt_07_ob1_aj_ok == false)
    {
	nr_pt_07_ob1_aj_ok = true;
    }

//////////////////////////////////// Distances actualisation ////////////////////////////////////////

    flowStatus = in_clock.read(clock);

    flowStatus = in_q.read(q);
    if (flowStatus == RTT::NewData && q_ok == false)
    {
	q_ok = true;
        dynModel->setJointPositions(q);
    }

    flowStatus = in_qdot.read(qdot);
    if (flowStatus == RTT::NewData && qdot_ok == false)
    {
	qdot_ok = true;
        dynModel->setJointVelocities(qdot);
    }

    flowStatus = in_d.read(d);	//Position de la base 
    if (flowStatus == RTT::NewData && d_ok == false)
    {
	d_ok = true;
        dynModel->setFreeFlyerPosition(d);
    }

    flowStatus = in_t.read(t);     //Vitesse de la base
    if (flowStatus == RTT::NewData && t_ok == false)
    {
	t_ok = true;
        dynModel->setFreeFlyerVelocity(t);
    }

    flowStatus = in_kp.read(kp);
    flowStatus = in_kd.read(kd);
    flowStatus = in_d_safe.read(d_safe);
    flowStatus = in_d_max.read(d_max);
    flowStatus = in_E_safe.read(E_safe);

    flowStatus = in_X_des_x.read(X_des_x);
    flowStatus = in_X_des_y.read(X_des_y);
    flowStatus = in_X_des_z.read(X_des_z);

    flowStatus = in_tau_0_sensor.read(tau_sensor_0);

    flowStatus = in_displacementd_obst_1.read(displacementd_obst_1);
    if (flowStatus == RTT::NewData && displacementd_obst_1_ok == false)
    {
	displacementd_obst_1_ok = true;
        Force_sensor_3dVector << 1000000000 * (absolute(0.1 - displacementd_obst_1.getTranslation().x())), 1000000000 * (absolute(0.3 - displacementd_obst_1.getTranslation().y())), 1000000000 * (absolute(0.0 - displacementd_obst_1.getTranslation().z()));
        save_Force_sensor_x(Force_sensor_3dVector[0]);
        save_Force_sensor_y(Force_sensor_3dVector[1]);
        save_Force_sensor_z(Force_sensor_3dVector[2]);
    }







if( q_ok && qdot_ok && d_ok && t_ok && nr_pt_07_ob1_ai_ok && nr_pt_07_ob1_aj_ok){
    q_ok = false;
    qdot_ok = false;
    d_ok = false;
    t_ok = false;
    nr_pt_07_ob1_ai_ok = false;
    nr_pt_07_ob1_aj_ok = false;
    displacementd_obst_1_ok = false;

////////////////////////////////////////////// Time computation ///////////////////////////////////////
time_diff = boost::posix_time::microsec_clock::local_time() - start_time;
time_in_second    = time_diff.total_milliseconds()/1000;                               //There are times since the beginning of the simulation
time_in_msecond   = time_diff.total_milliseconds();
time_in_micsecond = time_diff.total_microseconds();

t2_micro = time_in_micsecond;
step_time_micro = t2_micro - t1_micro;
time_step = step_time_micro/1000000;          //en seconde, utilisé pour les opérations de calcul d'intégrales
time_step = dt;
//std::cout << " step_time_micro " << step_time_micro <<std::endl;
//std::cout << " time_step : " << time_step <<std::endl;
//std::cout << " " <<std::endl;
//std::cout << " " <<std::endl;
t1_micro = t2_micro;
step_count = step_count + 1;
////////////////////////////////////////////// Time computation ///////////////////////////////////////
/*
std::cout<<"  "<<std::endl; 
std::cout<<"  "<<std::endl; 
std::cout<<"time_in_second : "<<time_in_second<<std::endl; 
std::cout<<"  "<<std::endl; 
std::cout<<"  "<<std::endl; 
*/
if(Force_sensor_3dVector[0] > 200 && already_acquired_first_impact_instant == 0){
first_impact_instant = time_in_msecond; //Save first impact instant
count_time_since_first_impact = 1;
already_acquired_first_impact_instant = 1;
}
if(count_time_since_first_impact == 1){
Time_since_first_impact = time_in_msecond - first_impact_instant;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////Ecrire le controleur ici///////////////////////////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
if(time_in_second < 10){
for(int yep=0; yep<200000; yep++){
double toto=0;
std::cout<<"time_sec : "<<time_in_second <<std::endl;
}
}
*/	
        dist_07_ob1 = compute_distance(nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first);


	C_pt_seg_7  = nr_pt_07_ob1_ai[0].first;    	//Point de contact de seg 7 le plus proche de ob_1


        C_pt_ob1_7  = nr_pt_07_ob1_aj[0].first; 	//Point de contact sur ob_1 le plus proche de seg 7 





	dist_07_nrst_ob = absolute(dist_07_ob1);  //Distance of segment 07 to the nearsest obstacle
        //std::cout<<"distance :" << dist_07_nrst_ob <<std::endl;
	save_d_07_ob(dist_07_nrst_ob);


        Eigen::Vector3d x_world_unit(1, 0, 0);			 //Vecteur x du repère world

        X_des << 0.5, 0.3, 0.6;

        tau_bounds << 200, 200, 100, 100, 100, 30, 30;		//Limites max sur les commandes en couple



	//F_max = 25.0; 		 //Force équivalente de freinage
        /*
	F_max = 0.44; 		 //Force équivalente de freinage
	d_safe=0.8;  //0.4 avant
	E_safe = 0.01;
	d_max = 1.5;
	*/
        F_max  = 0.44; 		 //Force équivalente de freinage
	d_safe = 0.4;  //0.4 avant
	E_safe = 0.01;
	d_max  = 1.5;

  

	q     = dynModel->getJointPositions();             //Récupération depuis XDE
        for(unsigned int i = 0; i < 7; i++){		
            q_fri[i] = q[i];						                   //On place les angles articulaires dans une structure eigen		 
        }
        //model.setJointPosition(q_fri);                     //Alimentation du model KDL


	q_dot = dynModel->getJointVelocities();            //Récupération depuis XDE
        for(unsigned int i = 0; i < 7; i++){
            q_dot_fri[i] = q_dot[i];
        }
        //model.setJointVelocity(q_dot_fri);                 //Alimentation du model KDL

        H_7   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.07"));	//Position of segments ends
        H_6   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.06"));
        H_5   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.05"));
        H_4   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.04"));
        H_3   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.03"));
        H_2   = dynModel->getSegmentPosition(dynModel->getSegmentIndex("kuka.02"));
/////////////////////////////////////////////////////// Jacobians_Computation //////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////Jacobienne using XDE////////////////////////////////////////////////////
  	J_77       =  dynModel->getSegmentJacobian(dynModel->getSegmentIndex("kuka.07")); //Jacobienne du dernier segment dans le repère du dernier segment
        //****Changement de repère de la Jacobienne***        	
	Eigen::Displacementd H_disp_70(0, 0, 0, H_7.getRotation().w(), H_7.getRotation().x(), H_7.getRotation().y(), H_7.getRotation().z());


	J_70       =  H_disp_70.adjoint() * J_77;
/*
        std::cout<<" J_70_XDE : "<<std::endl;
        std::cout<< J_70  <<std::endl;
        std::cout<< " "<<std::endl;
        std::cout<<"DOF : "<<model.nbSegments()<<std::endl; 
*/
        //Test
        //KDL::Jacobian J_70_kdl = model.getSegmentJacobian(8);                  //La jacobienne tirÃ©e du model est directement exprimÃ©e dans le repÃšre monde
        //J_70_desordonated      = J_70_kdl.data.block(0,0, 6,7);                //Le .data de la jacobienne kdl est une structure eigen, dans cette Jacobienne, la partie linÃ©aire est au dessus de la partie rotationnelle
        //J_70  		 = ordonate(J_70_desordonated);                  //La partie rotationnelle passe au dessus de la partie linÃ©aire  	    
        //std::cout<<" J_70_KDL : "<<std::endl;
        //std::cout<< J_70  <<std::endl;


        J_70_dot   = derive(J_70, J_70_previous, time_step); 
        J_70_dot_l = J_70_dot.block<3,7>(3,0); 
        //****Changement de repère de la Jacobienne***
	J_77_r     = J_77.block<3,7>(0,0); 
	J_70_t     = J_70.block<3,7>(0,0).transpose();    
	J_70_l     = J_70.block<3,7>(3,0);  
          
        J_70_r     = J_70.block<3,7>(0,0);                                                                                                                                                                                                                                                                                                                                                
	//****Changement de point de la Jacobienne***
	Eigen::Displacementd H_C_7((C_pt_seg_7.getTranslation().x() - H_7.getTranslation().x()), (C_pt_seg_7.getTranslation().y() - H_7.getTranslation().y()), (C_pt_seg_7.getTranslation().z() - H_7.getTranslation().z()), 1, 0, 0, 0); //Position of the contact pont on seg 7 
	J_70_C = H_C_7.adjoint() * J_70; 

        J_70_previous  = J_70;   //Sert juste à la dérivation numérique de la Jacobienne

        JdotQdot_77 = dynModel->getSegmentJdotQdot(dynModel->getSegmentIndex("kuka.07"));  //POur le calcul de l'accélération
        JdotQdot_70 = H_disp_70.adjoint() * JdotQdot_77;   //La partie haute correspond à la rotation. La partie basse à la translation.
////////////////////////////////////////////////////////////////Jacobienne using XDE////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////Jacobienne using KDL////////////////////////////////////////////////////
/*
    Eigen::Displacementd H_disp_70(0, 0, 0, H_7.getRotation().w(), H_7.getRotation().x(), H_7.getRotation().y(), H_7.getRotation().z());
    KDL::Jacobian J_70_kdl = model.getSegmentJacobian(8);                  //La jacobienne tirÃ©e du model est directement exprimÃ©e dans le repÃšre monde
    J_70_desordonated      = J_70_kdl.data.block(0,0, 6,7);                //Le .data de la jacobienne kdl est une structure eigen, dans cette Jacobienne, la partie linÃ©aire est au dessus de la partie rotationnelle
    J_70  		   = ordonate(J_70_desordonated);                  //La partie rotationnelle passe au dessus de la partie linÃ©aire  	    
    J_70_dot               = derive(J_70, J_70_previous, time_step); 
    J_70_dot_l             = J_70_dot.block<3,7>(3,0);
    J_70_l  	           = J_70.block<3,7>(3,0);
    J_70_r  	           = J_70.block<3,7>(0,0);
           
    J_70_kdl.changeBase(model.getSegmentPosition(7).M.Inverse());         //Le changement de repÃšre se fait en interneÃxX  On passe du repÃšre effecteur au repÃšre world
    J_77_desordonated      = J_70_kdl.data.block(0,0, 6,7);
    J_77    	           = ordonate(J_77_desordonated);                 //La partie rotationnelle passe au dessus de la partie linÃ©aire 
    J_77_dot               = derive(J_77, J_77_previous, time_step); 
    J_77_r  		   = J_77.block<3,7>(0,0); 

    Eigen::Displacementd H_C_7((C_pt_seg_7.getTranslation().x() - H_7.getTranslation().x()), (C_pt_seg_7.getTranslation().y() - H_7.getTranslation().y()), (C_pt_seg_7.getTranslation().z() - H_7.getTranslation().z()), 1, 0, 0, 0); //Position of the contact pont on seg 7 
    J_70_C = H_C_7.adjoint() * J_70;

    JdotQdot_70           = J_70_dot * q_dot;
    JdotQdot_77           = J_77_dot * q_dot;
	
    J_70_previous       = J_70;
    J_77_previous       = J_77;	
*/
////////////////////////////////////////////////////////////////Jacobienne using KDL////////////////////////////////////////////////////







	//****Projection de la jacobienne dans un repère lié au point le plus proche de l'obstacle****
        Eigen::Vector3d Distance_vector;
        Distance_vector << (nr_pt_07_ob1_aj[0].first).getTranslation().x() - (nr_pt_07_ob1_ai[0].first).getTranslation().x(),
		           (nr_pt_07_ob1_aj[0].first).getTranslation().y() - (nr_pt_07_ob1_ai[0].first).getTranslation().y(),
		           (nr_pt_07_ob1_aj[0].first).getTranslation().z() - (nr_pt_07_ob1_ai[0].first).getTranslation().z();

        save_dist_07((nr_pt_07_ob1_ai[0].first).getTranslation().x());


        Eigen::Vector3d Distance_vector_normalized; 
        Distance_vector_normalized = Distance_vector.normalized();
        n_7 = Distance_vector_normalized;   

	//n_7 = compute_unit_vect(C_pt_ob1_7, C_pt_seg_7);	 //Vecteur unitaire de la distance la plus courte, C_pt_ob_1_7 est sur ob_1 et C_pt_seg_7 est sur seg 7          
	angle_nrst_dist_vect_7 = acos(n_7[0]);                   //In 3D space if v1 and v2 are normalised so that |v1|=|v2|=1, then, angle = acos(v1•v2) and axis = norm(v1 x v2); Here the angle is between [1,0,0] and the vector of the nearest distance between seg 7 and ob_1

	axis_of_rot_angle_7 =  n_7.cross(x_world_unit);

	axis_of_rot_angle_7_normalized = axis_of_rot_angle_7.normalized();
	Eigen::AngleAxisd angle_axis_7(angle_nrst_dist_vect_7, axis_of_rot_angle_7_normalized);
	Eigen::Quaternion<double> quaternion_transf_0_C7(angle_axis_7);
        Eigen::Displacementd H_proj_jac_7(0, 0, 0, quaternion_transf_0_C7.w(), quaternion_transf_0_C7.x(), quaternion_transf_0_C7.y(), quaternion_transf_0_C7.z());   //Projector of the jacobian in the frame related to the nearest contact point to ob_1
	J_70_C_proj_full = H_proj_jac_7.adjoint() * J_70_C;		//Projected jacobian in the frame related to the nearest point to the obstacle 
	//J_70_C_proj = J_70_C_proj_full.block<1,7>(3,0);	        //The first line of the linear projected jacobian (the one in the same direction as n_7)
        save_acos_n_7_0((angle_nrst_dist_vect_7 *180)/3.14159265);




J_70_C_proj <<  (n_7[0] * J_70_C(3, 0) + n_7[1] * J_70_C(4, 0) + n_7[2] * J_70_C(5, 0)),     
		(n_7[0] * J_70_C(3, 1) + n_7[1] * J_70_C(4, 1) + n_7[2] * J_70_C(5, 1)),
		(n_7[0] * J_70_C(3, 2) + n_7[1] * J_70_C(4, 2) + n_7[2] * J_70_C(5, 2)),
		(n_7[0] * J_70_C(3, 3) + n_7[1] * J_70_C(4, 3) + n_7[2] * J_70_C(5, 3)),
		(n_7[0] * J_70_C(3, 4) + n_7[1] * J_70_C(4, 4) + n_7[2] * J_70_C(5, 4)),
		(n_7[0] * J_70_C(3, 5) + n_7[1] * J_70_C(4, 5) + n_7[2] * J_70_C(5, 5)),
		(n_7[0] * J_70_C(3, 6) + n_7[1] * J_70_C(4, 6) + n_7[2] * J_70_C(5, 6));
/////////////////////////////////////////////////////// Jacobians_Computation //////////////////////////////////////////////////////////








/////////////////////////////////////////////////////// Compute velocities and some parameters //////////////////////////////////////////////////////////
	V_7   = J_70 * q_dot; 		      //Absolute velocity of the end effector point

   
        V_77 = J_77 * q_dot; 

	V_7_x = V_7[3];
	V_7_y = V_7[4];
	V_7_z = V_7[5];



/*
std::cout << " Acc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_desAcc_7_des "<<std::endl;
std::cout << "   "        <<std::endl;
std::cout << " boost::posix_time::microsec_clock::local_time() " << boost::posix_time::microsec_clock::local_time()<<std::endl;
std::cout << " start_time "          << start_time        <<std::endl;
std::cout << " time_in_second  "     << time_in_second    <<std::endl;
std::cout << " time_in_msecond "     << time_in_msecond   <<std::endl;
std::cout << " time_in_micsecond "   << time_in_micsecond <<std::endl;
std::cout << " step_time_micro "     << step_time_micro   <<std::endl;
*/

       //Vector representing the distance from each segment to the nearest considered obstacle obstacle
       Vect_dist_nrst_ob_07 = compute_vect_dist_nrst_obst_considered(nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first); 


       //Compute vector of the projected velocity in the direction of the nearest obstacle --> End Effector
       V_7_ob = compute_velocity_pr_vect_considered(V_7, nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first);
	

       //Compute the projected velocity signed norm  --> End Effector
       V_7_ob_sgn_norm = compute_velocity_sgn_norm_considered(V_7, nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first);



       //Compute the projected velocity signed norm  --> Nearest potential contact point to ob_1 (Avec 2 méthodes différantes )
       V_7_C_ob                   = J_70_C_proj  * q_dot;    //C'est la vitesse du seg_7 au point de contact potetiel le plus proche de ob_1, projetée dans la direction de ob_1
       int sgn_V_7_C_ob           = know_sign(V_7_C_ob);

       V_7_C                      = J_70_C * q_dot;	  //C'est la vitesse du seg_7 au point de contact potetiel le plus proche de ob_1, non projetée 
       V_7_C_ob_diff_comp         = compute_velocity_sgn_norm_considered(V_7_C, nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first);
       int sgn_V_7_C_ob_diff_comp = know_sign(V_7_C_ob_diff_comp);


	M              = dynModel->getInertiaMatrix();
	M_inv          = dynModel->getInertiaMatrixInverse();

	m_eq_7_j_inter = (J_70_C_proj * M_inv * J_70_C_proj.transpose());
	m_eq_7_j       = 1/m_eq_7_j_inter;

        //KDL_NL_terms = model.getNonLinearTerms();       //Termes non linéaires récupérés depuis KDL
	  gravity_terms= dynModel->getGravityTerms();
          b            = dynModel->getNonLinearTerms() + dynModel->getGravityTerms(); 	       //Matrice des effets non lineaires depuis XDE
        //b            = KDL_NL_terms.data + dynModel->getGravityTerms(); 	               //Matrice des effets non lineaires depuis KDL
        //b            = dynModel->getGravityTerms();  
        //b            = dynModel->getNonLinearTerms();  //Matrice des effets non lineaires	

        //std::cout << "  dynModel->getJointDamping() " <<  dynModel->getJointDamping() <<std::endl;

/*
        std::cout<<"Coriolis XDE : " <<std::endl;
        std::cout<< dynModel->getNonLinearTerms() <<std::endl;
        std::cout<<"  " <<std::endl;
        std::cout<<"  " <<std::endl;

        std::cout<<"Coriolis KDL : " <<std::endl;
        std::cout<< KDL_NL_terms.data <<std::endl;
        std::cout<<"  " <<std::endl;
        std::cout<<"  " <<std::endl;
*/

        Jdot_qdot_eff_frame = dynModel->getSegmentJdotQdot(dynModel->getSegmentIndex("kuka.07")); 
        Jdot_qdot_r_77    = Jdot_qdot_eff_frame.block<3,1>(0,0);  //La jacobienne ici est dérivée numériquement 
	//Jdot_qdot_r_77      = JdotQdot_77.block<3,1>(0,0); //Ici c'est directement tiré de XDE


        Jdot_qdot           = H_disp_70.adjoint() * dynModel->getSegmentJdotQdot(dynModel->getSegmentIndex("kuka.07")); 
	Jdot_qdot_l       = Jdot_qdot.block<3,1>(3,0);   //La jacobienne ici est dérivé numériquement
	//Jdot_qdot_l         = JdotQdot_70.block<3,1>(3,0); //Ici c'est directement tiré de XDE
	Jdot_qdot_r_70    = Jdot_qdot.block<3,1>(0,0); //Ici la jacobienne est dérivée numériquement
	//Jdot_qdot_r_70      = JdotQdot_70.block<3,1>(0,0);

        //UTILISÉ DANS LA TACHE DE POSTURE	
        M_inv_J_70_transp          = M_inv * J_70.transpose(); 
        J_70_M_inv                 = J_70 * M_inv;
        J_70_M_inv_J_70_transp     = J_70 * M_inv * J_70.transpose(); 
        J_70_M_inv_J_70_transp_inv = J_70_M_inv_J_70_transp.inverse();
        J_70_plus                  = M_inv_J_70_transp * J_70_M_inv_J_70_transp_inv;
/////////////////////////////////////////////////////// Compute velocities and some parameters //////////////////////////////////////////////////////////








///////////////////////////////////////////////////////// Compute E & E_max ////////////////////////////////////////////////////////////
	F_max_7 = std::abs(J_70_C_proj * tau_bounds);


	E_7 = compute_E(V_7_ob_sgn_norm, V_7_ob, m_eq_7_j);		//V_7_ob_sgn_norm est la vitesse de l'effecteur projetée dans la direction de l'obstacle le plus proche 


	//Ec_max_7 = compute_E_max(dist_07_nrst_ob, d_safe, E_safe, d_max, F_max);
	  Ec_max_7 = compute_E_limit(dist_07_nrst_ob, d_safe, E_safe, d_max, F_max);

///////////////////////////////////////////////////////// Compute E & E_max ////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////// Compute articular bound ////////////////////////////////////////////////////////////
       float dt_     = 0.001;
       float dt_bis  = 0.001;
       double mulpr  = 1;
       double mulpr2 = 1;

       q_dddot_bounds_min << -25/mulpr2, -1000/mulpr2, -1000/mulpr2, -1000/mulpr2, -1000/mulpr2, -1000/mulpr2, -1000/mulpr2;
       q_dddot_bounds_max <<  25/mulpr2,  1000/mulpr2,  1000/mulpr2,  1000/mulpr2,  1000/mulpr2,  1000/mulpr2,  1000/mulpr2;

/*
       q_bounds_min << -2.95, -1.55, -2.95, -2.05, -2.95, -2.05, -2.75;
       q_bounds_max <<  2.95,  1.55,  2.95,  2.05,  2.95,  2.05,  2.75;
*/

       q_bounds_min << -2.8, -1.75, -2.95, -2.05, -2.95, -2.05, -2.75;
       q_bounds_max <<  2.6,  1.75,  2.95,  2.05,  2.95,  2.05,  2.75;



       q_dot_bounds_min << -2.0, -2.9, -2.9, -2.9, -3.14, -3.2, -3.2;
       q_dot_bounds_max <<  2.0,  2.9,  2.9,  2.9,  3.14,  3.2,  3.2;


       trq_mltper    = 1.0;
/*
       tau_min(0, 0) = trq_mltper*(-200+(gravity_terms(0)));
       tau_min(1, 0) = trq_mltper*(-200+(gravity_terms(1)));
       tau_min(2, 0) = trq_mltper*(-100+(gravity_terms(2)));
       tau_min(3, 0) = trq_mltper*(-100+(gravity_terms(3)));
       tau_min(4, 0) = trq_mltper*(-100+(gravity_terms(4)));
       tau_min(5, 0) = trq_mltper*(-30 +(gravity_terms(5)));
       tau_min(6, 0) = trq_mltper*(-30 +(gravity_terms(6)));

       tau_max(0, 0) = trq_mltper*(200-(gravity_terms(0)));
       tau_max(1, 0) = trq_mltper*(200-(gravity_terms(1)));
       tau_max(2, 0) = trq_mltper*(100-(gravity_terms(2)));
       tau_max(3, 0) = trq_mltper*(100-(gravity_terms(3)));
       tau_max(4, 0) = trq_mltper*(100-(gravity_terms(4)));
       tau_max(5, 0) = trq_mltper*(30 -(gravity_terms(5)));
       tau_max(6, 0) = trq_mltper*(30 -(gravity_terms(6)));
*/


       tau_min(0, 0) = trq_mltper*(-200);
       tau_min(1, 0) = trq_mltper*(-200);
       tau_min(2, 0) = trq_mltper*(-100);
       tau_min(3, 0) = trq_mltper*(-100);
       tau_min(4, 0) = trq_mltper*(-100);
       tau_min(5, 0) = trq_mltper*(-30);
       tau_min(6, 0) = trq_mltper*(-30);

       tau_max(0, 0) = trq_mltper*(200);
       tau_max(1, 0) = trq_mltper*(200);
       tau_max(2, 0) = trq_mltper*(100);
       tau_max(3, 0) = trq_mltper*(100);
       tau_max(4, 0) = trq_mltper*(100);
       tau_max(5, 0) = trq_mltper*(30);
       tau_max(6, 0) = trq_mltper*(30);


//       //Calcul des limites en accélération articulaire correspondant aux limites en couples.    //TEST POUR LE PAPIER, joint0 : -5, +100
         q_dotdot_bounds_optimized     = optimize_q_ddot(M_inv, b, tau_min, tau_max);
       q_dotdot_bounds_min_optimized << -10000000, q_dotdot_bounds_optimized[1], q_dotdot_bounds_optimized[2], q_dotdot_bounds_optimized[3],  q_dotdot_bounds_optimized[4],  q_dotdot_bounds_optimized[5],  q_dotdot_bounds_optimized[6]; 
//      //q_dotdot_bounds_min_optimized << q_dotdot_bounds_optimized[0], q_dotdot_bounds_optimized[1], q_dotdot_bounds_optimized[2], q_dotdot_bounds_optimized[3],  q_dotdot_bounds_optimized[4],  q_dotdot_bounds_optimized[5],  q_dotdot_bounds_optimized[6];
       q_dotdot_bounds_max_optimized << 10000000, q_dotdot_bounds_optimized[8], q_dotdot_bounds_optimized[9], q_dotdot_bounds_optimized[10], q_dotdot_bounds_optimized[11], q_dotdot_bounds_optimized[12], q_dotdot_bounds_optimized[13];

       //q_dotdot_bounds_min_optimized << q_dotdot_bounds_optimized[0], q_dotdot_bounds_optimized[1], q_dotdot_bounds_optimized[2], q_dotdot_bounds_optimized[3],  q_dotdot_bounds_optimized[4],  q_dotdot_bounds_optimized[5],  q_dotdot_bounds_optimized[6];
       //q_dotdot_bounds_max_optimized << q_dotdot_bounds_optimized[7], q_dotdot_bounds_optimized[8], q_dotdot_bounds_optimized[9], q_dotdot_bounds_optimized[10], q_dotdot_bounds_optimized[11], q_dotdot_bounds_optimized[12], q_dotdot_bounds_optimized[13];
       save_q_dotdot_bounds_min_optimized_0(q_dotdot_bounds_optimized[0]);
       save_q_dotdot_bounds_max_optimized_0(q_dotdot_bounds_optimized[7]);


std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<"q_dotdot_bounds_optimized[0] : "<<q_dotdot_bounds_optimized[0]<<std::endl;
std::cout<<"q_dotdot_bounds_optimized[7] : "<<q_dotdot_bounds_optimized[7]<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;

       q_dotdot_bounds_max(0, 0) = min(((q_dot_bounds_max[0]*mulpr)  - q_dot[0])/dt_, (q_bounds_max[0] - (q[0] + q_dot[0]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(1, 0) = min(((q_dot_bounds_max[1]*mulpr)  - q_dot[1])/dt_, (q_bounds_max[1] - (q[1] + q_dot[1]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(2, 0) = min(((q_dot_bounds_max[2]*mulpr)  - q_dot[2])/dt_, (q_bounds_max[2] - (q[2] + q_dot[2]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(3, 0) = min(((q_dot_bounds_max[3]*mulpr)  - q_dot[3])/dt_, (q_bounds_max[3] - (q[3] + q_dot[3]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(4, 0) = min(((q_dot_bounds_max[4]*mulpr)  - q_dot[4])/dt_, (q_bounds_max[4] - (q[4] + q_dot[4]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(5, 0) = min(((q_dot_bounds_max[5]*mulpr)  - q_dot[5])/dt_, (q_bounds_max[5] - (q[5] + q_dot[5]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_max(6, 0) = min(((q_dot_bounds_max[6]*mulpr)  - q_dot[6])/dt_, (q_bounds_max[6] - (q[6] + q_dot[6]*dt_bis)) * (2/pow(dt_bis,2)));

       q_dotdot_bounds_min(0, 0) = max(((q_dot_bounds_min[0]*mulpr)  - q_dot[0])/dt_, (q_bounds_min[0] - (q[0] + q_dot[0]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(1, 0) = max(((q_dot_bounds_min[1]*mulpr)  - q_dot[1])/dt_, (q_bounds_min[1] - (q[1] + q_dot[1]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(2, 0) = max(((q_dot_bounds_min[2]*mulpr)  - q_dot[2])/dt_, (q_bounds_min[2] - (q[2] + q_dot[2]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(3, 0) = max(((q_dot_bounds_min[3]*mulpr)  - q_dot[3])/dt_, (q_bounds_min[3] - (q[3] + q_dot[3]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(4, 0) = max(((q_dot_bounds_min[4]*mulpr)  - q_dot[4])/dt_, (q_bounds_min[4] - (q[4] + q_dot[4]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(5, 0) = max(((q_dot_bounds_min[5]*mulpr)  - q_dot[5])/dt_, (q_bounds_min[5] - (q[5] + q_dot[5]*dt_bis)) * (2/pow(dt_bis,2)));
       q_dotdot_bounds_min(6, 0) = max(((q_dot_bounds_min[6]*mulpr)  - q_dot[6])/dt_, (q_bounds_min[6] - (q[6] + q_dot[6]*dt_bis)) * (2/pow(dt_bis,2)));








//-----------------------------Calcul des butés modifiés sur : q_min, q_max, q_dot_min, q_dot_max, q_ddot_min, q_ddot_max, q_dddot_min, q_dddot_max. (METHODE_VINCENT)-----------------------------//
for(int m=0; m<7; m++){
//--------------------Bounds_minimales--------------------//
q_bounds_min_prime = q_bounds_min;

if(q[m]+q_dot_bounds_min[m]*dt < q_bounds_min[m]){
q_dot_bounds_min_prime[m] = ((q_bounds_min[m] - q[m])/dt);
//std::cout<<" CASE 1 min q_dot_bounds_min_prime"<<std::endl;
} 
else{
q_dot_bounds_min_prime[m] = q_dot_bounds_min[m]; 
//std::cout<<" CASE 2 min q_dot_bounds_min_prime"<<std::endl;
}


if(q_dot[m]+q_dotdot_bounds_min_optimized[m]*dt < q_dot_bounds_min_prime[m]){
q_dotdot_bounds_min_prime[m] = ((q_dot_bounds_min_prime[m] - q_dot[m])/dt);
//std::cout<<" CASE 1 min q_dotdot_bounds_min_prime"<<std::endl;
} 
else{
q_dotdot_bounds_min_prime[m] = q_dotdot_bounds_min_optimized[m]; 
//std::cout<<" CASE 2 min q_dotdot_bounds_min_prime"<<std::endl;
}

//voir si q_ddot[m] peut être remplacé par "q_dot_dot_final"(les sorties du colveur. )
if(q_dot_dot_final[m]+q_dddot_bounds_min[m]*dt < q_dotdot_bounds_min_prime[m]){
q_dddot_bounds_min_prime[m] = ((q_dotdot_bounds_min_prime[m] - q_dot_dot_final[m])/dt);
//std::cout<<" CASE 1 min q_dddot_bounds_min_prime"<<std::endl;
} 
else{
q_dddot_bounds_min_prime[m] = q_dddot_bounds_min[m]; 
//std::cout<<" CASE 2 min q_dddot_bounds_min_prime"<<std::endl;
}

//Recalage

//q_dotdot_bounds_min_prime[m] = q_dot_dot_final[m]+q_dddot_bounds_min_prime[m]*dt;
//q_dot_bounds_min_prime[m]    = q_dot[m]+q_dotdot_bounds_min_prime[m]*dt;
//q_bounds_min_prime[m]        = q[m]+q_dot_bounds_min_prime[m]*dt;

//--------------------Bounds_minimales--------------------//


//--------------------Bounds_maximales--------------------//
q_bounds_max_prime = q_bounds_max;

if(q[m]+q_dot_bounds_max[m]*dt > q_bounds_max[m]){
q_dot_bounds_max_prime[m] = ((q_bounds_max[m] - q[m])/dt);
//std::cout<<" CASE 1 max q_dot_bounds_max_prime"<<std::endl;
} 
else{
q_dot_bounds_max_prime[m] = q_dot_bounds_max[m]; 
//std::cout<<" CASE 2 max q_dot_bounds_max_prime"<<std::endl;
}


if(q_dot[m]+q_dotdot_bounds_max_optimized[m]*dt > q_dot_bounds_max_prime[m]){
q_dotdot_bounds_max_prime[m] = ((q_dot_bounds_max_prime[m] - q_dot[m])/dt);
//std::cout<<" CASE 1 max q_dotdot_bounds_max_prime"<<std::endl;
} 
else{
q_dotdot_bounds_max_prime[m] = q_dotdot_bounds_max_optimized[m]; 
//std::cout<<" CASE 2 max q_dotdot_bounds_max_prime"<<std::endl;
}

//voir ci q_ddot[m] peut être remplacé par "q_dot_dot_faxal"(les sorties du colveur. )
if(q_dot_dot_final[m]+q_dddot_bounds_max[m]*dt > q_dotdot_bounds_max_prime[m]){
q_dddot_bounds_max_prime[m] = ((q_dotdot_bounds_max_prime[m] - q_dot_dot_final[m])/dt);
//std::cout<<" CASE 1 max q_dddot_bounds_max_prime"<<std::endl;
} 
else{
q_dddot_bounds_max_prime[m] = q_dddot_bounds_max[m]; 
//std::cout<<" CASE 2 max q_dddot_bounds_max_prime"<<std::endl;
}



if(q_dot[m]>=0){  //lorsqu'on veut freiner, pour respecter une q_dot et un q positifs, les limites sur q_ddot et q_dddots sont négatives
q_dotdot_bounds_from_q_dddot_bounds_max_prime[m]  =  q_dotdot_bounds_max_optimized[m];
q_dotdot_bounds_from_q_dddot_bounds_min_prime[m]  =  (q_dddot_bounds_min_prime[m]*dt)+q_dot_dot_final[m];
q_dotdot_bounds_from_q_dotdot_bounds_max_prime[m] =  q_dotdot_bounds_max_optimized[m];
q_dotdot_bounds_from_q_dotdot_bounds_min_prime[m] =  q_dotdot_bounds_min_prime[m];

q_dotdot_bounds_from_q_dot_bounds_max_prime[m]    = (q_dot_bounds_max_prime[m]-q_dot[m])/dt;
q_dotdot_bounds_from_q_dot_bounds_min_prime[m]    =  q_dotdot_bounds_min_optimized[m];
q_dotdot_bounds_from_q_bounds_max_prime[m]        = (q_bounds_max_prime[m] - (q[m] + q_dot[m]*dt)) * (2/pow(dt,2));
q_dotdot_bounds_from_q_bounds_min_prime[m]        =  q_dotdot_bounds_min_optimized[m];
}
else{
q_dotdot_bounds_from_q_dddot_bounds_max_prime[m]  = (q_dddot_bounds_max_prime[m]*dt)+q_dot_dot_final[m];
q_dotdot_bounds_from_q_dddot_bounds_min_prime[m]  = q_dotdot_bounds_min_optimized[m];
q_dotdot_bounds_from_q_dotdot_bounds_max_prime[m] = q_dotdot_bounds_max_prime[m]; 
q_dotdot_bounds_from_q_dotdot_bounds_min_prime[m] = q_dotdot_bounds_min_optimized[m];

q_dotdot_bounds_from_q_dot_bounds_max_prime[m]    =  q_dotdot_bounds_max_optimized[m];
q_dotdot_bounds_from_q_dot_bounds_min_prime[m]    = (q_dot_bounds_min_prime[m]-q_dot[m])/dt;
q_dotdot_bounds_from_q_bounds_max_prime[m]        =  q_dotdot_bounds_max_optimized[m];
q_dotdot_bounds_from_q_bounds_min_prime[m]        = (q_bounds_min_prime[m] - (q[m] + q_dot[m]*dt)) * (2/pow(dt,2));
}


//Choix des domaines les plus contraignants.

//q_dotdot_bounds_max_prime_forwrd_backwrd(m, 0)    = minimum_4_values(q_dotdot_bounds_from_q_dddot_bounds_max_prime[m], q_dotdot_bounds_from_q_dotdot_bounds_max_prime[m], q_dotdot_bounds_from_q_dot_bounds_max_prime[m], q_dotdot_bounds_from_q_bounds_max_prime[m]);
//q_dotdot_bounds_min_prime_forwrd_backwrd(m, 0)    = maximum_4_values(q_dotdot_bounds_from_q_dddot_bounds_min_prime[m], q_dotdot_bounds_from_q_dotdot_bounds_min_prime[m], q_dotdot_bounds_from_q_dot_bounds_min_prime[m], q_dotdot_bounds_from_q_bounds_min_prime[m]);



//q_dotdot_bounds_max_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_bounds_max_prime[m];
//q_dotdot_bounds_min_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_bounds_min_prime[m];



//q_dotdot_bounds_max_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_dot_bounds_max_prime[m];
//q_dotdot_bounds_min_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_dot_bounds_min_prime[m];


q_dotdot_bounds_max_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_dotdot_bounds_max_prime[m];
q_dotdot_bounds_min_prime_forwrd_backwrd(m, 0)    = q_dotdot_bounds_from_q_dotdot_bounds_min_prime[m];
}

save_q_dotdot_bounds_max_prime_forwrd_backwrd(q_dotdot_bounds_max_prime_forwrd_backwrd);
save_q_dotdot_bounds_min_prime_forwrd_backwrd(q_dotdot_bounds_min_prime_forwrd_backwrd);
//-----------------------------Calcul des butés modifiés sur : q_min, q_max, q_dot_min, q_dot_max, q_ddot_min, q_ddot_max, q_dddot_min, q_dddot_max. (METHODE_VINCENT)-----------------------------//







///////////////////////////////////////////////////////// Compute articular bound ////////////////////////////////////////////////////////////















////////////////////////////////////////////// Trajectory Interpolation_3DDL online PICK&PLACE TRANSLATION + ROTATION///////////////////////////////////////
        if(one_time_declaration_2 == 1){
	  //Quaternions initiaux
	  init_H_quat_70      = H_disp_70.getRotation();        //Type Eigen::Displacementd::Rotation3D contenant les quaternions

          //Quaternions désirés    --> L'angle désirée est calculée une seule fois au début

//Orient désirée originale avant comp contraintes
          H_disp_des_rot.x()  =   0;           
          H_disp_des_rot.y()  =   0;
          H_disp_des_rot.z()  =   0;
          H_disp_des_rot.qw() =  -0.0153209;
          H_disp_des_rot.qx() =   0.867012;
          H_disp_des_rot.qy() =  -0.497335;
          H_disp_des_rot.qz() =  -0.0267092;








/*
          H_disp_des_rot.x()  =   0;           
          H_disp_des_rot.y()  =   0;
          H_disp_des_rot.z()  =   0;
          H_disp_des_rot.qw() =  H_disp_70.getRotation().w();
          H_disp_des_rot.qx() =  H_disp_70.getRotation().x();
          H_disp_des_rot.qy() =  H_disp_70.getRotation().y();
          H_disp_des_rot.qz() =  H_disp_70.getRotation().z();
*/

	  target_H_quat_70    =   H_disp_des_rot.getRotation();

          //Calcul de l'angle désiré qui ramène les quaternions initiaux aux quaternions finaux
          H_quat_7_to_des_rot = init_H_quat_70.inverse() * target_H_quat_70;
          Eigen::Quaterniond    Quaternion_7_to_des_rot(H_quat_7_to_des_rot.w(), H_quat_7_to_des_rot.x(), H_quat_7_to_des_rot.y(), H_quat_7_to_des_rot.z());
          Eigen::AngleAxisd     angle_axis_7_to_des_rot(Quaternion_7_to_des_rot);       //Angle/Axe qui emmène l'effecteur de son orientation actuelle à l'orientation désirée               
          angle_7_to_des_rot  = angle_axis_7_to_des_rot.angle();			//Angle de rotation désiré (depuis les quaternions initiaux aux quaternions désirés)
	  axis_7_to_des_rot   = angle_axis_7_to_des_rot.axis();                         //Axes de rotation pour arriver à l'orientation désirée 

          //Calcul de l'angle désiré avec une seconde méthode --> On trouve le même résultat qu'en haut
          cosHalfTheta    = compute_quat_cosHalfTheta(init_H_quat_70, target_H_quat_70);
	  halfTheta       = acos(cosHalfTheta);
	  theta           = 2 * halfTheta;  	

          one_time_declaration_2  = 0;

          Posi_x_curr_prev = H_7.getTranslation().x();
          Posi_y_curr_prev = H_7.getTranslation().y();
          Posi_z_curr_prev = H_7.getTranslation().z();
        }

        //Angle Réel (slerp) --> A garder pour l'instant juste pour le comparer avec l'angle calculé avec les quternions
          H_orient_70            = H_disp_70.getRotation();                                   //Ne contient que les quaternions de l'orientation actuelle
          H_orient_7_to_init_rot = init_H_quat_70.inverse() * H_orient_70;                    //Quaternions de l'orientation initiale vers l'orientation courante   (l'angle sera considéré dans cette direction) H_7 contient la position et l'orientation  
          Eigen::Quaterniond       Quaternion_init_rot_to_curr_rot(H_orient_7_to_init_rot.w(), H_orient_7_to_init_rot.x(), H_orient_7_to_init_rot.y(), H_orient_7_to_init_rot.z());
          Eigen::AngleAxisd        angle_axis_init_rot_to_curr_rot(Quaternion_init_rot_to_curr_rot);
          axis_curr_rot          = angle_axis_init_rot_to_curr_rot.axis();                    //Init to curr == direction de l'angle 
          angle_curr_rot         = angle_axis_init_rot_to_curr_rot.angle();

        //V_angle réelle (slerp)
          V_angle_curr_rot       =  (angle_curr_rot - angle_curr_rot_prev)/0.001;
        //Acc_angle réelle (slerp)
          Acc_angle_curr_rot     =  (V_angle_curr_rot - V_angle_curr_rot_prev)/0.001;
        //Jerk_angle réelle (slerp)
          Jerk_angle_curr_rot    =  (Acc_angle_curr_rot - Acc_angle_curr_rot_prev)/0.001;


/*
         std::cout<<"H_orient_70 : "<<std::endl;
         std::cout<< H_orient_70 <<std::endl;
         std::cout<<"  "<<std::endl;
         std::cout<<"  "<<std::endl;
*/


/*
         std::cout<<"q : "<<std::endl;
         std::cout<< q <<std::endl;
         std::cout<<"  "<<std::endl;
         std::cout<<"  "<<std::endl;
*/


       Eigen::VectorXd traj_pt1(3);				 //First point on the pick&place trajectory
       //traj_pt1 << -0.4, 0.4, 0.2;                             //ORIGINAL
       //traj_pt1 << -0.4, 0.16, 0.2;                            //First attempt comp constraints
       traj_pt1 << -0.4, -0.16, 0.2;
       double X_err_to_pt1;					 //Contiendra l'erreur entre l'effecteur du robot et ce premier point
       X_err_to_pt1 = sqrt(pow(H_7.getTranslation().x()-traj_pt1[0], 2) + pow(H_7.getTranslation().y()-traj_pt1[1], 2) + pow(H_7.getTranslation().z()-traj_pt1[2], 2));
       if(X_err_to_pt1 < 0.001 && save_first_time_on_pt1 == 1){
          first_time_on_pt1 = time_in_msecond;
          save_first_time_on_pt1 = 0;}         //On enregistre le temps d'arrivée de l'effecteur sur le point 1

       Eigen::VectorXd traj_pt2(3);			
       //traj_pt2 << -0.4, 0.4, 0.6;
       traj_pt2 << -0.4, 0.4, 0.6;
       double X_err_to_pt2;	
       X_err_to_pt2 = sqrt(pow(H_7.getTranslation().x()-traj_pt2[0], 2) + pow(H_7.getTranslation().y()-traj_pt2[1], 2) + pow(H_7.getTranslation().z()-traj_pt2[2], 2));
       if(X_err_to_pt2 < 0.001 && save_first_time_on_pt2 == 1){
	  first_time_on_pt2 = time_in_msecond;
          save_first_time_on_pt2 = 0;} 

       Eigen::VectorXd traj_pt3(3);			
       traj_pt3 << 0.3, 0.4, 0.6;  //0.3, 0.4, 0.6;
       //traj_pt3 << 0.1, 0.55, 0.6;
       double X_err_to_pt3;
       X_err_to_pt3 = sqrt(pow(H_7.getTranslation().x()-traj_pt3[0], 2) + pow(H_7.getTranslation().y()-traj_pt3[1], 2) + pow(H_7.getTranslation().z()-traj_pt3[2], 2));
       if(X_err_to_pt3 < 0.001 && save_first_time_on_pt3 == 1){
	  first_time_on_pt3 = time_in_msecond;
          save_first_time_on_pt3 = 0;} 

       Eigen::VectorXd traj_pt4(3);			
       traj_pt4 << 0.3, 0.3, 0.2;  //0.3, 0.3, 0.2; ORI COMP CONSTRAINTS 0.3, 0.3, 0.2   //POUR COMP ACC_POI : 0.3, 0.3, 0.5
       //traj_pt4 << 0.1, 0.55, 0.2;
       double X_err_to_pt4;
       X_err_to_pt4 = sqrt(pow(H_7.getTranslation().x()-traj_pt4[0], 2) + pow(H_7.getTranslation().y()-traj_pt4[1], 2) + pow(H_7.getTranslation().z()-traj_pt4[2], 2));
	if(X_err_to_pt4 < 0.001 && save_first_time_on_pt4 == 1){
	  first_time_on_pt4 = time_in_msecond;
          save_first_time_on_pt4 = 0;}


if(one_time_declaration == 1){   
       
    Posi_x_curr  	    =  H_7.getTranslation().x();
    Posi_y_curr  	    =  H_7.getTranslation().y();
    Posi_z_curr  	    =  H_7.getTranslation().z();

    init_posi_x     	    =  H_7.getTranslation().x();
    init_posi_y     	    =  H_7.getTranslation().y();
    init_posi_z     	    =  H_7.getTranslation().z();

    init_orient_alpha       =  0; 
    init_orient_beta        =  0; 
    init_orient_gamma       =  0; 
    init_rot_angle          =  0;    

/*
    target_posi_x   	    =  traj_pt1[0];
    target_posi_y   	    =  traj_pt1[1];
    target_posi_z   	    =  traj_pt1[2];
*/

    target_posi_x   	    =  init_posi_x;                               //On commence à aller vers le premier point de la trajectoire après avoir satisfait la rotation
    target_posi_y   	    =  init_posi_y;
    target_posi_z   	    =  init_posi_z;

    target_orient_alpha     =  angle_7_to_des_rot * axis_7_to_des_rot[0]; //Angle (slerp) projeté sur son axe.
    target_orient_beta      =  angle_7_to_des_rot * axis_7_to_des_rot[1]; 
    target_orient_gamma     =  angle_7_to_des_rot * axis_7_to_des_rot[2]; 
    target_rot_angle        =  angle_7_to_des_rot;                        //Angle désirée équivalent aux quaternions (voir slerp)


    V_7_posi_prev[0]        =  V_7[3];
    V_7_posi_prev[1]        =  V_7[4];
    V_7_posi_prev[2]        =  V_7[5];

    V_7_orient_prev[0]      =  0;
    V_7_orient_prev[1]      =  0;
    V_7_orient_prev[2]      =  0;
    V_angle_curr_rot_prev   =  0;

/*
    Acc_x_prev      	    =  (V_7[3] - V_7_posi_prev[0])/0.001;
    Acc_y_prev      	    =  (V_7[4] - V_7_posi_prev[1])/0.001;
    Acc_z_prev      	    =  (V_7[5] - V_7_posi_prev[2])/0.001;
*/

    Acc_alpha_prev          =  0;
    Acc_beta_prev      	    =  0;
    Acc_gamma_prev          =  0;
    Acc_angle_curr_rot_prev =  0;


    v_x_max         	    =  2.0/dvser;
    v_y_max         	    =  2.0/dvser;
    v_z_max         	    =  2.0/dvser;
    v_angle_max             =  (360)*PI / 180;    //La vitesse de rotation maximale est de 100°/s == 1.74532925 rad/s (sur l'angle du slerp)

    acc_x_max       	    =  2.0/dvser;
    acc_y_max       	    =  2.0/dvser;
    acc_z_max       	    =  2.0/dvser;
    acc_angle_max           =  (320)*PI / 180;    //L'accélération en rotation maximale est de 10°/s² == 1.04719755 rad/s² (sur l'angle du slerp)

    T                       = compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Yemps pour aller d'un point A à un point B de la trajectoire 
    T_angle                 = compute_angle_time(init_rot_angle, target_rot_angle, v_angle_max, acc_angle_max); //C'est le temps de parcour de l'angle du slerp

    T_x                     = T;
    T_y                     = T;
    T_z                     = T;

    T_alpha 		    = T_angle;
    T_beta  		    = T_angle;
    T_gamma 		    = T_angle;


    a_i_x                   = compute_poly_coefficients(init_posi_x, target_posi_x, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_x);
    a_i_y                   = compute_poly_coefficients(init_posi_y, target_posi_y, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_y);
    a_i_z                   = compute_poly_coefficients(init_posi_z, target_posi_z, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_z);
    a_i_alpha      	    = compute_poly_coefficients(init_orient_alpha, target_orient_alpha, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_alpha);
    a_i_beta       	    = compute_poly_coefficients(init_orient_beta, target_orient_beta, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_beta);
    a_i_gamma      	    = compute_poly_coefficients(init_orient_gamma, target_orient_gamma, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_gamma);
    a_i_angle      	    = compute_poly_coefficients(init_rot_angle, target_rot_angle, 0.0, 0.00, 0.0, 0.000, 0.0, 0.0, T_angle);


    //Vecteurs de vitesses et d'accélérations pour les conditions initiales et finales
/*
    Cond_V_1 = ((traj_pt3 - traj_pt1)/(traj_pt3 - traj_pt1).norm()) * 0.2;
    Cond_V_2 = ((traj_pt4 - traj_pt2)/(traj_pt4 - traj_pt2).norm()) * 0.2;
    Cond_V_3 = ((traj_pt2 - traj_pt4)/(traj_pt2 - traj_pt4).norm()) * 0.2;
    Cond_V_4 = ((traj_pt1 - traj_pt3)/(traj_pt1 - traj_pt3).norm()) * 0.2;
    
    Cond_A_1 = ((traj_pt3 - traj_pt1)/(traj_pt3 - traj_pt1).norm()) * 0.2;
    Cond_A_2 = ((traj_pt4 - traj_pt2)/(traj_pt4 - traj_pt2).norm()) * 0.2;
    Cond_A_3 = ((traj_pt2 - traj_pt4)/(traj_pt2 - traj_pt4).norm()) * 0.2;
    Cond_A_4 = ((traj_pt1 - traj_pt3)/(traj_pt1 - traj_pt3).norm()) * 0.2;
*/

    Cond_V_1 = ((traj_pt3 - traj_pt1)/(traj_pt3 - traj_pt1).norm()) * 0.0;
    Cond_V_2 = ((traj_pt4 - traj_pt2)/(traj_pt4 - traj_pt2).norm()) * 0.0;
    Cond_V_3 = ((traj_pt2 - traj_pt4)/(traj_pt2 - traj_pt4).norm()) * 0.0;
    Cond_V_4 = ((traj_pt1 - traj_pt3)/(traj_pt1 - traj_pt3).norm()) * 0.0;
    
    Cond_A_1 = ((traj_pt3 - traj_pt1)/(traj_pt3 - traj_pt1).norm()) * 0.0;
    Cond_A_2 = ((traj_pt4 - traj_pt2)/(traj_pt4 - traj_pt2).norm()) * 0.0;
    Cond_A_3 = ((traj_pt2 - traj_pt4)/(traj_pt2 - traj_pt4).norm()) * 0.0;
    Cond_A_4 = ((traj_pt1 - traj_pt3)/(traj_pt1 - traj_pt3).norm()) * 0.0;


one_time_declaration = 0;
}



//if(abs(angle_curr_rot - target_rot_angle) <= 0.15){

//rotation = true;
 if(one_time_declaration_3 == 1){
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 	        =  0.001;

    //init_posi_x     	=  H_7.getTranslation().x();
    init_posi_x     	=  q[0];
    init_posi_y     	=  H_7.getTranslation().y();
    init_posi_z     	=  H_7.getTranslation().z();

    //target_posi_x       =  traj_pt1[0]    ;         			                     //Point à atteindre par l'effecteur
    target_posi_x       =  3.79   ;         	
    target_posi_y       =  traj_pt1[1]    ;
    target_posi_z       =  traj_pt1[2]    ;

//    target_posi_x       =  H_7.getTranslation().x()    ;         			      //Point à atteindre par l'effecteur
//    target_posi_y       =  H_7.getTranslation().y()    ;
//    target_posi_z       =  H_7.getTranslation().z()    ;

    T  		        =  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, 0.0, 0.0, 0.0, 0.00, 0.0, 0.0, T_x);
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, 0.0, 0.0, 0.0, 0.00, 0.0, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, 0.0, 0.0, 0.0, 0.00, 0.0, 0.0, T_z);
    one_time_declaration_3 = 0;

std::cout<<" T ====================================================================================================================: " << T <<std::endl;

  //}
}
/*
std::cout<<"abs(angle_curr_rot - target_rot_angle) : "<< abs(angle_curr_rot - target_rot_angle)<<std::endl;
std::cout<<"X_err_to_pt1 : "<< X_err_to_pt1<<std::endl;
*/

//rotation = true;
if(aller && rotation){
/*
std::cout<<" " <<std::endl;
std::cout<<" " <<std::endl;
std::cout<<" PT20 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
*/
if( X_err_to_pt1 <= 0.001){                               //On attend environ 5 secondes au pt1 avant déplacement vers le point 2 (Changement de point cible)
//std::cout<<" PT2111 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
if(one_time_declaration_10 == 1){

    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 	        =  0.001;

/*    
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
*/  

    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z;      
                                         
    target_posi_x       =  traj_pt2[0]    ;         			      //Point à atteindre par l'effecteur
    target_posi_y       =  traj_pt2[1]    ;
    target_posi_z       =  traj_pt2[2]    ;

    T  		        =  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
/*
    a_i_x            	=  compute_poly_coefficients(init_posi_x, target_posi_x, 0.0, Cond_V_1(0), 0.0,  Cond_A_1(0), 0.0, 0.0, T_x);   //ORI
    a_i_y           	=  compute_poly_coefficients(init_posi_y, target_posi_y, 0.0, Cond_V_1(1), 0.0,  Cond_A_1(1), 0.0, 0.0, T_y);
    a_i_z           	=  compute_poly_coefficients(init_posi_z, target_posi_z, 0.0, Cond_V_1(2), 0.0,  Cond_A_1(2), 0.0, 0.0, T_z);
*/
    a_i_x            	=  compute_poly_coefficients(init_posi_x, target_posi_x, nxt_step_des_V_7_x, Cond_V_1(0), nxt_step_des_Acc_7_x,  Cond_A_1(0), nxt_step_des_Jerk_7_x, 0.0, T_x);   
    a_i_y           	=  compute_poly_coefficients(init_posi_y, target_posi_y, nxt_step_des_V_7_y, Cond_V_1(1), nxt_step_des_Acc_7_y,  Cond_A_1(1), nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z           	=  compute_poly_coefficients(init_posi_z, target_posi_z, nxt_step_des_V_7_z, Cond_V_1(2), nxt_step_des_Acc_7_z,  Cond_A_1(2), nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_10 = 0;
    }
}



//if((time_in_msecond - first_time_on_pt2) > 100 && (time_in_msecond - first_time_on_pt2) < 150 && X_err_to_pt2 <= err_to_pt){                               					     //On attend environ 5 secondes au pt1 avant déplacement vers le point 2 (Changement de point cible)
if(X_err_to_pt2 <= err_to_pt){               //Dès qu'on touche le point 2, on prend le point 3 comme cible
if(one_time_declaration_20 == 1){
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 		=  0.001; 

    /*
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
    */    
                     
    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z; 
                                                
    target_posi_x 	=  traj_pt3[0]    ;         			     //Point à atteindre par l'effecteur
    target_posi_y 	=  traj_pt3[1]    ;
    target_posi_z 	=  traj_pt3[2]    ;

    T   		=  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, nxt_step_des_V_7_x, Cond_V_2(0), nxt_step_des_Acc_7_x, Cond_A_2(0), nxt_step_des_Jerk_7_x, 0.0, T_x);
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, nxt_step_des_V_7_y, Cond_V_2(1), nxt_step_des_Acc_7_y, Cond_A_2(1), nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, nxt_step_des_V_7_z, Cond_V_2(2), nxt_step_des_Acc_7_z, Cond_A_2(2), nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_20 = 0;

//std::cout << "T " << T <<std::endl; 
    }
}




//if((time_in_msecond - first_time_on_pt3) > 100 && (time_in_msecond - first_time_on_pt3) < 150 && X_err_to_pt3 <= err_to_pt){                               					    //On attend environ 5 secondes au pt1 avant déplacement vers le point 2 (Changement de point cible)
if(X_err_to_pt3 <= err_to_pt){  
if(one_time_declaration_30 == 1){                          					                                 					    
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 		=  0.001;   

    /*
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
    */    
                     
    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z; 
                               
    target_posi_x 	=  traj_pt4[0]    ;     		           //Point à atteindre par l'effecteur
    target_posi_y 	=  traj_pt4[1]    ;
    target_posi_z 	=  traj_pt4[2]    ;  
    T   		=  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;                          
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, nxt_step_des_V_7_x, 0.0, nxt_step_des_Acc_7_x, 0.0, nxt_step_des_Jerk_7_x, 0.0, T_x);
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, nxt_step_des_V_7_y, 0.0, nxt_step_des_Acc_7_y, 0.0, nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, nxt_step_des_V_7_z, 0.0, nxt_step_des_Acc_7_z, 0.0, nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_30 = 0;
    }
}



if(one_time_declaration_70 == 1 && X_err_to_pt4 <= err_to_pt){                               
save_first_time_on_pt4  = 1;
one_time_declaration_70 = 0;
}   





//std::cout << " X_err_to_pt4 : "   << X_err_to_pt4 <<std::endl;
if(time_in_msecond - first_time_on_pt4 > 2000 && X_err_to_pt4 <= err_to_pt){ 
retour = true;
aller  = false;

one_time_declaration_10 = 1;
one_time_declaration_20 = 1;
one_time_declaration_30 = 1;
one_time_declaration_70 = 1;

}
}









if(retour && rotation){
//Transitions entre les points cibles de la trajectoire 
if((time_in_msecond - first_time_on_pt4) > 2000 && (time_in_msecond - first_time_on_pt4) < 2050  && X_err_to_pt4 <= err_to_pt){                               //On attend environ 5 secondes au pt1 avant déplacement vers le point 2 (Changement de point cible)
if(one_time_declaration_40 == 1){                          					    
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 		=  0.001;

    /*
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
    */    
                     
    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z; 
                         
    target_posi_x 	=  traj_pt3[0]    ;          //Point à atteindre par l'effecteur
    target_posi_y 	=  traj_pt3[1]    ;
    target_posi_z 	=  traj_pt3[2]    ;
    T   		=  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
/*
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, 0.0, Cond_V_3(0),  0.0,  Cond_A_3(0), 0.0, 0.0, T_x);  //ORI
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, 0.0, Cond_V_3(1),  0.0,  Cond_A_3(1), 0.0, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, 0.0, Cond_V_3(2),  0.0,  Cond_A_3(2), 0.0, 0.0, T_z);
*/
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, nxt_step_des_V_7_x, Cond_V_3(0),  nxt_step_des_Acc_7_x,  Cond_A_3(0), nxt_step_des_Jerk_7_x, 0.0, T_x);  
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, nxt_step_des_V_7_y, Cond_V_3(1),  nxt_step_des_Acc_7_y,  Cond_A_3(1), nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, nxt_step_des_V_7_z, Cond_V_3(2),  nxt_step_des_Acc_7_z,  Cond_A_3(2), nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_40 = 0;
    }
}


//if((time_in_msecond - first_time_on_pt3) > 100 && (time_in_msecond - first_time_on_pt3) < 150 && X_err_to_pt3 <= err_to_pt){                               
if(X_err_to_pt3 <= err_to_pt){   
if(one_time_declaration_50 == 1){                                                       
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 		=  0.001;  

    /*
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
    */    
                     
    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z; 
                                                  
    target_posi_x 	=  traj_pt2[0]    ;      
    target_posi_y 	=  traj_pt2[1]    ;
    target_posi_z 	=  traj_pt2[2]    ;
    T   		=  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x,  nxt_step_des_V_7_x,  Cond_V_4(0),  nxt_step_des_Acc_7_x,  Cond_A_4(0), nxt_step_des_Jerk_7_x, 0.0, T_x);
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y,  nxt_step_des_V_7_y,  Cond_V_4(1),  nxt_step_des_Acc_7_y,  Cond_A_4(1), nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z,  nxt_step_des_V_7_z,  Cond_V_4(2),  nxt_step_des_Acc_7_z,  Cond_A_4(2), nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_50 = 0;
    }
}


//if((time_in_msecond - first_time_on_pt2) > 100 && (time_in_msecond - first_time_on_pt2) < 150 && X_err_to_pt2 <= err_to_pt){                               
if(X_err_to_pt2 <= err_to_pt){   
if(one_time_declaration_60 == 1){                                                           
    t_1_x 		=  0.001;
    t_1_y 		=  0.001;
    t_1_z 		=  0.001; 

    /*
    init_posi_x     =  H_7.getTranslation().x();
    init_posi_y     =  H_7.getTranslation().y();
    init_posi_z     =  H_7.getTranslation().z();      
    */    
                     
    init_posi_x     =  nxt_step_des_x;
    init_posi_y     =  nxt_step_des_y;
    init_posi_z     =  nxt_step_des_z; 
                         
    target_posi_x 	=  traj_pt1[0]    ;      
    target_posi_y 	=  traj_pt1[1]    ;
    target_posi_z 	=  traj_pt1[2]    ;
    T   		=  compute_trj_time(init_posi_x, target_posi_x, init_posi_y, target_posi_y, init_posi_z, target_posi_z, v_x_max, acc_x_max, v_y_max, acc_y_max, v_z_max, acc_z_max); //Temps pour aller d'un point A à un point B de la trajectoire 
    T_x 		=  T;
    T_y 		=  T;
    T_z 		=  T;
    a_i_x          	=  compute_poly_coefficients(init_posi_x, target_posi_x, nxt_step_des_V_7_x, 0.0,  nxt_step_des_Acc_7_x, 0.000, nxt_step_des_Jerk_7_x, 0.0, T_x);
    a_i_y          	=  compute_poly_coefficients(init_posi_y, target_posi_y, nxt_step_des_V_7_y, 0.0,  nxt_step_des_Acc_7_y, 0.000, nxt_step_des_Jerk_7_y, 0.0, T_y);
    a_i_z          	=  compute_poly_coefficients(init_posi_z, target_posi_z, nxt_step_des_V_7_z, 0.0,  nxt_step_des_Acc_7_z, 0.000, nxt_step_des_Jerk_7_z, 0.0, T_z);
    one_time_declaration_60 = 0;
    }    
}




if(one_time_declaration_80 == 1 && X_err_to_pt1 <= err_to_pt){                                 
save_first_time_on_pt1  = 1;
one_time_declaration_80 = 0;
}   



if((time_in_msecond - first_time_on_pt1) > 2000 && (time_in_msecond - first_time_on_pt1) < 2050 && X_err_to_pt1 <= err_to_pt){  
retour = false;
aller  = true;

one_time_declaration_40 = 1;
one_time_declaration_50 = 1;
one_time_declaration_60 = 1;
one_time_declaration_80 = 1;
}
}





       Posi_x_curr     =  H_7.getTranslation().x();
       Posi_y_curr     =  H_7.getTranslation().y();
       Posi_z_curr     =  H_7.getTranslation().z();

       Acc_x_curr      = (V_7[3] - V_7_posi_prev[0])/0.001;
       Acc_y_curr      = (V_7[4] - V_7_posi_prev[1])/0.001;
       Acc_z_curr      = (V_7[5] - V_7_posi_prev[2])/0.001;

       Jerk_x_curr     = (Acc_x_curr - Acc_x_prev)/0.001;
       Jerk_y_curr     = (Acc_y_curr - Acc_y_prev)/0.001;
       Jerk_z_curr     = (Acc_z_curr - Acc_z_prev)/0.001;

       q_ddot          = (q_dot   - q_dot_prev)/0.001; //Accélération articulaire calsulée	
       q_dddot         = (q_ddot  - q_ddot_prev)/0.001; 
       q_ddddot        = (q_dddot - q_dddot_prev)/0.001;
 
       Acc_alpha_curr  = (V_77[0] - V_7_orient_prev[0])/0.001;
       Acc_beta_curr   = (V_77[1] - V_7_orient_prev[1])/0.001;
       Acc_gamma_curr  = (V_77[2] - V_7_orient_prev[2])/0.001;

       Jerk_alpha_curr = (Acc_alpha_curr - Acc_alpha_prev)/0.001;
       Jerk_beta_curr  = (Acc_beta_curr  - Acc_beta_prev) /0.001;
       Jerk_gamma_curr = (Acc_gamma_curr - Acc_gamma_prev)/0.001;


       t_2_x           = t_1_x/T_x;
       t_2_y           = t_1_y/T_y;
       t_2_z           = t_1_z/T_z;
       t_2_angle       = t_1_angle/T_angle;


       nxt_step_des_trj_x        = compute_nxt_step_des_x       (init_posi_x, target_posi_x, a_i_x, Posi_x_curr, T_x, t_2_x);
       nxt_step_des_x            = nxt_step_des_trj_x(0);
       nxt_step_des_V_7_x        = nxt_step_des_trj_x(1);
       nxt_step_des_Acc_7_x      = nxt_step_des_trj_x(2);
       nxt_step_des_Jerk_7_x     = nxt_step_des_trj_x(3);

       nxt_step_des_trj_y        = compute_nxt_step_des_y       (init_posi_y, target_posi_y, a_i_y, Posi_y_curr, T_y, t_2_y);
       nxt_step_des_y            = nxt_step_des_trj_y(0);
       nxt_step_des_V_7_y        = nxt_step_des_trj_y(1);
       nxt_step_des_Acc_7_y      = nxt_step_des_trj_y(2);
       nxt_step_des_Jerk_7_y     = nxt_step_des_trj_y(3);

       nxt_step_des_trj_z        = compute_nxt_step_des_z       (init_posi_z, target_posi_z, a_i_z, Posi_z_curr, T_z, t_2_z);
       nxt_step_des_z            = nxt_step_des_trj_z(0);
       nxt_step_des_V_7_z        = nxt_step_des_trj_z(1);
       nxt_step_des_Acc_7_z      = nxt_step_des_trj_z(2);
       nxt_step_des_Jerk_7_z     = nxt_step_des_trj_z(3);

       nxt_step_des_trj_alpha    = compute_nxt_step_des_alpha (init_orient_alpha, target_orient_alpha, a_i_alpha,T_angle, t_1_angle, t_2_angle);
       nxt_step_des_V_7_alpha    = nxt_step_des_trj_alpha(0);
       nxt_step_des_Acc_7_alpha  = nxt_step_des_trj_alpha(1);
       nxt_step_des_Jerk_7_alpha = nxt_step_des_trj_alpha(2);
       
       nxt_step_des_trj_beta     = compute_nxt_step_des_beta  (init_orient_beta, target_orient_beta, a_i_beta, T_angle, t_1_angle, t_2_angle);
       nxt_step_des_V_7_beta     = nxt_step_des_trj_beta(0); 
       nxt_step_des_Acc_7_beta   = nxt_step_des_trj_beta(1);
       nxt_step_des_Jerk_7_beta  = nxt_step_des_trj_beta(2);

       nxt_step_des_trj_gamma    = compute_nxt_step_des_gamma (init_orient_gamma, target_orient_gamma, a_i_gamma, T_angle, t_1_angle, t_2_angle);
       nxt_step_des_V_7_gamma    = nxt_step_des_trj_gamma(0);
       nxt_step_des_Acc_7_gamma  = nxt_step_des_trj_gamma(1);
       nxt_step_des_Jerk_7_gamma = nxt_step_des_trj_gamma(2);

       nxt_step_des_trj_angle    = compute_nxt_step_des_angle (init_rot_angle, target_rot_angle, a_i_angle, angle_curr_rot, nxt_step_des_angle_prev, T_angle, t_1_angle, t_2_angle);
       nxt_step_des_angle        = nxt_step_des_trj_angle(0);  //Ceci est l'angle du slerp --> Remarque important, l'erreur n'est pas calculée avec cette angle
       nxt_step_des_V_7_angle    = nxt_step_des_trj_angle(1);
       nxt_step_des_Acc_7_angle  = nxt_step_des_trj_angle(2);
       nxt_step_des_Jerk_7_angle = nxt_step_des_trj_angle(3);

       nxt_step_des_quat         = compute_nxt_step_des_quat(init_H_quat_70, target_H_quat_70, a_i_angle, cosHalfTheta, T_angle, t_1_angle, t_2_angle);  //On utilise ces quaterniosn pour l'interpolation de la position en rotation. Les vitesses, et accélérations sont interpolées avec l'angle du slerp
																			 //Ces quats servent à calculer l'err en rotation
       V_7_des                   << nxt_step_des_V_7_x,    nxt_step_des_V_7_y,    nxt_step_des_V_7_z;
       Acc_7                     << Acc_x_curr,            Acc_y_curr,            Acc_z_curr;
       Acc_7_des                 << nxt_step_des_Acc_7_x,  nxt_step_des_Acc_7_y,  nxt_step_des_Acc_7_z;
       Jerk_7                    << Jerk_x_curr,           Jerk_y_curr,           Jerk_z_curr;
       Jerk_7_des                << nxt_step_des_Jerk_7_x, nxt_step_des_Jerk_7_y, nxt_step_des_Jerk_7_z;
       angle_curr_rot_prj        << angle_curr_rot*axis_7_to_des_rot(0),            angle_curr_rot*axis_7_to_des_rot(1),            angle_curr_rot*axis_7_to_des_rot(2);                 
       angle_7_to_des_rot_prj    << nxt_step_des_angle*axis_7_to_des_rot(0),        nxt_step_des_angle*axis_7_to_des_rot(1),        nxt_step_des_angle*axis_7_to_des_rot(2);

       V_7_orient                << V_77[0], V_77[1], V_77[2];
       V_7_orient_des            << nxt_step_des_V_7_alpha,    nxt_step_des_V_7_beta,    nxt_step_des_V_7_gamma;
       Acc_7_orient              << Acc_alpha_curr,            Acc_beta_curr,            Acc_gamma_curr;
       Acc_7_orient_des          << nxt_step_des_Acc_7_alpha,  nxt_step_des_Acc_7_beta,  nxt_step_des_Acc_7_gamma;
       Jerk_7_orient             << Jerk_alpha_curr,           Jerk_beta_curr,           Jerk_gamma_curr;
       Jerk_7_orient_des         << nxt_step_des_Jerk_7_alpha, nxt_step_des_Jerk_7_beta, nxt_step_des_Jerk_7_gamma;

       norme_angle_curr_rot_prj     = sqrt(pow(angle_curr_rot_prj(0), 2)     + pow(angle_curr_rot_prj(1), 2)     + pow(angle_curr_rot_prj(2), 2));
       norme_angle_7_to_des_rot_prj = sqrt(pow(angle_7_to_des_rot_prj(0), 2) + pow(angle_7_to_des_rot_prj(1), 2) + pow(angle_7_to_des_rot_prj(2), 2));

       norme_V_7_orient             = sqrt(pow(V_7_orient(0), 2)     + pow(V_7_orient(1), 2)     + pow(V_7_orient(2), 2));
       norme_V_7_orient_des         = sqrt(pow(V_7_orient_des(0), 2) + pow(V_7_orient_des(1), 2) + pow(V_7_orient_des(2), 2));
	
       norme_Acc_7_orient           = sqrt(pow(Acc_7_orient(0), 2)     + pow(Acc_7_orient(1), 2)     + pow(Acc_7_orient(2), 2));
       norme_Acc_7_orient_des       = sqrt(pow(Acc_7_orient_des(0), 2) + pow(Acc_7_orient_des(1), 2) + pow(Acc_7_orient_des(2), 2));


       V_7_posi_prev[0] 	    =  V_7[3];
       V_7_posi_prev[1] 	    =  V_7[4];
       V_7_posi_prev[2] 	    =  V_7[5];
       q_dot_prev                   =  q_dot;  //Pour calculer l'accélération articulaire
       q_ddot_prev                  =  q_ddot; //Pour calculer le Jerk articulaire
       q_dddot_prev                 =  q_dddot;

       Acc_posi_70 << Acc_x_prev, Acc_y_prev, Acc_z_prev;


       Acc_x_prev 	 	    =  Acc_x_curr;
       Acc_y_prev 	 	    =  Acc_y_curr;
       Acc_z_prev 	 	    =  Acc_z_curr;

       V_7_orient_prev[0]           =  V_77[0];      
       V_7_orient_prev[1]           =  V_77[1]; 
       V_7_orient_prev[2]           =  V_77[2]; 

       Acc_alpha_prev 	 	    =  Acc_alpha_curr;
       Acc_beta_prev 	 	    =  Acc_beta_curr;
       Acc_gamma_prev 	 	    =  Acc_gamma_curr;

       angle_curr_rot_prev          =  angle_curr_rot;            //L'interpolation de la vitesse et acc de rotation se font sur le system Angle/Axe 
       V_angle_curr_rot_prev        =  V_angle_curr_rot;
       Acc_angle_curr_rot_prev      =  Acc_angle_curr_rot;

       nxt_step_des_angle_prev      = nxt_step_des_angle;


       X_err_x                      = nxt_step_des_x - H_7.getTranslation().x();
       X_err_y                      = nxt_step_des_y - H_7.getTranslation().y();
       X_err_z                      = nxt_step_des_z - H_7.getTranslation().z();
       X_err                        << X_err_x, X_err_y, X_err_z;
       X_err_orient                 << (H_orient_70.inverse() * nxt_step_des_quat).log();          //Erreur en orientation due à l'interpolation des quaternions;


       X_err_real                   << (Posi_x_curr - Posi_x_curr_prev), (Posi_y_curr - Posi_y_curr_prev), (Posi_z_curr - Posi_z_curr_prev); 

       Posi_x_curr_prev = Posi_x_curr;
       Posi_y_curr_prev = Posi_y_curr;
       Posi_z_curr_prev = Posi_z_curr;

       norme_X_err                  = sqrt(X_err_x*X_err_x + X_err_y*X_err_y + X_err_z*X_err_z);
       norme_X_err_orient           = sqrt((X_err_orient(0)*X_err_orient(0)) + (X_err_orient(1)*X_err_orient(1)) + (X_err_orient(2)*X_err_orient(2)));
          

       V_err_x                      = V_7_des[0] - V_7[3];
       V_err_y                      = V_7_des[1] - V_7[4];
       V_err_z                      = V_7_des[2] - V_7[5];

       V_err_angle_prj_0            = V_7_orient_des[0] - V_77[0];
       V_err_angle_prj_1            = V_7_orient_des[1] - V_77[1];
       V_err_angle_prj_2            = V_7_orient_des[2] - V_77[2];

       V_err                        << V_err_x, V_err_y, V_err_z;
       V_err_angle_prj              << V_err_angle_prj_0, V_err_angle_prj_1, V_err_angle_prj_2;

       norme_V_err                  = sqrt(V_err_x*V_err_x + V_err_y*V_err_y + V_err_z*V_err_z);
       norme_V_err_angle_prj        = sqrt(V_err_angle_prj_0*V_err_angle_prj_0 + V_err_angle_prj_1*V_err_angle_prj_1 + V_err_angle_prj_2*V_err_angle_prj_2);

       Err_interpolation_aggle_deg  = (nxt_step_des_trj_angle(0) - angle_curr_rot) * 180/PI; //Err entre l'angle d'interpolation désiré et l'angle acturel


   
//Ajoutés pour la partie concernant l'énergie potentielle
//Projection de la jacobienne linéaire et de sa dérivée dans la direction du vecteur d'erreur (Xdes - X)
n_Xerr_normalized = X_err.normalized();
n_Xerr            = n_Xerr_normalized;



J_70_l_proj_Xerr <<  (n_Xerr[0] * J_70(3, 0) + n_Xerr[1] * J_70(4, 0) + n_Xerr[2] * J_70(5, 0)),     
		     (n_Xerr[0] * J_70(3, 1) + n_Xerr[1] * J_70(4, 1) + n_Xerr[2] * J_70(5, 1)),
		     (n_Xerr[0] * J_70(3, 2) + n_Xerr[1] * J_70(4, 2) + n_Xerr[2] * J_70(5, 2)),
		     (n_Xerr[0] * J_70(3, 3) + n_Xerr[1] * J_70(4, 3) + n_Xerr[2] * J_70(5, 3)),
		     (n_Xerr[0] * J_70(3, 4) + n_Xerr[1] * J_70(4, 4) + n_Xerr[2] * J_70(5, 4)),
		     (n_Xerr[0] * J_70(3, 5) + n_Xerr[1] * J_70(4, 5) + n_Xerr[2] * J_70(5, 5)),
		     (n_Xerr[0] * J_70(3, 6) + n_Xerr[1] * J_70(4, 6) + n_Xerr[2] * J_70(5, 6));


J_70_dot_l_proj_Xerr <<  (n_Xerr[0] * J_70_dot_l(0, 0) + n_Xerr[1] * J_70_dot_l(1, 0) + n_Xerr[2] * J_70_dot_l(2, 0)),     
		         (n_Xerr[0] * J_70_dot_l(0, 1) + n_Xerr[1] * J_70_dot_l(1, 1) + n_Xerr[2] * J_70_dot_l(2, 1)),
		         (n_Xerr[0] * J_70_dot_l(0, 2) + n_Xerr[1] * J_70_dot_l(1, 2) + n_Xerr[2] * J_70_dot_l(2, 2)),
		         (n_Xerr[0] * J_70_dot_l(0, 3) + n_Xerr[1] * J_70_dot_l(1, 3) + n_Xerr[2] * J_70_dot_l(2, 3)),
		         (n_Xerr[0] * J_70_dot_l(0, 4) + n_Xerr[1] * J_70_dot_l(1, 4) + n_Xerr[2] * J_70_dot_l(2, 4)),
		         (n_Xerr[0] * J_70_dot_l(0, 5) + n_Xerr[1] * J_70_dot_l(1, 5) + n_Xerr[2] * J_70_dot_l(2, 5)),
		         (n_Xerr[0] * J_70_dot_l(0, 6) + n_Xerr[1] * J_70_dot_l(1, 6) + n_Xerr[2] * J_70_dot_l(2, 6));

m_eq_7_j_inter_Xerr = (J_70_l_proj_Xerr * M_inv * J_70_l_proj_Xerr.transpose());
m_eq_7_j_Xerr       = 1/m_eq_7_j_inter_Xerr;

/*
std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<"Posi_x_curr : "<<Posi_x_curr<<std::endl;
std::cout<<"Posi_y_curr : "<<Posi_y_curr<<std::endl;
std::cout<<"Posi_z_curr : "<<Posi_z_curr<<std::endl;
*/




//ÂµÂµÂµÂµÂµ
J_70_l_proj_x_axis <<    (x_axis[0] * J_70(3, 0) + x_axis[1] * J_70(4, 0) + x_axis[2] * J_70(5, 0)),     
		 	 (x_axis[0] * J_70(3, 1) + x_axis[1] * J_70(4, 1) + x_axis[2] * J_70(5, 1)),
		 	 (x_axis[0] * J_70(3, 2) + x_axis[1] * J_70(4, 2) + x_axis[2] * J_70(5, 2)),
		         (x_axis[0] * J_70(3, 3) + x_axis[1] * J_70(4, 3) + x_axis[2] * J_70(5, 3)),
			 (x_axis[0] * J_70(3, 4) + x_axis[1] * J_70(4, 4) + x_axis[2] * J_70(5, 4)),
		 	 (x_axis[0] * J_70(3, 5) + x_axis[1] * J_70(4, 5) + x_axis[2] * J_70(5, 5)),
		 	 (x_axis[0] * J_70(3, 6) + x_axis[1] * J_70(4, 6) + x_axis[2] * J_70(5, 6));


J_70_dot_l_proj_x_axis <<  (x_axis[0] * J_70_dot(3, 0) + x_axis[1] * J_70_dot(4, 0) + x_axis[2] * J_70_dot(5, 0)),     
		  	   (x_axis[0] * J_70_dot(3, 1) + x_axis[1] * J_70_dot(4, 1) + x_axis[2] * J_70_dot(5, 1)),
		   	   (x_axis[0] * J_70_dot(3, 2) + x_axis[1] * J_70_dot(4, 2) + x_axis[2] * J_70_dot(5, 2)),
		    	   (x_axis[0] * J_70_dot(3, 3) + x_axis[1] * J_70_dot(4, 3) + x_axis[2] * J_70_dot(5, 3)),
		           (x_axis[0] * J_70_dot(3, 4) + x_axis[1] * J_70_dot(4, 4) + x_axis[2] * J_70_dot(5, 4)),
		           (x_axis[0] * J_70_dot(3, 5) + x_axis[1] * J_70_dot(4, 5) + x_axis[2] * J_70_dot(5, 5)),
		           (x_axis[0] * J_70_dot(3, 6) + x_axis[1] * J_70_dot(4, 6) + x_axis[2] * J_70_dot(5, 6));
	    		

m_eq_7_j_inter_x_axis = (J_70_l_proj_x_axis * M_inv * J_70_l_proj_x_axis.transpose());
m_eq_7_j_x_axis       = 1/m_eq_7_j_inter_x_axis;


//ÂµÂµÂµÂµÂµ
J_70_l_proj_y_axis <<    (y_axis[0] * J_70(3, 0) + y_axis[1] * J_70(4, 0) + y_axis[2] * J_70(5, 0)),     
		 	 (y_axis[0] * J_70(3, 1) + y_axis[1] * J_70(4, 1) + y_axis[2] * J_70(5, 1)),
		 	 (y_axis[0] * J_70(3, 2) + y_axis[1] * J_70(4, 2) + y_axis[2] * J_70(5, 2)),
		         (y_axis[0] * J_70(3, 3) + y_axis[1] * J_70(4, 3) + y_axis[2] * J_70(5, 3)),
		         (y_axis[0] * J_70(3, 4) + y_axis[1] * J_70(4, 4) + y_axis[2] * J_70(5, 4)),
		         (y_axis[0] * J_70(3, 5) + y_axis[1] * J_70(4, 5) + y_axis[2] * J_70(5, 5)),
		         (y_axis[0] * J_70(3, 6) + y_axis[1] * J_70(4, 6) + y_axis[2] * J_70(5, 6));


J_70_dot_l_proj_y_axis <<  (y_axis[0] * J_70_dot(3, 0) + y_axis[1] * J_70_dot(4, 0) + y_axis[2] * J_70_dot(5, 0)),     
		  	   (y_axis[0] * J_70_dot(3, 1) + y_axis[1] * J_70_dot(4, 1) + y_axis[2] * J_70_dot(5, 1)),
		   	   (y_axis[0] * J_70_dot(3, 2) + y_axis[1] * J_70_dot(4, 2) + y_axis[2] * J_70_dot(5, 2)),
		           (y_axis[0] * J_70_dot(3, 3) + y_axis[1] * J_70_dot(4, 3) + y_axis[2] * J_70_dot(5, 3)),
		           (y_axis[0] * J_70_dot(3, 4) + y_axis[1] * J_70_dot(4, 4) + y_axis[2] * J_70_dot(5, 4)),
		           (y_axis[0] * J_70_dot(3, 5) + y_axis[1] * J_70_dot(4, 5) + y_axis[2] * J_70_dot(5, 5)),
		    	   (y_axis[0] * J_70_dot(3, 6) + y_axis[1] * J_70_dot(4, 6) + y_axis[2] * J_70_dot(5, 6));
	    		

m_eq_7_j_inter_y_axis = (J_70_l_proj_y_axis * M_inv * J_70_l_proj_y_axis.transpose());
m_eq_7_j_y_axis       = 1/m_eq_7_j_inter_y_axis;


//ÂµÂµÂµÂµÂµ
J_70_l_proj_z_axis <<    (z_axis[0] * J_70(3, 0) + z_axis[1] * J_70(4, 0) + z_axis[2] * J_70(5, 0)),     
		 	 (z_axis[0] * J_70(3, 1) + z_axis[1] * J_70(4, 1) + z_axis[2] * J_70(5, 1)),
		 	 (z_axis[0] * J_70(3, 2) + z_axis[1] * J_70(4, 2) + z_axis[2] * J_70(5, 2)),
		 	 (z_axis[0] * J_70(3, 3) + z_axis[1] * J_70(4, 3) + z_axis[2] * J_70(5, 3)),
			 (z_axis[0] * J_70(3, 4) + z_axis[1] * J_70(4, 4) + z_axis[2] * J_70(5, 4)),
		 	 (z_axis[0] * J_70(3, 5) + z_axis[1] * J_70(4, 5) + z_axis[2] * J_70(5, 5)),
		 	 (z_axis[0] * J_70(3, 6) + z_axis[1] * J_70(4, 6) + z_axis[2] * J_70(5, 6));


J_70_dot_l_proj_z_axis <<  (z_axis[0] * J_70_dot(3, 0) + z_axis[1] * J_70_dot(4, 0) + z_axis[2] * J_70_dot(5, 0)),     
		  	   (z_axis[0] * J_70_dot(3, 1) + z_axis[1] * J_70_dot(4, 1) + z_axis[2] * J_70_dot(5, 1)),
		   	   (z_axis[0] * J_70_dot(3, 2) + z_axis[1] * J_70_dot(4, 2) + z_axis[2] * J_70_dot(5, 2)),
		    	   (z_axis[0] * J_70_dot(3, 3) + z_axis[1] * J_70_dot(4, 3) + z_axis[2] * J_70_dot(5, 3)),
		           (z_axis[0] * J_70_dot(3, 4) + z_axis[1] * J_70_dot(4, 4) + z_axis[2] * J_70_dot(5, 4)),
		           (z_axis[0] * J_70_dot(3, 5) + z_axis[1] * J_70_dot(4, 5) + z_axis[2] * J_70_dot(5, 5)),
		    	  (z_axis[0] * J_70_dot(3, 6) + z_axis[1] * J_70_dot(4, 6) + z_axis[2] * J_70_dot(5, 6));
	    		

m_eq_7_j_inter_z_axis = (J_70_l_proj_z_axis * M_inv * J_70_l_proj_z_axis.transpose());
m_eq_7_j_z_axis       = 1/m_eq_7_j_inter_z_axis;











       V_7_posi[0] 	    =  V_7[3];
       V_7_posi[1] 	    =  V_7[4];
       V_7_posi[2] 	    =  V_7[5];

       V_7_posi_proj       << V_7_posi[0] * n_Xerr[0], V_7_posi[1] * n_Xerr[1], V_7_posi[2] * n_Xerr[2];


save_Ep_7_prj_real(-m_eq_7_j_Xerr * Acc_x_curr * Acc_x_curr * X_err[0]);                 //VRAI ENERGY POTENTIELLE 
save_F_7_x(Acc_x_curr * m_eq_7_j_Xerr);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


       if(t_1_x < T_x && t_1_x + 0.001 < T_x){
       t_1_x                  = t_1_x + 0.001;         //Increment pour parcourir les profiles de la trajectoire
       }
       else{
       t_1_x                  = T_x;
       }

       if(t_1_y < T_y && t_1_y + 0.001 < T_y){
       t_1_y                  = t_1_y + 0.001;         //Increment pour parcourir les profiles de la trajectoire
       }
       else{
       t_1_y                  = T_y;
       }

       if(t_1_z < T_z && t_1_z + 0.001 < T_z){
       t_1_z                  = t_1_z + 0.001;         //Increment pour parcourir les profiles de la trajectoire
       }
       else{
       t_1_z                  = T_z;
       }

       if(t_1_angle < T_angle && t_1_angle + 0.001 < T_angle){
       t_1_angle             = t_1_angle + 0.001;  //Increment pour parcourir les profiles de la rotation
       }
       else{
       t_1_angle             = T_angle;
       }

     
////////////////////////////////////////////// Trajectory Interpolation_3DDL online PICK&PLACE TRANSLATION + ROTATION///////////////////////////////////////












///////////////////////////////////////////////////////// save DATA ////////////////////////////////////////////////////////////
      save_tau_sensor_0(tau_sensor_0); 

       save_des_trajectory_x(nxt_step_des_x);
       save_des_trajectory_y(nxt_step_des_y);
       save_des_trajectory_z(nxt_step_des_z);
       save_trajectory_x(H_7.getTranslation().x());
       save_trajectory_y(H_7.getTranslation().y());
       save_trajectory_z(H_7.getTranslation().z());


       save_norme_angle_curr_rot_prj(norme_angle_curr_rot_prj);
       save_angle_curr_rot_prj_0(angle_curr_rot_prj(0));  
       save_angle_curr_rot_prj_1(angle_curr_rot_prj(1));  
       save_angle_curr_rot_prj_2(angle_curr_rot_prj(2));  
       save_trajectory_angle(angle_curr_rot * 180 / PI);         // Angle courant (Equivanlent Quaternions)

       save_norme_angle_7_to_des_rot_prj(norme_angle_7_to_des_rot_prj);
       save_angle_7_to_des_rot_prj_0(angle_7_to_des_rot_prj(0));  
       save_angle_7_to_des_rot_prj_1(angle_7_to_des_rot_prj(1));  
       save_angle_7_to_des_rot_prj_2(angle_7_to_des_rot_prj(2));  
       save_des_trajectory_angle(nxt_step_des_angle * 180 / PI); // Angle désiré (Equivanlent Quaternions)


       save_Acc_7(sqrt(pow(Acc_x_curr,2) + pow(Acc_y_curr,2) + pow(Acc_z_curr,2)));
       save_Acc_7_x(Acc_x_curr);
       save_Acc_7_y(Acc_y_curr);
       save_Acc_7_z(Acc_z_curr);


       save_norme_Acc_7_orient(norme_Acc_7_orient);
       save_Acc_7_orient_0(Acc_7_orient(0));  
       save_Acc_7_orient_1(Acc_7_orient(1));  
       save_Acc_7_orient_2(Acc_7_orient(2));  

       save_norme_Acc_7_orient_des(norme_Acc_7_orient_des);
       save_Acc_7_orient_des_0(Acc_7_orient_des(0));  
       save_Acc_7_orient_des_1(Acc_7_orient_des(1));  
       save_Acc_7_orient_des_2(Acc_7_orient_des(2));  
       save_Acc_7_angle(Acc_angle_curr_rot);


       save_Jerk_7(sqrt(pow(Jerk_7[0],2) + pow(Jerk_7[1],2) + pow(Jerk_7[2],2)));
       save_Jerk_7_x(Jerk_x_curr);
       save_Jerk_7_y(Jerk_y_curr);
       save_Jerk_7_z(Jerk_z_curr);
       save_Jerk_7_angle(Jerk_angle_curr_rot);  



	save_V_7_des(sqrt(pow(V_7_des[0],2) + pow(V_7_des[1],2) + pow(V_7_des[2],2)));
	save_V_7_des_x(V_7_des[0]);
	save_V_7_des_y(V_7_des[1]);
	save_V_7_des_z(V_7_des[2]);

       save_V_7(sqrt(pow(V_7[3], 2) + pow(V_7[4], 2) + pow(V_7[5], 2)));
       save_V_7_x(V_7[3]);
       save_V_7_y(V_7[4]);
       save_V_7_z(V_7[5]);


       save_norme_V_7_orient(norme_V_7_orient);
       save_V_7_orient_0(V_7_orient(0));  
       save_V_7_orient_1(V_7_orient(1));  
       save_V_7_orient_2(V_7_orient(2));  
       save_norme_V_7_orient_des(norme_V_7_orient_des);

       save_V_7_orient_des_0(V_7_orient_des(0));  
       save_V_7_orient_des_1(V_7_orient_des(1));  
       save_V_7_orient_des_2(V_7_orient_des(2)); 
       save_V_7_angle(V_angle_curr_rot);  
       save_V_7_des_angle(nxt_step_des_V_7_angle);  

/*
       save_des_qw(H_disp_des_rot.qw());
       save_des_qx(H_disp_des_rot.qx());
       save_des_qy(H_disp_des_rot.qy());
       save_des_qz(H_disp_des_rot.qz());
*/
       save_des_qw(nxt_step_des_quat.w());
       save_des_qx(nxt_step_des_quat.x());
       save_des_qy(nxt_step_des_quat.y());
       save_des_qz(nxt_step_des_quat.z());

       save_qw(H_7.getRotation().w());
       save_qx(H_7.getRotation().x());
       save_qy(H_7.getRotation().y());
       save_qz(H_7.getRotation().z());
       
       save_axis_curr_rot_0(axis_curr_rot(0));
       save_axis_curr_rot_1(axis_curr_rot(1));
       save_axis_curr_rot_2(axis_curr_rot(2));
       save_axis_7_to_des_rot_0(axis_7_to_des_rot(0));
       save_axis_7_to_des_rot_1(axis_7_to_des_rot(1));
       save_axis_7_to_des_rot_2(axis_7_to_des_rot(2));

       save_X_err_x(X_err_x);
       save_X_err_y(X_err_y);
       save_X_err_z(X_err_z);
       save_X_err(norme_X_err);

       save_X_err_orient_0(X_err_orient(0));
       save_X_err_orient_1(X_err_orient(1));
       save_X_err_orient_2(X_err_orient(2));
       save_X_err_orient(norme_X_err_orient);

       save_Err_interpolation_aggle(Err_interpolation_aggle_deg);


       Acc_7_err << Acc_7_des[0] - Acc_7[0], Acc_7_des[1] - Acc_7[1], Acc_7_des[2] - Acc_7[2];
       save_Acc_7_err(sqrt(pow(Acc_7_err[0],2) + pow(Acc_7_err[1],2) + pow(Acc_7_err[2],2)));
       save_Acc_7_err_x(Acc_7_err[0]); 
       save_Acc_7_err_y(Acc_7_err[1]);
       save_Acc_7_err_z(Acc_7_err[2]);


        save_Acc_7_des_angle(nxt_step_des_Acc_7_angle);  //

	save_Jerk_7_des(sqrt(pow(Jerk_7_des[0],2) + pow(Jerk_7_des[1],2) + pow(Jerk_7_des[2],2)));
	save_Jerk_7_des_x(Jerk_7_des[0]);
	save_Jerk_7_des_y(Jerk_7_des[1]);
	save_Jerk_7_des_z(Jerk_7_des[2]);
	save_Jerk_7_des_angle(nxt_step_des_Jerk_7_angle);  //




        save_q_dot(q_dot[0], q_dot[1], q_dot[2], q_dot[3], q_dot[4], q_dot[5], q_dot[6]);
	save_q_dot_0_min(q_dot_bounds_min[0]);
	save_q_dot_1_min(q_dot_bounds_min[1]);
	save_q_dot_2_min(q_dot_bounds_min[2]);
	save_q_dot_3_min(q_dot_bounds_min[3]);
	save_q_dot_4_min(q_dot_bounds_min[4]);
	save_q_dot_5_min(q_dot_bounds_min[5]);
	save_q_dot_6_min(q_dot_bounds_min[6]);

	save_q_dot_0_max(q_dot_bounds_max[0]);
	save_q_dot_1_max(q_dot_bounds_max[1]);
	save_q_dot_2_max(q_dot_bounds_max[2]);
	save_q_dot_3_max(q_dot_bounds_max[3]);
	save_q_dot_4_max(q_dot_bounds_max[4]);
	save_q_dot_5_max(q_dot_bounds_max[5]);
	save_q_dot_6_max(q_dot_bounds_max[6]);

        save_q(q[0], q[1], q[2], q[3], q[4], q[5], q[6]);
	save_q_0_min(q_bounds_min[0]);
	save_q_1_min(q_bounds_min[1]);
	save_q_2_min(q_bounds_min[2]);
	save_q_3_min(q_bounds_min[3]);
	save_q_4_min(q_bounds_min[4]);
	save_q_5_min(q_bounds_min[5]);
	save_q_6_min(q_bounds_min[6]);

	save_q_0_max(q_bounds_max[0]);
	save_q_1_max(q_bounds_max[1]);
	save_q_2_max(q_bounds_max[2]);
	save_q_3_max(q_bounds_max[3]);
	save_q_4_max(q_bounds_max[4]);
	save_q_5_max(q_bounds_max[5]);
	save_q_6_max(q_bounds_max[6]);




//Save_Jerk
save_q_dotdotdot_0(q_dddot[0]);
save_q_dotdotdot_1(q_dddot[1]);
save_q_dotdotdot_2(q_dddot[2]);
save_q_dotdotdot_3(q_dddot[3]);
save_q_dotdotdot_4(q_dddot[4]);
save_q_dotdotdot_5(q_dddot[5]);
save_q_dotdotdot_6(q_dddot[6]);
//Save_Jerk_max
save_q_dotdotdot_0_max(q_dddot_bounds_max[0]);
save_q_dotdotdot_1_max(q_dddot_bounds_max[1]);
save_q_dotdotdot_2_max(q_dddot_bounds_max[2]);
save_q_dotdotdot_3_max(q_dddot_bounds_max[3]);
save_q_dotdotdot_4_max(q_dddot_bounds_max[4]);
save_q_dotdotdot_5_max(q_dddot_bounds_max[5]);
save_q_dotdotdot_6_max(q_dddot_bounds_max[6]);
//Save_Jerk_min
save_q_dotdotdot_0_min(q_dddot_bounds_min[0]);
save_q_dotdotdot_1_min(q_dddot_bounds_min[1]);
save_q_dotdotdot_2_min(q_dddot_bounds_min[2]);
save_q_dotdotdot_3_min(q_dddot_bounds_min[3]);
save_q_dotdotdot_4_min(q_dddot_bounds_min[4]);
save_q_dotdotdot_5_min(q_dddot_bounds_min[5]);
save_q_dotdotdot_6_min(q_dddot_bounds_min[6]);




        save_real_step_time(step_time_micro/1000000);
        save_fixed_dt(dt);

	save_V_7_ob(V_7_ob_sgn_norm);                //C'est la vitesse du dernier segment du robot dans la direction de l'obstacle considéré --> au point de l'effecteur, V_7_ob_sgn_norm = project(V_7, dist) 

	save_V_7_C_ob(V_7_C_ob);          	     //C'est la vitesse du dernier segment du robot exprimé au point de contact le plus proche de ob_1, projetée dans sa direction, V_7_C_ob = J_70_C_proj * q_dot       
	save_V_7_C_ob_diff_comp(V_7_C_ob_diff_comp); //C'est la vitesse du dernier segment du robot exprimé au point de contact le plus proche de ob_1, projetée dans sa direction mais calculée différemment pour vérifier le résultat précédent
						     //V_7_C_ob_diff_comp = project(V_7_C, dist), avec : V_7_C = J_70_C * q_dot

	//E_7_C_ob = sgn_V_7_C_ob * 0.5 * m_eq_7_j * V_7_C_ob * V_7_C_ob;
	E_7_C_ob = sgn_V_7_C_ob * 0.5 * m_eq_7_j * V_7_C_ob * V_7_C_ob;
	save_E_7_C_ob(E_7_C_ob);
	E_7_C_ob_diff_comp = sgn_V_7_C_ob_diff_comp * 0.5 * m_eq_7_j * V_7_C_ob_diff_comp * V_7_C_ob_diff_comp;
	save_E_7_C_ob_diff_comp(E_7_C_ob_diff_comp);

	save_sgn_V_7_C_ob(0.1 * sgn_V_7_C_ob);
	save_sgn_V_7_C_ob_diff_comp(0.1 * sgn_V_7_C_ob_diff_comp);

        double angle_V_7_to_nrst_dist_ob = compute_angle(V_7, nr_pt_07_ob1_ai[0].first, nr_pt_07_ob1_aj[0].first); 
	save_angle_V_7_to_nrst_dist_ob((180*angle_V_7_to_nrst_dist_ob)/PI);

	double norm_axis_of_rot_angle_7 = sqrt(pow(axis_of_rot_angle_7_normalized[0],2)  + pow(axis_of_rot_angle_7_normalized[1],2) + pow(axis_of_rot_angle_7_normalized[2],2));
        save_norm_axis_of_rot_angle_7(norm_axis_of_rot_angle_7);
///////////////////////////////////////////////////////// save DATA ////////////////////////////////////////////////////////////


/*
       q_dotdot_bounds_max_optimized <<  300,  300,  300,  300,  300,  300,  300;
       q_dotdot_bounds_min_optimized << -300, -300, -300, -300, -300, -300, -300;
*/
 

       q_k2      = q + (q_dot*dt);   //Position articulaire au pas de temps suivant
       q_ddot_k2 = q_ddot + (q_dddot*dt); 
       q_des     << nxt_step_des_x, 0.7, 0.35, 2, -0.59, 0.5, 1.01;

tau_final = optimize_QP(J_70_l, 
			J_70_dot_l,
			J_70_l_proj_Xerr,
		        J_70_l_proj_x_axis,
		        J_70_l_proj_y_axis,		                    
		        J_70_l_proj_z_axis,
			J_70_dot_l_proj_Xerr,
	                J_70_dot_l_proj_x_axis,			                
			J_70_dot_l_proj_y_axis,			                
			J_70_dot_l_proj_z_axis,	
                        M,
                        M_inv, 
			b,
                        Jdot_qdot_r_77,
			Jdot_qdot_r_70,
			Jdot_qdot_l,
			Jdot_qdot,
			X_err,
			V_err,
			X_err_orient, 
			V_err_angle_prj,
			V_7,
                        Acc_posi_70,
                        V_7_posi,
			V_77,
			V_7_des,
			Acc_7_des,
			Acc_7_orient_des,
                        kp,
			kd, 
		        d_safe,
			d_max, 
			E_safe,
                        Ec_max_7,
			J_70,
		      	J_70_C_proj,
                        dt,			  
                        m_eq_7_j,
                        m_eq_7_j_Xerr,
			m_eq_7_j_x_axis,			                
			m_eq_7_j_y_axis,	
			m_eq_7_j_z_axis,
			q_dotdot_bounds,
			q_dotdot_bounds_max,
		        q_dotdot_bounds_min,
			q_dotdot_bounds_max_comp,
		        q_dotdot_bounds_min_comp,
			dist_07_nrst_ob,
			gravity_terms,
			J_77_r,
			Acc_7_orient,
			Acc_7, 
			V_7_posi_proj, 
			H_disp_70, 
			J_70_r, 
			nxt_step_des_Jerk_7_x, 
			Jerk_x_curr, 
                        q,
			q_dot,
			q_ddot, 
			q_dddot, 
			q_ddddot,
       			q_bounds_min,
       			q_bounds_max,
       			q_dot_bounds_min,
       			q_dot_bounds_max,
		        q_dddot_bounds_min, 
			q_dddot_bounds_max,
                        q_dotdot_bounds_min_optimized,
                        q_dotdot_bounds_max_optimized, 
		        tau_min,
			tau_max, 
			q_k2, 
			q_ddot_k2,
			q_dddot_k2,
			q_ddddot_k2,
			q_dotdot_bounds_max_prime_forwrd_backwrd, 
			q_dotdot_bounds_min_prime_forwrd_backwrd,
			time_in_second,
			time_in_micsecond, 
			q_des_posture, 
                        q_des); 


for(int i = 0; i<7; i++){
tau(i) = tau_final(i);
}

//Pour la tache de posture dans le kernel de la Jacobienne
  //Kp_kernel = 10;
  //tau = tau +  ((I - (J_70.transpose() * J_70_plus.transpose())) * (Kp_kernel * (q_des_posture - q) - (2*sqrt(Kp_kernel)*q_dot)));		

//tau += dynModel->getGravityTerms();        //Les termes de componsation de gravité sont rajoutés ici
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////Ecrire le controleur ici///////////////////////////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
out_tau.write(tau);
}
}








/////////////////////////////////////////////////////////////////////////////////////////
// OPERATIONS
/////////////////////////////////////////////////////////////////////////////////////////

void XDE_SimpleController::setDynModelPointerStr(const std::string& strPtr)
{
    long long dyn_ptr = atoll(strPtr.c_str());
	std::cout << "string is: "<<strPtr<<"\n";
	std::cout <<"pointer is: "<<dyn_ptr<<"\n";
    dynModel = reinterpret_cast<xde::gvm::extra::DynamicModel*>(dyn_ptr);
	std::cout << dynModel->getJointPositions() << std::endl ;
}

//Importer l'agent physique 
void XDE_SimpleController::loadAgent(std::string name){	
	OCL::DeploymentComponent deploy;
	bool loaded = deploy.import(name);
	if(loaded == true){
		std::cout << "loaded" << loaded << std::endl;
	}
}







