#include <iostream>
#include <fstream>
#include <Eigen/Lgsm>
#include <Eigen/Geometry> 
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/LU> 

using namespace std;


void save_E_2(double E_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_2.txt", std::ios_base::app);
    outputfile << E_2 << endl;

}

void save_E_2_max(double E_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_2_max.txt", std::ios_base::app);
    outputfile << E_2_max << endl;

}


void save_Force_sensor_x(double Force_sensor_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Force_sensor_x.txt", std::ios_base::app);
    outputfile << Force_sensor_x << endl;

}

void save_Force_sensor_y(double Force_sensor_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Force_sensor_y.txt", std::ios_base::app);
    outputfile << Force_sensor_y << endl;

}

void save_Force_sensor_z(double Force_sensor_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Force_sensor_z.txt", std::ios_base::app);
    outputfile << Force_sensor_z << endl;

}







void save_Ep_real_during_and_before_contact_x(double Ep_real_during_and_before_contact_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_real_during_and_before_contact_x.txt", std::ios_base::app);
    outputfile << Ep_real_during_and_before_contact_x << endl;

}






void save_robot_force_x_nxt_step(double robot_force_x_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_x_nxt_step.txt", std::ios_base::app);
    outputfile << robot_force_x_nxt_step << endl;

}

void save_Real_robot_force_estimated_x(double Real_robot_force_estimated_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Real_robot_force_estimated_x.txt", std::ios_base::app);
    outputfile << Real_robot_force_estimated_x << endl;

}

void save_robot_force_x_nxt_step_limit_max(double robot_force_x_nxt_step_limit_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_x_nxt_step_limit_max.txt", std::ios_base::app);
    outputfile << robot_force_x_nxt_step_limit_max << endl;

}



void save_robot_force_x_nxt_step_limit_min(double robot_force_x_nxt_step_limit_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_x_nxt_step_limit_min.txt", std::ios_base::app);
    outputfile << robot_force_x_nxt_step_limit_min << endl;

}







void save_robot_force_z_nxt_step(double robot_force_z_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_z_nxt_step.txt", std::ios_base::app);
    outputfile << robot_force_z_nxt_step << endl;

}

void save_Real_robot_force_estimated_z(double Real_robot_force_estimated_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Real_robot_force_estimated_z.txt", std::ios_base::app);
    outputfile << Real_robot_force_estimated_z << endl;

}

void save_robot_force_z_nxt_step_limit_max(double robot_force_z_nxt_step_limit_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_z_nxt_step_limit_max.txt", std::ios_base::app);
    outputfile << robot_force_z_nxt_step_limit_max << endl;

}



void save_robot_force_z_nxt_step_limit_min(double robot_force_z_nxt_step_limit_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/robot_force_z_nxt_step_limit_min.txt", std::ios_base::app);
    outputfile << robot_force_z_nxt_step_limit_min << endl;

}






void save_Ep_x_nxt_step(double Ep_x_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_x_nxt_step.txt", std::ios_base::app);
    outputfile << Ep_x_nxt_step << endl;

}

void save_Ep_x_nxt_step_limit_max(double Ep_x_nxt_step_limit_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_x_nxt_step_limit_max.txt", std::ios_base::app);
    outputfile << Ep_x_nxt_step_limit_max << endl;

}

void save_Ep_x_nxt_step_limit_min(double Ep_x_nxt_step_limit_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_x_nxt_step_limit_min.txt", std::ios_base::app);
    outputfile << Ep_x_nxt_step_limit_min << endl;
}


void save_Real_Ep_x(double Real_Ep_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Real_Ep_x.txt", std::ios_base::app);
    outputfile << Real_Ep_x << endl;
}






void save_E_3(double E_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_3.txt", std::ios_base::app);
    outputfile << E_3 << endl;
}


void save_E_3_max(double E_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_3_max.txt", std::ios_base::app);
    outputfile << E_3_max << endl;
}




void save_E_4(double E_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_4.txt", std::ios_base::app);
    outputfile << E_4 << endl;
}


void save_E_4_max(double E_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_4_max.txt", std::ios_base::app);
    outputfile << E_4_max << endl;
}





void save_E_5(double E_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_5.txt", std::ios_base::app);
    outputfile << E_5 << endl;
}


void save_E_5_max(double E_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_5_max.txt", std::ios_base::app);
    outputfile << E_5_max << endl;
}





void save_E_6(double E_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_6.txt", std::ios_base::app);
    outputfile << E_6 << endl;
}


void save_E_6_max(double E_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_6_max.txt", std::ios_base::app);
    outputfile << E_6_max << endl;
}





void save_Ec_7(double Ec_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_7.txt", std::ios_base::app);
    outputfile << Ec_7 << endl;
}


void save_Ec_7_max(double Ec_7_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_7_max.txt", std::ios_base::app);
    outputfile << Ec_7_max << endl;
}







void save_E_p_7(double E_p_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_p_7.txt", std::ios_base::app);
    outputfile << E_p_7 << endl;
}



void save_E_p_7_apprx(double E_p_7_apprx)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_p_7_apprx.txt", std::ios_base::app);
    outputfile << E_p_7_apprx << endl;
}



void save_Ep_7_x(double Ep_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_7_x.txt", std::ios_base::app);
    outputfile << Ep_7_x << endl;
}



void save_Ep_rebuilt2(double Ep_rebuilt2)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_rebuilt2.txt", std::ios_base::app);
    outputfile << Ep_rebuilt2 << endl;
}



void save_Acc_7_x_nxt_step(double Acc_7_x_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_x_nxt_step.txt", std::ios_base::app);
    outputfile << Acc_7_x_nxt_step << endl;
}


void save_Ep_7_prj_real(double Ep_7_prj_real)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_7_prj_real.txt", std::ios_base::app);
    outputfile << Ep_7_prj_real << endl;
}


void save_m_eq_7_j_Xerr(double m_eq_7_j_Xerr)
{
    ofstream outputfile;
    outputfile.open("saved_data/m_eq_7_j_Xerr.txt", std::ios_base::app);
    outputfile << m_eq_7_j_Xerr << endl;
}



void save_E_7_reconstructed_with_V_7_t2_derived(double E_7_reconstructed_with_V_7_t2_derived)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_7_reconstructed_with_V_7_t2_derived.txt", std::ios_base::app);
    outputfile << E_7_reconstructed_with_V_7_t2_derived << endl;
}





void save_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x(double Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", std::ios_base::app);
    outputfile << Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x << endl;
}



void save_Ec_7_x_rcnsrcted_wth_small_Ep_7_x_nxt_step(double Ec_7_x_rcnsrcted_wth_small_Ep_7_x_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_7_x_rcnsrcted_wth_small_Ep_7_x_nxt_step.txt", std::ios_base::app);
    outputfile << Ec_7_x_rcnsrcted_wth_small_Ep_7_x_nxt_step << endl;
}




void save_Ep_7_x_max(double Ep_7_x_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ep_7_x_max.txt", std::ios_base::app);
    outputfile << Ep_7_x_max << endl;
}


//save E_min 

void save_E_2_min(double E_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_2_min.txt", std::ios_base::app);
    outputfile << E_2_min << endl;

}

void save_E_3_min(double E_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_3_min.txt", std::ios_base::app);
    outputfile << E_3_min << endl;
}

void save_E_4_min(double E_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_4_min.txt", std::ios_base::app);
    outputfile << E_4_min << endl;
}

void save_E_5_min(double E_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_5_min.txt", std::ios_base::app);
    outputfile << E_5_min << endl;
}


void save_E_6_min(double E_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_6_min.txt", std::ios_base::app);
    outputfile << E_6_min << endl;
}

void save_E_7_min(double E_7_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_7_min.txt", std::ios_base::app);
    outputfile << E_7_min << endl;
}


void save_Ec_max_7_x(double Ec_max_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_max_7_x.txt", std::ios_base::app);
    outputfile << Ec_max_7_x << endl;
}








void save_dist_07(double global_dist_07_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_07_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_07_nrst_ob << endl;
}


void save_dist_06(double global_dist_06_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_06_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_06_nrst_ob << endl;
}



void save_dist_05(double global_dist_05_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_05_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_05_nrst_ob << endl;
}



void save_dist_04(double global_dist_04_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_04_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_04_nrst_ob << endl;
}




void save_dist_03(double global_dist_03_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_03_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_03_nrst_ob << endl;
}



void save_dist_02(double global_dist_02_nrst_ob){
    ofstream outputfile;
    outputfile.open("saved_data/Dist_02_nrst_ob.txt", std::ios_base::app);
    outputfile << global_dist_02_nrst_ob << endl;
}


double save_d_safe(double global_d_safe){
    ofstream outputfile;
    outputfile.open("saved_data/D_safe.txt", std::ios_base::app);
    outputfile << global_d_safe << endl;
}










void save_global_time(double time)
{
    ofstream outputfile;
    outputfile.open("saved_data/time.txt", std::ios_base::app);
    outputfile << time << endl;

}


void save_trajectory_x(double x)
{
    ofstream outputfile;
    outputfile.open("saved_data/trajectory_x.txt", std::ios_base::app);
    outputfile << x << endl;

}


void save_trajectory_y(double y)
{
    ofstream outputfile;
    outputfile.open("saved_data/trajectory_y.txt", std::ios_base::app);
    outputfile << y << endl;

}


void save_trajectory_z(double z)
{
    ofstream outputfile;
    outputfile.open("saved_data/trajectory_z.txt", std::ios_base::app);
    outputfile << z << endl;

}







void save_des_trajectory_x(double x)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_trajectory_x.txt", std::ios_base::app);
    outputfile << x << endl;

}


void save_des_trajectory_y(double y)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_trajectory_y.txt", std::ios_base::app);
    outputfile << y << endl;

}


void save_des_trajectory_z(double z)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_trajectory_z.txt", std::ios_base::app);
    outputfile << z << endl;

}







//Save torques
void save_tau_0(double tau_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_0.txt", std::ios_base::app);
    outputfile << tau_0 << endl;

}

void save_tau_1(double tau_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_1.txt", std::ios_base::app);
    outputfile << tau_1 << endl;

}

void save_tau_2(double tau_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_2.txt", std::ios_base::app);
    outputfile << tau_2 << endl;

}

void save_tau_3(double tau_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_3.txt", std::ios_base::app);
    outputfile << tau_3 << endl;

}


void save_tau_4(double tau_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_4.txt", std::ios_base::app);
    outputfile << tau_4 << endl;

}

void save_tau_5(double tau_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_5.txt", std::ios_base::app);
    outputfile << tau_5 << endl;

}

void save_tau_6(double tau_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_6.txt", std::ios_base::app);
    outputfile << tau_6 << endl;

}








//Save tau max

//Save torques
void save_tau_0_max(double tau_0_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_0_max.txt", std::ios_base::app);
    outputfile << tau_0_max << endl;

}

void save_tau_1_max(double tau_1_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_1_max.txt", std::ios_base::app);
    outputfile << tau_1_max << endl;

}

void save_tau_2_max(double tau_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_2_max.txt", std::ios_base::app);
    outputfile << tau_2_max << endl;

}

void save_tau_3_max(double tau_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_3_max.txt", std::ios_base::app);
    outputfile << tau_3_max << endl;

}


void save_tau_4_max(double tau_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_4_max.txt", std::ios_base::app);
    outputfile << tau_4_max << endl;

}

void save_tau_5_max(double tau_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_5_max.txt", std::ios_base::app);
    outputfile << tau_5_max << endl;

}

void save_tau_6_max(double tau_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_6_max.txt", std::ios_base::app);
    outputfile << tau_6_max << endl;

}











//Save tau min

//Save torques
void save_tau_0_min(double tau_0_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_0_min.txt", std::ios_base::app);
    outputfile << tau_0_min << endl;

}

void save_tau_1_min(double tau_1_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_1_min.txt", std::ios_base::app);
    outputfile << tau_1_min << endl;

}

void save_tau_2_min(double tau_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_2_min.txt", std::ios_base::app);
    outputfile << tau_2_min << endl;

}

void save_tau_3_min(double tau_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_3_min.txt", std::ios_base::app);
    outputfile << tau_3_min << endl;

}


void save_tau_4_min(double tau_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_4_min.txt", std::ios_base::app);
    outputfile << tau_4_min << endl;

}

void save_tau_5_min(double tau_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_5_min.txt", std::ios_base::app);
    outputfile << tau_5_min << endl;

}

void save_tau_6_min(double tau_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_6_min.txt", std::ios_base::app);
    outputfile << tau_6_min << endl;

}









//Save acceleration
void save_q_dotdot_0(double q_dotdot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_0.txt", std::ios_base::app);
    outputfile << q_dotdot_0 << endl;

}

void save_q_dotdot_1(double q_dotdot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_1.txt", std::ios_base::app);
    outputfile << q_dotdot_1 << endl;

}

void save_q_dotdot_2(double q_dotdot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_2.txt", std::ios_base::app);
    outputfile << q_dotdot_2 << endl;

}

void save_q_dotdot_3(double q_dotdot_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_3.txt", std::ios_base::app);
    outputfile << q_dotdot_3 << endl;

}

void save_q_dotdot_4(double q_dotdot_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_4.txt", std::ios_base::app);
    outputfile << q_dotdot_4 << endl;

}

void save_q_dotdot_5(double q_dotdot_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_5.txt", std::ios_base::app);
    outputfile << q_dotdot_5 << endl;

}

void save_q_dotdot_6(double q_dotdot_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_6.txt", std::ios_base::app);
    outputfile << q_dotdot_6 << endl;

}

















