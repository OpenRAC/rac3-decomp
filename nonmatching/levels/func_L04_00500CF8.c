/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_004FCBA8, the NTSC-U twin of func_L04_00500CF8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/04_marcadia/L04_00500CF8.c's current line.
 * Worker's note: 595 diff; best log func_L04_004FCBA8.1.log; allowed flags emit lit4 loads versus inline retail constants; complete branch draft retained, register allocation and VU0 scheduling also differ
 */
#include "common.h"
/* localdecomp:start func_L04_004FCBA8 */
typedef int Q87b __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern int D_L04_001D673C[];
extern u8 D_L04_001E28C0[];
extern float D_L04_001DBCD8[];
extern void func_L01_004EAA78(int,float);
extern void func_L04_004FC178(float);
extern void func_L01_004EC780(float,float);
extern void func_003BEBF8(void *,float,float);
extern void func_L01_004EB350(float,float);
extern void func_L01_0050D5B0(void *,void *,float);
extern void func_L01_0050D1A0(void *,void *,float);
extern void func_L01_0050D530(void *,void *,float);
extern void func_L01_004EAFF8(int,float,float,float);
extern float func_00388730(void *,void *);
extern void func_003888C8(void *,void *,void *);
extern int func_L01_0045D358(int,int,int,int);
extern void func_L01_004EA5B0(void);
extern void func_00388880(void *,void *,float);
extern int func_003CE740(void *,void *,int,int,int);
extern float func_00388960(float);
extern float func_00388978(float);
extern float func_00389468(float,float);
extern void func_00388830(void *,void *,float);
extern float func_L01_004455F0(void *,void *,int,float,float,float,float);
extern float func_003893C8(float,float);
extern void func_L01_004E14C8(float,float,float);
extern float func_L01_0050D430(void *);
void func_L04_004FCBA8(void) {
    u8 *h=D_001A4BE0;
    float v[4] __attribute__((aligned(16)));
    float a[4] __attribute__((aligned(16))), b[4] __attribute__((aligned(16)));
    float c[4] __attribute__((aligned(16))), d[4] __attribute__((aligned(16)));
    float yaw,mag,old,turn,tmp;
    Q87b save;
    int blocked=0;
    if(*(int *)(h+0x25C4)==0xA2) {
        func_L01_004EAA78(0,0.16166667640209198f);
        *(float *)(h+0x1A0)=*(float *)(h+0x98);
        func_L04_004FC178(0.01944444514811039f);
        *(float *)(h+0x1B4)=*(float *)(h+0x174);
        return;
    }
    if(*(int *)(h+0x25C4)==10) {
        func_L01_004EC780(0.7f,0);
        *(Q87b *)(h+0x160)=*(Q87b *)(h+0x9E0);
        *(float *)(h+0x1B4)=*(float *)(h+0x174);
        return;
    }
    if(*(int *)(h+0x25C4)==16) {
        if(*(int *)(h+0x1B8)>=55)func_003BEBF8(h+0x4F0,0.0069444444961845875f,0.0019444444915279746f);
        *(float *)(h+0x1B0)=*(int *)(h+0x1B8)<55 ? *(float *)(h+0x424):0.05833333730697632f;
        func_L01_004EB350(0.012222222983837128f,0.0125f);
        func_L01_0050D5B0(h+0xF0,h+0xF0,0);
        func_L01_0050D1A0(h+0xF0,h+0xF0,*(float *)(h+0x1B4));
        return;
    }
    if(*(int *)(h+0x25C4)==27) {
        if(*(int *)(h+0x1B8)>=41) {
            func_L01_004EAFF8(0,0.04f,0.2f,0.25016388297080994f);
            func_L04_004FC178(0.0055555556900799274f);
        }
        if(*(float *)(h+0xC18)>=13 && *(float *)(h+0xC18)<=30) {
            if(*(float *)(h+0xC18)>27)func_003BEBF8(h+0x48C,0,0.002222222276031971f);
            else func_003BEBF8(h+0x48C,0.03333333507180214f,0.002222222276031971f);
        }
        goto rotate;
    }
    if(*(int *)(h+0x25C4)==72) {
        if(*(float *)(h+0xC18)>=5 && *(float *)(h+0xC18)<=18) {
            if(*(float *)(h+0xC18)>15)func_003BEBF8(h+0x48C,0,0.002222222276031971f);
            else func_003BEBF8(h+0x48C,0.02083333395421505f,0.002222222276031971f);
        }
    rotate:
        v[1]=0;
        v[0]=*(float *)(h+0x48C);
        v[2]=func_00388730(h+0xF0,h+0x20);
        func_003888C8(h+0xF0,v,h);
        return;
    }
    if(*(int *)(h+0x25C4)==11) {
        if(*(short *)(h+0x1434) || (*(int *)(h+0x16B0)==1 && func_L01_0045D358(40,2,0,0)))func_L01_004EA5B0();
        else {
            *(Q87b *)(h+0x190)=*(Q87b *)(h+0x450);
            *(float *)(h+0x1A0)=*(float *)(h+0x494);
            func_L01_004EAFF8(0,0.04f,0.2f,0.1163552924990654f);
        }
        *(float *)(h+0x1B4)=*(int *)(h+0x4A4)==3 ? 0:*(float *)(h+0x4A8);
        if(!D_L04_001D673C[0] && *(float *)(h+0x33C)<3 && *(int *)(h+0x1B8)>=14) {
            func_00388880(v,h+0x110,0.5699999928474426f);
            __asm__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(v), "r"(h+0x80) : "vf1", "vf2", "memory");
            v[2]=*(float *)(h+0x308);
            *(Q87b *)b=*(Q87b *)v;
            *(Q87b *)a=*(Q87b *)v;
            b[2]-=3;
            a[2]+=2;
            if(!func_003CE740(a,b,2,0,0)) {
                func_00388880(v,h+0x110,5.5f);
                __asm__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(v), "r"(h+0x80) : "vf1", "vf2", "memory");
                v[2]=*(float *)(h+0x308);
                *(Q87b *)d=*(Q87b *)v;
                *(Q87b *)c=*(Q87b *)v;
                d[2]-=3;
                c[2]+=2;
                if(!func_003CE740(c,d,2,0,0)) {
                    *(float *)(h+0x4AC)=0;
                    blocked=1;
                }
            }
        }
        if(h[0x4FD]) {
            if(!blocked) {
                mag=*(float *)(h+0x2838)*0.09166666865348816f;
                if(mag<0.03333333507180214f)mag=0.03333333507180214f;
                func_003BEBF8(h+0x4AC,mag,0.013055555522441864f);
                *(float *)(h+0x1B4)=*(float *)(h+0x174);
            }
        } else if(h[0x46E] && *(short *)(h+0x47E)<12)func_003BEBF8(h+0x4AC,0,0.002222222276031971f);
        else if(!blocked)func_003BEBF8(h+0x4AC,0.07f,0.002222222276031971f);
        if(!h[0x25F4]) {
            *(float *)(h+0xF0)=func_00388960(*(float *)(h+0x490))**(float *)(h+0x4AC);
            *(float *)(h+0xF4)=func_00388978(*(float *)(h+0x490))**(float *)(h+0x4AC);
        } else {
            func_L01_0050D5B0(v,h+0x440,*(float *)(h+0x4AC));
            func_L01_0050D530(v,v,0);
            func_L01_0050D5B0(h+0xF0,h+0xF0,0);
            __asm__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(h+0xF0), "r"(h+0xF0), "r"(v) : "vf1", "vf2", "memory");
        }
        if(!h[0x25F4] && !h[0x4FD]) {
            mag=*(float *)(h+0x4A8)*func_00388978(func_00389468(*(float *)(h+0x494),*(float *)(h+0x490)));
            *(float *)(h+0xF0)+=func_00388960(*(float *)(h+0x494))*mag;
            *(float *)(h+0xF4)+=func_00388978(*(float *)(h+0x494))*mag;
        }
        func_L01_004EC780(0.7f,0);
        *(Q87b *)(h+0x160)=*(Q87b *)(h+0x9E0);
        return;
    }
    if(*(int *)(h+0x25C4)==17) {
        *(float *)(h+0x1A0)=*(float *)(h+0x4CC);
        *(Q87b *)(h+0x190)=*(Q87b *)(h+0x4C0);
        if(*(int *)(h+0x1B8)>=10)func_L01_004EAFF8(-1,0.041999999433755875f,0.2f,0.19780398905277252f);
        if(*(int *)(h+0x1B8)>=9) {
            if(!*(short *)(h+0x368)) {
                *(float *)(h+0xF0)=func_00388960(*(float *)(h+0x1A0))*0.08166667073965073f;
                *(float *)(h+0xF4)=func_00388978(*(float *)(h+0x1A0))*0.08166667073965073f;
            } else {
                func_L01_0050D5B0(h+0xF0,h+0xF0,0);
                func_00388830(v,h+0x190,0.08166667073965073f);
                __asm__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(h+0xF0), "r"(h+0xF0), "r"(v) : "vf1", "vf2", "memory");
            }
        }
        *(float *)(h+0x1B4)=*(float *)(h+0x174);
        return;
    }
    if(*(int *)(h+0x25C4)==134 && !D_L04_001D673C[0]) {
        func_L01_004EAFF8(0,0.04f,0.2f,*(float *)(h+0x464));
        *(float *)(h+0x1B4)=0;
        return;
    }
    if(*(int *)(h+0x25C4)==44) {
        tmp=*(float *)(h+0x98);
        *(float *)(h+0x1A8)=func_L01_004455F0(&tmp,h+0x1A4,0,*(float *)(h+0x1A0),0.017999999225139618f,0.2f,0.12217305600643158f);
        func_L01_004E14C8(0,0,func_003893C8(tmp,*(float *)(h+0x98)));
    } else {
        save=*(Q87b *)(h+0x190);old=*(float *)(h+0x1A0);
        if(*(short *)(h+0x1434) || (*(int *)(h+0x16B0)==1 && func_L01_0045D358(40,2,0,0))) {
            *(Q87b *)(h+0x190)=*(Q87b *)(D_L04_001E28C0+0x380);
            *(float *)(h+0x1A0)=*(float *)(D_L04_001E28C0+0x18);
        }
        func_L01_004EAFF8(0,0.04f,0.2f,*(float *)(h+0x464));
        if(*(short *)(h+0x1434) || (*(int *)(h+0x16B0)==1 && func_L01_0045D358(40,2,0,0))) {
            *(float *)(h+0x1A0)=old;*(Q87b *)(h+0x190)=save;*(float *)(h+0x1438)=old;*(Q87b *)(h+0x1420)=save;
        }
    }
    func_L01_004EC780(0.7f,0);
    *(Q87b *)(h+0x160)=*(Q87b *)(h+0x9E0);
    turn=0.0055555556900799274f;
    if(*(float *)(h+0x1B0)<D_L04_001DBCD8[0]*(1.0f/60.0f)*0.2f) {
        if(*(int *)(h+0x25CC)==2) {
            mag=*(float *)(h+0xA04);
            tmp=func_L01_0050D430(h+0xF0);
            func_003BEBF8(&tmp,0,mag);
            func_L01_0050D5B0(h+0xF0,h+0xF0,tmp);
            return;
        }
        if(*(short *)(h+0x36A))turn=0.003055555745959282f;
        else if(*(short *)(h+0x4F4))turn=0.0005555555690079927f;
        else turn=0.002222222276031971f;
    }
    func_L04_004FC178(turn);
}
/* localdecomp:end func_L04_004FCBA8 */
