/* func_L19_003AD6B0: 91 rows from check.py, nearly all a 4-byte shift; after alignment three spots differ (see nonmatching/README.md). Needs @ps2as on L19_003AD6B0.c (inline 1.1f). */
typedef struct { u8 pad0[0x80]; u8 x80[0x10]; u8 x90[0x10]; u8 pada0[0x35C - 0xA0]; u8 *x35C; s32 x360; u8 pad364[0x25C0 - 0x364]; u8 *x25C0; } G_3AD6B0;
typedef struct { u8 pad[0x18]; u8 *x18; } H_3AD6B0;
extern G_3AD6B0 D_001A4BE0;
extern H_3AD6B0 D_L19_001E8E40;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001D5570[];
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(void *, void *);
extern u8 *func_L01_0045B958(void);

s32 func_L19_003AD6B0(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *q;
    s32 h;
    H_3AD6B0 *e;

    if (*(s32 *)(p + 0x20) != 0) {
        if (D_001BBC40[obj[0xB0] + D_001D545C * 16] & 0x80)
            return 1;
    }
    if (*(s32 *)(p + 0x30) != 0) {
        if (D_001D5570[*(s32 *)(p + 0x30)] != 0)
            return 1;
    }
    if (D_001A4BE0.x35C == obj) {
        if (D_001A4BE0.x360 >= 2)
            return 1;
    }
    if (func_L01_003FB640(obj + 0x10, 1, obj, *(f32 *)(obj + 0x2C) * 1.1f / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24)) == 0)
        return 0;
    if (D_L19_001E8E40.x18 == 0)
        return 0;
    if (D_L19_001E8E40.x18 == D_001A4BE0.x25C0 && D_001A4BE0.x35C == obj) {
        if (*(s32 *)(p + 0x20) == 0)
            return 1;
        func_L01_0043B510(obj[0xB0]);
        func_L01_004A3610(D_001A4BE0.x80, D_001A4BE0.x90);
        return 1;
    }
    e = &D_L19_001E8E40;
    if ((*(u16 *)(e->x18 + 0x34) & 0x20) == 0)
        return 0;
    q = func_L01_0045B958();
    if (q == 0)
        return 0;
    if (*(u8 **)(q + 0x88) != obj && *(u8 **)(q + 0x84) != obj)
        return 0;
    h = *(s16 *)(e->x18 + 0xAA);
    if (h == 0x1A4E || h == 0x1AA0 || h == 0x1BD3 || h == 0x16BE || h == 0x1BA0)
        return 1;
    return 0;
}