//Save acceleration real
void save_q_dotdot_real_0(double q_dotdot_real_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_0.txt", std::ios_base::app);
    outputfile << q_dotdot_real_0 << endl;

}

void save_q_dotdot_real_1(double q_dotdot_real_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_1.txt", std::ios_base::app);
    outputfile << q_dotdot_real_1 << endl;

}

void save_q_dotdot_real_2(double q_dotdot_real_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_2.txt", std::ios_base::app);
    outputfile << q_dotdot_real_2 << endl;

}

void save_q_dotdot_real_3(double q_dotdot_real_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_3.txt", std::ios_base::app);
    outputfile << q_dotdot_real_3 << endl;

}

void save_q_dotdot_real_4(double q_dotdot_real_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_4.txt", std::ios_base::app);
    outputfile << q_dotdot_real_4 << endl;

}

void save_q_dotdot_real_5(double q_dotdot_real_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_5.txt", std::ios_base::app);
    outputfile << q_dotdot_real_5 << endl;

}

void save_q_dotdot_real_6(double q_dotdot_real_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_real_6.txt", std::ios_base::app);
    outputfile << q_dotdot_real_6 << endl;

}

















//Save acceleration max
void save_q_dotdot_0_max(double q_dotdot_0_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_0_max.txt", std::ios_base::app);
    outputfile << q_dotdot_0_max << endl;

}


void save_q_dotdot_1_max(double q_dotdot_1_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_1_max.txt", std::ios_base::app);
    outputfile << q_dotdot_1_max << endl;

}


void save_q_dotdot_2_max(double q_dotdot_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_2_max.txt", std::ios_base::app);
    outputfile << q_dotdot_2_max << endl;

}


void save_q_dotdot_3_max(double q_dotdot_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_3_max.txt", std::ios_base::app);
    outputfile << q_dotdot_3_max << endl;

}


void save_q_dotdot_4_max(double q_dotdot_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_4_max.txt", std::ios_base::app);
    outputfile << q_dotdot_4_max << endl;

}


void save_q_dotdot_5_max(double q_dotdot_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_5_max.txt", std::ios_base::app);
    outputfile << q_dotdot_5_max << endl;

}


void save_q_dotdot_6_max(double q_dotdot_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_6_max.txt", std::ios_base::app);
    outputfile << q_dotdot_6_max << endl;

}








//Save acceleration min
void save_q_dotdot_0_min(double q_dotdot_0_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_0_min.txt", std::ios_base::app);
    outputfile << q_dotdot_0_min << endl;

}


void save_q_dotdot_1_min(double q_dotdot_1_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_1_min.txt", std::ios_base::app);
    outputfile << q_dotdot_1_min << endl;

}


void save_q_dotdot_2_min(double q_dotdot_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_2_min.txt", std::ios_base::app);
    outputfile << q_dotdot_2_min << endl;

}


void save_q_dotdot_3_min(double q_dotdot_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_3_min.txt", std::ios_base::app);
    outputfile << q_dotdot_3_min << endl;

}


void save_q_dotdot_4_min(double q_dotdot_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_4_min.txt", std::ios_base::app);
    outputfile << q_dotdot_4_min << endl;

}


void save_q_dotdot_5_min(double q_dotdot_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_5_min.txt", std::ios_base::app);
    outputfile << q_dotdot_5_min << endl;

}


void save_q_dotdot_6_min(double q_dotdot_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_6_min.txt", std::ios_base::app);
    outputfile << q_dotdot_6_min << endl;

}





//Save Jerk
void save_q_dotdotdot_0(double q_dotdotdot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_0.txt", std::ios_base::app);
    outputfile << q_dotdotdot_0 << endl;

}

void save_q_dotdotdot_1(double q_dotdotdot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_1.txt", std::ios_base::app);
    outputfile << q_dotdotdot_1 << endl;

}

void save_q_dotdotdot_2(double q_dotdotdot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_2.txt", std::ios_base::app);
    outputfile << q_dotdotdot_2 << endl;

}

void save_q_dotdotdot_3(double q_dotdotdot_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_3.txt", std::ios_base::app);
    outputfile << q_dotdotdot_3 << endl;

}

void save_q_dotdotdot_4(double q_dotdotdot_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_4.txt", std::ios_base::app);
    outputfile << q_dotdotdot_4 << endl;

}

void save_q_dotdotdot_5(double q_dotdotdot_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_5.txt", std::ios_base::app);
    outputfile << q_dotdotdot_5 << endl;

}

void save_q_dotdotdot_6(double q_dotdotdot_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_6.txt", std::ios_base::app);
    outputfile << q_dotdotdot_6 << endl;

}





//Save Jerk max
void save_q_dotdotdot_0_max(double q_dotdotdot_0_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_0_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_0_max << endl;

}


void save_q_dotdotdot_1_max(double q_dotdotdot_1_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_1_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_1_max << endl;

}


void save_q_dotdotdot_2_max(double q_dotdotdot_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_2_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_2_max << endl;

}


void save_q_dotdotdot_3_max(double q_dotdotdot_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_3_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_3_max << endl;

}


void save_q_dotdotdot_4_max(double q_dotdotdot_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_4_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_4_max << endl;

}


void save_q_dotdotdot_5_max(double q_dotdotdot_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_5_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_5_max << endl;

}


void save_q_dotdotdot_6_max(double q_dotdotdot_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_6_max.txt", std::ios_base::app);
    outputfile << q_dotdotdot_6_max << endl;

}





