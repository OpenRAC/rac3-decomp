/* functional: medium. 514 diff words at the file's flags (frame 0xA0 vs 0x90, loop/branch layout, register choice). Read block by block: path A (m[0x21]==0xFF) and the three passes over the m[0x21] list (follow/attach pass, chain-walk pass, final distance pass) match retail's control flow, the D_0021F6C0 table walk (t==1/3/0x111 reset, 0x11..0x110 count-up, else reset all to 0), and the 8 register + stack argument layouts. Retail's path A passes an uninitialised sp+0x44 slot to func_L01_0044CB18; kept as an uninitialised local. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern s32 D_001D4CA8[];
extern s32 *D_L01_0021F6C0[];
extern u8 D_L01_001EAA00[];
extern void *func_L01_0043B548(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0033D188(u8 *, s32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern s32 func_003C4B50(void *);
extern s32 func_003C4D58(void *);
extern void func_L01_0044CB18(u8 *, u8 *, void *, void *, void *, void *);
extern void func_L01_00445C48(u8 **, s32, s32, s32);
extern void func_L01_00445D30(u8 **, u8 *, s32, s32);
extern f32 func_0038CF00(void *, void *);

void func_L01_0033B7C0(u8 *m) {
    Q16 buf[4];
    u8 *sp = (u8 *)buf;
    u8 *v40;
    u8 *v44;
    u8 *v48;
    u8 *p;
    u8 *pc;
    u8 *c;
    u8 *q;
    u8 *y;
    u8 *e;
    s32 id;
    s32 b;
    s32 t;
    s32 n;
    s32 i;
    s32 k;

    p = *(u8 **)(m + 0x68);
    v40 = m;
    func_L01_0043B548(0x19E1, 0x6C);
    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 4;
    id = m[0x21];
    if (id == 0xFF) {
        if (*(s16 *)(m + 0xAA) == 0x1F4) {
            if (func_00382468(2) != 0) {
                if (*(f32 *)(m + 0xF0) == 0.0f && *(f32 *)(m + 0xF4) == 0.0f) {
                    *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 1.5707964f);
                }
            }
        }
        t = *(s16 *)(m + 0xAA);
        if (t == 0x1F5 || t == 0x200) {
            b = m[0xB0];
            if (b != 0xFF && D_001D4CA8[b] < *(s32 *)(p + 0x128)) {
                func_L01_0033D188(m, 1);
                return;
            }
        }
        *(u16 *)(p + 0xF4) = *(u16 *)(m + 0xAC);
        *(f32 *)(p + 0xE0) = 1.0f;
        *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 1;
        *(Q16 *)sp = *(Q16 *)(m + 0x10);
        *(Q16 *)(sp + 0x10) = *(Q16 *)(m + 0x10);
        *(f32 *)(sp + 0x18) = 0.1f;
        *(f32 *)(sp + 0x8) = *(f32 *)(sp + 0x8) + *(f32 *)(p + 0xE0) * 0.5f;
        if (func_003D3CB0(sp, sp + 0x10, 2, 0, 0) == 0) {
            *(s32 *)(p + 0xD4) = 0;
            return;
        }
        q = D_L01_001EAA00;
        if (*(u8 **)(q + 0x18) == 0) {
            *(f32 *)(m + 0x18) = *(f32 *)(q + 0x28);
            *(s32 *)(p + 0xD4) = 0;
            return;
        }
        if (func_003C4B50(*(u8 **)(q + 0x18)) != 0) {
            return;
        }
        *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 8;
        *(s32 *)(p + 0xD4) = 0;
        if (func_003C4D58(*(u8 **)(q + 0x18)) == 0) {
            return;
        }
        if (v40 != 0) {
            *(s16 *)(v40 + 0x36) = 0x7F80;
        }
        func_L01_0044CB18(v44, *(u8 **)(q + 0x18), m + 0x10, m + 0xF0, p + 0x100, p + 0x110);
        *(s32 *)(p + 0x124) = 0;
        *(s32 *)(p + 0x120) = *(s32 *)(q + 0x18);
        return;
    }

    func_L01_00445C48(&v40, id, 0, 0);
    if (v40 != 0) {
        do {
            c = v40;
            pc = *(u8 **)(c + 0x68);
            if (func_003C4B50(c) != 0) {
                if (*(s16 *)(c + 0xAA) == 0x1F4) {
                    if (func_00382468(2) != 0) {
                        if (*(f32 *)(c + 0xF0) == 0.0f && *(f32 *)(c + 0xF4) == 0.0f) {
                            *(f32 *)(c + 0xF8) = func_0038DAB8(*(f32 *)(c + 0xF8), 1.5707964f);
                        }
                    }
                }
                t = *(s16 *)(c + 0xAA);
                if ((t == 0x1F5 || t == 0x200) && c[0xB0] != 0xFF &&
                    D_001D4CA8[c[0xB0]] < *(s32 *)(pc + 0x128)) {
                    func_L01_0033D188(c, 1);
                } else {
                    *(u16 *)(pc + 0xF4) = *(u16 *)(c + 0xAC);
                    *(f32 *)(pc + 0xE0) = 1.0f;
                    *(s32 *)(pc + 0xDC) = *(s32 *)(pc + 0xDC) | 1;
                    *(Q16 *)sp = *(Q16 *)(c + 0x10);
                    *(Q16 *)(sp + 0x10) = *(Q16 *)(c + 0x10);
                    *(f32 *)(sp + 0x18) = 0.1f;
                    *(f32 *)(sp + 0x8) = *(f32 *)(sp + 0x8) + *(f32 *)(pc + 0xE0) * 0.5f;
                    if (func_003D3CB0(sp, sp + 0x10, 2, 0, 0) == 0) {
                        *(s32 *)(pc + 0xD4) = 0;
                    } else {
                        q = D_L01_001EAA00;
                        if (*(u8 **)(q + 0x18) == 0) {
                            *(f32 *)(c + 0x18) = *(f32 *)(q + 0x28);
                            *(s32 *)(pc + 0xD4) = 0;
                        } else {
                            y = *(u8 **)(q + 0x18);
                            if (func_003C4B50(y) == 0 && (u32)((*(u16 *)(y + 0xAA)) - 0x128) >= 2u) {
                                *(s32 *)(pc + 0xD4) = 0;
                                c[0x30] = 0xFF;
                                *(s32 *)(pc + 0xDC) = *(s32 *)(pc + 0xDC) | 8;
                            } else {
                                y = *(u8 **)(q + 0x18);
                                if (*(u8 **)(y + 0x68) == 0) {
                                    *(s32 *)(pc + 0xD4) = 0;
                                } else if (y[0x21] != c[0x21]) {
                                    *(s32 *)(pc + 0xD4) = 0;
                                } else if (func_003C4B50(y) == 0) {
                                    *(s32 *)(pc + 0xD4) = 0;
                                    *(f32 *)(c + 0x18) = *(f32 *)(q + 0x28);
                                } else {
                                    u8 *py;
                                    *(u8 **)(pc + 0xD4) = *(u8 **)(q + 0x18);
                                    *(Q16 *)(c + 0x10) = *(Q16 *)(*(u8 **)(q + 0x18) + 0x10);
                                    y = *(u8 **)(q + 0x18);
                                    ((V4 *)(c + 0x10))->x = ((V4 *)(c + 0x10))->x + ((V4 *)(y + 0xE0))->x;
                                    ((V4 *)(c + 0x10))->y = ((V4 *)(c + 0x10))->y + ((V4 *)(y + 0xE0))->y;
                                    ((V4 *)(c + 0x10))->z = ((V4 *)(c + 0x10))->z + ((V4 *)(y + 0xE0))->z;
                                    y = *(u8 **)(q + 0x18);
                                    py = *(u8 **)(y + 0x68);
                                    if (func_003C4B50(c) != 0) {
                                        *(u8 **)(py + 0xD0) = c;
                                    } else {
                                        *(s32 *)(py + 0xD0) = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            func_L01_00445D30(&v40, v40, 0, 0);
        } while (v40 != 0);
    }

    func_L01_00445C48(&v44, id, 0, 0);
    if (v44 != 0) {
        do {
            c = v44;
            pc = *(u8 **)(c + 0x68);
            if (func_003C4B50(c) != 0 && *(s32 *)(pc + 0xD4) == 0) {
                *(Q16 *)(sp + 0x20) = *(Q16 *)(v44 + 0x10);
                *(Q16 *)(sp + 0x30) = *(Q16 *)(v44 + 0x10);
                *(f32 *)(sp + 0x28) = *(f32 *)(sp + 0x28) + *(f32 *)(pc + 0xE0) * 0.5f;
                *(f32 *)(sp + 0x38) = 0.1f;
                q = D_L01_001EAA00;
                if (func_003D3CB0(sp + 0x20, sp + 0x30, 2, v40, 0) != 0 && *(u8 **)(q + 0x18) != 0 &&
                    func_003C4D58(*(u8 **)(q + 0x18)) != 0) {
                    if (v40 != 0) {
                        *(s16 *)(v40 + 0x36) = 0x7F80;
                    }
                    func_L01_0044CB18(v44, *(u8 **)(q + 0x18), v44 + 0x10, v44 + 0xF0, pc + 0x100, pc + 0x110);
                    *(s32 *)(pc + 0x124) = 0;
                    *(s32 *)(pc + 0xDC) = *(s32 *)(pc + 0xDC) | 8;
                    *(u8 **)(pc + 0x120) = *(u8 **)(q + 0x18);
                }
                v40 = v44;
                while (v40 != 0) {
                    c = v40;
                    pc = *(u8 **)(c + 0x68);
                    y = *(s32 *)(pc + 0xD4) != 0 ? *(u8 **)(*(u8 **)(pc + 0xD4) + 0x68) : 0;
                    if (y != 0 && *(s32 *)(y + 0x120) != 0) {
                        c[0x30] = 0xFF;
                        *(s32 *)(pc + 0xDC) = *(s32 *)(pc + 0xDC) | 8;
                        *(Q16 *)(pc + 0x100) = *(Q16 *)(y + 0x100);
                        *(Q16 *)(pc + 0x110) = *(Q16 *)(y + 0x110);
                        *(s32 *)(pc + 0x120) = *(s32 *)(y + 0x120);
                        *(f32 *)(pc + 0x124) = *(f32 *)(y + 0x124) + 1.0f;
                    }
                    if (*(s16 *)(pc + 0xF6) != 0 || *(s16 *)(c + 0xAA) == 0x1F5 || *(s16 *)(c + 0xAA) == 0x200) {
                        if (*(s32 *)(pc + 0xD0) != 0 && *(s32 *)(pc + 0xF0) != -1) {
                            k = *(s32 *)(pc + 0xF0);
                            e = (u8 *)D_L01_0021F6C0[k];
                            n = *(s32 *)e;
                            if (n == 0) {
                                *(s32 *)(pc + 0xF0) = -1;
                            } else {
                                t = *(s32 *)(e + 0x1C);
                                if (t == 1 || t == 3 || t == 0x111) {
                                    *(s32 *)(pc + 0xF0) = -1;
                                } else if ((u32)(t - 0x11) < 0x100u) {
                                    if (t - 0x10 < n) {
                                        *(s32 *)(e + 0x1C) = t + 1;
                                    } else {
                                        *(s32 *)(pc + 0xF0) = -1;
                                    }
                                } else {
                                    *(s32 *)(e + 0x1C) = 0x11;
                                    if (*(s32 *)D_L01_0021F6C0[*(s32 *)(pc + 0xF0)] > 0) {
                                        i = 0;
                                        do {
                                            *(s32 *)((u8 *)D_L01_0021F6C0[*(s32 *)(pc + 0xF0)] + i * 16 + 0x1C) = 0;
                                            i++;
                                        } while (i < *(s32 *)D_L01_0021F6C0[*(s32 *)(pc + 0xF0)]);
                                    }
                                }
                            }
                        }
                    }
                    v40 = *(u8 **)(pc + 0xD0);
                }
            }
            func_L01_00445D30(&v44, v44, 0, 0);
        } while (v44 != 0);
    }

    func_L01_00445C48(&v40, id, 0, 0);
    if (v40 != 0) {
        do {
            if (func_003C4B50(v40) != 0) {
                func_L01_00445D30(&v48, v40, 0, 0);
                if (v48 != 0) {
                    do {
                        if (func_003C4B50(v48) != 0) {
                            func_0038CF00(v40 + 0x10, v48 + 0x10);
                        }
                        func_L01_00445D30(&v48, v48, 0, 0);
                    } while (v48 != 0);
                }
            }
            func_L01_00445D30(&v40, v40, 0, 0);
        } while (v40 != 0);
    }
}
