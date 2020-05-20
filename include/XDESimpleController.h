#ifndef __XDE_SIMPLE_CONTROLLER__H__
#define __XDE_SIMPLE_CONTROLLER__H__

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Lgsm>
#include <rtt/os/main.h>
#include <rtt/Logger.hpp>
#include <rtt/TaskContext.hpp>
//#include <boost/chrono.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
#include </home/anis/libs/boost_1_56_0/boost/chrono/include.hpp>
#include </home/anis/libs/boost_1_56_0/boost/date_time/posix_time/posix_time.hpp>
//#include <kukakdl/kukakdl.hpp>
#include <rtt/Property.hpp>
#include <rtt/Port.hpp>
#include <xdecore/gvm.h>
#include <xdecore/gvm/DynamicModel.h>
#include "Compute_distance.h"
#include "Compute_energy.h"
#include "Compute_prj_velocity.h"
#include "Compute_vectors.h"
#include "QP.h"



class XDE_SimpleController: public RTT::TaskContext{
/*
        public : KukaKDL model;
                 KDL::JntArray KDL_NL_terms;
                 KDL::JntArray KDL_GRV_terms;
*/
	public:
		XDE_SimpleController(const std::string& name);
		~XDE_SimpleController();

		bool startHook();
		void stopHook();
		bool configureHook();
		void updateHook();
		void setDynModelPointerStr(const std::string& strPtr);
		void loadAgent(std::string name);



                //KDL::Frame H_7_KDL_Frame;		    //Position et orientation de l'effecteur /////Déclarée et initialisée dans le .cpp
		Eigen::Displacementd H_7;		    //Position et orientation de l'effecteur
		Eigen::Displacementd H_6;		 	
		Eigen::Displacementd H_5;			
		Eigen::Displacementd H_4;			
		Eigen::Displacementd H_3;			
		Eigen::Displacementd H_2;	
		Eigen::Displacementd init_H_disp_70;	
                Eigen::Displacementd H_disp_7_to_des_rot;	
                Eigen::Displacementd H_disp_7_to_init_rot;
                Eigen::Displacementd H_disp_des_rot;

                Eigen::Displacementd::Rotation3D nxt_step_des_quat;         //Quaternions désiré exprimés par rapport au reper monde
                Eigen::Displacementd::Rotation3D init_H_quat_70;            //Eigen::Displacementd::Rotation3D est une structure contenant seulement des quaternions
                Eigen::Displacementd::Rotation3D target_H_quat_70;
                Eigen::Displacementd::Rotation3D H_quat_7_to_des_rot;
                Eigen::Displacementd::Rotation3D H_orient_7_to_init_rot; 
		Eigen::Displacementd::Rotation3D H_orient_70;

                Eigen::Displacementd::Rotation3D quat_curr_0;               //Quaternions courants exprimés par rapport à l'orientation initiale

                
                double norm_V_7;
                double V_7_x;
                double V_7_y;
                double V_7_z;
                double norm_V_7_ob;
		double nxt_step_des_x;           //Used to compute the error between the real position and desired position of the next step
		double nxt_step_des_y;
		double nxt_step_des_z;
		double nxt_step_des_angle;
		double nxt_step_des_angle_prev;
		double Posi_x_curr;		//Current position of the end effector
		double Posi_y_curr;
		double Posi_z_curr;
		double Posi_x_curr_prev;		//Previous current position of the end effector
		double Posi_y_curr_prev;
		double Posi_z_curr_prev;
		double Posi_x_curr_1;		//Current position of the end effector
		double Posi_y_curr_1;
		double Posi_z_curr_1;
		double V_x_curr_1;
		double V_y_curr_1;
		double V_z_curr_1;
		double Acc_x_curr_1;
		double Acc_y_curr_1;
		double Acc_z_curr_1;
		double Jerk_x_curr_1;
		double Jerk_y_curr_1;
		double Jerk_z_curr_1;
		double prev_posi_x;	
		double prev_posi_y;
		double prev_posi_z;
		double init_posi_x;		//Initial position of the end effector --> This value can be change when the trajectory generator is updated
		double init_posi_y;
		double init_posi_z;
		double init_orient_alpha;
		double init_orient_beta;	
		double init_orient_gamma;
		double init_rot_angle;
                double theta;
		double halfTheta;
		double cosHalfTheta;


        	double X_err_x;
		double X_err_y;
		double X_err_z;
		double X_err_orient_0;
		double X_err_orient_1;
		double X_err_orient_2;
		double norme_X_err;
		double norme_X_err_orient;
        	double V_err_x;
		double V_err_y;
		double V_err_z;
		double V_err_angle_prj_0;
		double V_err_angle_prj_1;
		double V_err_angle_prj_2;
		double norme_V_err;
		double norme_V_err_angle_prj;
		double Err_interpolation_aggle_deg; //Err entre l'angle d'interpolation désiré et l'angle acturel en °
		double norme_angle_curr_rot_prj;
		double norme_angle_7_to_des_rot_prj;
		double norme_V_7_orient;
		double norme_V_7_orient_des;
		double norme_Acc_7_orient;
		double norme_Acc_7_orient_des;


		double prev_init_posi_x;	//Previous initial position for the interpolation
		double prev_init_posi_y;
		double prev_init_posi_z;