//Save_q_dotdot_bounds_max_optimized //nombre articular acceleration constraints derived from torque constraints
void save_q_dotdot_bounds_max_optimized(Eigen::VectorXd q_dotdot_bounds_max_optimized)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_max_optimized_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_max_optimized[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_max_optimized_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_max_optimized[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_max_optimized_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_max_optimized[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_max_optimized_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_max_optimized[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_max_optimized_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_max_optimized[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_max_optimized_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_max_optimized[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_max_optimized_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_max_optimized[6] << endl;
}

void save_q_dotdot_bounds_min_optimized(Eigen::VectorXd q_dotdot_bounds_min_optimized)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_min_optimized_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_min_optimized[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_min_optimized_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_min_optimized[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_min_optimized_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_min_optimized[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_min_optimized_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_min_optimized[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_min_optimized_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_min_optimized[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_min_optimized_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_min_optimized[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_min_optimized_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_min_optimized[6] << endl;
}






//Save_n //nombre de pas pour arriver aux bounds
//Save Jerk max
void save_n_neg_acc_posi(Eigen::VectorXi n_neg_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n_neg_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n_neg_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n_neg_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n_neg_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n_neg_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n_neg_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n_neg_acc_posi[6] << endl;
}

void save_n_pos_acc_posi(Eigen::VectorXi n_pos_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n_pos_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n_pos_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n_pos_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n_pos_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n_pos_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n_pos_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n_pos_acc_posi[6] << endl;
}






void save_n_neg_jerk_vel(Eigen::VectorXi n_neg_jerk_vel)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_jerk_vel_0.txt", std::ios_base::app);
    outputfile0 << n_neg_jerk_vel[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_jerk_vel_1.txt", std::ios_base::app);
    outputfile1 << n_neg_jerk_vel[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_jerk_vel_2.txt", std::ios_base::app);
    outputfile2 << n_neg_jerk_vel[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_jerk_vel_3.txt", std::ios_base::app);
    outputfile3 << n_neg_jerk_vel[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_jerk_vel_4.txt", std::ios_base::app);
    outputfile4 << n_neg_jerk_vel[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_jerk_vel_5.txt", std::ios_base::app);
    outputfile5 << n_neg_jerk_vel[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_jerk_vel_6.txt", std::ios_base::app);
    outputfile6 << n_neg_jerk_vel[6] << endl;
}

void save_n_pos_jerk_vel(Eigen::VectorXi n_pos_jerk_vel)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_jerk_vel_0.txt", std::ios_base::app);
    outputfile0 << n_pos_jerk_vel[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_jerk_vel_1.txt", std::ios_base::app);
    outputfile1 << n_pos_jerk_vel[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_jerk_vel_2.txt", std::ios_base::app);
    outputfile2 << n_pos_jerk_vel[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_jerk_vel_3.txt", std::ios_base::app);
    outputfile3 << n_pos_jerk_vel[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_jerk_vel_4.txt", std::ios_base::app);
    outputfile4 << n_pos_jerk_vel[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_jerk_vel_5.txt", std::ios_base::app);
    outputfile5 << n_pos_jerk_vel[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_jerk_vel_6.txt", std::ios_base::app);
    outputfile6 << n_pos_jerk_vel[6] << endl;
}






void save_n_neg_jerk_posi(Eigen::VectorXi n_neg_jerk_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_jerk_posi_0.txt", std::ios_base::app);
    outputfile0 << n_neg_jerk_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_jerk_posi_1.txt", std::ios_base::app);
    outputfile1 << n_neg_jerk_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_jerk_posi_2.txt", std::ios_base::app);
    outputfile2 << n_neg_jerk_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_jerk_posi_3.txt", std::ios_base::app);
    outputfile3 << n_neg_jerk_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_jerk_posi_4.txt", std::ios_base::app);
    outputfile4 << n_neg_jerk_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_jerk_posi_5.txt", std::ios_base::app);
    outputfile5 << n_neg_jerk_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_jerk_posi_6.txt", std::ios_base::app);
    outputfile6 << n_neg_jerk_posi[6] << endl;
}

void save_n_pos_jerk_posi(Eigen::VectorXi n_pos_jerk_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_jerk_posi_0.txt", std::ios_base::app);
    outputfile0 << n_pos_jerk_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_jerk_posi_1.txt", std::ios_base::app);
    outputfile1 << n_pos_jerk_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_jerk_posi_2.txt", std::ios_base::app);
    outputfile2 << n_pos_jerk_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_jerk_posi_3.txt", std::ios_base::app);
    outputfile3 << n_pos_jerk_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_jerk_posi_4.txt", std::ios_base::app);
    outputfile4 << n_pos_jerk_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_jerk_posi_5.txt", std::ios_base::app);
    outputfile5 << n_pos_jerk_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_jerk_posi_6.txt", std::ios_base::app);
    outputfile6 << n_pos_jerk_posi[6] << endl;
}






void save_n_neg_jerk_posi_explored(Eigen::VectorXi n_neg_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n_neg_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n_neg_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n_neg_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n_neg_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n_neg_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n_neg_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n_neg_jerk_posi_explored[6] << endl;
}

void save_n_pos_jerk_posi_explored(Eigen::VectorXi n_pos_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n_pos_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n_pos_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n_pos_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n_pos_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n_pos_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n_pos_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n_pos_jerk_posi_explored[6] << endl;
}




void save_n1_neg_jerk_posi_explored(Eigen::VectorXd n1_neg_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_jerk_posi_explored[6] << endl;
}





void save_n1_pos_jerk_posi_explored(Eigen::VectorXd n1_pos_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_jerk_posi_explored[6] << endl;
}





void save_n2_neg_jerk_posi_explored(Eigen::VectorXd n2_neg_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_jerk_posi_explored[6] << endl;
}





void save_n2_pos_jerk_posi_explored(Eigen::VectorXd n2_pos_jerk_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_jerk_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_jerk_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_jerk_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_jerk_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_jerk_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_jerk_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_jerk_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_jerk_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_jerk_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_jerk_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_jerk_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_jerk_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_jerk_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_jerk_posi_explored[6] << endl;
}















void save_n1_neg_jerk_posi_explored_q(Eigen::VectorXd n1_neg_jerk_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_jerk_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_jerk_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_jerk_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_jerk_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_jerk_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_jerk_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_jerk_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_jerk_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_jerk_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_jerk_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_jerk_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_jerk_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_jerk_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_jerk_posi_explored_q[6] << endl;
}





void save_n1_pos_jerk_posi_explored_q(Eigen::VectorXd n1_pos_jerk_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_jerk_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_jerk_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_jerk_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_jerk_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_jerk_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_jerk_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_jerk_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_jerk_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_jerk_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_jerk_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_jerk_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_jerk_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_jerk_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_jerk_posi_explored_q[6] << endl;
}





void save_n2_neg_jerk_posi_explored_q(Eigen::VectorXd n2_neg_jerk_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_jerk_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_jerk_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_jerk_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_jerk_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_jerk_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_jerk_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_jerk_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_jerk_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_jerk_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_jerk_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_jerk_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_jerk_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_jerk_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_jerk_posi_explored_q[6] << endl;
}





void save_n2_pos_jerk_posi_explored_q(Eigen::VectorXd n2_pos_jerk_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_jerk_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_jerk_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_jerk_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_jerk_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_jerk_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_jerk_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_jerk_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_jerk_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_jerk_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_jerk_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_jerk_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_jerk_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_jerk_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_jerk_posi_explored_q[6] << endl;
}
//Save Jerk min
void save_q_dotdotdot_0_min(double q_dotdotdot_0_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_0_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_0_min << endl;

}


void save_q_dotdotdot_1_min(double q_dotdotdot_1_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_1_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_1_min << endl;

}


void save_q_dotdotdot_2_min(double q_dotdotdot_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_2_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_2_min << endl;

}


void save_q_dotdotdot_3_min(double q_dotdotdot_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_3_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_3_min << endl;

}


void save_q_dotdotdot_4_min(double q_dotdotdot_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_4_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_4_min << endl;

}


void save_q_dotdotdot_5_min(double q_dotdotdot_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_5_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_5_min << endl;

}


void save_q_dotdotdot_6_min(double q_dotdotdot_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdotdot_6_min.txt", std::ios_base::app);
    outputfile << q_dotdotdot_6_min << endl;

}



//Calcul du jerk en derivant les acc en sortie du solver
void save_q_dotdotdot_gurobi(Eigen::VectorXd q_dotdotdot_gurobi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdotdot_gurobi_0.txt", std::ios_base::app);
    outputfile0 << q_dotdotdot_gurobi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdotdot_gurobi_1.txt", std::ios_base::app);
    outputfile1 << q_dotdotdot_gurobi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdotdot_gurobi_2.txt", std::ios_base::app);
    outputfile2 << q_dotdotdot_gurobi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdotdot_gurobi_3.txt", std::ios_base::app);
    outputfile3 << q_dotdotdot_gurobi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdotdot_gurobi_4.txt", std::ios_base::app);
    outputfile4 << q_dotdotdot_gurobi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdotdot_gurobi_5.txt", std::ios_base::app);
    outputfile5 << q_dotdotdot_gurobi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdotdot_gurobi_6.txt", std::ios_base::app);
    outputfile6 << q_dotdotdot_gurobi[6] << endl;
}




void save_q_n_neg_jerk_posi_reconstr(Eigen::VectorXd q_n_neg_jerk_posi_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_neg_jerk_posi_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_neg_jerk_posi_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_neg_jerk_posi_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_neg_jerk_posi_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_neg_jerk_posi_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_neg_jerk_posi_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_neg_jerk_posi_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_neg_jerk_posi_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_neg_jerk_posi_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_neg_jerk_posi_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_neg_jerk_posi_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_neg_jerk_posi_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_neg_jerk_posi_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_neg_jerk_posi_reconstr[6] << endl;
}





void save_q_n_pos_jerk_posi_reconstr(Eigen::VectorXd q_n_pos_jerk_posi_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_pos_jerk_posi_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_pos_jerk_posi_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_pos_jerk_posi_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_pos_jerk_posi_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_pos_jerk_posi_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_pos_jerk_posi_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_pos_jerk_posi_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_pos_jerk_posi_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_pos_jerk_posi_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_pos_jerk_posi_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_pos_jerk_posi_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_pos_jerk_posi_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_pos_jerk_posi_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_pos_jerk_posi_reconstr[6] << endl;
}






void save_q_n_neg_jerk_posi_reconstr_explored(Eigen::VectorXd q_n_neg_jerk_posi_reconstr_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_0.txt", std::ios_base::app);
    outputfile0 << q_n_neg_jerk_posi_reconstr_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_1.txt", std::ios_base::app);
    outputfile1 << q_n_neg_jerk_posi_reconstr_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_2.txt", std::ios_base::app);
    outputfile2 << q_n_neg_jerk_posi_reconstr_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_3.txt", std::ios_base::app);
    outputfile3 << q_n_neg_jerk_posi_reconstr_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_4.txt", std::ios_base::app);
    outputfile4 << q_n_neg_jerk_posi_reconstr_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_5.txt", std::ios_base::app);
    outputfile5 << q_n_neg_jerk_posi_reconstr_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_neg_jerk_posi_reconstr_explored_6.txt", std::ios_base::app);
    outputfile6 << q_n_neg_jerk_posi_reconstr_explored[6] << endl;
}





void save_q_n_pos_jerk_posi_reconstr_explored(Eigen::VectorXd q_n_pos_jerk_posi_reconstr_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_0.txt", std::ios_base::app);
    outputfile0 << q_n_pos_jerk_posi_reconstr_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_1.txt", std::ios_base::app);
    outputfile1 << q_n_pos_jerk_posi_reconstr_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_2.txt", std::ios_base::app);
    outputfile2 << q_n_pos_jerk_posi_reconstr_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_3.txt", std::ios_base::app);
    outputfile3 << q_n_pos_jerk_posi_reconstr_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_4.txt", std::ios_base::app);
    outputfile4 << q_n_pos_jerk_posi_reconstr_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_5.txt", std::ios_base::app);
    outputfile5 << q_n_pos_jerk_posi_reconstr_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_pos_jerk_posi_reconstr_explored_6.txt", std::ios_base::app);
    outputfile6 << q_n_pos_jerk_posi_reconstr_explored[6] << endl;
}








void save_q_dot_n_neg_jerk_reconstr(Eigen::VectorXd q_dot_n_neg_jerk_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dot_n_neg_jerk_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_dot_n_neg_jerk_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dot_n_neg_jerk_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_dot_n_neg_jerk_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dot_n_neg_jerk_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_dot_n_neg_jerk_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dot_n_neg_jerk_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_dot_n_neg_jerk_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dot_n_neg_jerk_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_dot_n_neg_jerk_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dot_n_neg_jerk_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_dot_n_neg_jerk_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dot_n_neg_jerk_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_dot_n_neg_jerk_reconstr[6] << endl;
}







void save_q_n_neg_acc_reconstr(Eigen::VectorXd q_n_neg_acc_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_neg_acc_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_neg_acc_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_neg_acc_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_neg_acc_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_neg_acc_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_neg_acc_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_neg_acc_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_neg_acc_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_neg_acc_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_neg_acc_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_neg_acc_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_neg_acc_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_neg_acc_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_neg_acc_reconstr[6] << endl;
}




void save_q_n_pos_acc_reconstr(Eigen::VectorXd q_n_pos_acc_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_pos_acc_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_pos_acc_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_pos_acc_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_pos_acc_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_pos_acc_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_pos_acc_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_pos_acc_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_pos_acc_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_pos_acc_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_pos_acc_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_pos_acc_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_pos_acc_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_pos_acc_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_pos_acc_reconstr[6] << endl;
}






void save_q_dot_n_pos_jerk_reconstr(Eigen::VectorXd q_dot_n_pos_jerk_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dot_n_pos_jerk_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_dot_n_pos_jerk_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dot_n_pos_jerk_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_dot_n_pos_jerk_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dot_n_pos_jerk_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_dot_n_pos_jerk_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dot_n_pos_jerk_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_dot_n_pos_jerk_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dot_n_pos_jerk_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_dot_n_pos_jerk_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dot_n_pos_jerk_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_dot_n_pos_jerk_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dot_n_pos_jerk_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_dot_n_pos_jerk_reconstr[6] << endl;
}



//Save of compatible acceleration bounds
//Save acceleration max
void save_q_dotdot_0_max_comp(double q_dotdot_0_max_comp) 
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_0_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_0_max_comp << endl;

}


void save_q_dotdot_1_max_comp(double q_dotdot_1_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_1_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_1_max_comp << endl;

}


void save_q_dotdot_2_max_comp(double q_dotdot_2_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_2_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_2_max_comp << endl;

}


void save_q_dotdot_3_max_comp(double q_dotdot_3_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_3_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_3_max_comp << endl;

}


void save_q_dotdot_4_max_comp(double q_dotdot_4_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_4_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_4_max_comp << endl;

}


void save_q_dotdot_5_max_comp(double q_dotdot_5_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_5_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_5_max_comp << endl;

}


void save_q_dotdot_6_max_comp(double q_dotdot_6_max_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_6_max_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_6_max_comp << endl;

}



//Save acceleration min_comp
void save_q_dotdot_0_min_comp(double q_dotdot_0_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_0_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_0_min_comp << endl;

}


void save_q_dotdot_1_min_comp(double q_dotdot_1_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_1_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_1_min_comp << endl;

}


void save_q_dotdot_2_min_comp(double q_dotdot_2_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_2_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_2_min_comp << endl;

}


void save_q_dotdot_3_min_comp(double q_dotdot_3_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_3_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_3_min_comp << endl;

}


void save_q_dotdot_4_min_comp(double q_dotdot_4_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_4_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_4_min_comp << endl;

}


void save_q_dotdot_5_min_comp(double q_dotdot_5_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_5_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_5_min_comp << endl;

}


void save_q_dotdot_6_min_comp(double q_dotdot_6_min_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_6_min_comp.txt", std::ios_base::app);
    outputfile << q_dotdot_6_min_comp << endl;

}






//save q_dot_bounds_max_comp_Acc_Posi_vel_cmd
void save_q_dot_bounds_max_comp_Acc_Posi_vel_cmd(double q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0) 
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0.txt", std::ios_base::app);
    outputfile << q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 << endl;

}
void save_q_dot_bounds_min_comp_Acc_Posi_vel_cmd(double q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0.txt", std::ios_base::app);
    outputfile << q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0 << endl;

}











//Distance entre les differents segments du robot et l'obstacle le plus proche
void save_d_07_ob(double d_07_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_07_ob.txt", std::ios_base::app);
    outputfile << d_07_ob << endl;

}


void save_d_06_ob(double d_06_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_06_ob.txt", std::ios_base::app);
    outputfile << d_06_ob << endl;

}


void save_d_05_ob(double d_05_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_05_ob.txt", std::ios_base::app);
    outputfile << d_05_ob << endl;

}


void save_d_04_ob(double d_04_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_04_ob.txt", std::ios_base::app);
    outputfile << d_04_ob << endl;

}


void save_d_03_ob(double d_03_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_03_ob.txt", std::ios_base::app);
    outputfile << d_03_ob << endl;

}


void save_d_02_ob(double d_02_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/d_02_ob.txt", std::ios_base::app);
    outputfile << d_02_ob << endl;

}





void save_V_7(double V_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7.txt", std::ios_base::app);
    outputfile << V_7 << endl;

}

void save_V_7_x(double V_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_x.txt", std::ios_base::app);
    outputfile << V_7_x << endl;

}

void save_V_7_y(double V_7_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_y.txt", std::ios_base::app);
    outputfile << V_7_y << endl;

}

void save_V_7_z(double V_7_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_z.txt", std::ios_base::app);
    outputfile << V_7_z << endl;

}












void save_V_7_des_0(double V_7_des_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_0.txt", std::ios_base::app);
    outputfile << V_7_des_0 << endl;

}


void save_V_7_des_x_0(double V_7_des_x_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_x_0.txt", std::ios_base::app);
    outputfile << V_7_des_x_0 << endl;

}


void save_V_7_des_y_0(double V_7_des_y_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_y_0.txt", std::ios_base::app);
    outputfile << V_7_des_y_0 << endl;

}

void save_V_7_des_z_0(double V_7_des_z_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_z_0.txt", std::ios_base::app);
    outputfile << V_7_des_z_0 << endl;

}







void save_V_7_des(double V_7_des)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des.txt", std::ios_base::app);
    outputfile << V_7_des << endl;

}


void save_V_7_des_x(double V_7_des_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_x.txt", std::ios_base::app);
    outputfile << V_7_des_x << endl;

}


void save_V_7_des_y(double V_7_des_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_y.txt", std::ios_base::app);
    outputfile << V_7_des_y << endl;

}

void save_V_7_des_z(double V_7_des_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_des_z.txt", std::ios_base::app);
    outputfile << V_7_des_z << endl;

}






void save_Acc_7_des_0(double Acc_7_des_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_0.txt", std::ios_base::app);
    outputfile << Acc_7_des_0 << endl;

}

void save_Acc_7_des_0_x(double Acc_7_des_0_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_0_x.txt", std::ios_base::app);
    outputfile << Acc_7_des_0_x << endl;

}

void save_Acc_7_des_0_y(double Acc_7_des_0_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_0_y.txt", std::ios_base::app);
    outputfile << Acc_7_des_0_y << endl;

}

void save_Acc_7_des_0_z(double Acc_7_des_0_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_0_z.txt", std::ios_base::app);
    outputfile << Acc_7_des_0_z << endl;

}





void save_Acc_7_des(double Acc_7_des)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des.txt", std::ios_base::app);
    outputfile << Acc_7_des << endl;

}

void save_Acc_7_des_x(double Acc_7_des_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_x.txt", std::ios_base::app);
    outputfile << Acc_7_des_x << endl;

}

void save_Acc_7_des_y(double Acc_7_des_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_y.txt", std::ios_base::app);
    outputfile << Acc_7_des_y << endl;

}

void save_Acc_7_des_z(double Acc_7_des_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_des_z.txt", std::ios_base::app);
    outputfile << Acc_7_des_z << endl;

}



void save_small_err(double small_err)
{
    ofstream outputfile;
    outputfile.open("saved_data/small_err.txt", std::ios_base::app);
    outputfile << small_err << endl;

}







void save_Jerk_7_des(double Jerk_7_des)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_des.txt", std::ios_base::app);
    outputfile << Jerk_7_des << endl;

}

void save_Jerk_7_des_x(double Jerk_7_des_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_des_x.txt", std::ios_base::app);
    outputfile << Jerk_7_des_x << endl;

}

void save_Jerk_7_des_y(double Jerk_7_des_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_des_y.txt", std::ios_base::app);
    outputfile << Jerk_7_des_y << endl;

}

void save_Jerk_7_des_z(double Jerk_7_des_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_des_z.txt", std::ios_base::app);
    outputfile << Jerk_7_des_z << endl;

}






void save_Acc_7(double Acc_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7.txt", std::ios_base::app);
    outputfile << Acc_7 << endl;

}

void save_Acc_7_x(double Acc_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_x.txt", std::ios_base::app);
    outputfile << Acc_7_x << endl;

}



void save_F_7_x(double F_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/F_7_x.txt", std::ios_base::app);
    outputfile << F_7_x << endl;

}



void save_Acc_7_y(double Acc_7_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_y.txt", std::ios_base::app);
    outputfile << Acc_7_y << endl;

}

void save_Acc_7_z(double Acc_7_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_z.txt", std::ios_base::app);
    outputfile << Acc_7_z << endl;

}






void save_Jerk_7(double Jerk_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7.txt", std::ios_base::app);
    outputfile << Jerk_7 << endl;

}

void save_Jerk_7_x(double Jerk_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_x.txt", std::ios_base::app);
    outputfile << Jerk_7_x << endl;

}

void save_Jerk_7_y(double Jerk_7_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_y.txt", std::ios_base::app);
    outputfile << Jerk_7_y << endl;

}

void save_Jerk_7_z(double Jerk_7_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_7_z.txt", std::ios_base::app);
    outputfile << Jerk_7_z << endl;

}








void save_q(double q_0, double q_1, double q_2, double q_3, double q_4, double q_5, double q_6)
{
    ofstream outputfile1;
    outputfile1.open("saved_data/q_0.txt", std::ios_base::app);
    outputfile1 << q_0 << endl;


    ofstream outputfile2;
    outputfile2.open("saved_data/q_1.txt", std::ios_base::app);
    outputfile2 << q_1 << endl;


    ofstream outputfile3;
    outputfile3.open("saved_data/q_2.txt", std::ios_base::app);
    outputfile3 << q_2 << endl;


    ofstream outputfile4;
    outputfile4.open("saved_data/q_3.txt", std::ios_base::app);
    outputfile4 << q_3 << endl;


    ofstream outputfile5;
    outputfile5.open("saved_data/q_4.txt", std::ios_base::app);
    outputfile5 << q_4 << endl;


    ofstream outputfile6;
    outputfile6.open("saved_data/q_5.txt", std::ios_base::app);
    outputfile6 << q_5 << endl;


    ofstream outputfile7;
    outputfile7.open("saved_data/q_6.txt", std::ios_base::app);
    outputfile7 << q_6 << endl;
}







void save_q_dot(double q_dot_0, double q_dot_1, double q_dot_2, double q_dot_3, double q_dot_4, double q_dot_5, double q_dot_6)
{
    ofstream outputfile1;
    outputfile1.open("saved_data/q_dot_0.txt", std::ios_base::app);
    outputfile1 << q_dot_0 << endl;


    ofstream outputfile2;
    outputfile2.open("saved_data/q_dot_1.txt", std::ios_base::app);
    outputfile2 << q_dot_1 << endl;


    ofstream outputfile3;
    outputfile3.open("saved_data/q_dot_2.txt", std::ios_base::app);
    outputfile3 << q_dot_2 << endl;


    ofstream outputfile4;
    outputfile4.open("saved_data/q_dot_3.txt", std::ios_base::app);
    outputfile4 << q_dot_3 << endl;


    ofstream outputfile5;
    outputfile5.open("saved_data/q_dot_4.txt", std::ios_base::app);
    outputfile5 << q_dot_4 << endl;


    ofstream outputfile6;
    outputfile6.open("saved_data/q_dot_5.txt", std::ios_base::app);
    outputfile6 << q_dot_5 << endl;


    ofstream outputfile7;
    outputfile7.open("saved_data/q_dot_6.txt", std::ios_base::app);
    outputfile7 << q_dot_6 << endl;
}










//Save q max
void save_q_0_max(double q_0_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_0_max.txt", std::ios_base::app);
    outputfile << q_0_max << endl;

}


void save_q_1_max(double q_1_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_1_max.txt", std::ios_base::app);
    outputfile << q_1_max << endl;

}


void save_q_2_max(double q_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_2_max.txt", std::ios_base::app);
    outputfile << q_2_max << endl;

}


void save_q_3_max(double q_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_3_max.txt", std::ios_base::app);
    outputfile << q_3_max << endl;

}


void save_q_4_max(double q_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_4_max.txt", std::ios_base::app);
    outputfile << q_4_max << endl;

}


void save_q_5_max(double q_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_5_max.txt", std::ios_base::app);
    outputfile << q_5_max << endl;

}


void save_q_6_max(double q_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_6_max.txt", std::ios_base::app);
    outputfile << q_6_max << endl;

}








//Save q min
void save_q_0_min(double q_0_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_0_min.txt", std::ios_base::app);
    outputfile << q_0_min << endl;

}


void save_q_1_min(double q_1_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_1_min.txt", std::ios_base::app);
    outputfile << q_1_min << endl;

}


void save_q_2_min(double q_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_2_min.txt", std::ios_base::app);
    outputfile << q_2_min << endl;

}


void save_q_3_min(double q_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_3_min.txt", std::ios_base::app);
    outputfile << q_3_min << endl;

}


void save_q_4_min(double q_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_4_min.txt", std::ios_base::app);
    outputfile << q_4_min << endl;

}


void save_q_5_min(double q_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_5_min.txt", std::ios_base::app);
    outputfile << q_5_min << endl;

}


void save_q_6_min(double q_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_6_min.txt", std::ios_base::app);
    outputfile << q_6_min << endl;

}



//Save q_dot max
void save_q_dot_0_max(double q_dot_0_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_0_max.txt", std::ios_base::app);
    outputfile << q_dot_0_max << endl;

}


void save_q_dot_1_max(double q_dot_1_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_1_max.txt", std::ios_base::app);
    outputfile << q_dot_1_max << endl;

}


void save_q_dot_2_max(double q_dot_2_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_2_max.txt", std::ios_base::app);
    outputfile << q_dot_2_max << endl;

}


void save_q_dot_3_max(double q_dot_3_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_3_max.txt", std::ios_base::app);
    outputfile << q_dot_3_max << endl;

}


void save_q_dot_4_max(double q_dot_4_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_4_max.txt", std::ios_base::app);
    outputfile << q_dot_4_max << endl;

}


void save_q_dot_5_max(double q_dot_5_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_5_max.txt", std::ios_base::app);
    outputfile << q_dot_5_max << endl;

}


void save_q_dot_6_max(double q_dot_6_max)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_6_max.txt", std::ios_base::app);
    outputfile << q_dot_6_max << endl;

}








//Save q_dot min
void save_q_dot_0_min(double q_dot_0_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_0_min.txt", std::ios_base::app);
    outputfile << q_dot_0_min << endl;

}


void save_q_dot_1_min(double q_dot_1_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_1_min.txt", std::ios_base::app);
    outputfile << q_dot_1_min << endl;

}


void save_q_dot_2_min(double q_dot_2_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_2_min.txt", std::ios_base::app);
    outputfile << q_dot_2_min << endl;

}


void save_q_dot_3_min(double q_dot_3_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_3_min.txt", std::ios_base::app);
    outputfile << q_dot_3_min << endl;

}


void save_q_dot_4_min(double q_dot_4_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_4_min.txt", std::ios_base::app);
    outputfile << q_dot_4_min << endl;

}


void save_q_dot_5_min(double q_dot_5_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_5_min.txt", std::ios_base::app);
    outputfile << q_dot_5_min << endl;

}


void save_q_dot_6_min(double q_dot_6_min)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dot_6_min.txt", std::ios_base::app);
    outputfile << q_dot_6_min << endl;

}








void save_X_err_0(double X_err_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_0.txt", std::ios_base::app);
    outputfile << X_err_0 << endl;

}

void save_X_err_x_0(double X_err_x_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_x_0.txt", std::ios_base::app);
    outputfile << X_err_x_0 << endl;

}

void save_X_err_y_0(double X_err_y_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_y_0.txt", std::ios_base::app);
    outputfile << X_err_y_0 << endl;

}

void save_X_err_z_0(double X_err_z_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_z_0.txt", std::ios_base::app);
    outputfile << X_err_z_0 << endl;

}




void save_X_err(double X_err)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err.txt", std::ios_base::app);
    outputfile << X_err << endl;

}

void save_X_err_x(double X_err_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_x.txt", std::ios_base::app);
    outputfile << X_err_x << endl;

}

void save_X_err_y(double X_err_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_y.txt", std::ios_base::app);
    outputfile << X_err_y << endl;

}

void save_X_err_z(double X_err_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_err_z.txt", std::ios_base::app);
    outputfile << X_err_z << endl;

}




void save_real_step_time(double real_step_time)
{
    ofstream outputfile;
    outputfile.open("saved_data/real_step_time.txt", std::ios_base::app);
    outputfile << real_step_time << endl;
}


void save_fixed_dt(double fixed_dt)
{
    ofstream outputfile;
    outputfile.open("saved_data/fixed_dt.txt", std::ios_base::app);
    outputfile << fixed_dt << endl;
}


void save_V_7_ob(double V_7_ob_sgn_norm)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_ob_sgn_norm.txt", std::ios_base::app);
    outputfile << V_7_ob_sgn_norm << endl;
}



void save_E_7_C_ob(double E_7_C_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_7_C_ob.txt", std::ios_base::app);
    outputfile << E_7_C_ob << endl;
}



void save_E_7_C_ob_diff_comp(double E_7_C_ob_diff_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_7_C_ob_diff_comp.txt", std::ios_base::app);
    outputfile << E_7_C_ob_diff_comp << endl;
}


void save_V_7_C_ob(double V_7_C_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_C_ob.txt", std::ios_base::app);
    outputfile << V_7_C_ob << endl;
}

void save_V_7_C_ob_diff_comp(double V_7_C_ob_diff_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_C_ob_diff_comp.txt", std::ios_base::app);
    outputfile << V_7_C_ob_diff_comp << endl;
}






void save_V_7_C_ob_t2(double V_7_C_ob_t2)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_C_ob_t2.txt", std::ios_base::app);
    outputfile << V_7_C_ob_t2 << endl;
}




void save_V_7_C_ob_QP_side(double V_7_C_ob_QP_side)
{
    ofstream outputfile;
    outputfile.open("saved_data/V_7_C_ob_QP_side.txt", std::ios_base::app);
    outputfile << V_7_C_ob_QP_side << endl;
}



void save_E_7_reconstructed_with_V_7_t2(double E_7_reconstructed_with_V_7_t2)
{
    ofstream outputfile;
    outputfile.open("saved_data/E_7_reconstructed_with_V_7_t2.txt", std::ios_base::app);
    outputfile << E_7_reconstructed_with_V_7_t2 << endl;
}


void save_Real_Ec_7_x(double Real_Ec_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Real_Ec_7_x.txt", std::ios_base::app);
    outputfile << Real_Ec_7_x << endl;
}



void save_Ec_7_x_nxt_step(double Ec_7_x_nxt_step)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_7_x_nxt_step.txt", std::ios_base::app);
    outputfile << Ec_7_x_nxt_step << endl;
}



void save_Ec_7_x(double Ec_7_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Ec_7_x.txt", std::ios_base::app);
    outputfile << Ec_7_x << endl;
}



void save_Acc_7_x_nxt_step_limit(double Acc_7_x_nxt_step_limit)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_x_nxt_step_limit.txt", std::ios_base::app);
    outputfile << Acc_7_x_nxt_step_limit << endl;
}





void save_sgn_V_7_C_ob(double sgn_V_7_C_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/sgn_V_7_C_ob.txt", std::ios_base::app);
    outputfile << sgn_V_7_C_ob << endl;
}


void save_sgn_V_7_C_ob_diff_comp(double sgn_V_7_C_ob_diff_comp)
{
    ofstream outputfile;
    outputfile.open("saved_data/sgn_V_7_C_ob_diff_comp.txt", std::ios_base::app);
    outputfile << sgn_V_7_C_ob_diff_comp << endl;
}




void save_sgn_V_7_C_ob_t2(double sgn_V_7_C_ob_t2)
{
    ofstream outputfile;
    outputfile.open("saved_data/sgn_V_7_C_ob_t2.txt", std::ios_base::app);
    outputfile << sgn_V_7_C_ob_t2 << endl;
}




void save_acos_n_7_0(double acos_n_7_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/acos_n_7_0.txt", std::ios_base::app);
    outputfile << acos_n_7_0 << endl;
}


void save_angle_V_7_to_nrst_dist_ob(double angle_V_7_to_nrst_dist_ob)
{
    ofstream outputfile;
    outputfile.open("saved_data/angle_V_7_to_nrst_dist_ob.txt", std::ios_base::app);
    outputfile << angle_V_7_to_nrst_dist_ob << endl;
}



void save_norm_axis_of_rot_angle_7(double norm_axis_of_rot_angle_7)
{
    ofstream outputfile;
    outputfile.open("saved_data/norm_axis_of_rot_angle_7.txt", std::ios_base::app);
    outputfile << norm_axis_of_rot_angle_7 << endl;
}






void save_dynamic(double dynamic_1, double dynamic_2, double dynamic_3, double dynamic_4, double dynamic_5, double dynamic_6, double dynamic_7){

    ofstream outputfile;
    outputfile.open("saved_data/dynamic_1.txt", std::ios_base::app);
    outputfile << dynamic_1 << endl;


    ofstream outputfile2;
    outputfile2.open("saved_data/dynamic_2.txt", std::ios_base::app);
    outputfile2 << dynamic_2 << endl;


    ofstream outputfile3;
    outputfile3.open("saved_data/dynamic_3.txt", std::ios_base::app);
    outputfile3 << dynamic_3 << endl;


    ofstream outputfile4;
    outputfile4.open("saved_data/dynamic_4.txt", std::ios_base::app);
    outputfile4 << dynamic_4 << endl;


    ofstream outputfile5;
    outputfile5.open("saved_data/dynamic_5.txt", std::ios_base::app);
    outputfile5 << dynamic_5 << endl;


    ofstream outputfile6;
    outputfile6.open("saved_data/dynamic_6.txt", std::ios_base::app);
    outputfile6 << dynamic_6 << endl;


    ofstream outputfile7;
    outputfile7.open("saved_data/dynamic_7.txt", std::ios_base::app);
    outputfile7 << dynamic_7 << endl;

}




void save_M_q_dotdot_0(double M_q_dotdot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_0.txt", std::ios_base::app);
    outputfile << M_q_dotdot_0 << endl;
}

void save_M_q_dotdot_1(double M_q_dotdot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_1.txt", std::ios_base::app);
    outputfile << M_q_dotdot_1 << endl;
}

void save_M_q_dotdot_2(double M_q_dotdot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_2.txt", std::ios_base::app);
    outputfile << M_q_dotdot_2 << endl;
}

void save_M_q_dotdot_3(double M_q_dotdot_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_3.txt", std::ios_base::app);
    outputfile << M_q_dotdot_3 << endl;
}

void save_M_q_dotdot_4(double M_q_dotdot_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_4.txt", std::ios_base::app);
    outputfile << M_q_dotdot_4 << endl;
}

void save_M_q_dotdot_5(double M_q_dotdot_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_5.txt", std::ios_base::app);
    outputfile << M_q_dotdot_5 << endl;
}

void save_M_q_dotdot_6(double M_q_dotdot_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/M_q_dotdot_6.txt", std::ios_base::app);
    outputfile << M_q_dotdot_6 << endl;
}



void save_b_0(double b_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_0.txt", std::ios_base::app);
    outputfile << b_0 << endl;
}

void save_b_1(double b_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_1.txt", std::ios_base::app);
    outputfile << b_1 << endl;
}

void save_b_2(double b_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_2.txt", std::ios_base::app);
    outputfile << b_2 << endl;
}

void save_b_3(double b_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_3.txt", std::ios_base::app);
    outputfile << b_3 << endl;
}

void save_b_4(double b_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_4.txt", std::ios_base::app);
    outputfile << b_4 << endl;
}

void save_b_5(double b_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_5.txt", std::ios_base::app);
    outputfile << b_5 << endl;
}

void save_b_6(double b_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/b_6.txt", std::ios_base::app);
    outputfile << b_6 << endl;
}






void save_X_dot_dot_des_0(double X_dot_dot_des_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_0.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_0 << endl;
}

void save_X_dot_dot_des_0_x(double X_dot_dot_des_0_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_0_x.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_0_x << endl;
}

void save_X_dot_dot_des_0_y(double X_dot_dot_des_0_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_0_y.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_0_y << endl;
}

void save_X_dot_dot_des_0_z(double X_dot_dot_des_0_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_0_z.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_0_z << endl;
}









void save_X_dot_dot_des(double X_dot_dot_des)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des.txt", std::ios_base::app);
    outputfile << X_dot_dot_des << endl;
}

void save_X_dot_dot_des_x(double X_dot_dot_des_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_x.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_x << endl;
}

void save_X_dot_dot_des_y(double X_dot_dot_des_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_y.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_y << endl;
}

void save_X_dot_dot_des_z(double X_dot_dot_des_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_des_z.txt", std::ios_base::app);
    outputfile << X_dot_dot_des_z << endl;
}






void save_X_dot_dot(double X_dot_dot)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot.txt", std::ios_base::app);
    outputfile << X_dot_dot << endl;
}

void save_X_dot_dot_x(double X_dot_dot_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_x.txt", std::ios_base::app);
    outputfile << X_dot_dot_x << endl;
}

void save_X_dot_dot_y(double X_dot_dot_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_y.txt", std::ios_base::app);
    outputfile << X_dot_dot_y << endl;
}

void save_X_dot_dot_z(double X_dot_dot_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/X_dot_dot_z.txt", std::ios_base::app);
    outputfile << X_dot_dot_z << endl;
}









void save_kp_X_err_0(double kp_X_err_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/kp_X_err_0.txt", std::ios_base::app);
    outputfile << kp_X_err_0 << endl;
}

void save_kp_X_err_1(double kp_X_err_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/kp_X_err_1.txt", std::ios_base::app);
    outputfile << kp_X_err_1 << endl;
}

void save_kp_X_err_2(double kp_X_err_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/kp_X_err_2.txt", std::ios_base::app);
    outputfile << kp_X_err_2 << endl;
}








void save_kd_V_7_l_0(double kd_V_7_l_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/kd_V_7_l_0.txt", std::ios_base::app);
    outputfile << kd_V_7_l_0 << endl;
}

void save_kd_V_7_l_1(double kd_V_7_l_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/kd_V_7_l_1.txt", std::ios_base::app);
    outputfile << kd_V_7_l_1 << endl;
}

void save_kd_V_7_l_2(double kd_V_7_l_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/kd_V_7_l_2.txt", std::ios_base::app);
    outputfile << kd_V_7_l_2 << endl;
}




void save_rank_J_70_l(double rank_J_70_l)
{
    ofstream outputfile;
    outputfile.open("saved_data/rank_J_70_l.txt", std::ios_base::app);
    outputfile << rank_J_70_l << endl;
}



void save_t_1(double t_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_1.txt", std::ios_base::app);
    outputfile << t_1 << endl;
}






void save_s_x(double s_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_x.txt", std::ios_base::app);
    outputfile << s_x << endl;
}

void save_s_y(double s_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_y.txt", std::ios_base::app);
    outputfile << s_y << endl;
}

void save_s_z(double s_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_z.txt", std::ios_base::app);
    outputfile << s_z << endl;
}

void save_s_alpha(double s_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_alpha.txt", std::ios_base::app);
    outputfile << s_alpha << endl;
}

void save_s_beta(double s_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_beta.txt", std::ios_base::app);
    outputfile << s_beta << endl;
}

void save_s_gamma(double s_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_gamma.txt", std::ios_base::app);
    outputfile << s_gamma << endl;
}



void save_s_dot_x(double s_dot_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_x.txt", std::ios_base::app);
    outputfile << s_dot_x << endl;
}

void save_s_dot_y(double s_dot_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_y.txt", std::ios_base::app);
    outputfile << s_dot_y << endl;
}

void save_s_dot_z(double s_dot_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_z.txt", std::ios_base::app);
    outputfile << s_dot_z << endl;
}

void save_s_dot_alpha(double s_dot_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_alpha.txt", std::ios_base::app);
    outputfile << s_dot_alpha << endl;
}


void save_s_dot_beta(double s_dot_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_beta.txt", std::ios_base::app);
    outputfile << s_dot_beta << endl;
}

void save_s_dot_gamma(double s_dot_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_gamma.txt", std::ios_base::app);
    outputfile << s_dot_gamma << endl;
}









void save_s_dot_dot_x(double s_dot_dot_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_x.txt", std::ios_base::app);
    outputfile << s_dot_dot_x << endl;
}

void save_s_dot_dot_y(double s_dot_dot_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_y.txt", std::ios_base::app);
    outputfile << s_dot_dot_y << endl;
}

void save_s_dot_dot_z(double s_dot_dot_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_z.txt", std::ios_base::app);
    outputfile << s_dot_dot_z << endl;
}

void save_s_dot_dot_alpha(double s_dot_dot_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_alpha.txt", std::ios_base::app);
    outputfile << s_dot_dot_alpha << endl;
}

void save_s_dot_dot_beta(double s_dot_dot_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_beta.txt", std::ios_base::app);
    outputfile << s_dot_dot_beta << endl;
}

void save_s_dot_dot_gamma(double s_dot_dot_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_gamma.txt", std::ios_base::app);
    outputfile << s_dot_dot_gamma << endl;
}





void save_s_dot_dot_dot_x(double s_dot_dot_dot_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_x.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_x << endl;
}

void save_s_dot_dot_dot_y(double s_dot_dot_dot_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_y.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_y << endl;
}

void save_s_dot_dot_dot_z(double s_dot_dot_dot_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_z.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_z << endl;
}

void save_s_dot_dot_dot_alpha(double s_dot_dot_dot_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_alpha.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_alpha << endl;
}

void save_s_dot_dot_dot_beta(double s_dot_dot_dot_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_beta.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_beta << endl;
}

void save_s_dot_dot_dot_gamma(double s_dot_dot_dot_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_gamma.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_gamma << endl;
}







void save_T_x(double T_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_x.txt", std::ios_base::app);
    outputfile << T_x << endl;
}

void save_T_y(double T_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_y.txt", std::ios_base::app);
    outputfile << T_y << endl;
}

void save_T_z(double T_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_z.txt", std::ios_base::app);
    outputfile << T_z << endl;
}




void save_t_2_x(double t_2_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_x.txt", std::ios_base::app);
    outputfile << t_2_x << endl;
}

void save_t_2_y(double t_2_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_y.txt", std::ios_base::app);
    outputfile << t_2_y << endl;
}

void save_t_2_z(double t_2_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_z.txt", std::ios_base::app);
    outputfile << t_2_z << endl;
}


void save_t_2_alpha(double t_2_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_alpha.txt", std::ios_base::app);
    outputfile << t_2_alpha << endl;
}

void save_t_2_beta(double t_2_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_beta.txt", std::ios_base::app);
    outputfile << t_2_beta << endl;
}

void save_t_2_gamma(double t_2_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_gamma.txt", std::ios_base::app);
    outputfile << t_2_gamma << endl;
}





void save_K_p_X_err(double K_p_X_err)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_p_X_err.txt", std::ios_base::app);
    outputfile << K_p_X_err << endl;
}

void save_K_p_X_err_0(double K_p_X_err_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_p_X_err_0.txt", std::ios_base::app);
    outputfile << K_p_X_err_0 << endl;
}

void save_K_p_X_err_1(double K_p_X_err_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_p_X_err_1.txt", std::ios_base::app);
    outputfile << K_p_X_err_1 << endl;
}

void save_K_p_X_err_2(double K_p_X_err_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_p_X_err_2.txt", std::ios_base::app);
    outputfile << K_p_X_err_2 << endl;
}





void save_K_d_V_7_err(double K_d_V_7_err)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_d_V_7_err.txt", std::ios_base::app);
    outputfile << K_d_V_7_err << endl;
}

void save_K_d_V_7_err_0(double K_d_V_7_err_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_d_V_7_err_0.txt", std::ios_base::app);
    outputfile << K_d_V_7_err_0 << endl;
}

void save_K_d_V_7_err_1(double K_d_V_7_err_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_d_V_7_err_1.txt", std::ios_base::app);
    outputfile << K_d_V_7_err_1 << endl;
}

void save_K_d_V_7_err_2(double K_d_V_7_err_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/K_d_V_7_err_2.txt", std::ios_base::app);
    outputfile << K_d_V_7_err_2 << endl;
}







void save_Acc_7_err(double Acc_7_err)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_err.txt", std::ios_base::app);
    outputfile << Acc_7_err << endl;

}

void save_Acc_7_err_x(double Acc_7_err_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_err_x.txt", std::ios_base::app);
    outputfile << Acc_7_err_x << endl;

}

void save_Acc_7_err_y(double Acc_7_err_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_err_y.txt", std::ios_base::app);
    outputfile << Acc_7_err_y << endl;

}

void save_Acc_7_err_z(double Acc_7_err_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_err_z.txt", std::ios_base::app);
    outputfile << Acc_7_err_z << endl;
}




void save_Diff_X_dot_dot_Acc_7_des(double Diff_X_dot_dot_Acc_7_des)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_Acc_7_des.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_Acc_7_des << endl;

}

void save_Diff_X_dot_dot_Acc_7_des_x(double Diff_X_dot_dot_Acc_7_des_x)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_Acc_7_des_x.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_Acc_7_des_x << endl;

}

void save_Diff_X_dot_dot_Acc_7_des_y(double Diff_X_dot_dot_Acc_7_des_y)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_Acc_7_des_y.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_Acc_7_des_y << endl;

}

