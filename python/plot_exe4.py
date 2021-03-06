import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import pylab

params = {'legend.fontsize': 20,
          'legend.linewidth': 2}
plt.rcParams.update(params)



#Potential Energy E_p 
############################E_p plot##############################
source = open("saved_data/Ep_rebuilt2.txt", "r")
Ep_rebuilt2 = source.readlines()
source.close()


source = open("saved_data/Ep_7_x_max.txt", "r")
Ep_7_x_max = source.readlines()
source.close()


plt.figure(110)

ploted_Ep_rebuilt2, = plt.plot(0.001*np.arange(0,np.size(Ep_rebuilt2),1), Ep_rebuilt2, "b", linewidth=1.0)
ploted_Ep_7_x_max, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x_max),1), Ep_7_x_max, "r--", linewidth=1.0)
plt.legend([ploted_Ep_rebuilt2, ploted_Ep_7_x_max], ['$Ep_rebuilt2{eff} (Joule)$', '$E_{effmax} (Joule)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Ep_rebuilt2), -0.02, 0.02])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################






############################Distance plot222222222##############################
source = open("saved_data/d_07_ob.txt", "r")
Dist_07_nrst_ob = source.readlines()
source.close()

source = open("saved_data/Real_Ec_7_x.txt", "r")
Real_Ec_7_x = source.readlines()
source.close()

source = open("saved_data/E_7_max.txt", "r")
E_7_max = source.readlines()
source.close()


plt.figure(107)

ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=1.0)
ploted_E_7_max, = plt.plot(0.001*np.arange(0,np.size(E_7_max),1), E_7_max, "r--", linewidth=1.0)
ploted_Dist_07_nrst_ob, = plt.plot(0.001*np.arange(0,np.size(Dist_07_nrst_ob),1), Dist_07_nrst_ob, "g", linewidth=1.0)
plt.legend([ploted_Real_Ec_7_x, ploted_E_7_max, ploted_Dist_07_nrst_ob], ['$E_{eff} (Joule)$', '$E_{effmax} (Joule)$', "$d_{eff-obst} (m)$"])

#	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Dist_07_nrst_ob), -0.04, 0.8])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
#############################Distance plot222222222##############################










#############################X plot##############################
source = open("saved_data/trajectory_x.txt", "r")
X_x = source.readlines()
source.close()

source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()

plt.figure(100)
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

plt.figure(100)
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

plt.figure(100)
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


plt.figure(100)
plt.subplot(2, 2, 4)
	
ploted_X_err, = plt.plot(0.001*np.arange(0,np.size(X_err),1), X_err, "b", linewidth=2.0)

plt.legend([ploted_X_err], ['$X_{err}$'])
	
plt.ylabel("$(m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(X_err), 0.0, 0.005])
plt.grid(True)
#############################X plot##############################
















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









#Potential Energy E_p 
############################E_p plot##############################
#source = open("saved_data/Ep_7_x.txt", "r")
#Ep_7_x = source.readlines()
#source.close()

#source = open("saved_data/Real_Ec_7_x.txt", "r")
#Real_Ec_7_x = source.readlines()
#source.close()

#source = open("saved_data/E_7_reconstructed_with_V_7_t2_derived.txt", "r")
#E_7_reconstructed_with_V_7_t2_derived = source.readlines()
#source.close()

#source = open("saved_data/Ep_7_x_max.txt", "r")
#Ep_7_x_max = source.readlines()
#source.close()

#source = open("saved_data/Acc_7_x.txt", "r")
#Acc_7_x = source.readlines()
#source.close()


#plt.figure(113)

#ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=1.0)
#ploted_E_7_reconstructed_with_V_7_t2_derived, = plt.plot(0.001*np.arange(0,np.size(E_7_reconstructed_with_V_7_t2_derived),1), E_7_reconstructed_with_V_7_t2_derived, "g", linewidth=1.0)
#ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
#ploted_Ep_7_x_max, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x_max),1), Ep_7_x_max, "r--", linewidth=1.0)
#ploted_Acc_7_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_x),1), Acc_7_x, "k", linewidth=1.0)
#plt.legend([ploted_Real_Ec_7_x, ploted_E_7_reconstructed_with_V_7_t2_derived, ploted_Ep_7_x, ploted_Ep_7_x_max, ploted_Acc_7_x], ['$Ec_{eff} (Joule)$', 'Ec_derived{eff} (Joule)$', '$Ep_apprx{eff} (Joule)$', '$Ep_{effmax} (Joule)$', '$Acc_{7x} (m/s2)$'])

#	
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(E_7_reconstructed_with_V_7_t2_derived), -0.02, 0.02])
#plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
#plt.grid(True)
############################Distance plot222222222##############################









