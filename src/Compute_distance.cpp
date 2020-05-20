#include <iostream>
#include <Eigen/Core>
#include <Eigen/Lgsm>
#include <stdio.h>      
#include <math.h>       
#include "Compute_distance.h"


double compute_distance(Eigen::Displacementd point_1 , Eigen::Displacementd point_2){
	double distance; 
	distance = sqrt(pow(point_1.getTranslation().x()-point_2.getTranslation().x(),2) + pow(point_1.getTranslation().y()-point_2.getTranslation().y(),2) 
											 + pow(point_1.getTranslation().z()-point_2.getTranslation().z(),2));
return distance;
}



double compute_posi_Err(Eigen::Displacementd H_7, double circle_traj_x, double circle_traj_y, double circle_traj_z){
	double distance; 
	distance = sqrt(pow(circle_traj_x-H_7.getTranslation().x(),2) + pow(circle_traj_y-H_7.getTranslation().y(),2) + pow(circle_traj_z-H_7.getTranslation().z(),2));
return distance;
}



double dist_to_nrst_ob(double distance_1, double distance_2, double distance_3, double distance_4){
	double distance_mini_1;
	double distance_mini_2;
	double distance_mini_final;

	distance_mini_1 = fmin(distance_1, distance_2);
	distance_mini_2 = fmin(distance_3, distance_4);
	distance_mini_final = fmin(distance_mini_1, distance_mini_2);

return distance_mini_final; 
}




char *id_nrst_ob(double distance_1, double distance_2, double distance_3, double distance_4){     //dist_1 : to the ground;   dist_2 : to ob1;   dist_3 : to ob2;   dist_4 : to sphere
        using namespace std;
	string gr  = "gr";
	string ob1 = "ob1";
	string ob2 = "ob2";
	string sph = "sph";
        char*   id;
	double distance_mini_1;
	double distance_mini_2;
	double distance_mini_final;

	distance_mini_1 = fmin(distance_1, distance_2);
	distance_mini_2 = fmin(distance_3, distance_4);
	distance_mini_final = fmin(distance_mini_1, distance_mini_2);

	if(distance_mini_final == distance_1){
	id = (char*)gr.c_str();
	}

	if(distance_mini_final == distance_2){
	id =  (char*)ob1.c_str();
	}

	if(distance_mini_final == distance_3){
	id =  (char*)ob2.c_str();
	}

	if(distance_mini_final == distance_4){
	id =  (char*)sph.c_str();
	}

return id; 
}







//Computethe vector representing the distance to the closest obstacle
Eigen::Vector3d compute_vect_dist_nrst_obst(char* nrst_ob_id, Eigen::Displacementd point_1, Eigen::Displacementd point_2, Eigen::Displacementd point_3, Eigen::Displacementd point_4, 
					             Eigen::Displacementd point_5, Eigen::Displacementd point_6, Eigen::Displacementd point_7, Eigen::Displacementd point_8){
	using namespace std;	
	Eigen::Vector3d projection_vector;           //It is called projection vector because this vector is used to project distance
	char* gr =  "gr";
	char* ob1 = "ob1";
	char* ob2 = "ob2";
	char* sph = "sph";


if(strcmp(nrst_ob_id,gr)==0){
	projection_vector[0] =  point_1.getTranslation().x()-point_2.getTranslation().x();
	projection_vector[1] =  point_1.getTranslation().y()-point_2.getTranslation().y();
	projection_vector[2] =  point_1.getTranslation().z()-point_2.getTranslation().z();
	}

else if(strcmp(nrst_ob_id,ob1)==0){
	projection_vector[0] =  point_3.getTranslation().x()-point_4.getTranslation().x();
	projection_vector[1] =  point_3.getTranslation().y()-point_4.getTranslation().y();
	projection_vector[2] =  point_3.getTranslation().z()-point_4.getTranslation().z();
	}

else if(strcmp(nrst_ob_id,ob2)==0){
	projection_vector[0] =  point_5.getTranslation().x()-point_6.getTranslation().x();
	projection_vector[1] =  point_5.getTranslation().y()-point_6.getTranslation().y();
	projection_vector[2] =  point_5.getTranslation().z()-point_6.getTranslation().z();
	}

else if(strcmp(nrst_ob_id,sph)==0){
	projection_vector[0] =  point_7.getTranslation().x()-point_8.getTranslation().x();
	projection_vector[1] =  point_7.getTranslation().y()-point_8.getTranslation().y();
	projection_vector[2] =  point_7.getTranslation().z()-point_8.getTranslation().z();
	}


return projection_vector;
}




//Compute the vector representing the distance to the closest obstacle
Eigen::Vector3d compute_vect_dist_nrst_obst_considered(Eigen::Displacementd point_1, Eigen::Displacementd point_2){
	using namespace std;	
	Eigen::Vector3d projection_vector;           //It is called projection vector because this vector is used to project distance


	projection_vector[0] =  point_2.getTranslation().x()-point_1.getTranslation().x();
	projection_vector[1] =  point_2.getTranslation().y()-point_1.getTranslation().y();
	projection_vector[2] =  point_2.getTranslation().z()-point_1.getTranslation().z();


return projection_vector;
}
