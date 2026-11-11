/* func_L40_0040B1D0: near miss, 440 diff at level 40 (of 507 words; most are one register
   renumbering). 2028 bytes, 14 levels (40-53), src/levels/shared/L40_0040A4D0.c (flags
   -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). Written from asm
   (2026-11-11). The guber's network messages (called from func_L40_0040C6F0 as (uid, m)): it
   walks the guber's queue (guber +0x38, next at +0x84; header at msg+8: type, ?, time, subtype)
   and handles type 1 (subtype 0 target, 1 return point / velocity, 2 and 3 path node), 2 (killed:
   death, an explosion, the hero's lock released), 4 and 5 (ownership hand-over); then a Ranger in
   state 5 (off the map) comes back, and in states 2 and 3 it checks whether its target is in
   sight (func_003D3CB0).

   The instructions and blocks are retail's as far as checked; what is left is allocation:
   - ours hoists the constant 1 out of the message loop into a saved register (retail builds it
     at each use), so the uid parameter is spilled to the stack (frame 0x140, retail 0x130) and
     every saved register after it is renumbered (retail: $s0 temp, $s1 msg, $s2 header, $s3 pVar,
     $s4 m, $s5 guber, $s6 the net state, $s7 0x3064FF, $fp uid);
   - so the diff count says little about the rest; fix that first.
   Got here by: the early return of a Ranger already dying (pVar+0x3E 2), the net state
   D_001A5CD0 through a pointer (retail keeps its base in $s6: +0x128 time, +0x8 own client), four
   function-level vectors shared by case 1 and the sight check (retail's stack slots 0x90-0xC0),
   the 4-aligned message vectors as a plain struct (ldl/ldr copies), the explosion call as
   Veldin's func_L01_003E1DC0 makes it.
   Tried: the type dispatch as an if/else chain (493). Context: the file's prelude and earlier
   blocks (D_L40_0028FD80[], D_L40_002412DC[], D_001A5DF8[] and the message helpers are
   func_L40_0040ABB8's). */
#include "common.h"
#include "vu0.h"

