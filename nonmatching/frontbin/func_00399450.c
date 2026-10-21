/* US draft of func_00399450 (rac3-uya-decomp func_00394660, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00399450 */
extern unsigned long D_001D9F60[];
extern unsigned long D_001D9F78[];
void func_00399450(unsigned long *p, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    unsigned long t0 = D_0022CAD0[idx * 3];
    unsigned long t1 = D_0022CAD0[idx * 3 + 1];
    unsigned long t2 = D_0022CAD0[idx * 3 + 2];
    if (idx >= 0) {
        p[0] = (((t1 & 0x1C) | 0x20) | ((unsigned long)b << 6)) | ((unsigned long)a << 32);
        p += 2;
        p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
        p += 2;
        p[0] = t0;
        p[2] = t2;
        return;
    }
    if (idx < -1) {
        unsigned long *q = D_001D9F60;
        if (idx == -3) q = D_001D9F78;
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = q[0];
        p[2] = q[2];
    } else {
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = 0x80000004CC007FFBUL;
        p[2] = 0;
    }
}
/* localdecomp:end func_00399450 */
