#include <Eigen/Lgsm>
#include <Eigen/Geometry> 


Eigen::Matrix<double, 6, 7> ordonate(Eigen::Matrix<double, 6, 7> J_desordonated){
Eigen::Matrix<double, 6, 7> J_ordonated;
Eigen::Matrix<double, 3, 7> J_r_ordonated;

//J_r_ordonated << J_desordonated.block<1,7>(5,0),  J_desordonated.block<1,7>(4,0), J_desordonated.block<1,7>(3,0);
J_ordonated << J_desordonated.block<3,7>(3,0), J_desordonated.block<3,7>(0,0);
//J_ordonated << J_r_ordonated, J_desordonated.block<3,7>(0,0);
return J_ordonated;
}





Eigen::Matrix<double, 6, 7> correct(Eigen::Matrix<double, 6, 7> J_77){
Eigen::Matrix<double, 6, 7> J_77_corrected;


J_77_corrected << -J_77(0, 0), -J_77(0, 1), -J_77(0, 2), -J_77(0, 3), -J_77(0, 4), -J_77(0, 5), -J_77(0, 6),
				  -J_77(1, 0), -J_77(1, 1), -J_77(1, 2), -J_77(1, 3), -J_77(1, 4), -J_77(1, 5), -J_77(1, 6),
				   J_77(2, 0),  J_77(2, 1),  J_77(2, 2),  J_77(2, 3),  J_77(2, 4),  J_77(2, 5),  J_77(2, 6),
				   
				   J_77(3, 0),  J_77(3, 1),  J_77(3, 2),  J_77(3, 3),  J_77(3, 4),  J_77(3, 5),  J_77(3, 6),
				   J_77(4, 0),  J_77(4, 1),  J_77(4, 2),  J_77(4, 3),  J_77(4, 4),  J_77(4, 5),  J_77(4, 6),
				   J_77(5, 0),  J_77(5, 1),  J_77(5, 2),  J_77(5, 3),  J_77(5, 4),  J_77(5, 5),  J_77(5, 6);


return J_77_corrected;
}





Eigen::Matrix<double, 6, 7> derive(Eigen::Matrix<double, 6, 7> J, Eigen::Matrix<double, 6, 7> J_previous, double time_step){
Eigen::Matrix<double, 6, 7> J_derived; //Jacobienne dérivée

for(int i=0; i < 6; i++){
   for(int j=0; j < 7; j++){
   J_derived(i, j) = (J(i, j) - J_previous(i, j))/time_step;
   }
}
return J_derived;
}
