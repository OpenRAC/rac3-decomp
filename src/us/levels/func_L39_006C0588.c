#include "common.h"

/* NTSC-U counterpart of func_L39_006C30A0 (src/levels/39_multiplayer_menu/L39_006C20B0.c) */
extern u8 *D_L39_002417C0;
extern u8 D_L39_002496A0[];
extern u8 *D_L39_002417C0;
extern s32 func_L39_006C1C70(void *, s32);
extern s32 func_L39_006C1BD8(void *, s32);

/* localdecomp:start func_L39_006C0588 */
extern u8 *D_L39_0024D860;
__asm__(".extern D_L39_002407C0, 16");
extern s32 D_L39_002407C0;
__asm__(".extern D_L39_002412F0, 16");
extern s32 D_L39_002412F0[] __attribute__((section(".sdata")));
extern u8 D_L39_00225900[];
extern u8 D_L39_002496A0[];
extern u8 *D_L39_00247A74_006C0588;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern s32 func_L39_00685798(s32, s32, s32);
extern void func_L39_006848D0(void *, void *, s32, s32);
extern void func_L39_006C0DC8(u8 *, s32, s32);
extern void func_L39_006C17F0(u8 *, s32, s32);
extern s32 func_L39_006C1AB0(void *, s32, s32 *);
extern s32 func_L39_006C1C70(void *, s32);
extern void func_L39_006D2750(void *, s32, void *, s32, s32, s32, void *);

/* the game-state block at D_001A5E50 */
typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x160];
    u8 b168;
    u8 pad169[0x640 - 0x169];
    s32 msg[8];     /* 0x640: pending message target per slot, -1 = none */
    s32 msgArg[8];  /* 0x660 */
    s32 w680;
    s32 w684;
    u32 w688;
} G_006C30A0;
extern G_006C30A0 D_001A5CD0_006C30A0 __attribute__((section(".data")));

/* the lobby table at D_L39_002417C0 */
typedef struct {
    u8 names[8][16];
    u8 e80[8][8];
    s16 hC0[8];
    s16 hD0[8];
    s16 hE0[8];
    s16 hF0[8];
    u8 pad100[0x78];
    s32 w178;
} Q_006C30A0;

typedef struct {
    s32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    char pad[0x11];
} S_006C30A0;

static __inline__ G_006C30A0 *game_006C30A0(void) {
    return &D_001A5CD0_006C30A0;
}

