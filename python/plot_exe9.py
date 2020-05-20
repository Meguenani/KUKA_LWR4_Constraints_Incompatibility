import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import pylab

params = {'legend.fontsize': 20,
          'legend.linewidth': 2}
plt.rcParams.update(params)


#############################tau plot##############################
source = open("saved_data/tau_0.txt", "r")
tau_0 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_0, = plt.plot(0.001*np.arange(0,np.size(tau_0),1), tau_0, linewidth=2.0)

	



source = open("saved_data/tau_1.txt", "r")
tau_1 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_1, = plt.plot(0.001*np.arange(0,np.size(tau_1),1), tau_1, linewidth=2.0)

	



source = open("saved_data/tau_2.txt", "r")
tau_2 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_2, = plt.plot(0.001*np.arange(0,np.size(tau_2),1), tau_2, linewidth=2.0)

	





source = open("saved_data/tau_3.txt", "r")
tau_3 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_3, = plt.plot(0.001*np.arange(0,np.size(tau_3),1), tau_3, linewidth=2.0)






source = open("saved_data/tau_4.txt", "r")
tau_4 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_4, = plt.plot(0.001*np.arange(0,np.size(tau_4),1), tau_4, linewidth=2.0)

	






source = open("saved_data/tau_5.txt", "r")
tau_5 = source.readlines()
source.close()
plt.figure(7)	
ploted_tau_5, = plt.plot(0.001*np.arange(0,np.size(tau_5),1), tau_5, linewidth=2.0)







source = open("saved_data/tau_6.txt", "r")
tau_6 = source.readlines()
source.close()
plt.figure(7)
ploted_tau_6, = plt.plot(0.001*np.arange(0,np.size(tau_6),1), tau_6, linewidth=2.0)
plt.legend([ploted_tau_6, ploted_tau_5, ploted_tau_4, ploted_tau_3, ploted_tau_2, ploted_tau_1, ploted_tau_0], [r'$\tau_6$', r'$\tau_5$', r'$\tau_4$', r'$\tau_3$', r'$\tau_2$', r'$\tau_1$', r'$\tau_0$' ])






source = open("saved_data/tau_0_max.txt", "r")
tau_0_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_0_max, = plt.plot(0.001*np.arange(0,np.size(tau_0_max),1), tau_0_max, "b", linewidth=2.0)



source = open("saved_data/tau_0_min.txt", "r")
tau_0_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_0_min, = plt.plot(0.001*np.arange(0,np.size(tau_0_min),1), tau_0_min, "b--", linewidth=2.0)





source = open("saved_data/tau_1_max.txt", "r")
tau_1_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_1_max, = plt.plot(0.001*np.arange(0,np.size(tau_1_max),1), tau_1_max, "g", linewidth=2.0)



source = open("saved_data/tau_1_min.txt", "r")
tau_1_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_1_min, = plt.plot(0.001*np.arange(0,np.size(tau_1_min),1), tau_1_min, "g--", linewidth=2.0)







source = open("saved_data/tau_2_max.txt", "r")
tau_2_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_2_max, = plt.plot(0.001*np.arange(0,np.size(tau_2_max),1), tau_2_max, "r", linewidth=2.0)



source = open("saved_data/tau_2_min.txt", "r")
tau_2_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_2_min, = plt.plot(0.001*np.arange(0,np.size(tau_2_min),1), tau_2_min, "r--", linewidth=2.0)







source = open("saved_data/tau_3_max.txt", "r")
tau_3_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_3_max, = plt.plot(0.001*np.arange(0,np.size(tau_3_max),1), tau_3_max, "c", linewidth=2.0)



source = open("saved_data/tau_3_min.txt", "r")
tau_3_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_3_min, = plt.plot(0.001*np.arange(0,np.size(tau_3_min),1), tau_3_min, "c--", linewidth=2.0)






source = open("saved_data/tau_4_max.txt", "r")
tau_4_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_4_max, = plt.plot(0.001*np.arange(0,np.size(tau_4_max),1), tau_4_max, "m", linewidth=2.0)



source = open("saved_data/tau_4_min.txt", "r")
tau_4_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_4_min, = plt.plot(0.001*np.arange(0,np.size(tau_4_min),1), tau_4_min, "m--", linewidth=2.0)





source = open("saved_data/tau_5_max.txt", "r")
tau_5_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_5_max, = plt.plot(0.001*np.arange(0,np.size(tau_5_max),1), tau_5_max, "y", linewidth=2.0)



source = open("saved_data/tau_5_min.txt", "r")
tau_5_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_5_min, = plt.plot(0.001*np.arange(0,np.size(tau_5_min),1), tau_5_min, "y--", linewidth=2.0)









