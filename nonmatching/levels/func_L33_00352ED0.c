/* NTSC-U draft (2026-11-14, Codex worker): C of func_L33_00352298, the NTSC-U twin of func_L33_00352ED0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 5 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L33_00352298 */
extern void func_L01_00441FB8(void *, int, int);
extern void func_003BE4F0(void *, int, int, int);
extern int func_0037E208(int, int);
extern float D_001DD8B8_sda;
extern float D_001DD8A8_sda;
extern float D_001DD998_sda;
extern float D_001DD9C8_sda;
extern float D_001DDA70_sda;
extern float D_001DD9F0_sda;
extern float D_001DDA80_sda;
extern float D_001DDAA0_sda;
extern float D_001DD928_sda;
extern float D_001DDAC4_sda;
extern float D_001DDAAC_sda;
extern int D_001DDB88_sda;
extern int D_001DDB84_sda;
extern int D_001DDAB0_sda;

void func_L33_00352298(unsigned char *m, int state) {
    int type = 0x1761 - *(short *)(m+0xAA);
    func_L01_00441FB8(m,state,-1);
    switch(m[0x20]) {
    case 1:
        func_003BE4F0(m,4,(int)(&D_001DD8B8_sda)[type],D_001DDB88_sda);
        *(float *)(m+0x48)=(&D_001DD8A8_sda)[type];
        break;
    case 2:
        if(m[0x43]!=11) func_003BE4F0(m,11,(int)(&D_001DD998_sda)[type],D_001DDB84_sda);
        *(float *)(m+0x44)+=*(float *)(m+0x4C);
        *(float *)(m+0x48)=1.0f;
        break;
    case 3:
        if(m[0x43]!=7) func_003BE4F0(m,7,0,D_001DDB88_sda);
        *(float *)(m+0x48)=(&D_001DD9C8_sda)[type];
        break;
    case 4:
        func_003BE4F0(m,10,(int)(&D_001DDA70_sda)[type],D_001DDB84_sda);
        *(float *)(m+0x48)=(&D_001DD9F0_sda)[type];
        *(float *)(m+0x44)+=*(float *)(m+0x4C);
        break;
    case 5:
        if(!func_0037E208(0,1)) {
            if(m[0x43]!=1)func_003BE4F0(m,1,0,D_001DDB88_sda);
        } else {
            if(m[0x43]!=2)func_003BE4F0(m,2,0,D_001DDB88_sda);
        }
        *(float *)(m+0x48)=1.0f;
        break;
    case 7:
        if(m[0x43]!=5)func_003BE4F0(m,5,0,D_001DDB88_sda);
        *(float *)(m+0x48)=D_001DD928_sda;
        break;
    case 8:
        if(m[0x43]!=6)func_003BE4F0(m,6,(int)D_001DDAC4_sda,D_001DDB88_sda);
        *(float *)(m+0x48)=1.0f;
        break;
    case 9:
        if(m[0x43]!=6)func_003BE4F0(m,6,0,D_001DDB88_sda);
        break;
    case 10:
        if(m[0x43]!=12)func_003BE4F0(m,12,(int)D_001DDAAC_sda,D_001DDAB0_sda);
        *(float *)(m+0x48)=(&D_001DDA80_sda)[type];
        break;
    case 11:
        if(m[0x43]!=8)func_003BE4F0(m,8,(int)(&D_001DDAA0_sda)[type],D_001DDAB0_sda);
        *(float *)(m+0x48)=(&D_001DDA80_sda)[type];
        break;
    case 13:
        if(m[0x43]!=9)func_003BE4F0(m,9,0,D_001DDB88_sda);
        *(float *)(m+0x48)=1.0f;
        break;
    case 6: case 12: case 14:
        if(m[0x43]!=3)func_003BE4F0(m,3,0,D_001DDB88_sda);
        break;
    case 15:
        if(m[0x43]!=3)func_003BE4F0(m,3,0,D_001DDB88_sda);
        *(float *)(m+0x48)=1.0f;
        break;
    case 0: case 66: break;
    }
}
/* localdecomp:end func_L33_00352298 */
