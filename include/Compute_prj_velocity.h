

double compute_velocity_sgn_norm(char* nrst_ob_id, Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2, Eigen::Displacementd point_3, Eigen::Displacementd point_4, 
							   Eigen::Displacementd point_5, Eigen::Displacementd point_6, Eigen::Displacementd point_7, Eigen::Displacementd point_8);


Eigen::Vector3d compute_velocity_pr_vect(char* nrst_ob_id, Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2, Eigen::Displacementd point_3, Eigen::Displacementd point_4, 
							   Eigen::Displacementd point_5, Eigen::Displacementd point_6, Eigen::Displacementd point_7, Eigen::Displacementd point_8);


Eigen::Vector3d compute_velocity_pr_vect_considered(Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2);

double compute_velocity_sgn_norm_considered(Eigen::Twistd V, Eigen::Displacementd point_1, Eigen::Displacementd point_2);
