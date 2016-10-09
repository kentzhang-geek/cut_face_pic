#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

#include "config.h"
#include "cut_face_process.h"

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
    Vector<String> files;
    for (int i = 1; i < argc; i++) {
        files.push_back(String(argv[i]));
    }

    cut_face_process::init();

    for (Vector<String>::iterator fit = files.begin();
            fit != files.end();
            fit++) {
        cut_face_process::process_file(*fit);
    }

    for (std::vector<String>::iterator fit = cut_face_process::failed_files.begin();
         fit != cut_face_process::failed_files.end();
         fit++) {
        cout << "failed in process " << *fit << endl;
    }

    return 0;
}
