import matplotlib.pyplot as plt	
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import pylab





##############################Energy plot##############################
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()


#source = open("saved_data/E_7_C_ob.txt", "r")
#E_7_C_ob = source.readlines()
#source.close()


#plt.figure(0)

#plt.subplot(2, 3, 1)
#plt.plot(E_7)	
#plt.plot(E_7_max, 'r')
#plt.plot(E_7_C_ob, "g")
#plt.plot([0]*np.size(E_7), "k")
#plt.title("E_7")
#plt.ylabel("E_7_max (r), E_7 (b), E_7_C_ob_real (g) ")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_7),-0.06,0.9])





#source = open("saved_data/E_6.txt", "r")
#E_6 = source.readlines()
#source.close()

#source = open("saved_data/E_6_max.txt", "r")
#E_6_max = source.readlines()
#source.close()

#plt.figure(0)

#plt.subplot(2, 3, 2)
#plt.plot(E_6)	
#plt.plot(E_6_max, 'r')
#plt.plot([0]*np.size(E_6), "k")
#plt.title("E_6")
#plt.ylabel("E_6")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_6),-0.06,0.9])








#source = open("saved_data/E_5.txt", "r")
#E_5 = source.readlines()
#source.close()

#source = open("saved_data/E_5_max.txt", "r")
#E_5_max = source.readlines()
#source.close()

#plt.figure(0)

#plt.subplot(2, 3, 3)
#plt.plot(E_5)	
#plt.plot(E_5_max, 'r')
#plt.plot([0]*np.size(E_5), "k")
#plt.title("E_5")
#plt.ylabel("E_5")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_5),-0.06,0.9])








#source = open("saved_data/E_4.txt", "r")
#E_4 = source.readlines()
#source.close()

#source = open("saved_data/E_4_max.txt", "r")
#E_4_max = source.readlines()
#source.close()

#plt.figure(0)

#plt.subplot(2, 3, 4)
#plt.plot(E_4)	
#plt.plot(E_4_max, 'r')
#plt.plot([0]*np.size(E_4), "k")
#plt.title("E_4")
#plt.ylabel("E_4")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_4),-0.06,0.9])









#source = open("saved_data/E_3.txt", "r")
#E_3 = source.readlines()
#source.close()

#source = open("saved_data/E_3_max.txt", "r")
#E_3_max = source.readlines()
#source.close()

#plt.figure(0)

#plt.subplot(2, 3, 5)
#plt.plot(E_3)	
#plt.plot(E_3_max, 'r')
#plt.plot([0]*np.size(E_3), "k")
#plt.title("E_3")
#plt.ylabel("E_3")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_3),-0.06,0.9])







#source = open("saved_data/E_2.txt", "r")
#E_2 = source.readlines()
#source.close()

#source = open("saved_data/E_2_max.txt", "r")
#E_2_max = source.readlines()
#source.close()

#source.close()

#plt.figure(0)

#plt.subplot(2, 3, 6)
#plt.plot(E_2)	
#plt.plot(E_2_max, 'r')
#plt.plot([0]*np.size(E_2), "k")
#plt.title("E_2")
#plt.ylabel("E_2")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_2),-0.06,0.9])
#############################Energy plot##############################











 
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
plt.axis([0,np.size(q_dotdot_0),-10,10])



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
plt.axis([0,np.size(q_dotdot_1),-10,10])



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
plt.axis([0,np.size(q_dotdot_2),-10,10])






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
plt.axis([0,np.size(q_dotdot_3),-10,10])



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
plt.axis([0,np.size(q_dotdot_4),-10,10])



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
plt.axis([0,np.size(q_dotdot_5),-10,10])



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
plt.axis([0,np.size(q_dotdot_6),-10,10])
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
plt.plot(q_0, "b")
plt.plot(q_0_max, "r")		
plt.plot(q_0_min, "r")	
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
plt.plot(q_1, "b")	
plt.plot(q_1_max, "r")
plt.plot(q_1_min, "r")
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
plt.plot(q_2, "b")
plt.plot(q_2_max, "r")	
plt.plot(q_2_min, "r")	
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
plt.plot(q_3, "b")
plt.plot(q_3_max, "r")	
plt.plot(q_3_min, "r")	
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
plt.plot(q_4, "b")
plt.plot(q_4_max, "r")	
plt.plot(q_4_min, "r")
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
plt.plot(q_5, "b")	
plt.plot(q_5_max, "r")	
plt.plot(q_5_min, "r")	
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
plt.plot(q_6, "b")
plt.plot(q_6_max, "r")	
plt.plot(q_6_min, "r")		
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


























#############################DES Jerk plot##############################
source = open("saved_data/Jerk_7_des.txt", "r")
Jerk_7_des = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 1)
	
plt.plot(Jerk_7_des, "r")	
plt.plot([0]*np.size(Jerk_7_des), "k")
plt.title("Jerk_7_des")
plt.ylabel("Jerk_7_des")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_des),-1.5, 1.5])



source = open("saved_data/Jerk_7_des_x.txt", "r")
Jerk_7_des_x = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 2)
	
plt.plot(Jerk_7_des_x, "r")	
plt.plot([0]*np.size(Jerk_7_des_x), "k")
plt.title("Jerk_7_des_x")
plt.ylabel("Jerk_7_des_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_des_x),-1.5, 1.5])





source = open("saved_data/Jerk_7_des_y.txt", "r")
Jerk_7_des_y = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 3)
	
plt.plot(Jerk_7_des_y, "r")	
plt.plot([0]*np.size(Jerk_7_des_y), "k")
plt.title("Jerk_7_des_y")
plt.ylabel("Jerk_7_des_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_des_y),-1.5, 1.5])




source = open("saved_data/Jerk_7_des_z.txt", "r")
Jerk_7_des_z = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 4)
	
plt.plot(Jerk_7_des_z, "r")	
plt.plot([0]*np.size(Jerk_7_des_z), "k")
plt.title("Jerk_7_des_z")
plt.ylabel("Jerk_7_des_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_des_z),-1.5, 1.5])
#############################DES Jerkeleration plot##############################






#############################REAL Jerk plot##############################
source = open("saved_data/Jerk_7.txt", "r")
Jerk_7 = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 1)
	
plt.plot(Jerk_7, "m")	
plt.plot([0]*np.size(Jerk_7), "k")
plt.title("Jerk_7")
plt.ylabel("Jerk_7")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7),-0.3, 0.3])



source = open("saved_data/Jerk_7_x.txt", "r")
Jerk_7_x = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 2)
	
plt.plot(Jerk_7_x, "m")	
plt.plot([0]*np.size(Jerk_7_x), "k")
plt.title("Jerk_7_x")
plt.ylabel("Jerk_7_x")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_x),-0.3, 0.3])





source = open("saved_data/Jerk_7_y.txt", "r")
Jerk_7_y = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 3)
	
plt.plot(Jerk_7_y, "m")	
plt.plot([0]*np.size(Jerk_7_y), "k")
plt.title("Jerk_7_y")
plt.ylabel("Jerk_7_y")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_y),-0.3, 0.3])




source = open("saved_data/Jerk_7_z.txt", "r")
Jerk_7_z = source.readlines()
source.close()

plt.figure(31)

plt.subplot(2, 2, 4)
	