s32 func_L39_006C0588(u8 *obj) {
    void *h = *(void **)(D_L39_0024D860 + 0x3C);
    s32 i;
    s32 a;
    s32 b;
    u8 *p;

    if (D_L39_002417C0 == 0) {
        return 0;
    }
    if (game_006C30A0()->b168 != 0) {
            s32 cnt = 1;
            s32 j;
            for (j = 1; j < 8; j++) {
                s32 *e = &game_006C30A0()->msg[j];
                Q_006C30A0 *q;
                if (*e != -1) {
                    S_006C30A0 s;
                    s.b6 = game_006C30A0()->msgArg[j];
                    s.f0 = 0;
                    s.b5 = 0;
                    s.b4 = 0;
                    func_0014AD08(0x50, game_006C30A0()->w4, *e, D_L39_002407C0, 0x20, &s);
                    *e = -1;
                }
                q = (Q_006C30A0 *)D_L39_002417C0;
                if (q->hE0[j] != -1 && q->hF0[j] == 6) {
                    cnt++;
                }
            }
            obj[0x2A8] = cnt == ((Q_006C30A0 *)D_L39_002417C0)->w178;
    }
    if (*(s32 *)(obj + 0x2B8) != 0) {
        if (game_006C30A0()->w680 != 0) {
            if (game_006C30A0()->w684 == 2) {
                switch (*(s32 *)(obj + 0x2B8)) {
                case 1:
                    func_L39_006C0DC8(obj, func_L39_006C1C70(obj, 0), 0);
                    break;
                case 3:
                    func_L39_006C0DC8(obj, func_L39_006C1C70(obj, 1), 1);
                    break;
                case 2:
                    func_L39_006C0DC8(obj, func_L39_006C1C70(obj, 1), 0);
                    break;
                case 4:
                    func_L39_006848D0(D_L39_00247A74_006C0588, D_L39_002496A0, 3, *(u32 *)(obj + 0x2CC) - 1 < 2);
                    break;
                case 5:
                    break;
                }
            }
            *(s32 *)(obj + 0x2B8) = 0;
            game_006C30A0()->w680 = 0;
        }
    } else {
        if (game_006C30A0()->w680 != 0 && game_006C30A0()->w684 == 4) {
            u32 k = game_006C30A0()->w688;
            if (k < 2) {
                *(obj + k + 0x2C8) = 1;
            }
            game_006C30A0()->w680 = 0;
        }
    }
    for (i = 0; i < 8; i++) {
        a = -1;
        func_L39_006C1AB0(obj, i, &a);
        b = func_L39_006C1BD8(obj, i);
        if (a < 0 || b < 0) {
            continue;
        }
        if (a == 0) {
            if (D_L39_002412F0[0] == 0) {
                D_L39_002412F0[0] = (s32)D_L39_00225900;
            }
            p = (u8 *)D_L39_002412F0[a];
        } else {
            if (D_L39_002412F0[a] != 0 && ((u8 *)D_L39_002412F0[a])[0x558] == 0) {
                Q_006C30A0 *q = (Q_006C30A0 *)D_L39_002417C0;
                s16 *st = q->hF0;
                s16 *e = &st[b];
                if (*e == 6) {
                    if (game_006C30A0()->b168 != 0) {
                        *e = 0;
                        func_L39_006D2750(h, a, q->names[b], q->hC0[b], q->hD0[b], 0, q->e80[b]);
                    } else {
                        func_L39_006C17F0(obj, 5, a);
                    }
                }
                D_L39_002412F0[a] = 0;
            }
            if (D_L39_002412F0[a] == 0) {
                s32 k;
                for (k = 0; k < 8; k++) {
                    u8 *c = D_L39_00225900 + k * 0x5C0;
                    if ((c[0x558] != 0 && (*(s32 *)(c + 0x1C4) & 0x20)) || (*(s32 *)(c + 0x1C4) & 0x40)) {
                        s32 found = 0;
                        s32 j;
                        for (j = 0; j < 4; j++) {
                            if (D_L39_002412F0[j] == (s32)c) {
                                found = 1;
                                break;
                            }
                        }
                        if (!found) {
                            D_L39_002412F0[a] = (s32)(D_L39_00225900 + k * 0x5C0);
                            break;
                        }
                    }
                }
            }
            p = (u8 *)D_L39_002412F0[a];
        }
        if (p == 0) {
            continue;
        }
        if (*(s32 *)(p + 0x1C4) & 0x20) {
            Q_006C30A0 *q;
            s16 *e;
            s16 *st;
            func_L39_00685798(4, 0, 0);
            q = (Q_006C30A0 *)D_L39_002417C0;
            st = q->hF0;
            e = &st[b];
            if (*e == 6) {
                if (game_006C30A0()->b168 != 0) {
                    *e = 0;
                    func_L39_006D2750(h, a, q->names[b], q->hC0[b], q->hD0[b], 0, q->e80[b]);
                } else {
                    func_L39_006C17F0(obj, 5, a);
                }
            } else {
                *e = 6;
                func_L39_006D2750(h, a, q->names[b], q->hC0[b], q->hD0[b], 6, q->e80[b]);
            }
        }
        if (a > 0 && (*(s32 *)(p + 0x1C4) & 0x40)) {
            Q_006C30A0 *q = (Q_006C30A0 *)D_L39_002417C0;
            s16 *st = q->hF0;
            s16 *e = &st[b];
            if (*e != 6) {
                func_L39_006C0DC8(obj, i, 0);
            } else if (game_006C30A0()->b168 != 0) {
                *e = 0;
                func_L39_006D2750(h, a, q->names[b], q->hC0[b], q->hD0[b], 0, q->e80[b]);
                func_L39_006C0DC8(obj, i, 0);
            } else {
                func_L39_006C17F0(obj, 2, a);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006C0588 */