		double nxt_step_des_V_7_x;
		double nxt_step_des_V_7_y;
		double nxt_step_des_V_7_z;
		double nxt_step_des_V_7_alpha;
		double nxt_step_des_V_7_beta;
		double nxt_step_des_V_7_gamma;
		double nxt_step_des_V_7_angle;
		double nxt_step_des_Acc_7_x;
		double nxt_step_des_Acc_7_y;
		double nxt_step_des_Acc_7_z;
		double nxt_step_des_Acc_7_alpha;
		double nxt_step_des_Acc_7_beta;
		double nxt_step_des_Acc_7_gamma;
		double nxt_step_des_Acc_7_angle;
		double nxt_step_des_Jerk_7_x;
		double nxt_step_des_Jerk_7_y;
		double nxt_step_des_Jerk_7_z;
		double nxt_step_des_Jerk_7_alpha;
		double nxt_step_des_Jerk_7_beta;
		double nxt_step_des_Jerk_7_gamma;
		double nxt_step_des_Jerk_7_angle;
		double target_posi_x;		//Target position of the end effector 
		double target_posi_y;
		double target_posi_z;
		double target_orient_alpha; 
		double target_orient_beta; 
		double target_orient_gamma; 
		double target_rot_angle; 
		double s_t2;
		double s; 
		double s_x; 
		double s_y; 
		double s_z; 
		double s_t2_2; 
		double s_t2_3; 
		double s_t2_4; 
        	double s_dot_t2; 
        	double s_dot; 
        	double s_dot_x; 
        	double s_dot_y; 
        	double s_dot_z; 
        	double s_dot_t2_2; 
        	double s_dot_t2_3; 
        	double s_dot_t2_4; 
	 	double s_dot_dot_t2; 
	 	double s_dot_dot; 
	 	double s_dot_dot_x; 
	 	double s_dot_dot_y; 
	 	double s_dot_dot_z; 
	 	double s_dot_dot_t2_2; 
	 	double s_dot_dot_t2_3; 
	 	double s_dot_dot_t2_4;
        	double s_dot_dot_dot_t2;
        	double s_dot_dot_dot;
        	double s_dot_dot_dot_x;
        	double s_dot_dot_dot_y;
        	double s_dot_dot_dot_z;
        	double s_dot_dot_dot_t2_2;
        	double s_dot_dot_dot_t2_3;
        	double s_dot_dot_dot_t2_4;
        	double s_dot_x_prev;
        	double s_dot_y_prev;
        	double s_dot_z_prev;
        	double s_dot_dot_x_prev;
        	double s_dot_dot_y_prev;
        	double s_dot_dot_z_prev;
		double s_dot_dot_dot_x_prev;
        	double s_dot_dot_dot_y_prev;
        	double s_dot_dot_dot_z_prev;
		double s_x_init; 
		double s_y_init; 
		double s_z_init; 
        	double s_dot_x_init; 
        	double s_dot_y_init; 
        	double s_dot_z_init; 
	 	double s_dot_dot_x_init; 
	 	double s_dot_dot_y_init; 
	 	double s_dot_dot_z_init; 
        	double s_dot_dot_dot_x_init;
        	double s_dot_dot_dot_y_init;
        	double s_dot_dot_dot_z_init;


		double V_7_x_1_I;
       	        double V_7_x_2_I;  //Vitesse initiale selon x pour le deuxième segment de la trajectoire, la trajectoire de pick&place est constituée de 4 segments       
		double V_7_x_3_I;
		double V_7_x_4_I;

       	        double V_7_x_1_F;
       	        double V_7_x_2_F;  //Vitesse finale selon x pour le deuxième segment de la trajectoire, la trajectoire de pick&place est constituée de 4 segments 
       	        double V_7_x_3_F;
       	        double V_7_x_4_F;  

		double circle_traj_x;             //Coordinates of the circle points
		double circle_traj_y;
		double circle_traj_z;

		double start_x;
		double start_y;
		double start_z;

		double X_err_endeff_circle;      //direct distance between the end effector and the point that we were aiming on the circular path
		double traj_step_size;           //Le pas d'avance sur la trajectoire
		int nbr_unit_vect_to_X_des;      //Nombre d'avance avec le vecteur unitaire pour arriver sur un point voulu du cercle 
		int half_nbr_unit_vect_to_X_des;  


		Eigen::Vector3d Vect_dist_nrst_ob_07;   //Vector representing the distance to the nearest obstacle to segment 7
		Eigen::Vector3d Vect_dist_nrst_ob_06;   
		Eigen::Vector3d Vect_dist_nrst_ob_05;   
		Eigen::Vector3d Vect_dist_nrst_ob_04;   
		Eigen::Vector3d Vect_dist_nrst_ob_03;   
		Eigen::Vector3d Vect_dist_nrst_ob_02;  

		Eigen::Displacementd C_pt_seg_7;    	//Piont de contact de seg 7 le plus proche de ob_1
		Eigen::Displacementd C_pt_seg_6;
		Eigen::Displacementd C_pt_seg_5;
		Eigen::Displacementd C_pt_seg_4;
		Eigen::Displacementd C_pt_seg_3;
		Eigen::Displacementd C_pt_seg_2;

		Eigen::Displacementd C_pt_ob1_7;	//Point de contact sur ob_1 le plus proche de seg 7 
		Eigen::Displacementd C_pt_ob1_6;
		Eigen::Displacementd C_pt_ob1_5;
		Eigen::Displacementd C_pt_ob1_4;
		Eigen::Displacementd C_pt_ob1_3;
		Eigen::Displacementd C_pt_ob1_2;

		Eigen::Displacementd C_pt_sph_7;	//Point de contact sur sph le plus proche de seg 7 
		Eigen::Displacementd C_pt_sph_6;
		Eigen::Displacementd C_pt_sph_5;
		Eigen::Displacementd C_pt_sph_4;
		Eigen::Displacementd C_pt_sph_3;
		Eigen::Displacementd C_pt_sph_2;


		Eigen::Vector3d n_7; 			//Vector normal to the nearest point of seg 7 to the considered obstacle 
		Eigen::Vector3d n_7_normalized;
		Eigen::Vector3d n_Xerr;
		Eigen::Vector3d n_Xerr_normalized;
		Eigen::Vector3d n_6;
		Eigen::Vector3d n_5;
		Eigen::Vector3d n_4;
		Eigen::Vector3d n_3;
		Eigen::Vector3d n_2;
		Eigen::Vector3d disc_traj_unit_vector;  //Discretized trajectory (straight line) unit vector --> For online trajectory generation


		double angle_nrst_dist_vect_7;		//Angle entre le vecteur de la distance la plus courte entre le point du seg 7 concerné et l'axe x du repère world dans lequel on a la jacobienne exprimée
		double angle_nrst_dist_vect_6;
		double angle_nrst_dist_vect_5;
		double angle_nrst_dist_vect_4;
		double angle_nrst_dist_vect_3;
		double angle_nrst_dist_vect_2;

