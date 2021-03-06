
double compute_E(double V_seg_sgn_norm, Eigen::Vector3d V_seg, double m_eq_i_j);
double compute_E_f(double V_pt_C_seg, double m_eq_i_j);
double compute_E_max (double d, double d_safe, double E_safe, double d_max, double F_max);
double compute_E_limit (double d, double d_safe, double E_safe, double d_max, double F_max);
double compute_jerk_pond(double d, double d_safe, double d_thres);
int know_sign (double V);
double compute_E2(double V_seg_sgn_norm, Eigen::Vector3d V_seg, Eigen::Matrix<double, 3, 3> M_cart_inv, int segment_number);
double compute_E6(double V_seg_sgn_norm, Eigen::Vector3d V_seg, double m_eq_i_j);
