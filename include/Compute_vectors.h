Eigen::Vector3d compute_unit_vect(Eigen::Displacementd C_pt_ob_seg, Eigen::Displacementd C_pt_seg);
Eigen::Vector3d compute_normal_unit_vect(Eigen::Vector3d vect_unitaire);
Eigen::Vector3d compute_unit_vect_2(double nxt_step_des_x, double nxt_step_des_y, double nxt_step_des_z, double X_des, double Y_des, double Z_des);
Eigen::Vector3d compute_unit_vect_3(Eigen::Displacementd H_7, double X_des, double Y_des, double Z_des);
int compute_nbr_unit_vect_to_X_des(double nxt_step_des_x, double nxt_step_des_y, double nxt_step_des_z, double X_des, double Y_des, double Z_des, double traj_step_size);
double compute_angle(Eigen::Twistd V_7, Eigen::Displacementd C_pt_ob_seg, Eigen::Displacementd C_pt_seg);
