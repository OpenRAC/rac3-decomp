/* functional: high. Multiplayer-menu event dispatcher: reads the event kind (low 4 bits of ev[0]) and runs the 16-way switch as retail does. The protected-value decodes (keyed 8-byte table at D_L39_004997E0) are one helper here, retail repeats them inline; result 0 when the key byte is 0 as in retail. The delay-slot store `obj[0x31C]=0` / `obj[0x320]=0` that retail runs even when the lookup returns NULL is done only for non-NULL obj (a store to address 0x31C/0x320 would be a no-op on PS2 scratch and a fault on the host). */
extern char D_L39_00337700[];
extern u8 D_L39_0033AB08[];
extern u8 D_L39_004997E0[];
extern s32 D_L39_002461F8;
extern s32 D_L39_00246204;
extern s32 D_001A5DF8[];
extern s32 D_001A5E3C[];
extern void func_L39_00662B18(void *, void *, s32);
extern s32 func_L39_0061BFB0(s32);
extern u8 *func_L39_006685D8(s32);
extern void func_L39_00667908(s32, s32);
extern void func_L39_00667208(void *, u32, s32, s32);
extern void func_L39_00667540(void *, void *);
extern void func_L39_006672C0(void *, void *);
extern void func_L39_00667700(void *, void *, s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);

static u32 b68_unscramble(u8 *key) {
    u32 b[2];
    u32 c = key[0];
    u32 base;
    s32 k;
    if (c == 0) return 0;
    base = ((u32)key - c) & 7;
    for (k = 0; k < 8; k++) {
        ((u8 *)b)[k] = D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255];
    }
    b[0] ^= (u32)key;
    b[1] ^= b[0];
    return b[1];
}

