import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import pylab

params = {'legend.fontsize': 20,
          'legend.linewidth': 2}
plt.rcParams.update(params)


#############################X plot##############################
source = open("saved_data/trajectory_x.txt", "r")
X_x = source.readlines()
source.close()

source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()

plt.figure(100)
plt.subplot(2, 2, 1)
	
ploted_X_x, = plt.plot(0.001*np.arange(0,np.size(X_x),1), X_x, "b", linewidth=1.0)
ploted_Des_X_x, = plt.plot(0.001*np.arange(0,np.size(des_X_x),1), des_X_x, "r--", linewidth=1.0)
plt.legend([ploted_X_x, ploted_Des_X_x], ['$X_x$', '$X^*_x$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_x), -0.6, 0.85])





source = open("saved_data/trajectory_y.txt", "r")
X_y = source.readlines()
source.close()

source = open("saved_data/des_trajectory_y.txt", "r")
des_X_y = source.readlines()
source.close()

plt.figure(100)
plt.subplot(2, 2, 2)
	
ploted_X_y, = plt.plot(0.001*np.arange(0,np.size(X_y),1), X_y, "b", linewidth=1.0)
ploted_Des_X_y, = plt.plot(0.001*np.arange(0,np.size(des_X_y),1), des_X_y, "r--", linewidth=1.0)
plt.legend([ploted_X_y, ploted_Des_X_y], ['$X_y$', '$X^*_y$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_y), 0.15, 0.75])





source = open("saved_data/trajectory_z.txt", "r")
X_z = source.readlines()
source.close()

source = open("saved_data/des_trajectory_z.txt", "r")
des_X_z = source.readlines()
source.close()

plt.figure(100)
plt.subplot(2, 2, 3)

print len(np.arange(0,np.size(X_z),1))
print np.size(X_z)
	
ploted_X_z, = plt.plot(0.001*np.arange(0,np.size(X_z),1), X_z,  "b", linewidth=1.0)
ploted_Des_X_z, = plt.plot(0.001*np.arange(0,np.size(des_X_z),1), des_X_z, "r--", linewidth=1.0)
plt.legend([ploted_X_z, ploted_Des_X_z], ['$X_z$', '$X^*_z$'])
	

plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_z), 0.15, 0.85])
#############################X plot##############################


















#############################Velocities plot##############################
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#plt.figure(101)
#plt.subplot(2, 2, 1)
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "b", linewidth=1.0)
	
#plt.ylabel("$E_{eff} (Joules)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(E_7), -0.3, 0.3])
#plt.grid(True)





#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()

#plt.figure(101)
#plt.subplot(2, 2, 1)

#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "b", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)
#plt.legend([ploted_E_7, ploted_E_7_max], ['$E_{eff}$', '$E_{effmax}$'])
#	
#plt.ylabel("$(Joules)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(E_7), -0.3, 0.3])
#plt.grid(True)




#source = open("saved_data/V_7_x.txt", "r")
#V_7_x = source.readlines()
#source.close()

#source = open("saved_data/V_7_des_x.txt", "r")
#V_7_des_x = source.readlines()
#source.close()

#plt.figure(101)
#plt.subplot(2, 2, 2)
#	
#ploted_V_7_x, = plt.plot(0.001*np.arange(0,np.size(V_7_x),1), V_7_x, "b", linewidth=1.0)
#ploted_V_7_des_x, = plt.plot(0.001*np.arange(0,np.size(V_7_des_x),1), V_7_des_x, "r--", linewidth=1.0)
#plt.legend([ploted_V_7_x, ploted_V_7_des_x], ['$\dot{X_x}$', '$\dot{X^*}_x$'])
#	
#plt.ylabel("$(m/s)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(V_7_x), -1.0, 2])
#plt.grid(True)





#source = open("saved_data/V_7_y.txt", "r")
#V_7_y = source.readlines()
#source.close()

#source = open("saved_data/V_7_des_y.txt", "r")
#V_7_des_y = source.readlines()
#source.close()

