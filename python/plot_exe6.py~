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


plt.ylabel("$(N.m)$", fontsize=20)
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(tau_0), -200, 200])
plt.grid(True)
#############################tau plot##############################











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
plt.plot(q_dotdot_0, "c", linewidth=2.0)
plt.plot(q_dotdot_0_max, "r", linewidth=2.0)		
plt.plot(q_dotdot_0_min, "m")	
plt.plot([0]*np.size(q_dotdot_0), "k")
plt.title("q_dotdot_0")
plt.ylabel("q_dotdot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_0),-30,30])



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
plt.plot(q_dotdot_1, "c", linewidth=2.0)	
plt.plot(q_dotdot_1_max, "r", linewidth=2.0)
plt.plot(q_dotdot_1_min, "m")
plt.plot([0]*np.size(q_dotdot_1), "k")
plt.title("q_dotdot_1")
plt.ylabel("q_dotdot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_1),-30,30])



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
plt.plot(q_dotdot_2, "c", linewidth=2.0)
plt.plot(q_dotdot_2_max, "r", linewidth=2.0)	
plt.plot(q_dotdot_2_min, "m")	
plt.plot([0]*np.size(q_dotdot_2), "k")
plt.title("q_dotdot_2")
plt.ylabel("q_dotdot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_2),-30,30])






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
plt.plot(q_dotdot_3, "c", linewidth=2.0)
plt.plot(q_dotdot_3_max, "r", linewidth=2.0)	
plt.plot(q_dotdot_3_min, "m")	
plt.plot([0]*np.size(q_dotdot_3), "k")
plt.title("q_dotdot_3")
plt.ylabel("q_dotdot_3")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_3),-30,30])



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
plt.plot(q_dotdot_4, "c", linewidth=2.0)
plt.plot(q_dotdot_4_max, "r", linewidth=2.0)	
plt.plot(q_dotdot_4_min, "m")
plt.plot([0]*np.size(q_dotdot_4), "k")
plt.title("q_dotdot_4")
plt.ylabel("q_dotdot_4")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_4),-30,30])



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
plt.plot(q_dotdot_5, "c", linewidth=2.0)	
plt.plot(q_dotdot_5_max, "r", linewidth=2.0)	
plt.plot(q_dotdot_5_min, "m")	
plt.plot([0]*np.size(q_dotdot_5), "k")
plt.title("q_dotdot_5")
plt.ylabel("q_dotdot_5")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_5),-30,30])



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
plt.plot(q_dotdot_6, "c", linewidth=2.0)
plt.plot(q_dotdot_6_max, "r", linewidth=2.0)	
plt.plot(q_dotdot_6_min, "m")		
plt.plot([0]*np.size(q_dotdot_6), "k")
plt.title("q_dotdot_6")
plt.ylabel("q_dotdot_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_6),-30,30])
#############################q_dot_dot plot##############################







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


plt.figure(14)

plt.subplot(2, 4, 1)
plt.plot(q_dotdot_0, "c", linewidth=2.0)
plt.plot(q_dotdot_0_max_comp, "r", linewidth=2.0)		
plt.plot(q_dotdot_0_min_comp, "r--", linewidth=2.0)
plt.plot(q_dotdot_bounds_max_optimized_0, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_0, "m--", linewidth=2.0)	
plt.plot([0]*np.size(q_dotdot_0), "k")
plt.title("q_dotdot_0_comp")
plt.ylabel("q_dotdot_0_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_0),-60,60])



source_1 = open("saved_data/q_dotdot_1.txt", "r")
q_dotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_max_comp.txt", "r")
q_dotdot_1_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_min_comp.txt", "r")
q_dotdot_1_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_1.txt", "r")
q_dotdot_bounds_max_optimized_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_1.txt", "r")
q_dotdot_bounds_min_optimized_1 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 2)
plt.plot(q_dotdot_1, "c", linewidth=2.0)	
plt.plot(q_dotdot_1_max_comp, "r", linewidth=2.0)
plt.plot(q_dotdot_1_min_comp, "r--", linewidth=2.0)
plt.plot(q_dotdot_bounds_max_optimized_1, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_1, "m--", linewidth=2.0)
plt.plot([0]*np.size(q_dotdot_1), "k")
plt.title("q_dotdot_1_comp")
plt.ylabel("q_dotdot_1_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_1),-60,60])



source_1 = open("saved_data/q_dotdot_2.txt", "r")
q_dotdot_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_2_max_comp.txt", "r")
q_dotdot_2_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_2_min_comp.txt", "r")
q_dotdot_2_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_2.txt", "r")
q_dotdot_bounds_max_optimized_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_2.txt", "r")
q_dotdot_bounds_min_optimized_2 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 3)
plt.plot(q_dotdot_2, "c", linewidth=2.0)
plt.plot(q_dotdot_2_max_comp, "r", linewidth=2.0)	
plt.plot(q_dotdot_2_min_comp, "r--", linewidth=2.0)
plt.plot(q_dotdot_bounds_max_optimized_2, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_2, "m--", linewidth=2.0)	
plt.plot([0]*np.size(q_dotdot_2), "k")
plt.title("q_dotdot_2_comp")
plt.ylabel("q_dotdot_2_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_2),-60,60])






source_1 = open("saved_data/q_dotdot_3.txt", "r")
q_dotdot_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_3_max_comp.txt", "r")
q_dotdot_3_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_3_min_comp.txt", "r")
q_dotdot_3_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_3.txt", "r")
q_dotdot_bounds_max_optimized_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_3.txt", "r")
q_dotdot_bounds_min_optimized_3 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 4)
plt.plot(q_dotdot_3, "c", linewidth=2.0)
plt.plot(q_dotdot_3_max_comp, "r", linewidth=2.0)	
plt.plot(q_dotdot_3_min_comp, "r--", linewidth=2.0)
plt.plot(q_dotdot_bounds_max_optimized_3, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_3, "m--", linewidth=2.0)	
plt.plot([0]*np.size(q_dotdot_3), "k")
plt.title("q_dotdot_3_comp")
plt.ylabel("q_dotdot_3_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_3),-60,60])



source_1 = open("saved_data/q_dotdot_4.txt", "r")
q_dotdot_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_4_max_comp.txt", "r")
q_dotdot_4_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_4_min_comp.txt", "r")
q_dotdot_4_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_4.txt", "r")
q_dotdot_bounds_max_optimized_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_4.txt", "r")
q_dotdot_bounds_min_optimized_4 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 5)
plt.plot(q_dotdot_4, "c", linewidth=2.0)
plt.plot(q_dotdot_4_max_comp, "r", linewidth=2.0)	
plt.plot(q_dotdot_4_min_comp, "r--", linewidth=2.0)
plt.plot(q_dotdot_bounds_max_optimized_4, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_4, "m--", linewidth=2.0)
plt.plot([0]*np.size(q_dotdot_4), "k")
plt.title("q_dotdot_4_comp")
plt.ylabel("q_dotdot_4_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_4),-60,60])



source_1 = open("saved_data/q_dotdot_5.txt", "r")
q_dotdot_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_5_max_comp.txt", "r")
q_dotdot_5_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_5_min_comp.txt", "r")
q_dotdot_5_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_5.txt", "r")
q_dotdot_bounds_max_optimized_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_5.txt", "r")
q_dotdot_bounds_min_optimized_5 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 6)
plt.plot(q_dotdot_5, "c", linewidth=2.0)	
plt.plot(q_dotdot_5_max_comp, "r", linewidth=2.0)	
plt.plot(q_dotdot_5_min_comp, "r--", linewidth=2.0)	
plt.plot(q_dotdot_bounds_max_optimized_5, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_5, "m--", linewidth=2.0)
plt.plot([0]*np.size(q_dotdot_5), "k")
plt.title("q_dotdot_5_comp")
plt.ylabel("q_dotdot_5_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_5),-60,60])



source_1 = open("saved_data/q_dotdot_6.txt", "r")
q_dotdot_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_6_max_comp.txt", "r")
q_dotdot_6_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_6_min_comp.txt", "r")
q_dotdot_6_min_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_max_optimized_6.txt", "r")
q_dotdot_bounds_max_optimized_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_bounds_min_optimized_6.txt", "r")
q_dotdot_bounds_min_optimized_6 = source_1.readlines()
source_1.close()

plt.figure(14)

plt.subplot(2, 4, 7)
plt.plot(q_dotdot_6, "c", linewidth=2.0)
plt.plot(q_dotdot_6_max_comp, "r", linewidth=2.0)	
plt.plot(q_dotdot_6_min_comp, "r--", linewidth=2.0)		
plt.plot(q_dotdot_bounds_max_optimized_6, "m", linewidth=2.0)		
plt.plot(q_dotdot_bounds_min_optimized_6, "m--", linewidth=2.0)
plt.plot([0]*np.size(q_dotdot_6), "k")
plt.title("q_dotdot_6_comp")
plt.ylabel("q_dotdot_6_comp")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdot_6),-60,60])
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