void save_Diff_X_dot_dot_Acc_7_des_z(double Diff_X_dot_dot_Acc_7_des_z)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_Acc_7_des_z.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_Acc_7_des_z << endl;

}








void save_Diff_X_dot_dot_des_Jdot_qdot_rot(double Diff_X_dot_dot_des_Jdot_qdot_rot)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_des_Jdot_qdot_rot.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_des_Jdot_qdot_rot << endl;

}

void save_Diff_X_dot_dot_des_Jdot_qdot_rot_0(double Diff_X_dot_dot_des_Jdot_qdot_rot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_des_Jdot_qdot_rot_0.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_des_Jdot_qdot_rot_0 << endl;

}

void save_Diff_X_dot_dot_des_Jdot_qdot_rot_1(double Diff_X_dot_dot_des_Jdot_qdot_rot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_des_Jdot_qdot_rot_1.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_des_Jdot_qdot_rot_1 << endl;

}

void save_Diff_X_dot_dot_des_Jdot_qdot_rot_2(double Diff_X_dot_dot_des_Jdot_qdot_rot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/Diff_X_dot_dot_des_Jdot_qdot_rot_2.txt", std::ios_base::app);
    outputfile << Diff_X_dot_dot_des_Jdot_qdot_rot_2 << endl;

}