		Eigen::Vector3d axis_of_rot_angle_7;    //Axe de rotation transformant x_world en n_7
		Eigen::Vector3d axis_of_rot_angle_7_normalized;
		Eigen::Vector3d axis_of_rot_angle_6;
		Eigen::Vector3d axis_of_rot_angle_5;
		Eigen::Vector3d axis_of_rot_angle_4;
		Eigen::Vector3d axis_of_rot_angle_3;
		Eigen::Vector3d axis_of_rot_angle_2;
		Eigen::Vector3d axis_7_to_des_rot;
                Eigen::Vector3d axis_curr_rot;

		Eigen::Twistd V_7; 			//Vitesse de l'effecteur
		Eigen::Twistd V_77;                     //Vitesse de l'effecteur dans le repère de l'effecteur 
		Eigen::Twistd get_V_77; 		//C'est aussi la vitesse de l'effecteur mais directement obtenue depuis la physique, elle est exprimé dans le repère du segment (comme J_77)
		Eigen::Twistd get_V_7; 			///C'est aussi la vitesse de l'effecteur mais directement obtenue depuis la physique, elle est exprimé dans le repère world
		Eigen::Twistd V_7_C;                    //Vitesse au point de collision considéré
		Eigen::Matrix<double, 6, 1> V_7_matrix;	
		Eigen::Twistd V_6; 		
		Eigen::Twistd V_5; 		
		Eigen::Twistd V_4; 		
		Eigen::Twistd V_3; 		
		Eigen::Twistd V_2; 	

		Eigen::Twistd Col_1_J_70; 
		Eigen::Twistd Col_2_J_70; 
		Eigen::Twistd Col_3_J_70; 
		Eigen::Twistd Col_4_J_70; 
		Eigen::Twistd Col_5_J_70; 
		Eigen::Twistd Col_6_J_70; 
		Eigen::Twistd Col_7_J_70; 

		Eigen::Twistd Col_1_J_70_C; 
		Eigen::Twistd Col_2_J_70_C; 
		Eigen::Twistd Col_3_J_70_C; 
		Eigen::Twistd Col_4_J_70_C; 
		Eigen::Twistd Col_5_J_70_C; 
		Eigen::Twistd Col_6_J_70_C; 
		Eigen::Twistd Col_7_J_70_C; 


                Eigen::Twistd JdotQdot_77;
                Eigen::Twistd JdotQdot_70;

		Eigen::Twistd V_7_k2; 			//Vitesse de l'effecteur à l'étape de temps suivante
		Eigen::Twistd V_6_k2; 		
		Eigen::Twistd V_5_k2; 		
		Eigen::Twistd V_4_k2; 		
		Eigen::Twistd V_3_k2; 		
		Eigen::Twistd V_2_k2; 	


		Eigen::Vector3d V_7_ob;			//Absolute velocity of the end effector in the direction of the nearest obstacle
		Eigen::Vector3d V_6_ob;	
		Eigen::Vector3d V_5_ob;	
		Eigen::Vector3d V_4_ob;	
		Eigen::Vector3d V_3_ob;	
		Eigen::Vector3d V_2_ob;		

		Eigen::Vector3d V_7_ob_k2;			//Vector of the projected velocity in the direction of the nearest obstacle in the next time step
		Eigen::Vector3d V_6_ob_k2;	
		Eigen::Vector3d V_5_ob_k2;	
		Eigen::Vector3d V_4_ob_k2;	
		Eigen::Vector3d V_3_ob_k2;	
		Eigen::Vector3d V_2_ob_k2;		

		double V_7_ob_sgn_norm;			//Projected velocity signed norm at the end effector point
		double V_6_ob_sgn_norm;	
		double V_5_ob_sgn_norm;	
		double V_4_ob_sgn_norm;	
		double V_3_ob_sgn_norm;	
		double V_2_ob_sgn_norm;		

		double E_7_C_ob;
		double E_7_C_ob_diff_comp;
		double V_7_C_ob;			        //Ceci est directement la vitesse au point de contact potentiel C dans la direction de l'obstacle 
		double V_7_C_ob_diff_comp;			//Projected velocity signed norm at the potential collision point 

		double V_7_ob_sgn_norm_k2;			//Projected velocity signed norm in the k2 time step
		double V_6_ob_sgn_norm_k2;	
		double V_5_ob_sgn_norm_k2;	
		double V_4_ob_sgn_norm_k2;	
		double V_3_ob_sgn_norm_k2;	
		double V_2_ob_sgn_norm_k2;			

		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_77;         //Jacobienne de l'effecteur dans le repère du dernier segment
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_66;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_55;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_44;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_33;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_22;    

		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Joint_Jac;    //Joint jacobian 

		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_70;         //Jacobienne de l'effecteur dans le repère de base
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_60;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_50;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_40;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_30;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_20;    

                Eigen::Matrix<double, 6, 7> J_70_previous;
                Eigen::Matrix<double, 6, 7> J_70_dot;                //Dérivée de la jacobienne

		Eigen::Matrix<double, 6, 7> J_70_C;         //Jacobienne ddu point de contact du segment 7 dans le repère world
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_60_C;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_50_C;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_40_C;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_30_C;    
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_20_C; 
	
		Eigen::Matrix<double, 6, 7> J_70_C_proj_full;	//Projected jacobian in the frame related to the nearest point to the obstacle 
		Eigen::Matrix<double, 6, 7> J_60_C_proj_full;
		Eigen::Matrix<double, 6, 7> J_50_C_proj_full;
		Eigen::Matrix<double, 6, 7> J_40_C_proj_full;
		Eigen::Matrix<double, 6, 7> J_30_C_proj_full;
		Eigen::Matrix<double, 6, 7> J_20_C_proj_full;