#plt.figure(101)
#plt.subplot(2, 2, 3)
#	
#ploted_V_7_y, = plt.plot(0.001*np.arange(0,np.size(V_7_y),1), V_7_y, "b", linewidth=1.0)
#ploted_V_7_des_y, = plt.plot(0.001*np.arange(0,np.size(V_7_des_y),1), V_7_des_y, "r--", linewidth=1.0)
#plt.legend([ploted_V_7_y, ploted_V_7_des_y], ['$\dot{X_y}$', '$\dot{X^*}_y$'])
#	
#plt.ylabel("$(m/s)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(V_7_y), -1.0, 2])
#plt.grid(True)





#source = open("saved_data/V_7_z.txt", "r")
#V_7_z = source.readlines()
#source.close()

#source = open("saved_data/V_7_des_z.txt", "r")
#V_7_des_z = source.readlines()
#source.close()

#plt.figure(101)
#plt.subplot(2, 2, 4)
#	
#ploted_V_7_z, = plt.plot(0.001*np.arange(0,np.size(V_7_z),1), V_7_z, "b", linewidth=1.0)
#ploted_V_7_des_z, = plt.plot(0.001*np.arange(0,np.size(V_7_des_z),1), V_7_des_z, "r--", linewidth=1.0)
#plt.legend([ploted_V_7_z, ploted_V_7_des_z], ['$\dot{X_z}$', '$\dot{X^*}_z$'])
#	
#plt.ylabel("$(m/s)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(V_7_z), -1.0, 2])
#plt.grid(True)
#############################Velocities plot##############################













#############################q plot##############################
source = open("saved_data/q_0.txt", "r")
q_0 = source.readlines()
source.close()

source = open("saved_data/q_0_max.txt", "r")
q_0_max = source.readlines()
source.close()

source = open("saved_data/q_0_min.txt", "r")
q_0_min = source.readlines()
source.close()

plt.figure(102)
	
ploted_q_0, = plt.plot(0.001*np.arange(0,np.size(q_0),1), q_0, linewidth=1.0)
ploted_q_0_max, = plt.plot(0.001*np.arange(0,np.size(q_0_max),1), q_0_max, "k--", linewidth=1.0)
ploted_q_0_min, = plt.plot(0.001*np.arange(0,np.size(q_0_min),1), q_0_min, "k-.", linewidth=1.0)
plt.legend([ploted_q_0, ploted_q_0_max, ploted_q_0_min], ['$q_0$', '$q_{max}$', '$q_{min}$'])
	



source = open("saved_data/q_1.txt", "r")
q_1 = source.readlines()
source.close()
plt.figure(102)
ploted_q_1, = plt.plot(0.001*np.arange(0,np.size(q_1),1), q_1, linewidth=1.0)
plt.legend([ploted_q_1], ['$q_1$'])
	







source = open("saved_data/q_2.txt", "r")
q_2 = source.readlines()
source.close()
plt.figure(102)
ploted_q_2, = plt.plot(0.001*np.arange(0,np.size(q_2),1), q_2, linewidth=1.0)
plt.legend([ploted_q_2], ['$q_2$'])
	





source = open("saved_data/q_3.txt", "r")
q_3 = source.readlines()
source.close()
plt.figure(102)
ploted_q_3, = plt.plot(0.001*np.arange(0,np.size(q_3),1), q_3, linewidth=1.0)
plt.legend([ploted_q_3], ['$q_3$'])





source = open("saved_data/q_4.txt", "r")
q_4 = source.readlines()
source.close()
plt.figure(102)
ploted_q_4, = plt.plot(0.001*np.arange(0,np.size(q_4),1), q_4, linewidth=1.0)
plt.legend([ploted_q_4], ['$q_4$'])
	






source = open("saved_data/q_5.txt", "r")
q_5 = source.readlines()
source.close()
plt.figure(102)	
ploted_q_5, = plt.plot(0.001*np.arange(0,np.size(q_5),1), q_5, linewidth=1.0)
plt.legend([ploted_q_5], ['$q_5$'])






source = open("saved_data/q_6.txt", "r")
q_6 = source.readlines()
source.close()
plt.figure(102)
ploted_q_6, = plt.plot(0.001*np.arange(0,np.size(q_6),1), q_6, linewidth=1.0)
plt.legend([ploted_q_6, ploted_q_5, ploted_q_4, ploted_q_3, ploted_q_2, ploted_q_1, ploted_q_0, ploted_q_0_max, ploted_q_0_min], ['$q_6$', '$q_5$', '$q_4$', '$q_3$', '$q_2$', '$q_1$', '$q_0$', '$q_{max}$', '$q_{min}$' ])


