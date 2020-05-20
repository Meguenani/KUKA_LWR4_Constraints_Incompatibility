#-------------------------------------------------------------------------------
#
# Load libraries and setup agents
#
#-------------------------------------------------------------------------------
import os
import numpy as np
import matplotlib.pyplot as plt			#Pour les graphs
import math

import xde_world_manager as xwm
import xde_resources as xr
import xde_robot_loader as xrl
import xdefw.interactive
shell = xdefw.interactive.shell()
import deploy.deployer as ddeployer
import lgsm
import xde_resources as xr
import xde_robot_loader as xrl
import xde.desc.physic
import physicshelper
import desc.simple.scene
import os
import inspect
import desc.scene
import xde_spacemouse as spacemouse
import obj_move

import sys
import os
import inspect

cpath = os.path.dirname(os.path.abspath(inspect.getfile( inspect.currentframe()))) + "/"
sys.path.append(cpath)
cpath = os.path.dirname(os.path.abspath(inspect.getfile( inspect.currentframe()))) + "/../common"   #So we can look in this folder
sys.path.append(cpath)

import common
import lgsm
import time
import parameters

wm = xwm.WorldManager()
wm.createAllAgents(0.001, dt=0.001)

#Remove data files
dirPath = "saved_data"
fileList = os.listdir(dirPath)
for fileName in fileList:
 os.remove(dirPath+"/"+fileName)


#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------     
# Create the robot with the desc module.
#
# The goal is to make a general description of the robot.
# The robot is then create in the physical scene with
# the deserializeWorld method.
import kukacommon

world = kukacommon.add_kuka_with_meshes(damping = 0.0002)   #Ori damping = 0.001
kukacommon.addGround(world)
kukacommon.addSphere(world)
kukacommon.addObst_1(world)
kukacommon.addObst_2(world)
kukacommon.addContactLaws(world)
kukacommon.addCollision_with_ground(world)
kukacommon.addCollision_with_sphere(world)
kukacommon.addCollision_with_obst_1(world)
kukacommon.addCollision_with_obst_2(world)

wm.addWorld(world)
#wm.graph_scn.SceneInterface.setNodeMaterial('ground', 'xde/ConcretGround', True) # Pour changer la couleur du mannequin


###############################   Controller & Dynamic model    ###############################
# dsimi.rtt : convert RTT::TaskContext * into a python object /
control = xdefw.rtt.Task(ddeployer.load("control", "XDE_SimpleController", "XDESimpleController-gnulinux", "", libdir="/home/anis/ros_workspace/kuka_controller/lib/orocos/gnulinux"))

kukaModel = xde.desc.physic.physic_pb2.MultiBodyModel()
kukaModel.kinematic_tree.CopyFrom(world.scene.physical_scene.nodes[0])
kukaModel.meshes.extend(world.library.meshes)
kukaModel.mechanism.CopyFrom(world.scene.physical_scene.mechanisms[0])
kukaModel.composites.extend(world.scene.physical_scene.collision_scene.meshes)
model = physicshelper.createDynamicModel(kukaModel)

#model.setJointPositions(lgsm.vectord(-0.5, -0.3, -0.4, -0.4, -0.2, -0.2, -0.2))
#model.setJointPositions(lgsm.vectord(0.05, 0.68, 0.68, 0.68, 0.68, 0.68, 0.68))
#model.setJointPositions(lgsm.vectord(3.5, 0.68, -0.5, 0.68, 0.68, 0.68, 0.68))

model.setJointPositions(lgsm.vectord(0.5, 0.68, 0.0, 1.5, 0,    0.0,   0.0))         #Position articulaire de depart du robot
#model.setJointPositions(lgsm.vectord(0, 3.14159265359/2, 0, 0, 0,    0.0,   0.0)) 
#model.setJointPositions(lgsm.vectord(0, 0, 0, 0, 0,    0.0,   0.0))
                                #max 2.97 2.09  2.97 2.09 2.97  2.09 2.9

#model.setJointPositions(lgsm.vectord(0, 0.0, 0.0, 0, 0, 0.0, -1.5))
#0, 0.0, 0.0, 3.14159265/2, 0, 0.0, 0.0

