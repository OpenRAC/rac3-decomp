#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} G391938A;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G391938B;
typedef struct {
    u8 pad0[36];
    s32 unk24;
} V391938;
typedef struct {
    u8 pad0[104];
    V391938 *pVars;
} M391938;
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} V_003919E0;
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258;


/* localdecomp:start func_L01_00390508 */
#include "vu0.h"
typedef struct { vu0_q direction; f32 angle, speed; s32 life; void *owner; f32 scale; u8 pad[12]; } Particle_00391938;
extern Particle_00391938 D_L01_0029F020[];
void func_L01_00390508(u8 *m) {
    extern f32 func_L01_00440978(void);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_L01_004408C0(f32, f32);
    extern void func_L01_0040C0F0(void *, void *, f32);
    extern void func_L01_0040BF20(f32 *, f32 *, f32 *);
    vu0_v4 forward, position, end;
    vu0_v4 *pos = &position;
    u8 *v = *(u8 **)(m+0x68);
    Particle_00391938 *p;
    p=D_L01_0029F020;
    do {
        if(p->owner == 0) {
            p->owner=m;
            p->angle=func_L01_00440978();
            p->speed=func_L01_00440918(1200.0f,1400.0f)*0.017453292f*0.0166666675f;
            p->life=37;
            p->scale=func_L01_004408C0(0.3f,0.4f);
            func_L01_0040C0F0(&forward,*(u8 **)(v+0x18)+0xD0,1.0f);
            *(vu0_q *)&position=*(vu0_q *)(m+0x10);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(position), "m"(forward) : "vf1", "vf2");
            func_L01_0040BF20((f32 *)pos,(f32 *)pos,(f32 *)&end);
            func_L01_0040C0F0(p,pos,p->scale);
            break;
        }
        p++;
    } while ((s32)p < (s32)(D_L01_0029F020+12));
}
/* localdecomp:end func_L01_00390508 */
