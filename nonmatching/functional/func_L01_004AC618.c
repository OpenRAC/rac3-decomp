/* functional: medium. Read against the asm. The retail stack block at sp+0x10..0xB0 is one struct passed to func_003D2DA0 by &corner (callee reads colours, GIF-style packet header and direction behind the corners), so it is one struct here too (Quad_004AC618); vadd.xyz as float adds with w kept; D_001D6694_sda is the gp slot (gp 0x1DC8B0-0x621C). func_00389598(0) result stored into the packet as retail does; callee meanings of func_0038CE50/CE20/0040F6E8 unconfirmed (assumed (out, obj, scale)). */
#include "vu0.h"
extern s32 D_001D673C;
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern u8 D_0016C580[];
extern u8 D_L01_001D9940[];
extern u8 D_L01_001D9960[];
extern void func_0038CE50(void *, void *, f32);
extern s32 func_L01_0040F6E8(void *, void *, f32);
extern s64 func_00389598(s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

/* one block on retail's stack: the callee gets &corner and reads the colours, packet and direction behind it */
typedef struct {
    vu0_v4 corner[4];
    s32 color[4];
    u8 pkt[0x40];
    vu0_v4 dir;
    s32 alpha;
} Quad_004AC618;

void func_L01_004AC618(u8 *a0) {
    Quad_004AC618 q;
    vu0_v4 head;
    s32 i;
    s32 h;
    f32 z;
    vu0_v4 *c;
    u8 *t;
    u8 *pkt = q.pkt;

    if (D_001D673C != 0) {
        return;
    }
    q.alpha = 0;
    func_0038CE50(&head, a0, 0.0009765625f);
    if (func_L01_0040F6E8(&head, &q.alpha, 32.0f) < 0) {
        return;
    }
    if (D_001D6694_sda == 6 && *(s16 *)(D_0016C580 + 0x20) == 1) {
        h = *(s16 *)(D_0016C580 + 0x22);
        if (h >= 0x7E) {
            q.alpha = q.alpha - h;
            if (q.alpha <= 0) {
                return;
            }
        }
    }
    *(s64 *)(pkt + 0x20 + 0x00) = 0;
    *(s64 *)(pkt + 0x20 + 0x08) = func_00389598(0);
    *(s64 *)(pkt + 0x20 + 0x10) = ((s64)0xFF90 << 32) | 0x260;
    *(s64 *)(pkt + 0x20 + 0x18) = ((s64)0x8000 << 24) | 0x44;
    func_0038CD28(pkt, D_L01_001D9940, 0x20);
    func_0038CE20(&q.dir, a0, 0.0009765625f);
    z = *(f32 *)(a0 + 0x18) + 0.1f;
    if (D_001D6694_sda == 6 || D_001D6694_sda == 0 || D_001D6694_sda == 4) {
        z = func_003C3D30(a0 + 0x10, 0, 0, 0.5f) + 0.1f;
    }
    t = D_L01_001D9960;
    for (i = 0, c = q.corner; i < 4; i++, c++, t += 16) {
        q.color[i] = ((q.alpha >> 1) << 24) | 0x808080;
        func_0038D000(c, t, a0 + 0xC0);
        c->x = c->x + *(f32 *)(a0 + 0x10);
        c->y = c->y + *(f32 *)(a0 + 0x14);
        c->z = c->z + *(f32 *)(a0 + 0x18);
        c->z = z;
    }
    func_003D2DA0(q.corner, 0, 0);
}
