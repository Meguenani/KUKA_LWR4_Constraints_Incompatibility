import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D









#############################Torques plot##############################
source = open("saved_data/tau_0.txt", "r")
tau_0 = source.readlines()
source.close()

source = open("saved_data/tau_0_max.txt", "r")
tau_0_max = source.readlines()
source.close()

source = open("saved_data/tau_0_min.txt", "r")
tau_0_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 1)
plt.plot(tau_0)	
plt.plot(tau_0_max, "r")
plt.plot(tau_0_min, "m")	
plt.plot([0]*np.size(tau_0), "k")
plt.title("tau_0")
plt.ylabel("tau_0")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_0),-100,100])



source = open("saved_data/tau_1.txt", "r")
tau_1 = source.readlines()
source.close()

source = open("saved_data/tau_1_max.txt", "r")
tau_1_max = source.readlines()
source.close()

source = open("saved_data/tau_1_min.txt", "r")
tau_1_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 2)
plt.plot(tau_1)	
plt.plot(tau_1_max, "r")
plt.plot(tau_1_min, "m")	
plt.plot([0]*np.size(tau_1), "k")
plt.title("tau_1")
plt.ylabel("tau_1")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_1),-100,100])



source = open("saved_data/tau_2.txt", "r")
tau_2 = source.readlines()
source.close()

source = open("saved_data/tau_2_max.txt", "r")
tau_2_max = source.readlines()
source.close()

source = open("saved_data/tau_2_min.txt", "r")
tau_2_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 3)
plt.plot(tau_2)	
plt.plot(tau_2_max, "r")	
plt.plot(tau_2_min, "m")	
plt.plot([0]*np.size(tau_2), "k")
plt.title("tau_2")
plt.ylabel("tau_2")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_2),-100,100])






source = open("saved_data/tau_3.txt", "r")
tau_3 = source.readlines()
source.close()

source = open("saved_data/tau_3_max.txt", "r")
tau_3_max = source.readlines()
source.close()

source = open("saved_data/tau_3_min.txt", "r")
tau_3_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 4)
plt.plot(tau_3)	
plt.plot(tau_3_max, "r")	
plt.plot(tau_3_min, "m")	
plt.plot([0]*np.size(tau_3), "k")
plt.title("tau_3")
plt.ylabel("tau_3")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_3),-100,100])



source = open("saved_data/tau_4.txt", "r")
tau_4 = source.readlines()
source.close()

source = open("saved_data/tau_4_max.txt", "r")
tau_4_max = source.readlines()
source.close()

source = open("saved_data/tau_4_min.txt", "r")
tau_4_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 5)
plt.plot(tau_4)	
plt.plot(tau_4_max, "r")	
plt.plot(tau_4_min, "m")	
plt.plot([0]*np.size(tau_4), "k")
plt.title("tau_4")
plt.ylabel("tau_4")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_4),-100,100])



source = open("saved_data/tau_5.txt", "r")
tau_5 = source.readlines()
source.close()

source = open("saved_data/tau_5_max.txt", "r")
tau_5_max = source.readlines()
source.close()

source = open("saved_data/tau_5_min.txt", "r")
tau_5_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 6)
plt.plot(tau_5)	
plt.plot(tau_5_max, "r")	
plt.plot(tau_5_min, "m")	
plt.plot([0]*np.size(tau_5), "k")
plt.title("tau_5")
plt.ylabel("tau_5")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_5),-100,100])



source = open("saved_data/tau_6.txt", "r")
tau_6 = source.readlines()
source.close()

source = open("saved_data/tau_6_max.txt", "r")
tau_6_max = source.readlines()
source.close()

source = open("saved_data/tau_6_min.txt", "r")
tau_6_min = source.readlines()
source.close()

plt.figure(1)

plt.subplot(2, 4, 7)
plt.plot(tau_6)	
plt.plot(tau_6_max, "r")	
plt.plot(tau_6_min, "m")	
plt.plot([0]*np.size(tau_6), "k")
plt.title("tau_6")
plt.ylabel("tau_6")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_6),-100,100])
#############################Torques plot##############################











