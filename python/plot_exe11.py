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









############################q_dot_dot_dot plot##############################
source_1 = open("saved_data/q_dotdotdot_1.txt", "r")
q_dotdotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_max.txt", "r")
q_dotdotdot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_min.txt", "r")
q_dotdotdot_1_min = source_1.readlines()
source_1.close()

plt.figure('q_dot_dot_dot 0')



ploted_q_dotdotdot_1,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1),1),          q_dotdotdot_1,          "b",   linewidth=2.0)
ploted_q_dotdotdot_1_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1_max),1),      q_dotdotdot_1_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_1_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1_min),1),      q_dotdotdot_1_min,      "r--",   linewidth=2.0)
plt.legend([ploted_q_dotdotdot_1, ploted_q_dotdotdot_1_max, ploted_q_dotdotdot_1_min], ['$\dddot{q}_1 (rad/s^3)$', '$\dddot{q_{0_{max}}} (rad/s^3)$', '$\dddot{q_{0_{min}}} (rad/s^3)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_1), -8000, 8000])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot_dot plot##############################





############################q_dot_dot_dot plot##############################
source_1 = open("saved_data/q_dotdotdot_1.txt", "r")
q_dotdotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_max.txt", "r")
q_dotdotdot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdotdot_1_min.txt", "r")
q_dotdotdot_1_min = source_1.readlines()
source_1.close()

plt.figure('q_dot_dot_dot comp 0')



ploted_q_dotdotdot_1,          = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1),1),          q_dotdotdot_1,          "b",   linewidth=2.0)
ploted_q_dotdotdot_1_max,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1_max),1),      q_dotdotdot_1_max,      "r",   linewidth=2.0)
ploted_q_dotdotdot_1_min,      = plt.plot(0.001*np.arange(0,np.size(q_dotdotdot_1_min),1),      q_dotdotdot_1_min,      "r--",   linewidth=2.0)
plt.legend([ploted_q_dotdotdot_1, ploted_q_dotdotdot_1_max, ploted_q_dotdotdot_1_min], ['$\dddot{q}_1 (rad/s^3)$', '$\dddot{q_{0_{max}}} (rad/s^3)$', '$\dddot{q_{0_{min}}} (rad/s^3)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdotdot_1), -2000, 2000])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot_dot plot##############################






############################q_dot_dot plot_comp FINAL DEBUG##############################
source_1 = open("saved_data/q_1.txt", "r")
q_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_1_max.txt", "r")
q_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_1_min.txt", "r")
q_1_min = source_1.readlines()
source_1.close()


plt.figure('q 0')


ploted_q_1,                    = plt.plot(0.001*np.arange(0,np.size(q_1),1),                    q_1,                    "b",   linewidth=2.0)
ploted_q_1_max,                = plt.plot(0.001*np.arange(0,np.size(q_1_max),1),                q_1_max,                "r",   linewidth=2.0)
ploted_q_1_min,                = plt.plot(0.001*np.arange(0,np.size(q_1_min),1),                q_1_min,                "r--",   linewidth=2.0)



plt.legend([ploted_q_1, ploted_q_1_max, ploted_q_1_min], ['$q_1 (rad)$', '$q_{0_{max}} (rad)$', '$q_{0_{min}} (rad)$'])

plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_1), -3.5, 3.5])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp FINAL DEBUG##############################







#############################compatibility q_dot-q_dddot0 plot##############################
source_1 = open("saved_data/q_dot_1.txt", "r")
q_dot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_1_max.txt", "r")
q_dot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dot_1_min.txt", "r")
q_dot_1_min = source_1.readlines()
source_1.close()



plt.figure('q_dot 0')

ploted_q_dot_1,          = plt.plot(0.001*np.arange(0,np.size(q_dot_1),1),          q_dot_1,          "b",   linewidth=2.0)
ploted_q_dot_1_max,      = plt.plot(0.001*np.arange(0,np.size(q_dot_1_max),1),      q_dot_1_max,      "r",   linewidth=2.0)
ploted_q_dot_1_min,      = plt.plot(0.001*np.arange(0,np.size(q_dot_1_min),1),      q_dot_1_min,      "r--",   linewidth=2.0)

plt.legend([ploted_q_dot_1, ploted_q_dot_1_max, ploted_q_dot_1_min], ['$\dot{q}_1 (rad/s)$', '$\dot{q}_{0_{min}} (rad/s)$', '$\dot{q}_{0_{min}} (rad/s)$'])
plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dot_1), -4, 4])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
#############################compatibility q_dot-q_dddot0 plot##############################







############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_1.txt", "r")
q_dotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_max_comp.txt", "r")
q_dotdot_1_max_comp = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_min_comp.txt", "r")
q_dotdot_1_min_comp = source_1.readlines()
source_1.close()



plt.figure('q_dot_dot comp 0')


ploted_q_dotdot_1,                      = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1),1),                      q_dotdot_1,                   "b",   linewidth=2.0)
ploted_q_dotdot_1_max_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1_max_comp),1),             q_dotdot_1_max_comp,          "r",   linewidth=2.0)
ploted_q_dotdot_1_min_comp,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1_min_comp),1),             q_dotdot_1_min_comp,          "r--",   linewidth=2.0)



plt.legend([ploted_q_dotdot_1, ploted_q_dotdot_1_max_comp, ploted_q_dotdot_1_min_comp], ['$\ddot{q}_1 (rad s^2)$', '$\ddot{q}_{0_{max}} (rad s^2)$', '$\ddot{q}_{0_{min}} (rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_1), -100, 100])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################





############################q_dot_dot plot_comp##############################
source_1 = open("saved_data/q_dotdot_1.txt", "r")
q_dotdot_1 = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_max.txt", "r")
q_dotdot_1_max = source_1.readlines()
source_1.close()

source_1 = open("saved_data/q_dotdot_1_min.txt", "r")
q_dotdot_1_min = source_1.readlines()
source_1.close()



plt.figure('q_dot_dot 0')


ploted_q_dotdot_1,                 = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1),1),                 q_dotdot_1,              "b",   linewidth=2.0)
ploted_q_dotdot_1_max,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1_max),1),             q_dotdot_1_max,          "r",   linewidth=2.0)
ploted_q_dotdot_1_min,             = plt.plot(0.001*np.arange(0,np.size(q_dotdot_1_min),1),             q_dotdot_1_min,          "r--",   linewidth=2.0)



plt.legend([ploted_q_dotdot_1, ploted_q_dotdot_1_max, ploted_q_dotdot_1_min], ['$\ddot{q}_1 (rad s^2)$', '$\ddot{q}_{0_{max}} (rad s^2)$', '$\ddot{q}_{0_{min}} (rad s^2)$'])


plt.xlabel("$time (s)$", fontsize=20)
plt.axis([0,0.001*np.size(q_dotdot_1), -1250, 250])
plt.ticklabel_format(useOffset=False)
plt.grid(True)
############################q_dot_dot plot_comp##############################

plt.show()
