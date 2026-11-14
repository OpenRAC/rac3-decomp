#include "common.h"
/* localdecomp:start func_L30_00347AF8 */
extern void func_L30_00348A40(void *);
extern int func_0037E0F0(void *,int,int);
extern unsigned char D_001A4C60[];
typedef struct { unsigned char pad0[0x24]; unsigned char *data; unsigned char pad28[0xC]; unsigned short flags; unsigned char pad36[0x62]; int f98; unsigned char pad9C[0x64]; } Moby30;
extern Moby30 *D_L30_001DF71C_00347AF8;
typedef struct { unsigned char pad[0x20]; float f20; int f24,f28,f2C; } Data30;
extern Data30 D_L30_001E22C0_00347AF8;
extern unsigned char D_00142732[];
extern void func_L30_00349310(void *,int);
extern int func_L01_00452EC8(void *);
extern int func_L30_00348BF8(void *,int,int);
extern int func_L30_00349150(void *);
extern void func_L30_00348620(void *);
extern void func_L01_00441FB8(void *,int,int);
extern void func_003BE4F0(void *,int,int,int);
extern int func_00388398(void *);
extern void func_L30_003488C0(void *,int,void *);
extern float func_0037E250(float,float);
extern void func_L04_00324BA8(void *,int,int,int,int,int,int,int,int,int,int,int,float,float);
extern void func_L30_00348170(void *);
extern void func_L30_00348328(void *);
extern void func_L30_00348510(void *);
extern void func_L30_00348968(void *);
void func_L30_00347AF8(unsigned char *m) {
    unsigned char *p=*(unsigned char **)(m+0x68);
    int i,j,k;
    int *v;
    Moby30 *objects;
    float pos[4] __attribute__((aligned(16)));
    switch(m[0x20]) {
    case 0:
        func_L30_00348A40(m); func_L01_00441FB8(m,1,-1); break;
    case 1:
        if (func_0037E0F0(D_001A4C60,*(int *)(p+0x98),0)) {
            objects=D_L30_001DF71C_00347AF8;
            objects[*(int *)(p+0x90)].flags&=0xFFBE;
            objects[*(int *)(p+0x90)].flags|=*(unsigned short *)(objects[*(int *)(p+0x90)].data+0x44)&0x1000;
            objects[*(int *)(p+0x90)].f98=*(int *)(objects[*(int *)(p+0x90)].data+0x10);
            func_L30_00349310(m,1);func_L01_00441FB8(m,3,-1);
        }
        break;
    case 3:
        func_L01_00452EC8(m);
        v=(int *)(p+0x9C);i=0;
        do { if (!func_L30_00348BF8(m,*v,1)) *v=func_L30_00349150(m); i--; v++; } while (i>=0);
        if (!func_L30_00348BF8(m,0,0)) func_L30_00348620(m);
        if (*(int *)(p+0xB0)<=*(int *)(p+0xB4)) func_L01_00441FB8(m,4,-1);
        break;
    case 4:
        if (func_L01_00452EC8(m)) { D_L30_001E22C0_00347AF8.f20=2.0f;D_L30_001E22C0_00347AF8.f28=30;D_L30_001E22C0_00347AF8.f2C=0; }
        v=(int *)(p+0x9C);j=1;
        do { if (!func_L30_00348BF8(m,*v,1)) *v=func_L30_00349150(m); j--; v++; } while (j>=0);
        if (!func_L30_00348BF8(m,0,0)) func_L30_00348620(m);
        if (*(int *)(p+0xB0)<=*(int *)(p+0xB8)) func_L01_00441FB8(m,5,-1);
        break;
    case 5:
        if (func_L01_00452EC8(m)) { D_L30_001E22C0_00347AF8.f20=2.0f;D_L30_001E22C0_00347AF8.f28=30;D_L30_001E22C0_00347AF8.f2C=0; }
        v=(int *)(p+0x9C);k=2;
        do { if (!func_L30_00348BF8(m,*v,1)) *v=func_L30_00349150(m); k--; v++; } while (k>=0);
        if (!func_L30_00348BF8(m,0,0)) func_L30_00348620(m);
        if (*(int *)(p+0xB0)<=0) func_L01_00441FB8(m,6,-1);
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            *(int *)(p+0xD0)=30;*(int *)(p+0xF0)=600;
            if (m[0x43]!=1) func_003BE4F0(m,1,0,10);
        }
        if (func_00388398(p+0xD0)) {
            func_L30_003488C0(m,0,pos);
            pos[0]+=func_0037E250(-1.5f,1.5f);
            *(int *)(p+0xD0)=30;
            func_L04_00324BA8(pos,1,25,20,20,20,45,1,1,1,0,0,1.0f,20.0f);
        }
        if (func_00388398(p+0xF0)) D_00142732[0]=1;
        break;
    }
    func_L30_00348170(m);func_L30_00348328(m);func_L30_00348510(m);func_L30_00348968(m);
}
/* localdecomp:end func_L30_00347AF8 */
