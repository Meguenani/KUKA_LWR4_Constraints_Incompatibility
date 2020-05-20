import sys
import os
import inspect
import math
import numpy as np
import xdefw
import rtt_interface
import kukacommon
import xde_world_manager as xwm

#-------------------------------------------------------------------------------
#
# Create a new Task for the controller parameters.
#
#-------------------------------------------------------------------------------

class Parameters(xdefw.rtt.Task):
  
    def SetVnetGlobalParameters():
        global kuka
        kuka = ''


    def __init__(self, taskName):
        super(Parameters, self).__init__(rtt_interface.PyTaskFactory.CreateTask(taskName))


        # create output ports
        self.kp_out     = self.addCreateOutputPort("kp_out",     "double")
        self.kd_out     = self.addCreateOutputPort("kd_out",     "double")
        self.d_safe_out = self.addCreateOutputPort("d_safe_out", "double")
        self.d_max_out  = self.addCreateOutputPort("d_max_out",  "double")
        self.E_safe_out = self.addCreateOutputPort("E_safe_out", "double")

        self.X_des_x_out = self.addCreateOutputPort("X_des_x_out", "double")
        self.X_des_y_out = self.addCreateOutputPort("X_des_y_out",  "double")
        self.X_des_z_out = self.addCreateOutputPort("X_des_z_out", "double")
        self.tau_0_sensor_out = self.addCreateOutputPort("tau_0_sensor_out",     "double")

      

    def startHook(self):
        pass
  
    def stopHook(self):
        pass
  
    def updateHook(self):

################PARAMETRES################

         kp = 1000.0
	 kd = 70
        #kp = 550.0
	#kd = 50
	#kp = 140.0
	#kd = 35
	 d_safe  = 0.11
	 d_max   = 0.19
	 E_safe  = 0.01

	 X_des_x = 0.5
	 X_des_y = 0.5
	 X_des_z = 0.5
         tau_sensor   = kuka.getDesiredJointTorques()
         tau_sensor_0 = tau_sensor[0, 0]
         #print tau_sensor_0
################PARAMETRES################

       	 self.kp_out.write(kp)
         self.kd_out.write(kd)
         self.d_safe_out.write(d_safe)
         self.d_max_out.write(d_max)
         self.E_safe_out.write(E_safe)

         self.X_des_x_out.write(X_des_x)
         self.X_des_y_out.write(X_des_y)
         self.X_des_z_out.write(X_des_z)
         self.tau_0_sensor_out.write(tau_sensor_0)
#-------------------------------------------------------------------------------