plt.ylabel("$(rad)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_0), -5, 3.5])
plt.grid(True)
#############################q plot##############################


















#############################q_dot plot##############################
source = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source.readlines()
source.close()

source = open("saved_data/q_dot_0_max.txt", "r")
q_dot_0_max = source.readlines()
source.close()

source = open("saved_data/q_dot_0_min.txt", "r")
q_dot_0_min = source.readlines()
source.close()

plt.figure(103)
	
ploted_q_dot_0, = plt.plot(0.001*np.arange(0,np.size(q_dot_0),1), q_dot_0, linewidth=1.0)
ploted_q_dot_0_max, = plt.plot(0.001*np.arange(0,np.size(q_dot_0_max),1), q_dot_0_max, "k--", linewidth=1.0)
ploted_q_dot_0_min, = plt.plot(0.001*np.arange(0,np.size(q_dot_0_min),1), q_dot_0_min, "k-.", linewidth=1.0)

	



source = open("saved_data/q_dot_1.txt", "r")
q_dot_1 = source.readlines()
source.close()
plt.figure(103)
ploted_q_dot_1, = plt.plot(0.001*np.arange(0,np.size(q_dot_1),1), q_dot_1, linewidth=1.0)

	







source = open("saved_data/q_dot_2.txt", "r")
q_dot_2 = source.readlines()
source.close()
plt.figure(103)
ploted_q_dot_2, = plt.plot(0.001*np.arange(0,np.size(q_dot_2),1), q_dot_2, linewidth=1.0)

	





source = open("saved_data/q_dot_3.txt", "r")
q_dot_3 = source.readlines()
source.close()
plt.figure(103)
ploted_q_dot_3, = plt.plot(0.001*np.arange(0,np.size(q_dot_3),1), q_dot_3, linewidth=1.0)






source = open("saved_data/q_dot_4.txt", "r")
q_dot_4 = source.readlines()
source.close()
plt.figure(103)
ploted_q_dot_4, = plt.plot(0.001*np.arange(0,np.size(q_dot_4),1), q_dot_4, linewidth=1.0)

	






source = open("saved_data/q_dot_5.txt", "r")
q_dot_5 = source.readlines()
source.close()
plt.figure(103)	
ploted_q_dot_5, = plt.plot(0.001*np.arange(0,np.size(q_dot_5),1), q_dot_5, linewidth=1.0)







source = open("saved_data/q_dot_6.txt", "r")
q_dot_6 = source.readlines()
source.close()
plt.figure(103)
ploted_q_dot_6, = plt.plot(0.001*np.arange(0,np.size(q_dot_6),1), q_dot_6, linewidth=1.0)
plt.legend([ploted_q_dot_6, ploted_q_dot_5, ploted_q_dot_4, ploted_q_dot_3, ploted_q_dot_2, ploted_q_dot_1, ploted_q_dot_0, ploted_q_dot_0_max, ploted_q_dot_0_min], ['$\dot{q}_6$', '$\dot{q}_5$', '$\dot{q}_4$', '$\dot{q}_3$', '$\dot{q}_2$', '$\dot{q}_1$', '$\dot{q}_0$', '$\dot{q}_{max}$', '$\dot{q}_{min}$' ])


plt.ylabel("$(rad/s)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_0), -4.0, 2.5])
plt.grid(True)
#############################q_dot plot##############################







#############################tau plot##############################
source = open("saved_data/tau_0.txt", "r")
tau_0 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_0, = plt.plot(0.001*np.arange(0,np.size(tau_0),1), tau_0, linewidth=1.0)

	



source = open("saved_data/tau_1.txt", "r")
tau_1 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_1, = plt.plot(0.001*np.arange(0,np.size(tau_1),1), tau_1, linewidth=1.0)

	



source = open("saved_data/tau_2.txt", "r")
tau_2 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_2, = plt.plot(0.001*np.arange(0,np.size(tau_2),1), tau_2, linewidth=1.0)

	





source = open("saved_data/tau_3.txt", "r")
tau_3 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_3, = plt.plot(0.001*np.arange(0,np.size(tau_3),1), tau_3, linewidth=1.0)






source = open("saved_data/tau_4.txt", "r")
tau_4 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_4, = plt.plot(0.001*np.arange(0,np.size(tau_4),1), tau_4, linewidth=1.0)

	






source = open("saved_data/tau_5.txt", "r")
tau_5 = source.readlines()
source.close()
plt.figure(104)	
ploted_tau_5, = plt.plot(0.001*np.arange(0,np.size(tau_5),1), tau_5, linewidth=1.0)







source = open("saved_data/tau_6.txt", "r")
tau_6 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_6, = plt.plot(0.001*np.arange(0,np.size(tau_6),1), tau_6, linewidth=1.0)
plt.legend([ploted_tau_6, ploted_tau_5, ploted_tau_4, ploted_tau_3, ploted_tau_2, ploted_tau_1, ploted_tau_0], [r'$\tau_6$', r'$\tau_5$', r'$\tau_4$', r'$\tau_3$', r'$\tau_2$', r'$\tau_1$', r'$\tau_0$' ])


plt.ylabel("$(N.m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(tau_0), -50, 10])
plt.grid(True)
#############################tau plot##############################




#############################Energy plot222222222##############################
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#plt.figure(105)

#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "b", linewidth=1.0)
#	
#plt.ylabel("$E_7 (Joules)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(E_7), -0.3, 0.3])
#plt.grid(True)
#############################Energy plot222222222##############################







#############################Energy plot222222222##############################
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()

#plt.figure(106)
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "b", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)
#plt.legend([ploted_E_7, ploted_E_7_max], ['$E_7$', '$E_{7_{max}}$'])
#	
#plt.ylabel("$(Joules)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([2,0.001*np.size(E_7), -0.6, 0.85])
#plt.grid(True)
#############################Energy plot222222222##############################





############################Distance plot222222222##############################
#source = open("saved_data/d_07_ob.txt", "r")
#Dist_07_nrst_ob = source.readlines()
#source.close()

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()


#plt.figure(107)

#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "b", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)
#ploted_Dist_07_nrst_ob, = plt.plot(0.001*np.arange(0,np.size(Dist_07_nrst_ob),1), Dist_07_nrst_ob, "g", linewidth=1.0)
#plt.legend([ploted_E_7, ploted_E_7_max, ploted_Dist_07_nrst_ob], ['$E_{eff} (Joule)$', '$E_{effmax} (Joule)$', "$d_{eff-obst} (m)$"])

##	
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(Dist_07_nrst_ob), -0.04, 0.8])
#plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
#plt.grid(True)
#############################Distance plot222222222##############################











