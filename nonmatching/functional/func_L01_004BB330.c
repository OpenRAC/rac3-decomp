/* functional: high. Rebuilds the slot list at D_L01_002446C0 (count +0x740, slots from +0x140, stride 0x24) from the 38 records of D_L01_002BD300 (stride 0x24) whose level word (+0x14) is <= the value from func_L01_00452818; each slot copies the record's fields, calls func_L01_00435FC8 (zero the +0x144 field if it returns non-zero), func_00381FF0 (result at +0x154) and sets a flag byte at +0x160 when (rec+8 & D_001D54D0) == rec+0xC. Field names unknown (probably a shop/upgrade list). */
extern u8 D_L01_002BD300[];
extern s32 D_001D54D0;
extern s32 func_L01_00452818(void);
extern s32 func_L01_00435FC8(s32);
extern s32 func_00381FF0(s32);

void func_L01_004BB330(void) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *p;
    s32 cur;
    s32 cnt;
    s32 v8;
    s32 vC;
    s32 r;

    cur = func_L01_00452818();
    *(s32 *)(T + 0x740) = 0;
    for (p = D_L01_002BD300; p < D_L01_002BD300 + 0x558; p += 0x24) {
        if (cur < *(s32 *)(p + 0x14)) {
            continue;
        }
        cnt = *(s32 *)(T + 0x740);
        *(s32 *)(T + 0x144 + cnt * 0x24) = *(s32 *)(p + 0x18);
        if (func_L01_00435FC8(*(s32 *)p) != 0) {
            *(s32 *)(T + 0x144 + *(s32 *)(T + 0x740) * 0x24) = 0;
        }
        cnt = *(s32 *)(T + 0x740);
        *(s32 *)(T + 0x140 + cnt * 0x24) = *(s32 *)(p + 0x10);
        r = func_00381FF0(*(s32 *)(p + 4));
        cnt = *(s32 *)(T + 0x740);
        v8 = *(s32 *)(p + 8);
        vC = *(s32 *)(p + 0xC);
        *(s32 *)(T + 0x154 + cnt * 0x24) = r;
        *(s32 *)(T + 0x15C + cnt * 0x24) = *(s32 *)(p + 0x1C);
        *(s32 *)(T + 0x148 + cnt * 0x24) = v8;
        *(s32 *)(T + 0x14C + cnt * 0x24) = vC;
        *(s32 *)(T + 0x150 + cnt * 0x24) = *(s32 *)p;
        *(u8 *)(T + 0x160 + cnt * 0x24) = ((v8 & D_001D54D0) == vC);
        *(s32 *)(T + 0x740) = cnt + 1;
    }
}