#model.setJointPositions(lgsm.vectord(0.105, 0.7755, 1.11976, 1.23, 0.02420, 1.1028, 0.3))

parameters.kuka = wm.phy.s.GVM.Robot("kuka")
wm.addMarkers(world, ["kuka.01"], thin_markers=False)

#wm.graph_scn.SceneInterface.setNodeMaterial('kuka.01', 'xde/BlueTransparentSet', True) # Pour changer la couleur du mannequin
#wm.graph_scn.SceneInterface.setNodeMaterial('kuka.02', 'xde/RedTransparentSet', True) # Pour changer la couleur du mannequin
#wm.graph_scn.SceneInterface.setNodeMaterial('kuka.03', 'xde/GreenTransparentSet', True) # Pour changer la couleur du mannequin

parameters.kuka.lockSegmentJoints1(1)
parameters.kuka.lockSegmentJoints1(2)
parameters.kuka.lockSegmentJoints1(3)
parameters.kuka.lockSegmentJoints1(4)
parameters.kuka.lockSegmentJoints1(5)
parameters.kuka.lockSegmentJoints1(6)
parameters.kuka.lockSegmentJoints1(7)

#kuka.setJointPositions(lgsm.vectord(-0.5, -0.3, -0.4, -0.4, -0.2, -0.2, -0.2))
#kuka.setJointPositions(lgsm.vectord(0.05, 0.68, 0.68, 0.68, 0.68, 0.68, 0.68))
#kuka.setJointPositions(lgsm.vectord(3.5, 0.68, -0.5, 0.68, 0.68, 0.68, 0.68))

parameters.kuka.setJointPositions(lgsm.vectord(0.5, 0.68, 0.0, 1.5, 0, 0.0, 0.0))                  #Position articulaire de depart du robot
#kuka.setJointPositions(lgsm.vectord(0, 3.14159265359/2, 0, 0, 0, 0.0, 0.0))
#kuka.setJointPositions(lgsm.vectord(0, 0, 0, 0, 0, 0.0, 0.0))

#kuka.setJointPositions(lgsm.vectord(0, 0.0, 0.0, 0, 0, 0.0, -1.5))
#0, 0.0, 0.0, 3.14159265/2, 0, 0.0, 0.0

#kuka.setJointPositions(lgsm.vectord(0.105, 0.7755, 1.11976, 1.23, 0.02420, 1.1028, 0.3))

#model.setFreeFlyerPosition(lgsm.Displacement(0.5, 0.5, 0.5, 1, 0, 0, 0))
control.s.setDynModel(str(model.this.__long__()))
###############################################################################################












################################### Create clock #########################
clock = wm.clock      #Clock permet de stynchroniser le controleur 
###########################################################################
print "clock.s.getPeriod() : "
print clock.s.getPeriod()





########################################  Phy_Connectors  ########################################
#create connectors to get robot kuka state 'kuka_q', 'kuka_qdot', 'kuka_Hroot', 'kuka_Troot', 'kuka_H'
robot_name = "kuka"
wm.phy.s.Connectors.IConnectorRobotJointTorque.new("ict"+robot_name, robot_name+"_", robot_name) #Input port is the torque 
wm.phy.s.Connectors.OConnectorRobotState.new("ocpos"+robot_name, robot_name+"_", robot_name) #Output is the kuka robot state
wm.icsync.addEvent("kuka_tau")
####################################################################################################



#wm.graph_scn.MarkersInterface.addMarker("Target", False)
#d = lgsm.Displacementd(1,0,0.5,-0.0157,0,-0.9998,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("Target",d)


#wm.graph_scn.MarkersInterface.addMarker("1", False)
#d = lgsm.Displacementd(-0.4, 0.4, 0.2,-0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("1",d)

#wm.graph_scn.MarkersInterface.addMarker("2", False)
#d = lgsm.Displacementd(-0.4, 0.4, 0.6,-0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("2",d)

#wm.graph_scn.MarkersInterface.addMarker("3", False)
#d = lgsm.Displacementd(0.3, 0.4, 0.6,-0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("3",d)

