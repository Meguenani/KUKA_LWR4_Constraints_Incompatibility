""" This module abstract the instantiation and configuration of the spacemouse.
"""
import xdefw.rtt
import rtt_interface
import deploy.deployer as ddeployer
import xdefw.interactive
import xde_spacemouse as spacemouse
import lgsm


class SpaceMouse(xdefw.rtt.Task):

	def __init__(self, task):
		#Input Port	
		self.posi_in = self.addCreateInputPort("posi_in", "Displacementd", False)        
		self.sTask.addPort(self.posi_in)
		self.sTask = xdeTasksUtils.synchronizer.createTask()
		xdeTasksUtils.synchronizer.startTask()



        def startHook(self):
		pass

	def stopHook(self):
		pass

	def updateHook(self):
			
		if (self.sTask.ready()) == True: 				# garde pour valeur la premiere valeur arrivee sur chaque port. Peut etre depassee au moment de larrivee de la derniere
			self.data = self.sTask.getData()
			posi_in = self.data["posi_in"]



def createTask():
	task = rtt_interface.PyTaskFactory.CreateTask("3Dmouse_read")
	controller = SafeController(task)
	setProxy(posi_read)
	return posi_read

def setProxy(_posi_read):
	global posi_read
	posi_read = _posi_read


def startTask(_timestep):
	controller.s.setPeriod(_timestep)
	controller.s.start()

