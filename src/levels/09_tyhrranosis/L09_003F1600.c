#include "common.h"

typedef int Q87e __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V87e;
typedef struct { char pad[32]; float rate; int pad24, timer, count; } G87e;

INCLUDE_ASM("asm/levels", func_L09_003F1600);

INCLUDE_ASM("asm/levels", func_L09_003F1840);

/* localdecomp:start func_L09_003F1A50 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_003EFBC8.c */

extern void *func_L01_00447490(void *,int,int);
extern void func_003A52A0(int,int,void *);
extern float func_003824E0(float,float);
extern int func_00382498(int,int);
extern void func_L01_00451FE0(void *,int,void *,int,int,int,int,int,int,int,float,float,float,float,float,float,float,float);

extern float D_L09_001D66B0_003EFBC8;
__asm__(".extern D_L09_001D66B0_003EFBC8, 16");

extern G87e D_L09_001E2B80;
__asm__(".extern D_L09_001E2B80, 0");
extern void func_L01_004450F0(void *,int,int);
extern int func_003D4D00(void *,float,int,void *,void *);
extern int func_L01_00459590(void *,int,float);
extern void func_L09_003F1600(void *);
extern void func_L09_003F1840(void *);
extern int func_0038CAD0(int *);
extern void func_003C2880(void *);
void func_L09_003F1A50(u8 *m) {
    u8 *t=*(u8 **)(m+0x68);
    u8 *hit;
    float rand;
    float frac;
    int timer;
    struct { V87e pos; void *owner; int flags; int pad18; float power; int zero; } __attribute__((aligned(16))) data;
    V87e v;
    switch(m[0x20]) {
    case 0:
        *(int *)t=8;
        func_L01_004450F0(m,1,-1);
        break;
    case 1:
        hit=func_L01_00447490(m,-1,0);
        if(hit && *(u8 **)(hit+0x20) && *(short *)(*(u8 **)(hit+0x20)+0xAA)==0x1C0C) {
            func_003A52A0(0,0,m);
            rand=func_003824E0(10,20);
            timer=func_00382498(90,150);
            func_L01_00451FE0(m,255,&D_L09_001D66B0_003EFBC8,255,timer,0,0,35,0,3,0,1,0,1,2.5f,rand,1,1);
            D_L09_001E2B80.rate=0.5f;
            D_L09_001E2B80.timer=25;
            D_L09_001E2B80.count=0;
            m[0x31]=0;
            *(unsigned short *)(m+0x34)|=1;
            func_L01_004450F0(m,2,-1);
            data.owner=*(void **)(hit+0x20);
            data.power=100;
            data.flags=0x10000;
            data.zero=0;
            v=*(V87e *)(m+0x10);
            v.z+=4;
            func_003D4D00(&v,5,16,m,&data);
            v.z-=8;
            func_003D4D00(&v,5,16,m,&data);
        }
        break;
    case 2:
        frac=*(float *)(m+0x2C) / *(float *)(*(u8 **)(m+0x24)+0x24);
        data.pos=*(V87e *)(m+0x10);
        data.pos.w=frac*8;
        if(func_L01_00459590(&data,0,128)>=0) {
            func_L09_003F1600(m);
            func_L09_003F1840(m);
        }
        if(func_0038CAD0((int *)t))func_L01_004450F0(m,3,-1);
        break;
    case 3:
        func_003C2880(m);
        return;
    }
    m[0xA8]=255;
}
/* localdecomp:end func_L09_003F1A50 */