#############################E_p plot##############################
#source = open("saved_data/Ep_7_x.txt", "r")
#Ep_7_x = source.readlines()
#source.close()

#source = open("saved_data/Real_Ec_7_x.txt", "r")
#Real_Ec_7_x = source.readlines()
#source.close()


#source = open("saved_data/Ep_7_x_max.txt", "r")
#Ep_7_x_max = source.readlines()
#source.close()

#source = open("saved_data/X_err_x.txt", "r")
#X_err_x = source.readlines()
#source.close()

#source = open("saved_data/V_7_x.txt", "r")
#V_7_x = source.readlines()
#source.close()

#source = open("saved_data/Acc_7_x.txt", "r")
#Acc_7_x = source.readlines()
#source.close()

#source = open("saved_data/m_eq_7_j_Xerr.txt", "r")
#m_eq_7_j_Xerr = source.readlines()
#source.close()

#source = open("saved_data/Acc_7_nxt_dt_prj.txt", "r")
#Acc_7_nxt_dt_prj = source.readlines()
#source.close()

#source = open("saved_data/Ep_7_prj_real.txt", "r")
#Ep_7_prj_real = source.readlines()
#source.close()

#source = open("saved_data/Acc_7_des_x.txt", "r")
#Acc_7_des_x = source.readlines()
#source.close()


#plt.figure(113)

#ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=1.0)
#ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
#ploted_Ep_7_prj_real, = plt.plot(0.001*np.arange(0,np.size(Ep_7_prj_real),1), Ep_7_prj_real, "m--", linewidth=1.0)
#ploted_Ep_7_x_max, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x_max),1), Ep_7_x_max, "r--", linewidth=1.0)
#ploted_X_err_x, = plt.plot(0.001*np.arange(0,np.size(X_err_x),1), X_err_x, "c", linewidth=1.0)
#ploted_V_7_x, = plt.plot(0.001*np.arange(0,np.size(V_7_x),1), V_7_x, "k--", linewidth=1.0)
#ploted_Acc_7_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_x),1), Acc_7_x, "k", linewidth=1.0)
#ploted_Acc_7_nxt_dt_prj, = plt.plot(0.001*np.arange(0,np.size(Acc_7_nxt_dt_prj),1), Acc_7_nxt_dt_prj, "k-.", linewidth=1.0)
#ploted_Acc_7_des_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_des_x),1), Acc_7_des_x, "k:", linewidth=1.0)
#ploted_m_eq_7_j_Xerr, = plt.plot(0.001*np.arange(0,np.size(m_eq_7_j_Xerr),1), m_eq_7_j_Xerr, "c--", linewidth=1.0)
#plt.legend([ploted_Real_Ec_7_x, ploted_Ep_7_x, ploted_Ep_7_prj_real, ploted_Ep_7_x_max, ploted_X_err_x, ploted_V_7_x, ploted_Acc_7_x, ploted_m_eq_7_j_Xerr, ploted_Acc_7_nxt_dt_prj, ploted_Acc_7_des_x], ['$Ec_{eff} (Joule)$', '$Ep_apprx{eff} (Joule)$', '$Ep7prj_real (Joule)$', '$Ep_{effmax} (Joule)$', '$X_{errx} (m)$', '$V_{7x} (m/s2)$', '$Acc_{7x} (m/s2)$', '$meq_{7_prj}$', '$Acc_nxt_dt{7x} (m/s2)$', '$Acc_des{7x} (m/s2)$'])