plt.plot(Jerk_7_z, "m")	
plt.plot([0]*np.size(Jerk_7_z), "k")
plt.title("Jerk_7_z")
plt.ylabel("Jerk_7_z")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_7_z),-0.3, 0.3])
#############################REAL Jerk plot##############################








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
plt.plot(q_dot_0, "b")
plt.plot(q_dot_0_max, "r")		
plt.plot(q_dot_0_min, "r")	
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
plt.plot(q_dot_1, "b")	
plt.plot(q_dot_1_max, "r")
plt.plot(q_dot_1_min, "r")
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
plt.plot(q_dot_2, "b")
plt.plot(q_dot_2_max, "r")	
plt.plot(q_dot_2_min, "r")	
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
plt.plot(q_dot_3, "b")
plt.plot(q_dot_3_max, "r")	
plt.plot(q_dot_3_min, "r")	
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
plt.plot(q_dot_4, "b")
plt.plot(q_dot_4_max, "r")	
plt.plot(q_dot_4_min, "r")
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
plt.plot(q_dot_5, "b")	
plt.plot(q_dot_5_max, "r")	
plt.plot(q_dot_5_min, "r")	
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
plt.plot(q_dot_6, "b")
plt.plot(q_dot_6_max, "r")	
plt.plot(q_dot_6_min, "r")		
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
	
plt.plot(X_x, "b", linewidth=1.0, label = 'real Xx')	
plt.plot(des_X_x, "r", linewidth=1.0, label = 'des Xx')
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






source = open("saved_data/X_err.txt", "r")
X_err = source.readlines()
source.close()

plt.figure(11)

plt.subplot(2, 2, 4)
	
plt.plot(X_err, "b")	
plt.plot([0]*np.size(X_err), "k")
plt.title("X_err")
plt.ylabel("X_err")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err),0.0, 0.005])
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












































#############################s##############################
source = open("saved_data/s_x.txt", "r")
s_x = source.readlines()
source.close()

source.close()

plt.figure(25)
plt.subplot(2, 2, 1)
	
plt.plot(s_x, "b")	
plt.plot([0]*np.size(s_x), "k")
plt.title("s_x")
plt.ylabel("s_x")
plt.xlabel("iteration")
plt.axis([0,np.size(s_x),-10, 10])






source = open("saved_data/s_y.txt", "r")
s_y = source.readlines()
source.close()

source.close()

plt.figure(25)
plt.subplot(2, 2, 2)
	
plt.plot(s_y, "b")	
plt.plot([0]*np.size(s_y), "k")
plt.title("s_y")
plt.ylabel("s_y")
plt.xlabel("iteration")
plt.axis([0,np.size(s_y),-10, 10])






source = open("saved_data/s_z.txt", "r")
s_z = source.readlines()
source.close()

source.close()

plt.figure(25)
plt.subplot(2, 2, 3)
	
plt.plot(s_z, "b")	
plt.plot([0]*np.size(s_z), "k")
plt.title("s_z")
plt.ylabel("s_z")
plt.xlabel("iteration")
plt.axis([0,np.size(s_z),-10, 10])
#############################s##############################











#############################s_dot##############################
source = open("saved_data/s_dot_x.txt", "r")
s_dot_x = source.readlines()
source.close()

source.close()

plt.figure(27)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_x, "b")	
plt.plot([0]*np.size(s_dot_x), "k")
plt.title("s_dot_x")
plt.ylabel("s_dot_x")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_x),-10, 10])






source = open("saved_data/s_dot_y.txt", "r")
s_dot_y = source.readlines()
source.close()

source.close()

plt.figure(27)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_y, "b")	
plt.plot([0]*np.size(s_dot_y), "k")
plt.title("s_dot_y")
plt.ylabel("s_dot_y")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_y),-10, 10])






source = open("saved_data/s_dot_z.txt", "r")
s_dot_z = source.readlines()
source.close()

source.close()

plt.figure(27)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_z, "b")	
plt.plot([0]*np.size(s_dot_z), "k")
plt.title("s_dot_z")
plt.ylabel("s_dot_z")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_z),-10, 10])
#############################s_dot##############################













#############################s_dot_dot##############################
source = open("saved_data/s_dot_dot_x.txt", "r")
s_dot_dot_x = source.readlines()
source.close()

source.close()

plt.figure(28)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_dot_x, "b")	
plt.plot([0]*np.size(s_dot_dot_x), "k")
plt.title("s_dot_dot_x")
plt.ylabel("s_dot_dot_x")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_x),-10, 10])






source = open("saved_data/s_dot_dot_y.txt", "r")
s_dot_dot_y = source.readlines()
source.close()

source.close()

plt.figure(28)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_dot_y, "b")	
plt.plot([0]*np.size(s_dot_dot_y), "k")
plt.title("s_dot_dot_y")
plt.ylabel("s_dot_dot_y")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_y),-10, 10])






source = open("saved_data/s_dot_dot_z.txt", "r")
s_dot_dot_z = source.readlines()
source.close()

source.close()

plt.figure(28)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_dot_z, "b")	
plt.plot([0]*np.size(s_dot_dot_z), "k")
plt.title("s_dot_dot_z")
plt.ylabel("s_dot_dot_z")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_z),-10, 10])
#############################s_dot_dot##############################










#############################s_dot_dot_dot##############################
source = open("saved_data/s_dot_dot_dot_x.txt", "r")
s_dot_dot_dot_x = source.readlines()
source.close()

source.close()

plt.figure(30)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_dot_dot_x, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_x), "k")
plt.title("s_dot_dot_dot_x")
plt.ylabel("s_dot_dot_dot_x")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_x),-10, 10])






source = open("saved_data/s_dot_dot_dot_y.txt", "r")
s_dot_dot_dot_y = source.readlines()
source.close()

source.close()

plt.figure(30)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_dot_dot_y, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_y), "k")
plt.title("s_dot_dot_dot_y")
plt.ylabel("s_dot_dot_dot_y")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_y),-10, 10])






source = open("saved_data/s_dot_dot_dot_z.txt", "r")
s_dot_dot_dot_z = source.readlines()
source.close()

source.close()

plt.figure(30)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_dot_dot_z, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_z), "k")
plt.title("s_dot_dot_dot_z")
plt.ylabel("s_dot_dot_dot_z")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_z),-10, 10])
#############################s_dot_dot_dot##############################












#############################T_x##############################
source = open("saved_data/T_x.txt", "r")
T_x = source.readlines()
source.close()

source.close()

plt.figure(26)
plt.subplot(2, 2, 1)
	
plt.plot(T_x, "b")	
plt.plot([0]*np.size(T_x), "k")
plt.title("T_x")
plt.ylabel("T_x")
plt.xlabel("iteration")
plt.axis([0,np.size(T_x),-10, 10])






source = open("saved_data/T_y.txt", "r")
T_y = source.readlines()
source.close()

source.close()

plt.figure(26)
plt.subplot(2, 2, 2)
	
plt.plot(T_y, "b")	
plt.plot([0]*np.size(T_y), "k")
plt.title("T_y")
plt.ylabel("T_y")
plt.xlabel("iteration")
plt.axis([0,np.size(T_y),-10, 10])






source = open("saved_data/T_z.txt", "r")
T_z = source.readlines()
source.close()