void save_s_angle(double s_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_angle.txt", std::ios_base::app);
    outputfile << s_angle << endl;
}

void save_s_dot_angle(double s_dot_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_angle.txt", std::ios_base::app);
    outputfile << s_dot_angle << endl;
}

void save_s_dot_dot_angle(double s_dot_dot_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_angle.txt", std::ios_base::app);
    outputfile << s_dot_dot_angle << endl;
}

void save_s_dot_dot_dot_angle(double s_dot_dot_dot_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/s_dot_dot_dot_angle.txt", std::ios_base::app);
    outputfile << s_dot_dot_dot_angle << endl;
}


void save_T_angle(double T_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_angle.txt", std::ios_base::app);
    outputfile << T_angle << endl;
}

void save_t_2_angle(double t_2_angle)
{
    ofstream outputfile;
    outputfile.open("saved_data/t_2_angle.txt", std::ios_base::app);
    outputfile << t_2_angle << endl;
}






void save_T_alpha(double T_alpha)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_alpha.txt", std::ios_base::app);
    outputfile << T_alpha << endl;
}

void save_T_beta(double T_beta)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_beta.txt", std::ios_base::app);
    outputfile << T_beta << endl;
}

void save_T_gamma(double T_gamma)
{
    ofstream outputfile;
    outputfile.open("saved_data/T_gamma.txt", std::ios_base::app);
    outputfile << T_gamma << endl;
}




