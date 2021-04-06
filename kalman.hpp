// Implementation of Kalman Filter in C++11
// This is a streak at learning the concept of Kalman Filtering and advanced c++ concepts
/** So, a dicrete kalman filter is a recursive kalman filter and constructing a class here would help since
it will be required to call the same variables assuming different values again and again**/

#include<Eigen/Dense> //  defines all member functions for the MatrixXd type and related types
#pragma once // avoids redundant calls of the header file in the main code

class KalmanFilter {
public:

	// Constructor
	KalmanFilter(
		double dt,
		const Eigen::MatrixXd& A,
		const Eigen::MatrixXd& C,
		const Eigen::MatrixXd& Q,
		const Eigen::MatrixXd& R,
		const Eigen::MatrixXd& P
		); // Here Eigen is a namespace (like std)

	KalmanFilter();

	// Initialization
	void init();
	void init(double t0, const Eigen::VectorXd& x0); // Function Overloading

	// Update
	void update(const Eigen::VectorXd& y);
	void update(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd& A); // Function Overloading

	Eigen::VectorXd state() {return x_hat;};

	double time() {return t;};

private:

  // Matrices for computation
  Eigen::MatrixXd A, C, Q, R, P, K, P0;

  // System dimensions
  int m, n;

  // Initial and current time
  double t0, t;

  // Discrete time step
  double dt;

  // Is the filter initialized?
  bool initialized;

  // n-size identity
  Eigen::MatrixXd I;

  // Estimated states
  Eigen::VectorXd x_hat, x_hat_new;
};



