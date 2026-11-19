/* functional: high. Structure matches retail; VU0 vadd/vsub.xyz written as float xyz math (w from the first operand); 98 diff words scheduling/VU only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_4C870;
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);

s32 func_L01_0044C870(s32 a0, u8 *a1, Vec_4C870 *a2, Vec_4C870 *a3) {
    Vec_4C870 m0[4];
    Vec_4C870 v40;
    Vec_4C870 m50[4];
    Vec_4C870 m90[4];
    Vec_4C870 vD0;
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        a3->x = 0.0f;
        a3->y = 0.0f;
        a3->z = 0.0f;
        a3->w = 0.0f;
        return 0;
    }
    func_0038D328(m0, p);
    vD0 = *(Vec_4C870 *)(a1 + 0x10);
    v40.x = a2->x + ((Vec_4C870 *)(p + 0x10))->x;
    v40.y = a2->y + ((Vec_4C870 *)(p + 0x10))->y;
    v40.z = a2->z + ((Vec_4C870 *)(p + 0x10))->z;
    v40.w = a2->w;
    v40.x = v40.x - vD0.x;
    v40.y = v40.y - vD0.y;
    v40.z = v40.z - vD0.z;
    if (*(s32 *)(p + 0x3C) & 2) {
        func_0038D328(m90, p + 0x20);
        func_0038D5B0(m50, m90);
        func_0038D000(&v40, &v40, m50);
        func_0038D000(&v40, &v40, a1 + 0xC0);
    } else {
        func_0038D000(&v40, &v40, m0);
    }
    v40.x = v40.x + ((Vec_4C870 *)(a1 + 0x10))->x;
    v40.y = v40.y + ((Vec_4C870 *)(a1 + 0x10))->y;
    v40.z = v40.z + ((Vec_4C870 *)(a1 + 0x10))->z;
    a3->x = v40.x - a2->x;
    a3->y = v40.y - a2->y;
    a3->z = v40.z - a2->z;
    a3->w = v40.w;
    return 1;
}