source.close()

plt.figure(26)
plt.subplot(2, 2, 3)
	
plt.plot(T_z, "b")	
plt.plot([0]*np.size(T_z), "k")
plt.title("T_z")
plt.ylabel("T_z")
plt.xlabel("iteration")
plt.axis([0,np.size(T_z),-10, 10])
#############################T_x##############################









#############################t_2_x##############################
source = open("saved_data/t_2_x.txt", "r")
t_2_x = source.readlines()
source.close()

source.close()

plt.figure(29)
plt.subplot(2, 2, 1)
	
plt.plot(t_2_x, "b")	
plt.plot([0]*np.size(t_2_x), "k")
plt.title("t_2_x")
plt.ylabel("t_2_x")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_x),-10, 10])






source = open("saved_data/t_2_y.txt", "r")
t_2_y = source.readlines()
source.close()

source.close()

plt.figure(29)
plt.subplot(2, 2, 2)
	
plt.plot(t_2_y, "b")	
plt.plot([0]*np.size(t_2_y), "k")
plt.title("t_2_y")
plt.ylabel("t_2_y")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_y),-10, 10])






source = open("saved_data/t_2_z.txt", "r")
t_2_z = source.readlines()
source.close()

source.close()

plt.figure(29)
plt.subplot(2, 2, 3)
	
plt.plot(t_2_z, "b")	
plt.plot([0]*np.size(t_2_z), "k")
plt.title("t_2_z")
plt.ylabel("t_2_z")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_z),-10, 10])
#############################t_2_x##############################


























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
	
plt.plot(trajectory_x, "b", linewidth=1.0, label = 'X_x')	
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
	
plt.plot(trajectory_y, "b", linewidth=1.0, label = 'X_y')	
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
	
plt.plot(trajectory_z, "b", linewidth=1.0, label = 'X_z')	
plt.plot([0]*np.size(trajectory_z), "k")
plt.title("trajectory_z")
plt.ylabel("trajectory_z")
plt.xlabel("iteration")
plt.axis([0,np.size(trajectory_z),-0.9, 0.9])
#############################REAL Trajectory plot##############################










#############################s_angle##############################
source = open("saved_data/s_angle.txt", "r")
s_angle = source.readlines()
source.close()

source.close()

plt.figure(25)
plt.subplot(2, 2, 4)
	
plt.plot(s_angle, "b")	
plt.plot([0]*np.size(s_angle), "k")
plt.title("s_angle")
plt.ylabel("s_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(s_angle),-10, 10])
#############################s_angle##############################

#############################s_dot_angle##############################
source = open("saved_data/s_dot_angle.txt", "r")
s_dot_angle = source.readlines()
source.close()

source.close()

plt.figure(27)
plt.subplot(2, 2, 4)
	
plt.plot(s_dot_angle, "b")	
plt.plot([0]*np.size(s_dot_angle), "k")
plt.title("s_dot_angle")
plt.ylabel("s_dot_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_angle),-10, 10])
#############################s_dot_angle##############################

#############################s_dot_dot_angle##############################
source = open("saved_data/s_dot_dot_angle.txt", "r")
s_dot_dot_angle = source.readlines()
source.close()

source.close()

plt.figure(28)
plt.subplot(2, 2, 4)
	
plt.plot(s_dot_dot_angle, "b")	
plt.plot([0]*np.size(s_dot_dot_angle), "k")
plt.title("s_dot_dot_angle")
plt.ylabel("s_dot_dot_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_angle),-10, 10])
#############################s_dot_dot_angle##############################

#############################s_dot_dot_dot_angle##############################
source = open("saved_data/s_dot_dot_dot_angle.txt", "r")
s_dot_dot_dot_angle = source.readlines()
source.close()

source.close()

plt.figure(30)
plt.subplot(2, 2, 4)
	
plt.plot(s_dot_dot_dot_angle, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_angle), "k")
plt.title("s_dot_dot_dot_angle")
plt.ylabel("s_dot_dot_dot_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_angle),-10, 10])
#############################s_dot_dot_dot_angle##############################

#############################t_2_angle##############################
source = open("saved_data/t_2_angle.txt", "r")
t_2_angle = source.readlines()
source.close()

source.close()

plt.figure(29)
plt.subplot(2, 2, 4)
	
plt.plot(t_2_angle, "b")	
plt.plot([0]*np.size(t_2_angle), "k")
plt.title("t_2_angle")
plt.ylabel("t_2_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_angle),-10, 10])
#############################t_2_angle##############################

#############################T_angle##############################
source = open("saved_data/T_angle.txt", "r")
T_angle = source.readlines()
source.close()

source.close()

plt.figure(26)
plt.subplot(2, 2, 4)
	
plt.plot(T_angle, "b")	
plt.plot([0]*np.size(T_angle), "k")
plt.title("T_angle")
plt.ylabel("T_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(T_angle),-10, 10])
#############################T_angle##############################











#############################angle_curr_rot & nxt_step_des_angle plot##############################
source = open("saved_data/angle_curr_rot.txt", "r")
angle_curr_rot = source.readlines()
source.close()


source = open("saved_data/nxt_step_des_angle.txt", "r")
nxt_step_des_angle = source.readlines()
source.close()


plt.figure(39)

plt.plot(angle_curr_rot, "b")	
plt.plot(nxt_step_des_angle, "r")	
plt.plot([0]*np.size(angle_curr_rot), "k")
plt.title("angle_curr_rot")
plt.ylabel("angle_curr_rot")
plt.xlabel("iteration")
plt.axis([0,np.size(angle_curr_rot),-1.5, 1.5])
#############################angle_curr_rot & nxt_step_des_angle plot##############################

#############################Angle Velocities plot##############################
source = open("saved_data/V_angle_curr_rot.txt", "r")
V_angle_curr_rot = source.readlines()
source.close()


source = open("saved_data/nxt_step_des_V_7_angle.txt", "r")
nxt_step_des_V_7_angle = source.readlines()
source.close()


plt.figure(40)

plt.plot(V_angle_curr_rot, "b")	
plt.plot(nxt_step_des_V_7_angle, "r")	
plt.plot([0]*np.size(V_angle_curr_rot), "k")
plt.title("V_angle_curr_rot & nxt_step_des_V_7_angle")
plt.ylabel("V_angle_curr_rot & nxt_step_des_V_7_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(V_angle_curr_rot),-1.5, 1.5])
#############################Angle Velocities plot##############################

#############################Angle Acc plot##############################
source = open("saved_data/Acc_angle_curr_rot.txt", "r")
Acc_angle_curr_rot = source.readlines()
source.close()


source = open("saved_data/nxt_step_des_Acc_7_angle.txt", "r")
nxt_step_des_Acc_7_angle = source.readlines()
source.close()


plt.figure(41)

plt.plot(Acc_angle_curr_rot, "b")	
plt.plot(nxt_step_des_Acc_7_angle, "r")	
plt.plot([0]*np.size(Acc_angle_curr_rot), "k")
plt.title("Acc_angle_curr_rot & nxt_step_des_Acc_7_angle")
plt.ylabel("Acc_angle_curr_rot & nxt_step_des_Acc_7_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_angle_curr_rot),-1.5, 1.5])
#############################Angle Acc plot##############################


#############################Angle Jerk plot##############################
source = open("saved_data/Jerk_angle_curr_rot.txt", "r")
Jerk_angle_curr_rot = source.readlines()
source.close()


source = open("saved_data/nxt_step_des_Jerk_7_angle.txt", "r")
nxt_step_des_Jerk_7_angle = source.readlines()
source.close()


plt.figure(42)

plt.plot(Jerk_angle_curr_rot, "b")	
plt.plot(nxt_step_des_Jerk_7_angle, "r")	
plt.plot([0]*np.size(Jerk_angle_curr_rot), "k")
plt.title("Jerk_angle_curr_rot & nxt_step_des_Jerk_7_angle")
plt.ylabel("Jerk_angle_curr_rot & nxt_step_des_Jerk_7_angle")
plt.xlabel("iteration")
plt.axis([0,np.size(Jerk_angle_curr_rot),-1.5, 1.5])
#############################Angle Jerk plot##############################











#############################X_err_orient plot##############################
source = open("saved_data/norme_X_err_orient.txt", "r")
norme_X_err_orient = source.readlines()
source.close()

plt.figure(43)

plt.subplot(2, 2, 1)
	
plt.plot(norme_X_err_orient, "b")	
plt.plot([0]*np.size(norme_X_err_orient), "k")
plt.title("norme_X_err_orient")
plt.ylabel("norme_X_err_orient")
plt.xlabel("iteration")
plt.axis([0,np.size(norme_X_err_orient),-0.5, 0.5])




source = open("saved_data/X_err_orient_0.txt", "r")
X_err_orient_0 = source.readlines()
source.close()

plt.figure(43)

plt.subplot(2, 2, 2)
	
plt.plot(X_err_orient_0, "b")	
plt.plot([0]*np.size(X_err_orient_0), "k")
plt.title("X_err_orient_0")
plt.ylabel("X_err_orient_0")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_orient_0),-0.5, 0.5])





source = open("saved_data/X_err_orient_1.txt", "r")
X_err_orient_1 = source.readlines()
source.close()

plt.figure(43)

plt.subplot(2, 2, 3)
	
plt.plot(X_err_orient_1, "b")	
plt.plot([0]*np.size(X_err_orient_1), "k")
plt.title("X_err_orient_1")
plt.ylabel("X_err_orient_1")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_orient_1),-0.5, 0.5])




source = open("saved_data/X_err_orient_2.txt", "r")
X_err_orient_2 = source.readlines()
source.close()

plt.figure(43)

plt.subplot(2, 2, 4)
	
plt.plot(X_err_orient_2, "b")	
plt.plot([0]*np.size(X_err_orient_2), "k")
plt.title("X_err_orient_2")
plt.ylabel("X_err_orient_2")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err_orient_2),-0.5, 0.5])
#############################X_err_orient plot##############################









