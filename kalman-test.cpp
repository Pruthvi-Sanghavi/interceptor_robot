// Testing a 2d projectile motion which then will be extended to 3d

#include <iostream> // Standard input output library in c++
#include <vector> // Header for vector
#include <Eigen/Dense> // The linear algebra library which allows matrix definition
#include "kalman.hpp" // Header which contains the kalman filter class and all the variables

int main(int argc, char*argv[]) {

	int n = 3; // number of states
	int m = 1; // number of measurements

	double dt = 1.0/30; // Time steps

	// Define all the matrix containers
	Eigen::MatrixXd A(n, n); // System Dynamics matrix
	Eigen::MatrixXd C(m, n); // Output Matrix
	Eigen::MatrixXd Q(n, n); // Process noise covariance
	Eigen::MatrixXd R(m, m); // Measurement noise covariance
	Eigen::MatrixXd P(n, n); // Estimate Error Covariance

	A << 1, dt, 0, 0, 1, dt, 0, 0, 1;
	C << 1, 0, 0;

	Q << .05, .05, .0, .05, .05, .0, .0, .0, .0;
	R << 5;
	P << .1, .1, .1, .1, 10000, 10, .1, 10, 100;

	std::cout << "A: \n" << A << std::endl;
  	std::cout << "C: \n" << C << std::endl;
  	std::cout << "Q: \n" << Q << std::endl;
  	std::cout << "R: \n" << R << std::endl;
  	std::cout << "P: \n" << P << std::endl;

  	KalmanFilter kf(dt, A, C, Q, R, P);

  	std::vector<double> measurements = {
      1.04202710058, 1.10726790452, 1.2913511148, 1.48485250951, 1.72825901034,
      1.74216489744, 2.11672039768, 2.14529225112, 2.16029641405, 2.21269371128,
      2.57709350237, 2.6682215744, 2.51641839428, 2.76034056782, 2.88131780617,
      2.88373786518, 2.9448468727, 2.82866600131, 3.0006601946, 3.12920591669,
      2.858361783, 2.83808170354, 2.68975330958, 2.66533185589, 2.81613499531,
      2.81003612051, 2.88321849354, 2.69789264832, 2.4342229249, 2.23464791825,
      2.30278776224, 2.02069770395, 1.94393985809, 1.82498398739, 1.52526230354,
      1.86967808173, 1.18073207847, 1.10729605087, 0.916168349913, 0.678547664519,
      0.562381751596, 0.355468474885, -0.155607486619, -0.287198661013, -0.602973173813
  };

  // Best guess of initial states
  Eigen::VectorXd x0(n);
  double t = 0;
  x0 << measurements[0], 0, -9.81;
  kf.init(t, x0);

  // Feed measurements into filter, output estimated states

  Eigen::VectorXd y(m);
  std::cout << "t = " << t << ", " << "x_hat[0]: " << kf.state().transpose() << std::endl;
  for(int i = 0; i < measurements.size(); i++) {
    t += dt;
    y << measurements[i];
    kf.update(y);
    std::cout << "t = " << t << ", " << "y[" << i << "] = " << y.transpose()
        << ", x_hat[" << i << "] = " << kf.state().transpose() << std::endl;
  }

  return 0;
}

