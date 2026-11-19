/* functional: high. Structure matches retail; only VU0 vadd->scalar and register allocation differ (94 diff lines). callee names via functions.tsv */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_4C998;
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D570(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C4BB0(void *, f32);
extern s32 func_L01_0044CB18(u8 *a0, u8 *a1, Vec_4C998 *a2, Vec_4C998 *a3, Vec_4C998 *a4, Vec_4C998 *a5);
extern u8 *D_001A71A0[];

s32 func_L01_0044C998(u8 *a0, u8 *a1, Vec_4C998 *a2, Vec_4C998 *a3, Vec_4C998 *a4, Vec_4C998 *a5) {
    Vec_4C998 m0[4];
    Vec_4C998 m1[4];
    Vec_4C998 v80;
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x3C) & 0x40) {
        func_0038D328(m0, a1 + 0xF0);
    } else {
        func_0038D570(m0, a1 + 0xC0);
    }
    func_0038D000(a4, a2, m0);
    a4->x = a4->x + ((Vec_4C998 *)(a1 + 0x10))->x;
    a4->y = a4->y + ((Vec_4C998 *)(a1 + 0x10))->y;
    a4->z = a4->z + ((Vec_4C998 *)(a1 + 0x10))->z;
    func_0038D328(m1, a3);
    func_0038D640(m1, m0, m1);
    func_003C48A8(m1, a5);
    if (*(s32 *)(p + 0x3C) & 4) {
        a4->x = a4->x + ((Vec_4C998 *)(p + 0x10))->x;
        a4->y = a4->y + ((Vec_4C998 *)(p + 0x10))->y;
        a4->z = a4->z + ((Vec_4C998 *)(p + 0x10))->z;
        func_L01_0044CB18(a0, a1, a4, a5, a2, a3);
        return 1;
    }
    if (a0 != D_001A71A0[0] && a0[0x22] < a1[0x22]) {
        v80 = *(Vec_4C998 *)(p + 0x10);
        func_003C4BB0(&v80, 1.0f);
        a4->x = a4->x + v80.x;
        a4->y = a4->y + v80.y;
        a4->z = a4->z + v80.z;
    }
    return 1;
}