plt.figure(15)

plt.subplot(2, 4, 1)
plt.plot(q_dotdotdot_0, "c", linewidth=2.0)
plt.plot(q_dotdotdot_0_max, "r", linewidth=2.0)		
plt.plot(q_dotdotdot_0_min, "m")	
plt.plot([0]*np.size(q_dotdotdot_0), "k")
plt.title("q_dotdotdot_0")
plt.ylabel("q_dotdotdot_0")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_0),-30,30])



source_1 = open("saved_data/q_dotdotdot_1.txt", "r")
q_dotdotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_max.txt", "r")
q_dotdotdot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_min.txt", "r")
q_dotdotdot_1_min = source_1.readlines()
source_1.close()

plt.figure(15)

plt.subplot(2, 4, 2)
plt.plot(q_dotdotdot_1, "c", linewidth=2.0)	
plt.plot(q_dotdotdot_1_max, "r", linewidth=2.0)
plt.plot(q_dotdotdot_1_min, "m")
plt.plot([0]*np.size(q_dotdotdot_1), "k")
plt.title("q_dotdotdot_1")
plt.ylabel("q_dotdotdot_1")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_1),-30,30])



source_1 = open("saved_data/q_dotdotdot_2.txt", "r")
q_dotdotdot_2 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_2_max.txt", "r")
q_dotdotdot_2_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_2_min.txt", "r")
q_dotdotdot_2_min = source_1.readlines()
source_1.close()

plt.figure(15)

plt.subplot(2, 4, 3)
plt.plot(q_dotdotdot_2, "c", linewidth=2.0)
plt.plot(q_dotdotdot_2_max, "r", linewidth=2.0)	
plt.plot(q_dotdotdot_2_min, "m")	
plt.plot([0]*np.size(q_dotdotdot_2), "k")
plt.title("q_dotdotdot_2")
plt.ylabel("q_dotdotdot_2")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_2),-30,30])