void func_L39_00667B68(void *unused, s32 *ev) {
    s32 idv;
    u8 *g;
    u8 *obj;
    u8 *rec;
    s32 i;
    s32 owner;
    s32 code;
    s32 val;
    u32 w;
    f32 fv;
    u8 flag;

    owner = ev[2];
    func_L39_00662B18(ev, &idv, 4);
    g = (u8 *)func_L39_0061BFB0(idv);
    switch (ev[0] & 0xF) {
    case 9:
        if (D_L39_002461F8 > 0) {
            rec = D_L39_00337700;
            i = 0;
            do {
                if (*(s16 *)(rec + 0x304) == idv) {
                    *(s32 *)rec = owner;
                    return;
                }
                i++;
                rec += 0x340;
            } while (i < D_L39_002461F8);
        }
        return;
    case 15: {
        f32 f20;
        obj = func_L39_006685D8(owner);
        f20 = (f32)(u32)idv;
        if (f20 < *(f32 *)(obj + 0x308)) {
            s32 h = *(s16 *)(obj + 0x2FC);
            if (*(s32 *)(D_L39_0033AB08 + h * 0x1C + 0x18) != 0) {
                (*(void (**)(void *))(D_L39_0033AB08 + h * 0x1C + 0x18))(*(void **)(obj + 0x2D0));
            }
            *(f32 *)(obj + 0x308) = f20;
        }
        return;
    }
    case 14:
        obj = func_L39_006685D8(owner);
        {
            u8 *m = *(u8 **)(obj + 0x2D0);
            if (m[0xBC] != 0) return;
            m[0xBC] = 0xB;
            *(s32 *)(obj + 0x2E8) = 0x96;
        }
        return;
    case 6:
        val = D_001A5DF8[0] + D_L39_00246204;
        obj = func_L39_006685D8(owner);
        if ((*(u8 **)(obj + 0x2D0))[0xBC] != 0) return;
        func_L39_00667208(obj, val, 7, -1);
        return;
    case 7:
        obj = func_L39_006685D8(owner);
        {
            u8 *m = *(u8 **)(obj + 0x2D0);
            if (m[0xBC] != 0) return;
            m[0xBC] = 9;
            *(s32 *)(obj + 0x2E8) = idv;
        }
        return;
    case 13:
        func_L39_00667908(2, owner);
        obj = func_L39_006685D8(owner);
        *(s32 *)(obj + 0x320) = 0;
        return;
    case 12:
        func_L39_00667908(1, owner);
        obj = func_L39_006685D8(owner);
        *(s32 *)(obj + 0x31C) = 0;
        return;
    case 0:
        if (g == 0) return;
        obj = func_L39_006685D8(owner);
        if (*(s32 *)(obj + 0x31C) > 0) return;
        if (*(s32 *)(obj + 0x2D8) != 0) return;
        *(s32 *)(obj + 0x31C) = 0xFA;
        func_L39_00667208(obj, idv, 0xA, **(s32 **)(g + 0x2558));
        return;
    case 1:
        if (g == 0) return;
        obj = func_L39_006685D8(owner);
        if (*(s32 *)(obj + 0x320) > 0) return;
        if (*(s32 *)(obj + 0x2DC) != 0) return;
        *(s32 *)(obj + 0x320) = 0xFA;
        func_L39_00667208(obj, idv, 0xB, **(s32 **)(g + 0x2558));
        return;
    case 10:
        obj = func_L39_006685D8(owner);
        w = b68_unscramble(g + 0x19E6);
        if ((w ^ 0x14) != 0) {
            w = b68_unscramble(g + 0x2476);
            fv = *(f32 *)&w;
            if (g[0x2476] == 0) fv = 0.0f;
            if (0.0f < fv) {
                flag = 0;
                if (*(u8 **)(g + 0x2530) != 0 && (*(u8 **)(g + 0x2530))[0x27B] != 0) {
                    if ((b68_unscramble(g + 0x19E4) ^ 0x31) == 0) flag = 1;
                }
                if (!flag) {
                    s32 st = *(s32 *)(g + 0x254C);
                    if (st == 1 || st == 4) {
                        if (*(s32 *)(obj + 0x2D8) == 0) {
                            func_L39_00667208(obj, idv, 2, -1);
                            return;
                        }
                    }
                }
            }
        }
        func_L39_00667208(obj, idv, 0xC, D_001A5E3C[0]);
        return;
    case 11:
        if (g == 0) return;
        obj = func_L39_006685D8(owner);
        w = b68_unscramble(g + 0x19E6);
        if ((w ^ 0x14) != 0) {
            w = b68_unscramble(g + 0x2476);
            fv = *(f32 *)&w;
            if (g[0x2476] == 0) fv = 0.0f;
            if (0.0f < fv && (u32)(*(s32 *)(g + 0x254C) - 2) < 2) {
                flag = 0;
                if (*(u8 **)(g + 0x2530) != 0 && (*(u8 **)(g + 0x2530))[0x27B] != 0) {
                    if ((b68_unscramble(g + 0x19E4) ^ 0x31) == 0) flag = 1;
                }
                if (!flag && *(s32 *)(obj + 0x2DC) == 0) {
                    func_L39_00667208(obj, idv, 3, -1);
                    return;
                }
            }
        }
        func_L39_00667208(obj, idv, 0xD, D_001A5E3C[0]);
        return;
    case 2:
        if (g == 0) return;
        func_L39_00667908(1, owner);
        obj = func_L39_006685D8(owner);
        if (obj == 0) return;
        *(s32 *)(obj + 0x31C) = 0;
        if (*(s32 *)(obj + 0x2D8) != 0) return;
        if ((s32)g == *(s32 *)(obj + 0x2DC)) func_L39_006673E8(obj, g, 0);
        func_L39_00667540(obj, g);
        return;
    case 3:
        if (g == 0) return;
        func_L39_00667908(2, owner);
        obj = func_L39_006685D8(owner);
        if (obj == 0) return;
        *(s32 *)(obj + 0x320) = 0;
        if (*(s32 *)(obj + 0x2DC) != 0) return;
        if (*(s32 *)(obj + 0x2D8) == (s32)g) {
            if (g[0x1A14] != 0) {
                func_00382810(g[0x24C9], 0x1E, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
                *(u32 *)(obj + 0x2F8) |= 2;
            }
            func_L39_00667700(obj, g, 0);
        }
        func_L39_006672C0(obj, g);
        return;
    case 4:
        obj = func_L39_006685D8(owner);
        if (obj == 0) return;
        func_L39_00667700(obj, g, 0);
        return;
    case 5:
        obj = func_L39_006685D8(owner);
        if (obj == 0) return;
        func_L39_006673E8(obj, g, 0);
        return;
    default:
        return;
    }
}
