import xde_world_manager as xwm
import xde_resources as xr
import xde_robot_loader as xrl
import xde_spacemouse as spacemouse
import xdefw.interactive
shell = xdefw.interactive.shell()
import deploy.deployer as ddeployer
import lgsm
import xde_resources as xr
import xde_robot_loader as xrl
import xde.desc.physic
import physicshelper
from numpy import pi
import lgsm
import os
import inspect


################################################################################
import desc.graphic
import desc.physic
import desc.core
import desc.scene
import desc.collision
import desc.simple.scene
import desc.simple.physic
import desc.simple.graphic
import desc.simple.collision





def add_kuka_with_meshes(damping = 0, kuka_offset=0.001):
    current_path = os.path.dirname(os.path.abspath(inspect.getfile( inspect.currentframe())))
    urdfworld = xrl.createWorldFromUrdfFile(xr.kuka, "kuka", [0.0,0.0, 0.0, 1, 0, 0, 0], True, damping, 0.005) #, "material.concrete")  DEFINE THE POSITION AND ORIENTATION OF ROBOT IN WORLD  //Damping Ori 0.005
    #urdfworld = xrl.createWorldFromUrdfFile(xr.kuka, "kuka", [0.0,0.0, 0.0, 0, 0, 0, 1], True, damping, 0.005) #, "material.concrete")  DEFINE THE POSITION AND ORIENTATION OF ROBOT IN WORLD 
    return urdfworld



def addGround(world):
    current_path = os.path.dirname(os.path.abspath(inspect.getfile( inspect.currentframe())))
    ground_world = xrl.createWorldFromUrdfFile("resources/urdf/ground.xml", "ground", [0.0,0.0,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475], False, 0.1, 0.01)# , "material.concrete")
    phy_ground_world = desc.simple.scene.parseColladaFile("resources/dae/ground_phy_50mm.dae", append_label_library=".phyground", append_label_graph_meshes = ".ground_50mm")
    desc.simple.graphic.addGraphicalTree(world, ground_world, node_name="ground")
    ground_node = desc.core.findInTree(ground_world.scene.graphical_scene.root_node, "node-ground")
    comp_ground = desc.simple.collision.addCompositeMesh(world, phy_ground_world, composite_name="ground.comp", offset=0.00, clean_meshes=False, ignore_library_conflicts=False)
    #desc.collision.copyFromGraphicalTree(comp_ground.root_node, ground_node)
    desc.simple.physic.addRigidBody(world, "ground", mass=100000000, contact_material="material.concrete")
    #ground_position = lgsm.Displacementd(-0.2,2.0,0.256, 0.7071067811865476, 0.7071067811865476, 0, 0) #(0.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475)  //Ligne pour table horizontale
    ground_position = lgsm.Displacementd(0.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475) #(0.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475) //Pour mur vertical
    desc.simple.physic.addFixedJoint(world, "ground.joint", "ground", ground_position)
    #Binding graph, phy and coll object
    ground_graph_node      = desc.core.findInTree(world.scene.graphical_scene.root_node, "ground")
    ground_phy_node        = desc.physic.findInPhysicalScene(world.scene.physical_scene, "ground")
    ground_graph_node.name = "ground" # it is suitable to have the same name for both graphics and physics.
    ground_phy_node.rigid_body.composite_name="ground.comp"



def addSphere(world):
    sphere_world = xrl.createWorldFromUrdfFile("resources/urdf/sphere.xml", "sphere", [0,0,0.1, 1, 0, 0, 0], False, 0.1, 0.01)# , "material.concrete")
    phy_sphere_world = desc.simple.scene.parseColladaFile("resources/dae/sphere.dae", append_label_library=".physphere", append_label_graph_meshes = ".sphere")
    desc.simple.graphic.addGraphicalTree(world, sphere_world, node_name="sphere")
    shpere_node = desc.core.findInTree(sphere_world.scene.graphical_scene.root_node, "node-sphere")		
    comp_sphere = desc.simple.collision.addCompositeMesh(world, phy_sphere_world, composite_name="sphere.comp", offset=0.00, clean_meshes=False, ignore_library_conflicts=False)
    #desc.collision.copyFromGraphicalTree(comp_sphere.root_node, sphere_node)    
    desc.simple.physic.addRigidBody(world, "sphere", mass=1, contact_material="material.concrete")
    sphere_position = lgsm.Displacementd()
    sphere_position.setTranslation(lgsm.vector(0.7,5.3,5.3))
    desc.simple.physic.addFixedJoint(world, "sphere.joint", "sphere", sphere_position)
    #Binding graph, phy and coll object
    sphere_graph_node      = desc.core.findInTree(world.scene.graphical_scene.root_node, "sphere")
    sphere_phy_node        = desc.physic.findInPhysicalScene(world.scene.physical_scene, "sphere")
    sphere_graph_node.name = "sphere" # it is suitable to have the same name for both graphics and physics.
    sphere_phy_node.rigid_body.composite_name="sphere.comp"