source_1 = open("saved_data/q_dotdotdot_3.txt", "r")
q_dotdotdot_3 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_3_max.txt", "r")
q_dotdotdot_3_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_3_min.txt", "r")
q_dotdotdot_3_min = source_1.readlines()
source_1.close()

plt.figure(15)

plt.subplot(2, 4, 4)
plt.plot(q_dotdotdot_3, "c", linewidth=2.0)
plt.plot(q_dotdotdot_3_max, "r", linewidth=2.0)	
plt.plot(q_dotdotdot_3_min, "m")	
plt.plot([0]*np.size(q_dotdotdot_3), "k")
plt.title("q_dotdotdot_3")
plt.ylabel("q_dotdotdot_3")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_3),-30,30])



source_1 = open("saved_data/q_dotdotdot_4.txt", "r")
q_dotdotdot_4 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_4_max.txt", "r")
q_dotdotdot_4_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_4_min.txt", "r")
q_dotdotdot_4_min = source_1.readlines()
source_1.close()


plt.figure(15)

plt.subplot(2, 4, 5)
plt.plot(q_dotdotdot_4, "c", linewidth=2.0)
plt.plot(q_dotdotdot_4_max, "r", linewidth=2.0)	
plt.plot(q_dotdotdot_4_min, "m")
plt.plot([0]*np.size(q_dotdotdot_4), "k")
plt.title("q_dotdotdot_4")
plt.ylabel("q_dotdotdot_4")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_4),-30,30])



source_1 = open("saved_data/q_dotdotdot_5.txt", "r")
q_dotdotdot_5 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_5_max.txt", "r")
q_dotdotdot_5_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_5_min.txt", "r")
q_dotdotdot_5_min = source_1.readlines()
source_1.close()

plt.figure(15)

plt.subplot(2, 4, 6)
plt.plot(q_dotdotdot_5, "c", linewidth=2.0)	
plt.plot(q_dotdotdot_5_max, "r", linewidth=2.0)	
plt.plot(q_dotdotdot_5_min, "m")	
plt.plot([0]*np.size(q_dotdotdot_5), "k")
plt.title("q_dotdotdot_5")
plt.ylabel("q_dotdotdot_5")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_5),-30,30])



source_1 = open("saved_data/q_dotdotdot_6.txt", "r")
q_dotdotdot_6 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_6_max.txt", "r")
q_dotdotdot_6_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_6_min.txt", "r")
q_dotdotdot_6_min = source_1.readlines()
source_1.close()

plt.figure(15)

