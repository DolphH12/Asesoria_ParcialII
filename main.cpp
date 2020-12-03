#include <iostream>
#include <math.h>
#include <vector>
#define G 9.81
#define pi 3.141617
using namespace std;

//void Do(float Xo, float Yo, float Vo, float angle){
//   float X,Y,Vx,Vy,t;
//   Vx = Vo*cos(angle);
//   Vy = Vo*sin(angle) - G*t;
//   X = Xo + Vx*t;
//   Y = Yo + Vy*t-(0.5)*G*t*t;
//}

//void Dd(float Xo, float Yo, float Vo, float angle){
//   float X,Y,Vx,Vy,t;
//   Vx = Vo*cos(angle);
//   Vy = Vo*sin(angle) - G*t;
//   X = Xo + Vx*t;
//   Y = Yo + Vy*t-(0.5)*G*t*t;
//}

struct Do{
    float d = 800;
    float Ho = 100;
    float Xo = 0;
    float Yo = Ho;
    float d0 = 0.05*d;
    float ao = 0;
};

struct Dd{
    float d = 800;
    float Hd = 20;
    float Xd = d;
    float Yo = Hd;
    float d0 = 0.025*d;
    float ad = 0;
};

int main()
{
    Do disparoO;
    bool flag;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = 200; V0o <= 300; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoO.Yo + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoO.d - x),2)+pow((disparoO.Yo - y),2)) < disparoO.d0){
                    flag = 1;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag) break;

        }
        if(flag) break;
    }
    if(flag){
        cout << "Impacto con un angulo de " << angle << " grados" << endl;
        cout << "Impacto con velocidad incial " << V0o << endl;
        cout << "Impacto con posicion x: " << x << endl;
        cout << "Impacto con posicion y: " << y << endl;
        cout << "Con tiempo: " << t << endl;
    } else{
        cout << "No impacto"<< endl;
    }

    return 0;
}
