		Eigen::Matrix<double, 1, 7> J_70_C_proj;	//The first line of the projected jacobian (the one in the same direction as n_7)
		Eigen::Matrix<double, 1, 7> J_60_C_proj;
		Eigen::Matrix<double, 1, 7> J_50_C_proj;
		Eigen::Matrix<double, 1, 7> J_40_C_proj;
		Eigen::Matrix<double, 1, 7> J_30_C_proj;
		Eigen::Matrix<double, 1, 7> J_20_C_proj;

		Eigen::Matrix<double, 1, 7> J_70_l_proj_Xerr;	//Jacobienne au centre de l'effecteur projetée dans la direction de (Xdes - X)
                Eigen::Matrix<double, 1, 7> J_70_l_proj_x_axis;  //Jacobienne au centre de l'effecteur projetée dans la direction de x_world
                Eigen::Matrix<double, 1, 7> J_70_l_proj_y_axis;  //Jacobienne au centre de l'effecteur projetée dans la direction de y_world
                Eigen::Matrix<double, 1, 7> J_70_l_proj_z_axis;  //Jacobienne au centre de l'effecteur projetée dans la direction de z_world

		Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_Xerr;	//The first line of the projected derived jacobian (the one in the same direction as n_7)
                Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_x_axis;
                Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_y_axis;        
                Eigen::Matrix<double, 1, 7> J_70_dot_l_proj_z_axis;   

      	        Eigen::Matrix<double, 7, 6> M_inv_J_70_transp;
      	        Eigen::Matrix<double, 6, 7> J_70_M_inv;
      	        Eigen::Matrix<double, 6, 6> J_70_M_inv_J_70_transp;
      	        Eigen::Matrix<double, 6, 6> J_70_M_inv_J_70_transp_inv;


		Eigen::Matrix<double, 3, 7> J_77_r;         //Partie de J_77 responsable des mouvements rotationels de l'effecteur  exprimée dans le repère de l'effecteur     
                Eigen::Matrix<double, 3, 7> J_70_r;

		Eigen::Matrix<double, 3, 7> J_70_l;        //Partie de J_70 responsable des mouvements linéaires de l'effecteur avec J_70(JAi_7 JLi_7).transpose
		Eigen::Matrix<double, 3, 7> J_60_l;
		Eigen::Matrix<double, 3, 7> J_50_l;
		Eigen::Matrix<double, 3, 7> J_40_l;
		Eigen::Matrix<double, 3, 7> J_30_l;
		Eigen::Matrix<double, 3, 7> J_20_l;

                Eigen::Matrix<double, 7, 6> J_70_plus;

		Eigen::Matrix<double, 3, 7> J_70_dot_l;        //Partie linéaire de la dérivée de la Jacobienne

		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_70_t;        //Jacobienne transposée de l'effecteur 
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_60_t; 
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_50_t; 
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_40_t; 
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_30_t; 
		Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> J_20_t; 
		Eigen::Matrix<double, 6, 1> Jdot_qdot_eff_frame;
		Eigen::Matrix<double, 3, 1> Jdot_qdot_r_77;                    //Exprimé dans le repère de l'effecteur 
		Eigen::Matrix<double, 3, 1> Jdot_qdot_r_70;
		Eigen::Matrix<double, 6, 1> Jdot_qdot;				     //Pour calculer l'accélération de l'effecteur 
		Eigen::Matrix<double, 3, 1> Jdot_qdot_l;              		    //Même chose qu'en haut sauf qu'elle est responsable des mouvements linéaires			

		Eigen::Displacementd X; 			 //Position cartésienne de l'effecteur
		Eigen::VectorXd Joints_state;
		Eigen::VectorXd a_i_1;				//Paramètres d'interpolation du 1er segment de la trajectoire
		Eigen::VectorXd a_i_x;			//Paramètres d'interpolation du 1er segment de la trajectoire pour le mvt selon x
		Eigen::VectorXd a_i_y;			//Paramètres d'interpolation du 1er segment de la trajectoire pour le mvt selon y
		Eigen::VectorXd a_i_z;			//Paramètres d'interpolation du 1er segment de la trajectoire pour le mvt selon z
		Eigen::VectorXd a_i_angle;			//Paramètres d'interpolation pour le mvt de rotation de l'effecteur
		Eigen::VectorXd a_i_alpha;
		Eigen::VectorXd a_i_beta;
		Eigen::VectorXd a_i_gamma;
		Eigen::VectorXd a_i_2;				//Paramètres d'interpolation du 2ème segment de la trajectoire
		Eigen::VectorXd a_i_3;				//Paramètres d'interpolation du 3ème segment de la trajectoire
		Eigen::VectorXd a_i_4;				//Paramètres d'interpolation du 4ème segment de la trajectoire


                double nrmlize_coeff_s_dot_x; 
                double nrmlize_coeff_s_dot_y; 
                double nrmlize_coeff_s_dot_z; 
                double nrmlize_coeff_s_dot_dot_x;   
                double nrmlize_coeff_s_dot_dot_y;   
                double nrmlize_coeff_s_dot_dot_z;   
               

		double d_max;
		double F_max; 		//Force équivalente de freinage
		double F_max_2; 		
		double F_max_3; 		
		double F_max_4; 		
		double F_max_5; 		
		double F_max_6; 		
		double F_max_7; 		 		
 

                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M;  		//Matrice des effets d'inertie 
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J7_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J6_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J5_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J4_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J3_inv;  
                Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> M_cart_J2_inv;  

               Eigen::Matrix<double, 3, 3> M_cart_7_inv;        //Inertie équivalente inversée pour les mouvements linéaires du segment 7 : 1/mij
               Eigen::Matrix<double, 3, 3> M_cart_6_inv;
               Eigen::Matrix<double, 3, 3> M_cart_5_inv;
               Eigen::Matrix<double, 3, 3> M_cart_4_inv;
               Eigen::Matrix<double, 3, 3> M_cart_3_inv;
               Eigen::Matrix<double, 3, 3> M_cart_2_inv;
	       
	       double m_eq_7_j; 			        //Inertie équivalente du segment 7 dans la direction de l'obstacle j
	       double m_eq_6_j;
	       double m_eq_5_j;
	       double m_eq_4_j;
	       double m_eq_3_j;
	       double m_eq_2_j;

