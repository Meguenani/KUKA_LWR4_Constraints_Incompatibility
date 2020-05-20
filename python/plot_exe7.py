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







#############################Acceleration plot##############################
source = open("saved_data/Acc_7.txt", "r")
Acc_7 = source.readlines()
source.close()

source = open("saved_data/Acc_7_des.txt", "r")
Acc_7_des = source.readlines()
source.close()

plt.figure('Acc_7')
plt.subplot(2, 2, 1)

ploted_Acc_7,       = plt.plot(0.001*np.arange(0,np.size(Acc_7),1),       Acc_7,       "b",   linewidth=2.0)
ploted_Acc_7_des,   = plt.plot(0.001*np.arange(0,np.size(Acc_7_des),1),   Acc_7_des,   "r--", linewidth=2.0)

plt.legend([ploted_Acc_7, ploted_Acc_7_des], ['$|\ddot{X}|$', '$|\ddot{X^*}_{des}|$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/Acc_7_x.txt", "r")
Acc_7_x = source.readlines()
source.close()

source = open("saved_data/Acc_7_des_x.txt", "r")
Acc_7_des_x = source.readlines()
source.close()

plt.figure('Acc_7')
plt.subplot(2, 2, 2)

ploted_Acc_7_x,     = plt.plot(0.001*np.arange(0,np.size(Acc_7_x),1),     Acc_7_x,     "b",   linewidth=2.0)
ploted_Acc_7_des_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_des_x),1), Acc_7_des_x, "r--", linewidth=2.0)

