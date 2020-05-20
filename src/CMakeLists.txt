include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(
    ${OROCOS-RTT_INCLUDE_DIR}
    ${PC_XDECORE_INCLUDE_DIRS}
    ${PC_EIGEN_INCLUDE_DIRS}
    ${PC_OCL_INCLUDE_DIRS}
    ${PC_OCL_DEPLOY_INCLUDE_DIRS}

    ${PC_ORC_FRAMEWORK_INCLUDE_DIRS}
    ${PC_OROCOS_KDL_INCLUDE_DIRS}
    /home/anis/libs/ReflexxesTypeII/include/ 
    /home/anis/libs/boost_1_56_0/boost/
    /home/anis/libs/boost_1_56_0/boost/chrono/
    /home/anis/libs/boost_1_56_0/boost/date_time/posix_time/
    /usr/local/include/Geant4
)


LINK_DIRECTORIES(
	${PC_XDECORE_LIBRARY_DIRS}
	${PC_OCL_LIBRARY_DIRS}
	${PC_OCL_DEPLOY_LIBRARY_DIRS}
	${LD_LIBRARY_PATH}

        ${PC_ORC_FRAMEWORK_LIBRARY_DIRS}
        ${PC_OROCOS_KDL_LIBRARY_DIRS}


	/home/anis/libs/CoinIpopt/build/lib
	/usr/local/lib
	/usr/lib/gcc/x86_64-linux-gnu/4.6
	/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../x86_64-linux-gnu
	/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../../lib
	/lib/../lib 
	/usr/lib/../lib
	/usr/lib/gcc/x86_64-linux-gnu/4.6/../../..
        /home/anis/libs/gurobi563/linux64/lib
        /home/anis/libs/ReflexxesTypeII/Linux/x64/release/lib/shared
	/home/anis/libs/boost_1_56_0/bin.v2/libs

)

orocos_component(XDESimpleController
	XDESimpleController.cpp
	Compute_distance.cpp
        Compute_energy.cpp
        Compute_prj_velocity.cpp
	Compute_vectors.cpp
        save_data_in_txt.cpp
        QP.cpp
	Interpolation.cpp
	Absolute.cpp
	Maximum.cpp
        Jacobian_operations.cpp
        G4_P4_ApproxEqual.cpp
        G4_P4_Solver.cpp
        G4_P3_Solver.cpp
        round_up.cpp
        Minimum.cpp
        choose_int_root_n.cpp
        choose_int_root_n_P3.cpp
        compute_n.cpp
        optimize_q_ddot.cpp
        choose_q_ddot_final_bounds.cpp
        comp_constr_generator.cpp
	)

target_link_libraries(
	XDESimpleController
        ipopt lapack dl coinmumps blas pthread gfortran m gcc_s quadmath coinmetis gurobi_c++ gurobi56 gurobi_g++4.1 gurobi_g++4.2 GurobiJni56 ReflexxesTypeII  boost_chrono boost_coroutine G4global
        ${Orocos-RTT_LIBRARIES}
	${PC_OCL_LIBRARIES}
	${PC_OCL_DEPLOY_LIBRARIES}
        ${PC_XDECORE_LIBRARIES}
	${LD_LIBRARY_PATH}
	${PC_OROCOS_KDL_LIBRARIES}

)