	       double m_eq_7_j_Xerr; 
	       double m_eq_7_j_x_axis;
	       double m_eq_7_j_y_axis;
	       double m_eq_7_j_z_axis;

	       double m_eq_7_inter;				//Juste une valeur intermédiaire pour calculer m_eq_7
	       double m_eq_7;					//This is the full mass

	       double m_eq_7_j_inter; 			       
	       double m_eq_6_j_inter;
	       double m_eq_5_j_inter;
	       double m_eq_4_j_inter;
	       double m_eq_3_j_inter;
	       double m_eq_2_j_inter;

	       double m_eq_7_j_inter_Xerr;
	       double m_eq_7_j_inter_x_axis;
	       double m_eq_7_j_inter_y_axis;
	       double m_eq_7_j_inter_z_axis;
		
		Eigen::Matrix<double, 7, 1> b;                 //Matrice des effets non lineaires (Centrifuge et Coriolis)
		Eigen::Matrix<double, 7, 1> gravity_terms;
	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds;   //bounds used in the QP solver. Just to respect position bounds.
	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max;
	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min;

	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_trq_derived; //Articular acceleration bound : q_dotdot_bounds_max_trq_derived = M_inv*(tau_max-b)
	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_trq_derived; 

	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_max_comp; //Celas sont calculés avec la compatibilité des contraintes
	        Eigen::Matrix<double, 7, 1> q_dotdot_bounds_min_comp;

	        Eigen::Matrix<double, 7, 1> tau_min;
	        Eigen::Matrix<double, 7, 1> tau_max; 

		double E_7;				       // Kinematics energy in the direction of the considered obstacle
		double E_6;
		double E_5;
		double E_4;
		double E_3;
		double E_2;

		double full_E_7;			       //The full Kinematics energy

		double E_7_k2; 				      //This is the energy in the future so V_k2 in g(x) is related to the variables tau
		double E_6_k2;
		double E_5_k2;
		double E_4_k2;
		double E_3_k2;
		double E_2_k2;


		double Ec_max_7;
		double Ec_max_6;
		double Ec_max_5;
		double Ec_max_4;
		double Ec_max_3;
		double Ec_max_2;

                double dist_07_gr;
                double dist_06_gr;
                double dist_05_gr;
                double dist_04_gr;
                double dist_03_gr;
                double dist_02_gr;

                double dist_07_ob1;
                double dist_06_ob1;
                double dist_05_ob1;
                double dist_04_ob1;
                double dist_03_ob1;
                double dist_02_ob1;

                double dist_07_ob2;
                double dist_06_ob2;
                double dist_05_ob2;
                double dist_04_ob2;
                double dist_03_ob2;
                double dist_02_ob2;

                double dist_07_sph;
                double dist_06_sph;
                double dist_05_sph;
                double dist_04_sph;
                double dist_03_sph;
                double dist_02_sph;

                double dist_07_nrst_ob;     //The distance to the nearest obstacle is the minimum of the distances above
                double dist_06_nrst_ob;
                double dist_05_nrst_ob;
                double dist_04_nrst_ob;
                double dist_03_nrst_ob;
                double dist_02_nrst_ob;
		
