/* functional: medium. Init routine of the same Thran object family (called from state 0 of func_L19_00332948): sets flags, ground height via func_003C3D30, fills the extra record at +0x68 with tuning floats per object type (0x940/0x93C/0xA59), zeroes its fields and sequence counters, sets the starting animation. Not hand-asm; the two 16-byte zero stores are written as 4 words each. Float constants decoded from the retail hex. */
extern s32 D_L19_001DCBE0;
extern s32 D_001DCBD0_sda, D_001DCBD4_sda;
extern void func_L19_00333468(void *);

void func_L19_00333160(u8 *obj) {
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 tmp[4];
    f32 f;
    s32 t;
    s32 r;

    if (func_00382468(2) != 0) {
        *(u16 *)(obj + 0x34) |= 0x8000;
    } else {
        *(u16 *)(obj + 0x34) &= 0x7FFF;
    }
    obj[0x7E] |= 1;
    D_L19_001DCBE0 = 0;
    D_001DCBD4_sda = 0;
    *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
    if (*(s32 *)(pv + 0x350) == 0) {
        func_L19_00333468(obj);
    }
    *(f32 *)(pv + 0x30) = 1.0f;
    *(s16 *)(pv + 0x34) = 1;
    pv[0x38] = 3;
    *(f32 *)(pv + 0x144) = 0.1f;
    *(f32 *)(pv + 0x14C) = 0.5f;
    *(f32 *)(pv + 0x150) = 1.5882496f;
    *(f32 *)(pv + 0x170) = 0.5235988f;
    *(u8 **)(pv + 0x188) = pv + 0x230;
    *(u8 **)(pv + 0x18C) = pv + 0x2B0;
    *(f32 *)(pv + 0x16C) = 0.008f;
    *(f32 *)(pv + 0x174) = 0.5f;
    *(f32 *)(pv + 0x140) = 0.1f;
    *(f32 *)(pv + 0x148) = 0.5f;
    switch (*(s16 *)(obj + 0xAA)) {
    case 0x940:
        *(f32 *)(pv + 0x140) = 0.39f;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.089f;
        func_0038CF68(tmp, obj + 0xC0, -0.2f);
        *(f32 *)(obj + 0x10) = tmp[0] + *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0x14) = tmp[1] + *(f32 *)(obj + 0x14);
        *(f32 *)(obj + 0x18) = tmp[2] + *(f32 *)(obj + 0x18);
        *(s32 *)(pv + 0x358) = 0;
        break;
    case 0x93C:
    case 0xA59:
        *(f32 *)(pv + 0x140) = 0.42f;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.089f;
        *(s32 *)(pv + 0x358) = 0;
        break;
    default:
        *(f32 *)(pv + 0x140) = 0.1f;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.089f;
        *(s32 *)(pv + 0x358) = 0;
        break;
    }
    for (t = 0x35C; t <= 0x38C; t += 4) {
        *(s32 *)(pv + t) = 0;
    }
    *(s32 *)(pv + 0x3A0) = 0;
    f = *(f32 *)(obj + 0x18);
    t = D_001DCBD0_sda;
    *(s32 *)(pv + 0x3B0) = t;
    *(s32 *)(pv + 0x3A8) = -1;
    D_001DCBD0_sda = t + 1;
    *(f32 *)(pv + 0x3A4) = f;
    *(s32 *)(pv + 0x3B4) = 0;
    if (*(f32 *)(pv + 0x3BC) <= -999.0f) {
        *(f32 *)(pv + 0x3BC) = f - 10.0f;
    }
    *(s32 *)(pv + 0x3D0) = 0;
    *(s32 *)(pv + 0x3D4) = 0;
    *(s32 *)(pv + 0x3D8) = 0;
    *(s32 *)(pv + 0x3DC) = 0;
    *(s32 *)(pv + 0x3C0) = 0;
    *(s32 *)(pv + 0x3C4) = 0;
    *(s32 *)(pv + 0x3C8) = 0;
    *(s32 *)(pv + 0x3CC) = 0;
    func_L01_004450F0(obj, 1, 0);
    if (*(s16 *)(obj + 0xAA) == 0xA59) {
        if (obj[0x43] != 6) {
            func_003C3A10(obj, 6, 0, 0);
        }
    } else if (obj[0x43] != 0) {
        r = func_00382468(*(u8 *)(*(u8 **)(*(u8 **)(obj + 0x24) + 0x48) + 0x10));
        func_003C3A10(obj, 0, r, 0);
    }
}
