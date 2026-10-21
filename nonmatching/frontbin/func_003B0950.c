/* Near miss of func_003B0950 with its file's own flags: tools/check.py reports 107 diff
   (the version it replaces: 123).
*/

/* PAL candidate for func_003B0950.
   The US draft used the US addresses; PAL has the flag buffer at
   D_00226420 + 0x7F00 (= D_0022E320). */

/* localdecomp:start func_003B0950 */
extern s32 func_13D1B0();
extern void func_003B0728(u8 *, s32, s32, s32);
extern S_2224A0 D_00226420;
void func_003B0950(s32 *arg0) {
    S_3AB3A8 *o = (S_3AB3A8 *)arg0;
    s32 n = 0;
    s32 i, j, k;
    u8 *src, *dst;
    switch (o->x0) {
    case 1:
        if (o->x3C < 0x1000) return;
        n = 0x1000 - o->x50;
        break;
    case 2:
        n = (func_13D1B0() - o->x60) & 0xFFF;
        break;
    case 3:
        return;
    }
    while (n >= 0x100 && o->x3C >= o->x18 << 8) {
        s32 m = n - 0x100;
        for (i = 0; i < o->x18; i++) {
            S_2224A0 *hdr = &D_00226420;
            u8 *h = hdr->buf;
            dst = &D_0022E320[0];
            k = 0;
            src = (u8 *)o->x34 + (o->x38 - o->x3C + o->x40) % o->x40;
            src += i * o->x1C;
            do {
                for (j = 0; j < o->x1C; j++) {
                    *dst++ = *src++;
                    k++;
                }
                src += o->x1C * (o->x18 - 1);
            } while (k < 0x100);
            if (o->x60 + 0x100 == 0x1000) hdr->buf[0xF1] = 3;
            if (o->x60 == 0) {
                h[1] = 6;
                h[0x11] = 2;
            }
            func_003B0728((u8 *)o, (s32)&D_0022E320[0], 0x100, (i << 12) + o->x60);
        }
        o->x60 = (o->x60 + 0x100) % 0x1000;
        o->x3C -= o->x18 << 8;
        o->x50 += 0x100;
        n = m;
    }
}
/* localdecomp:end func_003B0950 */
