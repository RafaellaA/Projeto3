#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <iostream>
#include "vector"

using namespace std;

struct Voxel{
    float r,g,b,a;
    bool isOn;
};

enum {XY,ZX,YZ};//Identifica o plano

class Sculptor
{
private:
    Voxel ***v;
    int nx,ny,nz;
    float _r,_g,_b,_a;

public:
    Sculptor(int _nx=0,int _ny=0,int _nz=0);
    ~Sculptor();
    void setColor(float r,float g,float b,float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x,int y,int z);
    void putBox(int x0,int x1,int y0, int y1,int z0,int z1);
    void cutBox(int x0,int x1,int y0, int y1,int z0,int z1);
    void putSphere(int xcenter, int ycenter, int zcenter,int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter,int radius);
    void putEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz);
    void cutEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz);
    void writeOFF(string filename);
    void writeVECT(string filename);
    vector< vector<Voxel> > getPlano(int dim =0, int plano = XY);
};

#endif // SCULPTOR_H