#	
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(Real_Ec_7_x), -0.02, 0.02])
#plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
#plt.grid(True)
#############################Distance plot222222222##############################



















#############################E_p plot##############################
#source = open("saved_data/Ep_7_x.txt", "r")
#Ep_7_x = source.readlines()
#source.close()

#source = open("saved_data/Real_Ec_7_x.txt", "r")
#Real_Ec_7_x = source.readlines()
#source.close()


#source = open("saved_data/Ep_7_x_max.txt", "r")
#Ep_7_x_max = source.readlines()
#source.close()

#source = open("saved_data/E_7_reconstructed_with_V_7_t2_derived.txt", "r")
#E_7_reconstructed_with_V_7_t2_derived = source.readlines()
#source.close()

#plt.figure(113)

#ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=1.0)
#ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
#ploted_E_7_reconstructed_with_V_7_t2_derived, = plt.plot(0.001*np.arange(0,np.size(E_7_reconstructed_with_V_7_t2_derived),1), E_7_reconstructed_with_V_7_t2_derived, "g", linewidth=1.0)
#ploted_Ep_7_x_max, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x_max),1), Ep_7_x_max, "r--", linewidth=1.0)
#plt.legend([ploted_Real_Ec_7_x, ploted_Ep_7_x, ploted_Ep_7_x_max, ploted_E_7_reconstructed_with_V_7_t2_derived], ['$Ec_{eff} (Joule)$', '$Ep_apprx{eff} (Joule)$', '$Ep_{effmax} (Joule)$', 'Ec_derived{eff} (Joule)$'])

#	
#plt.xlabel("$time (s)$", fontsize=20)
#plt.axis([0,0.001*np.size(Real_Ec_7_x), -0.02, 0.02])
#plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
#plt.grid(True)
#############################Distance plot222222222##############################








############################E_p plot##############################
source = open("saved_data/Ep_7_x.txt", "r")
Ep_7_x = source.readlines()
source.close()

source = open("saved_data/Real_Ec_7_x.txt", "r")
Real_Ec_7_x = source.readlines()
source.close()


source = open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", "r")
Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x = source.readlines()
source.close()




source = open("saved_data/Ep_7_x_max.txt", "r")
Ep_7_x_max = source.readlines()
source.close()

source = open("saved_data/status.txt", "r")
status = source.readlines()
source.close()

source = open("saved_data/Acc_7_nxt_dt_prj.txt", "r")
Acc_7_nxt_dt_prj = source.readlines()
source.close()


source = open("saved_data/Acc_7_nxt_dt_prj_lilmit_max.txt", "r")
Acc_7_nxt_dt_prj_lilmit_max = source.readlines()
source.close()