plt.subplot(2, 4, 7)
plt.plot(q_dotdotdot_6, "c", linewidth=2.0)
plt.plot(q_dotdotdot_6_max, "r", linewidth=2.0)	
plt.plot(q_dotdotdot_6_min, "m")		
plt.plot([0]*np.size(q_dotdotdot_6), "k")
plt.title("q_dotdotdot_6")
plt.ylabel("q_dotdotdot_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dotdotdot_6),-30,30])
############################q_dot_dot_dot plot##############################





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

plt.figure(16)

plt.subplot(2, 4, 1)
plt.plot(q_0, "b", linewidth=2.0)
plt.plot(q_0_max, "r", linewidth=2.0)		
plt.plot(q_0_min, "r", linewidth=2.0)	
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

plt.figure(16)

plt.subplot(2, 4, 2)
plt.plot(q_1, "b", linewidth=2.0)	
plt.plot(q_1_max, "r", linewidth=2.0)
plt.plot(q_1_min, "r", linewidth=2.0)
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

plt.figure(16)

plt.subplot(2, 4, 3)
plt.plot(q_2, "b", linewidth=2.0)
plt.plot(q_2_max, "r", linewidth=2.0)	
plt.plot(q_2_min, "r", linewidth=2.0)	
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

plt.figure(16)

plt.subplot(2, 4, 4)
plt.plot(q_3, "b", linewidth=2.0)
plt.plot(q_3_max, "r", linewidth=2.0)	
plt.plot(q_3_min, "r", linewidth=2.0)	
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


plt.figure(16)

plt.subplot(2, 4, 5)
plt.plot(q_4, "b", linewidth=2.0)
plt.plot(q_4_max, "r", linewidth=2.0)	
plt.plot(q_4_min, "r", linewidth=2.0)
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

plt.figure(16)

plt.subplot(2, 4, 6)
plt.plot(q_5, "b", linewidth=2.0)	
plt.plot(q_5_max, "r", linewidth=2.0)	
plt.plot(q_5_min, "r", linewidth=2.0)	
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

plt.figure(16)

plt.subplot(2, 4, 7)
plt.plot(q_6, "b", linewidth=2.0)
plt.plot(q_6_max, "r", linewidth=2.0)	
plt.plot(q_6_min, "r", linewidth=2.0)		
plt.plot([0]*np.size(q_6), "k")
plt.title("q_6")
plt.ylabel("q_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_6),-5,5])
#############################q plot##############################






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

plt.figure(17)

plt.subplot(2, 4, 1)
plt.plot(q_dot_0, "b", linewidth=2.0)
plt.plot(q_dot_0_max, "r", linewidth=2.0)		
plt.plot(q_dot_0_min, "r", linewidth=2.0)	
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

plt.figure(17)

plt.subplot(2, 4, 2)
plt.plot(q_dot_1, "b", linewidth=2.0)	
plt.plot(q_dot_1_max, "r", linewidth=2.0)
plt.plot(q_dot_1_min, "r", linewidth=2.0)
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

plt.figure(17)

plt.subplot(2, 4, 3)
plt.plot(q_dot_2, "b", linewidth=2.0)
plt.plot(q_dot_2_max, "r", linewidth=2.0)	
plt.plot(q_dot_2_min, "r", linewidth=2.0)	
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

plt.figure(17)

plt.subplot(2, 4, 4)
plt.plot(q_dot_3, "b", linewidth=2.0)
plt.plot(q_dot_3_max, "r", linewidth=2.0)	
plt.plot(q_dot_3_min, "r", linewidth=2.0)	
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


plt.figure(17)

plt.subplot(2, 4, 5)
plt.plot(q_dot_4, "b", linewidth=2.0)
plt.plot(q_dot_4_max, "r", linewidth=2.0)	
plt.plot(q_dot_4_min, "r", linewidth=2.0)
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

plt.figure(17)

plt.subplot(2, 4, 6)
plt.plot(q_dot_5, "b", linewidth=2.0)	
plt.plot(q_dot_5_max, "r", linewidth=2.0)	
plt.plot(q_dot_5_min, "r", linewidth=2.0)	
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

plt.figure(17)

plt.subplot(2, 4, 7)
plt.plot(q_dot_6, "b", linewidth=2.0)
plt.plot(q_dot_6_max, "r", linewidth=2.0)	
plt.plot(q_dot_6_min, "r", linewidth=2.0)		
plt.plot([0]*np.size(q_dot_6), "k")
plt.title("q_dot_6")
plt.ylabel("q_dot_6")
plt.xlabel("iteration")
plt.axis([0,np.size(q_dot_6),-3.15,3.15])
#############################q_dot plot##############################







############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################
source = open("saved_data/Force_sensor_x.txt", "r")
Force_sensor_x = source.readlines()
source.close()

source = open("saved_data/Ep_real_during_and_before_contact_x.txt", "r")
Ep_real_during_and_before_contact_x = source.readlines()
source.close()


plt.figure(8)

ploted_Force_sensor_x, = plt.plot(0.001*np.arange(0,np.size(Force_sensor_x),1), Force_sensor_x, "r--", linewidth=2.0)
ploted_Ep_real_during_and_before_contact_x, = plt.plot(0.001*np.arange(0,np.size(Ep_real_during_and_before_contact_x),1), Ep_real_during_and_before_contact_x, "b", linewidth=2.0)
plt.legend([ploted_Force_sensor_x, ploted_Ep_real_during_and_before_contact_x], ['$F_x (N)$', '$Ep_{x} (J)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Force_sensor_x), 0, 600])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################








############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################
source = open("saved_data/Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x.txt", "r")
Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x = source.readlines()
source.close()

source = open("saved_data/Ec_7_x.txt", "r")
Ec_7_x = source.readlines()
source.close()


plt.figure(9)

ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, = plt.plot(0.001*np.arange(0,np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x),1), Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, "b--", linewidth=2.0)
ploted_Ec_7_x, = plt.plot(0.001*np.arange(0,np.size(Ec_7_x),1), Ec_7_x, "b", linewidth=2.0)
plt.legend([ploted_Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x, ploted_Ec_7_x], ['$Real E_{c|sum Ep} (J)$', '$E_{c|x} (J)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_Ec_7_x_rcnsrcted_wth_small_Ep_7_x), -0.4, 0.6])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################







############################plot Real_robot_force_estimated_x, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################
source = open("saved_data/Real_robot_force_estimated_x.txt", "r")
Real_robot_force_estimated_x = source.readlines()
source.close()

source = open("saved_data/robot_force_x_nxt_step.txt", "r")
robot_force_x_nxt_step = source.readlines()
source.close()


source = open("saved_data/robot_force_x_nxt_step_limit_max.txt", "r")
robot_force_x_nxt_step_limit_max = source.readlines()
source.close()

source = open("saved_data/robot_force_x_nxt_step_limit_min.txt", "r")
robot_force_x_nxt_step_limit_min = source.readlines()
source.close()

plt.figure(10)

ploted_Real_robot_force_estimated_x, = plt.plot(0.001*np.arange(0,np.size(Real_robot_force_estimated_x),1), Real_robot_force_estimated_x, "b", linewidth=2.0)
ploted_robot_force_x_nxt_step, = plt.plot(0.001*np.arange(0,np.size(robot_force_x_nxt_step),1), robot_force_x_nxt_step, "b--", linewidth=2.0)
ploted_robot_force_x_nxt_step_limit_max, = plt.plot(0.001*np.arange(0,np.size(robot_force_x_nxt_step_limit_max),1), robot_force_x_nxt_step_limit_max, "r", linewidth=2.0)
ploted_robot_force_x_nxt_step_limit_min, = plt.plot(0.001*np.arange(0,np.size(robot_force_x_nxt_step_limit_min),1), robot_force_x_nxt_step_limit_min, "r--", linewidth=2.0)
plt.legend([ploted_Real_robot_force_estimated_x, ploted_robot_force_x_nxt_step, ploted_robot_force_x_nxt_step_limit_max, ploted_robot_force_x_nxt_step_limit_min], ['$End-eff F_{x} (N)$', '$End-eff F_{x|k+1} (N)$', '$End-eff F_{x}^{max} (N)$', '$End-eff F_{x}^{min} (N)$' ])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_robot_force_estimated_x), -5, 5])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################





############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################
source = open("saved_data/Force_sensor_x.txt", "r")
Force_sensor_x = source.readlines()
source.close()



source = open("saved_data/Force_sensor_y.txt", "r")
Force_sensor_y = source.readlines()
source.close()


source = open("saved_data/Force_sensor_z.txt", "r")
Force_sensor_z = source.readlines()
source.close()

plt.figure(11)


ploted_Force_sensor_x, = plt.plot(0.001*np.arange(0,np.size(Force_sensor_x),1), Force_sensor_x, "b", linewidth=2.0)
ploted_Force_sensor_y, = plt.plot(0.001*np.arange(0,np.size(Force_sensor_y),1), Force_sensor_y, "r", linewidth=2.0)
ploted_Force_sensor_z, = plt.plot(0.001*np.arange(0,np.size(Force_sensor_z),1), Force_sensor_z, "g", linewidth=2.0)
plt.legend([ploted_Force_sensor_x, ploted_Force_sensor_y, ploted_Force_sensor_z], ['$F_x (N)$', '$F_y (N)$', '$F_z (N)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Force_sensor_x), 0, 600])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_x##############################






############################plot Real_robot_force_estimated_z, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_z##############################
source = open("saved_data/Real_robot_force_estimated_z.txt", "r")
Real_robot_force_estimated_z = source.readlines()
source.close()

source = open("saved_data/robot_force_z_nxt_step.txt", "r")
robot_force_z_nxt_step = source.readlines()
source.close()


source = open("saved_data/robot_force_z_nxt_step_limit_max.txt", "r")
robot_force_z_nxt_step_limit_max = source.readlines()
source.close()

source = open("saved_data/robot_force_z_nxt_step_limit_min.txt", "r")
robot_force_z_nxt_step_limit_min = source.readlines()
source.close()

plt.figure(12)

ploted_Real_robot_force_estimated_z, = plt.plot(0.001*np.arange(0,np.size(Real_robot_force_estimated_z),1), Real_robot_force_estimated_z, "b", linewidth=2.0)
ploted_robot_force_z_nxt_step, = plt.plot(0.001*np.arange(0,np.size(robot_force_z_nxt_step),1), robot_force_z_nxt_step, "b--", linewidth=2.0)
ploted_robot_force_z_nxt_step_limit_max, = plt.plot(0.001*np.arange(0,np.size(robot_force_z_nxt_step_limit_max),1), robot_force_z_nxt_step_limit_max, "r", linewidth=2.0)
ploted_robot_force_z_nxt_step_limit_min, = plt.plot(0.001*np.arange(0,np.size(robot_force_z_nxt_step_limit_min),1), robot_force_z_nxt_step_limit_min, "r--", linewidth=2.0)
plt.legend([ploted_Real_robot_force_estimated_z, ploted_robot_force_z_nxt_step, ploted_robot_force_z_nxt_step_limit_max, ploted_robot_force_z_nxt_step_limit_min], ['$End-eff F_{z} (N)$', '$End-eff F_{z|k+1} (N)$', '$End-eff F_{z}^{max} (N)$', '$End-eff F_{z}^{min} (N)$' ])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(Real_robot_force_estimated_z), -5, 5])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot nxt_step Ec, nxt_step Ec_rcnstrctd_with_small_Ep, nxt_step Acc_z##############################









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










###################################PLOT n##############################################
###################################PLOT n##############################################
###################################PLOT n##############################################
###################################PLOT n##############################################
#//ACC-POSI
##############################n_neg_acc_posi plot##############################
#source = open("saved_data/n_neg_acc_posi_0.txt", "r")
#n_neg_acc_posi_0 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 1)
#plt.plot(n_neg_acc_posi_0, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_0), "k")
#plt.title("n_neg_acc_posi_0")
#plt.ylabel("n_neg_acc_posi_0")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_0),-100,100])



#source = open("saved_data/n_neg_acc_posi_1.txt", "r")
#n_neg_acc_posi_1 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 2)
#plt.plot(n_neg_acc_posi_1, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_1), "k")
#plt.title("n_neg_acc_posi_1")
#plt.ylabel("n_neg_acc_posi_1")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_1),-100,100])



#source = open("saved_data/n_neg_acc_posi_2.txt", "r")
#n_neg_acc_posi_2 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 3)
#plt.plot(n_neg_acc_posi_2, "k", linewidth=2.0)	
#plt.plot([0]*np.size(n_neg_acc_posi_2), "k")
#plt.title("n_neg_acc_posi_2")
#plt.ylabel("n_neg_acc_posi_2")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_2),-100,100])






#source = open("saved_data/n_neg_acc_posi_3.txt", "r")
#n_neg_acc_posi_3 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 4)
#plt.plot(n_neg_acc_posi_3, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_3), "k")
#plt.title("n_neg_acc_posi_3")
#plt.ylabel("n_neg_acc_posi_3")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_3),-100,100])



#source = open("saved_data/n_neg_acc_posi_4.txt", "r")
#n_neg_acc_posi_4 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 5)
#plt.plot(n_neg_acc_posi_4, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_4), "k")
#plt.title("n_neg_acc_posi_4")
#plt.ylabel("n_neg_acc_posi_4")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_4),-100,100])



#source = open("saved_data/n_neg_acc_posi_5.txt", "r")
#n_neg_acc_posi_5 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 6)
#plt.plot(n_neg_acc_posi_5, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_5), "k")
#plt.title("n_neg_acc_posi_5")
#plt.ylabel("n_neg_acc_posi_5")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_5),-100,100])



#source = open("saved_data/n_neg_acc_posi_6.txt", "r")
#n_neg_acc_posi_6 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 7)
#plt.plot(n_neg_acc_posi_6, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_acc_posi_6), "k")
#plt.title("n_neg_acc_posi_6")
#plt.ylabel("n_neg_acc_posi_6")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_acc_posi_6),-100,100])
##############################n_neg_acc_posi plot##############################

##############################n_pos_acc_posi plot##############################
#source = open("saved_data/n_pos_acc_posi_0.txt", "r")
#n_pos_acc_posi_0 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 1)
#plt.plot(n_pos_acc_posi_0, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_0), "k")
#plt.title("n_pos_acc_posi_0")
#plt.ylabel("n_pos_acc_posi_0")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_0),-100,100])



#source = open("saved_data/n_pos_acc_posi_1.txt", "r")
#n_pos_acc_posi_1 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 2)
#plt.plot(n_pos_acc_posi_1, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_1), "k")
#plt.title("n_pos_acc_posi_1")
#plt.ylabel("n_pos_acc_posi_1")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_1),-100,100])



#source = open("saved_data/n_pos_acc_posi_2.txt", "r")
#n_pos_acc_posi_2 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 3)
#plt.plot(n_pos_acc_posi_2, "k--", linewidth=2.0)	
#plt.plot([0]*np.size(n_pos_acc_posi_2), "k")
#plt.title("n_pos_acc_posi_2")
#plt.ylabel("n_pos_acc_posi_2")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_2),-100,100])






#source = open("saved_data/n_pos_acc_posi_3.txt", "r")
#n_pos_acc_posi_3 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 4)
#plt.plot(n_pos_acc_posi_3, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_3), "k")
#plt.title("n_pos_acc_posi_3")
#plt.ylabel("n_pos_acc_posi_3")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_3),-100,100])



#source = open("saved_data/n_pos_acc_posi_4.txt", "r")
#n_pos_acc_posi_4 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 5)
#plt.plot(n_pos_acc_posi_4, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_4), "k")
#plt.title("n_pos_acc_posi_4")
#plt.ylabel("n_pos_acc_posi_4")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_4),-100,100])



#source = open("saved_data/n_pos_acc_posi_5.txt", "r")
#n_pos_acc_posi_5 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 6)
#plt.plot(n_pos_acc_posi_5, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_5), "k")
#plt.title("n_pos_acc_posi_5")
#plt.ylabel("n_pos_acc_posi_5")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_5),-100,100])



#source = open("saved_data/n_pos_acc_posi_6.txt", "r")
#n_pos_acc_posi_6 = source.readlines()
#source.close()

#plt.figure(16)

#plt.subplot(2, 4, 7)
#plt.plot(n_pos_acc_posi_6, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_acc_posi_6), "k")
#plt.title("n_pos_acc_posi_6")
#plt.ylabel("n_pos_acc_posi_6")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_acc_posi_6),-100,100])
##############################n_pos_acc_posi plot##############################







#//Jerk_Vel
#############################n_neg_jerk_vel plot##############################
#source = open("saved_data/n_neg_jerk_vel_0.txt", "r")
#n_neg_jerk_vel_0 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 1)
#plt.plot(n_neg_jerk_vel_0, "k", linewidth=2.0)			
#plt.plot([0]*np.size(n_neg_jerk_vel_0), "k")
#plt.title("n_neg_jerk_vel_0")
#plt.ylabel("n_neg_jerk_vel_0")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_0),-100,100])



#source = open("saved_data/n_neg_jerk_vel_1.txt", "r")
#n_neg_jerk_vel_1 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 2)
#plt.plot(n_neg_jerk_vel_1, "k", linewidth=2.0)			
#plt.plot([0]*np.size(n_neg_jerk_vel_1), "k")
#plt.title("n_neg_jerk_vel_1")
#plt.ylabel("n_neg_jerk_vel_1")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_1),-100,100])



#source = open("saved_data/n_neg_jerk_vel_2.txt", "r")
#n_neg_jerk_vel_2 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 3)
#plt.plot(n_neg_jerk_vel_2, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_jerk_vel_2), "k")
#plt.title("n_neg_jerk_vel_2")
#plt.ylabel("n_neg_jerk_vel_2")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_2),-100,100])






#source = open("saved_data/n_neg_jerk_vel_3.txt", "r")
#n_neg_jerk_vel_3 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 4)
#plt.plot(n_neg_jerk_vel_3, "k", linewidth=2.0)			
#plt.plot([0]*np.size(n_neg_jerk_vel_3), "k")
#plt.title("n_neg_jerk_vel_3")
#plt.ylabel("n_neg_jerk_vel_3")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_3),-100,100])



#source = open("saved_data/n_neg_jerk_vel_4.txt", "r")
#n_neg_jerk_vel_4 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 5)
#plt.plot(n_neg_jerk_vel_4, "k", linewidth=2.0)			
#plt.plot([0]*np.size(n_neg_jerk_vel_4), "k")
#plt.title("n_neg_jerk_vel_4")
#plt.ylabel("n_neg_jerk_vel_4")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_4),-100,100])



#source = open("saved_data/n_neg_jerk_vel_5.txt", "r")
#n_neg_jerk_vel_5 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 6)
#plt.plot(n_neg_jerk_vel_5, "k", linewidth=2.0)			
#plt.plot([0]*np.size(n_neg_jerk_vel_5), "k")
#plt.title("n_neg_jerk_vel_5")
#plt.ylabel("n_neg_jerk_vel_5")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_5),-100,100])



#source = open("saved_data/n_neg_jerk_vel_6.txt", "r")
#n_neg_jerk_vel_6 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 7)
#plt.plot(n_neg_jerk_vel_6, "k", linewidth=2.0)		
#plt.plot([0]*np.size(n_neg_jerk_vel_6), "k")
#plt.title("n_neg_jerk_vel_6")
#plt.ylabel("n_neg_jerk_vel_6")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_neg_jerk_vel_6),-100,100])
#############################n_neg_jerk_vel plot##############################

#############################n_pos_jerk_vel plot##############################
#source = open("saved_data/n_pos_jerk_vel_0.txt", "r")
#n_pos_jerk_vel_0 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 1)
#plt.plot(n_pos_jerk_vel_0, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_0), "k")
#plt.title("n_pos_jerk_vel_0")
#plt.ylabel("n_pos_jerk_vel_0")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_0),-100,100])



#source = open("saved_data/n_pos_jerk_vel_1.txt", "r")
#n_pos_jerk_vel_1 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 2)
#plt.plot(n_pos_jerk_vel_1, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_1), "k")
#plt.title("n_pos_jerk_vel_1")
#plt.ylabel("n_pos_jerk_vel_1")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_1),-100,100])



#source = open("saved_data/n_pos_jerk_vel_2.txt", "r")
#n_pos_jerk_vel_2 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 3)
#plt.plot(n_pos_jerk_vel_2, "k--", linewidth=2.0)	
#plt.plot([0]*np.size(n_pos_jerk_vel_2), "k")
#plt.title("n_pos_jerk_vel_2")
#plt.ylabel("n_pos_jerk_vel_2")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_2),-100,100])






#source = open("saved_data/n_pos_jerk_vel_3.txt", "r")
#n_pos_jerk_vel_3 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 4)
#plt.plot(n_pos_jerk_vel_3, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_3), "k")
#plt.title("n_pos_jerk_vel_3")
#plt.ylabel("n_pos_jerk_vel_3")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_3),-100,100])



#source = open("saved_data/n_pos_jerk_vel_4.txt", "r")
#n_pos_jerk_vel_4 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 5)
#plt.plot(n_pos_jerk_vel_4, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_4), "k")
#plt.title("n_pos_jerk_vel_4")
#plt.ylabel("n_pos_jerk_vel_4")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_4),-100,100])



#source = open("saved_data/n_pos_jerk_vel_5.txt", "r")
#n_pos_jerk_vel_5 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 6)
#plt.plot(n_pos_jerk_vel_5, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_5), "k")
#plt.title("n_pos_jerk_vel_5")
#plt.ylabel("n_pos_jerk_vel_5")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_5),-100,100])



#source = open("saved_data/n_pos_jerk_vel_6.txt", "r")
#n_pos_jerk_vel_6 = source.readlines()
#source.close()

#plt.figure(17)

#plt.subplot(2, 4, 7)
#plt.plot(n_pos_jerk_vel_6, "k--", linewidth=2.0)		
#plt.plot([0]*np.size(n_pos_jerk_vel_6), "k")
#plt.title("n_pos_jerk_vel_6")
#plt.ylabel("n_pos_jerk_vel_6")
#plt.xlabel("iteration")
#plt.axis([0,np.size(n_pos_jerk_vel_6),-100,100])
#############################n_pos_jerk_vel plot##############################









#############################n_neg_jerk_posi plot##############################
source = open("saved_data/n_neg_jerk_posi_0.txt", "r")
n_neg_jerk_posi_0 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 1)
plt.plot(n_neg_jerk_posi_0)		
plt.plot([0]*np.size(n_neg_jerk_posi_0), "k")
plt.title("n_neg_jerk_posi_0")
plt.ylabel("n_neg_jerk_posi_0")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_0),-100,100])



