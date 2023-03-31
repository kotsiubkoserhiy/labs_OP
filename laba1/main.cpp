#include <iostream>
#include "workTheFiles.h"
#include "transformFiles.h"

using namespace std;

int main(int argc, char* argv[]) {
//    cout <<argv[0]<<endl;
    if (argc!=3){
        cout << "Error: parameters are incorrect" << endl;
        exit(0);
    }
    else{
        if (string(argv[1]) == "-mode" && string(argv[2]) == "FilePointer"){
            cout << "--------( -mode FilePointer )--------" << endl;
            //------------------------------------------------
            char path[13];
            cout << "Enter file name:  "; gets(path);
            createFile(path);
            //------------------------------------------------
            cout << "----Output new filePointer:----" << endl;
            readFile(path);
            //------------------------------------------------
            cout<< "----Transform filePointer:----" << endl;
            conversionFile(path);
            readFile(path);
            //------------------------------------------------
            cout<< "----Calc filePointer:----" << endl;
            calcandAddFile(path);
            readFile(path);
        }
        else{
            if (strcmp(argv[1], "-mode") == 0 && string(argv[2]) == "FileStream"){
                cout << "--------( -mode FileStream )--------" << endl;
                //------------------------------------------------
                string path;
                cout << "Enter file name: ";
                getline(cin, path);
                createFile(path);
                //------------------------------------------------
                cout << "----Output new fileStream:----" << endl;
                readFile(path);
                //------------------------------------------------
                cout << "----Transform fileStream:----" << endl;
                conversionFile(path);
                readFile(path);
                //------------------------------------------------
                cout << "----Calc and Add to the fileStream:----" << endl;
                calcandAddFile(path);
                readFile(path);
            }
            else{
                cout << "Error: parameters are incorrect" << endl;
            }
        }
    }

    return 0;
}
