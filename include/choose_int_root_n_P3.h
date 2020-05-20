Eigen::VectorXi int_root_neg_jerk_P3(Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_neg_jerk_poly, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q_k2, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_min, Eigen::VectorXd q_dot, double dt);
Eigen::VectorXi int_root_pos_jerk_P3(Eigen::Matrix<int, 3, 7> rounded_Cubic_roots_pos_jerk_poly, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q_k2, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_max, Eigen::VectorXd q_dot, double dt);