source = open("saved_data/n_neg_jerk_posi_1.txt", "r")
n_neg_jerk_posi_1 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 2)
plt.plot(n_neg_jerk_posi_1)		
plt.plot([0]*np.size(n_neg_jerk_posi_1), "k")
plt.title("n_neg_jerk_posi_1")
plt.ylabel("n_neg_jerk_posi_1")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_1),-100,100])



source = open("saved_data/n_neg_jerk_posi_2.txt", "r")
n_neg_jerk_posi_2 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 3)
plt.plot(n_neg_jerk_posi_2)	
plt.plot([0]*np.size(n_neg_jerk_posi_2), "k")
plt.title("n_neg_jerk_posi_2")
plt.ylabel("n_neg_jerk_posi_2")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_2),-100,100])






source = open("saved_data/n_neg_jerk_posi_3.txt", "r")
n_neg_jerk_posi_3 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 4)
plt.plot(n_neg_jerk_posi_3)		
plt.plot([0]*np.size(n_neg_jerk_posi_3), "k")
plt.title("n_neg_jerk_posi_3")
plt.ylabel("n_neg_jerk_posi_3")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_3),-100,100])



source = open("saved_data/n_neg_jerk_posi_4.txt", "r")
n_neg_jerk_posi_4 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 5)
plt.plot(n_neg_jerk_posi_4)		
plt.plot([0]*np.size(n_neg_jerk_posi_4), "k")
plt.title("n_neg_jerk_posi_4")
plt.ylabel("n_neg_jerk_posi_4")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_4),-100,100])



