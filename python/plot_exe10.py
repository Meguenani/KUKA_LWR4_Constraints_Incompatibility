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




#############################X plot##############################
source = open("saved_data/trajectory_x.txt", "r")
X_x = source.readlines()
source.close()

source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()

plt.figure(13)
plt.subplot(2, 2, 1)
	
ploted_X_x, = plt.plot(0.001*np.arange(0,np.size(X_x),1), X_x, "b", linewidth=2.0)
ploted_Des_X_x, = plt.plot(0.001*np.arange(0,np.size(des_X_x),1), des_X_x, "r--", linewidth=2.0)
plt.legend([ploted_X_x, ploted_Des_X_x], ['$X_x$', '$X^*_x$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_x), -0.6, 0.85])
plt.grid(True)




source = open("saved_data/trajectory_y.txt", "r")
X_y = source.readlines()
source.close()

source = open("saved_data/des_trajectory_y.txt", "r")
des_X_y = source.readlines()
source.close()

plt.figure(13)
plt.subplot(2, 2, 2)
	
ploted_X_y, = plt.plot(0.001*np.arange(0,np.size(X_y),1), X_y, "b", linewidth=2.0)
ploted_Des_X_y, = plt.plot(0.001*np.arange(0,np.size(des_X_y),1), des_X_y, "r--", linewidth=2.0)
plt.legend([ploted_X_y, ploted_Des_X_y], ['$X_y$', '$X^*_y$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_y), 0.15, 0.75])
plt.grid(True)




source = open("saved_data/trajectory_z.txt", "r")
X_z = source.readlines()
source.close()

source = open("saved_data/des_trajectory_z.txt", "r")
des_X_z = source.readlines()
source.close()

plt.figure(13)
plt.subplot(2, 2, 3)

print len(np.arange(0,np.size(X_z),1))
print np.size(X_z)
	
ploted_X_z, = plt.plot(0.001*np.arange(0,np.size(X_z),1), X_z,  "b", linewidth=2.0)
ploted_Des_X_z, = plt.plot(0.001*np.arange(0,np.size(des_X_z),1), des_X_z, "r--", linewidth=2.0)
plt.legend([ploted_X_z, ploted_Des_X_z], ['$X_z$', '$X^*_z$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_z), 0.15, 0.85])
plt.grid(True)





source = open("saved_data/X_err.txt", "r")
X_err = source.readlines()
source.close()


plt.figure(13)
plt.subplot(2, 2, 4)
	
ploted_X_err, = plt.plot(0.001*np.arange(0,np.size(X_err),1), X_err, "b", linewidth=2.0)

plt.legend([ploted_X_err], ['$X_{err}$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_err), 0.0, 0.005])
plt.grid(True)
#############################X plot##############################









#############################Velocities plot##############################
source = open("saved_data/V_7.txt", "r")
V_7 = source.readlines()
source.close()

source = open("saved_data/V_7_des.txt", "r")
V_7_des = source.readlines()
source.close()

plt.figure('V_7')
plt.subplot(2, 2, 1)

ploted_V_7,       = plt.plot(0.001*np.arange(0,np.size(V_7),1),       V_7,       "b",   linewidth=2.0)
ploted_V_7_des,   = plt.plot(0.001*np.arange(0,np.size(V_7_des),1),   V_7_des,   "r--", linewidth=2.0)

plt.legend([ploted_V_7, ploted_V_7_des], ['$|\dot{X}|$', '$|\dot{X^*}_{des}|$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/V_7_x.txt", "r")
V_7_x = source.readlines()
source.close()

source = open("saved_data/V_7_des_x.txt", "r")
V_7_des_x = source.readlines()
source.close()

plt.figure('V_7')
plt.subplot(2, 2, 2)

ploted_V_7_x,     = plt.plot(0.001*np.arange(0,np.size(V_7_x),1),     V_7_x,     "b",   linewidth=2.0)
ploted_V_7_des_x, = plt.plot(0.001*np.arange(0,np.size(V_7_des_x),1), V_7_des_x, "r--", linewidth=2.0)

plt.legend([ploted_V_7_x, ploted_V_7_des_x], ['$\dot{X_x}$', '$\dot{X^*}_x$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_x), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/V_7_y.txt", "r")
V_7_y = source.readlines()
source.close()

source = open("saved_data/V_7_des_y.txt", "r")
V_7_des_y = source.readlines()
source.close()

plt.figure('V_7')
plt.subplot(2, 2, 3)

ploted_V_7_y,     = plt.plot(0.001*np.arange(0,np.size(V_7_y),1),     V_7_y,     "b",   linewidth=2.0)
ploted_V_7_des_y, = plt.plot(0.001*np.arange(0,np.size(V_7_des_y),1), V_7_des_y, "r--", linewidth=2.0)

plt.legend([ploted_V_7_y, ploted_V_7_des_y], ['$\dot{X_y}$', '$\dot{X^*}_y$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_y), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/V_7_z.txt", "r")
V_7_z = source.readlines()
source.close()

source = open("saved_data/V_7_des_z.txt", "r")
V_7_des_z = source.readlines()
source.close()

plt.figure('V_7')
plt.subplot(2, 2, 4)

ploted_V_7_z,     = plt.plot(0.001*np.arange(0,np.size(V_7_z),1),     V_7_z,     "b",   linewidth=2.0)
ploted_V_7_des_z, = plt.plot(0.001*np.arange(0,np.size(V_7_des_z),1), V_7_des_z, "r--", linewidth=2.0)

plt.legend([ploted_V_7_z, ploted_V_7_des_y], ['$\dot{X_z}$', '$\dot{X^*}_z$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_z), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################Velocities plot##############################





##############################q_dot_dot_dot plot##############################
#source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
#q_dotdotdot_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
#q_dotdotdot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
#q_dotdotdot_0_min = source_1.readlines()
#source_1.close()

#plt.figure('q_dot_dot_dot 0')



#ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "b",   linewidth=2.0)
#ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
#ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r--",   linewidth=2.0)
#plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min], ['$\dddot{q}_0 (rad/s^3)$', '$\dddot{q_{M_{0}}} (rad/s^3)$', '$\dddot{q_{m_{0}}} (rad/s^3)$'])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dotdotdot_0), -8000, 8000])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
##############################q_dot_dot_dot plot##############################





###########################q_dot_dot_dot  pour la comp vel_jerk plot##############################
#source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
#q_dotdotdot_0 = source_1.readlines()
#source_1.close()


#source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
#q_dotdotdot_gurobi_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/constr_jerk.txt", "r")
#constr_jerk = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/constr_jerk.txt", "r")
#constr_jerk = source_1.readlines()
#source_1.close()


#source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
#q_dotdotdot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
#q_dotdotdot_0_min = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_min_comp_0.txt", "r")
#q_dotdot_bounds_deriv_min_comp_0 = source_1.readlines()
#source_1.close()

#plt.figure('q_dot_dot_dot comp 0 q_dot_dot_dot_reconstruit_from_q_ddot_gurobi')



#ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "g",   linewidth=2.0)
#ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
#ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
#ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r--", linewidth=2.0)
#ploted_constr_jerk,                      = plt.plot(0.001*np.arange(0,np.size(constr_jerk),1),          constr_jerk,          "k",   linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),          q_dotdot_bounds_deriv_max_comp_0,          "m",   linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_min_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_min_comp_0),1),          q_dotdot_bounds_deriv_min_comp_0,          "m--",   linewidth=2.0)
#plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0, ploted_q_dotdot_bounds_deriv_min_comp_0, ploted_constr_jerk], ['$\dddot{q}_{real.0} (rad/s^3)$', '$\dddot{q}_{gurobi.0} (rad/s^3)$', '$\dddot{q_{M_{0}}} (rad/s^3)$', '$\dddot{q_{m_{0}}} (rad/s^3)$', '$\dddot{q}_{max.0.constr} (rad/s)$', '$\dddot{q}_{max.0.constr} (rad/s)$', '$\dddot{q}_{min.0.constr} (rad/s)$', '$const_jerk$'])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dotdotdot_0), -2000, 2000])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
###########################q_dot_dot_dot  pour la comp vel_jerk plot##############################





















############################q_dot_dot_dot plot##############################
#source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
#q_dotdotdot_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
#q_dotdotdot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
#q_dotdotdot_0_min = source_1.readlines()
#source_1.close()

#plt.figure('q_dot_dot_dot comp 0')



#ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "b",   linewidth=2.0)
#ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
#ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r--",   linewidth=2.0)
#plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min], ['$\dddot{q}_0 (rad/s^3)$', '$\dddot{q_{M_{0}}} (rad/s^3)$', '$\dddot{q_{m_{0}}} (rad/s^3)$'])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dotdotdot_0), -2000, 2000])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
############################q_dot_dot_dot plot##############################






############################q_0 plot_comp FINAL DEBUG##############################
#source_1 = open("saved_data/q_0.txt", "r")
#q_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_max.txt", "r")
#q_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_min.txt", "r")
#q_0_min = source_1.readlines()
#source_1.close()


#plt.figure('q 0')


#ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
#ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r",   linewidth=2.0)
#ploted_q_0_min,                = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),                q_0_min,                "r--",   linewidth=2.0)



#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$'])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_0), -3.5, 3.5])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
############################q_0 plot_comp FINAL DEBUG##############################








#############################compatibility q_dot-q_dddot0 plot##############################
#source_1 = open("saved_data/q_dot_0.txt", "r")
#q_dot_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dot_0_max.txt", "r")
#q_dot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dot_0_min.txt", "r")
#q_dot_0_min = source_1.readlines()
#source_1.close()


#source_1 = open("saved_data/q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0.txt", "r")
#q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0.txt", "r")
#q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
#source_1.close()



#plt.figure('q_dot 0')

#ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),          q_dot_0,          "b",   linewidth=2.0)
#ploted_q_dot_0_max,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),      q_dot_0_max,      "r",   linewidth=2.0)
#ploted_q_dot_0_min,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1),      q_dot_0_min,      "r--", linewidth=2.0)
#ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0,      "m",   linewidth=2.0)
#ploted_q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0,      "m--", linewidth=2.0)

#plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min, ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0, ploted_q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0], ['$\dot{q}_0 (rad/s)$', '$\dot{q}_{m_{0}} (rad/s)$', '$\dot{q}_{m_{0}} (rad/s)$', '$\dot{q}_{cmdm_{0}} (rad/s)$', '$\dot{q}_{cmdm_{0}} (rad/s)$'])
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dot_0), -4, 4])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################compatibility q_dot-q_dddot0 plot##############################







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


source_1 = open("saved_data/q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0.txt", "r")
q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0.txt", "r")
q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dot_n_neg_jerk_reconstr_0.txt", "r")
q_dot_n_neg_jerk_reconstr_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_n_pos_jerk_reconstr_0.txt", "r")
q_dot_n_pos_jerk_reconstr_0 = source_1.readlines()
source_1.close()



source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()


plt.figure('q_dot 0 avec q_dot_n_comp_vel_jerk_reconstr')

ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),          q_dot_0,          "b",   linewidth=2.0)
ploted_q_dot_0_max,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),      q_dot_0_max,      "r",   linewidth=2.0)
ploted_q_dot_0_min,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1),      q_dot_0_min,      "r--", linewidth=2.0)
ploted_q_dot_n_neg_jerk_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_n_neg_jerk_reconstr_0),1), q_dot_n_neg_jerk_reconstr_0, "y",     linewidth=2.0)
ploted_q_dot_n_pos_jerk_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_n_pos_jerk_reconstr_0),1), q_dot_n_pos_jerk_reconstr_0, "y--",   linewidth=2.0)
ploted_n_neg_jerk_vel_0,                = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1), n_neg_jerk_vel_0, "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0,                = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1), n_pos_jerk_vel_0, "k--", linewidth=2.0)
ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0,      "m",   linewidth=2.0)
ploted_q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0,      "m--", linewidth=2.0)

plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min, ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0, ploted_q_dot_bounds_min_comp_Acc_Posi_vel_cmd_0, ploted_q_dot_n_neg_jerk_reconstr_0, ploted_q_dot_n_pos_jerk_reconstr_0, ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0], ['$\dot{q}_0 (rad/s)$', '$\dot{q}_{m_{0}} (rad/s)$', '$\dot{q}_{m_{0}} (rad/s)$', '$\dot{q}_{cmdm_{0}} (rad/s)$', '$\dot{q}_{cmdm_{0}} (rad/s)$', '$\dot{q}_{posrectr.0} (rad)$', '$\dot{q}_{negrectr.0} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -4, 4])
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


plt.figure('q_dot_dot comp 0 FINAL !!!')


ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,                   "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r--",   linewidth=2.0)



plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp], ['$\ddot{q}_{gurobi.0} (rad s^2)$', '$\ddot{q}_{M_{0}} (rad s^2)$', '$\ddot{q}_{m_{0}} (rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -5, 10])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################



##############################compatibility q-q_dddot0 plot##############################
#source_1 = open("saved_data/q_0.txt", "r")
#q_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_max.txt", "r")
#q_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_min.txt", "r")
#q_0_min = source_1.readlines()
#source_1.close()




#source_1 = open("saved_data/q_n_pos_jerk_posi_reconstr_0.txt", "r")
#q_n_pos_jerk_posi_reconstr_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_n_neg_jerk_posi_reconstr_0.txt", "r")
#q_n_neg_jerk_posi_reconstr_0 = source_1.readlines()
#source_1.close()


#source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
#n_neg_jerk_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
#n_pos_jerk_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n_neg_jerk_posi_explored_0.txt", "r")
#n_neg_jerk_posi_explored_0 = source.readlines()
#source.close()

#source = open("saved_data/n_pos_jerk_posi_explored_0.txt", "r")
#n_pos_jerk_posi_explored_0 = source.readlines()
#source.close()

#plt.figure('q (Jerk_Posi_comp Explored/ComputedP4) ')


#ploted_q_0,                         = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,              "b",   linewidth=2.0)
#ploted_q_n_pos_jerk_posi_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_n_pos_jerk_posi_reconstr_0),1), q_n_pos_jerk_posi_reconstr_0, "y",     linewidth=2.0)
#ploted_q_n_neg_jerk_posi_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_n_neg_jerk_posi_reconstr_0),1), q_n_neg_jerk_posi_reconstr_0, "y--",   linewidth=2.0)
#ploted_q_0_max,          	    = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,          "r",   linewidth=2.0)
#ploted_q_0_min,                     = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,          "r",   linewidth=2.0)

#ploted_n_neg_jerk_posi_0,           = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_0),1), n_neg_jerk_posi_0, "k",   linewidth=2.0)
#ploted_n_pos_jerk_posi_0,           = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_0),1), n_pos_jerk_posi_0, "k--", linewidth=2.0)
#ploted_n_neg_jerk_posi_explored_0,  = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_explored_0),1), n_neg_jerk_posi_explored_0, "m",   linewidth=2.0)
#ploted_n_pos_jerk_posi_explored_0,  = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_explored_0),1), n_pos_jerk_posi_explored_0, "m--", linewidth=2.0)
#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_jerk_posi_0, ploted_n_pos_jerk_posi_0, ploted_n_neg_jerk_posi_explored_0, ploted_n_pos_jerk_posi_explored_0, ploted_q_n_pos_jerk_posi_reconstr_0, ploted_q_n_neg_jerk_posi_reconstr_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$n_{exp.minimize}$', '$n_{exp.maximize}$', '$q_{posrectr.0} (rad)$', '$q_{negrectr.0} (rad)$'])


#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_0), -5, 15])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################










#############################compatibility q-q_dddot0 plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_n_neg_jerk_posi_reconstr_0.txt", "r")
q_n_neg_jerk_posi_reconstr_0 = source_1.readlines()
source_1.close()


source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
n_neg_jerk_posi_0 = source.readlines()
source.close()

plt.figure('q (Jerk_Posi_comp Explored/ComputedP4) FINAL !!!')

ploted_q_0,                         = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,                "b",   linewidth=2.0)
ploted_q_n_neg_jerk_posi_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_n_neg_jerk_posi_reconstr_0),1), q_n_neg_jerk_posi_reconstr_0, "y--",   linewidth=2.0)
ploted_q_0_max,          	    = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),           q_0_max,            "r",   linewidth=2.0)
ploted_q_0_min,                     = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),           q_0_min,            "r--",   linewidth=2.0)
ploted_n_neg_jerk_posi_0,           = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_0),1), n_neg_jerk_posi_0,  "k",   linewidth=2.0)



plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_jerk_posi_0,  ploted_q_n_neg_jerk_posi_reconstr_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n_{minimize}$', '$q_{ectr} (rad)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 5])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################









#############################q_dot_dot plot_comp##############################
#source_1 = open("saved_data/q_dotdot_0.txt", "r")
#q_dotdot_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_0_max.txt", "r")
#q_dotdot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_0_min.txt", "r")
#q_dotdot_0_min = source_1.readlines()
#source_1.close()



#plt.figure('q_dot_dot 0')


#ploted_q_dotdot_0,                       = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                 q_dotdot_0,              "b",   linewidth=2.0)
#ploted_q_dotdot_0_max,                   = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max),1),             q_dotdot_0_max,          "r",   linewidth=2.0)
#ploted_q_dotdot_0_min,                   = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min),1),             q_dotdot_0_min,          "r--",   linewidth=2.0)



#plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max, ploted_q_dotdot_0_min], ['$\ddot{q}_0 (rad s^2)$', '$\ddot{q}_{M_{0}} (rad s^2)$', '$\ddot{q}_{m_{0}} (rad s^2)$'])


#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dotdot_0), -1250, 250])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################q_dot_dot plot_comp##############################











#############################compatibility q-q_ddot0 plot##############################
#source_1 = open("saved_data/q_0.txt", "r")
#q_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_max.txt", "r")
#q_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_min.txt", "r")
#q_0_min = source_1.readlines()
#source_1.close()

#source = open("saved_data/n_neg_acc_posi_0.txt", "r")
#n_neg_acc_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n_pos_acc_posi_0.txt", "r")
#n_pos_acc_posi_0 = source.readlines()
#source.close()



#source_1 = open("saved_data/q_n_neg_acc_reconstr_0.txt", "r")
#q_n_neg_acc_reconstr_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_n_pos_acc_reconstr_0.txt", "r")
#q_n_pos_acc_reconstr_0 = source_1.readlines()
#source_1.close()


#plt.figure('q 0 comp_posi_acc')


#ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
#ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r",   linewidth=2.0)
#ploted_q_0_min,                = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),                q_0_min,                "r--",   linewidth=2.0)
#ploted_q_n_neg_acc_reconstr_0  = plt.plot(0.001*np.arange(0,np.size(q_n_neg_acc_reconstr_0),1), q_n_neg_acc_reconstr_0, "y",     linewidth=2.0)
#ploted_q_n_pos_acc_reconstr_0  = plt.plot(0.001*np.arange(0,np.size(q_n_pos_acc_reconstr_0),1), q_n_pos_acc_reconstr_0, "y--",   linewidth=2.0)
#ploted_n_neg_acc_posi_0,       = plt.plot(0.001*np.arange(0,np.size(n_neg_acc_posi_0),1), n_neg_acc_posi_0, "k",   linewidth=2.0)
#ploted_n_pos_acc_posi_0,                = plt.plot(0.001*np.arange(0,np.size(n_pos_acc_posi_0),1), n_pos_acc_posi_0, "k--", linewidth=2.0)


#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_acc_posi_0, ploted_n_pos_acc_posi_0, ploted_q_n_neg_acc_reconstr_0, ploted_q_n_pos_acc_reconstr_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$q_{neg.acc.rectr.0} (rad)$', '$q_{pos.acc.rectr.0} (rad)$',])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_0), -3.5, 3.5])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################compatibility q-q_ddot0 plot##############################









#############################compatibility q-q_ddot0_q_dddot0 plot##############################
#source_1 = open("saved_data/q_0.txt", "r")
#q_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_max.txt", "r")
#q_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_0_min.txt", "r")
#q_0_min = source_1.readlines()
#source_1.close()



#source_1 = open("saved_data/q_n_pos_jerk_acc_posi_reconstr_0.txt", "r")
#q_n_pos_jerk_acc_posi_reconstr_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_n_neg_jerk_acc_posi_reconstr_0.txt", "r")
#q_n_neg_jerk_acc_posi_reconstr_0 = source_1.readlines()
#source_1.close()


#source = open("saved_data/n1_neg_jerk_acc_posi_0.txt", "r")
#n1_neg_jerk_acc_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n1_pos_jerk_acc_posi_0.txt", "r")
#n1_pos_jerk_acc_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n2_neg_jerk_acc_posi_0.txt", "r")
#n2_neg_jerk_acc_posi_0 = source.readlines()
#source.close()

#source = open("saved_data/n2_pos_jerk_acc_posi_0.txt", "r")
#n2_pos_jerk_acc_posi_0 = source.readlines()
#source.close()

#plt.figure('q (Jerk_acc_Posi_comp) ')


#ploted_q_0,                         = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,              "b",   linewidth=2.0)
#ploted_q_n_pos_jerk_acc_posi_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_n_pos_jerk_acc_posi_reconstr_0),1), q_n_pos_jerk_acc_posi_reconstr_0, "y",     linewidth=2.0)
#ploted_q_n_neg_jerk_acc_posi_reconstr_0 = plt.plot(0.001*np.arange(0,np.size(q_n_neg_jerk_acc_posi_reconstr_0),1), q_n_neg_jerk_acc_posi_reconstr_0, "y--",   linewidth=2.0)
#ploted_q_0_max,          	    = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,          "r",   linewidth=2.0)
#ploted_q_0_min,                     = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,          "r",   linewidth=2.0)
#ploted_n1_neg_jerk_acc_posi_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_acc_posi_0),1), n1_neg_jerk_acc_posi_0, "k",   linewidth=2.0)
#ploted_n1_pos_jerk_acc_posi_0,           = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_acc_posi_0),1), n1_pos_jerk_acc_posi_0, "k--", linewidth=2.0)
#ploted_n2_neg_jerk_acc_posi_0,  = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_acc_posi_0),1), n2_neg_jerk_acc_posi_0, "m",   linewidth=2.0)
#ploted_n2_pos_jerk_acc_posi_0,  = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_acc_posi_0),1), n2_pos_jerk_acc_posi_0, "m--", linewidth=2.0)
#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n1_neg_jerk_acc_posi_0, ploted_n1_pos_jerk_acc_posi_0, n2_neg_jerk_acc_posi_0, n2_pos_jerk_acc_posi_0, ploted_q_n_pos_jerk_acc_posi_reconstr_0, ploted_q_n_neg_jerk_acc_posi_reconstr_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n1_{J.minimize}$', '$n1_{J.maximize}$', '$n2_{acc.minimize}$', '$n2_{acc.maximize}$', '$q_{posrectr.0} (rad)$', '$q_{negrectr.0} (rad)$'])