#############################Err_interpolation_aggle plot##############################
source = open("saved_data/Err_interpolation_aggle.txt", "r")
Err_interpolation_aggle = source.readlines()
source.close()

plt.figure(44)

	
plt.plot(Err_interpolation_aggle, "b")	
plt.plot([0]*np.size(Err_interpolation_aggle), "k")
plt.title("Err_interpolation_aggle en deg")
plt.ylabel("Err_interpolation_aggle en deg")
plt.xlabel("iteration")
plt.axis([0,np.size(Err_interpolation_aggle),-0.5, 0.5])
#############################Err_interpolation_aggle plot##############################





#############################DES Angle Acceleration plot##############################
source = open("saved_data/norme_Acc_7_orient_des.txt", "r")
norme_Acc_7_orient_des = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 1)
	
plt.plot(norme_Acc_7_orient_des, "r")	
plt.plot([0]*np.size(norme_Acc_7_orient_des), "k")
plt.title("norme_Acc_7_orient_des")
plt.ylabel("norme_Acc_7_orient_des")
plt.xlabel("iteration")
plt.axis([0,np.size(norme_Acc_7_orient_des),-1.5, 1.5])



source = open("saved_data/Acc_7_orient_des_0.txt", "r")
Acc_7_orient_des_0 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 2)
	
plt.plot(Acc_7_orient_des_0, "r")	
plt.plot([0]*np.size(Acc_7_orient_des_0), "k")
plt.title("Acc_7_orient_des_0")
plt.ylabel("Acc_7_orient_des_0")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_des_0),-1.5, 1.5])





source = open("saved_data/Acc_7_orient_des_1.txt", "r")
Acc_7_orient_des_1 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 3)
	
plt.plot(Acc_7_orient_des_1, "r")	
plt.plot([0]*np.size(Acc_7_orient_des_1), "k")
plt.title("Acc_7_orient_des_1")
plt.ylabel("Acc_7_orient_des_1")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_des_1),-1.5, 1.5])




source = open("saved_data/Acc_7_orient_des_2.txt", "r")
Acc_7_orient_des_2 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 4)
	
plt.plot(Acc_7_orient_des_2, "r")	
plt.plot([0]*np.size(Acc_7_orient_des_2), "k")
plt.title("Acc_7_orient_des_2")
plt.ylabel("Acc_7_orient_des_2")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_des_2),-1.5, 1.5])
#############################DES Angle Acceleration plot##############################

#############################REAL Angle Acceleration plot##############################
source = open("saved_data/norme_Acc_7_orient.txt", "r")
norme_Acc_7_orient = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 1)
	
plt.plot(norme_Acc_7_orient, "b")	
plt.plot([0]*np.size(norme_Acc_7_orient), "k")
plt.title("norme_Acc_7_orient")
plt.ylabel("norme_Acc_7_orient")
plt.xlabel("iteration")
plt.axis([0,np.size(norme_Acc_7_orient),-0.3, 0.3])



source = open("saved_data/Acc_7_orient_0.txt", "r")
Acc_7_orient_0 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 2)
	
plt.plot(Acc_7_orient_0, "b")	
plt.plot([0]*np.size(Acc_7_orient_0), "k")
plt.title("Acc_7_orient_0")
plt.ylabel("Acc_7_orient_0")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_0),-0.3, 0.3])





source = open("saved_data/Acc_7_orient_1.txt", "r")
Acc_7_orient_1 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 3)
	
plt.plot(Acc_7_orient_1, "b")	
plt.plot([0]*np.size(Acc_7_orient_1), "k")
plt.title("Acc_7_orient_1")
plt.ylabel("Acc_7_orient_1")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_1),-0.3, 0.3])




source = open("saved_data/Acc_7_orient_2.txt", "r")
Acc_7_orient_2 = source.readlines()
source.close()

plt.figure(46)

plt.subplot(2, 2, 4)
	
plt.plot(Acc_7_orient_2, "b")	
plt.plot([0]*np.size(Acc_7_orient_2), "k")
plt.title("Acc_7_orient_2")
plt.ylabel("Acc_7_orient_2")
plt.xlabel("iteration")
plt.axis([0,np.size(Acc_7_orient_2),-0.3, 0.3])
#############################REAL Angle Acceleration plot##############################



#############################DES Angle Velocity plot##############################
source = open("saved_data/norme_V_7_orient_des.txt", "r")
norme_V_7_orient_des = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 1)
	
