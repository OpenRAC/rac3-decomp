/* PAL near miss (haiku-w6): 251 words differ with the file's flags; the h base register (retail keeps it in $s0, this draft in $s1), the allow flag register, and the $gp global loads placed before the 0x33C test. Moby_4E52E0 needs the typedef moved before the block to compile in its file. */
#include "common.h"
/* localdecomp:start func_L01_004E20E8 */
#include "vu0.h"
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6694;
extern u8 D_00142CAB[];
typedef struct { u8 pad0[0x50]; u8 *object; u8 pad54[0x2A0-0x54]; s16 counter; } State_004E20E8;
extern State_004E20E8 D_L01_001E2A40;
void func_L01_004E20E8(void) {
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CF38(void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DBA0(f32,f32);
    extern int func_003D3CB0(char *,char *,int,int,int);
    extern void func_L01_00430118(void *);
    extern void func_L01_004436F4(s32);
    extern s32 func_L01_004606E8(s32,s32,s32,s32);
    extern void func_L01_004E04A0(void);
    extern void func_L01_004E0618(void);
    extern void func_L01_004E0920(void);
    extern void func_L01_004E1218(void);
    extern void func_L01_004E13A0(void);
    extern void func_L01_004E1638(void);
    extern void func_L01_004E1F00(s32);
    extern void func_L01_004E20E8(void);
    extern s32 func_L01_004E26A0(void);
    extern void func_L01_004E2C48(void);
    extern void func_L01_004E2ED0(void);
    extern void func_L01_004E3148(void);
    extern void func_L01_004E45C8(void);
    extern void func_L01_004E48C8(void);
    extern void func_L01_004E52E0(Moby_4E52E0 *);
    extern void func_L01_004E64C0(void);
    extern void func_L01_004E67F8(void);
    extern void func_L01_004E6D10(void);
    extern void func_L01_004E6D18(void);
    extern void func_L01_004E7338(void);
    extern void func_L01_004E7CB8(void);
    extern void func_L01_004E8318(void *,void *,void *);
    extern void func_L01_004E8EE0(void);
    extern void func_L01_004E90C8(void);
    extern void func_L01_004E9450(void);
    extern void func_L01_004EAEE8(void);
    extern void func_L01_004ED328(void);
    extern void func_L01_004EE4E0(void);
    extern void func_L01_004F2A08(void);
    extern void func_L01_004F5010(void);
    extern void func_L01_004FF780(void);
    extern void func_L01_004FFA10(void);
    extern void func_L01_004FFD00(void);
    extern void func_L01_004FFF58(void);
    extern void func_L01_00507AF8(void);
    extern void func_L01_0050FF00(void);
    extern void func_L01_005108C0(s32);
    extern void func_L01_00510AD0(void);
    extern void func_L01_005129A8(s32);
    extern void func_L01_00512E68(void);
    extern void func_L01_005138F8(void);
    extern s32 func_L01_00513EF0(void);
    vu0_v4 point,top,bottom;
    u8 *h=(u8 *)&D_001A4BE0;
    s32 allow=0;
    s32 eligible;
    *(s16 *)(h+0x23D2)=0;
    *(s16 *)(h+0x23D0)=0;
    if (h[0x25E4]) {
        func_L01_004E13A0();
        func_L01_004E1F00(0);
        if (h[0x25E4]==5) func_L01_004E1638();
        return;
    }
    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L01_004E7CB8();
    func_L01_004E8318(h+0x80,h+0x90,h+0x500);
    func_L01_004E8EE0();
    func_L01_004E90C8();
    if (*(f32 *)(h+0x338)==0.0f || *(f32 *)(h+0x308)-*(f32 *)(h+0x338)>2.0f || h[0x147D] || h[0x1476] || h[0x147E] || h[0x1477] || h[0x1478]) allow=1;
    if (func_L01_004606E8(0x20,0x11,0,0)) {
        if (*(f32 *)(h+0x33C)>0.7f && *(f32 *)(h+0x178)>0.10000000894069672f) {
            func_0038CE20(&point,h+0x110,20.0f);
            point.z=0.0f;
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(point) : "m"(*(vu0_v4 *)(h+0x80)) : "vf1","vf2");
            *(vu0_q *)&top=*(vu0_q *)&point;
            *(vu0_q *)&bottom=*(vu0_q *)&point;
            bottom.z-=1.5f;
            top.z+=1.0f;
            if (!func_003D3CB0((char *)&top,(char *)&bottom,2,0,0)) allow=1;
        }
    }
    if (D_L01_001D673C) allow=0;
    if (func_L01_004606E8(0x20,4,0,0)) {
        if (*(s32 *)(h+0x1228)==11) goto update;
        eligible=D_001D545C==5;
        if (D_001D545C==17) {
            *(vu0_q *)&point=0;
            point.y=455.70001220703125f;
            point.x=424.5f;
            point.z=120.2699966430664f;
            if (func_0038CF38(h+0x80,&point)<11.5f) {
                f32 angle=func_0038D160(point.x-*(f32 *)(h+0x80),point.y-*(f32 *)(h+0x84));
                if (func_0038DBA0(*(f32 *)(h+0x98),angle)<30.0f) eligible=1;
            }
        }
        if (eligible) {
            func_L01_004FFF58();
            if (*(s32 *)(h+0xAC4)) allow=1;
        }
    }
    if (*(s32 *)(h+0x1228)==11 || allow) {
update:
        func_L01_004FF780();
        func_L01_004FFA10();
        func_L01_004FFD00();
        func_L01_004FFF58();
        if ((*(s32 *)(h+0xA28) || *(s16 *)(h+0xA5E) || *(s32 *)(h+0xAC4)) && allow && h[0x25E8]==0 && h[0x25F0]==0 && D_00142CAB[0]) h[0x25E7]=1;
    }
    func_L01_00507AF8();
    if (D_L01_001D6694==2 || D_L01_001D6694==6) {
        if (h[0x25E5]) func_L01_005108C0(0);
        else func_L01_00510AD0();
        goto save;
    }
    func_L01_005129A8(*(s32 *)(h+0x25C0));
    func_L01_004E9450();
    if (h[0x25E4]) goto save;
    func_L01_004F5010();
    func_L01_004E7338();
    func_L01_004E64C0();
    func_L01_004E67F8();
    func_L01_004E6D18();
    func_L01_004E6D10();
    func_L01_004E0618();
    func_L01_004E0920();
    func_L01_004F2A08();
    func_L01_004E04A0();
    func_L01_004E45C8();
    func_L01_004E52E0(0);
    func_L01_004ED328();
    func_L01_004EAEE8();
    if (h[0x25E5] || func_L01_00513EF0()==2) {
        if (func_L01_00513EF0()==2 && (D_L01_001E2A40.counter || (D_L01_001E2A40.object && *(s16 *)(D_L01_001E2A40.object+0x86)==0))) func_L01_00510AD0();
        else func_L01_005108C0(0);
    } else func_L01_00510AD0();
    func_L01_004E3148();
    func_L01_004E2ED0();
    func_L01_004E1638();
    func_L01_005138F8();
    func_L01_004E1218();
    func_L01_00512E68();
    if (*(s32 *)(h+0x25C4)!=0x31 || func_L01_004E26A0()) func_L01_00430118(h+0x80);
    func_L01_004436F4(*(s32 *)(h+0x25C0));
    func_L01_004E2C48();
    func_L01_004E48C8();
    if (func_L01_00513EF0() && *(s32 *)(h+0x280C)!=4 && *(s32 *)(h+0x280C)!=0x51) *(s32 *)(h+0x280C)=0x20;
save:
    func_L01_004E1F00(0);
}
/* localdecomp:end func_L01_004E20E8 */