void save_des_trajectory_angle(double nxt_step_des_angle){
    ofstream outputfile;
    outputfile.open("saved_data/nxt_step_des_angle.txt", std::ios_base::app);
    outputfile << nxt_step_des_angle << endl;
}

void save_trajectory_angle(double angle_curr_rot){
    ofstream outputfile;
    outputfile.open("saved_data/angle_curr_rot.txt", std::ios_base::app);
    outputfile << angle_curr_rot << endl;
}

void save_Acc_7_angle(double Acc_angle_curr_rot){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_angle_curr_rot.txt", std::ios_base::app);
    outputfile << Acc_angle_curr_rot << endl;
}

void save_Jerk_7_angle(double Jerk_angle_curr_rot){
    ofstream outputfile;
    outputfile.open("saved_data/Jerk_angle_curr_rot.txt", std::ios_base::app);
    outputfile << Jerk_angle_curr_rot << endl;
}

void save_V_7_angle(double V_angle_curr_rot){
    ofstream outputfile;
    outputfile.open("saved_data/V_angle_curr_rot.txt", std::ios_base::app);
    outputfile << V_angle_curr_rot << endl;
}

void save_V_7_des_angle(double nxt_step_des_V_7_angle){
    ofstream outputfile;
    outputfile.open("saved_data/nxt_step_des_V_7_angle.txt", std::ios_base::app);
    outputfile << nxt_step_des_V_7_angle << endl;
}

void save_Acc_7_des_angle(double nxt_step_des_Acc_7_angle){
    ofstream outputfile;
    outputfile.open("saved_data/nxt_step_des_Acc_7_angle.txt", std::ios_base::app);
    outputfile << nxt_step_des_Acc_7_angle << endl;
}

void save_Jerk_7_des_angle(double nxt_step_des_Jerk_7_angle){
    ofstream outputfile;
    outputfile.open("saved_data/nxt_step_des_Jerk_7_angle.txt", std::ios_base::app);
    outputfile << nxt_step_des_Jerk_7_angle << endl;
}



void save_X_err_orient_0(double X_err_orient_0){
    ofstream outputfile;
    outputfile.open("saved_data/X_err_orient_0.txt", std::ios_base::app);
    outputfile << X_err_orient_0 << endl;
}


void save_X_err_orient_1(double X_err_orient_1){
    ofstream outputfile;
    outputfile.open("saved_data/X_err_orient_1.txt", std::ios_base::app);
    outputfile << X_err_orient_1 << endl;
}


void save_X_err_orient_2(double X_err_orient_2){
    ofstream outputfile;
    outputfile.open("saved_data/X_err_orient_2.txt", std::ios_base::app);
    outputfile << X_err_orient_2 << endl;
}


void save_X_err_orient(double norme_X_err_orient){
    ofstream outputfile;
    outputfile.open("saved_data/norme_X_err_orient.txt", std::ios_base::app);
    outputfile << norme_X_err_orient << endl;
}



void save_Err_interpolation_aggle(double Err_interpolation_aggle){
    ofstream outputfile;
    outputfile.open("saved_data/Err_interpolation_aggle.txt", std::ios_base::app);
    outputfile << Err_interpolation_aggle << endl;
}










void save_norme_Acc_7_orient(double norme_Acc_7_orient){
    ofstream outputfile;
    outputfile.open("saved_data/norme_Acc_7_orient.txt", std::ios_base::app);
    outputfile << norme_Acc_7_orient << endl;
}


void save_Acc_7_orient_0(double Acc_7_orient_0){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_0.txt", std::ios_base::app);
    outputfile << Acc_7_orient_0 << endl;
}

void save_Acc_7_orient_1(double Acc_7_orient_1){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_1.txt", std::ios_base::app);
    outputfile << Acc_7_orient_1 << endl;
}

void save_Acc_7_orient_2(double Acc_7_orient_2){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_2.txt", std::ios_base::app);
    outputfile << Acc_7_orient_2 << endl;
}



void save_norme_Acc_7_orient_des(double norme_Acc_7_orient_des){
    ofstream outputfile;
    outputfile.open("saved_data/norme_Acc_7_orient_des.txt", std::ios_base::app);
    outputfile << norme_Acc_7_orient_des << endl;
}

void save_Acc_7_orient_des_0(double Acc_7_orient_des_0){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_des_0.txt", std::ios_base::app);
    outputfile << Acc_7_orient_des_0 << endl;
}

void save_Acc_7_orient_des_1(double Acc_7_orient_des_1){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_des_1.txt", std::ios_base::app);
    outputfile << Acc_7_orient_des_1 << endl;
}

void save_Acc_7_orient_des_2(double Acc_7_orient_des_2){
    ofstream outputfile;
    outputfile.open("saved_data/Acc_7_orient_des_2.txt", std::ios_base::app);
    outputfile << Acc_7_orient_des_2 << endl;
}







void save_norme_V_7_orient(double norme_V_7_orient){
    ofstream outputfile;
    outputfile.open("saved_data/norme_V_7_orient.txt", std::ios_base::app);
    outputfile << norme_V_7_orient << endl;
}


void save_V_7_orient_0(double V_7_orient_0){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_0.txt", std::ios_base::app);
    outputfile << V_7_orient_0 << endl;
}

void save_V_7_orient_1(double V_7_orient_1){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_1.txt", std::ios_base::app);
    outputfile << V_7_orient_1 << endl;
}

void save_V_7_orient_2(double V_7_orient_2){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_2.txt", std::ios_base::app);
    outputfile << V_7_orient_2 << endl;
}


void save_norme_V_7_orient_des(double norme_V_7_orient_des){
    ofstream outputfile;
    outputfile.open("saved_data/norme_V_7_orient_des.txt", std::ios_base::app);
    outputfile << norme_V_7_orient_des << endl;
}

void save_V_7_orient_des_0(double V_7_orient_des_0){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_des_0.txt", std::ios_base::app);
    outputfile << V_7_orient_des_0 << endl;
}

void save_V_7_orient_des_1(double V_7_orient_des_1){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_des_1.txt", std::ios_base::app);
    outputfile << V_7_orient_des_1 << endl;
}

void save_V_7_orient_des_2(double V_7_orient_des_2){
    ofstream outputfile;
    outputfile.open("saved_data/V_7_orient_des_2.txt", std::ios_base::app);
    outputfile << V_7_orient_des_2 << endl;
}








void save_norme_angle_curr_rot_prj(double norme_angle_curr_rot_prj){
    ofstream outputfile;
    outputfile.open("saved_data/norme_angle_curr_rot_prj.txt", std::ios_base::app);
    outputfile << norme_angle_curr_rot_prj << endl;
}


void save_angle_curr_rot_prj_0(double angle_curr_rot_prj_0){
    ofstream outputfile;
    outputfile.open("saved_data/angle_curr_rot_prj_0.txt", std::ios_base::app);
    outputfile << angle_curr_rot_prj_0 << endl;
}

void save_angle_curr_rot_prj_1(double angle_curr_rot_prj_1){
    ofstream outputfile;
    outputfile.open("saved_data/angle_curr_rot_prj_1.txt", std::ios_base::app);
    outputfile << angle_curr_rot_prj_1 << endl;
}

void save_angle_curr_rot_prj_2(double angle_curr_rot_prj_2){
    ofstream outputfile;
    outputfile.open("saved_data/angle_curr_rot_prj_2.txt", std::ios_base::app);
    outputfile << angle_curr_rot_prj_2 << endl;
}




void save_norme_angle_7_to_des_rot_prj(double norme_angle_7_to_des_rot_prj){
    ofstream outputfile;
    outputfile.open("saved_data/norme_angle_7_to_des_rot_prj.txt", std::ios_base::app);
    outputfile << norme_angle_7_to_des_rot_prj << endl;
}

void save_angle_7_to_des_rot_prj_0(double angle_7_to_des_rot_prj_0){
    ofstream outputfile;
    outputfile.open("saved_data/angle_7_to_des_rot_prj_0.txt", std::ios_base::app);
    outputfile << angle_7_to_des_rot_prj_0 << endl;
}

void save_angle_7_to_des_rot_prj_1(double angle_7_to_des_rot_prj_1){
    ofstream outputfile;
    outputfile.open("saved_data/angle_7_to_des_rot_prj_1.txt", std::ios_base::app);
    outputfile << angle_7_to_des_rot_prj_1 << endl;
}

void save_angle_7_to_des_rot_prj_2(double angle_7_to_des_rot_prj_2){
    ofstream outputfile;
    outputfile.open("saved_data/angle_7_to_des_rot_prj_2.txt", std::ios_base::app);
    outputfile << angle_7_to_des_rot_prj_2 << endl;
}










void save_q_dotdot_des_0(double q_dotdot_des_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_0.txt", std::ios_base::app);
    outputfile << q_dotdot_des_0 << endl;

}

void save_q_dotdot_des_1(double q_dotdot_des_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_1.txt", std::ios_base::app);
    outputfile << q_dotdot_des_1 << endl;

}

void save_q_dotdot_des_2(double q_dotdot_des_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_2.txt", std::ios_base::app);
    outputfile << q_dotdot_des_2 << endl;

}

void save_q_dotdot_des_3(double q_dotdot_des_3)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_3.txt", std::ios_base::app);
    outputfile << q_dotdot_des_3 << endl;

}

void save_q_dotdot_des_4(double q_dotdot_des_4)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_4.txt", std::ios_base::app);
    outputfile << q_dotdot_des_4 << endl;

}

void save_q_dotdot_des_5(double q_dotdot_des_5)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_5.txt", std::ios_base::app);
    outputfile << q_dotdot_des_5 << endl;

}

void save_q_dotdot_des_6(double q_dotdot_des_6)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_des_6.txt", std::ios_base::app);
    outputfile << q_dotdot_des_6 << endl;

}






void save_des_qw(double des_qw)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_qw.txt", std::ios_base::app);
    outputfile << des_qw << endl;

}

void save_des_qx(double des_qx)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_qx.txt", std::ios_base::app);
    outputfile << des_qx << endl;

}

void save_des_qy(double des_qy)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_qy.txt", std::ios_base::app);
    outputfile << des_qy << endl;

}

void save_des_qz(double des_qz)
{
    ofstream outputfile;
    outputfile.open("saved_data/des_qz.txt", std::ios_base::app);
    outputfile << des_qz << endl;

}








void save_qw(double qw)
{
    ofstream outputfile;
    outputfile.open("saved_data/qw.txt", std::ios_base::app);
    outputfile << qw << endl;

}

void save_qx(double qx)
{
    ofstream outputfile;
    outputfile.open("saved_data/qx.txt", std::ios_base::app);
    outputfile << qx << endl;

}

void save_qy(double qy)
{
    ofstream outputfile;
    outputfile.open("saved_data/qy.txt", std::ios_base::app);
    outputfile << qy << endl;

}

void save_qz(double qz)
{
    ofstream outputfile;
    outputfile.open("saved_data/qz.txt", std::ios_base::app);
    outputfile << qz << endl;

}







void save_axis_curr_rot_0(double axis_curr_rot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_curr_rot_0.txt", std::ios_base::app);
    outputfile << axis_curr_rot_0 << endl;

}

void save_axis_curr_rot_1(double axis_curr_rot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_curr_rot_1.txt", std::ios_base::app);
    outputfile << axis_curr_rot_1 << endl;

}

void save_axis_curr_rot_2(double axis_curr_rot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_curr_rot_2.txt", std::ios_base::app);
    outputfile << axis_curr_rot_2 << endl;

}




void save_axis_7_to_des_rot_0(double axis_7_to_des_rot_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_7_to_des_rot_0.txt", std::ios_base::app);
    outputfile << axis_7_to_des_rot_0 << endl;

}

void save_axis_7_to_des_rot_1(double axis_7_to_des_rot_1)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_7_to_des_rot_1.txt", std::ios_base::app);
    outputfile << axis_7_to_des_rot_1 << endl;

}

void save_axis_7_to_des_rot_2(double axis_7_to_des_rot_2)
{
    ofstream outputfile;
    outputfile.open("saved_data/axis_7_to_des_rot_2.txt", std::ios_base::app);
    outputfile << axis_7_to_des_rot_2 << endl;

}





void save_status(int status)
{
    ofstream outputfile;
    outputfile.open("saved_data/status.txt", std::ios_base::app);
    outputfile << status << endl;

}



void save_PSD(int PSD)
{
    ofstream outputfile;
    outputfile.open("saved_data/PSD.txt", std::ios_base::app);
    outputfile << PSD << endl;

}