def addObst_1(world):
    obst_1_world = xrl.createWorldFromUrdfFile("resources/urdf/env11.xml", "obst_1", [0.0,0.0,0.0, 1, 0, 0, 0], True, 0.1, 0.01)
    phy_obst_1_world = desc.simple.scene.parseColladaFile("resources/dae/env11.dae", append_label_library=".phyobst_1", append_label_graph_meshes = ".obst_1")
    desc.simple.graphic.addGraphicalTree(world, obst_1_world, node_name="obst_1")
    shpere_node = desc.core.findInTree(obst_1_world.scene.graphical_scene.root_node, "node-obst_1")		
    comp_obst_1 = desc.simple.collision.addCompositeMesh(world, phy_obst_1_world, composite_name="obst_1.comp", offset=0.00, clean_meshes=False, ignore_library_conflicts=False)
    #desc.collision.copyFromGraphicalTree(comp_obst_1.root_node, obst_1_node)    
    desc.simple.physic.addRigidBody(world, "obst_1", mass=0.00001, contact_material="material.concrete")
    #obst_1_position = lgsm.Displacementd(0.60,0.0,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475)   posi ori paper Ec
    #obst_1_position = lgsm.Displacementd(-0.2,2.0,0.256, 0.7071067811865476, 0.7071067811865476, 0, 0)   #(0.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475) //Cette ligne a ete utilise pour table horizontale
    obst_1_position = lgsm.Displacementd(5.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475)   #(0.1,0.3,0.0, 0.7071067811865476, 0, 0, 0.7071067811865475) //Cette ligne a ete utilise pour table horizontale
    #obst_1_position.setTranslation(lgsm.vector(0.9,0.0,0.0))
    desc.simple.physic.addFreeJoint(world, "obst_1.joint", "obst_1", obst_1_position)
    #Binding graph, phy and coll object
    obst_1_graph_node      = desc.core.findInTree(world.scene.graphical_scene.root_node, "obst_1")
    obst_1_phy_node        = desc.physic.findInPhysicalScene(world.scene.physical_scene, "obst_1")
    obst_1_graph_node.name = "obst_1" # it is suitable to have the same name for both graphics and physics.
    obst_1_phy_node.rigid_body.composite_name="obst_1.comp"


def addObst_2(world):
    obst_2_world = xrl.createWorldFromUrdfFile("resources/urdf/env12.xml", "obst_2", [0.6,-0.2,0.0, 1, 0, 0, 0], True, 0.1, 0.01)
    phy_obst_2_world = desc.simple.scene.parseColladaFile("resources/dae/env12.dae", append_label_library=".phyobst_2", append_label_graph_meshes = ".obst_2")

    desc.simple.graphic.addGraphicalTree(world, obst_2_world, node_name="obst_2")
    shpere_node = desc.core.findInTree(obst_2_world.scene.graphical_scene.root_node, "node-obst_2")		
    comp_obst_2 = desc.simple.collision.addCompositeMesh(world, phy_obst_2_world, composite_name="obst_2.comp", offset=0.00, clean_meshes=False, ignore_library_conflicts=False)
    #desc.collision.copyFromGraphicalTree(comp_obst_2.root_node, obst_2_node)    
    desc.simple.physic.addRigidBody(world, "obst_2", mass=1, contact_material="material.concrete")
    obst_2_position = lgsm.Displacementd()
    #obst_2_position.setTranslation(lgsm.vector(0.6,-0.2,0.0))
    obst_2_position.setTranslation(lgsm.vector(2.6,3.2,0.0))
    desc.simple.physic.addFixedJoint(world, "obst_2.joint", "obst_2", obst_2_position)
    #Binding graph, phy and coll object
    obst_2_graph_node      = desc.core.findInTree(world.scene.graphical_scene.root_node, "obst_2")
    obst_2_phy_node        = desc.physic.findInPhysicalScene(world.scene.physical_scene, "obst_2")
    obst_2_graph_node.name = "obst_2" # it is suitable to have the same name for both graphics and physics.
    obst_2_phy_node.rigid_body.composite_name="obst_2.comp"



def addContactLaws(world, friction_coeff=.4):
    world.scene.physical_scene.contact_materials.extend(["material.concrete", "material.metal"])
    cl = world.scene.physical_scene.contact_laws.add()
    cl.material_i = "material.metal"
    cl.material_j = "material.concrete"
    cl.law = cl.COULOMB
    cl.friction = friction_coeff



def addCollision_with_ground(world):
    cp = world.scene.physical_scene.collision_pairs.add()
    cp.body_i = "ground"
    cp.mechanism_j = "kuka"
    cp.queries.add(type=1, enabled=True)

def addCollision_with_sphere(world):
    cp = world.scene.physical_scene.collision_pairs.add()
    cp.body_i = "sphere"
    cp.mechanism_j = "kuka"
    cp.queries.add(type=1, enabled=True)

def addCollision_with_obst_1(world):
    cp = world.scene.physical_scene.collision_pairs.add()
    cp.body_i = "obst_1"
    cp.mechanism_j = "kuka"
    cp.queries.add(type=1, enabled=True)

def addCollision_with_obst_2(world):
    cp = world.scene.physical_scene.collision_pairs.add()
    cp.body_i = "obst_2"
    cp.mechanism_j = "kuka"
    cp.queries.add(type=1, enabled=True)