#############################q_dot_dot plot##############################
source_1 = open("saved_data/q_dotdot_0.txt", "r")
q_dotdot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_max.txt", "r")
q_dotdot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_0_min.txt", "r")
q_dotdot_0_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 1)
plt.plot(q_dotdot_0, "c")
plt.plot(q_dotdot_0_max, "r")		
plt.plot(q_dotdot_0_min, "m")	
plt.plot([0]*np.size(q_dotdot_0), "k")
plt.title("q_dotdot_0")
plt.ylabel("q_dotdot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_0),-1000,1000])



source_1 = open("saved_data/q_dotdot_1.txt", "r")
q_dotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_max.txt", "r")
q_dotdot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_min.txt", "r")
q_dotdot_1_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 2)
plt.plot(q_dotdot_1, "c")	
plt.plot(q_dotdot_1_max, "r")
plt.plot(q_dotdot_1_min, "m")
plt.plot([0]*np.size(q_dotdot_1), "k")
plt.title("q_dotdot_1")
plt.ylabel("q_dotdot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_1),-1000,1000])



source_1 = open("saved_data/q_dotdot_2.txt", "r")
q_dotdot_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_2_max.txt", "r")
q_dotdot_2_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_2_min.txt", "r")
q_dotdot_2_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 3)
plt.plot(q_dotdot_2, "c")
plt.plot(q_dotdot_2_max, "r")	
plt.plot(q_dotdot_2_min, "m")	
plt.plot([0]*np.size(q_dotdot_2), "k")
plt.title("q_dotdot_2")
plt.ylabel("q_dotdot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_2),-1000,1000])






source_1 = open("saved_data/q_dotdot_3.txt", "r")
q_dotdot_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_3_max.txt", "r")
q_dotdot_3_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_3_min.txt", "r")
q_dotdot_3_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 4)
plt.plot(q_dotdot_3, "c")
plt.plot(q_dotdot_3_max, "r")	
plt.plot(q_dotdot_3_min, "m")	
plt.plot([0]*np.size(q_dotdot_3), "k")
plt.title("q_dotdot_3")
plt.ylabel("q_dotdot_3")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_3),-1000,1000])



source_1 = open("saved_data/q_dotdot_4.txt", "r")
q_dotdot_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_4_max.txt", "r")
q_dotdot_4_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_4_min.txt", "r")
q_dotdot_4_min = source_1.readlines()
source_1.close()


plt.figure(3)

plt.subplot(2, 4, 5)
plt.plot(q_dotdot_4, "c")
plt.plot(q_dotdot_4_max, "r")	
plt.plot(q_dotdot_4_min, "m")
plt.plot([0]*np.size(q_dotdot_4), "k")
plt.title("q_dotdot_4")
plt.ylabel("q_dotdot_4")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_4),-1000,1000])



source_1 = open("saved_data/q_dotdot_5.txt", "r")
q_dotdot_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_5_max.txt", "r")
q_dotdot_5_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_5_min.txt", "r")
q_dotdot_5_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 6)
plt.plot(q_dotdot_5, "c")	
plt.plot(q_dotdot_5_max, "r")	
plt.plot(q_dotdot_5_min, "m")	
plt.plot([0]*np.size(q_dotdot_5), "k")
plt.title("q_dotdot_5")
plt.ylabel("q_dotdot_5")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_5),-1000,1000])



source_1 = open("saved_data/q_dotdot_6.txt", "r")
q_dotdot_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_6_max.txt", "r")
q_dotdot_6_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_6_min.txt", "r")
q_dotdot_6_min = source_1.readlines()
source_1.close()

plt.figure(3)

plt.subplot(2, 4, 7)
plt.plot(q_dotdot_6, "c")
plt.plot(q_dotdot_6_max, "r")	
plt.plot(q_dotdot_6_min, "m")		
plt.plot([0]*np.size(q_dotdot_6), "k")
plt.title("q_dotdot_6")
plt.ylabel("q_dotdot_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_6),-1000,1000])
#############################q_dot_dot plot##############################















#############################q plot##############################
source_1 = open("saved_data/q_0.txt", "r")
q_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_max.txt", "r")
q_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_0_min.txt", "r")
q_0_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 1)
plt.plot(q_0, "c")
plt.plot(q_0_max, "r")		
plt.plot(q_0_min, "m")	
plt.plot([0]*np.size(q_0), "k")
plt.title("q_0")
plt.ylabel("q_0")
plt.xlabel("iteration")
plt.axis([0,np.size(q_0),-5,5])



source_1 = open("saved_data/q_1.txt", "r")
q_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_1_max.txt", "r")
q_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_1_min.txt", "r")
q_1_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 2)
plt.plot(q_1, "c")	
plt.plot(q_1_max, "r")
plt.plot(q_1_min, "m")
plt.plot([0]*np.size(q_1), "k")
plt.title("q_1")
plt.ylabel("q_1")
plt.xlabel("iteration")
plt.axis([0,np.size(q_1),-5,5])



source_1 = open("saved_data/q_2.txt", "r")
q_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_2_max.txt", "r")
q_2_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_2_min.txt", "r")
q_2_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 3)
plt.plot(q_2, "c")
plt.plot(q_2_max, "r")	
plt.plot(q_2_min, "m")	
plt.plot([0]*np.size(q_2), "k")
plt.title("q_2")
plt.ylabel("q_2")
plt.xlabel("iteration")
plt.axis([0,np.size(q_2),-5,5])






source_1 = open("saved_data/q_3.txt", "r")
q_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_3_max.txt", "r")
q_3_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_3_min.txt", "r")
q_3_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 4)
plt.plot(q_3, "c")
plt.plot(q_3_max, "r")	
plt.plot(q_3_min, "m")	
plt.plot([0]*np.size(q_3), "k")
plt.title("q_3")
plt.ylabel("q_3")
plt.xlabel("iteration")
plt.axis([0,np.size(q_3),-5,5])