plt.plot(norme_V_7_orient_des, "r")	
plt.plot([0]*np.size(norme_V_7_orient_des), "k")
plt.title("norme_V_7_orient_des")
plt.ylabel("norme_V_7_orient_des")
plt.xlabel("iteration")
plt.axis([0,np.size(norme_V_7_orient_des),-1.5, 1.5])



source = open("saved_data/V_7_orient_des_0.txt", "r")
V_7_orient_des_0 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 2)
	
plt.plot(V_7_orient_des_0, "r")	
plt.plot([0]*np.size(V_7_orient_des_0), "k")
plt.title("V_7_orient_des_0")
plt.ylabel("V_7_orient_des_0")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_des_0),-1.5, 1.5])





source = open("saved_data/V_7_orient_des_1.txt", "r")
V_7_orient_des_1 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 3)
	
plt.plot(V_7_orient_des_1, "r")	
plt.plot([0]*np.size(V_7_orient_des_1), "k")
plt.title("V_7_orient_des_1")
plt.ylabel("V_7_orient_des_1")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_des_1),-1.5, 1.5])




source = open("saved_data/V_7_orient_des_2.txt", "r")
V_7_orient_des_2 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 4)
	
plt.plot(V_7_orient_des_2, "r")	
plt.plot([0]*np.size(V_7_orient_des_2), "k")
plt.title("V_7_orient_des_2")
plt.ylabel("V_7_orient_des_2")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_des_2),-1.5, 1.5])
#############################DES Angle Velocity plot##############################

#############################REAL Angle Velocity plot##############################
source = open("saved_data/norme_V_7_orient.txt", "r")
norme_V_7_orient = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 1)
	
plt.plot(norme_V_7_orient, "b")	
plt.plot([0]*np.size(norme_V_7_orient), "k")
plt.title("norme_V_7_orient")
plt.ylabel("norme_V_7_orient")
plt.xlabel("iteration")
plt.axis([0,np.size(norme_V_7_orient),-0.3, 0.3])



source = open("saved_data/V_7_orient_0.txt", "r")
V_7_orient_0 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 2)
	
plt.plot(V_7_orient_0, "b")	
plt.plot([0]*np.size(V_7_orient_0), "k")
plt.title("V_7_orient_0")
plt.ylabel("V_7_orient_0")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_0),-0.3, 0.3])





source = open("saved_data/V_7_orient_1.txt", "r")
V_7_orient_1 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 3)
	
plt.plot(V_7_orient_1, "b")	
plt.plot([0]*np.size(V_7_orient_1), "k")
plt.title("V_7_orient_1")
plt.ylabel("V_7_orient_1")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_1),-0.3, 0.3])




source = open("saved_data/V_7_orient_2.txt", "r")
V_7_orient_2 = source.readlines()
source.close()

plt.figure(47)

plt.subplot(2, 2, 4)
	
plt.plot(V_7_orient_2, "b")	
plt.plot([0]*np.size(V_7_orient_2), "k")
plt.title("V_7_orient_2")
plt.ylabel("V_7_orient_2")
plt.xlabel("iteration")
plt.axis([0,np.size(V_7_orient_2),-0.3, 0.3])
#############################REAL Angle Velocity plot##############################
































#############################Des_quaternions plot##############################
source_1 = open("saved_data/des_qw.txt", "r")
des_qw = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 1)
plt.plot(des_qw, "r")	
plt.plot([0]*np.size(des_qw), "k")
plt.title("des_qw")
plt.ylabel("des_qw")
plt.xlabel("iteration")
plt.axis([0,np.size(des_qw),-1,1])



source_1 = open("saved_data/des_qx.txt", "r")
des_qx = source_1.readlines()
source_1.close()

plt.figure(51)

plt.subplot(2, 4, 2)
plt.plot(des_qx, "r")	
plt.plot([0]*np.size(des_qx), "k")
plt.title("des_qx")
plt.ylabel("des_qx")
plt.xlabel("iteration")
plt.axis([0,np.size(des_qx),-1,1])



source_1 = open("saved_data/des_qy.txt", "r")
des_qy = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 3)
plt.plot(des_qy, "r")	
plt.plot([0]*np.size(des_qy), "k")
plt.title("des_qy")
plt.ylabel("des_qy")
plt.xlabel("iteration")
plt.axis([0,np.size(des_qy),-1,1])






source_1 = open("saved_data/des_qz.txt", "r")
des_qz = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 4)
plt.plot(des_qz, "r")	
plt.plot([0]*np.size(des_qz), "k")
plt.title("des_qz")
plt.ylabel("des_qz")
plt.xlabel("iteration")
plt.axis([0,np.size(des_qz),-1,1])
#############################Des_quaternions plot##############################

#############################Real quaternions plot##############################
source_1 = open("saved_data/qw.txt", "r")
qw = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 1)
plt.plot(qw, "b")	
plt.plot([0]*np.size(qw), "k")
plt.title("qw")
plt.ylabel("qw")
plt.xlabel("iteration")
plt.axis([0,np.size(qw),-1,1])



source_1 = open("saved_data/qx.txt", "r")
qx = source_1.readlines()
source_1.close()

plt.figure(51)

plt.subplot(2, 4, 2)
plt.plot(qx, "b")	
plt.plot([0]*np.size(qx), "k")
plt.title("qx")
plt.ylabel("qx")
plt.xlabel("iteration")
plt.axis([0,np.size(qx),-1,1])



source_1 = open("saved_data/qy.txt", "r")
qy = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 3)
plt.plot(qy, "b")	
plt.plot([0]*np.size(qy), "k")
plt.title("qy")
plt.ylabel("qy")
plt.xlabel("iteration")
plt.axis([0,np.size(qy),-1,1])






source_1 = open("saved_data/qz.txt", "r")
qz = source_1.readlines()
source_1.close()


plt.figure(51)

plt.subplot(2, 4, 4)
plt.plot(qz, "b")	
plt.plot([0]*np.size(qz), "k")
plt.title("qz")
plt.ylabel("qz")
plt.xlabel("iteration")
plt.axis([0,np.size(qz),-1,1])
#############################Real quaternions plot##############################








#############################axis_curr_rot##############################
source_1 = open("saved_data/axis_curr_rot_0.txt", "r")
axis_curr_rot_0 = source_1.readlines()
source_1.close()


plt.figure(52)

