/* functional: medium. Large stateful function decoded by hand without a gate; reads/writes and call order re-read against the asm twice, but unusual branches (selection skipping, slot flag xor 0x1000) are untested. */
typedef struct { s32 a; s32 b; } Pair_0048F4E0;
extern u8 D_L01_001F3FA0[];
extern u8 *D_001D52FC;
extern s16 D_001CCFD4[];
extern u8 D_001D5570[];
extern u8 D_001A9318[];
extern u8 D_00142CA5[];
extern u8 D_00160C40[];
extern Pair_0048F4E0 D_L01_002E9DC0[];
extern s32 *D_L01_001D8D50;
extern char D_L01_001D8D10[];
extern char D_L01_001D8D58[];
extern void func_L01_0042E818(void);
extern s32 func_003BB148(s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern s32 func_L01_0042E500(s32);
extern void func_L01_0042E768(s32);
extern void func_003A5348(s32, s32, s32);
extern void func_0039EF28(void);
extern s32 func_L01_0042E318(s32);
extern s32 func_L01_0042E598(void);
extern void func_L01_0042E278(s32, s32);
extern void func_003A0760(s32, s32);
extern s32 func_003BB3A8(s32);
extern void func_L01_0042E700(s32, s32, s32, s32);
extern void func_L01_00430A80(s32, s32, s32);
extern void func_L01_0042FEB0(s32, s32, s32);
extern long func_L01_0042D9C0(s32, s32, s32, s32, s32, s32);
extern void func_003A02E8(void);
extern void func_003BB468(s32);
extern void func_L01_00438028(s32, s32);
extern s32 func_L01_0042E1D8(void);
extern s32 func_L01_0042E3A8(void);
extern void func_L01_004B11E0(s32, s32, s32, s32, s32);
extern void func_003A2598(s32, s32, s32);

void func_L01_0048F4E0(void) {
    u8 *S = D_L01_001F3FA0;
    s32 id;
    s32 first;
    s32 sec;
    s32 cur;
    s32 n;
    s32 buttons;
    s32 *P;
    s32 w;
    s32 sel;
    s32 alloc;
    s32 s20;
    s32 s23;
    s32 s16;
    s32 s17;
    s32 base;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 idx;
    s32 t;

    func_L01_0042E818();
    id = func_003BB148(*(s32 *)(S + 0x410));
    if (id == -1) {
        func_L01_00517190(0x180006, 0);
        func_L01_00516D60(0x180006, 0);
        func_L01_00516D60(0x180007, 0);
    } else {
        func_L01_00517190(0x180006, id);
        func_L01_00516D60(0x180006, 1);
        func_L01_00516D60(0x180007, 1);
        cur = *(s32 *)(S + 0x410);
        if (cur > 0) {
            first = D_L01_002E9DC0[cur % 0x3C].b;
        } else {
            first = D_L01_002E9DC0[1].b;
        }
        cur = *(s32 *)(S + 0x410);
        if (cur > 0) {
            sec = D_L01_002E9DC0[cur % 0x3C].a;
        } else {
            sec = D_L01_002E9DC0[1].a;
        }
        if (first == 0 || sec == 0) {
            func_L01_00516D60(0x180007, 0);
        } else {
            s17 = (s32)func_00381FF0(sec);
            ((void (*)(char *, char *, s32, char *))func_0011B2E8)(D_L01_001D8D10, D_L01_001D8D58, s17, func_00381FF0(first));
            func_L01_00516FD8(0x180007, D_L01_001D8D10);
        }
    }
    s16 = *(s32 *)(S + 0x410);
    n = func_L01_0042E500(s16);
    if (n >= 0) {
        buttons = *(s32 *)(D_001D52FC + 0x1C4);
        if ((buttons & 8) && n < 0x3B) {
            P = D_L01_001D8D50;
            if (P[n + 1] == 3 && D_001D545C == 6) {
                func_L01_0042E768(6);
            } else {
                w = P[n + 1];
                if (w == 0xB) {
                    if (P[n + 2] != 0) {
                        func_L01_0042E768(P[n + 2]);
                    }
                } else if ((u32)w >= 2) {
                    func_L01_0042E768(w);
                }
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 4) {
            if (n != 0) {
                P = D_L01_001D8D50;
                if (P[n - 1] == 3 && D_001D545C == 6) {
                    func_L01_0042E768(6);
                } else {
                    w = P[n - 1];
                    if (w == 0xB) {
                        if (P[n - 2] != 0) {
                            func_L01_0042E768(P[n - 2]);
                        }
                    } else if ((u32)w >= 2) {
                        func_L01_0042E768(w);
                    }
                }
            }
        }
    }
    if (*(s32 *)(S + 0x410) != s16) {
        func_003A5348(3, 0, 0);
        func_0039EF28();
    }
    s23 = *(s32 *)(S + 0x410);
    if (D_00142CA5[0] != 0) {
        s23 = s23 + 0x100;
    }
    s17 = func_L01_0042E318(s23);
    if (*(s32 *)(S + 0x410) != *(s32 *)(S + 0x414)) {
        if (s17 != -1) {
            s16 = func_L01_0042E598();
            if (*(s32 *)(S + 0x468) != 0) {
                if (s16 > 0) {
                    func_L01_0042E278(s16, 0);
                    if (s17 == 0) {
                        s17 = s16;
                    }
                }
            }
            func_003A0760(*(s32 *)(S + 0x468 + s17 * 4), *(s32 *)(S + 0x428));
            base = *(s32 *)(S + 0x428);
            a = *(s32 *)(base + 8);
            b = *(s32 *)(base + 0xC);
            alloc = func_003BB3A8(0);
            if (alloc != 0) {
                c = *(s32 *)(S + 0x428) + *(s32 *)base + 8;
                if (*(s32 *)(S + 0x410) == D_001D545C) {
                    func_L01_0042E700(base + b, base + a, base + b, *(s32 *)(S + 0xC));
                } else {
                    if (D_001D5570[*(s32 *)(S + 0x410)] != 0) {
                        func_L01_00430A80(alloc, (s32)D_001A9318 + (*(s32 *)(S + 0x410) << 11), *(s32 *)(S + 0x428) + *(s32 *)(base + 4));
                    } else {
                        func_L01_0042FEB0(alloc, c, c);
                    }
                    func_L01_0042E700(base + b, base + a, base + b, alloc);
                }
            }
            d = *(s32 *)(S + 0x428);
            *(long *)(S + 0x448) = func_L01_0042D9C0(7, 7, d + *(s32 *)(base + 0x10) + 0x20, d + *(s32 *)(base + 0x10) + 0x420, *(s32 *)(S + 0x430), *(s32 *)(S + 0x434));
            *(long *)(S + 0x450) = func_L01_0042D9C0(7, 7, d + *(s32 *)(base + 0x10) + 0x20, d + *(s32 *)(base + 0x14) + 0x420, *(s32 *)(S + 0x430), *(s32 *)(S + 0x438));
            *(long *)(S + 0x458) = func_L01_0042D9C0(7, 7, d + *(s32 *)(base + 0x10) + 0x20, d + *(s32 *)(base + 0x18) + 0x420, *(s32 *)(S + 0x430), *(s32 *)(S + 0x43C));
            if (alloc != 0) {
                func_L01_0042D9C0(9, 9, base + b, base + b, 0x3FF000, *(s32 *)(S + 0x42C));
            }
            func_003A02E8();
            if (alloc != 0) {
                func_003BB468(alloc);
            }
            *(s32 *)(S + 0x468) = base + a;
            *(s32 *)(S + 0x414) = *(s32 *)(S + 0x410);
            func_L01_00438028(*(s32 *)(S + 0x410), 0);
        }
    }
    if (D_001CCFD4[0] == 0) {
        if (*(s32 *)(S + 0x490) != -1) {
            *(u32 *)(S + 0x47C + *(s32 *)(S + 0x490) * 4) ^= 0x1000;
            *(s32 *)(S + 0x490) = -1;
        }
    }
    s20 = -1;
    if (*(s32 *)(S + 0x28) != 0 && D_001CCFD4[0] == 0) {
        s20 = func_L01_0042E1D8();
        if (s20 != -1) {
            sel = func_L01_0042E3A8();
            if (sel != -1) {
                t = 0x100;
                if (D_001D545C + *(s32 *)(S + 0x41C) == 0) {
                    t = 0;
                }
                if (t == sel) {
                    func_L01_004B11E0(*(s32 *)(S + 0x468 + s20 * 4), *(s32 *)(S + 0x418), 0, *(s32 *)(S + 0x420), 0);
                    *(s32 *)(S + 0x494 + s20 * 4) = *(s32 *)(S + 0x420);
                } else {
                    if (sel & 0x100) {
                        idx = (sel ^ 0x100) << 3;
                        c = *(s32 *)(D_00160C40 + 0x5FA8 + idx);
                        d = *(s32 *)(D_00160C40 + 0x5FAC + idx);
                        func_003A2598(*(s32 *)(S + 0x468 + s20 * 4), c + *(s32 *)(D_00160C40 + 0x4954), d);
                    } else {
                        idx = sel << 3;
                        c = *(s32 *)(D_00160C40 + 0x5DC8 + idx);
                        d = *(s32 *)(D_00160C40 + 0x5DCC + idx);
                        func_003A2598(*(s32 *)(S + 0x468 + s20 * 4), c + *(s32 *)(D_00160C40 + 0x4954), d);
                    }
                    *(s32 *)(S + 0x494 + s20 * 4) = (d << 11) >> 4;
                }
                *(s32 *)(S + 0x47C + s20 * 4) = sel | 0x1000;
                *(s32 *)(S + 0x490) = s20;
            }
        }
    }
    s17 = func_L01_0042E318(s23);
    if (*(s32 *)(S + 0x410) != *(s32 *)(S + 0x414)) {
        if (D_001CCFD4[0] == 0) {
            if (s17 == -1 && s20 == s17) {
                func_L01_0042E598();
            }
        }
    }
}