source_1 = open("saved_data/q_4.txt", "r")
q_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_4_max.txt", "r")
q_4_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_4_min.txt", "r")
q_4_min = source_1.readlines()
source_1.close()


plt.figure(18)

plt.subplot(2, 4, 5)
plt.plot(q_4, "c")
plt.plot(q_4_max, "r")	
plt.plot(q_4_min, "m")
plt.plot([0]*np.size(q_4), "k")
plt.title("q_4")
plt.ylabel("q_4")
plt.xlabel("iteration")
plt.axis([0,np.size(q_4),-5,5])



source_1 = open("saved_data/q_5.txt", "r")
q_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_5_max.txt", "r")
q_5_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_5_min.txt", "r")
q_5_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 6)
plt.plot(q_5, "c")	
plt.plot(q_5_max, "r")	
plt.plot(q_5_min, "m")	
plt.plot([0]*np.size(q_5), "k")
plt.title("q_5")
plt.ylabel("q_5")
plt.xlabel("iteration")
plt.axis([0,np.size(q_5),-5,5])



source_1 = open("saved_data/q_6.txt", "r")
q_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_6_max.txt", "r")
q_6_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_6_min.txt", "r")
q_6_min = source_1.readlines()
source_1.close()

plt.figure(18)

plt.subplot(2, 4, 7)
plt.plot(q_6, "c")
plt.plot(q_6_max, "r")	
plt.plot(q_6_min, "m")		
plt.plot([0]*np.size(q_6), "k")
plt.title("q_6")
plt.ylabel("q_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_6),-5,5])
#############################q plot##############################













#############################Velocities plot##############################
source = open("saved_data/V_7.txt", "r")
V_7 = source.readlines()
source.close()

plt.figure(8)
plt.subplot(2, 2, 1)

plt.plot(V_7, "b")	
plt.plot([0]*np.size(V_7), "k")
plt.title("V_7")
plt.ylabel("V_7")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7),-1.5, 1.5])



source = open("saved_data/V_7_x.txt", "r")
V_7_x = source.readlines()
source.close()

plt.figure(8)
plt.subplot(2, 2, 2)

plt.plot(V_7_x, "b")	
plt.plot([0]*np.size(V_7_x), "k")
plt.title("V_7_x")
plt.ylabel("V_7_x")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_x),-1.5, 1.5])



source = open("saved_data/V_7_y.txt", "r")
V_7_y = source.readlines()
source.close()

plt.figure(8)
plt.subplot(2, 2, 3)

plt.plot(V_7_y, "b")	
plt.plot([0]*np.size(V_7_y), "k")
plt.title("V_7_y")
plt.ylabel("V_7_y")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_y),-1.5, 1.5])



source = open("saved_data/V_7_z.txt", "r")
V_7_z = source.readlines()
source.close()

plt.figure(8)
plt.subplot(2, 2, 4)

plt.plot(V_7_z, "b")	
plt.plot([0]*np.size(V_7_z), "k")
plt.title("V_7_z")
plt.ylabel("V_7_z")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_z),-1.5, 1.5])










source = open("saved_data/V_7_des.txt", "r")
V_7_des = source.readlines()
source.close()


plt.figure(8)
plt.subplot(2, 2, 1)

plt.plot(V_7_des, "r")	
plt.plot([0]*np.size(V_7_des), "k")
plt.title("V_7_des")
plt.ylabel("V_7_des")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_des),-1.5, 1.5])




source = open("saved_data/V_7_des_x.txt", "r")
V_7_des_x = source.readlines()
source.close()


plt.figure(8)
plt.subplot(2, 2, 2)

plt.plot(V_7_des_x, "r")	
plt.plot([0]*np.size(V_7_des_x), "k")
plt.title("V_7_des_x")
plt.ylabel("V_7_des_x")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_des_x),-1.5, 1.5])




source = open("saved_data/V_7_des_y.txt", "r")
V_7_des_y = source.readlines()
source.close()


plt.figure(8)
plt.subplot(2, 2, 3)

plt.plot(V_7_des_y, "r")	
plt.plot([0]*np.size(V_7_des_y), "k")
plt.title("V_7_des_y")
plt.ylabel("V_7_des_y")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_des_y),-1.5, 1.5])




source = open("saved_data/V_7_des_z.txt", "r")
V_7_des_z = source.readlines()
source.close()


plt.figure(8)
plt.subplot(2, 2, 4)

plt.plot(V_7_des_z, "r")	
plt.plot([0]*np.size(V_7_des_z), "k")
plt.title("V_7_des_z")
plt.ylabel("V_7_des_z")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_des_z),-1.5, 1.5])

#############################Velocities plot##############################









#############################End effector Trajectory plot##############################
mpl.rcParams['legend.fontsize'] = 10
fig = plt.figure(5)
ax = fig.gca(projection='3d')
ax = Axes3D(fig)


