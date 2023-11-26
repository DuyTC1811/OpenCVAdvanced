//! [include]

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {
  //! [imread]
  string image_parth =
      samples::findFile("/Users/duytc/Documents/OpenCVAdvanced/"
                        "01_display_image/starry_night.jpg");
  Mat img = imread(image_parth, IMREAD_COLOR);
  //! [imread]

  //! [empty]
  if (img.empty()) {
    cout << "Could not read the image" << image_parth << endl;
    return 1;
  }
  //! [empty]

  //! [imshow]
  imshow("Display window", img);
  int key = waitKey(0);
  //! [imshow]

  //! [imsave]
  if (key == 'q') {
    imwrite("starry_night.png", img);
  }
  //! [imsave]

  return 0;
}
