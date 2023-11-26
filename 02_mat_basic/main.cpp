#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

static void help() {
  cout 
    << "\n-------------------------------------------------------------------------------------------" << endl
    << "This program shows how to create matrices (cv::Mat) in OpenCV and its serial out capabilities" << endl
    << "That is, cv::Mat M(...); M.create and cout << M."                                              << endl
    << "Show how out can be formartted to OpenCV, python, numpy, csv and C styles."                    << endl
    << "Usage: "                                                                                       << endl
    << "./mat_basic"                                                                                   << endl
    << "---------------------------------------------------------------------------------------------" << endl
    << endl;
}

int main(int, char **) {
  help();
  // create by using the constructor
  // ! [constructor]
  Mat M(2, 2, CV_8SC3, Scalar(0, 0, 255));
  cout << "M = " << endl << "" << M << endl << endl;
  //![constructor]

  // create by using the create function()
  //! [create]
  M.create(4, 4, CV_8UC(2));
  cout << "M = " << endl << "" << M << endl << endl;

  // create multidimensional matrices
  //! [init]
  int sz[3] = {2, 2, 2};
  Mat L(3, sz, CV_8UC(1), Scalar::all(0));
  //! [init]

  // Create using MATLAB styles eye, one or zero matrix
  //! [matlab]
  Mat E = Mat::eye(4, 4, CV_64F);
  cout << "E = " << endl << "" << E << endl << endl;
  Mat O = Mat::ones(2, 2, CV_32F);
  cout << "O = " << endl << "" << O << endl << endl;
  Mat Z = Mat::zeros(3, 3, CV_8UC1);
  cout << "Z = " << endl << "" << Z << endl << endl;
  //! [matlab]

  // create a 3x3 double-precision indentity matrix
  //! [comma]
  // do the same with initialize_list
  Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  cout << "C = " << endl << "" << C << endl << endl;

#ifdef CV_CXX11
  //! [list]
  C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);
  cout << "C = " << endl << "" << C << endl << endl;
  //! [list]
#endif
  //! [Clone]
  Mat RowCone = C.row(1).clone();
  cout << "Clone" << endl << "" << RowCone << endl << endl;
  //! [Clone]

  // Fill a matrix with random values
  //! [random]
  Mat R = Mat(3, 2, CV_8UC3);
  randu(R, Scalar::all(0), Scalar::all(255));
  //! [random]

  // Demonstrate the output formatting options
  //! [out-default]
  cout << "R (default) = " << endl <<        R           << endl << endl;
  //! [out-default]

  //! [out-python]
  cout << "R (python)  = " << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;
  //! [out-python]

  //! [out-numpy]
  cout << "R (numpy)   = " << endl << format(R, Formatter::FMT_NUMPY ) << endl << endl;
  //! [out-numpy]
  //! [out-csv]
  cout << "R (csv)     = " << endl << format(R, Formatter::FMT_CSV   ) << endl << endl;
  //! [out-csv]

  //! [out-c]
  cout << "R (c)       = " << endl << format(R, Formatter::FMT_C     ) << endl << endl;
  //! [out-c]
  
  //! [out-poit2]
  Point2f P(5, 1);
  cout << "Point (2D) = " << P << endl << endl;
  //! [out-poit2]

  //! [out-poit3]
  Point3f P3f(2, 6, 7);
  cout << "Point (3D) = " << P3f << endl << endl;
  //! [out-poit3]

  //! [out-vertor]
  vector<float> vec;
  vec.push_back( (float) CV_PI);    vec.push_back(2);    vec.push_back(3.01f);
  cout << "Vector of float via Mat = " << Mat(vec) << endl << endl;
  //! [out-vertor]

  //! [out-vertor-points]
  vector<Point2f> vecPoints(20);
  for (size_t i = 0; i < vecPoints.size(); ++i) {
    vecPoints[i] = Point2f( (float) (i * 5), (float) (i % 7));
    cout << "A vector of 2D Point = " << vecPoints << endl << endl;
  }
  //! [out-vertor-points]

  return 0;       
}                 
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