plt.legend([ploted_Acc_7_x, ploted_Acc_7_des_x], ['$\ddot{X_x}$', '$\ddot{X^*}_x$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_x), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/Acc_7_y.txt", "r")
Acc_7_y = source.readlines()
source.close()

source = open("saved_data/Acc_7_des_y.txt", "r")
Acc_7_des_y = source.readlines()
source.close()

plt.figure('Acc_7')
plt.subplot(2, 2, 3)

ploted_Acc_7_y,     = plt.plot(0.001*np.arange(0,np.size(Acc_7_y),1),     Acc_7_y,     "b",   linewidth=2.0)
ploted_Acc_7_des_y, = plt.plot(0.001*np.arange(0,np.size(Acc_7_des_y),1), Acc_7_des_y, "r--", linewidth=2.0)

plt.legend([ploted_Acc_7_y, ploted_Acc_7_des_y], ['$\ddot{X_y}$', '$\ddot{X^*}_y$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_y), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/Acc_7_z.txt", "r")
Acc_7_z = source.readlines()
source.close()

source = open("saved_data/Acc_7_des_z.txt", "r")
Acc_7_des_z = source.readlines()
source.close()

plt.figure('Acc_7')
plt.subplot(2, 2, 4)

ploted_Acc_7_z,     = plt.plot(0.001*np.arange(0,np.size(Acc_7_z),1),     Acc_7_z,     "b",   linewidth=2.0)
ploted_Acc_7_des_z, = plt.plot(0.001*np.arange(0,np.size(Acc_7_des_z),1), Acc_7_des_z, "r--", linewidth=2.0)

plt.legend([ploted_Acc_7_z, ploted_Acc_7_des_y], ['$\ddot{X_z}$', '$\ddot{X^*}_z$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_z), -1, 2])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################Acceleration plot##############################



















#############################REAL Jerk plot##############################
source = open("saved_data/Jerk_7.txt", "r")
Jerk_7 = source.readlines()
source.close()

source = open("saved_data/Jerk_7_des.txt", "r")
Jerk_7_des = source.readlines()
source.close()

plt.figure('Jerk_7')
plt.subplot(2, 2, 1)
	
ploted_Jerk_7,     = plt.plot(0.001*np.arange(0,np.size(Jerk_7),1),     Jerk_7,     "m--",  linewidth=2.0)
ploted_Jerk_7_des, = plt.plot(0.001*np.arange(0,np.size(Jerk_7_des),1), Jerk_7_des, "r",    linewidth=2.0)

plt.legend([ploted_Jerk_7, ploted_Jerk_7_des], ['$\dddot{X}$', '$\dddot{X^*}$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_z), -1, 14])
plt.ticklabel_format(useOffset=False)
plt.grid(True)



source = open("saved_data/Jerk_7_x.txt", "r")
Jerk_7_x = source.readlines()
source.close()

source = open("saved_data/Jerk_7_des_x.txt", "r")
Jerk_7_des_x = source.readlines()
source.close()

plt.figure('Jerk_7')
plt.subplot(2, 2, 2)
	
ploted_Jerk_7_x,     = plt.plot(0.001*np.arange(0,np.size(Jerk_7_x),1),     Jerk_7_x,     "m--",  linewidth=2.0)
ploted_Jerk_7_des_x, = plt.plot(0.001*np.arange(0,np.size(Jerk_7_des_x),1), Jerk_7_des_x, "r",    linewidth=2.0)

plt.legend([ploted_Jerk_7_x, ploted_Jerk_7_des_x], ['$\dddot{X}_x$', '$\dddot{X^*}_x$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_z), -4, 6])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/Jerk_7_y.txt", "r")
Jerk_7_y = source.readlines()
source.close()

source = open("saved_data/Jerk_7_des_y.txt", "r")
Jerk_7_des_y = source.readlines()
source.close()

plt.figure('Jerk_7')
plt.subplot(2, 2, 3)
	
ploted_Jerk_7_y,     = plt.plot(0.001*np.arange(0,np.size(Jerk_7_y),1),     Jerk_7_y,     "m--",  linewidth=2.0)
ploted_Jerk_7_des_y, = plt.plot(0.001*np.arange(0,np.size(Jerk_7_des_y),1), Jerk_7_des_y, "r",    linewidth=2.0)

plt.legend([ploted_Jerk_7_y, ploted_Jerk_7_des_y], ['$\dddot{X}_y$', '$\dddot{X^*}_y$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_z), -4, 6])
plt.ticklabel_format(useOffset=False)
plt.grid(True)


source = open("saved_data/Jerk_7_z.txt", "r")
Jerk_7_z = source.readlines()
source.close()

source = open("saved_data/Jerk_7_des_z.txt", "r")
Jerk_7_des_z = source.readlines()
source.close()

plt.figure('Jerk_7')
plt.subplot(2, 2, 4)
	
ploted_Jerk_7_z,     = plt.plot(0.001*np.arange(0,np.size(Jerk_7_z),1),     Jerk_7_z,     "m--",  linewidth=2.0)
ploted_Jerk_7_des_z, = plt.plot(0.001*np.arange(0,np.size(Jerk_7_des_z),1), Jerk_7_des_z, "r",    linewidth=2.0)

plt.legend([ploted_Jerk_7_z, ploted_Jerk_7_des_z], ['$\dddot{X}_z$', '$\dddot{X^*}_z$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Acc_7_z), -4, 6])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################DES Jerkeleration plot##############################













#############################compatibility q-q_ddot0 plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

source = open("saved_data/n_neg_acc_posi_0.txt", "r")
n_neg_acc_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_acc_posi_0.txt", "r")
n_pos_acc_posi_0 = source.readlines()
source.close()


plt.figure('q (Acc_Posi_comp)')


ploted_q_0,              = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,              "b",   linewidth=2.0)
ploted_q_0_max,          = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,          "r",   linewidth=2.0)
ploted_q_0_min,          = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,          "r",   linewidth=2.0)
ploted_n_neg_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_neg_acc_posi_0),1), n_neg_acc_posi_0, "k",   linewidth=2.0)
ploted_n_pos_acc_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_pos_acc_posi_0),1), n_pos_acc_posi_0, "k--", linewidth=2.0)
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_acc_posi_0, ploted_n_pos_acc_posi_0], ['$q_0 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 15])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_ddot0 plot##############################












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


plt.figure('q_dot (Vel_Jerk_comp)')

ploted_q_dot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1),          q_dot_0,          "b",   linewidth=2.0)
ploted_q_dot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1),      q_dot_0_max,      "r",   linewidth=2.0)
ploted_q_dot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1),      q_dot_0_min,      "r",   linewidth=2.0)
ploted_n_neg_jerk_vel_0, = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_vel_0),1), n_neg_jerk_vel_0, "k",   linewidth=2.0)
ploted_n_pos_jerk_vel_0, = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_vel_0),1), n_pos_jerk_vel_0, "k--", linewidth=2.0)
plt.legend([ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min, ploted_n_neg_jerk_vel_0, ploted_n_pos_jerk_vel_0], ['$\dot{q_0} (rad/s)$', '$\dot{q_0}_{max} (rad)$', '$\dot{q_0}_{min} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -5, 15])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q_dot-q_dddot0 plot##############################











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

source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
n_neg_jerk_posi_0 = source.readlines()
source.close()

source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
n_pos_jerk_posi_0 = source.readlines()
source.close()


plt.figure('q (Jerk_Posi_comp) ')


ploted_q_0,              = plt.plot(0.001*np.arange(0,np.size(q_0),1),              q_0,              "b",   linewidth=2.0)
ploted_q_0_max,          = plt.plot(0.001*np.arange(0,np.size(q_0_max),1),          q_0_max,          "r",   linewidth=2.0)
ploted_q_0_min,          = plt.plot(0.001*np.arange(0,np.size(q_0_min),1),          q_0_min,          "r",   linewidth=2.0)
ploted_n_neg_jerk_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_neg_jerk_posi_0),1), n_neg_jerk_posi_0, "k",   linewidth=2.0)
ploted_n_pos_jerk_posi_0, = plt.plot(0.001*np.arange(0,np.size(n_pos_jerk_posi_0),1), n_pos_jerk_posi_0, "k--", linewidth=2.0)
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min, ploted_n_neg_jerk_posi_0, ploted_n_pos_jerk_posi_0], ['$q_0 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$', '$n_{minimize}$', '$n_{maximize}$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 15])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q-q_dddot0 plot##############################





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


source_1 = open("saved_data/q_dotdot_bounds_deriv_max_comp_0.txt", "r")
q_dotdot_bounds_deriv_max_comp_0 = source_1.readlines()
source_1.close()


source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
n_pos_jerk_posi_0 = source.readlines()
source.close()
plt.figure('q_dot_dot_dot')








ploted_q_dotdotdot_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0),1),          q_dotdotdot_0,          "b",   linewidth=2.0)
ploted_q_dotdotdot_0_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_max),1),      q_dotdotdot_0_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_0_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_0_min),1),      q_dotdotdot_0_min,      "r",   linewidth=2.0)
ploted_q_dotdot_bounds_deriv_max_comp_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_deriv_max_comp_0),1),          q_dotdot_bounds_deriv_max_comp_0,          "m",   linewidth=2.0)
plt.legend([ploted_q_dotdotdot_0, ploted_q_dotdotdot_0_max, ploted_q_dotdotdot_0_min, n_neg_jerk_posi_0, n_pos_jerk_posi_0, ploted_q_dotdot_bounds_deriv_max_comp_0], ['$\dddot{q}_0 (rad/s)$', '$\dddot{q_0}_{max} (rad)$', '$\dddot{q_0}_{min} (rad)$', '$n_{minimize}$', '$n_{maximize}$', '$\dddot{q}_{0.constr} (rad/s)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_0), -600, 600])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot_dot plot##############################





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


plt.figure('q_dot_dot')


ploted_q_dotdot_0,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                      q_dotdot_0,              "b",   linewidth=2.0)
ploted_q_dotdot_0_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_max_comp),1),             q_dotdot_0_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_0_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0_min_comp),1),             q_dotdot_0_min_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_bounds_max_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_optimized_0),1), q_dotdot_bounds_max_optimized_0, "k",   linewidth=2.0)
ploted_q_dotdot_bounds_min_optimized_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_optimized_0),1), q_dotdot_bounds_min_optimized_0, "k--", linewidth=2.0)
plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_0_max_comp, ploted_q_dotdot_0_min_comp, ploted_q_dotdot_bounds_max_optimized_0, ploted_q_dotdot_bounds_min_optimized_0], ['$\ddot{q_0} (rad s^2)$', '$\ddot{q_0} max (rad s^2)$', '$\ddot{q_0} min (rad s^2)$', '$\ddot{q_0} max(rad s^2)$', '$\ddot{q_0} min (rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -100, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################






#############################status##############################
source = open("saved_data/status.txt", "r")
status = source.readlines()
source.close()

plt.figure('status')

	
plt.plot(status, "b",   linewidth=2.0)	
plt.plot([0]*np.size(status), "k")
plt.title("status")
plt.ylabel("status")
plt.xlabel("iteration")
plt.axis([0,np.size(status),0, 15])
#############################status##############################







############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_bounds_max_comp_Acc_Posi_0.txt", "r")
q_dotdot_bounds_max_comp_Acc_Posi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_comp_Acc_Posi_0.txt", "r")
q_dotdot_bounds_min_comp_Acc_Posi_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dotdot_bounds_max_comp_Jerk_Vel_0.txt", "r")
q_dotdot_bounds_max_comp_Jerk_Vel_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_comp_Jerk_Vel_0.txt", "r")
q_dotdot_bounds_min_comp_Jerk_Vel_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dotdot_bounds_max_comp_0.txt", "r")
q_dotdot_bounds_max_comp_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_comp_0.txt", "r")
q_dotdot_bounds_min_comp_0 = source_1.readlines()
source_1.close()

#source_1 = open("saved_data/domaines_Jerk_Vel_and_Acc_Posi_disconnected.txt", "r")
#domaines_Jerk_Vel_and_Acc_Posi_disconnected = source_1.readlines()
#source_1.close()


source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()


plt.figure('q_dot_dot_coupled_debug')


ploted_q_dotdot_bounds_max_comp_Acc_Posi_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_comp_Acc_Posi_0),1), q_dotdot_bounds_max_comp_Acc_Posi_0, "b",   linewidth=2.0)
ploted_q_dotdot_bounds_min_comp_Acc_Posi_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_comp_Acc_Posi_0),1), q_dotdot_bounds_min_comp_Acc_Posi_0, "b--", linewidth=2.0)
ploted_q_dotdot_bounds_max_comp_Jerk_Vel_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_comp_Jerk_Vel_0),1), q_dotdot_bounds_max_comp_Jerk_Vel_0, "m",   linewidth=2.0)
ploted_q_dotdot_bounds_min_comp_Jerk_Vel_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_comp_Jerk_Vel_0),1), q_dotdot_bounds_min_comp_Jerk_Vel_0, "m--", linewidth=2.0)
ploted_q_dotdot_bounds_max_comp_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_comp_0),1),          q_dotdot_bounds_max_comp_0,          "g",   linewidth=2.0)
ploted_q_dotdot_bounds_min_comp_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_comp_0),1),          q_dotdot_bounds_min_comp_0,          "g--", linewidth=2.0)
ploted_q_dotdot_0,                          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                          q_dotdot_0,                          "k",   linewidth=2.0)
#ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1),          domaines_Jerk_Vel_and_Acc_Posi_disconnected,          "r", linewidth=2.0)
#plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$disconnected$'])
plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_q_dotdot_0], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$\ddot{q_0} (rad s^2)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -600, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################








