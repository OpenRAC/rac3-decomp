/* functional: high. No draft; written from PAL asm, compiles (94 diff). func_001306F8 is the unsigned long helper declared in other levels; result used as (ret<<16)>>32; return is 1 only for the high-offset odd case */
/* localdecomp:start func_L40_00449828 */
extern u8 D_L40_003A8FB8[];
extern unsigned long func_001306F8(unsigned long, unsigned long);

s32 func_L40_00449828(u32 a0, s32 *a1, s32 *a2, u16 *a3) {
    s32 flag = 0;
    s32 q, r, o1, r8, t;
    u32 hi;
    s32 pos, v;
    s32 cnt;
    u8 *tbl;
    s32 i, j, n;
    s32 idx[2];
    s32 base;

    if (a0 & 1) {
        a0 >>= 1;
        q = a0 / 0x1E1;
        r = a0 % 0x1E1;
        o1 = q << 3;
        r8 = (r + 1) << 3;
        *a1 = o1;
        if (0x2000000 < o1) {
            t = o1 - 0x2000000;
            flag = 1;
            *a1 = t;
            *a2 = t;
            *a1 = *a1 + r8;
        } else {
            *a2 = o1 + r8;
        }
        *a3 = (u16)-1;
        return flag != 0;
    }

    hi = (a0 >> 4) & 0xFFFF;
    pos = (s32)((long)func_001306F8(*(s32 *)(D_L40_003A8FB8 + 0xC), hi) << 16 >> 32) & ~7;
    pos += hi;
    cnt = *(s16 *)(D_L40_003A8FB8 + 6);
    tbl = D_L40_003A8FB8 + 0x1A0;
    idx[0] = 0;
    if (!(pos < *(s32 *)(tbl + 4))) {
        i = 0;
        do {
            n = (i + 1) % cnt;
            pos += *(s32 *)(tbl + n * 8) - *(s32 *)(tbl + i * 8 + 4);
            i = n;
        } while (!(pos < *(s32 *)(tbl + i * 8 + 4)));
        idx[0] = i;
    }
    cnt = *(s16 *)(D_L40_003A8FB8 + 6);
    base = (*(s32 *)(D_L40_003A8FB8 + 0xC) >> 11) << 3;
    idx[1] = idx[0];
    v = base + ((base + (a0 >> 20)) << 8) + pos;
    if (!(v < *(s32 *)(tbl + idx[0] * 8 + 4))) {
        j = idx[1];
        do {
            n = (j + 1) % cnt;
            v += *(s32 *)(tbl + n * 8) - *(s32 *)(tbl + j * 8 + 4);
            j = n;
        } while (!(v < *(s32 *)(tbl + j * 8 + 4)));
        idx[1] = j;
    }
    *a1 = pos;
    *a2 = v;
    *a3 = (u16)idx[0];
    return 0;
}
/* localdecomp:end func_L40_00449828 */