#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_0), -5, 15])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################compatibility q-q_ddot0_q_dddot0 plot##############################











###########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
#source_1 = open("saved_data/q_dotdotdot_0.txt", "r")
#q_dotdotdot_0 = source_1.readlines()
#source_1.close()


#source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
#q_dotdotdot_gurobi_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/constr_jerk.txt", "r")
#constr_jerk = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/constr_jerk.txt", "r")
#constr_jerk = source_1.readlines()
#source_1.close()


#source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
#q_dotdotdot_0_max = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
#q_dotdotdot_0_min = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_min_comp_0.txt", "r")
#q_dotdot_bounds_deriv_min_comp_0 = source_1.readlines()
#source_1.close()

#plt.figure('q_dot_dot_dot comp 0 q_dot_dot_dot_reconstruit_from_q_ddot_gurobi')



#ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "g",   linewidth=2.0)
#ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
#ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
#ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r--", linewidth=2.0)
#ploted_constr_jerk,                      = plt.plot(0.001*np.arange(0,np.size(constr_jerk),1),          constr_jerk,          "k",   linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),          q_dotdot_bounds_deriv_max_comp_0,          "m",   linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_min_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_min_comp_0),1),          q_dotdot_bounds_deriv_min_comp_0,          "m--",   linewidth=2.0)
#plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0, ploted_q_dotdot_bounds_deriv_min_comp_0, ploted_constr_jerk], ['$\dddot{q}_{real.0} (rad/s^3)$', '$\dddot{q}_{gurobi.0} (rad/s^3)$', '$\dddot{q_{M_{0}}} (rad/s^3)$', '$\dddot{q_{m_{0}}} (rad/s^3)$', '$\dddot{q}_{max.0.constr} (rad/s)$', '$\dddot{q}_{max.0.constr} (rad/s)$', '$\dddot{q}_{min.0.constr} (rad/s)$', '$const_jerk$'])

#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(q_dotdotdot_0), -50, 50])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
###########################q_dot_dot_dot  pour la comp posi_jerk plot##############################






##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
q_dotdotdot_gurobi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
source_1.close()


plt.figure('q_dot_dot_dot FINAL !!!')


ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r--", linewidth=2.0)
ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),   q_dotdot_bounds_deriv_max_comp_0,          "m--",   linewidth=2.0)

plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_{real.0} (rad/s^3)$', '$\dddot{q_{M_{0}}} (rad/s^3)$', '$\dddot{q_{m_{0}}} (rad/s^3)$', '$\dddot{q}_{max.0.constr} (rad/s^3)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_gurobi_0), -50, 50])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################











#############################tau_cmd VS tau_sensor plot##############################
#source = open("saved_data/tau_0.txt", "r")
#tau_0 = source.readlines()
#source.close()

#source = open("saved_data/tau_sensor_0.txt", "r")
#tau_sensor_0 = source.readlines()
#source.close()

#plt.figure('tau_cmd VS tau_sensor')

#ploted_tau_0, = plt.plot(0.001*np.arange(0,np.size(tau_0),1),          tau_0,          "g",   linewidth=2.0)
#ploted_tau_sensor_0, = plt.plot(0.001*np.arange(0,np.size(tau_sensor_0),1),          tau_sensor_0,          "r",   linewidth=2.0)

#plt.legend([ploted_tau_0, ploted_tau_sensor_0], ['$tau_0 (N.m)$', '$tau_{0.sensor} (N.m)$'])


#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(tau_0), -20, 20])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
#############################tau_cmd VS tau_sensor plot##############################

























#############################compatibility q-q_dddot0 plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_n_neg_jerk_posi_reconstr_0.txt", "r")
q_n_neg_jerk_posi_reconstr_0 = source_1.readlines()
source_1.close()

source = open("saved_data/n1_neg_jerk_posi_explored_0.txt", "r")
n1_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n2_neg_jerk_posi_explored_0.txt", "r")
n2_neg_jerk_posi_explored_0 = source.readlines()
source.close()

plt.figure('q (Comp_jerk_posi complete formula FINAL !!!!!) ')


ploted_q_0,                                  = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,                                      "b",   linewidth=2.0)
ploted_q_0_max,          	             = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,                                  "r",   linewidth=2.0)
ploted_q_0_min,                              = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,                                  "r--",   linewidth=2.0)
ploted_q_n_neg_jerk_posi_reconstr_0          = plt.plot(0.001*np.arange(0,np.size(q_n_neg_jerk_posi_reconstr_0),1), q_n_neg_jerk_posi_reconstr_0, "y",   linewidth=2.0)
ploted_n1_neg_jerk_posi_explored_0,          = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_posi_explored_0),1), n1_neg_jerk_posi_explored_0,   "k",   linewidth=2.0)
ploted_n2_neg_jerk_posi_explored_0,          = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_posi_explored_0),1), n2_neg_jerk_posi_explored_0,   "k--",   linewidth=2.0)
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_q_n_neg_jerk_posi_reconstr_0, ploted_n1_neg_jerk_posi_explored_0, ploted_n2_neg_jerk_posi_explored_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$q_{rectr}$', '$n_{1exp.neg}$', '$n_{2exp.neg}$'])
#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_q_n_pos_jerk_posi_reconstr_0, ploted_q_n_neg_jerk_posi_reconstr_0, ploted_q_n_pos_jerk_posi_reconstr_explored_0, ploted_q_n_neg_jerk_posi_reconstr_explored_0, ploted_n1_neg_jerk_posi_explored_0, ploted_n1_neg_jerk_posi_explored_q_0, ploted_n2_neg_jerk_posi_explored_0, ploted_n2_neg_jerk_posi_explored_q_0, ploted_small_err], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$q_{posrectr}$', '$q_{negrectr}$', '$q_{posrectrexpl}$', '$q_{negrectrexpl}$', '$n_{1exp.neg}$', '$n_{1exp.q.neg}$', '$n_{2exp.neg}$', '$n_{2exp.q.neg}$', '$small_{err}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 5])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################








#############################compatibility q-q_dddot0 plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_n_neg_jerk_acc_posi_reconstr_0.txt", "r")
q_n_neg_jerk_acc_posi_reconstr_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_n_neg_Jerk_acc_Posi_reconstr_explored_0.txt", "r")
q_n_neg_Jerk_acc_Posi_reconstr_explored_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()


plt.figure('q (Comp_jerk_posi_acc complete formula FINAL !!!!!) ')


ploted_q_0,                                       = plt.plot(0.001*np.arange(0,np.size(q_0),1),                                       q_0,                                       "b",   linewidth=2.0)
ploted_q_0_max,          	                  = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                                   q_0_max,                                   "r",   linewidth=2.0)
ploted_q_0_min,                                   = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),                                   q_0_min,                                   "r--", linewidth=2.0)
#ploted_q_n_neg_jerk_acc_posi_reconstr_0           = plt.plot(0.001*np.arange(0,np.size(q_n_neg_jerk_acc_posi_reconstr_0),1),          q_n_neg_jerk_acc_posi_reconstr_0,          "y",   linewidth=2.0)
#ploted_q_n_neg_Jerk_acc_Posi_reconstr_explored_0  = plt.plot(0.001*np.arange(0,np.size(q_n_neg_Jerk_acc_Posi_reconstr_explored_0),1), q_n_neg_Jerk_acc_Posi_reconstr_explored_0, "c",   linewidth=2.0)
ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "k",   linewidth=2.0)
ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "m",   linewidth=2.0)
ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "k--", linewidth=2.0)