############################q_dot_dot plot vincent limits##############################
source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_prime_forwrd_backwrd_0.txt", "r")
q_dotdot_bounds_max_prime_forwrd_backwrd_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_prime_forwrd_backwrd_0.txt", "r")
q_dotdot_bounds_min_prime_forwrd_backwrd_0 = source_1.readlines()
source_1.close()

plt.figure('q_dot_dot plot vincent limits')


ploted_q_dotdot_0,                          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                          q_dotdot_0,                          "b",   linewidth=2.0)
ploted_q_dotdot_bounds_max_prime_forwrd_backwrd_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_prime_forwrd_backwrd_0),1), q_dotdot_bounds_max_prime_forwrd_backwrd_0, "r", linewidth=2.0)
ploted_q_dotdot_bounds_min_prime_forwrd_backwrd_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_prime_forwrd_backwrd_0),1), q_dotdot_bounds_min_prime_forwrd_backwrd_0, "r--",   linewidth=2.0)
plt.legend([ploted_q_dotdot_0, ploted_q_dotdot_bounds_max_prime_forwrd_backwrd_0, ploted_q_dotdot_bounds_min_prime_forwrd_backwrd_0], ['$\ddot{q_0} (rad s^2)$', '$\ddot{q_0} max_vincent (rad s^2)$', '$\ddot{q_0} min_vincent(rad s^2)$'])
############################q_dot_dot plot vincent limits##############################















