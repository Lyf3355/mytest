#include<string.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

class Dictionary 
{
public:
    void read(const std::string & filename);
    void store(const std::string & filename);
private:

};

void write()
{
    ofstream ofs("vactorStore.txt",ios::app);
    if(!ofs)
    {
        cout << "ofstream open file error!" << endl;
        return;
    }
    cout << "pos =" <<ofs.tellp() << endl;
    ofs <<  "data" <<endl;//放数据
    ofs.close();
}

void readVector(const string & filename)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << "ifstream open file " << filename << "error!" << endl;
        return ;
    }
    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        string key, value;
        while(!iss.eof())
        {
            iss >> key >> value;
            cout << key << "  " << value << endl;
        }
    }
}

void chgString()
{
    string filename = "vector.cc";
    ifstream ifs(filename,ios::ate);
    if(!ifs)
    {
        cout << "ifstream open file " << filename << "error" <<endl;
        return;
    }

    int length =ifs.tellg();
    char * buff = new char[length+1]();

    ifs.seekg(ios::beg);
    ifs.read(buff, length);
    delete [] buff;
    ifs.close();
}



void reasch()
{
    vector<string> line;
    line.reserve(10000);
    ifstream ifs;
    ifs.open("vector.cc");
    if(!ifs.good())
    {
        cout << ">> ifstream open file error" << endl;
        return;
    }
    string word;
    size_t tag=1;
    while(ifs >> word)
    {
        for(size_t idx=0;idx!=tag;++idx)
        {
            if(word==line[idx])
            {
                            
            }
        }
    }
}
int main()
{
    vector<string> line;
    line.reserve(10000);
    return 0;
}

