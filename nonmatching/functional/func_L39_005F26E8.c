/* functional: medium. Compiles, not byte-exact. Omits retail's dead direction vector (computed by VU0 vadd/vsub into a stack temp that is never read afterwards); all stores, calls and arguments otherwise follow the asm block by block. Scratchpad blocks at fixed addresses as the asm has them. */
/* localdecomp:start func_L39_005F26E8 */
typedef int Q_005F26E8 __attribute__((mode(TI)));
extern u8 D_001FE020[];
extern u8 D_L39_0024DE80[];
extern s32 D_L39_00242914;
extern s32 D_L39_0024E2D0;
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_002410E8;
__asm__(".extern D_L39_002410E8, 16");
extern s32 func_00193590(void);
extern void func_L39_005F1470(void);
extern void func_00194BC8(s32, s32, s32, s32, s32);
extern void func_00194C40(s32, s32, s32, s32);
extern void func_00193BB0(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_003A3DC8(void *, void *, void *, s32);
extern s32 func_003A3E28(void *, void *);
extern void func_00193D98(s32);
extern void func_00193E80(s32, void *, long);
extern void func_00193F08(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_00193D38(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_003A5550(s32, long);
extern void func_003A5508(s32, long);
extern void func_00194670(void);
extern void func_00194668(void);
extern void func_L39_005C2148(void);

s32 func_L39_005F26E8(void) {
    u8 *B = D_001FE020;
    s32 *blk0 = (s32 *)0x70000000; /* scratchpad: per-voice state flags */
    s32 *sc[4]; /* scratchpad: per-listener volume rows */
    s32 w[4];
    s32 nL = D_L39_00242914 + 1;
    s32 sflag = D_L39_0024E2D0;
    s32 i;
    s32 k;
    s32 b43;
    u8 *rec;
    u8 *src;
    u8 *q;
    s32 special;
    s32 lim;
    s32 sumW;
    s32 sumV;

    func_00193590();
    func_L39_005F1470();
    b43 = B[0x43];
    if ((b43 & 8) != 0) {
        func_00194BC8(2, 0, 0, 0, 0);
    } else if ((b43 & 0x13) != 0) {
        func_00194BC8(2, B[0x40], *(s32 *)(B + 0xB4), B[0x41], B[0x42]);
    } else if ((b43 & 4) != 0) {
        func_00194C40(2, *(s32 *)(B + 0xB4), 0xC, 3);
    }
    B[0x43] = 0;
    if ((*(s32 *)(B + 0x1B20) & 2) != 0) {
        s32 v = *(s32 *)(B + 4);
        if (sflag != 0) {
            v = (v * 3) / 5;
        }
        *(s32 *)(B + 4) = v;
        func_00193BB0(1, v);
    }
    if ((*(s32 *)(B + 0x1B20) & 1) != 0) {
        func_00193BB0(0, *(s32 *)B);
    }
    if ((*(s32 *)(B + 0x1B20) & 8) != 0) {
        func_00193BB0(3, *(s32 *)(B + 0xC));
    }
    if ((*(s32 *)(B + 0x1B20) & 0x10) != 0) {
        func_00193BB0(4, *(s32 *)(B + 0x10));
    }
    if ((*(s32 *)(B + 0x1B20) & 4) != 0) {
        func_00193BB0(2, *(s32 *)(B + 8));
        func_00193BB0(6, *(s32 *)(B + 8));
    }
    if ((*(s32 *)(B + 0x1B20) & 0x20) != 0) {
        func_00193BB0(5, *(s32 *)(B + 0x14));
    }
    for (k = 0; k < nL; k++) {
        sc[k] = (s32 *)(0x700000D0 + k * 0xD0);
    }
    func_0038CB78((void *)0x70000000, 0, 0xD0 * (nL + 1));

    for (i = 0; i < 0x34; i++) {
        rec = B + i * 0x80;
        if (rec[0xD0] == 7) {
            src = *(u8 **)(rec + 0xDC);
        } else {
            if (*(s32 *)(rec + 0xC0) == 0 || *(s32 *)(rec + 0xC0) == -1) {
                continue;
            }
            src = *(u8 **)(rec + 0xDC);
        }
        special = 0;
        if (src != 0 && (src[0x20] == 0xFE || src[0x20] == 0xFD)) {
            special = 1;
        }
        if (special != 0) {
            *(u8 **)(rec + 0xDC) = 0;
        }
        if (rec[0xD0] == 4 || (rec[0xD0] != 6 && special != 0 && (*(u8 **)(rec + 0xC4))[0x18] != 0)) {
            blk0[i] = 0x20;
            continue;
        }
        if (D_L39_00241128 != 0 && D_L39_00241128 != 2 && D_L39_00241128 != 6 && rec[0xD0] != 7) {
            blk0[i] = 0x10;
            continue;
        }
        q = *(u8 **)(rec + 0xDC);
        if (q != 0 && (*(u32 *)(rec + 0x118) & 8) == 0) {
            if ((*(u32 *)(rec + 0x118) & 0x40) != 0) {
                f32 tmp[4];
                func_0038D000(tmp, rec + 0xF0, q + 0xC0);
                tmp[0] += *(f32 *)(q + 0x10);
                tmp[1] += *(f32 *)(q + 0x14);
                tmp[2] += *(f32 *)(q + 0x18);
                *(Q_005F26E8 *)(rec + 0xE0) = *(Q_005F26E8 *)tmp;
            } else {
                *(Q_005F26E8 *)(rec + 0xE0) = *(Q_005F26E8 *)(q + 0x10);
                *(f32 *)(rec + 0xE8) = *(f32 *)(rec + 0xE8) + 1.0f;
            }
        }
        if ((*(u32 *)(rec + 0x118) & 0x10) != 0) {
            for (k = 0; k < nL; k++) {
                w[k] = 0x400;
                sc[k][i] = *(s16 *)(rec + 0xCC);
            }
        } else {
            for (k = 0; k < nL; k++) {
                s32 r = func_003A3DC8(rec + 0xC0, rec + 0xE0, D_L39_0024DE80 + k * 0x460, 1);
                w[k] = r;
                sc[k][i] = (r * *(s16 *)(rec + 0xCC)) / 1024;
            }
            if (((*(u8 **)(rec + 0xC4))[0x19] & 2) == 0) {
                blk0[i] |= 8;
            }
        }
        if (sflag != 0 && ((*(u8 **)(rec + 0xC4))[0x19] & 4) == 0 && 0.0f < *(f32 *)(rec + 0xE8)) {
            for (k = 0; k < nL; k++) {
                sc[k][i] = sc[k][i] / 2;
            }
        }
        blk0[i] |= 1;
        sumW = 0;
        sumV = 0;
        for (k = 0; k < nL; k++) {
            sumW += w[k];
            sumV += sc[k][i];
        }
        lim = 0x400 - D_L39_002410E8;
        if (sumW > lim) {
            sumW = lim;
        }
        if (sumV > lim) {
            sumV = lim;
        }
        if (sumW < 0x20 && sumV < 0x20 && (*(u32 *)(rec + 0x118) & 4) != 0) {
            blk0[i] = 0x20;
        }
    }

    for (i = 0; i < 0x34; i++) {
        s32 v = blk0[i];
        s32 h;
        s32 fl;
        s32 a20;
        s32 a22;
        s32 pan;
        s32 sum;
        long aux;

        if (v == 0) {
            continue;
        }
        rec = B + i * 0x80;
        h = *(s32 *)(rec + 0xC0);
        *(s32 *)(rec + 0xC0) = -1;
        aux = (long)(rec + 0xC0);
        if ((v & 0x20) != 0) {
            if (rec[0xD0] == 7) {
                rec[0xD0] = 0;
                *(s32 *)(rec + 0xDC) = 0;
                *(s32 *)(rec + 0x100) = 0;
                continue;
            }
            func_00193D98(h);
            rec[0xD0] = 6;
            func_00193E80(h, func_003A5550, aux);
            *(s32 *)(rec + 0x10C) = rec[0xD3];
            continue;
        }
        if ((v & 0x10) != 0) {
            func_00193E80(h, func_003A5550, aux);
            *(s32 *)(rec + 0x10C) = rec[0xD3];
            continue;
        }
        a20 = *(s32 *)(rec + 0xD4);
        fl = 1;
        if (a20 != 0) {
            fl = 0x11;
        }
        a22 = 0;
        if (*(s32 *)(rec + 0xD8) != 0) {
            a22 = *(s32 *)(rec + 0xD8);
            fl |= 8;
        }
        pan = 0;
        if ((v & 2) != 0) {
            fl |= 6;
            pan = func_003A3E28((void *)aux, rec + 0xE0);
        }
        sum = 0;
        for (k = 0; k < nL; k++) {
            sum += sc[k][i];
        }
        lim = 0x400 - D_L39_002410E8;
        if (sum > lim) {
            sum = lim;
        }
        if (rec[0xD0] != 7) {
            func_00193F08(h, fl, sum, pan, a22, a20, func_003A5550, aux);
            *(s32 *)(rec + 0x10C) = rec[0xD3];
        } else {
            q = *(u8 **)(rec + 0xC4);
            if (q == 0 || *(s32 *)(B + 0x90 + *(s32 *)(q + 0x1C) * 4) == -1 ||
                *(s32 *)(B + 0x90 + *(s32 *)(q + 0x1C) * 4) == 0) {
                rec[0xD0] = 0;
                *(s32 *)(rec + 0xDC) = 0;
                *(s32 *)(rec + 0x100) = 0;
            } else {
                rec[0xD0] = 1;
                func_00193D38(*(s32 *)(B + 0x90 + *(s32 *)(q + 0x1C) * 4), *(s16 *)(q + 0x1A), sum, pan, a22, a20,
                              func_003A5508, aux);
            }
        }
    }
    func_L39_005C2148();
    func_00194670();
    func_00193590();
    func_00194668();
    *(s32 *)(B + 0x44) = 0;
    return 0;
}
/* localdecomp:end func_L39_005F26E8 */
