import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import pylab

params = {'legend.fontsize': 20,
          'legend.linewidth': 2}
plt.rcParams.update(params)





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


source_1 = open("saved_data/q_ddot_k_n_jerk_const_max_0.txt", "r")
q_ddot_k_n_jerk_const_max_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_ddot_k_n_jerk_const_min_0.txt", "r")
q_ddot_k_n_jerk_const_min_0 = source_1.readlines()
source_1.close()

plt.figure('q_dot_dot')




ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,              "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_bounds_max_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_optimized_0),1), q_dotdot_bounds_max_optimized_0, "k",   linewidth=2.0)
ploted_q_dotdot_bounds_min_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_optimized_0),1), q_dotdot_bounds_min_optimized_0, "k--", linewidth=2.0)

ploted_q_ddot_k_n_jerk_const_max_0, = plt.plot(0.001*np.arange(0,np.size(q_ddot_k_n_jerk_const_max_0),1), q_ddot_k_n_jerk_const_max_0, "g",   linewidth=2.0)
ploted_q_ddot_k_n_jerk_const_min_0, = plt.plot(0.001*np.arange(0,np.size(q_ddot_k_n_jerk_const_min_0),1), q_ddot_k_n_jerk_const_min_0, "g--", linewidth=2.0)

plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp, ploted_q_dotdot_bounds_max_optimized_0, ploted_q_dotdot_bounds_min_optimized_0, ploted_q_ddot_k_n_jerk_const_max_0, ploted_q_ddot_k_n_jerk_const_min_0], ['$\ddot{q_0} (rad s^2)$', '$\ddot{q_0} max (rad s^2)$', '$\ddot{q_0} min (rad s^2)$', '$\ddot{q_0} max(rad s^2)$', '$\ddot{q_0} min (rad s^2)$', '$\ddot{q_0}_{k.n.kerk.const.max}(rad s^2)$', '$\ddot{q_0}_{k.n.kerk.const.min}(rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -100, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################












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
ploted_n_neg_jerk_posi_P3_0,   = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_P3_0),1),   n_neg_jerk_posi_P3_0,    "c",   linewidth=2.0)
ploted_n_pos_jerk_posi_P3_0,   = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_P3_0),1),   n_pos_jerk_posi_P3_0,    "c--", linewidth=2.0)

ploted_n_neg_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_acc_posi_0),1), n_neg_jerk_acc_posi_0,  "y",   linewidth=2.0)
ploted_n_pos_jerk_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_acc_posi_0),1), n_pos_jerk_acc_posi_0,  "y--", linewidth=2.0)

ploted_q_k_n_jerk_const_max_0, = plt.plot(0.001*np.arange(0,np.size(q_k_n_jerk_const_max_0),1), q_k_n_jerk_const_max_0, "m",   linewidth=2.0)
ploted_q_k_n_jerk_const_min_0, = plt.plot(0.001*np.arange(0,np.size(q_k_n_jerk_const_min_0),1), q_k_n_jerk_const_min_0, "m--", linewidth=2.0)

#ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1),          domaines_Jerk_Vel_and_Acc_Posi_disconnected,          "r", linewidth=2.0)
#plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$disconnected$'])
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_jerk_posi_0, ploted_n_pos_jerk_posi_0, ploted_n_neg_jerk_posi_P3_0, ploted_n_pos_jerk_posi_P3_0, ploted_n_neg_jerk_acc_posi_0, ploted_n_pos_jerk_acc_posi_0, ploted_q_k_n_jerk_const_max_0, ploted_q_k_n_jerk_const_min_0], ['$q_0 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$n_{minimize.P3}$', '$n_{maximize.P3}$', '$n_{minimize.qddotmin.qddot}$', '$n_{maximize.qddotmax.qddot}$', 'q_0_{n.jerk.const.max} (rad)', 'q_0_{n.jerk.const.min} (rad)'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_k_n_jerk_const_max_0), -4, 50])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp FINAL DEBUG##############################


plt.show()
