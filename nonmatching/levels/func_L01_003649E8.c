/* PAL near miss (Codex wave 8): near miss: 99 words differ with the file's flags.
 * Worker's note: 101 diff in w386/func_L01_003649E8.07.log; 8 checks; remaining state-base allocation, VU sequence/store scheduling, vector-init and clear-loop differences. Future State_00366240 typedef copied exactly for snippet; integration must reuse its existing ...
 */
#include "common.h"
/* localdecomp:start func_L01_003649E8 */
#include "vu0.h"
__asm__(".extern D_001DD774_sda, 4");
__asm__(".extern D_001DD778_sda, 4");
__asm__(".extern D_001DD784_sda, 4");
__asm__(".extern D_001DD788_sda, 4");
__asm__(".extern D_001DD78C_sda, 4");

typedef int Q_003649E8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003649E8;
typedef struct {
    u8 pad[0x1200];
    u8 *p1200;
    u8 pad2[0x24];
    s32 mode1228;
} State_00366240;
extern State_00366240 D_001A4BE0;
extern s16 D_L01_001E1B10;
extern s32 D_001DD774_sda;
extern s32 D_001DD778_sda;
extern f32 D_001DD784_sda;
extern s32 D_001DD788_sda;
extern s32 D_001DD78C_sda;
extern f32 D_L01_001E1AE4[];
extern f32 D_L01_001E1AE0;
extern Q_003649E8 D_L01_001E29E0[3];
extern Q_003649E8 D_L01_0028E3A0[10];
extern Q_003649E8 D_L01_001E1AC0;
extern Q_003649E8 D_L01_001E1AD0;
extern u8 D_L01_0028CAA0[];
void func_L01_003649E8(u8 *obj, Q_003649E8 *pos) {
    extern void func_0038CE20(Q_003649E8 *, Q_003649E8 *, f32);
    extern void func_0038CF68(Q_003649E8 *, Q_003649E8 *, f32);
    extern f32 func_00382538(void);
    extern void func_0038D890(Q_003649E8 *, Q_003649E8 *, Q_003649E8 *, f32);
    Q_003649E8 basis[3];
    V_003649E8 step, forward, a, b;
    f32 r;
    s32 i;
    u8 *state;
    if (!D_001DD774_sda) return;
    state = (u8 *)&D_001A4BE0;
    D_L01_001E1AE4[0] = 1.0f;
    D_001DD774_sda = 0;
    if ((*(s32 *)(state+0x25c4)==29 || *(s32 *)(state+0x25c4)==1) &&
        (*(u16 *)(*(u8 **)(state+0x25c0)+0x34) & 1)) {
        basis[0]=D_L01_001E29E0[0];
        basis[1]=D_L01_001E29E0[1];
        basis[2]=D_L01_001E29E0[2];
    } else if (*(s16 *)((u8 *)&D_001A4BE0+0x2874)==1) {
        func_0038CE20(basis,(Q_003649E8 *)(obj+0xd0),-1.0f);
        { Q_003649E8 c=*(Q_003649E8 *)(obj+0xe0); Q_003649E8 d=*(Q_003649E8 *)(obj+0xc0); basis[2]=c; basis[1]=d; }
    } else {
        basis[0]=*(Q_003649E8 *)(state+0x6c0);
        basis[1]=*(Q_003649E8 *)(state+0x6d0);
        basis[2]=*(Q_003649E8 *)(state+0x6e0);
    }
    func_0038CF68((Q_003649E8 *)&step,basis,D_L01_001E1AE4[0]);
    func_0038CF68((Q_003649E8 *)&forward,&basis[2],1.0f);
    D_L01_0028E3A0[0]=*pos;
    D_L01_001E1B10=0;
    { Q_003649E8 *p=&D_L01_0028E3A0[1]; s16 *h=&D_L01_001E1B10+1;
    for (i=8;i>=0;i--,p++,h++) {
        *h=0;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*p)
            : "m"(p[-1]), "m"(step)
            : "vf1", "vf2");
    }
    }
    *(Q_003649E8 *)&a=0;
    *(Q_003649E8 *)&b=0;
    a.z=0.1f;
    a.w=1.0f;
    b.x=1.0f;
    b.w=1.0f;
    qzero(&D_L01_001E1AC0);
    r=func_00382538();
    func_0038D890(&D_L01_001E1AD0,(Q_003649E8 *)&a,(Q_003649E8 *)&b,r);
    D_L01_001E1AE0=r;
    D_001DD784_sda=0.006f;
    D_001DD788_sda=0;
    D_001DD78C_sda=0;
    if (D_001DD778_sda) {
        D_001DD778_sda=0;
        for(i=0;i<200;i++) {
            *(s32 *)(D_L01_0028CAA0+i*32+28)=0;
            *(s32 *)(D_L01_0028CAA0+i*32+12)=0;
        }
    }
}
/* localdecomp:end func_L01_003649E8 */
