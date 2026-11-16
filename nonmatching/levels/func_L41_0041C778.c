/* PAL near miss (Codex wave 7): near miss: 28 words differ with the file's flags.
 * Worker's note: 28 diff after 10 variants; remaining packed constant-copy scheduling/registers and switch-global address register. Retained log build/codex/w371/C778-retained.log; detailed C778-04.log; retail switch table decoded in C778-switch.txt (cases 41/51,42/52,45/55).
 */
#include "common.h"
/* localdecomp:start func_L41_0041C778 */
typedef int Q_0041C778 __attribute__((mode(TI)));
typedef struct { u8 bytes[8]; } __attribute__((packed)) B8_0041C778;
typedef struct { f32 v[8]; } __attribute__((aligned(16))) B32_0041C778;
typedef struct { s32 index, other; u8 p8[8]; f32 health, max; s32 delay, ownArg, otherArg; } P_0041C778;
typedef struct { u8 p[0x10]; void *collision; } C_0041C778;
typedef struct { u8 p[0x10]; f32 pos[4]; u8 state; u8 p21[3]; C_0041C778 *cl; u8 p28[4]; f32 scale; u8 byte30; u8 p31; u16 distance,flags; u8 p36[0x32]; P_0041C778 *vars; u8 p6C[0x2C]; void *collision; u8 p9C[0xC]; u8 hit; u8 pA9[0x57]; } M_0041C778;
typedef struct { u8 p[0x2C]; f32 damage; } H_0041C778;
typedef struct { u8 p[0x20]; f32 scale; s32 p24, duration, timer; } F_0041C778;
extern M_0041C778 *D_001DCF4C_sda;
extern M_0041C778 *D_L41_0024865C;
extern u8 D_L41_00242930[] __attribute__((section(".sdata")));
extern B8_0041C778 D_L41_002477E8, D_L41_002477F0;
extern B32_0041C778 D_L41_00247800;
extern F_0041C778 D_L41_0024A100;
extern s32 D_001A5DF8[];
extern s32 D_L41_002412DC[];
void func_L41_0041C778(M_0041C778 *m) {
    extern void func_L41_0048B4B8(M_0041C778 *,s32);
    extern void func_L40_004897A8(M_0041C778 *,s32);
    extern H_0041C778 *func_L41_0041C1E8(M_0041C778 *);
    extern s32 func_L03_003FB6C8(void *,void *,s32);
    extern void func_L41_0041C568(M_0041C778 *);
    extern void func_L41_0041BAF8(void *,s32,u32,f32);
    extern void func_L41_0041C328(M_0041C778 *,s32);
    extern void func_L41_0041C170(M_0041C778 *,s32);
    extern s32 func_L41_0041C2E8(f32 *,f32);
    extern void func_L41_00491978(M_0041C778 *,void *,void *,void *,s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_004398C8(M_0041C778 *,s32,f32 *);
    extern void func_L41_0041B9C8(f32 *,s32,f32,f32,f32);
    extern void func_L01_00439880(M_0041C778 *,s32 *,s32 *);
    extern void func_L40_004C5C78(s32,s32,M_0041C778 *,s32);
    extern void func_003C2880(M_0041C778 *);
    B8_0041C778 b1,b2;
    B32_0041C778 b3;
    f32 pos[4] __attribute__((aligned(16)));
    s32 n1,n2;
    P_0041C778 *p=m->vars;
    M_0041C778 *other;
    H_0041C778 *hit;
    s32 dead, sound;
    f32 old,low,mid;
    if(m->state==0) {
        p->delay=0;
        p->index=-1;
        m->state=1;
        m->byte30=255;
        m->distance=255;
        if(p->other>=0) {
            M_0041C778 *initOther;
            initOther=&D_001DCF4C_sda[p->other];
            initOther->distance=255;
            initOther->flags |=0x4041;
            func_L41_0048B4B8(initOther,p->otherArg);
        }
        m->collision=0;
        m->flags |=0x41;
        func_L40_004897A8(m,p->ownArg);
        p->max=p->health;
    }
    if(m->state==1) {
        if(p->index==-1) {
            dead=0;
            if(p->other>=0) {
                other=&D_L41_0024865C[p->other];
                hit=func_L41_0041C1E8(other);
                if(p->delay>0)p->delay--;
                if(hit && p->delay==0) {
                    p->delay=25;
                    if(!func_L03_003FB6C8(D_L41_00242930,hit,16)) {
                        if(hit->damage>=8.0f)func_L41_0041C568(m);
                        func_L41_0041BAF8(hit,20,0x80555E6A,1.0f);
                    }
                    old=p->health;
                    mid=p->max*0.6f;
                    low=p->max*0.3f;
                    p->health=old-hit->damage;
                    if(old>mid && p->health<=mid)func_L41_0041C328(m,500);
                    if(old>low && p->health<=low)func_L41_0041C328(m,500);
                    if(p->health<=0.0f) {p->health=0.0f;dead=1;}
                }
                other->hit=255;
            }
            if(dead) {
                func_L41_0041C170(m,250);
                func_L41_0041C328(m,500);
                func_L41_0041C328(m,1000);
            }
        }
        if(p->index>=0 && p->index<D_001A5DF8[0] && p->other>=0) {
            other=&D_001DCF4C_sda[p->other];
            if(func_L41_0041C2E8(m->pos,64.0f)) {
                b3=D_L41_00247800;
                b2=D_L41_002477F0;
                b1=D_L41_002477E8;
                func_L41_00491978(other,&b3,&b2,&b1,65535,-1,-1,1,65535,255,0);
                func_L01_004398C8(other,0,pos);
                func_L41_0041B9C8(pos,5,1.0f,6.0f,12.0f);
                func_L41_0041BAF8(pos,20,0x80555E6A,1.5f);
                func_L01_00439880(m,&n1,&n2);
                if(n2>=2) {
                    func_L01_004398C8(other,1,pos);
                    func_L41_0041BAF8(pos,25,0x80555E6A,2.0f);
                }
                if(n2>=5) {
                    func_L01_004398C8(other,4,pos);
                    func_L41_0041B9C8(pos,5,1.0f,8.0f,12.0f);
                    func_L41_0041BAF8(pos,20,0x80555E6A,1.5f);
                }
                if(n2>=8) {
                    func_L01_004398C8(other,7,pos);
                    func_L41_0041B9C8(pos,5,1.0f,6.0f,12.0f);
                    func_L41_0041BAF8(pos,20,0x80555E6A,1.5f);
                }
                D_L41_0024A100.scale=0.15f;
                D_L41_0024A100.duration=50;
                D_L41_0024A100.timer=0;
            }
            sound=-1;
            switch(D_L41_002412DC[0]) {
                case 41:case 51:sound=19;break;
                case 42:case 52:sound=18;break;
                case 45:case 55:sound=17;break;
            }
            if(sound!=-1)func_L40_004C5C78(sound,0,m,0);
            m->state=2;
            func_L41_0048B4B8(m,p->ownArg);
            if(p->other>=0)func_L40_004897A8(&D_001DCF4C_sda[p->other],p->otherArg);
            m->collision=m->cl->collision;
            func_003C2880(other);
        }
    }
}
/* localdecomp:end func_L41_0041C778 */