void save_lambda(double lambda_0, double lambda_1, double lambda_2, double lambda_3, double lambda_4, double lambda_5, double lambda_6)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/lambda_0.txt", std::ios_base::app);
    outputfile0 << lambda_0 << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/lambda_1.txt", std::ios_base::app);
    outputfile1 << lambda_1 << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/lambda_2.txt", std::ios_base::app);
    outputfile2 << lambda_2 << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/lambda_3.txt", std::ios_base::app);
    outputfile3 << lambda_3 << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/lambda_4.txt", std::ios_base::app);
    outputfile4 << lambda_4 << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/lambda_5.txt", std::ios_base::app);
    outputfile5 << lambda_5 << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/lambda_6.txt", std::ios_base::app);
    outputfile6 << lambda_6 << endl;

}



void save_status_q_ddot_opt_min(double status_q_ddot_opt_min){
    ofstream outputfile;
    outputfile.open("saved_data/status_q_ddot_opt_min.txt", std::ios_base::app);
    outputfile << status_q_ddot_opt_min << endl;

}

void save_status_q_ddot_opt_max(double status_q_ddot_opt_max){
    ofstream outputfile;
    outputfile.open("saved_data/status_q_ddot_opt_max.txt", std::ios_base::app);
    outputfile << status_q_ddot_opt_max << endl;

}



void save_q_dotdot_bounds_max_comp_0(double q_dotdot_bounds_max_comp_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_max_comp_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_max_comp_0 << endl;

}


void save_q_dotdot_bounds_min_comp_0(double q_dotdot_bounds_min_comp_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_min_comp_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_min_comp_0 << endl;

}





void save_q_dotdot_bounds_max_comp_Acc_Posi_0(double q_dotdot_bounds_max_comp_Acc_Posi_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_max_comp_Acc_Posi_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_max_comp_Acc_Posi_0 << endl;

}


void save_q_dotdot_bounds_min_comp_Acc_Posi_0(double q_dotdot_bounds_min_comp_Acc_Posi_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_min_comp_Acc_Posi_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_min_comp_Acc_Posi_0 << endl;

}






void save_q_dotdot_bounds_max_comp_Jerk_Vel_0(double q_dotdot_bounds_max_comp_Jerk_Vel_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_max_comp_Jerk_Vel_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_max_comp_Jerk_Vel_0 << endl;

}


void save_q_dotdot_bounds_min_comp_Jerk_Vel_0(double q_dotdot_bounds_min_comp_Jerk_Vel_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_min_comp_Jerk_Vel_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_min_comp_Jerk_Vel_0 << endl;

}



void save_domaines_Jerk_Vel_and_Acc_Posi_disconnected(double domaines_Jerk_Vel_and_Acc_Posi_disconnected)
{
    ofstream outputfile;
    outputfile.open("saved_data/domaines_Jerk_Vel_and_Acc_Posi_disconnected.txt", std::ios_base::app);
    outputfile << domaines_Jerk_Vel_and_Acc_Posi_disconnected << endl;

}


