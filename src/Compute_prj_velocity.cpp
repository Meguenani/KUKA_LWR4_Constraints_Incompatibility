#include <iostream>
#include <Eigen/Core>
#include <Eigen/Lgsm>
#include <stdio.h>      
#include <math.h>       
#include "Compute_prj_velocity.h"

//Compute signed norm of the projected velocity 
double compute_velocity_sgn_norm(char* nrst_ob_id, Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2, Eigen::Displacementd point_3, Eigen::Displacementd point_4, 
							   Eigen::Displacementd point_5, Eigen::Displacementd point_6, Eigen::Displacementd point_7, Eigen::Displacementd point_8){
	using namespace std;	
	double projected_velocity_sgn_norm = 0.0;
	Eigen::Vector3d projection_vector;
	char* gr =  "gr";
	char* ob1 = "ob1";
	char* ob2 = "ob2";
	char* sph = "sph";


if(strcmp(nrst_ob_id,gr)==0){
	projection_vector[0] =  point_1.getTranslation().x()-point_2.getTranslation().x();
	projection_vector[1] =  point_1.getTranslation().y()-point_2.getTranslation().y();
	projection_vector[2] =  point_1.getTranslation().z()-point_2.getTranslation().z();
	projected_velocity_sgn_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	}

else if(strcmp(nrst_ob_id,ob1)==0){
	projection_vector[0] =  point_3.getTranslation().x()-point_4.getTranslation().x();
	projection_vector[1] =  point_3.getTranslation().y()-point_4.getTranslation().y();
	projection_vector[2] =  point_3.getTranslation().z()-point_4.getTranslation().z();
	projected_velocity_sgn_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	}

else if(strcmp(nrst_ob_id,ob2)==0){
	projection_vector[0] =  point_5.getTranslation().x()-point_6.getTranslation().x();
	projection_vector[1] =  point_5.getTranslation().y()-point_6.getTranslation().y();
	projection_vector[2] =  point_5.getTranslation().z()-point_6.getTranslation().z();
	projected_velocity_sgn_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	}

else if(strcmp(nrst_ob_id,sph)==0){
	projection_vector[0] =  point_7.getTranslation().x()-point_8.getTranslation().x();
	projection_vector[1] =  point_7.getTranslation().y()-point_8.getTranslation().y();
	projection_vector[2] =  point_7.getTranslation().z()-point_8.getTranslation().z();
	projected_velocity_sgn_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	}

return projected_velocity_sgn_norm;
}







//Compute signed norm of the projected velocity 
double compute_velocity_sgn_norm_considered(Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2){
	using namespace std;	
	double projected_velocity_sgn_norm = 0.0;
	Eigen::Vector3d projection_vector;
	Eigen::Vector3d projection_vector_normalized;

	projection_vector[0] =  point_2.getTranslation().x()-point_1.getTranslation().x();
	projection_vector[1] =  point_2.getTranslation().y()-point_1.getTranslation().y();
	projection_vector[2] =  point_2.getTranslation().z()-point_1.getTranslation().z();
        projection_vector_normalized = projection_vector.normalized();
	projected_velocity_sgn_norm = (V[3]*projection_vector_normalized[0]) + (V[4]*projection_vector_normalized[1]) + (V[5]*projection_vector_normalized[2]);

//std::cout << " projected_velocity_sgn_norm " << projected_velocity_sgn_norm << std::endl;


return projected_velocity_sgn_norm;
}












