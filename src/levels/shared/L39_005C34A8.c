#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005C34A8);

/* localdecomp:start func_L39_005C3E30 */
extern void func_L39_005C34A8(u8 *, u8 *, s32);
void func_L39_005C3E30(u8 *a0) {
    s32 n;
    *(s32 *)(a0 + 416) = 0;
    *(s32 *)(a0 + 428) = *(s32 *)(a0 + 840);
    *(s32 *)(a0 + 444) = *(s32 *)(a0 + 432);
    *(s32 *)(a0 + 432) = 0;
    if (*(s32 *)(a0 + 408) != 0 && a0[1396] == 0) {
        n = (a0[1397] & 0xF) * 2 + 2;
        if (n > 20) {
            n = 20;
        }
        func_L39_005C34A8(a0, a0 + 1396, n);
    }
}
/* localdecomp:end func_L39_005C3E30 */

/* localdecomp:start func_L39_005C3EA0 */
extern u8 D_001D7D78_sda[8];
extern void func_L39_005C34A8(u8 *, u8 *, s32);
extern s32 func_0013CB00(s32, s32);
extern s32 func_0013CDB8(s32, s32, s32, s32);
extern s32 func_0013CEF0(s32, s32, s32, s32);
extern s32 func_0013CC38(s32, s32);
extern s32 func_0013CC98(s32, s32, s32, s32);
extern s32 func_0013D070(s32, s32, u8 *);
extern s32 func_0013D2A8(s32, s32);
extern s32 func_0013D308(s32, s32);
extern s32 func_0013C190(s32);
extern s32 func_0013CA88(s32, s32, u8 *);
extern void func_0013CFA8(s32, s32, u8 *);

typedef struct Pad_005C3EA0 {
    u8 pad0[0x551];
    u8 align[6];
} Pad_005C3EA0;

void func_L39_005C3EA0(void *arg) {
    u8 *a0 = arg;
    Pad_005C3EA0 *s = arg;
    u8 p;
    u8 q;
    s32 r;
    s32 n;
    s32 i;

    *(s32 *)(a0 + 0x1A0) = 0;
    *(s32 *)(a0 + 0x1AC) = *(s32 *)(a0 + 0x348);
    *(s32 *)(a0 + 0x1BC) = *(s32 *)(a0 + 0x1B0);
    *(s32 *)(a0 + 0x1B0) = 0;
    p = a0[0x54C];
    q = a0[0x557];
    r = func_0013CB00(p, q);
    *(s32 *)(a0 + 0x19C) = r;
    if (r == 0) {
        *(s32 *)(a0 + 0x198) = 0;
    }
    switch (*(u32 *)(a0 + 0x198)) {
    case 0:
        if (*(s32 *)(a0 + 0x19C) != 6 && *(s32 *)(a0 + 0x19C) != 2) {
            void (*cb)(u8 *, u8 *, s32, s32) = *(void (**)(u8 *, u8 *, s32, s32))(a0 + 0x56C);
            if (cb != 0) {
                cb(a0, D_001D7D78_sda, 0x20, *(s32 *)(a0 + 0x570));
            }
            func_L39_005C34A8(a0, D_001D7D78_sda, 0x20);
            a0[0x558] = 0;
            break;
        }
        r = func_0013CDB8(p, q, 1, 0);
        *(s32 *)(a0 + 0x560) = r;
        if (r == 0) break;
        r = func_0013CDB8(p, q, 2, 0);
        *(s32 *)(a0 + 0x564) = r;
        if (r > 0) {
            *(s32 *)(a0 + 0x560) = r;
        }
        *(s32 *)(a0 + 0x55C) = 0;
        switch (*(s32 *)(a0 + 0x560)) {
        case 4:
            *(s32 *)(a0 + 0x198) = 0x28;
            break;
        case 7:
            *(s32 *)(a0 + 0x198) = 0x46;
            break;
        default:
            *(s32 *)(a0 + 0x198) = 0x63;
            break;
        }
        break;
    case 40:
        if (func_0013CDB8(p, q, 2, 0) == 0) {
            *(s32 *)(a0 + 0x198) = 0x63;
            break;
        }
        *(s32 *)(a0 + 0x198) += 1;
    case 41:
        if (func_0013CEF0(p, q, 1, 3) == 1) {
            *(s32 *)(a0 + 0x198) += 1;
        }
        break;
    case 42:
        if (func_0013CC38(p, q) == 1) {
            *(s32 *)(a0 + 0x198) -= 1;
        }
        if (func_0013CC38(p, q) == 0) {
            *(s32 *)(a0 + 0x198) = 0;
        }
        break;
    case 70:
        r = func_0013CC98(p, q, -1, 0);
        if (r == 0) {
            *(s32 *)(a0 + 0x198) = 0x63;
        }
        s->align[1] = 1;
        s->align[0] = 0;
        for (i = 2; i < 6; i++) {
            s->align[i] = 0xFF;
        }
        if (func_0013D070(p, q, s->align) != 0) {
            *(s32 *)(a0 + 0x198) += 1;
        }
        break;
    case 72:
        if (func_0013D2A8(p, q) == 0) {
            *(s32 *)(a0 + 0x55C) = 0;
            *(s32 *)(a0 + 0x198) = 0x63;
        } else {
            *(s32 *)(a0 + 0x198) = 0x4C;
        }
        break;
    case 76:
        if (func_0013D308(p, q) == 0) {
            *(s32 *)(a0 + 0x198) = 0x48;
        } else {
            *(s32 *)(a0 + 0x198) += 1;
        }
        break;
    case 71:
    case 77:
        if (func_0013CC38(p, q) == 1) {
            *(s32 *)(a0 + 0x198) -= 1;
        }
        if (func_0013CC38(p, q) == 0) {
            *(s32 *)(a0 + 0x198) += 1;
        }
        break;
    case 78:
        *(s32 *)(a0 + 0x198) = 0x63;
        break;
    default:
        if (a0[0x558] == 0) {
            a0[0x550] = func_0013C190(a0[0x54C]);
        }
        a0[0x558] = 1;
        if (*(s32 *)(a0 + 0x19C) == 6 || *(s32 *)(a0 + 0x19C) == 2) {
            u8 *buf = a0 + 0x574;
            if (func_0013CA88(p, q, buf) == 0) break;
            if (a0[0x574] == 0) {
                void (*cb)(u8 *, u8 *, s32, s32) = *(void (**)(u8 *, u8 *, s32, s32))(a0 + 0x56C);
                n = (a0[0x575] & 0xF) * 2 + 2;
                if (n > 20) n = 20;
                if (cb != 0) {
                    cb(a0, buf, n, *(s32 *)(a0 + 0x570));
                }
                func_L39_005C34A8(a0, buf, n);
                *(s32 *)(a0 + 0x1DC) = a0[0x575];
            }
            if (*(s32 *)(a0 + 0x1DC) > 0) {
                if (*(s32 *)(a0 + 0x55C) != 0 && *(s32 *)(a0 + 0x1DC) != *(s32 *)(a0 + 0x55C)) {
                    *(s32 *)(a0 + 0x55C) = 0;
                    *(s32 *)(a0 + 0x198) = 0;
                } else if (*(s32 *)(a0 + 0x1DC) > 0) {
                    *(s32 *)(a0 + 0x55C) = *(s32 *)(a0 + 0x1DC);
                }
            }
            func_0013CFA8(p, q, a0 + 0x188);
            a0[0x188] = 0;
            a0[0x189] = 0;
        }
        break;
    }
}
/* localdecomp:end func_L39_005C3EA0 */