#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_q_n_neg_jerk_acc_posi_reconstr_0, ploted_q_n_neg_Jerk_acc_Posi_reconstr_explored_0, ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$q_{|k+n_{1}+n_{2}+n_{3}}$', '$q_{|k+n_{1}+n_{2}+n_{3}}$', '$n_{1}$', '$n_{2}$', '$n_{3}$'])
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n_{1}$', '$n_{2}$', '$n_{3}$'])
#plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_q_n_neg_jerk_acc_posi_reconstr_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 5])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################






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


source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()


plt.figure('q_dot 0 avec q_dot_n_comp_vel_jerk_reconstr FINAL !!!!')

ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),          q_dot_0,          "b",   linewidth=2.0)
ploted_q_dot_0_max,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),      q_dot_0_max,      "r",   linewidth=2.0)
ploted_q_dot_0_min,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1),      q_dot_0_min,      "r--", linewidth=2.0)
ploted_n_neg_jerk_vel_0,                        = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1), n_neg_jerk_vel_0, "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0,                        = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1), n_pos_jerk_vel_0, "k--", linewidth=2.0)


plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min, ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0], ['$\dot{q}_0 (rad/s)$', '$\dot{q}_{m_{0}} (rad/s)$', '$\dot{q}_{M_{0}} (rad/s)$', '$n_{minimize}$', '$n_{maximize}$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -3, 3])
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


plt.figure('q_dot_dot comp ZOOOM !!!')



ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,                   "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r--",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r:",   linewidth=2.0)



plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp], ['$\ddot{q}_{0}$', '$\ddot{q}_{M_{0}}$', '$\ddot{q}_{m_{0}}$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^2)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -4, 14])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################










##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
q_dotdotdot_gurobi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()


plt.figure('q_dot_dot_dot ZOOOM !!!')


ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r--",   linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r:", linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),   q_dotdot_bounds_deriv_max_comp_0,          "m--",   linewidth=2.0)

#plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_{0}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$', '$\dddot{q}_{max.0.constr}$'])
plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min], ['$\dddot{q}_{0}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^3)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_gurobi_0), -35, 35])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################







##############################compatibility q-q_dddot0 plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()


source = open("saved_data/n_neg_jerk_posi_explored_0.txt", "r")
n_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_explored_0.txt", "r")
n_pos_jerk_posi_explored_0 = source.readlines()
source.close()

plt.figure('q (Jerk_Posi_comp Explored n_neg n_pos) ')


ploted_q_0,                         = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,              "b",   linewidth=2.0)
ploted_q_0_max,          	    = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,          "r",   linewidth=2.0)
ploted_q_0_min,                     = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,          "r",   linewidth=2.0)


ploted_n_neg_jerk_posi_explored_0,  = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_explored_0),1), n_neg_jerk_posi_explored_0, "m",   linewidth=2.0)
ploted_n_pos_jerk_posi_explored_0,  = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_explored_0),1), n_pos_jerk_posi_explored_0, "m--", linewidth=2.0)
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min,  ploted_n_neg_jerk_posi_explored_0, ploted_n_pos_jerk_posi_explored_0], ['$q_0 (rad)$', '$q_{M_{0}} (rad)$', '$q_{m_{0}} (rad)$', '$n_{exp.maximize}$', '$n_{exp.mminimize}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 15])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################









#########################################################################PLOT n###########################################################

#############################n plot comp everything##############################
#n pour comp vel jerk
source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()



#n for comp posi acc
source = open("saved_data/n_neg_acc_posi_0.txt", "r")
n_neg_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_acc_posi_0.txt", "r")
n_pos_acc_posi_0 = source.readlines()
source.close()



#n for comp posi jerk incomplete
source = open("saved_data/n_neg_jerk_posi_explored_0.txt", "r")
n_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_explored_0.txt", "r")
n_pos_jerk_posi_explored_0 = source.readlines()
source.close()


#n for comp posi jerk complete
source = open("saved_data/n1_neg_jerk_posi_explored_0.txt", "r")
n1_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n2_neg_jerk_posi_explored_0.txt", "r")
n2_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n1_pos_jerk_posi_explored_0.txt", "r")
n1_pos_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n2_pos_jerk_posi_explored_0.txt", "r")
n2_pos_jerk_posi_explored_0 = source.readlines()
source.close()


#n for comp posi acc jerk incomplete
source = open("saved_data/n1_neg_jerk_acc_posi_0.txt", "r")
n1_neg_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n1_pos_jerk_acc_posi_0.txt", "r")
n1_pos_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n2_neg_jerk_acc_posi_0.txt", "r")
n2_neg_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n2_pos_jerk_acc_posi_0.txt", "r")
n2_pos_jerk_acc_posi_0 = source.readlines()
source.close()



#n for comp posi acc jerk complete
source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", "r")
n1_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", "r")
n2_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", "r")
n3_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()



plt.figure('n_khalota FINAL !!!')






#n pour comp vel jerk
ploted_n_neg_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1),                          n_neg_jerk_vel_0,                          "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1),                          n_pos_jerk_vel_0,                          "k--", linewidth=2.0)

##n for comp posi acc
#ploted_n_neg_acc_posi_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_acc_posi_0),1),                          n_neg_acc_posi_0,                          "k",   linewidth=2.0)
#ploted_n_pos_acc_posi_0,                          = plt.plot(0.001*np.arange(0,np.size(n_pos_acc_posi_0),1),                          n_pos_acc_posi_0,                          "k--", linewidth=2.0)

##n for comp posi jerk incomplete
#ploted_n_neg_jerk_posi_explored_0,                = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_explored_0),1),                n_neg_jerk_posi_explored_0,                "k",   linewidth=2.0)
#ploted_n_pos_jerk_posi_explored_0,                = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_explored_0),1),                n_pos_jerk_posi_explored_0,                "k--", linewidth=2.0)

##n for comp posi jerk complete
#ploted_n1_neg_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_posi_explored_0),1),               n1_neg_jerk_posi_explored_0,               "k",   linewidth=2.0)
#ploted_n2_neg_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_posi_explored_0),1),               n2_neg_jerk_posi_explored_0,               "m",   linewidth=2.0)
#ploted_n1_pos_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_posi_explored_0),1),               n1_pos_jerk_posi_explored_0,               "k--", linewidth=2.0)
#ploted_n2_pos_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_posi_explored_0),1),               n2_pos_jerk_posi_explored_0,               "m--", linewidth=2.0)

##n for comp posi acc jerk incomplete 
#ploted_n1_neg_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_acc_posi_0),1),                    n1_neg_jerk_acc_posi_0,                    "k",   linewidth=2.0)
#ploted_n1_pos_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_acc_posi_0),1),                    n1_pos_jerk_acc_posi_0,                    "k--", linewidth=2.0)
#ploted_n2_neg_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_acc_posi_0),1),                    n2_neg_jerk_acc_posi_0,                    "m",   linewidth=2.0)
#ploted_n2_pos_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_acc_posi_0),1),                    n2_pos_jerk_acc_posi_0,                    "m--", linewidth=2.0)