plt.subplot(2, 4, 1)
plt.plot(axis_curr_rot_0, "b")	
plt.plot([0]*np.size(axis_curr_rot_0), "k")
plt.title("axis_curr_rot_0")
plt.ylabel("axis_curr_rot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_curr_rot_0),-1,1])



source_1 = open("saved_data/axis_curr_rot_1.txt", "r")
axis_curr_rot_1 = source_1.readlines()
source_1.close()

plt.figure(52)

plt.subplot(2, 4, 2)
plt.plot(axis_curr_rot_1, "b")	
plt.plot([0]*np.size(axis_curr_rot_1), "k")
plt.title("axis_curr_rot_1")
plt.ylabel("axis_curr_rot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_curr_rot_1),-1,1])



source_1 = open("saved_data/axis_curr_rot_2.txt", "r")
axis_curr_rot_2 = source_1.readlines()
source_1.close()


plt.figure(52)

plt.subplot(2, 4, 3)
plt.plot(axis_curr_rot_2, "b")	
plt.plot([0]*np.size(axis_curr_rot_2), "k")
plt.title("axis_curr_rot_2")
plt.ylabel("axis_curr_rot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_curr_rot_2),-1,1])
#############################axis_curr_rot##############################


#############################axis_7_to_des_rot##############################
source_1 = open("saved_data/axis_7_to_des_rot_0.txt", "r")
axis_7_to_des_rot_0 = source_1.readlines()
source_1.close()


plt.figure(52)

plt.subplot(2, 4, 1)
plt.plot(axis_7_to_des_rot_0, "r")	
plt.plot([0]*np.size(axis_7_to_des_rot_0), "k")
plt.title("axis_7_to_des_rot_0")
plt.ylabel("axis_7_to_des_rot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_7_to_des_rot_0),-1,1])



source_1 = open("saved_data/axis_7_to_des_rot_1.txt", "r")
axis_7_to_des_rot_1 = source_1.readlines()
source_1.close()

plt.figure(52)

plt.subplot(2, 4, 2)
plt.plot(axis_7_to_des_rot_1, "r")	
plt.plot([0]*np.size(axis_7_to_des_rot_1), "k")
plt.title("axis_7_to_des_rot_1")
plt.ylabel("axis_7_to_des_rot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_7_to_des_rot_1),-1,1])



source_1 = open("saved_data/axis_7_to_des_rot_2.txt", "r")
axis_7_to_des_rot_2 = source_1.readlines()
source_1.close()


plt.figure(52)

plt.subplot(2, 4, 3)
plt.plot(axis_7_to_des_rot_2, "r")	
plt.plot([0]*np.size(axis_7_to_des_rot_2), "k")
plt.title("axis_7_to_des_rot_2")
plt.ylabel("axis_7_to_des_rot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(axis_7_to_des_rot_2),-1,1])
#############################axis_7_to_des_rot##############################






















#############################s_dot##############################
source = open("saved_data/s_dot_alpha.txt", "r")
s_dot_alpha = source.readlines()
source.close()

source.close()

plt.figure(53)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_alpha, "b")	
plt.plot([0]*np.size(s_dot_alpha), "k")
plt.title("s_dot_alpha")
plt.ylabel("s_dot_alpha")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_alpha),-10, 10])






source = open("saved_data/s_dot_beta.txt", "r")
s_dot_beta = source.readlines()
source.close()

source.close()

plt.figure(53)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_beta, "b")	
plt.plot([0]*np.size(s_dot_beta), "k")
plt.title("s_dot_beta")
plt.ylabel("s_dot_beta")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_beta),-10, 10])






source = open("saved_data/s_dot_gamma.txt", "r")
s_dot_gamma = source.readlines()
source.close()

source.close()

plt.figure(53)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_gamma, "b")	
plt.plot([0]*np.size(s_dot_gamma), "k")
plt.title("s_dot_gamma")
plt.ylabel("s_dot_gamma")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_gamma),-10, 10])
#############################s_dot##############################













#############################s_dot_dot##############################
source = open("saved_data/s_dot_dot_alpha.txt", "r")
s_dot_dot_alpha = source.readlines()
source.close()

source.close()

plt.figure(54)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_dot_alpha, "b")	
plt.plot([0]*np.size(s_dot_dot_alpha), "k")
plt.title("s_dot_dot_alpha")
plt.ylabel("s_dot_dot_alpha")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_alpha),-10, 10])






source = open("saved_data/s_dot_dot_beta.txt", "r")
s_dot_dot_beta = source.readlines()
source.close()

source.close()

plt.figure(54)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_dot_beta, "b")	
plt.plot([0]*np.size(s_dot_dot_beta), "k")
plt.title("s_dot_dot_beta")
plt.ylabel("s_dot_dot_beta")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_beta),-10, 10])






source = open("saved_data/s_dot_dot_gamma.txt", "r")
s_dot_dot_gamma = source.readlines()
source.close()

source.close()

plt.figure(54)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_dot_gamma, "b")	
plt.plot([0]*np.size(s_dot_dot_gamma), "k")
plt.title("s_dot_dot_gamma")
plt.ylabel("s_dot_dot_gamma")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_gamma),-10, 10])
#############################s_dot_dot##############################










#############################s_dot_dot_dot##############################
source = open("saved_data/s_dot_dot_dot_alpha.txt", "r")
s_dot_dot_dot_alpha = source.readlines()
source.close()

source.close()

plt.figure(55)
plt.subplot(2, 2, 1)
	
plt.plot(s_dot_dot_dot_alpha, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_alpha), "k")
plt.title("s_dot_dot_dot_alpha")
plt.ylabel("s_dot_dot_dot_alpha")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_alpha),-10, 10])






source = open("saved_data/s_dot_dot_dot_beta.txt", "r")
s_dot_dot_dot_beta = source.readlines()
source.close()

source.close()

plt.figure(55)
plt.subplot(2, 2, 2)
	
plt.plot(s_dot_dot_dot_beta, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_beta), "k")
plt.title("s_dot_dot_dot_beta")
plt.ylabel("s_dot_dot_dot_beta")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_beta),-10, 10])






source = open("saved_data/s_dot_dot_dot_gamma.txt", "r")
s_dot_dot_dot_gamma = source.readlines()
source.close()

source.close()

plt.figure(55)
plt.subplot(2, 2, 3)
	
plt.plot(s_dot_dot_dot_gamma, "b")	
plt.plot([0]*np.size(s_dot_dot_dot_gamma), "k")
plt.title("s_dot_dot_dot_gamma")
plt.ylabel("s_dot_dot_dot_gamma")
plt.xlabel("iteration")
plt.axis([0,np.size(s_dot_dot_dot_gamma),-10, 10])
#############################s_dot_dot_dot##############################












#############################T_x##############################
source = open("saved_data/T_x.txt", "r")
T_x = source.readlines()
source.close()

source.close()

plt.figure(56)
plt.subplot(2, 2, 1)
	
plt.plot(T_x, "b")	
plt.plot([0]*np.size(T_x), "k")
plt.title("T_x")
plt.ylabel("T_x")
plt.xlabel("iteration")
plt.axis([0,np.size(T_x),-10, 10])






source = open("saved_data/T_y.txt", "r")
T_y = source.readlines()
source.close()

source.close()

plt.figure(56)
plt.subplot(2, 2, 2)
	
plt.plot(T_y, "b")	
plt.plot([0]*np.size(T_y), "k")
plt.title("T_y")
plt.ylabel("T_y")
plt.xlabel("iteration")
plt.axis([0,np.size(T_y),-10, 10])






source = open("saved_data/T_z.txt", "r")
T_z = source.readlines()
source.close()

source.close()

plt.figure(56)
plt.subplot(2, 2, 3)
	
plt.plot(T_z, "b")	
plt.plot([0]*np.size(T_z), "k")
plt.title("T_z")
plt.ylabel("T_z")
plt.xlabel("iteration")
plt.axis([0,np.size(T_z),-10, 10])
#############################T_x##############################









#############################t_2_x##############################
source = open("saved_data/t_2_x.txt", "r")
t_2_x = source.readlines()
source.close()

source.close()

plt.figure(57)
plt.subplot(2, 2, 1)
	
