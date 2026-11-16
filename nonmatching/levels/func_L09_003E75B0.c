/* NTSC-U draft (Codex wave 3): C of func_L09_003E58D8, the NTSC-U twin of func_L09_003E75B0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 354 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L09_003E58D8", whose code is not the PAL one).
 * Worker's note: 354 diff; register allocation, constant hoisting and branch scheduling; best log func_L09_003E58D8.check-03.log; 7 compiles
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003E58D8 */
typedef int Q_3E58D8 __attribute__((mode(TI)));
extern unsigned char D_L09_001D9BA0[];
extern unsigned char *D_L09_001ED9C0[];
typedef struct { unsigned char pad[0x1DC]; short timer; } Hero_3E58D8;
extern Hero_3E58D8 D_001A4BE0;
extern Q_3E58D8 D_001A4C60[];
extern float func_00388730(void *, void *);
extern float func_00388A28(float, float);
extern float func_003893C8(float, float);
extern float func_00389380(float, float);
extern void func_L01_00449148(void *, void *, void *, void *, void *, int, float, float, float, float);
extern void func_003BF360(void *, void *);
extern void func_00388830(void *, void *, float);
extern void func_003886E8(void *, void *, float);
extern void func_L01_00443610(void *, void *, int, float);
extern int func_003CE740(void *, void *, int, void *, void *);
extern int func_003CF790(void *, int, void *, void *, float);
extern void func_L01_00443628(void *, void *, int, float, void *);
extern void func_L01_00443840(void *, void *);
extern void func_0039FE80(int, int, void *);
extern int func_L01_003F9498(void *, int, void *, float);
extern void func_L01_0032FE90(float, void *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, float, float, float);
extern void func_003BD360(void *);
extern void func_L09_003E60D0(void *);

void func_L09_003E58D8(unsigned char *m) {
    float old[4] __attribute__((aligned(16)));
    float hit[4] __attribute__((aligned(16)));
    float ball[8] __attribute__((aligned(16)));
    float impulse[4] __attribute__((aligned(16)));
    unsigned char *p = *(unsigned char **)(m + 0x68);
    float angle;
    int count, i;
    unsigned char **hits;
    unsigned char *vel;
    *(Q_3E58D8 *)old = *(Q_3E58D8 *)(m + 0x10);
    if (p[0x2F] == 0) {
        vel=m+0xC0;
        vec_sub_ba(hit, m + 0x10, p + 0x10);
        if (!p[0x2E] && func_00388730(vel, hit) < 0.0f) {
            angle = func_003893C8(func_00388A28(*(float *)(p+0x10)-*(float *)(m+0x10), *(float *)(p+0x14)-*(float *)(m+0x14)), *(float *)(m+0xF8));
            if (angle > 0.00872664712369442f) angle = 0.00872664712369442f;
            else if (angle < -0.00872664712369442f) angle = -0.00872664712369442f;
            *(float *)(m+0xF8)=func_00389380(*(float *)(m+0xF8),angle);
        }
    } else if (p[0x2F] == 1) {
        func_L01_00449148(m+0x10,m+0xC0,p+0x10,p+0x28,D_L09_001D9BA0,0,0.003f,0.003f,0.0f,0.0f);
        vel=m+0xC0;
        func_003BF360(m+0xC0,m+0xF0);
    } else {
        func_L01_00449148(m+0x10,m+0xC0,p+0x10,p+0x28,D_L09_001D9BA0,0,0.003f,0.003f,0.0f,7.0f);
        vel=m+0xC0;
        func_003BF360(m+0xC0,m+0xF0);
    }
    func_00388830(vel,vel,1.0f);
    func_003886E8(p,vel,*(float *)(p+0x24));
    vec_add_ab(m+0x10,p,m+0x10);
    if (p[0x2F] == 0) {
        func_L01_00443610(ball,m,p[0x2E]?0x1090001:0x1010001,(float)*(short *)(p+0x2C));
        if (func_003CE740(old,m+0x10,0,*(void **)(m+0xB8),ball) || func_003CF790(m+0x10,0,*(void **)(m+0xB8),ball,0.1f)) goto explode;
    } else {
        count=func_003CF790(m+0x10,1,m,0,1.0f);
        if(count) for(i=0,hits=D_L09_001ED9C0;i<count;i++,hits++) {
            if (*hits == *(unsigned char **)(p+0x20)) {
                if(p[0x2F]==2) func_003886E8(impulse,*(unsigned char **)(m+0xB8)+0xC0,10.0f);
                else func_003886E8(impulse,*(unsigned char **)(m+0xB8)+0xC0,4.0f);
                impulse[3]=5627.9248046875f;
                func_L01_00443628(hit,m,1,(float)*(short *)(p+0x2C),impulse);
                if(p[0x2F]==2) D_001A4BE0.timer=0;
                func_L01_00443840(*hits,hit);
                func_0039FE80(0,0,m);
                func_L01_0032FE90(0.8f,m+0x10,0,5,5,5,5,10,1,0,1,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0,0.0f,0.0f,2.0f);
                func_003BD360(m);
                return;
            }
        }
        if (func_003CE740(old,m+0x10,0,*(void **)(m+0xB8),0) || func_L01_003F9498(m+0x10,0,*(void **)(m+0xB8),0.1f)) {
            func_L01_00443610(hit,m,0x10000,(float)*(short *)(p+0x2C));
            func_003CF790(m+0x10,0,m,hit,1.7f);
explode:
            func_0039FE80(0,0,m);
            func_L01_0032FE90(0.8f,m+0x10,0,5,5,5,5,10,1,0,1,0,0,0,1,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0,0.0f,0.0f,2.0f);
            func_003BD360(m);
            return;
        }
    }
    if (*(unsigned char **)(p+0x20) && !*(short *)(*(unsigned char **)(p+0x20)+0xAA) && p[0x2F]==2) *(Q_3E58D8 *)(p+0x10)=D_001A4C60[0];
    func_L09_003E60D0(m);
}
/* localdecomp:end func_L09_003E58D8 */