plt.figure(123)

ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=1.0)
ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x),1), Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, "b--", linewidth=1.0)
ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
ploted_Ep_7_x_max, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x_max),1), Ep_7_x_max, "r--", linewidth=1.0)
ploted_status, = plt.plot(0.001*np.arange(0,np.size(status),1), status, "k", linewidth=1.0)
ploted_Acc_7_nxt_dt_prj, = plt.plot(0.001*np.arange(0,np.size(Acc_7_nxt_dt_prj),1), Acc_7_nxt_dt_prj, "c", linewidth=1.0)
ploted_Acc_7_nxt_dt_prj_lilmit_max, = plt.plot(0.001*np.arange(0,np.size(Acc_7_nxt_dt_prj_lilmit_max),1), Acc_7_nxt_dt_prj_lilmit_max, "m-.", linewidth=1.0)
plt.legend([ploted_Real_Ec_7_x, ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, ploted_Ep_7_x, ploted_Ep_7_x_max, ploted_status, ploted_Acc_7_nxt_dt_prj, ploted_Acc_7_nxt_dt_prj_lilmit_max], ['$Ec_{eff} (Joule)$', '$Ec_rcntructrd{eff} (Joule)$', '$Ep_apprx{eff} (Joule)$', '$Ep_{effmax} (Joule)$', '$status$', '$Acc7rblt_prj (m/s2)$', '$ploted_Accnxt7_max (m/s2)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_Ec_7_x), -0.02, 0.02])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################













############################E_p plot##############################
source = open("saved_data/Real_Ec_7_x.txt", "r")
Real_Ec_7_x = source.readlines()
source.close()

source = open("saved_data/Acc_7_x.txt", "r")
Acc_7_x = source.readlines()
source.close()

source = open("saved_data/Acc_7_des_x.txt", "r")
Acc_7_des_x = source.readlines()
source.close()


source = open("saved_data/Ep_7_x.txt", "r")
Ep_7_x = source.readlines()
source.close()
plt.figure(113)

source = open("saved_data/Acc_7_nxt_dt_prj.txt", "r")
Acc_7_nxt_dt_prj = source.readlines()
source.close()


source = open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", "r")
Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x = source.readlines()
source.close()

source = open("saved_data/E_7_reconstructed_with_V_7_t2_derived.txt", "r")
E_7_reconstructed_with_V_7_t2_derived = source.readlines()
source.close()

source = open("saved_data/X_err_x_0.txt", "r")
X_err_x_0 = source.readlines()
source.close()


ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=2.0)
ploted_Acc_7_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_x),1), Acc_7_x, "k", linewidth=2.0)
ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x),1), Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, "b--", linewidth=2.0)
ploted_E_7_reconstructed_with_V_7_t2_derived, = plt.plot(0.001*np.arange(0,np.size(E_7_reconstructed_with_V_7_t2_derived),1), E_7_reconstructed_with_V_7_t2_derived, "m--", linewidth=2.0)
ploted_Acc_7_des_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_des_x),1), Acc_7_des_x, "k--", linewidth=2.0)
ploted_Acc_7_nxt_dt_prj, = plt.plot(0.001*np.arange(0,np.size(Acc_7_nxt_dt_prj),1), Acc_7_nxt_dt_prj, "c", linewidth=2.0)
ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
ploted_X_err_x_0, = plt.plot(0.001*np.arange(0,np.size(X_err_x_0),1), X_err_x_0, "g", linewidth=2.0)
plt.legend([ploted_Real_Ec_7_x, ploted_Acc_7_x, ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x,  ploted_E_7_reconstructed_with_V_7_t2_derived, ploted_Acc_7_des_x, ploted_Acc_7_nxt_dt_prj, ploted_Ep_7_x, ploted_X_err_x_0], ['$E_c^{rblt} (J)$', '$\ddot{X}_x (m/s^2)$', '$E_c^{sum} (J)$', '$E_p^{\partial E_c} (J)$', '$\ddot{X}_x^* (m/s^2)$', '$\ddot{X}_x^{rblt} (m/s^2)$', '$E_p^{sqr} (J)$', '$X_0^{err} (m)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_Ec_7_x), -1, 1])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################













############################E_p plot##############################
source = open("saved_data/Real_Ec_7_x.txt", "r")
Real_Ec_7_x = source.readlines()
source.close()


source = open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", "r")
Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x = source.readlines()
source.close()


source = open("saved_data/Ep_7_x.txt", "r")
Ep_7_x = source.readlines()
source.close()


source = open("saved_data/X_err_x.txt", "r")
X_err_x = source.readlines()
source.close()


source = open("saved_data/F_7_x.txt", "r")
F_7_x = source.readlines()
source.close()


plt.figure(153)

ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=2.0)
ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x),1), Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, "b--", linewidth=2.0)
ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=2.0)
ploted_X_err_x, = plt.plot(0.001*np.arange(0,np.size(X_err_x),1), X_err_x, "g", linewidth=2.0)
ploted_F_7_x, = plt.plot(0.001*np.arange(0,np.size(F_7_x),1), F_7_x, "g--", linewidth=2.0)