x_data = np.genfromtxt('saved_data/trajectory_x.txt', dtype=[('x_', float)])
y_data = np.genfromtxt('saved_data/trajectory_y.txt', dtype=[('y_', float)])
z_data = np.genfromtxt('saved_data/trajectory_z.txt', dtype=[('z_', float)])

x = x_data['x_']
y = y_data['y_']
z = z_data['z_']

ax.set_title("Plot 3d",fontsize=14)
ax.set_xlabel('X', fontsize=12)
ax.set_ylabel('Y', fontsize=12)
ax.set_zlabel('Z', fontsize=12)

ax.plot(x, y, z, 'b', label = 'Real_Traj')
#############################End effector Trajectories plot##############################









#############################des Trajectories plot##############################
x_data_des = np.genfromtxt('saved_data/des_trajectory_x.txt', dtype=[('x_', float)])
y_data_des = np.genfromtxt('saved_data/des_trajectory_y.txt', dtype=[('y_', float)])
z_data_des = np.genfromtxt('saved_data/des_trajectory_z.txt', dtype=[('z_', float)])

des_x = x_data_des['x_']
des_y = y_data_des['y_']
des_z = z_data_des['z_']

gloal_x = [0.5]
gloal_y = [0.3]
gloal_z = [0.6]
ax.plot(des_x, des_y, des_z, 'r', label = 'Des_Traj')
#ax.scatter(des_x, des_y, des_z, 'r', label = 'Des_Traj')

#############################des Trajectories plot##############################







#############################DES Acceleration plot##############################
source = open("saved_data/Acc_7_des.txt", "r")
Acc_7_des = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 1)
	
plt.plot(Acc_7_des, "r")	
plt.plot([0]*np.size(Acc_7_des), "k")
plt.title("Acc_7_des")
plt.ylabel("Acc_7_des")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_des),-1.5, 1.5])



source = open("saved_data/Acc_7_des_x.txt", "r")
Acc_7_des_x = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 2)
	
plt.plot(Acc_7_des_x, "r")	
plt.plot([0]*np.size(Acc_7_des_x), "k")
plt.title("Acc_7_des_x")
plt.ylabel("Acc_7_des_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_des_x),-1.5, 1.5])





source = open("saved_data/Acc_7_des_y.txt", "r")
Acc_7_des_y = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 3)
	
plt.plot(Acc_7_des_y, "r")	
plt.plot([0]*np.size(Acc_7_des_y), "k")
plt.title("Acc_7_des_y")
plt.ylabel("Acc_7_des_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_des_y),-1.5, 1.5])




source = open("saved_data/Acc_7_des_z.txt", "r")
Acc_7_des_z = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 4)
	
plt.plot(Acc_7_des_z, "r")	
plt.plot([0]*np.size(Acc_7_des_z), "k")
plt.title("Acc_7_des_z")
plt.ylabel("Acc_7_des_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_des_z),-1.5, 1.5])
#############################DES Acceleration plot##############################








#############################REAL Acceleration plot##############################
source = open("saved_data/Acc_7.txt", "r")
Acc_7 = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 1)
	
plt.plot(Acc_7, "m")	
plt.plot([0]*np.size(Acc_7), "k")
plt.title("Acc_7")
plt.ylabel("Acc_7")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7),-0.3, 0.3])



source = open("saved_data/Acc_7_x.txt", "r")
Acc_7_x = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 2)
	
plt.plot(Acc_7_x, "m")	
plt.plot([0]*np.size(Acc_7_x), "k")
plt.title("Acc_7_x")
plt.ylabel("Acc_7_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_x),-0.3, 0.3])





source = open("saved_data/Acc_7_y.txt", "r")
Acc_7_y = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 3)
	
