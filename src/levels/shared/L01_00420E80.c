#include "common.h"

/* localdecomp:start func_L01_00420E80 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 D_L01_001E1068;
__asm__(".extern D_L01_001E1068, 16");
extern u8 D_L01_001DA170[];
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_L01_001DFD0C;
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");
__asm__(".extern D_L01_001DFD0C, 16");

void func_L01_00420E80(s32 u, s32 v, long tex, s32 flag, s32 *q, f32 x, f32 y, f32 w, f32 h, f32 angle) {
    vu0_v4 a, b, c, p2, p3, p1, p4, z;
    u8 *p, *r;
    s32 t0, t1;

    c.x = x;
    c.y = y;
    a.x = h * func_0038D0B0(angle);
    a.y = h * func_0038D098(angle);
    b.x = -w * func_0038D098(angle);
    b.y = w * func_0038D0B0(angle);
    if (flag != 0) {
        *(vu0_q *)&z = 0;
        vec_add_ab(&p1, &c, &a);
        vec_add_ab(&p1, &p1, &z);
        vec_sub_ab(&p2, &c, &a);
        vec_add_ab(&p2, &p2, &z);
        vec_sub_ab(&p3, &c, &a);
        vec_sub_ab(&p3, &p3, &b);
        vec_add_ab(&p4, &c, &a);
        vec_sub_ab(&p4, &p4, &b);
    } else {
        vec_add_ab(&p4, &c, &a);
        vec_sub_ab(&p4, &p4, &b);
        vec_add_ab(&p1, &c, &a);
        vec_add_ab(&p1, &p1, &b);
        vec_sub_ab(&p3, &c, &a);
        vec_sub_ab(&p3, &p3, &b);
        vec_sub_ab(&p2, &c, &a);
        vec_add_ab(&p2, &p2, &b);
    }
    *(s32 *)(D_L01_001E1068 + 0) = 0x10000008;
    *(s32 *)(D_L01_001E1068 + 4) = 0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000008;
    p = (u8 *)D_L01_001E1068 + 0x10;
    D_L01_001E1068 = (s32)p;
    *(u128_t *)p = *(u128_t *)D_L01_001DA170;
    r = (u8 *)D_L01_001E1068 + 0x10;
    D_L01_001E1068 = (s32)r;
    t0 = u << 4;
    t1 = v << 20;
    *(long *)(r + 0x00) = tex;
    *(long *)(r + 0x08) = 0x15C;
    *(long *)(r + 0x10) = q[0];
    *(long *)(r + 0x18) = 0;
    *(long *)(r + 0x20) = ((s32)p2.x + D_001D4BD0 - 8) | ((long)((s32)p2.y + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    *(long *)(r + 0x28) = q[1];
    *(long *)(r + 0x30) = t0;
    *(long *)(r + 0x38) = ((s32)p3.x + D_001D4BD0 - 8) | ((long)((s32)p3.y + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    *(long *)(r + 0x40) = q[2];
    *(long *)(r + 0x48) = t1;
    *(long *)(r + 0x50) = ((s32)p1.x + D_001D4BD0 - 8) | ((long)((s32)p1.y + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    *(long *)(r + 0x58) = q[3];
    *(long *)(r + 0x60) = t1 + t0;
    *(long *)(r + 0x68) = ((s32)p4.x + D_001D4BD0 - 8) | ((long)((s32)p4.y + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    D_L01_001E1068 = D_L01_001E1068 + 0x70;
}
/* localdecomp:end func_L01_00420E80 */
