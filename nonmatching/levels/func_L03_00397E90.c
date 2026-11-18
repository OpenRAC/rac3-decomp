/* PAL port of the NTSC-U draft (Codex wave 3, func_L03_00396818), 22 diff on PAL with the file's flags (Sonnet Y1, round 7).
 * Ported: callee names through config/us/map.tsv, D_L03_001DFA80 (was ...FB00), D_L03_002D09B0 (was ...09F0), 125 (was 150), and the
 * 50 Hz constants 0.003200000152f / 0.3200000226f (were 0.002222222276f / 0.2666666806f). The switch, the cases and the epilogue match;
 * left (22 words, three spots):
 * - case 10: retail loads the call's first argument (`li $a0,0x74`) before the `sw` to D_001A74A4; ours stores first;
 * - case 12: retail's `lui $v0,0x1d` for D_001D5534 sits after the func_L01_004561B8 call (the beqz slot is a nop), ours hoists it into the
 *   slot (gcse hoists the very busy lui; the lbu result is $v0 there, $v1 here);
 * - the case-12 bit loop: retail has `sltiu $v0,$s0,8; beqz` and a plain `li $a1,1` for the 1 of `1 << i` (cse knew the flag is 1),
 *   registers $v0/$a0/$a1 against ours $a0/$a1/$a0. `i >= 0 && i < 8` / `(u32)i < 8` with a literal 1 change the frame (0x60, 404 diff):
 *   the `enable` local is what keeps the register count. */
#include "common.h"

typedef int Q96818 __attribute__((mode(TI)));

/* localdecomp:start func_L03_00397E90 */
extern void func_L03_00398500(void *);
extern void func_L01_0044F450(void *, void *);
extern u8 *D_L03_001DFA80;
extern u8 D_001426E8[], D_001A30B0[], D_001A4C60[];
extern int D_L03_002D09B0[];
extern u8 *D_001D52FC;
extern short D_001A4DF2[];
extern unsigned short D_001A801C[], D_001A8538[];
extern int D_001A74A4[];
extern u8 D_001D5534[], D_00142660[], D_001426E0[], D_001426F4[];
extern int func_003A52A0(int, int, void *);
extern void func_003A4F28(int);
extern int func_00382380(void *, int, int);
extern void func_L01_004450F0(void *, int, int);
extern void func_L03_00398E30(void *, int, int);
extern void func_L03_00399010(void *, int, int);
extern int func_L01_00452560(int,int,int,int,int,int,int);
extern void func_L01_005003D0(int,int);
extern int func_L01_004561B8(void *);
extern void func_L01_003F3740(int);
extern void func_L01_003F3768(int);
extern int func_0038CAD0(void *);
extern void func_L01_0041A5B0(int,int);
extern float func_003C41A0(float *,void *,float,float,float,float);
extern int func_0039EF28(void);
extern void func_L01_0041BE28(int,int);
static __inline__ int flag96818(u8 *p) {return *p;}
extern void func_L03_00398900(void *);
static __inline__ int above96818(u8 *p,int i) {return *(short *)(p+0x40)<i;}
extern void func_L03_00398A78(void *);
extern void func_L03_00398D50(void *);

void func_L03_00397E90(u8 *a) {
    u8 *d;
    int i;
    func_L03_00398500(a);
    d=*(u8 **)(a+0x68);
    func_L01_0044F450(a,d);
    *(Q96818 *)(D_L03_001DFA80+(*(int *)(d+0x4D8)<<7)+0x30)=*(Q96818 *)(a+0x10);
    switch(a[0x20]) {
    case 1:
        if(D_001426E8[0]) {
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_003A52A0(1,4,a); }
            func_L01_004450F0(a,2,-1);
        }
        break;
    case 2:
        func_L03_00398E30(a,0,3);
        break;
    case 3:
        if(func_00382380(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_004450F0(a,4,-1);
        break;
    case 4:
        if(!func_00382380(D_001A4C60,*(int *)(d+0x4D8),0)) {
            func_L01_004450F0(a,3,-1);
            break;
        }
        func_L01_00452560(0,11,0xA26,1,0,0,0);
        if(D_L03_002D09B0[0]==11 && (*(int *)(D_001D52FC+0x1A4)&16)) {
            *(int *)(D_001A4C60+0x2844)=1;
            func_L01_005003D0(0x74,1);
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_003A52A0(1,4,a); }
            func_L01_004450F0(a,5,-1);
        }
        break;
    case 5:
        func_L03_00399010(a,0,6);
        break;
    case 6:
        if(func_L01_004561B8(a)) {
            func_L01_003F3740(0);
            *(int *)(d+0x4E4)=125;
        }
        D_001A4DF2[0]=4;
        if(func_0038CAD0(d+0x4E4) && !D_001A801C[0]) func_L01_0041A5B0(0xB88,0x2B);
        func_003C41A0((float *)(a+0x14),d+0x4DC,325.0f,0.003200000152f,0.003200000152f,0.3200000226f);
        if(*(float *)(a+0x14)==325.0f) {
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h!=-1 && ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)==a && p[0xD0]))) func_003A4F28(h); }
            *(int *)(d+0x4E8)=-1;
            *(int *)(d+0x4E8)=func_003A52A0(1,4,a);
            func_L01_003F3768(0);
            func_L01_004450F0(a,7,-1);
        }
        break;
    case 7:
        func_L03_00398E30(a,1,9);
        break;
    case 9:
        if(func_00382380(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_004450F0(a,10,-1);
        break;
    case 10:
        func_L01_00452560(0,11,0xA27,1,0,0,0);
        if(D_L03_002D09B0[0]==11 && (*(int *)(D_001D52FC+0x1A4)&16)) {
            D_001A74A4[0]=1;
            func_L01_005003D0(0x74,1);
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_003A52A0(1,4,a); }
            func_L01_004450F0(a,11,-1);
        } else if(!func_00382380(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_004450F0(a,9,-1);
        break;
    case 11:
        func_L03_00399010(a,1,12);
        break;
    case 12:
        if(func_L01_004561B8(a)) func_L01_003F3740(0);
        if(flag96818(D_001D5534) && !D_001A8538[0]) func_L01_0041A5B0(0xCF1,0x98);
        D_001A4DF2[0]=4;
        func_003C41A0((float *)(a+0x14),d+0x4DC,*(float *)(d+0x4E0),0.003200000152f,0.003200000152f,0.3200000226f);
        if(*(float *)(a+0x14)==*(float *)(d+0x4E0)) {
            for(i=1;i<5;i++) {
                unsigned char enable;
                if((enable=(u32)i<8) && ((D_001426E0[0x3E]>>i)&1) && !((D_001426E0[0x75]>>i)&1) && above96818(D_00142660,i)) {
                    D_001426E0[0x75]|=enable<<i;
                    func_0039EF28();
                    func_L01_0041A5B0(0xC9A,0x5D);
                    switch(i) { case 2: func_L01_0041BE28(0x15FA,0x131); break; case 3: func_L01_0041BE28(0x15FB,0x132); break; }
                }
            }
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h!=-1 && ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)==a && p[0xD0]))) func_003A4F28(h); }
            *(int *)(d+0x4E8)=-1;
            *(int *)(d+0x4E8)=func_003A52A0(1,4,a);
            func_L01_004450F0(a,2,-1);
            func_L01_003F3768(0);
        }
        break;
    case 13:
        if(D_001426F4[0]) {
            func_L03_00398900(a);
            func_L03_00398A78(a);
            func_L03_00398D50(a);
            func_L01_004450F0(a,9,-1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00397E90 */