plt.plot(Acc_7_y, "m")	
plt.plot([0]*np.size(Acc_7_y), "k")
plt.title("Acc_7_y")
plt.ylabel("Acc_7_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_y),-0.3, 0.3])




source = open("saved_data/Acc_7_z.txt", "r")
Acc_7_z = source.readlines()
source.close()

plt.figure(6)

plt.subplot(2, 2, 4)
	
plt.plot(Acc_7_z, "m")	
plt.plot([0]*np.size(Acc_7_z), "k")
plt.title("Acc_7_z")
plt.ylabel("Acc_7_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_z),-0.3, 0.3])
#############################REAL Acceleration plot##############################
















#############################q_dot plot##############################
source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_0_max.txt", "r")
q_dot_0_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_0_min.txt", "r")
q_dot_0_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 1)
plt.plot(q_dot_0, "c")
plt.plot(q_dot_0_max, "r")		
plt.plot(q_dot_0_min, "m")	
plt.plot([0]*np.size(q_dot_0), "k")
plt.title("q_dot_0")
plt.ylabel("q_dot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_0),-3.15,3.15])



source_1 = open("saved_data/q_dot_1.txt", "r")
q_dot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_1_max.txt", "r")
q_dot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_1_min.txt", "r")
q_dot_1_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 2)
plt.plot(q_dot_1, "c")	
plt.plot(q_dot_1_max, "r")
plt.plot(q_dot_1_min, "m")
plt.plot([0]*np.size(q_dot_1), "k")
plt.title("q_dot_1")
plt.ylabel("q_dot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_1),-3.15,3.15])



source_1 = open("saved_data/q_dot_2.txt", "r")
q_dot_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_2_max.txt", "r")
q_dot_2_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_2_min.txt", "r")
q_dot_2_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 3)
plt.plot(q_dot_2, "c")
plt.plot(q_dot_2_max, "r")	
plt.plot(q_dot_2_min, "m")	
plt.plot([0]*np.size(q_dot_2), "k")
plt.title("q_dot_2")
plt.ylabel("q_dot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_2),-3.15,3.15])






source_1 = open("saved_data/q_dot_3.txt", "r")
q_dot_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_3_max.txt", "r")
q_dot_3_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_3_min.txt", "r")
q_dot_3_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 4)
plt.plot(q_dot_3, "c")
plt.plot(q_dot_3_max, "r")	
plt.plot(q_dot_3_min, "m")	
plt.plot([0]*np.size(q_dot_3), "k")
plt.title("q_dot_3")
plt.ylabel("q_dot_3")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_3),-3.15,3.15])



source_1 = open("saved_data/q_dot_4.txt", "r")
q_dot_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_4_max.txt", "r")
q_dot_4_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_4_min.txt", "r")
q_dot_4_min = source_1.readlines()
source_1.close()


plt.figure(7)

plt.subplot(2, 4, 5)
plt.plot(q_dot_4, "c")
plt.plot(q_dot_4_max, "r")	
plt.plot(q_dot_4_min, "m")
plt.plot([0]*np.size(q_dot_4), "k")
plt.title("q_dot_4")
plt.ylabel("q_dot_4")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_4),-3.15,3.15])



source_1 = open("saved_data/q_dot_5.txt", "r")
q_dot_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_5_max.txt", "r")
q_dot_5_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_5_min.txt", "r")
q_dot_5_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 6)
plt.plot(q_dot_5, "c")	
plt.plot(q_dot_5_max, "r")	
plt.plot(q_dot_5_min, "m")	
plt.plot([0]*np.size(q_dot_5), "k")
plt.title("q_dot_5")
plt.ylabel("q_dot_5")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_5),-3.15,3.15])



source_1 = open("saved_data/q_dot_6.txt", "r")
q_dot_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_6_max.txt", "r")
q_dot_6_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_6_min.txt", "r")
q_dot_6_min = source_1.readlines()
source_1.close()

plt.figure(7)

plt.subplot(2, 4, 7)
plt.plot(q_dot_6, "c")
plt.plot(q_dot_6_max, "r")	
plt.plot(q_dot_6_min, "m")		
plt.plot([0]*np.size(q_dot_6), "k")
plt.title("q_dot_6")
plt.ylabel("q_dot_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_6),-3.15,3.15])
#############################q_dot plot##############################





#############################X_err plot##############################
source = open("saved_data/X_err.txt", "r")
X_err = source.readlines()
source.close()

plt.figure(10)

plt.subplot(2, 2, 1)
	
plt.plot(X_err, "b")	
plt.plot([0]*np.size(X_err), "k")
plt.title("X_err")
plt.ylabel("X_err")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err),-0.5, 0.5])



source = open("saved_data/X_err_x.txt", "r")
X_err_x = source.readlines()
source.close()

plt.figure(10)

plt.subplot(2, 2, 2)
	
plt.plot(X_err_x, "b")	
plt.plot([0]*np.size(X_err_x), "k")
plt.title("X_err_x")
plt.ylabel("X_err_x")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_x),-0.5, 0.5])





source = open("saved_data/X_err_y.txt", "r")
X_err_y = source.readlines()
source.close()

plt.figure(10)

plt.subplot(2, 2, 3)
	
plt.plot(X_err_y, "b")	
plt.plot([0]*np.size(X_err_y), "k")
plt.title("X_err_y")
plt.ylabel("X_err_y")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_y),-0.5, 0.5])




source = open("saved_data/X_err_z.txt", "r")
X_err_z = source.readlines()
source.close()

plt.figure(10)

plt.subplot(2, 2, 4)
	
plt.plot(X_err_z, "b")	
plt.plot([0]*np.size(X_err_z), "k")
plt.title("X_err_z")
plt.ylabel("X_err_z")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_z),-0.5, 0.5])
#############################X_err plot##############################












#############################X plot##############################
source = open("saved_data/trajectory_x.txt", "r")
X_x = source.readlines()
source.close()

source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()

plt.figure(11)
plt.subplot(2, 2, 1)
	
