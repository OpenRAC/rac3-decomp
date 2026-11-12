/* func_L19_003C2628: 20 diff, one register swap (obj/p: $s1/$s2); file L19_003C0938.c already @ps2as. */
typedef struct { f32 x, y, z, w; } V_3C2628 __attribute__((aligned(16)));
__asm__(".extern D_001DE800, 4");
__asm__(".extern D_001DE840, 4");
__asm__(".extern D_001DE808, 8");
__asm__(".extern D_001DE820, 8");
extern s32 D_001DE800;
extern f32 D_001DE840;
extern f32 D_001DE808[2];
extern f32 D_001DE820[2];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045AA10(f32);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045AA30(void *, void *);

void func_L19_003C2628(void *objp, void *a5, int state, float fv) {
    u8 *obj = objp;
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C2628 v;
    f32 s;

    if (state != *(s32 *)(p + 0x418)) {
        if (state == 2)
            *(f32 *)(obj + 0x48) = D_001DE840;
        if (D_001DE800 != 0)
            *(f32 *)(obj + 0x48) = 0.1f;
        s = *(f32 *)(obj + 0x48);
        func_L01_0045BD78(obj, D_001DE820[state] * s, D_001DE808[state] * s, s * 0.0050265486f, s * 0.12566371f);
        if (state == 3)
            *(s32 *)(p + 0xA8) = 0x514;
        else
            *(s32 *)(p + 0xA8) = 0;
    }
    *(s32 *)(p + 0x418) = state;
    switch (state) {
    case 0:
        func_L01_0045AA10(fv);
        func_L01_0045BD10(obj, fv);
        break;
    case 1:
    case 2:
        func_L01_0045A748(obj, a5);
        break;
    case 3:
        v = *(V_3C2628 *)(p + 0x110);
        v.z = *(f32 *)(p + 0x448);
        *(f32 *)(p + 0x448) = *(f32 *)(p + 0x448) - (*(f32 *)(p + 0x9C) + *(f32 *)(p + 0x9C));
        func_L01_0045AA30(obj, &v);
        break;
    }
}
