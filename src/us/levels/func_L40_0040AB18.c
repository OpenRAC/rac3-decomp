#include "common.h"

/* NTSC-U counterpart of func_L40_0040B1D0 (src/levels/shared/L40_0040A4D0.c): 17 -> 20; 0.0004 -> 0.000277778; 0.02 -> 0.0166667; 0.0100531 -> 0.00698132; 0.502655 -> 0.418879; 0.0036 -> 0.0025; 0.12 -> 0.1; 0.0139626 -> 0.00969627; 0.698132 -> 0.581776 */
#include "vu0.h"
extern s32 D_001A5F78[];
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8*msg);
extern u8*func_L39_006699B0(void);
extern f32 func_003BE7F0(void *pos, s32 a1, s32 a2, f32 f);
extern s32 D_L40_0024145C[] __attribute__((section(".sdata")));
extern s32 *D_L40_0028FF00[];
extern s32 D_001A5F78[];
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053BEB0(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
extern f32 D_L40_002473D0;
extern s32 D_001A5F78[];
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);

/* localdecomp:start func_L40_0040AB18 */
#include "vu0.h"

extern s32 *D_L40_0028FF00[];
extern s32 D_L40_0024145C[] __attribute__((section(".sdata")));
extern s32 D_001A5F78[];
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053BEB0(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
__asm__(".extern D_L40_002473CC, 4");
__asm__(".extern D_L40_002473D0, 4");
__asm__(".extern D_L40_002473D4, 4");
__asm__(".extern D_L40_002473D8, 4");
extern f32 D_L40_002473CC;
extern f32 D_L40_002473D0;
extern f32 D_L40_002473D4;
extern f32 D_L40_002473D8;
typedef struct {
    f32 x, y, z, w;
} V4u_40B1D0; /* 4-aligned: copied with ldl/ldr */

extern s32 D_L40_002412AC[] __attribute__((section(".sdata")));
typedef struct { u8 pad[0x2C4]; s32 f2C4; } V_0040B1D0; /* the guber's pVar (a struct store: the f32 global load may pass it) */
typedef struct { u8 pad0[8]; s32 client; u8 padC[0x128 - 0xC]; s32 time; } G_0040B1D0; /* the net state: this console's client, the network time */
extern G_0040B1D0 D_001A5E50;
extern u8 *D_L40_002485EC; /* the local hero's moby; no early .extern: ps2as expands lw into lui/lw on one register */
extern u8 *D_L40_0025BB18[];
extern void func_L40_0040C6B0(u8 *m);
extern void func_L40_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L40_0053CE30();
extern void func_L39_00669B68(s32 uid);
extern void func_L01_00458A70(u8 *m, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_00441FB8(u8 *m, s32 state, s32 a2);
extern f32 func_003BE7F0(void *pos, s32 a1, s32 a2, f32 f);
extern u8 *func_L01_0032FE90_0040AB18(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_00619838(u32);
extern s32 func_L40_0053C768(u8 *m);
extern void func_L40_0053C788(u8 *m, s32 a1);
extern void func_L40_0053C7B8(u8 *m, s32 a1, s32 a2);
extern u8 *func_L39_00669AC0(u8 *msg, void *list);
extern f32 func_L01_0040C018(void *a, void *b);
extern void func_00388830(void *d, void *s, f32 k);
extern s32 func_003CE740(void *a, void *b, s32 a2, u8 *m, s32 a4);

/* whether a message type belongs to an ownership hand-over (4 asks the owner, 5 names the new one) */
static __inline__ u8 handover_0040B1D0(s32 type) {
    return type == 4 || type == 5;
}

/* The guber's messages from the network: path, target and state (1), killed (2), and the
   ownership hand-over (4, 5); then the return of a Ranger that left the map (state 5), and in
   states 2 and 3 whether its target is in sight. */
void func_L40_0040AB18(s32 uid, u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *g = *(u8 **)(m + 0x90);
    u8 *msg;
    s32 *h;
    s32 type;
    vu0_v4 a;
    vu0_v4 tg;
    vu0_v4 vel;
    vu0_v4 d;

    if (*(u8 *)(v + 0x3E) == 2) {
        func_L40_0040C6B0(m);
        func_L39_00669B68(uid);
        func_L40_0053CE30(m);
        return;
    }
    msg = *(u8 **)(g + 0x38);
    while (msg != 0) {
        h = (s32 *)(msg + 8);
        if (D_001A5E50.time < h[2]) {
            msg = *(u8 **)(msg + 0x84);
            continue;
        }
        type = *(s32 *)(msg + 8);
        switch (type) {
        case 1:
            switch (h[3]) {
            case 3:
                *(s32 *)(v + 0x340) = *(s32 *)(msg + 0x18);
                *(s32 *)(v + 0x290) = *(s32 *)(msg + 0x18);
                func_L40_0040C828(m, 9, 0, 0x14);
                func_L01_00458A70(m, D_L40_002473D8 * 0.000277777785f, D_L40_002473D4 * 0.0166666675f, 0.00698131742f, 0.418879062f);
                if (*(s32 *)(m + 0x28) == 0 && m != D_L40_002485EC && *(s32 *)(msg + 0x1C) != -1 && *(s32 *)(v + 0x2C8) != -1) {
                    f32 z = *(f32 *)(m + 0x18);
                    f32 dz = 1.0f;

                    *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)((u8 *)D_L40_0028FF00[*(s32 *)(v + 0x2C8)] + 0x10 + *(s32 *)(msg + 0x1C) * 16);
                    if (D_L40_0024145C[0] == 0x2C || D_L40_0024145C[0] == 0x36 || D_L40_0024145C[0] == 0x28 || D_L40_0024145C[0] == 0x32) {
                        dz = 8.0f;
                    }
                    *(f32 *)(m + 0x18) = z + dz;
                    *(f32 *)(m + 0x18) = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
                }
                break;
            case 0:
                func_L01_00458A70(m, 0.00249999994f, 0.100000009f, 0.00969627406f, 0.58177644f);
                *(s32 *)(v + 0x368) = *(s32 *)(msg + 0x18);
                func_L01_00441FB8(m, 2, -1);
                if (*(s32 *)(v + 0x368) == -1) {
                    func_L01_00458A70(m, D_L40_002473D8 * 0.000277777785f, D_L40_002473D4 * 0.0166666675f, 0.00969627406f, 0.58177644f);
                    func_L01_00441FB8(m, 1, -1);
                }
                break;
            case 1: {
                s32 t;

                *(V4u_40B1D0 *)&a = *(V4u_40B1D0 *)(msg + 0x18);
                vec_sub_ab(&d, v + 0x300, &a);
                vel = d;
                tg = d;
                *(vu0_v4 *)(v + 0x300) = a;
                *(V4u_40B1D0 *)(v + 0x390) = *(V4u_40B1D0 *)(msg + 0x28);
                *(V4u_40B1D0 *)(v + 0x380) = *(V4u_40B1D0 *)(msg + 0x38);
                t = *(s32 *)(msg + 0x48);
                ((V_0040B1D0 *)v)->f2C4 = t;
                if (!(D_L40_002473CC < (f32)(D_001A5E50.time - t))) {
                    *(u8 *)(m + 0x20) = 5;
                }
                break;
            }
            case 2:
                *(s32 *)(v + 0x290) = *(s32 *)(msg + 0x18);
                *(s32 *)(v + 0x340) = *(s32 *)(msg + 0x18);
                break;
            }
            msg = func_L39_00669AC0(msg, g + 0x38);
            continue;
        case 2: {
            u8 *fx;
            u8 *q;

            func_L40_0040C6B0(m);
            func_L40_0053CE30(m);
            fx = func_L01_0032FE90_0040AB18(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f,
                                   0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (fx != 0) {
                *(u8 **)(fx + 0xB8) = m;
            }
            if ((u32)*(s32 *)(v + 0x2AC) >> 28 == D_001A5E50.client) {
                q = func_L39_00619838(*(s32 *)(v + 0x2AC));
                if (q != 0) {
                    *(u8 *)(q + 0x1A11) = 0;
                }
            }
            return;
        }
        case 4:
            if (func_L40_0053C768(m) && *(u8 *)(v + 0x2D0) == 0) {
                u8 *out;
                u8 *p;

                *(u8 *)(v + 0x2D0) = handover_0040B1D0(type);
                *(s32 *)(v + 0x378) = *(s32 *)(msg + 0x18);
                out = func_L39_006699B0();
                if (out == 0) {
                    return;
                }
                p = out + func_L39_00669978(5, uid, D_001A5E50.time + 500, h[3], out);
                *(s32 *)p = *(s32 *)(v + 0x378);
                p += 4;
                *(s32 *)out = p - out;
            }
            msg = func_L39_00669AC0(msg, g + 0x38);
            continue;
        case 5:
            *(u8 *)(v + 0x2D0) = handover_0040B1D0(type);
            if (h[3] != D_001A5E50.client) {
                func_L40_0053C7B8(m, h[3], h[2]);
            } else {
                func_L40_0053C788(m, h[2]);
            }
            msg = func_L39_00669AC0(msg, g + 0x38);
            continue;
        }
        msg = func_L39_00669AC0(msg, g + 0x38);
    }
    if (*(u8 *)(m + 0x20) == 5 && (f32)(D_001A5F78[0] - *(s32 *)(v + 0x2C4)) > D_L40_002473D0) {
        func_L01_00441FB8(m, 6, -1);
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(v + 0x300);
        *(vu0_v4 *)(m + 0xF0) = *(vu0_v4 *)(v + 0x390);
        *(vu0_v4 *)(v + 0x110) = *(vu0_v4 *)(v + 0x380);
        *(s32 *)(v + 0x12C) = D_L40_002412AC[0] - 1;
    }
    if ((u32)(*(u8 *)(m + 0x20) - 2) < 2) {
        u8 *q;
        s32 ok;

        if (*(s32 *)(v + 0x368) == 0) {
            return;
        }
        if ((u32)*(s32 *)(v + 0x2AC) >> 28 == D_001A5E50.client) {
            u8 *hero = func_L39_00619838(*(s32 *)(v + 0x2AC));

            if (hero != 0) {
                *(u8 *)(hero + 0x1A11) = 0;
            }
        }
        if (*(s32 *)(v + 0x368) == -1) {
            func_L01_00441FB8(m, 1, -1);
        }
        *(s16 *)(v + 0x234) = 0;
        *(s32 *)(v + 0x230) = func_L40_0053BEB0(*(s32 *)(v + 0x368), (vu0_v4 *)(v + 0x220), -1, 1);
        if (*(s32 *)(v + 0x230) == 0) {
            return;
        }
        ok = 1;
        a = *(vu0_v4 *)(m + 0x10);
        a.z += 1.0f;
        tg = *(vu0_v4 *)(v + 0x220);
        tg.z += 0.699999988f;
        q = func_L39_00619838(*(s32 *)(v + 0x368));
        if (q != 0 && *(s16 *)(q + 0x2D8) != 0) {
            vel = *(vu0_v4 *)(*(u8 **)(q + 0x2524) + 0xE0);
            func_00388830(&vel, &vel, 0.699999988f);
            tg.z -= 0.699999988f;
            vec_add_ab(&tg, &tg, &vel);
        }
        if (func_L01_0040C018(&a, &tg) < *(f32 *)(v + 0x2C0) * 4.0f * *(f32 *)(v + 0x2C0)) {
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            if (func_003CE740(&a, &tg, 0x10, m, 0) != 0) {
                if (D_L40_0025BB18[0] == 0 || D_L40_0025BB18[0] != *(u8 **)(v + 0x230)) {
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
/* localdecomp:end func_L40_0040AB18 */
