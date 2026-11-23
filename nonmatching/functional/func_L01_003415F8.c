/* functional: high. Not byte-exact (movz/movn, scheduling); behaviour verified. Returns obj or 0. */
__asm__(".extern D_001DD298_sda, 4");
extern s32 D_001DD298_sda;
__asm__(".extern D_001DD260_sda, 4");
extern f32 D_001DD260_sda;
extern f32 D_001E19D4_sda;
extern u8 D_L01_001FE62C[1];
extern s32 D_L01_001FD180[] __attribute__((section(".sdata")));
extern vu0_q D_001A4C60;
extern s32 D_L01_001E194C[] __attribute__((section(".sdata")));
extern s32 D_L01_001E196C[] __attribute__((section(".sdata")));
extern s16 D_L01_001E1998[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_00278F80[][20];
extern vu0_v4 D_L01_001E1900[] __attribute__((section(".sdata")));
extern vu0_q D_L01_001E1910;
extern vu0_q D_L01_001E1920;
extern vu0_v4 D_L01_001E1930;
u8 *func_L01_003415F8(s32 kind) {
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_003A4FF8(void *, s32, s32, void *, s32);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_004C93E0(s32);
    extern f32 func_L01_004C93D8(void);
    extern void func_003A52A0(s32, s32, void *);
    u8 *obj, *p;
    s32 i;
    s32 *w;
    s32 j, k, n, t;
    s16 *h;
    void *x, *y, *z;
    vu0_v4 *vectors, *sum;
    s16 *small;
    s32 *counts;
    s32 class_id = 0xA5C;
    if (D_001DD298_sda) {
        func_003A4FF8(*(u8 **)((u8 *)D_L01_001FD180[D_L01_001FE62C[0]] + 0x28) + 0x80, 0, 0, &D_001A4C60, 0x400);
        return 0;
    } else if (!func_L01_005118D0(0x16, 1)) {
        func_003A4FF8(*(u8 **)((u8 *)D_L01_001FD180[D_L01_001FE62C[0]] + 0x28), 0, 0, &D_001A4C60, 0x400);
        return 0;
    }
    if (kind >= 4) class_id = 0x1192;
    obj = func_003C24B0(class_id, 0x80);
    if (obj) {
        p = *(u8 **)(obj + 0x68);
        D_001DD298_sda = (s32)obj;
        obj[0x30] = 0xFF;
        *(u16 *)(obj + 0x34) |= 0x41;
        obj[0x20] = 1;
        func_0038D308(obj + 0xC0, obj + 0xF0);
        x = obj + 0xC0;
        y = obj + 0xD0;
        z = obj + 0xE0;
        w = D_L01_001E194C;
        i = 3;
        do { *w = 0; i--; w--; } while(i >= 0);
        vectors = &D_L01_00278F80[0][0];
        sum = vectors + 60;
        small = (s16 *)(p + 0x18);
        func_0038CF68(vectors, obj + 0xC0, D_001DD260_sda);
        counts = (s32 *)(p + 0x20);
        *(vu0_q *)&D_L01_001E1900[0] = *(vu0_q *)(obj + 0xE0);
        func_0038CF68(vectors + 20, y, D_001DD260_sda);
        D_L01_001E1910 = *(vu0_q *)(obj + 0xC0);
        func_0038CF68(vectors + 40, z, D_001DD260_sda);
        D_L01_001E1920 = *(vu0_q *)(obj + 0xD0);
        vec_add_ba(sum, obj + 0xC0, obj + 0xE0);
        func_0038CF68(sum, sum, D_001DD260_sda);
        func_0038CE90(&D_L01_001E1930, sum, y);
        w = D_L01_001E196C;
        for (j=7; j>=0; j--) *w-- = 0;
        h = D_L01_001E1998;
        for (k=4; k>=0; k--) *h-- = 0;
        D_001E19D4_sda = 1.0f;
        func_L01_004C93E0(kind);
        *(f32 *)p = func_L01_004C93D8();
        *(vu0_q *)(obj + 0x10) = D_001A4C60;
        *(s32 *)(p + 0xC) = -1;
        *(s32 *)(p + 0x14) = 0x19;
        *(s32 *)(p + 0x10) = 0;
        for (n=3; n>=0; n--) small[n] = 0;
        for (t=3; t>=0; t--) counts[t] = 0;
        func_003A52A0(1, 0, obj);
    }
    return obj;
}
