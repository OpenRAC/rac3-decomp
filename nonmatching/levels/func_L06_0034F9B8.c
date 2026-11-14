/* NTSC-U draft (2026-11-14, Codex worker): C of func_L06_0034ECC8, the NTSC-U twin of func_L06_0034F9B8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L06_0034A2B8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
typedef int Q128 __attribute__((mode(TI)));
/* localdecomp:start func_L06_0034ECC8 */
extern int func_0037E1D8(int);
extern void func_L01_00458A70(void *, float, float, float, float);
extern void func_L06_00349480(void *);
extern void func_L01_00441FB8(void *, int, int);
extern void func_003BE4F0(void *, int, int, int);
extern void func_L01_004A6DF8(void *, int);
int func_L06_0034ECC8(unsigned char *a) {
    unsigned char *d = *(unsigned char **)(a+0x68);
    d[0x170]=41;
    *(Q128 *)(d+0x910)=*(Q128 *)(a+0x10);
    d[0x1A8]=3;
    *(float *)(d+0x194)=0.5f;
    *(float *)(d+0x19C)=0.15f;
    d[0x171]=22; d[0x172]=24; d[0x176]=26;
    *(float *)(d+0x190)=0.5f;
    if (!func_0037E1D8(3)) d[0x176]=25;
    else if (!func_0037E1D8(2)) d[0x176]=255;
    if (d[0x176]==25) {
        d[0x1D3]=12; d[0x1D2]=7;
        *(float *)(d+0x17C)=0.916666687f;
        *(float *)(d+0x188)=0.216666684f;
        *(float *)(d+0x180)=0.216666684f;
        *(float *)(d+0x184)=0.216666684f;
    }
    *(int *)(d+0xAC)=*(int *)(d+0x97C);
    d[0x1D7]=1; d[0x1A9]=1;
    *(float *)(d+0x70)=0.65f; *(float *)(d+0x74)=0.2f;
    *(float *)(d+0x78)=0.5f; *(float *)(d+0x7C)=1.5f;
    *(float *)(d+0x80)=1.51843643f; *(float *)(d+0xA0)=0.34906584f;
    *(float *)(d+0x9C)=0.00272222236f;
    func_L01_00458A70(a,0.005f,0.13333334f,0.00698131742f,0.209894434f);
    d[0x58]=20; d[0x5A]=14;
    if (!*(short *)(d+0x34)) { *(short *)(d+0x34)=20; *(float *)(d+0x30)=20.0f; }
    d[0x3E]=1; d[0x39]=0; d[0x3F]=0; *(float *)(d+0x40)=1.0f;
    func_L06_00349480(a);
    *(int *)(d+0x934)=-1;
    func_L01_00441FB8(a,1,0);
    if(a[0x43]) func_003BE4F0(a,0,0,0);
    if(*(int *)(d+0x94C)) {
        func_L01_00441FB8(a,31,-1);
        if(a[0x43]!=5) func_003BE4F0(a,5,0,4);
    }
    if(*(int *)(d+0x954)) {
        if(a[0x43]!=6) func_003BE4F0(a,6,0,6);
        func_L01_00441FB8(a,4,-1);
    }
    if(*(int *)(d+0x950)!=-1) {
        func_L01_00441FB8(a,5,-1);
        if(a[0x43]!=6) func_003BE4F0(a,6,0,10);
    }
    if(*(int *)(d+0x958)) {
        *(int *)(a+0x98)=0;
        *(unsigned short *)(a+0x34)=(*(unsigned short *)(a+0x34)|0x41)&0xEFFF;
        func_L01_004A6DF8(a,1);
        func_L01_00441FB8(a,37,5);
    }
    return 0;
}
/* localdecomp:end func_L06_0034ECC8 */