#############################tau plot2##############################
#source = open("saved_data/tau_0.txt", "r")
#tau_0 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 1)
#ploted_tau_0, = plt.plot(0.001*np.arange(0,np.size(tau_0),1), tau_0, linewidth=1.0)
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)

#	



#source = open("saved_data/tau_1.txt", "r")
#tau_1 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 2)
#ploted_tau_1, = plt.plot(0.001*np.arange(0,np.size(tau_1),1), tau_1, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)


#	



#source = open("saved_data/tau_2.txt", "r")
#tau_2 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 3)
#ploted_tau_2, = plt.plot(0.001*np.arange(0,np.size(tau_2),1), tau_2, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)

#	





#source = open("saved_data/tau_3.txt", "r")
#tau_3 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 4)
#ploted_tau_3, = plt.plot(0.001*np.arange(0,np.size(tau_3),1), tau_3, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)






#source = open("saved_data/tau_4.txt", "r")
#tau_4 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 5)
#ploted_tau_4, = plt.plot(0.001*np.arange(0,np.size(tau_4),1), tau_4, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)

	






#source = open("saved_data/tau_5.txt", "r")
#tau_5 = source.readlines()
#source.close()
#plt.figure(109)	
#plt.subplot(2, 4, 6)
#ploted_tau_5, = plt.plot(0.001*np.arange(0,np.size(tau_5),1), tau_5, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)







#source = open("saved_data/tau_6.txt", "r")
#tau_6 = source.readlines()
#source.close()
#plt.figure(109)
#plt.subplot(2, 4, 7)
#ploted_tau_6, = plt.plot(0.001*np.arange(0,np.size(tau_6),1), tau_6, linewidth=1.0)