plt.plot(X_x, "b")	
plt.plot(des_X_x, "r")
plt.plot([0]*np.size(X_x), "k")
plt.title("X_x")
plt.ylabel("X_x")
plt.xlabel("iteration")
plt.axis([0,np.size(X_x),-0.8, 0.8])





source = open("saved_data/trajectory_y.txt", "r")
X_y = source.readlines()
source.close()

source = open("saved_data/des_trajectory_y.txt", "r")
des_X_y = source.readlines()
source.close()

plt.figure(11)
plt.subplot(2, 2, 2)
	
plt.plot(X_y, "b")	
plt.plot(des_X_y, "r")
plt.plot([0]*np.size(X_y), "k")
plt.title("X_y")
plt.ylabel("X_y")
plt.xlabel("iteration")
plt.axis([0,np.size(X_y),-0.8, 0.8])




source = open("saved_data/trajectory_z.txt", "r")
X_z = source.readlines()
source.close()

source = open("saved_data/des_trajectory_z.txt", "r")
des_X_z = source.readlines()
source.close()

plt.figure(11)
plt.subplot(2, 2, 3)
	
plt.plot(X_z, "b")
plt.plot(des_X_z, "r")	
plt.plot([0]*np.size(X_err_z), "k")
plt.title("X_z")
plt.ylabel("X_z")
plt.xlabel("iteration")
plt.axis([0,np.size(X_z),-0.8, 0.8])
#############################X plot##############################







#############################time plot##############################
#source = open("saved_data/real_step_time.txt", "r")
#real_step_time = source.readlines()
#source.close()

#plt.figure(12)

#plt.plot(real_step_time, "b")	
#plt.plot([0]*np.size(real_step_time), "k")
#plt.title("real_step_time")
#plt.ylabel("real_step_time")
#plt.xlabel("iteration")
#plt.axis([0,np.size(real_step_time),-0.01, 0.01])





#source = open("saved_data/fixed_dt.txt", "r")
#fixed_dt = source.readlines()
#source.close()

#plt.figure(12)

#plt.plot(fixed_dt, "r")	
#plt.plot([0]*np.size(fixed_dt), "k")
#plt.title("fixed_dt & real_step_time")
#plt.ylabel("fixed_dt")
#plt.xlabel("iteration")
#plt.axis([0,np.size(fixed_dt),-0.01, 0.01])
#############################time plot##############################










#############################acos_n_7_0##############################
source = open("saved_data/acos_n_7_0.txt", "r")
acos_n_7_0 = source.readlines()
source.close()

source = open("saved_data/angle_V_7_to_nrst_dist_ob.txt", "r")
angle_V_7_to_nrst_dist_ob = source.readlines()
source.close()


plt.figure(16)


plt.plot(acos_n_7_0, "b")
plt.plot(angle_V_7_to_nrst_dist_ob, "g")
plt.plot([0]*np.size(acos_n_7_0), "k")
plt.title("acos_n_7_0 (b), angle_V_7_to_nrst_dist_ob(k) ")
plt.ylabel("acos_n_7_0 ")
plt.xlabel("iteration")
plt.axis([0,np.size(acos_n_7_0),-90, 180])
#############################acos_n_7_0##############################




#############################norm_axis_of_rot_angle_7##############################
source = open("saved_data/norm_axis_of_rot_angle_7.txt", "r")
norm_axis_of_rot_angle_7 = source.readlines()
source.close()


plt.figure(19)


plt.plot(norm_axis_of_rot_angle_7, "b")
plt.plot([0]*np.size(norm_axis_of_rot_angle_7), "k")
plt.title("norm_axis_of_rot_angle_7 ")
plt.ylabel("norm_axis_of_rot_angle_7 ")
plt.xlabel("iteration")
plt.axis([0,np.size(norm_axis_of_rot_angle_7),-2, 2])
#############################acos_n_7_0##############################





#############################t_1##############################
#source = open("saved_data/t_1.txt", "r")
#t_1 = source.readlines()
#source.close()


#plt.figure(20)


#plt.plot(t_1, "b")
#plt.plot([0]*np.size(t_1), "k")
#plt.title("t_1 ")
#plt.ylabel("t_1 ")
#plt.xlabel("iteration")
#plt.axis([0,np.size(t_1),-5000, 5000])
#############################t_1##############################

















#############################K_p_X_err##############################
source = open("saved_data/K_p_X_err_0.txt", "r")
K_p_X_err_0 = source.readlines()
source.close()

source.close()

plt.figure(35)
plt.subplot(2, 2, 1)
	
plt.plot(K_p_X_err_0, "b")	
plt.plot([0]*np.size(K_p_X_err_0), "k")
plt.title("K_p_X_err_0")
plt.ylabel("K_p_X_err_0")
plt.xlabel("iteration")
plt.axis([0,np.size(K_p_X_err_0),-0.05, 0.05])






source = open("saved_data/K_p_X_err_1.txt", "r")
K_p_X_err_1 = source.readlines()
source.close()

source.close()

plt.figure(35)
plt.subplot(2, 2, 2)
	
