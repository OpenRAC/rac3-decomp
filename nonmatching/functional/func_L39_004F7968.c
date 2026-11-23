/* functional: high. Table walk, early-outs and output stores follow the retail blocks exactly; not byte-checked (file is @ee296, whose compiler does not run on the Mac), compiled with SN gcc and structure compared by eye. Table symbol is func_L39_00509558 (an INCLUDE_ASM data blob). */
extern s32 func_L39_00509558[];

/* look up `key` in the sorted-by-key table at func_L39_00509558 (word 0 = count,
 * then {key<<1|flag, offset} pairs, then the records); outputs record fields or zeros */
void func_L39_004F7968(u32 key, s32 *out0, s32 *out1, s32 *out2) {
    s32 *t;
    s32 off;
    s32 i;
    s32 n;
    s32 *rec;

    if (key == 0) {
        *out0 = 0;
        *out1 = 0;
        *out2 = 0;
        return;
    }
    t = func_L39_00509558;
    off = -1;
    n = t[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (((u32)t[1 + i * 2] >> 1) == key) {
                off = t[2 + i * 2];
                break;
            }
        }
    }
    if (off < 0) {
        *out0 = 0;
        *out1 = 0;
        *out2 = 0;
        return;
    }
    rec = (s32 *)((u8 *)&t[1 + n * 2] + off);
    *out0 = rec[0];
    *out1 = rec[1];
    *out2 = (s32)&rec[2];
}