#n for comp posi acc jerk complete 
ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "k",   linewidth=2.0)
ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "m",   linewidth=2.0)
ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "g",   linewidth=2.0)
ploted_n1_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_pos_Jerk_acc_Posi_explored_0),1),           n1_pos_Jerk_acc_Posi_explored_0,           "k--", linewidth=2.0)
ploted_n2_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_pos_Jerk_acc_Posi_explored_0),1),           n2_pos_Jerk_acc_Posi_explored_0,           "m--", linewidth=2.0)
ploted_n3_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_pos_Jerk_acc_Posi_explored_0),1),           n3_pos_Jerk_acc_Posi_explored_0,           "g--", linewidth=2.0)


##n pour comp vel jerk
#plt.legend([ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0], ['$n_{1}$', '$n_{2}$'])

##n for comp posi acc
#plt.legend([ploted_n_neg_acc_posi_0, ploted_n_pos_acc_posi_0], ['$n_{3}$', '$n_{4}$'])

##n for comp posi jerk incomplete
#plt.legend([ploted_n_neg_jerk_posi_explored_0, ploted_n_pos_jerk_posi_explored_0], ['$n_{5}$', '$n_{6}$'])

##n for comp posi jerk complete
#plt.legend([ploted_n1_neg_jerk_posi_explored_0, ploted_n2_neg_jerk_posi_explored_0, ploted_n1_pos_jerk_posi_explored_0, ploted_n2_pos_jerk_posi_explored_0], ['$n_{7}$', '$n_{8}$', '$n_{9}$', '$n_{10}$'])

#n for comp posi acc jerk incomplete
#plt.legend([ploted_n1_neg_jerk_acc_posi_0, n2_neg_jerk_acc_posi_0, ploted_n1_pos_jerk_acc_posi_0, n2_pos_jerk_acc_posi_0], ['$n_{11}$', '$n_{12}$', '$n_{13}$', '$n_{14}$'])

#n for comp posi acc jerk complete 
#plt.legend([ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0, ploted_n1_pos_Jerk_acc_Posi_explored_0, ploted_n2_pos_Jerk_acc_Posi_explored_0, ploted_n3_pos_Jerk_acc_Posi_explored_0], ['$n_{15}$', '$n_{16}$', '$n_{17}$', '$n_{18}$', '$n_{19}$', '$n_{20}$'])

#n for all
plt.legend([ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0, ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0, ploted_n1_pos_Jerk_acc_Posi_explored_0, ploted_n2_pos_Jerk_acc_Posi_explored_0, ploted_n3_pos_Jerk_acc_Posi_explored_0], ['$n_{1}$', '$n_{15}$', '$n_{16}$', '$n_{17}$', '$n_{18}$', '$n_{19}$', '$n_{20}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n plot comp everything##############################













##############################n pour comp vel jerk##############################
#n pour comp vel jerk
source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()


plt.figure('n pour comp vel jerk FINAL !!!')

#n pour comp vel jerk
ploted_n_neg_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1),                          n_neg_jerk_vel_0,                          "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1),                          n_pos_jerk_vel_0,                          "k--", linewidth=2.0)

#n pour comp vel jerk
plt.legend([ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0], ['$n_{1}$', '$n_{2}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##############################n pour comp vel jerk##############################















#############################n for comp posi acc##############################
#n for comp posi acc
source = open("saved_data/n_neg_acc_posi_0.txt", "r")
n_neg_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_acc_posi_0.txt", "r")
n_pos_acc_posi_0 = source.readlines()
source.close()

plt.figure('n for comp posi acc FINAL !!!')


#n for comp posi acc
ploted_n_neg_acc_posi_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_acc_posi_0),1),                          n_neg_acc_posi_0,                          "k",   linewidth=2.0)
ploted_n_pos_acc_posi_0,                          = plt.plot(0.001*np.arange(0,np.size(n_pos_acc_posi_0),1),                          n_pos_acc_posi_0,                          "k--", linewidth=2.0)


#n for comp posi acc
plt.legend([ploted_n_neg_acc_posi_0, ploted_n_pos_acc_posi_0], ['$n_{3}$', '$n_{4}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for comp posi acc##############################












#############################n for comp posi jerk incomplete##############################
#n for comp posi jerk incomplete
source = open("saved_data/n_neg_jerk_posi_explored_0.txt", "r")
n_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_explored_0.txt", "r")
n_pos_jerk_posi_explored_0 = source.readlines()
source.close()

plt.figure('n for comp posi jerk incomplete FINAL !!!')

#n for comp posi jerk incomplete
ploted_n_neg_jerk_posi_explored_0,                = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_explored_0),1),                n_neg_jerk_posi_explored_0,                "k",   linewidth=2.0)
ploted_n_pos_jerk_posi_explored_0,                = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_explored_0),1),                n_pos_jerk_posi_explored_0,                "k--", linewidth=2.0)

#n for comp posi jerk incomplete
plt.legend([ploted_n_neg_jerk_posi_explored_0, ploted_n_pos_jerk_posi_explored_0], ['$n_{5}$', '$n_{6}$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for comp posi jerk incomplete##############################















#############################n for comp posi jerk complete##############################
#n for comp posi jerk complete
source = open("saved_data/n1_neg_jerk_posi_explored_0.txt", "r")
n1_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n2_neg_jerk_posi_explored_0.txt", "r")
n2_neg_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n1_pos_jerk_posi_explored_0.txt", "r")
n1_pos_jerk_posi_explored_0 = source.readlines()
source.close()

source = open("saved_data/n2_pos_jerk_posi_explored_0.txt", "r")
n2_pos_jerk_posi_explored_0 = source.readlines()
source.close()


plt.figure('n for comp posi jerk complete FINAL !!!')


#n for comp posi jerk complete
ploted_n1_neg_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_posi_explored_0),1),               n1_neg_jerk_posi_explored_0,               "k",   linewidth=2.0)
ploted_n2_neg_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_posi_explored_0),1),               n2_neg_jerk_posi_explored_0,               "m",   linewidth=2.0)
ploted_n1_pos_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_posi_explored_0),1),               n1_pos_jerk_posi_explored_0,               "k--", linewidth=2.0)
ploted_n2_pos_jerk_posi_explored_0,               = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_posi_explored_0),1),               n2_pos_jerk_posi_explored_0,               "m--", linewidth=2.0)

#n for comp posi jerk complete
plt.legend([ploted_n1_neg_jerk_posi_explored_0, ploted_n2_neg_jerk_posi_explored_0, ploted_n1_pos_jerk_posi_explored_0, ploted_n2_pos_jerk_posi_explored_0], ['$n_{7}$', '$n_{8}$', '$n_{9}$', '$n_{10}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for comp posi jerk complete##############################











#############################n for comp posi acc jerk incomplete##############################
#n for comp posi acc jerk incomplete
source = open("saved_data/n1_neg_jerk_acc_posi_0.txt", "r")
n1_neg_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n1_pos_jerk_acc_posi_0.txt", "r")
n1_pos_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n2_neg_jerk_acc_posi_0.txt", "r")
n2_neg_jerk_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n2_pos_jerk_acc_posi_0.txt", "r")
n2_pos_jerk_acc_posi_0 = source.readlines()
source.close()

plt.figure('n for comp posi acc jerk incomplete FINAL !!!')

#n for comp posi acc jerk incomplete 
ploted_n1_neg_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_acc_posi_0),1),                    n1_neg_jerk_acc_posi_0,                    "k",   linewidth=2.0)
ploted_n1_pos_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n1_pos_jerk_acc_posi_0),1),                    n1_pos_jerk_acc_posi_0,                    "k--", linewidth=2.0)
ploted_n2_neg_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_acc_posi_0),1),                    n2_neg_jerk_acc_posi_0,                    "m",   linewidth=2.0)
ploted_n2_pos_jerk_acc_posi_0,                    = plt.plot(0.001*np.arange(0,np.size(n2_pos_jerk_acc_posi_0),1),                    n2_pos_jerk_acc_posi_0,                    "m--", linewidth=2.0)

