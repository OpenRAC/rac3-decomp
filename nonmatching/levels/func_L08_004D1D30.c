/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_004CDA88, the NTSC-U twin of func_L08_004D1D30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L08_004D1D30.c's current line.
 * Worker's note: 308 diff; best func_L08_004CDA88.check01.log; permitted default assembler emits .lit4 GP loads for 0.02/0.1/0.0001/0.004/0.866666734 versus retail inline lui/ori/mtc1; real VU0 blocks still differ in scheduling; retail div nops 2 2 2; no unlisted flags tried
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L08_004CDA88 */
typedef struct { float x,y,z,w; } V_4CDA88;
typedef struct {
    char p0[0x80]; V_4CDA88 pos,v90; char pa0[0x50];
    V_4CDA88 velocity,extra,step,projected,flat,vertical,total;
    char p160[0x10]; float speed,hspeed,vspeed,ratio,vertical_speed,extra_speed;
    char p188[0x68]; short h1f0; char p1f2[0x5a]; float fall_limit;
    char p250[0x34]; float speed_limit; int clear28c_pad,clear28c;
    char p290[0x17]; unsigned char b2a7; char p2a8[0x290]; void *ref538;
    char p53c[0x4a4]; V_4CDA88 external;
    char p9f0[0x1bd4]; int state;
} Hero_4CDA88;
extern Hero_4CDA88 D_001A4BE0;
extern void func_L01_0050DB78(void *,void *,void *);
extern float func_L01_0050D430(void *),func_L01_0050D4D8(void *),func_00388770(void *),func_00388730(void *,void *),func_L01_004EC818(void *);
extern void func_L01_0050D5B0(void *,void *,float),func_L01_0050D530(void *,void *,float);
extern void func_003886E8(void *,void *,float),func_00388830(void *,void *,float),func_L01_0050D348(void *,void *);
extern void func_L01_004ECCD8(void),func_L08_004CC898(void),func_L01_004EC500(void);
static __inline__ void add_4CDA88(V_4CDA88 *d,V_4CDA88 *a,V_4CDA88 *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void sub_4CDA88(V_4CDA88 *d,V_4CDA88 *a,V_4CDA88 *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L08_004CDA88(void) {
    V_4CDA88 old,temp,temp2;
    float x,len,cap;
    *(vu0_q *)&old=*(vu0_q *)&D_001A4BE0.pos;
    func_L01_0050DB78(D_001A4BE0.ref538,&D_001A4BE0.extra,&D_001A4BE0.v90);
    if (D_001A4BE0.state==20 || D_001A4BE0.state==95 || D_001A4BE0.state==92 || D_001A4BE0.state==162 || D_001A4BE0.state==134) {
        if (!D_001A4BE0.h1f0) {
            x=func_L01_0050D430(&D_001A4BE0.velocity);
            cap=D_001A4BE0.speed_limit-0.02f;
            if (cap<x) func_L01_0050D5B0(&D_001A4BE0.velocity,&D_001A4BE0.velocity,cap);
        }
        x=func_L01_0050D4D8(&D_001A4BE0.velocity);
        if (x<0 && x < -D_001A4BE0.fall_limit) {
            cap=-D_001A4BE0.fall_limit-0.1f;
            if (x<cap) x=cap;
            if (x>0) x=0;
            func_L01_0050D530(&D_001A4BE0.velocity,&D_001A4BE0.velocity,x);
        }
        if (D_001A4BE0.state==20) {
            len=func_00388770(&D_001A4BE0.velocity);
            cap=D_001A4BE0.speed_limit-0.02f;
            if (cap<len) func_003886E8(&D_001A4BE0.velocity,&D_001A4BE0.velocity,cap/len);
        }
    } else if (D_001A4BE0.state!=68 && !D_001A4BE0.h1f0) {
        x=func_00388770(&D_001A4BE0.velocity);
        cap=D_001A4BE0.speed_limit-0.02f;
        if (cap<x) func_00388830(&D_001A4BE0.velocity,&D_001A4BE0.velocity,cap);
    }
    add_4CDA88(&D_001A4BE0.pos,&D_001A4BE0.pos,&D_001A4BE0.velocity);
    add_4CDA88(&D_001A4BE0.pos,&D_001A4BE0.pos,&D_001A4BE0.external);
    qzero(&D_001A4BE0.external);
    D_001A4BE0.b2a7=0;
    D_001A4BE0.clear28c=0;
    if (func_00388770(&D_001A4BE0.extra)<=0.0001f) {
        func_L01_004ECCD8();
        func_L08_004CC898();
        sub_4CDA88(&D_001A4BE0.step,&D_001A4BE0.pos,&old);
        func_L01_004EC500();
    } else func_L08_004CC898();
    sub_4CDA88(&D_001A4BE0.projected,&D_001A4BE0.pos,&old);
    *(vu0_q *)&D_001A4BE0.flat=*(vu0_q *)&D_001A4BE0.projected;
    *(vu0_q *)&D_001A4BE0.vertical=*(vu0_q *)&D_001A4BE0.projected;
    func_00388830(&D_001A4BE0.projected,&D_001A4BE0.projected,1);
    x=func_00388730(&D_001A4BE0.projected,&D_001A4BE0.velocity);
    if (x<0) x=0;
    func_00388830(&D_001A4BE0.projected,&D_001A4BE0.velocity,x);
    *(vu0_q *)&temp=*(vu0_q *)&D_001A4BE0.velocity;
    func_L01_0050D348(&temp,&temp);
    func_L01_0050D348(&D_001A4BE0.vertical,&D_001A4BE0.vertical);
    func_00388830(&D_001A4BE0.vertical,&D_001A4BE0.vertical,1);
    x=func_00388730(&D_001A4BE0.vertical,&temp);
    if (x<0) x=0;
    func_00388830(&D_001A4BE0.vertical,&temp,x);
    *(vu0_q *)&temp2=*(vu0_q *)&D_001A4BE0.velocity;
    func_L01_0050D5B0(&temp2,&temp2,0);
    func_L01_0050D5B0(&D_001A4BE0.flat,&D_001A4BE0.flat,0);
    func_00388830(&D_001A4BE0.flat,&D_001A4BE0.flat,1);
    x=func_00388730(&D_001A4BE0.flat,&temp2);
    if (x<0) x=0;
    func_00388830(&D_001A4BE0.flat,&temp2,x);
    D_001A4BE0.speed=func_00388770(&D_001A4BE0.projected);
    D_001A4BE0.hspeed=func_L01_0050D430(&D_001A4BE0.projected);
    *(vu0_q *)&temp=*(vu0_q *)&D_001A4BE0.projected;
    D_001A4BE0.vspeed=func_L01_004EC818(&temp);
    D_001A4BE0.vertical_speed=func_L01_0050D4D8(&D_001A4BE0.projected);
    if (D_001A4BE0.vspeed<0) D_001A4BE0.vspeed=0;
    *(vu0_q *)&temp=*(vu0_q *)&D_001A4BE0.pos;
    if (func_00388770(&D_001A4BE0.extra)>0.0001f) {
        add_4CDA88(&D_001A4BE0.pos,&D_001A4BE0.pos,&D_001A4BE0.extra);
        x=D_001A4BE0.extra.w;
        qzero(&D_001A4BE0.extra);
        D_001A4BE0.extra.w=x;
        func_L01_004ECCD8();
        func_L08_004CC898();
        sub_4CDA88(&D_001A4BE0.step,&D_001A4BE0.pos,&old);
        func_L01_004EC500();
    }
    sub_4CDA88(&D_001A4BE0.total,&D_001A4BE0.pos,&temp);
    D_001A4BE0.extra_speed=func_00388770(&D_001A4BE0.total);
    D_001A4BE0.total.w=D_001A4BE0.extra.w;
    D_001A4BE0.extra.w=0;
    sub_4CDA88(&D_001A4BE0.step,&D_001A4BE0.pos,&old);
    D_001A4BE0.ratio=0;
    if (D_001A4BE0.hspeed>0.004f) {
        D_001A4BE0.ratio=D_001A4BE0.step.z/D_001A4BE0.hspeed;
        if (D_001A4BE0.ratio>0.5f) D_001A4BE0.ratio=0.5f;
        else if (D_001A4BE0.ratio < -0.5f) D_001A4BE0.ratio=-0.5f;
    }
    if (D_001A4BE0.speed>0.8666667342185974f) {
        func_003886E8(&D_001A4BE0.step,&D_001A4BE0.step,0.8666667342185974f/D_001A4BE0.speed);
        D_001A4BE0.speed=0.8666667342185974f;
    }
}
/* localdecomp:end func_L08_004CDA88 */