		char* id_nrst_ob_7;	    //id of the nearest obstacle to seg_7
		char* id_nrst_ob_6;	    
		char* id_nrst_ob_5;	    
		char* id_nrst_ob_4;	    
		char* id_nrst_ob_3;	    
		char* id_nrst_ob_2;
/*	
//QP optimization data
		double f;
		Eigen::Matrix<double, 7, 1> grad_f_intermediaire; 
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau1;              //d tau / d tau1      :  tau = [tau1 ....tau7]
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau2;  
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau3;  
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau4;  
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau5;  
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau6;  
		Eigen::Matrix<double, 7, 1> grad_vect_tau_tau7;  
		
		//Hessian of the lagrangian components			
		double d2f_dtau1_2;  			//d²f(x)/dtau1²				
		double d2f_dtau1_dtau2;			//d²f(x)/dtau1 * dtau2 
		double d2f_dtau1_dtau3;			//d²f(x)/dtau1 * dtau3 
		double d2f_dtau1_dtau4;			//d²f(x)/dtau1 * dtau4 
		double d2f_dtau1_dtau5;			//d²f(x)/dtau1 * dtau5
		double d2f_dtau1_dtau6;			//d²f(x)/dtau1 * dtau6 
		double d2f_dtau1_dtau7;			//d²f(x)/dtau1 * dtau7 
                   
		double d2f_dtau2_2;			//d²f(x)/dtau2² 
		double d2f_dtau2_dtau3;			//d²f(x)/dtau2 * dtau3
		double d2f_dtau2_dtau4;			//d²f(x)/dtau2 * dtau4 
		double d2f_dtau2_dtau5;			//d²f(x)/dtau2 * dtau5 
		double d2f_dtau2_dtau6;			//d²f(x)/dtau2 * dtau6 
		double d2f_dtau2_dtau7;			//d²f(x)/dtau2 * dtau7  
                                  
		double d2f_dtau3_2;			//d²f(x)/dtau3² 
		double d2f_dtau3_dtau4;			//d²f(x)/dtau3 * dtau4
		double d2f_dtau3_dtau5;			//d²f(x)/dtau3 * dtau5
		double d2f_dtau3_dtau6;			//d²f(x)/dtau3 * dtau6
		double d2f_dtau3_dtau7;			//d²f(x)/dtau3 * dtau7
                     
		double d2f_dtau4_2;			//d²f(x)/dtau4² 
		double d2f_dtau4_dtau5;			//d²f(x)/dtau4 * dtau5
		double d2f_dtau4_dtau6;			//d²f(x)/dtau4 * dtau6
		double d2f_dtau4_dtau7;			//d²f(x)/dtau4 * dtau7
                                     
		double d2f_dtau5_2;			//d²f(x)/dtau5²
		double d2f_dtau5_dtau6;			//d²f(x)/dtau5 * dtau6 
		double d2f_dtau5_dtau7;			//d²f(x)/dtau5 * dtau7 
         
		double d2f_dtau6_2;			//d²f(x)/dtau6²
		double d2f_dtau6_dtau7;			//d²f(x)/dtau6 * dtau7 

		double d2f_dtau7_2;			//d²f(x)/dtau6²


		double d2g0_dtau1_2;             //d²g[0]/dtau1² 
		double d2g0_dtau1_dtau2;         //d²g[0]/dtau1 * dtau2
		double d2g0_dtau1_dtau3;         //d²g[0]/dtau1 * dtau3
		double d2g0_dtau1_dtau4;         //d²g[0]/dtau1 * dtau3
		double d2g0_dtau1_dtau5;         //d²g[0]/dtau1 * dtau3
		double d2g0_dtau1_dtau6;         //d²g[0]/dtau1 * dtau3
		double d2g0_dtau1_dtau7;         //d²g[0]/dtau1 * dtau3
		double d2g0_dtau2_2;	     	 //d²g[0]/dtau2² 
		double d2g0_dtau2_dtau3;	 //d²g[0]/dtau2 * dtau3 
		double d2g0_dtau2_dtau4;	 //d²g[0]/dtau2 * dtau4 
		double d2g0_dtau2_dtau5;	 //d²g[0]/dtau2 * dtau5 
		double d2g0_dtau2_dtau6;	 //d²g[0]/dtau2 * dtau6 
		double d2g0_dtau2_dtau7;	 //d²g[0]/dtau2 * dtau7 
		double d2g0_dtau3_2;		 //d²g[0]/dtau3²
		double d2g0_dtau3_dtau4;	 //d²g[0]/dtau3 * dtau4 
		double d2g0_dtau3_dtau5;	 //d²g[0]/dtau3 * dtau4 
		double d2g0_dtau3_dtau6;	 //d²g[0]/dtau3 * dtau4 
		double d2g0_dtau3_dtau7;	 //d²g[0]/dtau3 * dtau4
		double d2g0_dtau4_2;		 //d²g[0]/dtau4²
		double d2g0_dtau4_dtau5;	 //d²g[0]/dtau4 * dtau5 
		double d2g0_dtau4_dtau6;	 //d²g[0]/dtau4 * dtau6 
		double d2g0_dtau4_dtau7;	 //d²g[0]/dtau4 * dtau7  
		double d2g0_dtau5_2;		 //d²g[0]/dtau5²
		double d2g0_dtau5_dtau6;	 //d²g[0]/dtau5 * dtau6
		double d2g0_dtau5_dtau7;	 //d²g[0]/dtau5 * dtau7
		double d2g0_dtau6_2;		 //d²g[0]/dtau6²
		double d2g0_dtau6_dtau7;	 //d²g[0]/dtau6 * dtau7
		double d2g0_dtau7_2;		 //d²g[0]/dtau7²

		double d2g1_dtau1_2;             //d²g[1]/dtau1² 
		double d2g1_dtau1_dtau2;         //d²g[1]/dtau1 * dtau2
		double d2g1_dtau1_dtau3;         //d²g[1]/dtau1 * dtau3
		double d2g1_dtau1_dtau4;         //d²g[1]/dtau1 * dtau3
		double d2g1_dtau1_dtau5;         //d²g[1]/dtau1 * dtau3
		double d2g1_dtau1_dtau6;         //d²g[1]/dtau1 * dtau3
		double d2g1_dtau1_dtau7;         //d²g[1]/dtau1 * dtau3     
		double d2g1_dtau2_2;		 //d²g[1]/dtau2² 
		double d2g1_dtau2_dtau3;	 //d²g[1]/dtau2 * dtau3 
		double d2g1_dtau2_dtau4;	 //d²g[1]/dtau2 * dtau4 
		double d2g1_dtau2_dtau5;	 //d²g[1]/dtau2 * dtau5 
		double d2g1_dtau2_dtau6;	 //d²g[1]/dtau2 * dtau6 
		double d2g1_dtau2_dtau7;	 //d²g[1]/dtau2 * dtau7 
		double d2g1_dtau3_2;		 //d²g[1]/dtau3²
		double d2g1_dtau3_dtau4;	 //d²g[1]/dtau3 * dtau4 
		double d2g1_dtau3_dtau5;	 //d²g[1]/dtau3 * dtau4 
		double d2g1_dtau3_dtau6;	 //d²g[1]/dtau3 * dtau4 
		double d2g1_dtau3_dtau7;	 //d²g[1]/dtau3 * dtau4
		double d2g1_dtau4_2;     	 //d²g[1]/dtau4²
		double d2g1_dtau4_dtau5;	 //d²g[1]/dtau4 * dtau5 
		double d2g1_dtau4_dtau6;	 //d²g[1]/dtau4 * dtau6 
		double d2g1_dtau4_dtau7;	 //d²g[1]/dtau4 * dtau7
		double d2g1_dtau5_2;		 //d²g[1]/dtau5²
		double d2g1_dtau5_dtau6;	 //d²g[1]/dtau5 * dtau6
		double d2g1_dtau5_dtau7;	 //d²g[1]/dtau5 * dtau7
		double d2g1_dtau6_2;	 	 //d²g[1]/dtau6²
		double d2g1_dtau6_dtau7;	 //d²g[1]/dtau6 * dtau7
		double d2g1_dtau7_2;	         //d²g[1]/dtau7²

		double d2g2_dtau1_2;             //d²g[2]/dtau1² 
		double d2g2_dtau1_dtau2;         //d²g[2]/dtau1 * dtau2
		double d2g2_dtau1_dtau3;         //d²g[2]/dtau1 * dtau3
		double d2g2_dtau1_dtau4;         //d²g[2]/dtau1 * dtau3
		double d2g2_dtau1_dtau5;         //d²g[2]/dtau1 * dtau3
		double d2g2_dtau1_dtau6;         //d²g[2]/dtau1 * dtau3
		double d2g2_dtau1_dtau7;         //d²g[2]/dtau1 * dtau3   
		double d2g2_dtau2_2;	 	 //d²g[2]/dtau2² 
		double d2g2_dtau2_dtau3;	 //d²g[2]/dtau2 * dtau3 
		double d2g2_dtau2_dtau4;	 //d²g[2]/dtau2 * dtau4 
		double d2g2_dtau2_dtau5;	 //d²g[2]/dtau2 * dtau5 
		double d2g2_dtau2_dtau6;	 //d²g[2]/dtau2 * dtau6 
		double d2g2_dtau2_dtau7;	 //d²g[2]/dtau2 * dtau7 
		double d2g2_dtau3_2;		 //d²g[2]/dtau3²
		double d2g2_dtau3_dtau4;	 //d²g[2]/dtau3 * dtau4 
		double d2g2_dtau3_dtau5;	 //d²g[2]/dtau3 * dtau4 
		double d2g2_dtau3_dtau6;	 //d²g[2]/dtau3 * dtau4 
		double d2g2_dtau3_dtau7;	 //d²g[2]/dtau3 * dtau4
		double d2g2_dtau4_2;		 //d²g[2]/dtau4²
		double d2g2_dtau4_dtau5;	 //d²g[2]/dtau4 * dtau5 
		double d2g2_dtau4_dtau6;	 //d²g[2]/dtau4 * dtau6 
		double d2g2_dtau4_dtau7;	 //d²g[2]/dtau4 * dtau7                
		double d2g2_dtau5_2;		 //d²g[2]/dtau5²
		double d2g2_dtau5_dtau6;	 //d²g[2]/dtau5 * dtau6
		double d2g2_dtau5_dtau7;	 //d²g[2]/dtau5 * dtau7
		double d2g2_dtau6_2;	 	 //d²g[2]/dtau6²
		double d2g2_dtau6_dtau7;	 //d²g[2]/dtau6 * dtau7    
		double d2g2_dtau7_2;	 	 //d²g[2]/dtau7²

		double d2g3_dtau1_2;     	 //d²g[3]/dtau1² 
		double d2g3_dtau1_dtau2;         //d²g[3]/dtau1 * dtau2
		double d2g3_dtau1_dtau3;         //d²g[3]/dtau1 * dtau3
		double d2g3_dtau1_dtau4;         //d²g[3]/dtau1 * dtau3
		double d2g3_dtau1_dtau5;         //d²g[3]/dtau1 * dtau3
		double d2g3_dtau1_dtau6;         //d²g[3]/dtau1 * dtau3
		double d2g3_dtau1_dtau7;         //d²g[3]/dtau1 * dtau3           
		double d2g3_dtau2_2;	 	 //d²g[3]/dtau2² 
		double d2g3_dtau2_dtau3;	 //d²g[3]/dtau2 * dtau3 
		double d2g3_dtau2_dtau4;	 //d²g[3]/dtau2 * dtau4 
		double d2g3_dtau2_dtau5;	 //d²g[3]/dtau2 * dtau5 
		double d2g3_dtau2_dtau6;	 //d²g[3]/dtau2 * dtau6 
		double d2g3_dtau2_dtau7;	 //d²g[3]/dtau2 * dtau7 
		double d2g3_dtau3_2;		 //d²g[3]/dtau3²
		double d2g3_dtau3_dtau4;	 //d²g[3]/dtau3 * dtau4 
		double d2g3_dtau3_dtau5;	 //d²g[3]/dtau3 * dtau4 
		double d2g3_dtau3_dtau6;	 //d²g[3]/dtau3 * dtau4 
		double d2g3_dtau3_dtau7;	 //d²g[3]/dtau3 * dtau4    
		double d2g3_dtau4_2;		 //d²g[3]/dtau4²
		double d2g3_dtau4_dtau5;	 //d²g[3]/dtau4 * dtau5 
		double d2g3_dtau4_dtau6;	 //d²g[3]/dtau4 * dtau6 
		double d2g3_dtau4_dtau7;	 //d²g[3]/dtau4 * dtau7
		double d2g3_dtau5_2;		 //d²g[3]/dtau5²
		double d2g3_dtau5_dtau6;	 //d²g[3]/dtau5 * dtau6
		double d2g3_dtau5_dtau7;	 //d²g[3]/dtau5 * dtau7                   
		double d2g3_dtau6_2;		 //d²g[3]/dtau6²
		double d2g3_dtau6_dtau7;	 //d²g[3]/dtau6 * dtau7                 
		double d2g3_dtau7_2;	 	 //d²g[3]/dtau7²

		double d2g4_dtau1_2;     	 //d²g[4]/dtau1² 
		double d2g4_dtau1_dtau2;         //d²g[4]/dtau1 * dtau2
		double d2g4_dtau1_dtau3;         //d²g[4]/dtau1 * dtau3
		double d2g4_dtau1_dtau4;         //d²g[4]/dtau1 * dtau3
		double d2g4_dtau1_dtau5;         //d²g[4]/dtau1 * dtau3
		double d2g4_dtau1_dtau6;         //d²g[4]/dtau1 * dtau3
		double d2g4_dtau1_dtau7;         //d²g[4]/dtau1 * dtau3      
		double d2g4_dtau2_2;	 	 //d²g[4]/dtau2² 
		double d2g4_dtau2_dtau3;	 //d²g[4]/dtau2 * dtau3 
		double d2g4_dtau2_dtau4;	 //d²g[4]/dtau2 * dtau4 
		double d2g4_dtau2_dtau5;	 //d²g[4]/dtau2 * dtau5 
		double d2g4_dtau2_dtau6;	 //d²g[4]/dtau2 * dtau6 
		double d2g4_dtau2_dtau7;	 //d²g[4]/dtau2 * dtau7     
		double d2g4_dtau3_2;	 	 //d²g[4]/dtau3²
		double d2g4_dtau3_dtau4;	 //d²g[4]/dtau3 * dtau4 
		double d2g4_dtau3_dtau5;	 //d²g[4]/dtau3 * dtau4 
		double d2g4_dtau3_dtau6;	 //d²g[4]/dtau3 * dtau4 
		double d2g4_dtau3_dtau7;	 //d²g[4]/dtau3 * dtau4            
		double d2g4_dtau4_2;		 //d²g[4]/dtau4²
		double d2g4_dtau4_dtau5;	 //d²g[4]/dtau4 * dtau5 
		double d2g4_dtau4_dtau6;	 //d²g[4]/dtau4 * dtau6 
		double d2g4_dtau4_dtau7;	 //d²g[4]/dtau4 * dtau7  
		double d2g4_dtau5_2;	 	 //d²g[4]/dtau5²
		double d2g4_dtau5_dtau6;	 //d²g[4]/dtau5 * dtau6
		double d2g4_dtau5_dtau7;	 //d²g[4]/dtau5 * dtau7                          
		double d2g4_dtau6_2;		 //d²g[4]/dtau6²
		double d2g4_dtau6_dtau7;	 //d²g[4]/dtau6 * dtau7  
		double d2g4_dtau7_2;		 //d²g[4]/dtau7²

		double d2g5_dtau1_2;    	 //d²g[5]/dtau1² 
		double d2g5_dtau1_dtau2;    	 //d²g[5]/dtau1 * dtau2
		double d2g5_dtau1_dtau3;    	 //d²g[5]/dtau1 * dtau3
		double d2g5_dtau1_dtau4;   	 //d²g[5]/dtau1 * dtau3
		double d2g5_dtau1_dtau5;   	 //d²g[5]/dtau1 * dtau3
		double d2g5_dtau1_dtau6;   	 //d²g[5]/dtau1 * dtau3
		double d2g5_dtau1_dtau7;   	 //d²g[5]/dtau1 * dtau3
		double d2g5_dtau2_2;	 	 //d²g[5]/dtau2² 
		double d2g5_dtau2_dtau3;	 //d²g[5]/dtau2 * dtau3 
		double d2g5_dtau2_dtau4;	 //d²g[5]/dtau2 * dtau4 
		double d2g5_dtau2_dtau5;	 //d²g[5]/dtau2 * dtau5 
		double d2g5_dtau2_dtau6;	 //d²g[5]/dtau2 * dtau6 
		double d2g5_dtau2_dtau7;	 //d²g[5]/dtau2 * dtau7 
		double d2g5_dtau3_2;		 //d²g[5]/dtau3²
		double d2g5_dtau3_dtau4;	 //d²g[5]/dtau3 * dtau4 
		double d2g5_dtau3_dtau5;	 //d²g[5]/dtau3 * dtau4 
		double d2g5_dtau3_dtau6;	 //d²g[5]/dtau3 * dtau4 
		double d2g5_dtau3_dtau7;	 //d²g[5]/dtau3 * dtau4
		double d2g5_dtau4_2;		 //d²g[5]/dtau4²
		double d2g5_dtau4_dtau5;	 //d²g[5]/dtau4 * dtau5 
		double d2g5_dtau4_dtau6;	 //d²g[5]/dtau4 * dtau6 
		double d2g5_dtau4_dtau7;	 //d²g[5]/dtau4 * dtau7
		double d2g5_dtau5_2;	 	 //d²g[5]/dtau5²
		double d2g5_dtau5_dtau6;	 //d²g[5]/dtau5 * dtau6
		double d2g5_dtau5_dtau7;	 //d²g[5]/dtau5 * dtau7
		double d2g5_dtau6_2;	 	 //d²g[5]/dtau6²
		double d2g5_dtau6_dtau7;	 //d²g[5]/dtau6 * dtau7
		double d2g5_dtau7_2;		 //d²g[5]/dtau7²
*/
		int global;
		//KukaKDL model;
	private:
		RTT::InputPort< Eigen::VectorXd > in_q;
		RTT::InputPort< Eigen::VectorXd > in_qdot;
		RTT::InputPort< Eigen::Displacementd > in_d;
		RTT::InputPort< Eigen::Displacementd > in_displacementd_obst_1;
		RTT::InputPort< Eigen::Twistd > in_t;
		RTT::InputPort< double > in_clock;
		RTT::OutputPort< Eigen::VectorXd > out_tau;