source = open("saved_data/n_neg_jerk_posi_5.txt", "r")
n_neg_jerk_posi_5 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 6)
plt.plot(n_neg_jerk_posi_5)		
plt.plot([0]*np.size(n_neg_jerk_posi_5), "k")
plt.title("n_neg_jerk_posi_5")
plt.ylabel("n_neg_jerk_posi_5")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_5),-100,100])



source = open("saved_data/n_neg_jerk_posi_6.txt", "r")
n_neg_jerk_posi_6 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 7)
plt.plot(n_neg_jerk_posi_6)		
plt.plot([0]*np.size(n_neg_jerk_posi_6), "k")
plt.title("n_neg_jerk_posi_6")
plt.ylabel("n_neg_jerk_posi_6")
plt.xlabel("iteration")
plt.axis([0,np.size(n_neg_jerk_posi_6),-100,100])
#############################n_neg_jerk_posi plot##############################

#############################n_pos_jerk_posi plot##############################
source = open("saved_data/n_pos_jerk_posi_0.txt", "r")
n_pos_jerk_posi_0 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 1)
plt.plot(n_pos_jerk_posi_0)		
plt.plot([0]*np.size(n_pos_jerk_posi_0), "k")
plt.title("n_pos_jerk_posi_0")
plt.ylabel("n_pos_jerk_posi_0")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_0),-100,100])



