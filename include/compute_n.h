Eigen::VectorXi compute_n_neg_acc_posi(Eigen::VectorXd q_dotdot_bounds_min_trq_derived, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q, double dt);
Eigen::VectorXi compute_n_pos_acc_posi(Eigen::VectorXd q_dotdot_bounds_max_trq_derived, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q, double dt);
Eigen::VectorXi compute_n_neg_jerk_vel(Eigen::VectorXd q_dddot_bounds_min, Eigen::VectorXd q_dot_bounds_max, Eigen::VectorXd q_dot, double dt);
Eigen::VectorXi compute_n_pos_jerk_vel(Eigen::VectorXd q_dddot_bounds_max, Eigen::VectorXd q_dot_bounds_min, Eigen::VectorXd q_dot, double dt);
Eigen::VectorXi compute_n_neg_jerk_acc_posi(Eigen::VectorXi n1_neg_jerk_acc_posi, Eigen::VectorXd q_dotdot_bounds_min_optimized, Eigen::VectorXd q_bounds_max, Eigen::VectorXd q, Eigen::VectorXd q_k2, Eigen::VectorXd q_dot, Eigen::VectorXd q_ddot, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_min, double dt);
Eigen::VectorXi compute_n_pos_jerk_acc_posi(Eigen::VectorXi n1_pos_jerk_acc_posi, Eigen::VectorXd q_dotdot_bounds_max_optimized, Eigen::VectorXd q_bounds_min, Eigen::VectorXd q, Eigen::VectorXd q_k2, Eigen::VectorXd q_dot, Eigen::VectorXd q_ddot, Eigen::VectorXd q_ddot_k2, Eigen::VectorXd q_dddot_bounds_max, double dt);