		RTT::InputPort< double > in_kp;
		RTT::InputPort< double > in_kd;
		RTT::InputPort< double > in_d_safe;
		RTT::InputPort< double > in_d_max;
		RTT::InputPort< double > in_E_safe;

		RTT::InputPort< double > in_X_des_x;
		RTT::InputPort< double > in_X_des_y;
		RTT::InputPort< double > in_X_des_z;

		RTT::InputPort< double > in_tau_0_sensor;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





		RTT::InputPort< std::vector< std::pair<Eigen::Displacementd, std::string> > > in_nr_pt_07_ob1_ai; 
		RTT::InputPort< std::vector< std::pair<Eigen::Displacementd, std::string> > > in_nr_pt_07_ob1_aj;





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_gr_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_gr_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_gr_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_gr_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_gr_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_gr_aj; 



		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob1_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob1_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob1_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob1_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob1_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob1_aj; 



		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_ob2_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_ob2_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_ob2_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_ob2_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_ob2_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_ob2_aj; 



		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_07_sph_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_06_sph_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_05_sph_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_04_sph_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_03_sph_aj; 

		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_ai; 
		std::vector< std::pair<Eigen::Displacementd, std::string> > nr_pt_02_sph_aj; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		Eigen::VectorXd q;
		Eigen::VectorXd qdot;
		Eigen::Displacementd d;
		Eigen::Twistd t;
                Eigen::Displacementd displacementd_obst_1;
		double clock;
		double kp; //Coeffs du controleur
		double kd;
		double d_safe;
		double E_safe;
		
		double X_des_x;
		double X_des_y;
		double X_des_z;
		double tau_sensor_0;

		xde::gvm::extra::DynamicModel* dynModel;
		bool q_ok;
		bool qdot_ok;
		bool d_ok;
		bool t_ok;

                bool nr_pt_07_ob1_ai_ok;
                bool nr_pt_07_ob1_aj_ok;
                bool displacementd_obst_1_ok;
};

#include <rtt/Component.hpp>
ORO_CREATE_COMPONENT( XDE_SimpleController );

#endif