void save_q_dotdot_bounds_max_prime_forwrd_backwrd(Eigen::VectorXd q_dotdot_bounds_max_prime_forwrd_backwrd)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_max_prime_forwrd_backwrd[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_max_prime_forwrd_backwrd[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_max_prime_forwrd_backwrd[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_max_prime_forwrd_backwrd[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_max_prime_forwrd_backwrd[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_max_prime_forwrd_backwrd[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_max_prime_forwrd_backwrd[6] << endl;
}






void save_q_dotdot_bounds_min_prime_forwrd_backwrd(Eigen::VectorXd q_dotdot_bounds_min_prime_forwrd_backwrd)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_min_prime_forwrd_backwrd[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_min_prime_forwrd_backwrd[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_min_prime_forwrd_backwrd[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_min_prime_forwrd_backwrd[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_min_prime_forwrd_backwrd[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_min_prime_forwrd_backwrd[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_min_prime_forwrd_backwrd[6] << endl;
}



















void save_n1_neg_jerk_acc_posi(Eigen::VectorXi n1_neg_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_jerk_acc_posi[6] << endl;
}



void save_n2_neg_jerk_acc_posi(Eigen::VectorXi n2_neg_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_jerk_acc_posi[6] << endl;
}



void save_n_neg_jerk_acc_posi(Eigen::VectorXi n_neg_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n_neg_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n_neg_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n_neg_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n_neg_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n_neg_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n_neg_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n_neg_jerk_acc_posi[6] << endl;
}







void save_n1_pos_jerk_acc_posi(Eigen::VectorXi n1_pos_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_jerk_acc_posi[6] << endl;
}



void save_n2_pos_jerk_acc_posi(Eigen::VectorXi n2_pos_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_jerk_acc_posi[6] << endl;
}



void save_n_pos_jerk_acc_posi(Eigen::VectorXi n_pos_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n_pos_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n_pos_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n_pos_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n_pos_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n_pos_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n_pos_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n_pos_jerk_acc_posi[6] << endl;
}






void save_q_k_n_jerk_const_max(Eigen::VectorXd q_k_n_jerk_const_max)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_k_n_jerk_const_max_0.txt", std::ios_base::app);
    outputfile0 << q_k_n_jerk_const_max[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_k_n_jerk_const_max_1.txt", std::ios_base::app);
    outputfile1 << q_k_n_jerk_const_max[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_k_n_jerk_const_max_2.txt", std::ios_base::app);
    outputfile2 << q_k_n_jerk_const_max[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_k_n_jerk_const_max_3.txt", std::ios_base::app);
    outputfile3 << q_k_n_jerk_const_max[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_k_n_jerk_const_max_4.txt", std::ios_base::app);
    outputfile4 << q_k_n_jerk_const_max[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_k_n_jerk_const_max_5.txt", std::ios_base::app);
    outputfile5 << q_k_n_jerk_const_max[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_k_n_jerk_const_max_6.txt", std::ios_base::app);
    outputfile6 << q_k_n_jerk_const_max[6] << endl;
}



void save_q_k_n_jerk_const_min(Eigen::VectorXd q_k_n_jerk_const_min)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_k_n_jerk_const_min_0.txt", std::ios_base::app);
    outputfile0 << q_k_n_jerk_const_min[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_k_n_jerk_const_min_1.txt", std::ios_base::app);
    outputfile1 << q_k_n_jerk_const_min[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_k_n_jerk_const_min_2.txt", std::ios_base::app);
    outputfile2 << q_k_n_jerk_const_min[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_k_n_jerk_const_min_3.txt", std::ios_base::app);
    outputfile3 << q_k_n_jerk_const_min[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_k_n_jerk_const_min_4.txt", std::ios_base::app);
    outputfile4 << q_k_n_jerk_const_min[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_k_n_jerk_const_min_5.txt", std::ios_base::app);
    outputfile5 << q_k_n_jerk_const_min[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_k_n_jerk_const_min_6.txt", std::ios_base::app);
    outputfile6 << q_k_n_jerk_const_min[6] << endl;
}




void save_q_ddot_k_n_jerk_const_max(Eigen::VectorXd q_ddot_k_n_jerk_const_max)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_ddot_k_n_jerk_const_max_0.txt", std::ios_base::app);
    outputfile0 << q_ddot_k_n_jerk_const_max[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_ddot_k_n_jerk_const_max_1.txt", std::ios_base::app);
    outputfile1 << q_ddot_k_n_jerk_const_max[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_ddot_k_n_jerk_const_max_2.txt", std::ios_base::app);
    outputfile2 << q_ddot_k_n_jerk_const_max[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_ddot_k_n_jerk_const_max_3.txt", std::ios_base::app);
    outputfile3 << q_ddot_k_n_jerk_const_max[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_ddot_k_n_jerk_const_max_4.txt", std::ios_base::app);
    outputfile4 << q_ddot_k_n_jerk_const_max[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_ddot_k_n_jerk_const_max_5.txt", std::ios_base::app);
    outputfile5 << q_ddot_k_n_jerk_const_max[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_ddot_k_n_jerk_const_max_6.txt", std::ios_base::app);
    outputfile6 << q_ddot_k_n_jerk_const_max[6] << endl;
}



void save_q_ddot_k_n_jerk_const_min(Eigen::VectorXd q_ddot_k_n_jerk_const_min)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_ddot_k_n_jerk_const_min_0.txt", std::ios_base::app);
    outputfile0 << q_ddot_k_n_jerk_const_min[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_ddot_k_n_jerk_const_min_1.txt", std::ios_base::app);
    outputfile1 << q_ddot_k_n_jerk_const_min[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_ddot_k_n_jerk_const_min_2.txt", std::ios_base::app);
    outputfile2 << q_ddot_k_n_jerk_const_min[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_ddot_k_n_jerk_const_min_3.txt", std::ios_base::app);
    outputfile3 << q_ddot_k_n_jerk_const_min[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_ddot_k_n_jerk_const_min_4.txt", std::ios_base::app);
    outputfile4 << q_ddot_k_n_jerk_const_min[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_ddot_k_n_jerk_const_min_5.txt", std::ios_base::app);
    outputfile5 << q_ddot_k_n_jerk_const_min[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_ddot_k_n_jerk_const_min_6.txt", std::ios_base::app);
    outputfile6 << q_ddot_k_n_jerk_const_min[6] << endl;
}






void save_n_neg_jerk_posi_P3(Eigen::VectorXi n_neg_jerk_posi_P3)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_neg_jerk_posi_P3_0.txt", std::ios_base::app);
    outputfile0 << n_neg_jerk_posi_P3[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_neg_jerk_posi_P3_1.txt", std::ios_base::app);
    outputfile1 << n_neg_jerk_posi_P3[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_neg_jerk_posi_P3_2.txt", std::ios_base::app);
    outputfile2 << n_neg_jerk_posi_P3[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_neg_jerk_posi_P3_3.txt", std::ios_base::app);
    outputfile3 << n_neg_jerk_posi_P3[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_neg_jerk_posi_P3_4.txt", std::ios_base::app);
    outputfile4 << n_neg_jerk_posi_P3[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_neg_jerk_posi_P3_5.txt", std::ios_base::app);
    outputfile5 << n_neg_jerk_posi_P3[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_neg_jerk_posi_P3_6.txt", std::ios_base::app);
    outputfile6 << n_neg_jerk_posi_P3[6] << endl;
}



void save_n_pos_jerk_posi_P3(Eigen::VectorXi n_pos_jerk_posi_P3)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n_pos_jerk_posi_P3_0.txt", std::ios_base::app);
    outputfile0 << n_pos_jerk_posi_P3[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n_pos_jerk_posi_P3_1.txt", std::ios_base::app);
    outputfile1 << n_pos_jerk_posi_P3[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n_pos_jerk_posi_P3_2.txt", std::ios_base::app);
    outputfile2 << n_pos_jerk_posi_P3[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n_pos_jerk_posi_P3_3.txt", std::ios_base::app);
    outputfile3 << n_pos_jerk_posi_P3[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n_pos_jerk_posi_P3_4.txt", std::ios_base::app);
    outputfile4 << n_pos_jerk_posi_P3[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n_pos_jerk_posi_P3_5.txt", std::ios_base::app);
    outputfile5 << n_pos_jerk_posi_P3[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n_pos_jerk_posi_P3_6.txt", std::ios_base::app);
    outputfile6 << n_pos_jerk_posi_P3[6] << endl;
}






void save_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr(Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0.txt", std::ios_base::app);
    outputfile0 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_1.txt", std::ios_base::app);
    outputfile1 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_2.txt", std::ios_base::app);
    outputfile2 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_3.txt", std::ios_base::app);
    outputfile3 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_4.txt", std::ios_base::app);
    outputfile4 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_5.txt", std::ios_base::app);
    outputfile5 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_6.txt", std::ios_base::app);
    outputfile6 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr[6] << endl;
}


void save_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr(Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0.txt", std::ios_base::app);
    outputfile0 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_1.txt", std::ios_base::app);
    outputfile1 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_2.txt", std::ios_base::app);
    outputfile2 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_3.txt", std::ios_base::app);
    outputfile3 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_4.txt", std::ios_base::app);
    outputfile4 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_5.txt", std::ios_base::app);
    outputfile5 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_6.txt", std::ios_base::app);
    outputfile6 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr[6] << endl;
}




void save_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr(Eigen::VectorXd nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0.txt", std::ios_base::app);
    outputfile0 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_1.txt", std::ios_base::app);
    outputfile1 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_2.txt", std::ios_base::app);
    outputfile2 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_3.txt", std::ios_base::app);
    outputfile3 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_4.txt", std::ios_base::app);
    outputfile4 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_5.txt", std::ios_base::app);
    outputfile5 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_6.txt", std::ios_base::app);
    outputfile6 << nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr[6] << endl;
}



void save_q_dotdot_bounds_deriv_max_comp(Eigen::VectorXd q_dotdot_bounds_deriv_max_comp)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_deriv_max_comp[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_deriv_max_comp_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_deriv_max_comp[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_deriv_max_comp_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_deriv_max_comp[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_deriv_max_comp_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_deriv_max_comp[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_deriv_max_comp_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_deriv_max_comp[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_deriv_max_comp_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_deriv_max_comp[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_deriv_max_comp_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_deriv_max_comp[6] << endl;
}





void save_q_dotdot_bounds_deriv_min_comp(Eigen::VectorXd q_dotdot_bounds_deriv_min_comp)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_dotdot_bounds_deriv_min_comp_0.txt", std::ios_base::app);
    outputfile0 << q_dotdot_bounds_deriv_min_comp[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_dotdot_bounds_deriv_min_comp_1.txt", std::ios_base::app);
    outputfile1 << q_dotdot_bounds_deriv_min_comp[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_dotdot_bounds_deriv_min_comp_2.txt", std::ios_base::app);
    outputfile2 << q_dotdot_bounds_deriv_min_comp[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_dotdot_bounds_deriv_min_comp_3.txt", std::ios_base::app);
    outputfile3 << q_dotdot_bounds_deriv_min_comp[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_dotdot_bounds_deriv_min_comp_4.txt", std::ios_base::app);
    outputfile4 << q_dotdot_bounds_deriv_min_comp[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_dotdot_bounds_deriv_min_comp_5.txt", std::ios_base::app);
    outputfile5 << q_dotdot_bounds_deriv_min_comp[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_dotdot_bounds_deriv_min_comp_6.txt", std::ios_base::app);
    outputfile6 << q_dotdot_bounds_deriv_min_comp[6] << endl;
}

void save_constr_jerk(int constr_jerk)
{
    ofstream outputfile;
    outputfile.open("saved_data/constr_jerk.txt", std::ios_base::app);
    outputfile << constr_jerk << endl;

}



void save_tau_sensor_0(double tau_sensor_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/tau_sensor_0.txt", std::ios_base::app);
    outputfile << tau_sensor_0 << endl;

}




void save_n2_neg_jerk_acc_posi_explored(Eigen::VectorXd n2_neg_jerk_acc_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_jerk_acc_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_jerk_acc_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_jerk_acc_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_jerk_acc_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_jerk_acc_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_jerk_acc_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_jerk_acc_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_jerk_acc_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_jerk_acc_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_jerk_acc_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_jerk_acc_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_jerk_acc_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_jerk_acc_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_jerk_acc_posi_explored[6] << endl;
}


void save_n2_pos_jerk_acc_posi_explored(Eigen::VectorXd n2_pos_jerk_acc_posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_jerk_acc_posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_jerk_acc_posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_jerk_acc_posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_jerk_acc_posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_jerk_acc_posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_jerk_acc_posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_jerk_acc_posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_jerk_acc_posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_jerk_acc_posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_jerk_acc_posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_jerk_acc_posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_jerk_acc_posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_jerk_acc_posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_jerk_acc_posi_explored[6] << endl;
}

void save_n2_neg_jerk_acc_posi_explored_q(Eigen::VectorXd n2_neg_jerk_acc_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_jerk_acc_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_jerk_acc_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_jerk_acc_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_jerk_acc_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_jerk_acc_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_jerk_acc_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_jerk_acc_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_jerk_acc_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_jerk_acc_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_jerk_acc_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_jerk_acc_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_jerk_acc_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_jerk_acc_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_jerk_acc_posi_explored_q[6] << endl;
}


void save_n2_pos_jerk_acc_posi_explored_q(Eigen::VectorXd n2_pos_jerk_acc_posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_jerk_acc_posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_jerk_acc_posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_jerk_acc_posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_jerk_acc_posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_jerk_acc_posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_jerk_acc_posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_jerk_acc_posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_jerk_acc_posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_jerk_acc_posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_jerk_acc_posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_jerk_acc_posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_jerk_acc_posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_jerk_acc_posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_jerk_acc_posi_explored_q[6] << endl;
}






//
void save_q_n_neg_jerk_acc_posi_reconstr(Eigen::VectorXd q_n_neg_jerk_acc_posi_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_neg_jerk_acc_posi_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_neg_jerk_acc_posi_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_neg_jerk_acc_posi_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_neg_jerk_acc_posi_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_neg_jerk_acc_posi_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_neg_jerk_acc_posi_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_neg_jerk_acc_posi_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_neg_jerk_acc_posi_reconstr[6] << endl;
}




void save_q_n_pos_jerk_acc_posi_reconstr(Eigen::VectorXd q_n_pos_jerk_acc_posi_reconstr)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_0.txt", std::ios_base::app);
    outputfile0 << q_n_pos_jerk_acc_posi_reconstr[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_1.txt", std::ios_base::app);
    outputfile1 << q_n_pos_jerk_acc_posi_reconstr[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_2.txt", std::ios_base::app);
    outputfile2 << q_n_pos_jerk_acc_posi_reconstr[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_3.txt", std::ios_base::app);
    outputfile3 << q_n_pos_jerk_acc_posi_reconstr[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_4.txt", std::ios_base::app);
    outputfile4 << q_n_pos_jerk_acc_posi_reconstr[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_5.txt", std::ios_base::app);
    outputfile5 << q_n_pos_jerk_acc_posi_reconstr[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_pos_jerk_acc_posi_reconstr_6.txt", std::ios_base::app);
    outputfile6 << q_n_pos_jerk_acc_posi_reconstr[6] << endl;
}


void save_q_n_neg_Jerk_acc_Posi_reconstr_explored(Eigen::VectorXd q_n_neg_Jerk_acc_Posi_reconstr_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_0.txt", std::ios_base::app);
    outputfile0 << q_n_neg_Jerk_acc_Posi_reconstr_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_1.txt", std::ios_base::app);
    outputfile1 << q_n_neg_Jerk_acc_Posi_reconstr_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_2.txt", std::ios_base::app);
    outputfile2 << q_n_neg_Jerk_acc_Posi_reconstr_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_3.txt", std::ios_base::app);
    outputfile3 << q_n_neg_Jerk_acc_Posi_reconstr_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_4.txt", std::ios_base::app);
    outputfile4 << q_n_neg_Jerk_acc_Posi_reconstr_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_5.txt", std::ios_base::app);
    outputfile5 << q_n_neg_Jerk_acc_Posi_reconstr_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_6.txt", std::ios_base::app);
    outputfile6 << q_n_neg_Jerk_acc_Posi_reconstr_explored[6] << endl;
}


void save_q_n_pos_Jerk_acc_Posi_reconstr_explored(Eigen::VectorXd q_n_pos_Jerk_acc_Posi_reconstr_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_0.txt", std::ios_base::app);
    outputfile0 << q_n_pos_Jerk_acc_Posi_reconstr_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_1.txt", std::ios_base::app);
    outputfile1 << q_n_pos_Jerk_acc_Posi_reconstr_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_2.txt", std::ios_base::app);
    outputfile2 << q_n_pos_Jerk_acc_Posi_reconstr_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_3.txt", std::ios_base::app);
    outputfile3 << q_n_pos_Jerk_acc_Posi_reconstr_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_4.txt", std::ios_base::app);
    outputfile4 << q_n_pos_Jerk_acc_Posi_reconstr_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_5.txt", std::ios_base::app);
    outputfile5 << q_n_pos_Jerk_acc_Posi_reconstr_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/q_n_pos_Jerk_acc_Posi_reconstr_explored_6.txt", std::ios_base::app);
    outputfile6 << q_n_pos_Jerk_acc_Posi_reconstr_explored[6] << endl;
}



void save_n1_neg_Jerk_acc_Posi_explored(Eigen::VectorXd n1_neg_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_Jerk_acc_Posi_explored[6] << endl;
}

void save_n1_pos_Jerk_acc_Posi_explored(Eigen::VectorXd n1_pos_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_Jerk_acc_Posi_explored[6] << endl;
}




void save_n2_neg_Jerk_acc_Posi_explored(Eigen::VectorXd n2_neg_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_Jerk_acc_Posi_explored[6] << endl;
}

void save_n2_pos_Jerk_acc_Posi_explored(Eigen::VectorXd n2_pos_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_Jerk_acc_Posi_explored[6] << endl;
}



void save_n3_neg_Jerk_acc_Posi_explored(Eigen::VectorXd n3_neg_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n3_neg_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n3_neg_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n3_neg_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n3_neg_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n3_neg_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n3_neg_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n3_neg_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n3_neg_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n3_neg_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n3_neg_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n3_neg_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n3_neg_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n3_neg_Jerk_acc_Posi_explored[6] << endl;
}

void save_n3_pos_Jerk_acc_Posi_explored(Eigen::VectorXd n3_pos_Jerk_acc_Posi_explored)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", std::ios_base::app);
    outputfile0 << n3_pos_Jerk_acc_Posi_explored[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n3_pos_Jerk_acc_Posi_explored_1.txt", std::ios_base::app);
    outputfile1 << n3_pos_Jerk_acc_Posi_explored[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n3_pos_Jerk_acc_Posi_explored_2.txt", std::ios_base::app);
    outputfile2 << n3_pos_Jerk_acc_Posi_explored[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n3_pos_Jerk_acc_Posi_explored_3.txt", std::ios_base::app);
    outputfile3 << n3_pos_Jerk_acc_Posi_explored[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n3_pos_Jerk_acc_Posi_explored_4.txt", std::ios_base::app);
    outputfile4 << n3_pos_Jerk_acc_Posi_explored[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n3_pos_Jerk_acc_Posi_explored_5.txt", std::ios_base::app);
    outputfile5 << n3_pos_Jerk_acc_Posi_explored[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n3_pos_Jerk_acc_Posi_explored_6.txt", std::ios_base::app);
    outputfile6 << n3_pos_Jerk_acc_Posi_explored[6] << endl;
}




void save_n1_neg_Jerk_acc_Posi_explored_q(Eigen::VectorXd n1_neg_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_Jerk_acc_Posi_explored_q[6] << endl;
}

void save_n1_pos_Jerk_acc_Posi_explored_q(Eigen::VectorXd n1_pos_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_Jerk_acc_Posi_explored_q[6] << endl;
}




void save_n2_neg_Jerk_acc_Posi_explored_q(Eigen::VectorXd n2_neg_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_neg_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_neg_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_neg_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_neg_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_neg_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_neg_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_neg_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_neg_Jerk_acc_Posi_explored_q[6] << endl;
}

void save_n2_pos_Jerk_acc_Posi_explored_q(Eigen::VectorXd n2_pos_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n2_pos_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n2_pos_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n2_pos_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n2_pos_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n2_pos_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n2_pos_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n2_pos_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n2_pos_Jerk_acc_Posi_explored_q[6] << endl;
}



void save_n3_neg_Jerk_acc_Posi_explored_q(Eigen::VectorXd n3_neg_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n3_neg_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n3_neg_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n3_neg_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n3_neg_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n3_neg_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n3_neg_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n3_neg_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n3_neg_Jerk_acc_Posi_explored_q[6] << endl;
}

void save_n3_pos_Jerk_acc_Posi_explored_q(Eigen::VectorXd n3_pos_Jerk_acc_Posi_explored_q)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_0.txt", std::ios_base::app);
    outputfile0 << n3_pos_Jerk_acc_Posi_explored_q[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_1.txt", std::ios_base::app);
    outputfile1 << n3_pos_Jerk_acc_Posi_explored_q[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_2.txt", std::ios_base::app);
    outputfile2 << n3_pos_Jerk_acc_Posi_explored_q[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_3.txt", std::ios_base::app);
    outputfile3 << n3_pos_Jerk_acc_Posi_explored_q[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_4.txt", std::ios_base::app);
    outputfile4 << n3_pos_Jerk_acc_Posi_explored_q[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_5.txt", std::ios_base::app);
    outputfile5 << n3_pos_Jerk_acc_Posi_explored_q[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n3_pos_Jerk_acc_Posi_explored_q_6.txt", std::ios_base::app);
    outputfile6 << n3_pos_Jerk_acc_Posi_explored_q[6] << endl;
}








void save_n1_neg_jerk_acc_posi(Eigen::VectorXd n1_neg_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_neg_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n1_neg_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_neg_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n1_neg_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_neg_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n1_neg_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_neg_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n1_neg_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_neg_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n1_neg_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_neg_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n1_neg_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_neg_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n1_neg_jerk_acc_posi[6] << endl;
}



void save_n1_pos_jerk_acc_posi(Eigen::VectorXd n1_pos_jerk_acc_posi)
{
    ofstream outputfile0;
    outputfile0.open("saved_data/n1_pos_jerk_acc_posi_0.txt", std::ios_base::app);
    outputfile0 << n1_pos_jerk_acc_posi[0] << endl;

    ofstream outputfile1;
    outputfile1.open("saved_data/n1_pos_jerk_acc_posi_1.txt", std::ios_base::app);
    outputfile1 << n1_pos_jerk_acc_posi[1] << endl;

    ofstream outputfile2;
    outputfile2.open("saved_data/n1_pos_jerk_acc_posi_2.txt", std::ios_base::app);
    outputfile2 << n1_pos_jerk_acc_posi[2] << endl;

    ofstream outputfile3;
    outputfile3.open("saved_data/n1_pos_jerk_acc_posi_3.txt", std::ios_base::app);
    outputfile3 << n1_pos_jerk_acc_posi[3] << endl;

    ofstream outputfile4;
    outputfile4.open("saved_data/n1_pos_jerk_acc_posi_4.txt", std::ios_base::app);
    outputfile4 << n1_pos_jerk_acc_posi[4] << endl;

    ofstream outputfile5;
    outputfile5.open("saved_data/n1_pos_jerk_acc_posi_5.txt", std::ios_base::app);
    outputfile5 << n1_pos_jerk_acc_posi[5] << endl;

    ofstream outputfile6;
    outputfile6.open("saved_data/n1_pos_jerk_acc_posi_6.txt", std::ios_base::app);
    outputfile6 << n1_pos_jerk_acc_posi[6] << endl;
}







void save_q_dotdot_bounds_min_optimized_0(double q_dotdot_bounds_min_optimized_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_min_optimized_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_min_optimized_0 << endl;
}

void save_q_dotdot_bounds_max_optimized_0(double q_dotdot_bounds_max_optimized_0)
{
    ofstream outputfile;
    outputfile.open("saved_data/q_dotdot_bounds_max_optimized_0.txt", std::ios_base::app);
    outputfile << q_dotdot_bounds_max_optimized_0 << endl;
}