//Compute vector of the projected velocity. The projected V on d : V_pr = (V.d/|d|²) * d 
Eigen::Vector3d compute_velocity_pr_vect(char* nrst_ob_id, Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2, Eigen::Displacementd point_3, Eigen::Displacementd point_4, 
							   Eigen::Displacementd point_5, Eigen::Displacementd point_6, Eigen::Displacementd point_7, Eigen::Displacementd point_8){
	using namespace std;	
	double projected_velocity_norm;
	double norm_divided;
	Eigen::Vector3d projected_velocity;
	Eigen::Vector3d projection_vector;
	char* gr =  "gr";
	char* ob1 = "ob1";
	char* ob2 = "ob2";
	char* sph = "sph";


if(strcmp(nrst_ob_id,gr)==0){
	projection_vector[0] =  point_1.getTranslation().x()-point_2.getTranslation().x();
	projection_vector[1] =  point_1.getTranslation().y()-point_2.getTranslation().y();
	projection_vector[2] =  point_1.getTranslation().z()-point_2.getTranslation().z();
	projected_velocity_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	norm_divided = projected_velocity_norm / (pow(projection_vector[0],2) + pow(projection_vector[1],2) + pow(projection_vector[2],2));
	projected_velocity[0] = norm_divided * projection_vector[0];
	projected_velocity[1] = norm_divided * projection_vector[1];
	projected_velocity[2] = norm_divided * projection_vector[2];
	}

else if(strcmp(nrst_ob_id,ob1)==0){
	projection_vector[0] =  point_3.getTranslation().x()-point_4.getTranslation().x();
	projection_vector[1] =  point_3.getTranslation().y()-point_4.getTranslation().y();
	projection_vector[2] =  point_3.getTranslation().z()-point_4.getTranslation().z();
	projected_velocity_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	norm_divided = projected_velocity_norm / (pow(projection_vector[0],2) + pow(projection_vector[1],2) + pow(projection_vector[2],2));
	projected_velocity[0] = norm_divided * projection_vector[0];
	projected_velocity[1] = norm_divided * projection_vector[1];
	projected_velocity[2] = norm_divided * projection_vector[2];
	}

else if(strcmp(nrst_ob_id,ob2)==0){
	projection_vector[0] =  point_5.getTranslation().x()-point_6.getTranslation().x();
	projection_vector[1] =  point_5.getTranslation().y()-point_6.getTranslation().y();
	projection_vector[2] =  point_5.getTranslation().z()-point_6.getTranslation().z();
	projected_velocity_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	norm_divided = projected_velocity_norm / (pow(projection_vector[0],2) + pow(projection_vector[1],2) + pow(projection_vector[2],2));
	projected_velocity[0] = norm_divided * projection_vector[0];
	projected_velocity[1] = norm_divided * projection_vector[1];
	projected_velocity[2] = norm_divided * projection_vector[2];
	}

else if(strcmp(nrst_ob_id,sph)==0){
	projection_vector[0] =  point_7.getTranslation().x()-point_8.getTranslation().x();
	projection_vector[1] =  point_7.getTranslation().y()-point_8.getTranslation().y();
	projection_vector[2] =  point_7.getTranslation().z()-point_8.getTranslation().z();
	projected_velocity_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	norm_divided = projected_velocity_norm / (pow(projection_vector[0],2) + pow(projection_vector[1],2) + pow(projection_vector[2],2));
	projected_velocity[0] = norm_divided * projection_vector[0];
	projected_velocity[1] = norm_divided * projection_vector[1];
	projected_velocity[2] = norm_divided * projection_vector[2];
	}



return projected_velocity;
}











Eigen::Vector3d compute_velocity_pr_vect_considered(Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2){     //Twistd en haut les valeurs angulaires et en bas les valeurs linéaires
	using namespace std;	
	double projected_velocity_norm;
	double norm_divided;
	Eigen::Vector3d projected_velocity;
	Eigen::Vector3d projection_vector;

	projection_vector[0] =  point_2.getTranslation().x()-point_1.getTranslation().x();
	projection_vector[1] =  point_2.getTranslation().y()-point_1.getTranslation().y();
	projection_vector[2] =  point_2.getTranslation().z()-point_1.getTranslation().z();

	projected_velocity_norm = (V[3]*projection_vector[0]) + (V[4]*projection_vector[1]) + (V[5]*projection_vector[2]);
	norm_divided = projected_velocity_norm / (pow(projection_vector[0],2) + pow(projection_vector[1],2) + pow(projection_vector[2],2));
	projected_velocity[0] = norm_divided * projection_vector[0];
	projected_velocity[1] = norm_divided * projection_vector[1];
	projected_velocity[2] = norm_divided * projection_vector[2];
	
return projected_velocity;
}












