#include "common.h"
/* localdecomp:start func_L41_0041AA98 */
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
typedef struct {int quality;} Settings;
extern Settings *D_L41_002412A0;
extern int D_L41_0024145C;
extern u8 *D_L41_0029B39C[];
extern u32 D_001DBFF0_sda,D_001DBFEC_sda;
__asm__(".extern D_001DBFF0_sda, 4");
__asm__(".extern D_001DBFEC_sda, 4");
extern void func_L01_00440A88(void *,float,float);
extern float func_L39_005B2510(float,float);
extern int func_L39_005B2498(int),func_L39_005B24C8(int,int);
extern u8 *func_L01_0046DCB8(void *,void *,int,u32,int,int,int,float,float,int,float);
void func_L41_0041AA98(void *pos,int count,float rate,float sizeMin,float sizeMax,float speedMin,float speedMax,float zMin,float zMax) {
    V velocity;
    int i;
    u32 color;
    u8 *p;
    float size;
    if(D_L41_002412A0->quality>=3)count/=3;
    for(i=0;i<count;i++) {
        func_L01_00440A88(&velocity,speedMin*(1.0f/60.0f),speedMax*(1.0f/60.0f));
        velocity.z=func_L39_005B2510(zMin,zMax)*(1.0f/60.0f);
        size=func_L39_005B2510(sizeMin,sizeMax);
        color=func_L39_005B2498(3)?D_001DBFF0_sda:D_001DBFEC_sda;
        switch(D_L41_0024145C) {
        case 0x2A: case 0x34:
            color=func_L39_005B2498(3)?0x273538:0x263438;break;
        case 0x29: case 0x2D: case 0x33: case 0x37:
            color=func_L39_005B2498(3)?0x282720:0x272418;break;
        }
        p=func_L01_0046DCB8(pos,&velocity,func_L39_005B24C8(90,150),color,-2,127,127,size*210000.0f,size*210000.0f,0,rate*0.00027777778450399637f);
        if(p) {
            int index=func_L39_005B2498(3);
            u8 texture=D_L41_0029B39C[0][index+10];
            p[3]=0x44;
            p[2]=texture;
        }
    }
}
/* localdecomp:end func_L41_0041AA98 */
