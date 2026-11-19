/* functional: high. Instruction stream equal after masking regs apart from flag select; needs vu0 flag line. */
#include "vu0.h"
typedef struct { u8 pad[0x140]; f32 x, y; } Hero_0051DD30;
extern vu0_v4 D_L39_0025F770;
extern u8 D_L39_004997E0[];
extern Hero_0051DD30 D_L39_0024DCC0;
extern s32 D_L39_0024D490;
extern f32 func_L01_00446E38(void *, void *, s32, void *, f32);
extern void func_L39_00628760(void *);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00628038(void *, s32);
extern u8 *func_00382348(s32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, f32, s32);
extern void func_L39_005D2930(void *, void *, s32);
extern void func_L39_0051E268(void *);
extern void func_003C2880(void *);

/* Multiplayer-menu level: death/despawn of a pickup-like object that is tied to a player slot
 * (vars+0x9C). Updates the owning player's spawn point (with a ground test), on `die` notifies the
 * player, otherwise runs the player-ownership check; then sprays two kinds of particles (counts
 * reduced by the current effect load D_L39_0024D490) and deletes the object. */
void func_L39_0051DD30(void *mv, s32 die, s32 unused) {
    u8 *m = mv;
    union { vu0_v4 tmp; s32 buf[2]; } work;
    vu0_v4 pos;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *g = (u8 *)D_L39_0024CE20[*(s32 *)(v + 0x9C)];
    s32 i;
    f32 a, b, c, angle;

    if (g) {
        *(s32 *)(g + 0x2458) = 0;
        if (g[0x1A14]) {
            pos = *(vu0_v4 *)(m + 0x10);
            work.tmp = *(vu0_v4 *)(m + 0x10);
            pos.z += 2.0f;
            if (func_L01_00446E38(&pos, &work.tmp, 0, m, *(f32 *)(g + 0x1F4)) < 1.0f) {
                *(vu0_v4 *)(m + 0x10) = D_L39_0025F770;
            }
            *(vu0_v4 *)(g + 0xA0) = *(vu0_v4 *)(m + 0x10);
            *(vu0_v4 *)(g + 0xB0) = *(vu0_v4 *)(m + 0xF0);
        }
        if (die) {
            u8 *o;
            func_L39_00628760(g);
            o = func_00382348(*(s32 *)(g + 0x2524));
            if (o) {
                o[0xE] = 1;
            }
            if (g[0x1A14]) {
                g[0x1A0A] = 1;
                func_L39_00637EC8(g, m + 0x10, m + 0xF0, 0, 1, 1, 0);
            }
        } else {
            s32 flag = 0;
            u8 *source = *(u8 **)(g + 0x2530);
            if (source && source[0x27B]) {
                u8 *p = g + 0x19E4;
                s32 x = 0;
                s32 t = *p;
                if (t) {
                    s32 n = *p;
                    s32 k = ((s32)p - n) & 7;
                    s32 j;
                    s32 base = n + 1;
                    u8 *d = (u8 *)work.buf;
                    for (j = 0; j < 40; j += 5) {
                        *d++ = D_L39_004997E0[base + ((k + j) & 7) * 255];
                    }
                    work.buf[0] ^= (s32)p;
                    work.buf[1] ^= work.buf[0];
                    x = work.buf[1];
                }
                if ((x ^ 0x31) == 0) {
                    flag = 1;
                }
            }
            if ((u8)flag) {
                *(vu0_v4 *)(g + 0xA0) = *(vu0_v4 *)(m + 0x10);
                *(vu0_v4 *)(g + 0xB0) = *(vu0_v4 *)(m + 0xF0);
                func_L39_00628038(g, 0);
                ((void (*)(void *, s32, s32, s32, s32)) * (void **)(*(u8 **)(g + 0x14) + 0x34))(g, 0x76, 0, 1, 0);
                if (!g[0x1A14]) {
                    g[0x1A0A] = 2;
                }
            }
        }
    }
    for (i = 0; i < 33 - D_L39_0024D490; i++) {
        a = func_L39_005B4410(0.0f, 0.3700000047683716f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&pos, a, b, c);
        pos.z += func_L39_005B4410(0.3499999940395355f, 0.6000000238418579f);
        vec_add_ba(&pos, &pos, m + 0x10);
        a = func_L39_005B4410(0.0020000000949949026f, 0.020000001415610313f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&work.tmp, a, b, c);
        func_L39_005C8CA8(&pos, &work.tmp, 0x4F20507F, 0x102F, 150000.0f, func_L39_005B43C8(25, 47));
    }
    for (i = 0; i < 50 - D_L39_0024D490; i++) {
        angle = func_0038D160(D_L39_0024DCC0.x - *(f32 *)(m + 0x10), D_L39_0024DCC0.y - *(f32 *)(m + 0x14));
        func_L39_005B4468(1.0f, 2.0f);
        work.tmp.x = *(f32 *)(m + 0x10) + func_L39_005B4468(0.0f, 0.15000000596046448f);
        work.tmp.y = *(f32 *)(m + 0x14) + func_L39_005B4468(0.0f, 0.15000000596046448f);
        work.tmp.z = *(f32 *)(m + 0x18) + func_L39_005B4468(0.0f, 0.15000000596046448f);
        angle = func_0038DAB8(angle, func_L39_005B4468(0.0f, -1.5707963705062866f));
        pos.x = func_0038D098(angle) * 0.1600000113248825f;
        pos.y = func_0038D0B0(angle) * 0.1600000113248825f;
        pos.z = 0.18000000715255737f;
        func_L39_005D2930(&work.tmp, &pos, 250);
    }
    func_L39_0051E268(m);
    func_003C2880(m);
}
