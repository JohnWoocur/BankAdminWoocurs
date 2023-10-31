#include <iostream>
#include <fstream>

using namespace std;

int sreport()
{

    fstream StaReadFile;
    string txtOut;

    StaReadFile.open("staff_record.txt");
    while(getline(StaReadFile,txtOut))
    {
        cout<<txtOut;

    }



    return 0;
}