############################q_dot_dot plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_dotdot_bounds_max_comp_Acc_Posi_0.txt", "r")
q_dotdot_bounds_max_comp_Acc_Posi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_comp_Acc_Posi_0.txt", "r")
q_dotdot_bounds_min_comp_Acc_Posi_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dotdot_bounds_max_comp_0.txt", "r")
q_dotdot_bounds_max_comp_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_comp_0.txt", "r")
q_dotdot_bounds_min_comp_0 = source_1.readlines()
source_1.close()


source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()



source_1 = open("saved_data/n1_neg_jerk_acc_posi_0.txt", "r")
n1_neg_jerk_acc_posi_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/n2_neg_jerk_acc_posi_0.txt", "r")
n2_neg_jerk_acc_posi_0 = source_1.readlines()
source_1.close()



plt.figure('q_dot_dot_coupled_debug FINAL')


ploted_q_dotdot_bounds_max_comp_Acc_Posi_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_comp_Acc_Posi_0),1), q_dotdot_bounds_max_comp_Acc_Posi_0, "m",   linewidth=2.0)
ploted_q_dotdot_bounds_min_comp_Acc_Posi_0, = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_comp_Acc_Posi_0),1), q_dotdot_bounds_min_comp_Acc_Posi_0, "m--", linewidth=2.0)
ploted_q_dotdot_bounds_max_comp_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_max_comp_0),1),          q_dotdot_bounds_max_comp_0,          "r",   linewidth=2.0)
ploted_q_dotdot_bounds_min_comp_0,          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_bounds_min_comp_0),1),          q_dotdot_bounds_min_comp_0,          "r--", linewidth=2.0)
ploted_q_dotdot_0,                          = plt.plot(0.001*np.arange(0,np.size(q_dotdot_0),1),                          q_dotdot_0,                          "b",   linewidth=2.0)
ploted_n1_neg_jerk_acc_posi_0,              = plt.plot(0.001*np.arange(0,np.size(n1_neg_jerk_acc_posi_0),1),              n1_neg_jerk_acc_posi_0,              "k",   linewidth=2.0)
ploted_n2_neg_jerk_acc_posi_0,              = plt.plot(0.001*np.arange(0,np.size(n2_neg_jerk_acc_posi_0),1),              n2_neg_jerk_acc_posi_0,              "k--", linewidth=2.0)

#ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected, = plt.plot(0.001*np.arange(0,np.size(domaines_Jerk_Vel_and_Acc_Posi_disconnected),1),          domaines_Jerk_Vel_and_Acc_Posi_disconnected,          "r", linewidth=2.0)
#plt.legend([q_dotdot_bounds_max_comp_Acc_Posi_0, q_dotdot_bounds_min_comp_Acc_Posi_0, q_dotdot_bounds_max_comp_Jerk_Vel_0, q_dotdot_bounds_min_comp_Jerk_Vel_0, q_dotdot_bounds_max_comp_0, q_dotdot_bounds_min_comp_0, ploted_domaines_Jerk_Vel_and_Acc_Posi_disconnected], ['$\ddot{q_0} acc-posi max (rad s^2)$', '$\ddot{q_0} acc-posi min (rad s^2)$', '$\ddot{q_0} vel-jerk max(rad s^2)$', '$\ddot{q_0} vel-jerk min (rad s^2)$', '$\ddot{q_0} coupled max(rad s^2)$', '$\ddot{q_0} coupled min(rad s^2)$', '$disconnected$'])
plt.legend([ploted_q_dotdot_bounds_max_comp_Acc_Posi_0, ploted_q_dotdot_bounds_min_comp_Acc_Posi_0, ploted_q_dotdot_bounds_max_comp_0, ploted_q_dotdot_bounds_min_comp_0, ploted_q_dotdot_0, ploted_n1_neg_jerk_acc_posi_0, ploted_n2_neg_jerk_acc_posi_0], ['$\ddot{q_0}_{acc.posi.max} (rad/s^2)$', '$\ddot{q_0}_{acc.posi.min} (rad/s^2)$', '$\ddot{q_0}_{acc.jerk.posi.max} (rad/s^2)$', '$\ddot{q_0}_{acc.jerk.posi.min} (rad/s^2)$', '$\ddot{q_0} (rad/s^2)$', 'n_1_{neg}', 'n_2_{neg}'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_0), -5000, 5000])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp FINAL DEBUG##############################


plt.show()
