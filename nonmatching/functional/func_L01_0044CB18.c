/* functional: high. Structure matches retail; VU0 vsub->scalar float; 0xF0 matrix variant (flag 0x40) handled */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_4CB18;
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);

s32 func_L01_0044CB18(s32 a0, u8 *a1, Vec_4CB18 *a2, Vec_4CB18 *a3, Vec_4CB18 *a4, Vec_4CB18 *a5) {
    Vec_4CB18 m0[4];
    Vec_4CB18 v40;
    Vec_4CB18 m50[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x3C) & 0x40) {
        func_0038D328(m0, a1 + 0xF0);
        func_0038D5B0(m0, m0);
    } else {
        func_0038D5B0(m0, a1 + 0xC0);
    }
    v40.x = a2->x - ((Vec_4CB18 *)(a1 + 0x10))->x;
    v40.y = a2->y - ((Vec_4CB18 *)(a1 + 0x10))->y;
    v40.z = a2->z - ((Vec_4CB18 *)(a1 + 0x10))->z;
    v40.w = a2->w;
    func_0038D028(a4, &v40, m0);
    func_0038D328(m50, a3);
    func_0038D640(m50, m0, m50);
    func_003C48A8(m50, a5);
    return 1;
}
