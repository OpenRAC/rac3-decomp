/* functional: high. compiles; 76 diff lines (regalloc/frame); mirrors retail loop incl. the -1 initial cached type */
extern char *func_L01_0043B568(int, int, int);
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;

s32 func_L01_003ADA68(void *obj, u8 *m) {
    s32 *slots = (s32 *)(m + 0xC90);
    s32 idx;
    s16 *p;
    u8 *e;
    s32 prev;
    s32 r;
    char *t;

    idx = slots[*(s32 *)(m + 0xD0C)];
    p = D_L01_0021DE20[idx];
    if ((idx & 0xFF) == 0xFF) {
        return 0;
    }
    if (D_L01_001E0058 < idx) {
        return 0;
    }
    if (p == 0) {
        return 0;
    }
    prev = -1;
    for (;;) {
        if (p[-1] < 0) {
            if (p != D_L01_0021DE20[slots[*(s32 *)(m + 0xD0C)]]) {
                return 0;
            }
        }
        e = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
        if (e == 0) {
            return 0;
        }
        if (*(s16 *)(e + 0xAA) != prev) {
            t = func_L01_0043B568(*(s16 *)(e + 0xAA), 2, 12);
            r = ((s32 (*)(s32))*(void **)t)(slots[*(s32 *)(m + 0xD0C)]);
            if (r != 0) {
                return r;
            }
            prev = *(s16 *)(e + 0xAA);
        }
        idx = slots[*(s32 *)(m + 0xD0C)];
        p++;
        if ((idx & 0xFF) == 0xFF) {
            return 0;
        }
        if (D_L01_001E0058 < idx) {
            return 0;
        }
        if (p == 0) {
            return 0;
        }
    }
}
