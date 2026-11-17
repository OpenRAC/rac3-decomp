#include "common.h"

/* localdecomp:start func_L39_0069E5C0 */
extern u8 D_L39_0047D310[];
extern u8 D_L39_002483F0[];
extern f32 D_001DCCB8_sda;
extern f32 D_001DCCBC_sda;
extern f32 D_001DCCC0_sda;
extern f32 D_001DCCC4_sda;
extern f32 D_001DCCC8_sda;
__asm__(".extern D_001DCCB8_sda, 4");
__asm__(".extern D_001DCCBC_sda, 4");
__asm__(".extern D_001DCCC0_sda, 4");
__asm__(".extern D_001DCCC4_sda, 4");
__asm__(".extern D_001DCCC8_sda, 4");
void func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_L39_00689670(void *, void *);

typedef struct E_0069E5C0 {
    s32 kind;
    u8 name[0x34];
    f32 x38;
    f32 x3C;
    f32 x40;
    f32 x44;
    s32 x48;
    s32 x4C;
} E_0069E5C0;

typedef struct D_0069E5C0 {
    E_0069E5C0 e;
    E_0069E5C0 *a;
    E_0069E5C0 *b;
    u8 pad[0x178];
} D_0069E5C0;

static __inline__ void H_0069E5C0(void *it, s32 name, f32 x, f32 y, f32 w, f32 h)
{
    *(s32 *)it = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
}

void *func_L39_0069E5C0(u8 *p) {
    E_0069E5C0 e0;
    E_0069E5C0 e1;
    D_0069E5C0 d;
    E_0069E5C0 *pb;
    D_0069E5C0 *pc;
    f32 half = 0.5f;

    func_L39_00688388(p);
    {
        f32 x = D_001DCCB8_sda;
        f32 y = D_001DCCBC_sda + (D_001DCCC4_sda - D_001DCCC8_sda) * -0.5f * half;
        f32 w = D_001DCCC0_sda - (D_001DCCC8_sda + D_001DCCC8_sda);
        *(void **)(p + 0x60) = D_L39_0047D310;
        *(void **)(p + 0x2A4) = p + 0x2B0;
        H_0069E5C0(&e0, (s32)D_L39_002483F0, x, y, w, 0.05f);
    }
    e0.kind = 1;
    pb = &e1;
    H_0069E5C0(pb, (s32)D_L39_002483F0, D_001DCCB8_sda,
                      D_001DCCBC_sda + (D_001DCCC4_sda - D_001DCCC8_sda) * half * half,
                      D_001DCCC0_sda - (D_001DCCC8_sda + D_001DCCC8_sda), 0.05f);
    e1.kind = 1;
    pc = &d;
    H_0069E5C0(&pc->e, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pc->e.x48 = 0x2E;
    d.e.x4C = 0;
    d.e.x38 = 0;
    d.e.x3C = 0;
    pc->e.x40 = 1.0f;
    pc->e.x44 = 1.0f;
    d.b = pb;
    d.e.x4C = 2;
    d.a = &e0;
    func_L39_00689670(p, pc);
    return p;
}
/* localdecomp:end func_L39_0069E5C0 */
