/* func_L24_0034C088: 52 differences (level 24, file L24_0034A2C8.c, -mvu0-use-vf0-vf2 @ps2as). Sibling of the matched
   func_L24_0034BF38 (two 4-iteration loops with a separate pointer/counter set for the second). Frame (0xA0), VU0 add,
   calls and the compare match; what differs is the loop tail: retail keeps `n--`/`q++` at the loop end (q++ in the
   bgez delay slot) and turns `if (w[2] < f) w[2] = f` into bc1tl with the store in its delay slot, this C hoists
   `n--`/`q++` into the first jal's delay slot and gets bc1f. Tried: `f > w[2]`, `q++; n--;`, `while (--n >= 0)`. */
#include "common.h"
#include "vu0.h"
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L24_0034C088(u8 *obj) {
    u8 buf[0x50];
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    u8 *w;
    s32 *q;
    s32 n;
    s32 m;
    u8 *p2;
    u8 *w2;
    s32 *q2;
    f32 f;

    p = s + 0x250;
    w = s + 0x2E0;
    q = (s32 *)(s + 0x540);
    n = 3;
    do {
        func_003C2EC0((char *)q[0], 0, buf + 0x10);
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(w, buf, buf + 0x40);
        f = func_003C3D30(p, 2, 0, 0.5f) + 0.25f;
        if (*(f32 *)(w + 8) < f) {
            *(f32 *)(w + 8) = f;
        }
        p += 0x10;
        w += 0x10;
        n--;
        q++;
    } while (n >= 0);
    p2 = s + 0x380;
    w2 = s + 0x410;
    q2 = (s32 *)(s + 0x560);
    m = 3;
    do {
        func_003C2EC0((char *)q2[0], 0, buf + 0x10);
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(w2, buf, buf + 0x40);
        f = func_003C3D30(p2, 2, 0, 0.5f) + 0.25f;
        if (*(f32 *)(w2 + 8) < f) {
            *(f32 *)(w2 + 8) = f;
        }
        p2 += 0x10;
        w2 += 0x10;
        m--;
        q2++;
    } while (m >= 0);
}