source = open("saved_data/tau_6_max.txt", "r")
tau_6_max = source.readlines()
source.close()
plt.figure(7)
ploted_tau_6_max, = plt.plot(0.001*np.arange(0,np.size(tau_6_max),1), tau_6_max, "k", linewidth=2.0)



source = open("saved_data/tau_6_min.txt", "r")
tau_6_min = source.readlines()
source.close()
plt.figure(7)
ploted_tau_6_min, = plt.plot(0.001*np.arange(0,np.size(tau_6_min),1), tau_6_min, "k--", linewidth=2.0)


plt.ylabel("$(N.m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(tau_0), -210, 210])
plt.grid(True)
#############################tau plot##############################








############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_max_comp.txt", "r")
q_dotdot_0_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_min_comp.txt", "r")
q_dotdot_0_min_comp = source_1.readlines()
source_1.close()


plt.figure(12)



ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,              "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r",   linewidth=2.0)


plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp], ['$\ddot{q_0} (rad s^2)$', '$\ddot{q_0} max (rad s^2)$', '$\ddot{q_0} min (rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -100, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################






############################q_dot_dot_dot plot##############################
source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
q_dotdotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
n_neg_jerk_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
n_pos_jerk_posi_0 = source.readlines()
source.close()
plt.figure('q_dot_dot_dot')



ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r",   linewidth=2.0)
plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, n_neg_jerk_posi_0, n_pos_jerk_posi_0], ['$\dddot{q}_0 (rad/s)$', '$\dddot{q_0}_{max} (rad)$', '$\dddot{q_0}_{min} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_0), -600, 600])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot_dot plot##############################









############################q_dot_dot plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_k_n_jerk_const_max_0.txt", "r")
q_k_n_jerk_const_max_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_k_n_jerk_const_min_0.txt", "r")
q_k_n_jerk_const_min_0 = source_1.readlines()
source_1.close()

source = open("saved_data/n_neg_jerk_posi_0.txt", "r")  #CALCUL n JERK-POSI normal
n_neg_jerk_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_0.txt", "r") #CALCUL n JERK-POSI NORMAL
n_pos_jerk_posi_0 = source.readlines()
source.close()




source = open("saved_data/n_neg_jerk_posi_P3_0.txt", "r")  #CALCUL n JERK-POSI normal
n_neg_jerk_posi_P3_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_P3_0.txt", "r") #CALCUL n JERK-POSI NORMAL
n_pos_jerk_posi_P3_0 = source.readlines()
source.close()


source = open("saved_data/n_neg_jerk_acc_posi_0.txt", "r")  #CALCUL n JERK-POSI normal
n_neg_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_acc_posi_0.txt", "r") #CALCUL n JERK-POSI NORMAL
n_pos_jerk_acc_posi_0 = source.readlines()
source.close()



plt.figure('q_k_n_jerk_const_debug FINAL')


ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r",   linewidth=2.0)
ploted_q_0_min,                = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),                q_0_min,                "r",   linewidth=2.0)
ploted_n_neg_jerk_posi_0,      = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_0),1),      n_neg_jerk_posi_0,      "k",   linewidth=2.0)
ploted_n_pos_jerk_posi_0,      = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_0),1),      n_pos_jerk_posi_0,      "k--", linewidth=2.0)


#ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1),          domaines_Jerk_Vel_and_Acc_Posi_disconnected,          "r", linewidth=2.0)
#plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$disconnected$'])
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_jerk_posi_0, ploted_n_pos_jerk_posi_0], ['$q_0 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_k_n_jerk_const_max_0), -4, 50])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp FINAL DEBUG##############################











#############################compatibility q_dot-q_dddot0 plot##############################
source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_0_max.txt", "r")
q_dot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_0_min.txt", "r")
q_dot_0_min = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0.txt", "r")
nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0 = source_1.readlines()
source_1.close()

plt.figure('q_dot (Vel_Jerk_comp)')

ploted_q_dot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),          q_dot_0,          "b",   linewidth=2.0)
ploted_q_dot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),      q_dot_0_max,      "r",   linewidth=2.0)
ploted_q_dot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1),      q_dot_0_min,      "r",   linewidth=2.0)
ploted_n_neg_jerk_vel_0, = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1), n_neg_jerk_vel_0, "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0, = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1), n_pos_jerk_vel_0, "k--", linewidth=2.0)
ploted_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0,          = plt.plot(0.001*np.arange(0,np.size(nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0),1),          nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0,          "m--",   linewidth=2.0)
plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min, ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0, ploted_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_vel_constr_0], ['$\dot{q_0} (rad/s)$', '$\dot{q_0}_{max} (rad)$', '$\dot{q_0}_{min} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$\dot{q_0}_{max.brake} (rad)$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -5, 15])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q_dot-q_dddot0 plot##############################
















############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_max_comp.txt", "r")
q_dotdot_0_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_min_comp.txt", "r")
q_dotdot_0_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_0.txt", "r")
q_dotdot_bounds_max_optimized_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_0.txt", "r")
q_dotdot_bounds_min_optimized_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0.txt", "r")
nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/domaines_Jerk_Vel_and_Acc_Posi_disconnected.txt", "r")
domaines_Jerk_Vel_and_Acc_Posi_disconnected = source_1.readlines()
source_1.close()


plt.figure('q_dot_dot')


ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,              "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r--",   linewidth=2.0)
ploted_q_dotdot_bounds_max_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_optimized_0),1), q_dotdot_bounds_max_optimized_0, "k",   linewidth=2.0)
ploted_q_dotdot_bounds_min_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_optimized_0),1), q_dotdot_bounds_min_optimized_0, "k--", linewidth=2.0)
ploted_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0,                      = plt.plot(0.001*np.arange(0,np.size(nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0),1),                      nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0,              "m--",   linewidth=2.0)
ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1), domaines_Jerk_Vel_and_Acc_Posi_disconnected, "g", linewidth=2.0)
plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp, ploted_q_dotdot_bounds_max_optimized_0, ploted_q_dotdot_bounds_min_optimized_0, ploted_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_acc_constr_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} (rad s^2)$', '$\ddot{q_0} max (rad s^2)$', '$\ddot{q_0} min (rad s^2)$', '$\ddot{q_0} max(rad s^2)$', '$\ddot{q_0} min (rad s^2)$', '$\ddot{q_0} max.brake (rad s^2)$', '$\ddot{q_0} domains.C$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -100, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################





############################q_dot_dot_dot plot##############################
source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
q_dotdotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
n_neg_jerk_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
n_pos_jerk_posi_0 = source.readlines()
source.close()
plt.figure('q_dot_dot_dot')


source_1 = open("saved_data/nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0.txt", "r")
nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0 = source_1.readlines()
source_1.close()


ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r",   linewidth=2.0)
ploted_nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0,          = plt.plot(0.001*np.arange(0,np.size(nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0),1),          nxt_step_des_qddot_cnstr_frm_brking_posi_cnstr_jerk_constr_0,          "m--",   linewidth=2.0)
plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, n_neg_jerk_posi_0, n_pos_jerk_posi_0], ['$\dddot{q}_0 (rad/s)$', '$\dddot{q_0}_{max} (rad)$', '$\dddot{q_0}_{min} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$\dddot{q_0}_{max.brake} (rad)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_0), -600, 600])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot_dot plot##############################

















############################q plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()


source_1 = open("saved_data/n1_pos_jerk_acc_posi_0.txt", "r")
n1_pos_jerk_acc_posi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n1_neg_jerk_acc_posi_0.txt", "r")
n1_neg_jerk_acc_posi_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/n2_pos_jerk_acc_posi_0.txt", "r")
n2_pos_jerk_acc_posi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_jerk_acc_posi_0.txt", "r")
n2_neg_jerk_acc_posi_0 = source_1.readlines()
source_1.close()


plt.figure('q_k_n_acc_jerk FINAL')


ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r",   linewidth=2.0)
ploted_q_0_min,                = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),                q_0_min,                "r--",   linewidth=2.0)

ploted_n1_pos_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_acc_posi_0),1),      n1_pos_jerk_acc_posi_0,      "k--",   linewidth=2.0)
ploted_n1_neg_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_acc_posi_0),1),      n1_neg_jerk_acc_posi_0,      "k", linewidth=2.0)

ploted_n2_pos_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_acc_posi_0),1),      n2_pos_jerk_acc_posi_0,      "g--",   linewidth=2.0)
ploted_n2_neg_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_acc_posi_0),1),      n2_neg_jerk_acc_posi_0,      "g", linewidth=2.0)

#ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1),          domaines_Jerk_Vel_and_Acc_Posi_disconnected,          "r", linewidth=2.0)
#plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$disconnected$'])
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n1_pos_jerk_acc_posi_0, ploted_n1_neg_jerk_acc_posi_0, ploted_n2_pos_jerk_acc_posi_0, ploted_n2_neg_jerk_acc_posi_0], ['$q_0 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$', '$n1_{pos}$', '$n1_{neg}$', '$n2_{pos}$', '$n2_{neg}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_k_n_jerk_const_max_0), -4, 50])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q  plot_comp FINAL DEBUG##############################







plt.show()
