/* functional: high. Matches structurally (83 diff words are only VU0 lqc2/vadd vs scalar float code). VU0 vadd.xyz replaced by plain float xyz math with w kept from a2. exact=no */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_4C638;
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);

s32 func_L01_0044C638(s32 a0, u8 *a1, Vec_4C638 *a2, Vec_4C638 *a3, Vec_4C638 *a4, Vec_4C638 *a5) {
    Vec_4C638 m0[4];
    Vec_4C638 m1[4];
    Vec_4C638 m2[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        *a4 = *a2;
        *a5 = *a3;
        return 0;
    }
    func_0038D328(m0, p);
    a4->x = a2->x + ((Vec_4C638 *)(p + 0x10))->x;
    a4->y = a2->y + ((Vec_4C638 *)(p + 0x10))->y;
    a4->z = a2->z + ((Vec_4C638 *)(p + 0x10))->z;
    a4->w = a2->w;
    a4->x = a4->x - ((Vec_4C638 *)(a1 + 0x10))->x;
    a4->y = a4->y - ((Vec_4C638 *)(a1 + 0x10))->y;
    a4->z = a4->z - ((Vec_4C638 *)(a1 + 0x10))->z;
    if (*(s32 *)(p + 0x3C) & 2) {
        func_0038D328(m2, p + 0x20);
        func_0038D5B0(m1, m2);
        func_0038D000(a4, a4, m1);
        func_0038D000(a4, a4, a1 + 0xC0);
    } else {
        func_0038D000(a4, a4, m0);
    }
    a4->x = a4->x + ((Vec_4C638 *)(a1 + 0x10))->x;
    a4->y = a4->y + ((Vec_4C638 *)(a1 + 0x10))->y;
    a4->z = a4->z + ((Vec_4C638 *)(a1 + 0x10))->z;
    func_0038D328(m1, a3);
    func_0038D640(m1, m0, m1);
    func_003C48A8(m1, a5);
    return 1;
}
