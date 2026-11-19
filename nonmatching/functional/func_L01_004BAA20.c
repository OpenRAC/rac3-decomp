/* functional: high. Rebuilds the Veldin slot list at D_L01_002446C0 (count at +0x740, slots from +0x140, stride 0x14) from the id table D_001D54D8 (32 u16 entries: 0xFFFF end/unused, bit 15 / bit 14 flags, id in the low 14 bits), filtered by item records (D_L01_002C5600, 0xF0 bytes each) and D_001427F0 limits, then adds the optional extra slots (mode 1) and re-finds the selected slot index (+0x80). Table layouts reverse-read from the asm, field names are mine. */
extern u16 D_001D54D8[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern s32 D_001D545C_sda;

extern s32 func_L01_0041A4F0(void);
extern void func_L01_004BA990(void);
extern void func_L01_004BA8F8(s32, s32, s32, s32);
extern void func_L01_004BA940(s32, s32);
extern void func_L01_004BF660(void);
extern s32 func_L01_004BB0F0(s32);

void func_L01_004BAA20(s32 a0) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *recs = (u8 *)D_L01_002C5600;
    s32 mode;
    s32 selId;
    s32 k;
    s32 i;
    s32 n;
    s32 id;
    u32 e;
    u8 *rec;

    *(s32 *)(T + 0x740) = 0;
    mode = 1;
    if (*(s32 *)(T + 0x5C) == 0) {
        mode = a0;
    }
    selId = *(s32 *)(T + *(s32 *)(T + 0x80) * 0x14 + 0x140);
    if (func_L01_0041A4F0() != 0) {
        func_L01_004BA990();
    }
    if (*(s32 *)(T + 0x744) == 0) {
        for (k = 0; k < 32; k++) {
            e = D_001D54D8[k];
            if (e == 0xFFFF) {
                continue;
            }
            if ((e >> 15) == 0) {
                continue;
            }
            id = e & 0x3FFF;
            rec = recs + D_001425C0[id] * 0xF0;
            if (*(u16 *)(rec + 0x84) == 0) {
                continue;
            }
            if (!(D_001427F0[id] < (s32)*(u16 *)(rec + 0x8A))) {
                continue;
            }
            if (*(s32 *)(T + 0x5C) != 0) {
                if ((u32)(id - 0x10) < 2 || id == 0x13 || id == 0x15 || id == 0x16) {
                    continue;
                }
            }
            func_L01_004BA8F8(*(s32 *)(T + 0x740), id, 1, 0);
            *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
        }
        func_L01_004BA940(*(s32 *)(T + 0x740), 0);
        *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
        for (k = 0; k < 32; k++) {
            e = D_001D54D8[k];
            if (e == 0xFFFF) {
                continue;
            }
            id = e & 0x3FFF;
            if ((e >> 15) == 0) {
                if (mode != 0) {
                    continue;
                }
                if (!(e & 0x4000)) {
                    if ((u32)(id - 0x10) < 2 || id == 0x13 || id == 0x15 || id == 0x16) {
                        if (func_L01_0041A4F0() == 0) {
                            goto flag15;
                        }
                        rec = recs + D_001425C0[id] * 0xF0;
                        if (rec[1] == 4) {
                            goto flag14;
                        }
                    }
                    func_L01_004BA8F8(*(s32 *)(T + 0x740), id, 0, 0);
                    *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
                    continue;
                }
                goto flag14;
            }
flag15:
flag14:
            if (mode != 0) {
                continue;
            }
            if (!(D_001D54D8[k] & 0x8000)) {
                continue;
            }
            if (func_L01_0041A4F0() == 0) {
                continue;
            }
            rec = recs + D_001425C0[id] * 0xF0;
            if (rec[1] != 4) {
                continue;
            }
            if (id == 0x97) {
                continue;
            }
            func_L01_004BA8F8(*(s32 *)(T + 0x740), id, 0, 1);
            *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
        }
    } else {
        for (k = 0; k < 32; k++) {
            e = D_001D54D8[k];
            if (e == 0xFFFF) {
                continue;
            }
            id = e & 0x3FFF;
            if ((u32)(id - 0x10) < 2 || id == 0x13 || id == 0x15 || id == 0x16) {
                func_L01_004BA8F8(*(s32 *)(T + 0x740), id, D_00142CA0[id] != 0, 0);
                *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
            }
        }
    }
    func_L01_004BF660();
    if (*(s32 *)(T + 0x744) != 0) {
        if (*(s32 *)(T + 0x770) == 0) {
            func_L01_004BA940(*(s32 *)(T + 0x740), 1);
            *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
        }
    } else {
        if (*(s32 *)(T + 0x77C) != 0 && func_L01_004BB0F0(5) != 0) {
            /* no extra slot */
        } else if (D_001D545C_sda == 3 || D_001D545C_sda == 6) {
            func_L01_004BA940(*(s32 *)(T + 0x740), 1);
            *(s32 *)(T + 0x740) = *(s32 *)(T + 0x740) + 1;
        }
    }
    n = *(s32 *)(T + 0x740);
    for (i = 0; i < n; i++) {
        if (*(s32 *)(T + 0x140 + i * 0x14) == selId) {
            *(s32 *)(T + 0x80) = i;
        }
    }
    n = *(s32 *)(T + 0x740) - 1;
    if (n < *(s32 *)(T + 0x80)) {
        *(s32 *)(T + 0x80) = n;
    } else if (*(s32 *)(T + 0x80) < 0) {
        *(s32 *)(T + 0x80) = 0;
    }
}