plt.plot(K_p_X_err_1, "b")	
plt.plot([0]*np.size(K_p_X_err_0), "k")
plt.title("K_p_X_err_1")
plt.ylabel("K_p_X_err_1")
plt.xlabel("iteration")
plt.axis([0,np.size(K_p_X_err_1),-0.05, 0.05])





source = open("saved_data/K_p_X_err_2.txt", "r")
K_p_X_err_2 = source.readlines()
source.close()

source.close()

plt.figure(35)
plt.subplot(2, 2, 3)
	
plt.plot(K_p_X_err_2, "b")	
plt.plot([0]*np.size(K_p_X_err_2), "k")
plt.title("K_p_X_err_2")
plt.ylabel("K_p_X_err_2")
plt.xlabel("iteration")
plt.axis([0,np.size(K_p_X_err_2),-0.05, 0.05])
#############################K_p_X_err##############################






#############################K_p_X_err_##############################
source = open("saved_data/K_d_V_7_err_0.txt", "r")
K_d_V_7_err_0 = source.readlines()
source.close()

source.close()

plt.figure(34)
plt.subplot(2, 2, 1)
	
plt.plot(K_d_V_7_err_0, "b")	
plt.plot([0]*np.size(K_d_V_7_err_0), "k")
plt.title("K_d_V_7_err_0")
plt.ylabel("K_d_V_7_err_0")
plt.xlabel("iteration")
plt.axis([0,np.size(K_d_V_7_err_0),-0.05, 0.05])






source = open("saved_data/K_d_V_7_err_1.txt", "r")
K_d_V_7_err_1 = source.readlines()
source.close()

source.close()

plt.figure(34)
plt.subplot(2, 2, 2)
	
plt.plot(K_d_V_7_err_1, "b")	
plt.plot([0]*np.size(K_d_V_7_err_0), "k")
plt.title("K_d_V_7_err_1")
plt.ylabel("K_d_V_7_err_1")
plt.xlabel("iteration")
plt.axis([0,np.size(K_d_V_7_err_1),-0.05, 0.05])





source = open("saved_data/K_d_V_7_err_2.txt", "r")
K_d_V_7_err_2 = source.readlines()
source.close()

source.close()

plt.figure(34)
plt.subplot(2, 2, 3)
	
plt.plot(K_d_V_7_err_2, "b")	
plt.plot([0]*np.size(K_d_V_7_err_2), "k")
plt.title("K_d_V_7_err_2")
plt.ylabel("K_d_V_7_err_2")
plt.xlabel("iteration")
plt.axis([0,np.size(K_d_V_7_err_2),-0.05, 0.05])
#############################K_p_X_err_##############################





#############################ERR Acceleration plot##############################
source = open("saved_data/Acc_7_err.txt", "r")
Acc_7_err = source.readlines()
source.close()

plt.figure(36)

plt.subplot(2, 2, 1)
	
plt.plot(Acc_7_err, "r")	
plt.plot([0]*np.size(Acc_7_err), "k")
plt.title("Acc_7_err")
plt.ylabel("Acc_7_err")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_err),-1.5, 1.5])



source = open("saved_data/Acc_7_err_x.txt", "r")
Acc_7_err_x = source.readlines()
source.close()

plt.figure(36)

plt.subplot(2, 2, 2)
	
