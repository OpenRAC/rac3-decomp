/* functional: high. compiles; control flow mirrors retail, structure differs in bytes only */
extern void func_L01_003AB248(void *, void *);
extern s32 *func_L01_0043B548(s32, s32);
extern void func_L01_003ADCE8(void *, void *, void *);
extern s32 func_L01_003ADA68(void *, void *);
extern void func_003C2880(void *);
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_001E0058_sda;

void func_L01_003ACAD0(u8 *obj, s32 flag) {
    u8 *m = *(u8 **)(obj + 0x68);
    s32 *tbl;
    s32 *slots;
    s32 i;
    s32 idx;
    s16 *p;
    u8 *e;
    s32 r;
    void (*fn)(void *);

    func_L01_003AB248(obj, m);
    if (*(s32 *)(m + 0x50) == 0) {
        func_003C2880(obj);
        return;
    }
    tbl = func_L01_0043B548(0x19E1, 0x6C);
    slots = (s32 *)(m + 0xC90);
    ((void (*)(void *))tbl[0])(obj);
    for (i = 0; i < 4; i++) {
        idx = slots[i];
        if (idx == -1) {
            continue;
        }
        p = D_L01_0021DE20[idx];
        if ((idx & 0xFF) != 0xFF && !(D_001E0058_sda < idx) && p != 0) {
            for (;;) {
                if (p[-1] < 0) {
                    if (p != D_L01_0021DE20[slots[i]]) {
                        break;
                    }
                }
                e = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                p++;
                func_L01_003ADCE8(obj, m, e);
                idx = slots[i];
                if ((idx & 0xFF) == 0xFF) {
                    break;
                }
                if (D_001E0058_sda < idx) {
                    break;
                }
                if (p == 0) {
                    break;
                }
            }
        }
        *(s32 *)(m + 0xD0C) = i;
        for (;;) {
            r = func_L01_003ADA68(obj, m);
            if (r == 0) {
                break;
            }
            ((void (*)(void *))tbl[4])((void *)r);
        }
    }
    if (flag != 0) {
        fn = (void (*)(void *))(*(s32 *)(m + 0xD20) != 0 ? tbl[1] : tbl[3]);
        fn(obj);
    }
}
