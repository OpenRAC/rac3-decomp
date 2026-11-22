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

/* localdecomp:start func_L01_00391EC8 */
#include "vu0.h"
typedef int Q_00391EC8 __attribute__((mode(TI)));
typedef struct {
    Q_00391EC8 pos, vel;
    f32 f20, f24, f28, f2C;
    s32 f30, f34, color, life, start;
    u8 *owner;
    s32 f48, f4C;
} Effect_00391EC8;
extern Effect_00391EC8 D_L01_0029F1E0_00391EC8[];
__asm__(".extern D_L01_001DDFF4, 4");
extern s32 D_L01_001DDFF4;
extern void func_L01_00392130_00391EC8(void *, f32, s32, s32, f32, s32, s32, f32);
void func_L01_00391EC8(u8 *owner) {
    Effect_00391EC8 *p = D_L01_0029F1E0_00391EC8;
    while (1) {
        if (p->owner == owner) {
            vu0_v4 pos;
            vec_add_ab(&pos, &p->pos, owner + 0x10);
            func_L01_00392130_00391EC8(&pos, p->f20, 0x7F7F7F, p->f34, p->f2C, D_L01_001DDFF4, 2, 0.001f);
            func_L01_00392130_00391EC8(&pos, p->f24, p->color, p->f34 >> 1, p->f2C, D_L01_001DDFF4, 2, 0.001f);
        }
        p++;
        if ((s32)p >= (s32)(D_L01_0029F1E0_00391EC8 + 128)) break;
    }
}
/* localdecomp:end func_L01_00391EC8 */