plt.plot(Acc_7_err_x, "r")	
plt.plot([0]*np.size(Acc_7_err_x), "k")
plt.title("Acc_7_err_x")
plt.ylabel("Acc_7_err_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_err_x),-1.5, 1.5])





source = open("saved_data/Acc_7_err_y.txt", "r")
Acc_7_err_y = source.readlines()
source.close()

plt.figure(36)

plt.subplot(2, 2, 3)
	
plt.plot(Acc_7_err_y, "r")	
plt.plot([0]*np.size(Acc_7_err_y), "k")
plt.title("Acc_7_err_y")
plt.ylabel("Acc_7_err_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_err_y),-1.5, 1.5])




source = open("saved_data/Acc_7_err_z.txt", "r")
Acc_7_err_z = source.readlines()
source.close()

plt.figure(36)

plt.subplot(2, 2, 4)
	
plt.plot(Acc_7_err_z, "r")	
plt.plot([0]*np.size(Acc_7_err_z), "k")
plt.title("Acc_7_err_z")
plt.ylabel("Acc_7_err_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_err_z),-1.5, 1.5])
#############################ERR Acceleration plot##############################









#############################Diff_X_dot_dot_Acc_7_des plot##############################
source = open("saved_data/Diff_X_dot_dot_Acc_7_des.txt", "r")
Diff_X_dot_dot_Acc_7_des = source.readlines()
source.close()

plt.figure(37)

plt.subplot(2, 2, 1)
	
plt.plot(Diff_X_dot_dot_Acc_7_des, "r")	
plt.plot([0]*np.size(Diff_X_dot_dot_Acc_7_des), "k")
plt.title("Diff_X_dot_dot_Acc_7_des")
plt.ylabel("Diff_X_dot_dot_Acc_7_des")
plt.xlabel("iteration")
plt.axis([0,np.size(Diff_X_dot_dot_Acc_7_des),-1.5, 1.5])



source = open("saved_data/Diff_X_dot_dot_Acc_7_des_x.txt", "r")
Diff_X_dot_dot_Acc_7_des_x = source.readlines()
source.close()

plt.figure(37)

plt.subplot(2, 2, 2)
	
plt.plot(Diff_X_dot_dot_Acc_7_des_x, "r")	
plt.plot([0]*np.size(Diff_X_dot_dot_Acc_7_des_x), "k")
plt.title("Diff_X_dot_dot_Acc_7_des_x")
plt.ylabel("Diff_X_dot_dot_Acc_7_des_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Diff_X_dot_dot_Acc_7_des_x),-1.5, 1.5])





source = open("saved_data/Diff_X_dot_dot_Acc_7_des_y.txt", "r")
Diff_X_dot_dot_Acc_7_des_y = source.readlines()
source.close()

plt.figure(37)

plt.subplot(2, 2, 3)
	
plt.plot(Diff_X_dot_dot_Acc_7_des_y, "r")	
plt.plot([0]*np.size(Diff_X_dot_dot_Acc_7_des_y), "k")
plt.title("Diff_X_dot_dot_Acc_7_des_y")
plt.ylabel("Diff_X_dot_dot_Acc_7_des_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Diff_X_dot_dot_Acc_7_des_y),-1.5, 1.5])




source = open("saved_data/Diff_X_dot_dot_Acc_7_des_z.txt", "r")
Diff_X_dot_dot_Acc_7_des_z = source.readlines()
source.close()

plt.figure(37)

plt.subplot(2, 2, 4)
	
plt.plot(Diff_X_dot_dot_Acc_7_des_z, "r")	
plt.plot([0]*np.size(Diff_X_dot_dot_Acc_7_des_z), "k")
plt.title("Diff_X_dot_dot_Acc_7_des_z")
plt.ylabel("Diff_X_dot_dot_Acc_7_des_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Diff_X_dot_dot_Acc_7_des_z),-1.5, 1.5])
#############################Diff_X_dot_dot_Acc_7_des plot##############################






#############################DES Trajectory plot##############################
source = open("saved_data/des_trajectory_x.txt", "r")
des_trajectory_x = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 2)
	
plt.plot(des_trajectory_x, "r")	
plt.plot([0]*np.size(des_trajectory_x), "k")
plt.title("des_trajectory_x")
plt.ylabel("des_trajectory_x")
plt.xlabel("iteration")
plt.axis([0,np.size(des_trajectory_x),-0.9, 0.9])





source = open("saved_data/des_trajectory_y.txt", "r")
des_trajectory_y = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 3)
	
plt.plot(des_trajectory_y, "r")	
plt.plot([0]*np.size(des_trajectory_y), "k")
plt.title("des_trajectory_y")
plt.ylabel("des_trajectory_y")
plt.xlabel("iteration")
plt.axis([0,np.size(des_trajectory_y),-0.9, 0.9])




source = open("saved_data/des_trajectory_z.txt", "r")
des_trajectory_z = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 4)
	
plt.plot(des_trajectory_z, "r")	
plt.plot([0]*np.size(des_trajectory_z), "k")
plt.title("des_trajectory_z")
plt.ylabel("des_trajectory_z")
plt.xlabel("iteration")
plt.axis([0,np.size(des_trajectory_z),-0.9, 0.9])
#############################DES Trajectory plot##############################



#############################REAL Trajectory plot##############################
source = open("saved_data/trajectory_x.txt", "r")
trajectory_x = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 2)
	
plt.plot(trajectory_x, "m")	
plt.plot([0]*np.size(trajectory_x), "k")
plt.title("trajectory_x")
plt.ylabel("trajectory_x")
plt.xlabel("iteration")
plt.axis([0,np.size(trajectory_x),-0.9, 0.9])





source = open("saved_data/trajectory_y.txt", "r")
trajectory_y = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 3)
	
plt.plot(trajectory_y, "m")	
plt.plot([0]*np.size(trajectory_y), "k")
plt.title("trajectory_y")
plt.ylabel("trajectory_y")
plt.xlabel("iteration")
plt.axis([0,np.size(trajectory_y),-0.9, 0.9])




source = open("saved_data/trajectory_z.txt", "r")
trajectory_z = source.readlines()
source.close()

plt.figure(38)

plt.subplot(2, 2, 4)
	
plt.plot(trajectory_z, "m")	
plt.plot([0]*np.size(trajectory_z), "k")
plt.title("trajectory_z")
plt.ylabel("trajectory_z")
plt.xlabel("iteration")
plt.axis([0,np.size(trajectory_z),-0.9, 0.9])
#############################REAL Trajectory plot##############################

plt.show()