#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()
#	
#ploted_E_7, = plt.plot(0.001*np.arange(0,np.size(E_7),1), E_7, "m", linewidth=1.0)
#ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)

#plt.ylabel("$(N.m)$", fontsize=20)
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(tau_0), -50, 10])
#plt.grid(True)

#############################tau plot2##############################












#Potential Energy E_p 
############################E_p plot##############################
source = open("saved_data/E_p_7_apprx.txt", "r")
E_p_7_apprx = source.readlines()
source.close()

source = open("saved_data/E_p_7.txt", "r")
E_p_7 = source.readlines()
source.close()

source = open("saved_data/E_p_7_max.txt", "r")
E_p_7_max = source.readlines()
source.close()


plt.figure(110)

ploted_E_p_7, = plt.plot(0.001*np.arange(0,np.size(E_p_7),1), E_p_7, "b", linewidth=1.0)
ploted_E_p_7_apprx, = plt.plot(0.001*np.arange(0,np.size(E_p_7_apprx),1), E_p_7_apprx, "m", linewidth=1.0)
ploted_E_p_7_max, = plt.plot(0.001*np.arange(0,np.size(E_p_7_max),1), E_p_7_max, "r--", linewidth=1.0)
plt.legend([ploted_E_p_7, ploted_E_p_7_apprx, ploted_E_p_7_max], ['$E_P{eff} (Joule)$', '$E_P_apprx{eff} (Joule)$', '$E_{effmax} (Joule)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(E_p_7), -0.02, 0.02])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################










#############################Velocities plot##############################
source = open("saved_data/V_7_x.txt", "r")
V_7_x = source.readlines()
source.close()

source = open("saved_data/V_7_des_x.txt", "r")
V_7_des_x = source.readlines()
source.close()

plt.figure(101)
plt.subplot(2, 2, 2)
	
ploted_V_7_x, = plt.plot(0.001*np.arange(0,np.size(V_7_x),1), V_7_x, "b", linewidth=1.0)
ploted_V_7_des_x, = plt.plot(0.001*np.arange(0,np.size(V_7_des_x),1), V_7_des_x, "r--", linewidth=1.0)
plt.legend([ploted_V_7_x, ploted_V_7_des_x], ['$\dot{X_x}$', '$\dot{X^*}_x$'])
	
plt.ylabel("$(m/s)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_x), -1.0, 2])
plt.grid(True)





source = open("saved_data/V_7_y.txt", "r")
V_7_y = source.readlines()
source.close()

source = open("saved_data/V_7_des_y.txt", "r")
V_7_des_y = source.readlines()
source.close()

plt.figure(101)
plt.subplot(2, 2, 3)
	
ploted_V_7_y, = plt.plot(0.001*np.arange(0,np.size(V_7_y),1), V_7_y, "b", linewidth=1.0)
ploted_V_7_des_y, = plt.plot(0.001*np.arange(0,np.size(V_7_des_y),1), V_7_des_y, "r--", linewidth=1.0)
plt.legend([ploted_V_7_y, ploted_V_7_des_y], ['$\dot{X_y}$', '$\dot{X^*}_y$'])
	
plt.ylabel("$(m/s)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_y), -1.0, 2])
plt.grid(True)





source = open("saved_data/V_7_z.txt", "r")
V_7_z = source.readlines()
source.close()

source = open("saved_data/V_7_des_z.txt", "r")
V_7_des_z = source.readlines()
source.close()

plt.figure(101)
plt.subplot(2, 2, 4)
	
ploted_V_7_z, = plt.plot(0.001*np.arange(0,np.size(V_7_z),1), V_7_z, "b", linewidth=1.0)
ploted_V_7_des_z, = plt.plot(0.001*np.arange(0,np.size(V_7_des_z),1), V_7_des_z, "r--", linewidth=1.0)
plt.legend([ploted_V_7_z, ploted_V_7_des_z], ['$\dot{X_z}$', '$\dot{X^*}_z$'])
	
plt.ylabel("$(m/s)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(V_7_z), -1.0, 2])
plt.grid(True)
#############################Velocities plot##############################



plt.show()