source = open("saved_data/n_pos_jerk_posi_1.txt", "r")
n_pos_jerk_posi_1 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 2)
plt.plot(n_pos_jerk_posi_1)		
plt.plot([0]*np.size(n_pos_jerk_posi_1), "k")
plt.title("n_pos_jerk_posi_1")
plt.ylabel("n_pos_jerk_posi_1")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_1),-100,100])



source = open("saved_data/n_pos_jerk_posi_2.txt", "r")
n_pos_jerk_posi_2 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 3)
plt.plot(n_pos_jerk_posi_2)	
plt.plot([0]*np.size(n_pos_jerk_posi_2), "k")
plt.title("n_pos_jerk_posi_2")
plt.ylabel("n_pos_jerk_posi_2")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_2),-100,100])






source = open("saved_data/n_pos_jerk_posi_3.txt", "r")
n_pos_jerk_posi_3 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 4)
plt.plot(n_pos_jerk_posi_3)		
plt.plot([0]*np.size(n_pos_jerk_posi_3), "k")
plt.title("n_pos_jerk_posi_3")
plt.ylabel("n_pos_jerk_posi_3")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_3),-100,100])



source = open("saved_data/n_pos_jerk_posi_4.txt", "r")
n_pos_jerk_posi_4 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 5)
plt.plot(n_pos_jerk_posi_4)		
plt.plot([0]*np.size(n_pos_jerk_posi_4), "k")
plt.title("n_pos_jerk_posi_4")
plt.ylabel("n_pos_jerk_posi_4")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_4),-100,100])