#n for comp posi acc jerk incomplete 
plt.legend([ploted_n1_neg_jerk_acc_posi_0, n2_neg_jerk_acc_posi_0, ploted_n1_pos_jerk_acc_posi_0, n2_pos_jerk_acc_posi_0], ['$n_{11}$', '$n_{12}$', '$n_{13}$', '$n_{14}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for comp posi acc jerk incomplete##############################









#############################n for comp posi acc jerk complete##############################
#n for comp posi acc jerk complete
source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", "r")
n1_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", "r")
n2_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", "r")
n3_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()


plt.figure('n for comp posi acc jerk complete FINAL !!!')


#n for comp posi acc jerk complete 
ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "k",   linewidth=2.0)
ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "m",   linewidth=2.0)
ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "g",   linewidth=2.0)
ploted_n1_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_pos_Jerk_acc_Posi_explored_0),1),           n1_pos_Jerk_acc_Posi_explored_0,           "k--", linewidth=2.0)
ploted_n2_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_pos_Jerk_acc_Posi_explored_0),1),           n2_pos_Jerk_acc_Posi_explored_0,           "m--", linewidth=2.0)
ploted_n3_pos_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_pos_Jerk_acc_Posi_explored_0),1),           n3_pos_Jerk_acc_Posi_explored_0,           "g--", linewidth=2.0)

#n for comp posi acc jerk complete 
plt.legend([ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0, ploted_n1_pos_Jerk_acc_Posi_explored_0, ploted_n2_pos_Jerk_acc_Posi_explored_0, ploted_n3_pos_Jerk_acc_Posi_explored_0], ['$n_{15}$', '$n_{16}$', '$n_{17}$', '$n_{18}$', '$n_{19}$', '$n_{20}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), 0, 1200])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for comp posi acc jerk complete##############################

































##FINAL PLOTS
###########################q_0 plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()


source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()



#plt.figure(' q FINAL !!!')
plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
plt.figure(figsize=(10,10))
ax1 = plt.subplot2grid((4,1), (0,0), colspan=1)
#ax1.set_title('-a-')

#plt.subplot(4, 1, 1)


ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
ploted_q_0_des,                = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                "g--",   linewidth=2.0)

plt.legend([ploted_q_0, ploted_q_0_des], ['$q_{0}$', '$q_{0}^*$'])

#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), 0.4, 4.2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
###########################q_0 plot_comp FINAL DEBUG##############################

#############################compatibility q_dot-q_dddot0 plot##############################


source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()

#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax2 = plt.subplot2grid((4,1), (1,0), colspan=1)
#ax2.set_title('-b-')
#plt.subplot(4, 1, 2)

ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),                                       q_dot_0,                                       "b",  linewidth=2.0)

plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min], ['$\dot{q}_0$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -0.4, 3])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q_dot-q_dddot0 plot##############################

############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()



#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax3 = plt.subplot2grid((4,1), (2,0), colspan=1)
#ax3.set_title('-c-')
#plt.subplot(4, 1, 3)



ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,                   "b",   linewidth=2.0)



plt.legend([ploted_q_dotdot_0], ['$\ddot{q}_{0}$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^2)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -4, 8])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################

##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
q_dotdotdot_gurobi_0 = source_1.readlines()
source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()



#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax4 = plt.subplot2grid((4,1), (3,0), colspan=1)
#ax4.set_title('-d-')
#plt.subplot(4, 1, 4)

ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)

#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),   q_dotdot_bounds_deriv_max_comp_0,          "m--",   linewidth=2.0)

#plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_{0}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$', '$\dddot{q}_{max.0.constr}$'])
plt.legend([ploted_q_dotdotdot_gurobi_0], ['$\dddot{q}_{0}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^3)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_gurobi_0), -20, 35])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################


##############################n for all##############################
##n pour comp vel jerk
#source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
#n_neg_jerk_vel_0 = source.readlines()
#source.close()

#source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
#n_pos_jerk_vel_0 = source.readlines()
#source.close()


##n for comp posi acc jerk complete
#source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
#n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
#n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
#n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", "r")
#n1_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", "r")
#n2_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()

#source_1 = open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", "r")
#n3_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
#source_1.close()


##plt.figure('n for all FINAL !!!')
##plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
#ax5 = plt.subplot2grid((5,1), (4,0), rowspan=1)
##ax5.set_title('-e-')

##n pour comp vel jerk
#ploted_n_neg_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1),                          n_neg_jerk_vel_0,                          "k",   linewidth=2.0)


##n for comp posi acc jerk complete 
#ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "b",   linewidth=2.0)
#ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "m",   linewidth=2.0)
#ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "g",   linewidth=2.0)


##n for all
#plt.legend([ploted_n_neg_jerk_vel_0, ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0], ['$n_{1}$', '$n_{15}$', '$n_{16}$', '$n_{17}$'])


#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), -10, 610])
#plt.ticklabel_format(useOffset=False)
#plt.grid(True)
##############################n for all##############################































##FINAUX !!!!!!!!!
##FINAL PLOTS
###########################q_0 plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

#plt.figure(' q FINAL !!!')
plt.figure('comp q, q_ddot, q_dddot FINAL3 !!!')
plt.figure(figsize=(10,10))
ax1 = plt.subplot2grid((5,1), (0,0), colspan=1)
#ax1.set_title('-a-')

#plt.subplot(4, 1, 1)


ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r--",   linewidth=2.0)


plt.legend([ploted_q_0, ploted_q_0_max], ['$q_{0}$', '$q_{M_{0}}$'])

#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), 0.1, 3.2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
###########################q_0 plot_comp FINAL DEBUG##############################

#############################compatibility q_dot-q_dddot0 plot##############################
source_1 = open("saved_data/q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0.txt", "r")
q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()

#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax2 = plt.subplot2grid((5,1), (1,0), colspan=1)
#ax2.set_title('-b-')
#plt.subplot(4, 1, 2)

ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),                                       q_dot_0,                                       "b",  linewidth=2.0)
ploted_q_dot_0_max,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),                                   q_dot_0_max,                                   "r--",  linewidth=2.0)

#ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0,      "m",  linewidth=2.0)

plt.legend([ploted_q_dot_0, ploted_q_dot_0_max], ['$\dot{q}_0$', '$\dot{q}_{M_{0}}$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -0.4, 3])
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



#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax3 = plt.subplot2grid((5,1), (2,0), colspan=1)
#ax3.set_title('-c-')
#plt.subplot(4, 1, 3)



ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,                   "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "m--",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r:",   linewidth=2.0)



plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp], ['$\ddot{q}_{0}$', '$f_{\psi}$', '$\ddot{q}_{m_{0}}$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^2)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -5, 11])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################

##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
q_dotdotdot_gurobi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()



#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax4 = plt.subplot2grid((5,1), (3,0), colspan=1)
#ax4.set_title('-d-')
#plt.subplot(4, 1, 4)

ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r--", linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r:",  linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),   q_dotdot_bounds_deriv_max_comp_0,          "m--",   linewidth=2.0)

#plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_{0}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$', '$\dddot{q}_{max.0.constr}$'])
plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min], ['$\dddot{q_{0}}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^3)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_gurobi_0), -35, 35])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################


#############################n for all##############################
#n pour comp vel jerk
source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()


#n for comp posi acc jerk complete
source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", "r")
n1_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", "r")
n2_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", "r")
n3_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()


#plt.figure('n for all FINAL !!!')
#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax5 = plt.subplot2grid((5,1), (4,0), rowspan=1)
#ax5.set_title('-e-')

#n pour comp vel jerk
ploted_n_neg_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1),                          n_neg_jerk_vel_0,                          "k",   linewidth=2.0)


#n for comp posi acc jerk complete 
ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "b",   linewidth=2.0)
ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "c",   linewidth=2.0)
ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "g",   linewidth=2.0)


#n for all
plt.legend([ploted_n_neg_jerk_vel_0, ploted_n1_neg_Jerk_acc_Posi_explored_0, ploted_n2_neg_Jerk_acc_Posi_explored_0, ploted_n3_neg_Jerk_acc_Posi_explored_0], ['$n_{1}$', '$n_{15}$', '$n_{16}$', '$n_{17}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), -200, 620])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for all##############################























##ZOOMZ !!!!!!!!!
###########################q_0 plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

#plt.figure(' q FINAL !!!')
plt.figure('ZOOMZ !!!')
plt.figure(figsize=(9,7))
ax1 = plt.subplot2grid((4,2), (0,0), colspan=1, rowspan=1)
#ax1.set_title('-a-')

#plt.subplot(4, 1, 1)


ploted_q_0,                    = plt.plot(0.001*np.arange(0,np.size(q_0),1),                    q_0,                    "b",   linewidth=2.0)
ploted_q_0_max,                = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),                q_0_max,                "r--",   linewidth=2.0)


plt.legend(['$z_{18}$'])

#plt.xlabel("$time (s)$", fontsize=20)

plt.axis([0,0.001*np.size(q_0), 0.1, 3.2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
###########################q_0 plot_comp FINAL DEBUG##############################

#############################compatibility q_dot-q_dddot0 plot##############################
source_1 = open("saved_data/q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0.txt", "r")
q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()


#plt.figure(figsize=(10,10))
ax1 = plt.subplot2grid((4,2), (1,0), colspan=1)
#ax2.set_title('-b-')
#plt.subplot(4, 1, 2)

ploted_q_dot_0,                                 = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),                                       q_dot_0,                                       "b",  linewidth=2.0)
ploted_q_dot_0_max,                             = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),                                   q_dot_0_max,                                   "r--",  linewidth=2.0)

#ploted_q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0 = plt.plot(0.001*np.arange(0,np.size(q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0),1),      q_dot_bounds_max_comp_Acc_Posi_vel_cmd_0,      "m",  linewidth=2.0)

plt.legend(['$z_{19}$'])


#plt.xlabel("$time (s)$", fontsize=20)

plt.axis([0,0.001*np.size(q_dot_0), -0.4, 3])
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




#plt.figure(figsize=(10,10))
ax1 = plt.subplot2grid((4,2), (0,1), rowspan=2)
#ax3.set_title('-c-')
#plt.subplot(4, 1, 3)



ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,                   "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "m--",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r:",   linewidth=2.0)



plt.legend(['$z_{20}$'])


#plt.xlabel("$time (s)$", fontsize=20)

plt.axis([0,0.001*np.size(q_dotdot_0), -5, 11])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################

##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################
source_1 = open("saved_data/q_dotdotdot_gurobi_0.txt", "r")
q_dotdotdot_gurobi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_max.txt", "r")
q_dotdotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_0_min.txt", "r")
q_dotdotdot_0_min = source_1.readlines()
source_1.close()

#source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
#q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
#source_1.close()




#plt.figure(figsize=(10,10))
ax1 = plt.subplot2grid((4,2), (2,0), rowspan=2)
#ax4.set_title('-d-')
#plt.subplot(4, 1, 4)

ploted_q_dotdotdot_gurobi_0,   = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_gurobi_0),1),   q_dotdotdot_gurobi_0,   "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r--", linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r:",  linewidth=2.0)
#ploted_q_dotdot_bounds_deriv_max_comp_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),   q_dotdot_bounds_deriv_max_comp_0,          "m--",   linewidth=2.0)

#plt.legend([ploted_q_dotdotdot_gurobi_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_{0}$', '$\dddot{q_{M_{0}}}$', '$\dddot{q_{m_{0}}}$', '$\dddot{q}_{max.0.constr}$'])
plt.legend(['$z_{21}$'])




plt.axis([0,0.001*np.size(q_dotdotdot_gurobi_0), -35, 35])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
##########################q_dot_dot_dot  pour la comp posi_jerk plot##############################


#############################n for all##############################
#n pour comp vel jerk
source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
n_neg_jerk_vel_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
n_pos_jerk_vel_0 = source.readlines()
source.close()


#n for comp posi acc jerk complete
source_1 = open("saved_data/n1_neg_Jerk_acc_Posi_explored_0.txt", "r")
n1_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_Jerk_acc_Posi_explored_0.txt", "r")
n2_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_neg_Jerk_acc_Posi_explored_0.txt", "r")
n3_neg_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n1_pos_Jerk_acc_Posi_explored_0.txt", "r")
n1_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_pos_Jerk_acc_Posi_explored_0.txt", "r")
n2_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n3_pos_Jerk_acc_Posi_explored_0.txt", "r")
n3_pos_Jerk_acc_Posi_explored_0 = source_1.readlines()
source_1.close()


#plt.figure('n for all FINAL !!!')
#plt.figure('comp q, q_ddot, q_dddot FINAL2 !!!')
ax1 = plt.subplot2grid((4,2), (2,1), rowspan=2)
#ax5.set_title('-e-')

#n pour comp vel jerk
ploted_n_neg_jerk_vel_0,                          = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1),                          n_neg_jerk_vel_0,                          "k",   linewidth=2.0)


#n for comp posi acc jerk complete 
ploted_n1_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n1_neg_Jerk_acc_Posi_explored_0),1),           n1_neg_Jerk_acc_Posi_explored_0,           "b",   linewidth=2.0)
ploted_n2_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n2_neg_Jerk_acc_Posi_explored_0),1),           n2_neg_Jerk_acc_Posi_explored_0,           "c",   linewidth=2.0)
ploted_n3_neg_Jerk_acc_Posi_explored_0,           = plt.plot(0.001*np.arange(0,np.size(n3_neg_Jerk_acc_Posi_explored_0),1),           n3_neg_Jerk_acc_Posi_explored_0,           "g",   linewidth=2.0)


#n for all
plt.legend(['$z_{22}$'])



plt.axis([0,0.001*np.size(n_neg_jerk_vel_0), -200, 620])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################n for all##############################








####compute max min acceleration instant#######"
############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_bounds_min_optimized_0.txt", "r")
q_dotdot_bounds_min_optimized_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_0.txt", "r")
q_dotdot_bounds_max_optimized_0 = source_1.readlines()
source_1.close()


plt.figure('INSTANT ARTICULAR ACCELERATION  !!!')



ploted_q_dotdot_bounds_min_optimized_0,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_optimized_0),1),             q_dotdot_bounds_min_optimized_0,          "r--",   linewidth=2.0)
ploted_q_dotdot_bounds_max_optimized_0,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_optimized_0),1),             q_dotdot_bounds_max_optimized_0,          "r",   linewidth=2.0)


plt.legend([ploted_q_dotdot_bounds_max_optimized_0, ploted_q_dotdot_bounds_min_optimized_0], ['$\ddot{q}_{M_{0}}^{inst}$', '$\ddot{q}_{m_{0}}^{inst}$'])


#plt.xlabel("$time (s)$", fontsize=20)
plt.ylabel("$(rad/s^2)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -3800, 3800])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################

plt.show()



