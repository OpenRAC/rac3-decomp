/* functional: high. Register allocation differs only; behaviour identical (TI 128-bit copy via mode(TI)) */
typedef int Q_3A4180 __attribute__((mode(TI)));
extern void func_003C2F58(void *, s32, void *);
extern void func_003C7C38(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L01_003A4180(u8 *obj) {
    Q_3A4180 pos;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 **slot = (u8 **)(p + 0x2F0);
    s32 i;
    for (i = 0; i < 2; i++, slot++) {
        u8 *child = *slot;
        if (child != 0 && *(s16 *)(child + 0xAA) == 0x1939 && *(u8 **)(child + 0xB8) == obj &&
            child[0x20] != 0xFE && child[0x20] != 0xFD) {
            u8 *v = *(u8 **)(child + 0x68);
            if (i != 0) {
                func_003C2F58(obj, 3, &pos);
            } else {
                func_003C2F58(obj, 2, &pos);
            }
            *(Q_3A4180 *)(v + 0x20) = pos;
        } else {
            *slot = 0;
        }
    }
    slot = (u8 **)(p + 0x3F0);
    for (i = 7; i >= 0; i--, slot++) {
        if (*slot != 0) {
            *(s32 *)(*slot + 0x98) = 0;
            func_003C7C38(*slot);
        }
    }
    func_L01_0044E850(obj, p + 0x300, 4, 0.04297f, 0.43255f);
    func_0038CAD0(p + 0x2E0);
    func_0038CB00(p + 0x2E4);
    if (*(u16 *)(obj + 0x96) < 0xFFFF) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    func_L01_00451DF8(obj, p + 0x250, 5, 1, 2.5f);
}