#wm.graph_scn.MarkersInterface.addMarker("4", False)
#d = lgsm.Displacementd(0.3, 0.3, 0.2,-0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("4",d)


#wm.graph_scn.MarkersInterface.addMarker("start", False)
#d = lgsm.Displacementd(0.562939, 0.304145, 0.355963, -0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("start",d)


#wm.graph_scn.MarkersInterface.addMarker("end", False)
#d = lgsm.Displacementd(-0.41641, 0.113913, 0.200128, -0.9998,0,-0.0157,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("end",d)




#wm.graph_scn.MarkersInterface.addMarker("World", False)
#d = lgsm.Displacementd(0.639864, -0.2, 0.355999, 1,0,0,0)
#d = lgsm.Displacementd(0, 0, 0, 1,0,0,0)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("World",d)




#wm.graph_scn.MarkersInterface.addMarker("Initial", False)
#d = lgsm.Displacementd(0.639864, -0.003, 0.355999, -0.460175, -0.088515, -0.882197, -0.0461715)
#d = lgsm.Displacementd(0.639864, -0.003, 0.355999,    -0.460175, 0.0397945, -0.882197, -0.0915593)
#d = lgsm.Displacementd(-0.330539, 0.268275, 1.05205, -0.706716, 0.0685121, 0.41762, 0.566964)
#wm.graph_scn.MarkersInterface.setMarker6DPosition("Initial",d)


#################################### Plug controller input  ##################################### 
near_pt_07_ob1 = wm.creategetLocalDisplacement_07_ob1()
near_pt_07_ob1.get_nearest_Pair("kuka.07","obst_1")
near_pt_07_ob1.getPort("nr_pt_07_ob1_ai_Port_out").connectTo(control.getPort("nr_pt_07_ob1_ai"))
near_pt_07_ob1.getPort("nr_pt_07_ob1_aj_Port_out").connectTo(control.getPort("nr_pt_07_ob1_aj"))


#clock.getPort("ticks").connectTo(control.getPort("clock"))
wm.phy.getPort(robot_name+"_q").connectTo(control.getPort("q"))
wm.phy.getPort(robot_name+"_qdot").connectTo(control.getPort("qdot"))
wm.phy.getPort(robot_name+"_Troot").connectTo(control.getPort("t"))
wm.phy.getPort(robot_name+"_Hroot").connectTo(control.getPort("d"))
control.getPort("tau").connectTo(wm.phy.getPort(robot_name+"_tau"))     #D'ici on place les commandes en couple dans le world physique 
##################################################################################################





######################################## Connection for information about contacts and visualization ########################################
occ_2 = wm.phy.s.Connectors.OConnectorContactBody.new("occ_2", "contacts")
occ_2.addInteraction("kuka.04", "ground")
occ_2.addInteraction("kuka.05", "ground")
occ_2.addInteraction("kuka.06", "ground")
occ_2.addInteraction("kuka.07", "ground")

occ_2.addInteraction("kuka.04", "sphere")
occ_2.addInteraction("kuka.05", "sphere")
occ_2.addInteraction("kuka.06", "sphere")
occ_2.addInteraction("kuka.07", "sphere")

occ_2.addInteraction("kuka.04", "obst_1")
occ_2.addInteraction("kuka.05", "obst_1")
occ_2.addInteraction("kuka.06", "obst_1")
occ_2.addInteraction("kuka.07", "obst_1")

occ_2.addInteraction("kuka.04", "obst_2")
occ_2.addInteraction("kuka.05", "obst_2")
occ_2.addInteraction("kuka.06", "obst_2")
occ_2.addInteraction("kuka.07", "obst_2")

icc_2 = wm.graph.s.Connectors.IConnectorContacts.new("icc_2", "contacts", "mainScene")
icc_2.setMaxProximity(.05)
icc_2.setGlyphScale(2)

wm.graph.getPort("contacts").connectTo(wm.phy.getPort("contacts"))     #Connection of contact ports phy-graph