extern s32 *D_L40_0028FD80[];
extern s32 D_L40_002412DC[] __attribute__((section(".sdata")));
extern s32 D_001A5DF8[];
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053E760(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
/* localdecomp:start func_L40_0040B1D0 */
__asm__(".extern D_L40_0024724C, 4");
__asm__(".extern D_L40_00247250, 4");
__asm__(".extern D_L40_00247254, 4");
__asm__(".extern D_L40_00247258, 4");
extern f32 D_L40_0024724C;
extern f32 D_L40_00247250;
extern f32 D_L40_00247254;
extern f32 D_L40_00247258;
typedef struct {
    f32 x, y, z, w;
} V4u_40B1D0; /* 4-aligned: copied with ldl/ldr */

extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
extern u8 D_001A5CD0[];  /* +0x8 this console's client, +0x128 the network time */
extern s32 D_001A5CD8[];
extern u8 *D_L40_0024846C[];
extern u8 *D_L40_0025B998[];
extern void func_L40_0040CD80(u8 *m);
extern void func_L40_0040CEF8(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L40_0053F6E0(u8 *m);
extern void func_L39_0066C470(s32 uid);
extern void func_L01_0045BD78(u8 *m, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_004450F0(u8 *m, s32 state, s32 a2);
extern f32 func_003C3D30(void *pos, s32 a1, s32 a2, f32 f);
extern u8 *func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_0061BFB0(s32 uid);
extern s32 func_L40_0053F018(u8 *m);
extern void func_L40_0053F038(u8 *m, s32 a1);
extern void func_L40_0053F068(u8 *m, s32 a1, s32 a2);
extern u8 *func_L39_0066C3C8(u8 *msg, void *list);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_0038CF68(void *d, void *s, f32 k);
extern s32 func_003D3CB0(void *a, void *b, s32 a2, u8 *m, s32 a4);

/* The guber's messages from the network: path, target and state (1), killed (2), and the
   ownership hand-over (4, 5); then the return of a Ranger that left the map (state 5), and in
   states 2 and 3 whether its target is in sight. */
void func_L40_0040B1D0(s32 uid, u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *g = *(u8 **)(m + 0x90);
    u8 *msg;
    s32 *h;
    u8 *ns;
    vu0_v4 a;
    vu0_v4 tg;
    vu0_v4 vel;
    vu0_v4 d;

    if (*(u8 *)(v + 0x3E) == 2) {
        func_L40_0040CD80(m);
        func_L39_0066C470(uid);
        func_L40_0053F6E0(m);
        return;
    }
    ns = D_001A5CD0;
    for (msg = *(u8 **)(g + 0x38); msg != 0; ) {
        h = (s32 *)(msg + 8);
        if (*(s32 *)(ns + 0x128) < h[2]) {
            msg = *(u8 **)(msg + 0x84);
            continue;
        }
        switch (h[0]) {
        case 1:
            switch (h[3]) {
            case 3:
                *(s32 *)(v + 0x340) = *(s32 *)(msg + 0x18);
                *(s32 *)(v + 0x290) = *(s32 *)(msg + 0x18);
                func_L40_0040CEF8(m, 9, 0, 0x11);
                func_L01_0045BD78(m, D_L40_00247258 * 0.000400000019f, D_L40_00247254 * 0.0200000014f, 0.0100530973f, 0.50265485f);
                if (*(s32 *)(m + 0x28) == 0 && m != D_L40_0024846C[0] && *(s32 *)(msg + 0x1C) != -1 && *(s32 *)(v + 0x2C8) != -1) {
                    f32 z = *(f32 *)(m + 0x18);

                    *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)((u8 *)D_L40_0028FD80[*(s32 *)(v + 0x2C8)] + 0x10 + *(s32 *)(msg + 0x1C) * 16);
                    if (D_L40_002412DC[0] == 0x2C || D_L40_002412DC[0] == 0x36 || D_L40_002412DC[0] == 0x28 || D_L40_002412DC[0] == 0x32) {
                        z += 8.0f;
                    } else {
                        z += 1.0f;
                    }
                    *(f32 *)(m + 0x18) = z;
                    *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
                }
                break;
            case 0:
                func_L01_0045BD78(m, 0.00360000017f, 0.120000005f, 0.0139626348f, 0.69813174f);
                *(s32 *)(v + 0x368) = *(s32 *)(msg + 0x18);
                func_L01_004450F0(m, 2, -1);
                if (*(s32 *)(v + 0x368) == -1) {
                    func_L01_0045BD78(m, D_L40_00247258 * 0.000400000019f, D_L40_00247254 * 0.0200000014f, 0.0139626348f, 0.69813174f);
                    func_L01_004450F0(m, 1, -1);
                }
                break;
            case 1: {
                *(V4u_40B1D0 *)&a = *(V4u_40B1D0 *)(msg + 0x18);
                vec_sub_ab(&d, v + 0x300, &a);
                tg = d;
                vel = d;
                *(vu0_v4 *)(v + 0x300) = a;
                *(V4u_40B1D0 *)(v + 0x390) = *(V4u_40B1D0 *)(msg + 0x28);
                *(V4u_40B1D0 *)(v + 0x380) = *(V4u_40B1D0 *)(msg + 0x38);
                *(s32 *)(v + 0x2C4) = *(s32 *)(msg + 0x48);
                if (!((f32)(*(s32 *)(ns + 0x128) - *(s32 *)(msg + 0x48)) > D_L40_0024724C)) {
                    *(u8 *)(m + 0x20) = 5;
                }
                break;
            }
            case 2:
                *(s32 *)(v + 0x290) = *(s32 *)(msg + 0x18);
                *(s32 *)(v + 0x340) = *(s32 *)(msg + 0x18);
                break;
            }
            break;
        case 2: {
            u8 *fx;
            u8 *q;

            func_L40_0040CD80(m);
            func_L40_0053F6E0(m);
            fx = func_L01_003303B8(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f,
                                   0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (fx != 0) {
                *(u8 **)(fx + 0xB8) = m;
            }
            if ((u32)*(s32 *)(v + 0x2AC) >> 28 == *(s32 *)(ns + 8)) {
                q = func_L39_0061BFB0(*(s32 *)(v + 0x2AC));
                if (q != 0) {
                    *(u8 *)(q + 0x1A11) = 0;
                }
            }
            return;
        }
        case 4:
            if (func_L40_0053F018(m) && *(u8 *)(v + 0x2D0) == 0) {
                u8 *out;
                u8 *p;

                *(u8 *)(v + 0x2D0) = 1;
                *(s32 *)(v + 0x378) = *(s32 *)(msg + 0x18);
                out = func_L39_0066C2B8();
                if (out == 0) {
                    return;
                }
                p = out + func_L39_0066C280(5, uid, *(s32 *)(ns + 0x128) + 500, h[3], out);
                *(s32 *)p = *(s32 *)(v + 0x378);
                p += 4;
                *(s32 *)out = p - out;
            }
            break;
        case 5:
            *(u8 *)(v + 0x2D0) = 1;
            if (h[3] == *(s32 *)(ns + 8)) {
                func_L40_0053F038(m, h[2]);
            } else {
                func_L40_0053F068(m, h[3], h[2]);
            }
            break;
        }
        msg = func_L39_0066C3C8(msg, g + 0x38);
    }
    if (*(u8 *)(m + 0x20) == 5 && (f32)(D_001A5DF8[0] - *(s32 *)(v + 0x2C4)) > D_L40_00247250) {
        func_L01_004450F0(m, 6, -1);
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(v + 0x300);
        *(vu0_v4 *)(m + 0xF0) = *(vu0_v4 *)(v + 0x390);
        *(vu0_v4 *)(v + 0x110) = *(vu0_v4 *)(v + 0x380);
        *(s32 *)(v + 0x12C) = D_L40_0024112C[0] - 1;
    }
    if ((u32)(*(u8 *)(m + 0x20) - 2) < 2) {
        vu0_v4 *pt;
        u8 *q;
        s32 ok;

        if (*(s32 *)(v + 0x368) == 0) {
            return;
        }
        if ((u32)*(s32 *)(v + 0x2AC) >> 28 == D_001A5CD8[0]) {
            q = func_L39_0061BFB0(*(s32 *)(v + 0x2AC));
            if (q != 0) {
                *(u8 *)(q + 0x1A11) = 0;
            }
        }
        if (*(s32 *)(v + 0x368) == -1) {
            func_L01_004450F0(m, 1, -1);
        }
        *(s16 *)(v + 0x234) = 0;
        *(s32 *)(v + 0x230) = func_L40_0053E760(*(s32 *)(v + 0x368), (vu0_v4 *)(v + 0x220), -1, 1);
        if (*(s32 *)(v + 0x230) == 0) {
            return;
        }
        ok = 1;
        a = *(vu0_v4 *)(m + 0x10);
        a.z += 1.0f;
        tg = *(vu0_v4 *)(v + 0x220);
        tg.z += 0.699999988f;
        pt = &tg;
        q = func_L39_0061BFB0(*(s32 *)(v + 0x368));
        if (q != 0 && *(s16 *)(q + 0x2D8) != 0) {
            vel = *(vu0_v4 *)(*(u8 **)(q + 0x2524) + 0xE0);
            func_0038CF68(&vel, &vel, 0.699999988f);
            tg.z -= 0.699999988f;
            vec_add_ab(&tg, &tg, &vel);
            pt = &tg;
        }
        if (func_L01_0040E548(&a, pt) < *(f32 *)(v + 0x2C0) * 4.0f * *(f32 *)(v + 0x2C0)) {
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            if (func_003D3CB0(&a, pt, 0x10, m, 0) != 0) {
                if (D_L40_0025B998[0] == 0 || D_L40_0025B998[0] != *(u8 **)(v + 0x230)) {
                    ok = 0;
                }
            }
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x10);
        } else {
            ok = 0;
        }
        if (ok == 1) {
            *(s16 *)(v + 0x234) = ok;
        }
    }
}
/* localdecomp:end func_L40_0040B1D0 */
