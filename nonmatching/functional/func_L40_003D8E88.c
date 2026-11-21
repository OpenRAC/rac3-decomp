/* functional: high. not byte exact (store order/scheduling); sentinel D_L40_00241120 declared like neighbours */
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C7C38(u8 *m);

u8 *func_L40_003D8E88(s32 a0, s32 a1, u8 *msg) {
    u8 *m;
    u8 *v;
    f32 f20, f21;
    s32 sc, s17;

    m = func_L40_0053F570(0x19F6, *(s32 *)(msg + 0xC), *(s32 *)(msg + 4), func_L40_0053F2D8(msg), *(s32 *)(msg + 0x18));
    if (m != 0) {
        *(u8 *)(m + 0x30) = 0x7F;
        *(u16 *)(m + 0x32) = 0x7F;
        *(u16 *)(m + 0x34) |= 0x20;
        v = *(u8 **)(m + 0x68);
        if (*D_L40_00241120 >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        *(s32 *)(v + 0x1C0) = 0;
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x1B4) = 0;
        f20 = *(f32 *)(v + 0x1C4);
        sc = *(s32 *)(v + 0x1CC);
        f21 = *(f32 *)(v + 0x1C8);
        s17 = *(s32 *)(v + 0x1D0);
        func_0038CB78(v + 0x1A4, 0, 0x48);
        *(s32 *)(v + 0x1D0) = s17;
        *(s32 *)(v + 0x1B0) = 2;
        *(f32 *)(v + 0x1C8) = f21;
        *(f32 *)(v + 0x1C4) = f20;
        *(f32 *)(v + 0x30) = f20;
        *(s16 *)(v + 0x34) = (s32)f20;
        *(s32 *)(v + 0x1CC) = (sc > 0xF9) ? sc : 0xFA;
        func_003C7C38(m);
    }
    return m;
}