plt.plot(t_2_x, "b")	
plt.plot([0]*np.size(t_2_x), "k")
plt.title("t_2_x")
plt.ylabel("t_2_x")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_x),-10, 10])






source = open("saved_data/t_2_y.txt", "r")
t_2_y = source.readlines()
source.close()

source.close()

plt.figure(57)
plt.subplot(2, 2, 2)
	
plt.plot(t_2_y, "b")	
plt.plot([0]*np.size(t_2_y), "k")
plt.title("t_2_y")
plt.ylabel("t_2_y")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_y),-10, 10])






source = open("saved_data/t_2_z.txt", "r")
t_2_z = source.readlines()
source.close()

source.close()

plt.figure(57)
plt.subplot(2, 2, 3)
	
plt.plot(t_2_z, "b")	
plt.plot([0]*np.size(t_2_z), "k")
plt.title("t_2_z")
plt.ylabel("t_2_z")
plt.xlabel("iteration")
plt.axis([0,np.size(t_2_z),-10, 10])
#############################t_2_x##############################





#############################status##############################
source = open("saved_data/status.txt", "r")
status = source.readlines()
source.close()

plt.figure(60)

	
plt.plot(status, "b")	
plt.plot([0]*np.size(status), "k")
plt.title("status")
plt.ylabel("status")
plt.xlabel("iteration")
plt.axis([0,np.size(status),0, 15])
#############################status##############################

#############################PSD##############################
source = open("saved_data/PSD.txt", "r")
PSD = source.readlines()
source.close()

plt.figure(61)

	
plt.plot(PSD, "b")	
plt.plot([0]*np.size(PSD), "k")
plt.title("PSD")
plt.ylabel("PSD")
plt.xlabel("iteration")
plt.axis([0,np.size(PSD),0, 15])
#############################PSD##############################



#############################Lambda##############################
source = open("saved_data/lambda_0.txt", "r")
lambda_0 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 1)
	
plt.plot(lambda_0, "b")	
plt.plot([0]*np.size(lambda_0), "k")
plt.title("lambda_0")
plt.ylabel("lambda_0")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_0),-5, 5])




source = open("saved_data/lambda_1.txt", "r")
lambda_1 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 2)
	
plt.plot(lambda_1, "b")	
plt.plot([0]*np.size(lambda_1), "k")
plt.title("lambda_1")
plt.ylabel("lambda_1")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_1),-5, 5])




source = open("saved_data/lambda_2.txt", "r")
lambda_2 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 3)
	
plt.plot(lambda_2, "b")	
plt.plot([0]*np.size(lambda_2), "k")
plt.title("lambda_2")
plt.ylabel("lambda_2")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_2),-5, 5])





source = open("saved_data/lambda_3.txt", "r")
lambda_3 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 4)
	
plt.plot(lambda_3, "b")	
plt.plot([0]*np.size(lambda_3), "k")
plt.title("lambda_3")
plt.ylabel("lambda_3")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_3),-5, 5])





source = open("saved_data/lambda_4.txt", "r")
lambda_4 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 5)
	
plt.plot(lambda_4, "b")	
plt.plot([0]*np.size(lambda_4), "k")
plt.title("lambda_4")
plt.ylabel("lambda_4")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_4),-5, 5])





source = open("saved_data/lambda_5.txt", "r")
lambda_5 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 6)
	
plt.plot(lambda_5, "b")	
plt.plot([0]*np.size(lambda_5), "k")
plt.title("lambda_5")
plt.ylabel("lambda_5")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_5),-5, 5])





source = open("saved_data/lambda_6.txt", "r")
lambda_6 = source.readlines()
source.close()

plt.figure(62)
plt.subplot(2, 4, 7)
	
plt.plot(lambda_6, "b")	
plt.plot([0]*np.size(lambda_6), "k")
plt.title("lambda_6")
plt.ylabel("lambda_6")
plt.xlabel("iteration")
plt.axis([0,np.size(lambda_6),-5, 5])

#############################Lambda##############################



#############################Distance plot##############################
source = open("saved_data/Dist_07_nrst_ob.txt", "r")
Dist_07_nrst_ob = source.readlines()
source.close()

plt.figure(63)

plt.plot(Dist_07_nrst_ob)	
plt.plot([0]*np.size(Dist_07_nrst_ob), "k")
plt.title("Dist_07_nrst_ob")
plt.ylabel("Dist_07_nrst_ob")
plt.xlabel("iteration")
plt.axis([0,np.size(Dist_07_nrst_ob),-0.06,0.4])
#############################Distance plot##############################




#############################Energy plot222222222##############################
#source = open("saved_data/E_7.txt", "r")
#E_7 = source.readlines()
#source.close()

#source = open("saved_data/E_7_max.txt", "r")
#E_7_max = source.readlines()
#source.close()

#plt.figure(64)

#plt.plot(E_7[2:np.size(E_7)],'b' , linewidth=1.0, label = 'E_7')	
#plt.plot(E_7_max[2:np.size(E_7)], 'r', linewidth=1.0, label = 'E_7_max')
#plt.title("E_7")
#plt.ylabel("E_7_max (r), E_7 (b)")
#plt.xlabel("iteration")
#plt.axis([0,np.size(E_7),-0.3,0.3])
#############################Energy plot222222222##############################






#############################Torques plot222222222##############################
source = open("saved_data/tau_0.txt", "r")
tau_0 = source.readlines()
source.close()

source = open("saved_data/tau_0_max.txt", "r")
tau_0_max = source.readlines()
source.close()

source = open("saved_data/tau_0_min.txt", "r")
tau_0_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 1)
plt.plot(tau_0[2:np.size(tau_0)], linewidth=1.0, label = 'tau_0')	
plt.plot(tau_0_max[2:np.size(tau_0)], "r", linewidth=1.0, label = 'tau_0_max' )
plt.plot(tau_0_min[2:np.size(tau_0)], "r", linewidth=1.0, label = 'tau_0_min')	
plt.plot([0]*np.size(tau_0), "k")
plt.title("tau_0")
plt.ylabel("tau_0")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_0),-210,210])



source = open("saved_data/tau_1.txt", "r")
tau_1 = source.readlines()
source.close()

source = open("saved_data/tau_1_max.txt", "r")
tau_1_max = source.readlines()
source.close()

source = open("saved_data/tau_1_min.txt", "r")
tau_1_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 2)
plt.plot(tau_1[2:np.size(tau_1)], linewidth=1.0, label = 'tau_1')	
plt.plot(tau_1_max[2:np.size(tau_1)], "r", linewidth=1.0, label = 'tau_1_max' )
plt.plot(tau_1_min[2:np.size(tau_1)], "r", linewidth=1.0, label = 'tau_1_min')	
plt.plot([0]*np.size(tau_1), "k")
plt.title("tau_1")
plt.ylabel("tau_1")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_1),-210,210])



source = open("saved_data/tau_2.txt", "r")
tau_2 = source.readlines()
source.close()

source = open("saved_data/tau_2_max.txt", "r")
tau_2_max = source.readlines()
source.close()