#op = wm.phy.getPort("contacts")
#ip = op.antiClone()
#ip.connectTo(op)
#(a,b) = ip.read()
################################################################################################################################################






########################## Conmpute mini_distanceswith ports ########################
near_pt_07_ob1.s.start()
#####################################################################################






########################## Conmpute mini_distances ###############################

gdv = wm.createGlobalDistanceVisualizer()
#gdv.addCompositePair("kuka.07", "ground")
#gdv.addCompositePair("kuka.06", "ground")
#gdv.addCompositePair("kuka.05", "ground")
#gdv.addCompositePair("kuka.04", "ground")
#gdv.addCompositePair("kuka.03", "ground")
#gdv.addCompositePair("kuka.02", "ground")
gdv.s.start()

nr_pt_07_ob1  = wm.collision.getCompositePairLocalDisplacement("kuka.07", "obst_1")
##################################################################################



#################################### Plug controller parameters ####################
controller_parameters = parameters.Parameters("control_param") 

controller_parameters.getPort("kp_out").connectTo(control.getPort("kp"))
controller_parameters.getPort("kd_out").connectTo(control.getPort("kd"))
controller_parameters.getPort("d_safe_out").connectTo(control.getPort("d_safe"))
controller_parameters.getPort("d_max_out").connectTo(control.getPort("d_max"))
controller_parameters.getPort("E_safe_out").connectTo(control.getPort("E_safe"))    

controller_parameters.getPort("X_des_x_out").connectTo(control.getPort("X_des_x"))
controller_parameters.getPort("X_des_y_out").connectTo(control.getPort("X_des_y"))
controller_parameters.getPort("X_des_z_out").connectTo(control.getPort("X_des_z"))  

controller_parameters.getPort("tau_0_sensor_out").connectTo(control.getPort("tau_0_sensor"))
####################################################################################






## Run agents
#wm.startAgents()
##controller_parameters.s.setPeriod(0.001)
##controller_parameters.s.start()
#control.s.setPeriod(0.001)
#control.s.start()
#wm.phy.s.agent.triggerUpdate()


# Run agents
wm.startAgents()
wm.phy.s.agent.triggerUpdate()
controller_parameters.s.setPeriod(0.001)
controller_parameters.s.start()
control.s.setPeriod(0.001)
control.s.start()

#ObjController.s.start()


parameters.kuka.unlockSegmentJoints1(1)
parameters.kuka.unlockSegmentJoints1(2)
parameters.kuka.unlockSegmentJoints1(3)
parameters.kuka.unlockSegmentJoints1(4)
parameters.kuka.unlockSegmentJoints1(5)
parameters.kuka.unlockSegmentJoints1(6)
parameters.kuka.unlockSegmentJoints1(7)


#sm = spacemouse.createTask("smi", 0.001, wm.phy, wm.graph, "obst_1", pdc_enabled=False) #Ce qu'il faut utiliser normalement
#sm_obj = obj_move.createTask("smi_obj", 0.001, wm.phy, wm.graph, "obst_1", pdc_enabled=False)
#sm = spacemouse.createTask("smi", 0.001, wm.phy, wm.graph, "obst_1", pdc_enabled=True, body_name="kuka.07")
#sm = spacemouse.createTask("smi", 0.001, wm.phy, wm.graph, "obst_1", pdc_enabled=True, body_name="ground")


sm = spacemouse.createTask("smi", 0.001, wm.phy, wm.graph, "ground", pdc_enabled=True, body_name="obst_1", PR=00000000000000000000000000000, PT=0.00000000000000000000000000, DR=0.0, DT=0.0) #Capteur d'effort #Mettre 0.1 partout pour debeug
#################################### Plug Force Sensor data ##########################
sm.getPort("force_sensor_pos_out").connectTo(control.getPort("displacementd_obst_1"))
######################################################################################
sm.s.start()


#sm_obj.s.start()

kuka.enableGravity(True)
print "To enable gravity, type: kuka.enableGravity(True)"


##### Interactive shell
import xdefw.interactive
shell = xdefw.interactive.shell_console()
shell()


# on obtient:
# ai
# aj
# gap
# ni
# nj
# normalForce