plt.legend([ploted_Real_Ec_7_x, ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, ploted_Ep_7_x, ploted_X_err_x, ploted_F_7_x], ['$E_{c} (J)$','$E_{c|sum Ep} (J)$', '$E_p (J)$', '$X_{err|x} (m)$', '$F_{eq|x} (N)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_Ec_7_x), -0.05, 0.12])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################













############################E_p plot##############################
source = open("saved_data/Real_Ec_7_x.txt", "r")
Real_Ec_7_x = source.readlines()
source.close()


source = open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", "r")
Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x = source.readlines()
source.close()


source = open("saved_data/Ep_7_x.txt", "r")
Ep_7_x = source.readlines()
source.close()



source = open("saved_data/Acc_7_x.txt", "r")
Acc_7_x = source.readlines()
source.close()

plt.figure(154)

ploted_Real_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x),1), Real_Ec_7_x, "b", linewidth=2.0)
ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x),1), Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, "b--", linewidth=2.0)
ploted_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Ep_7_x),1), Ep_7_x, "m", linewidth=1.0)
ploted_Acc_7_x, = plt.plot(0.001*np.arange(0,np.size(Acc_7_x),1), Acc_7_x, "k", linewidth=2.0)

plt.legend([ploted_Real_Ec_7_x, ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, ploted_Ep_7_x], ['$E_{c} (J)$','$E_{c|sum Ep} (J)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_Ec_7_x), -0.35, 0.3])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################Distance plot222222222##############################

















#############################tau plot##############################
source = open("saved_data/tau_0.txt", "r")
tau_0 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_0, = plt.plot(0.001*np.arange(0,np.size(tau_0),1), tau_0, linewidth=2.0)

	



source = open("saved_data/tau_1.txt", "r")
tau_1 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_1, = plt.plot(0.001*np.arange(0,np.size(tau_1),1), tau_1, linewidth=2.0)

	



source = open("saved_data/tau_2.txt", "r")
tau_2 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_2, = plt.plot(0.001*np.arange(0,np.size(tau_2),1), tau_2, linewidth=2.0)

	





source = open("saved_data/tau_3.txt", "r")
tau_3 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_3, = plt.plot(0.001*np.arange(0,np.size(tau_3),1), tau_3, linewidth=2.0)






source = open("saved_data/tau_4.txt", "r")
tau_4 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_4, = plt.plot(0.001*np.arange(0,np.size(tau_4),1), tau_4, linewidth=2.0)

	






source = open("saved_data/tau_5.txt", "r")
tau_5 = source.readlines()
source.close()
plt.figure(104)	
ploted_tau_5, = plt.plot(0.001*np.arange(0,np.size(tau_5),1), tau_5, linewidth=2.0)







source = open("saved_data/tau_6.txt", "r")
tau_6 = source.readlines()
source.close()
plt.figure(104)
ploted_tau_6, = plt.plot(0.001*np.arange(0,np.size(tau_6),1), tau_6, linewidth=2.0)
plt.legend([ploted_tau_6, ploted_tau_5, ploted_tau_4, ploted_tau_3, ploted_tau_2, ploted_tau_1, ploted_tau_0], [r'$\tau_6$', r'$\tau_5$', r'$\tau_4$', r'$\tau_3$', r'$\tau_2$', r'$\tau_1$', r'$\tau_0$' ])


plt.ylabel("$(N.m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(tau_0), -200, 200])
plt.grid(True)
#############################tau plot##############################














plt.show()
