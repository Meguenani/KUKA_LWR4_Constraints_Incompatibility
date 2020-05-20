Eigen::Matrix<double, 6, 7> ordonate(Eigen::Matrix<double, 6, 7> J_desordonated);
Eigen::Matrix<double, 6, 7> correct(Eigen::Matrix<double, 6, 7> J_77);
Eigen::Matrix<double, 6, 7> derive(Eigen::Matrix<double, 6, 7> J, Eigen::Matrix<double, 6, 7> J_previous, double time_step);