source = open("saved_data/tau_2_min.txt", "r")
tau_2_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 3)
plt.plot(tau_2[2:np.size(tau_2)], linewidth=1.0, label = 'tau_2')	
plt.plot(tau_2_max[2:np.size(tau_2)], "r", linewidth=1.0, label = 'tau_2_max' )
plt.plot(tau_2_min[2:np.size(tau_2)], "r", linewidth=1.0, label = 'tau_2_min')	
plt.plot([0]*np.size(tau_2), "k")
plt.title("tau_2")
plt.ylabel("tau_2")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_2),-110,110])






source = open("saved_data/tau_3.txt", "r")
tau_3 = source.readlines()
source.close()

source = open("saved_data/tau_3_max.txt", "r")
tau_3_max = source.readlines()
source.close()

source = open("saved_data/tau_3_min.txt", "r")
tau_3_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 4)
plt.plot(tau_3[2:np.size(tau_3)], linewidth=1.0, label = 'tau_3')	
plt.plot(tau_3_max[2:np.size(tau_3)], "r", linewidth=1.0, label = 'tau_3_max' )
plt.plot(tau_3_min[2:np.size(tau_3)], "r", linewidth=1.0, label = 'tau_3_min')	
plt.plot([0]*np.size(tau_3), "k")
plt.title("tau_3")
plt.ylabel("tau_3")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_3),-110,110])



source = open("saved_data/tau_4.txt", "r")
tau_4 = source.readlines()
source.close()

source = open("saved_data/tau_4_max.txt", "r")
tau_4_max = source.readlines()
source.close()

source = open("saved_data/tau_4_min.txt", "r")
tau_4_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 5)
plt.plot(tau_4[2:np.size(tau_4)], linewidth=1.0, label = 'tau_4')	
plt.plot(tau_4_max[2:np.size(tau_4)], "r", linewidth=1.0, label = 'tau_4_max' )
plt.plot(tau_4_min[2:np.size(tau_4)], "r", linewidth=1.0, label = 'tau_4_min')	
plt.plot([0]*np.size(tau_4), "k")
plt.title("tau_4")
plt.ylabel("tau_4")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_4),-110,110])



source = open("saved_data/tau_5.txt", "r")
tau_5 = source.readlines()
source.close()

source = open("saved_data/tau_5_max.txt", "r")
tau_5_max = source.readlines()
source.close()

source = open("saved_data/tau_5_min.txt", "r")
tau_5_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 6)
plt.plot(tau_5[2:np.size(tau_5)], linewidth=1.0, label = 'tau_5')	
plt.plot(tau_5_max[2:np.size(tau_5)], "r", linewidth=1.0, label = 'tau_5_max' )
plt.plot(tau_5_min[2:np.size(tau_5)], "r", linewidth=1.0, label = 'tau_5_min')	
plt.plot([0]*np.size(tau_5), "k")
plt.title("tau_5")
plt.ylabel("tau_5")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_5),-40,40])



source = open("saved_data/tau_6.txt", "r")
tau_6 = source.readlines()
source.close()

source = open("saved_data/tau_6_max.txt", "r")
tau_6_max = source.readlines()
source.close()

source = open("saved_data/tau_6_min.txt", "r")
tau_6_min = source.readlines()
source.close()

plt.figure(67)

plt.subplot(2, 4, 7)
plt.plot(tau_6[2:np.size(tau_6)], linewidth=1.0, label = 'tau_6')	
plt.plot(tau_6_max[2:np.size(tau_6)], "r", linewidth=1.0, label = 'tau_6_max' )
plt.plot(tau_6_min[2:np.size(tau_6)], "r", linewidth=1.0, label = 'tau_6_min')	
plt.plot([0]*np.size(tau_6), "k")
plt.title("tau_6")
plt.ylabel("tau_6")
plt.xlabel("iteration")
plt.axis([0,np.size(tau_6),-40,40])
#############################Torques plot222222222##############################












#############################q_dot plot##############################
source_1 = open("saved_data/q_dot_0.txt", "r")
q_dot_0 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_1.txt", "r")
q_dot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_2.txt", "r")
q_dot_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_3.txt", "r")
q_dot_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_4.txt", "r")
q_dot_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_5.txt", "r")
q_dot_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_6.txt", "r")
q_dot_6 = source_1.readlines()
source_1.close()

plt.figure(68)


plt.plot(q_dot_0)
plt.plot(q_dot_1)
plt.plot(q_dot_2)
plt.plot(q_dot_3)
plt.plot(q_dot_4)
plt.plot(q_dot_5)
plt.plot(q_dot_6)

		
plt.plot([0]*np.size(q_dot_6), "k")
plt.title("q_dot")
plt.ylabel("q_dot")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_6),-3.15,3.15])
#############################q_dot plot##############################







#############################X plot##############################
source = open("saved_data/trajectory_x.txt", "r")
X_x = source.readlines()
source.close()

source = open("saved_data/des_trajectory_x.txt", "r")
des_X_x = source.readlines()
source.close()

plt.figure(69)
plt.subplot(2, 2, 1)
	
ploted_X_x, = plt.plot(X_x, "b")	
ploted_Des_X_x, = plt.plot(des_X_x, "r")
plt.legend([ploted_X_x, ploted_Des_X_x], ['Real X_x', 'Des X_x'])	

plt.plot([0]*np.size(X_x), "k")
plt.ylabel("(m)")
plt.xlabel("iteration")
plt.legend([X_x, des_X_x], ['Real X_x', 'Des X_x'])
plt.axis([0,np.size(X_x),-0.5, 0.65])





source = open("saved_data/trajectory_y.txt", "r")
X_y = source.readlines()
source.close()

source = open("saved_data/des_trajectory_y.txt", "r")
des_X_y = source.readlines()
source.close()

plt.figure(69)
plt.subplot(2, 2, 2)
	
ploted_X_y, = plt.plot(X_y, "b")	
ploted_Des_X_y, = plt.plot(des_X_y, "r")
plt.legend([ploted_X_y, ploted_Des_X_y], ['Real X_y', 'Des X_y'])	

plt.plot([0]*np.size(X_y), "k")
plt.ylabel("(m)")
plt.xlabel("iteration")
plt.legend([X_y, des_X_y], ['Real X_y', 'Des X_y'])
plt.axis([0,np.size(X_y), 0.0, 0.65])




source = open("saved_data/trajectory_z.txt", "r")
X_z = source.readlines()
source.close()

source = open("saved_data/des_trajectory_z.txt", "r")
des_X_z = source.readlines()
source.close()

plt.figure(69)
plt.subplot(2, 2, 3)
	
ploted_X_z, = plt.plot(X_z, "b")
ploted_Des_X_z, = plt.plot(des_X_z, "r")
plt.legend([ploted_X_z, ploted_Des_X_z], ['Real X_z', 'Des X_z'])
	
plt.plot([0]*np.size(X_err_z), "k")
plt.ylabel("(m)")
plt.xlabel("iteration")
plt.axis([0,np.size(X_z), 0.15, 0.75])






source = open("saved_data/X_err.txt", "r")
X_err = source.readlines()
source.close()

plt.figure(69)

plt.subplot(2, 2, 4)
	
plt.plot(X_err, "b")	
plt.plot([0]*np.size(X_err), "k")
plt.ylabel("X_err (m)")
plt.xlabel("iteration")
plt.axis([0,np.size(X_err),0.0, 0.005])
#############################X plot##############################










plt.show()