source = open("saved_data/n_pos_jerk_posi_5.txt", "r")
n_pos_jerk_posi_5 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 6)
plt.plot(n_pos_jerk_posi_5)		
plt.plot([0]*np.size(n_pos_jerk_posi_5), "k")
plt.title("n_pos_jerk_posi_5")
plt.ylabel("n_pos_jerk_posi_5")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_5),-100,100])



source = open("saved_data/n_pos_jerk_posi_6.txt", "r")
n_pos_jerk_posi_6 = source.readlines()
source.close()

plt.figure(14)

plt.subplot(2, 4, 7)
plt.plot(n_pos_jerk_posi_6)		
plt.plot([0]*np.size(n_pos_jerk_posi_6), "k")
plt.title("n_pos_jerk_posi_6")
plt.ylabel("n_pos_jerk_posi_6")
plt.xlabel("iteration")
plt.axis([0,np.size(n_pos_jerk_posi_6),-100,100])
#############################n_pos_jerk_posi plot##############################

###################################PLOT n##############################################
###################################PLOT n##############################################
###################################PLOT n##############################################
###################################PLOT n##############################################








############################plot status_q_ddot_opt_min, status_q_ddot_opt_max##############################
source = open("saved_data/status_q_ddot_opt_min.txt", "r")
status_q_ddot_opt_min = source.readlines()
source.close()

source = open("saved_data/status_q_ddot_opt_max.txt", "r")
status_q_ddot_opt_max = source.readlines()
source.close()


plt.figure(17)

ploted_status_q_ddot_opt_min, = plt.plot(0.001*np.arange(0,np.size(status_q_ddot_opt_min),1), status_q_ddot_opt_min, "b", linewidth=2.0)
ploted_status_q_ddot_opt_max, = plt.plot(0.001*np.arange(0,np.size(status_q_ddot_opt_max),1), status_q_ddot_opt_max, "g", linewidth=2.0)
plt.legend([ploted_status_q_ddot_opt_min, ploted_status_q_ddot_opt_max], ['$status_q_ddot_opt_min (st)$', '$status_q_ddot_opt_min (st)$'])

	
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(status_q_ddot_opt_min), 0, 600])
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.grid(True)
############################plot status_q_ddot_opt_min, status_q_ddot_opt_max##############################
plt.show()
