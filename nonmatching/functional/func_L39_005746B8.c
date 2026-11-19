/* functional: medium. Loop 0..2pi step pi/10 (20 samples); func_L01_00451768 returns a float height. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_46B8;
extern u8 D_L39_0024DE00[];
extern u8 D_L39_0024DCC0[];
extern u8 D_001FE020[];
extern u8 D_001FE100[];
extern f32 D_001E0088_sda;
extern f32 D_001D5A8C_sda;
extern void func_0038D890(void *dst, void *src, void *axis, float ang);
extern float func_L01_00451768(void *pos);
extern void func_L39_005F3760(s32 slot, s32 vol);
extern s32 func_L39_005F35D8(s32 id, s32 flags, void *owner, s32 range);

void func_L39_005746B8(u8 *obj) {
    V_46B8 pos, dir, axis;
    u8 *t = *(u8 **)(obj + 8);
    V_46B8 *c = (V_46B8 *)D_L39_0024DE00;
    float ang = 0.0f, blocked = 0.0f, v;
    u8 *e;

    dir.x = 4.0f; dir.y = 0.0f; dir.z = 0.0f; dir.w = 1.0f;
    axis.x = 0.0f; axis.y = 0.0f; axis.z = 1.0f;
    do {
        func_0038D890(&pos, &dir, &axis, ang);
        pos.x += c->x; pos.y += c->y; pos.z += c->z;
        if (func_L01_00451768(&pos) < *(float *)(D_L39_0024DCC0 + 0x148)) blocked += 0.05f;
        ang += 0.31415927f;
    } while (ang < 6.2831855f);
    if (D_001E0088_sda < blocked) v = D_001E0088_sda + D_001D5A8C_sda * 0.2f;
    else v = D_001E0088_sda - D_001D5A8C_sda * 0.75f;
    D_001E0088_sda = v;
    if (1.0f < D_001E0088_sda) D_001E0088_sda = 1.0f;
    else if (D_001E0088_sda < 0.0f) D_001E0088_sda = 0.0f;
    e = D_001FE020 + (*(s32 *)(t + 8) << 7);
    if (*(void **)(e + 0x100) == obj && e[0xD0] != 0) {
        float lo = *(float *)(t + 4);
        func_L39_005F3760(*(s32 *)(t + 8), (s32)((lo + D_001E0088_sda) / (lo + 1.0f) * 1024.0f));
    }
    *(V_46B8 *)(D_001FE100 + (*(s32 *)(t + 8) << 7)) = *c;
    e = D_001FE020 + (*(s32 *)(t + 8) << 7);
    if (*(void **)(e + 0x100) == obj && e[0xD0] != 0) return;
    *(s32 *)(t + 8) = func_L39_005F35D8(*(s32 *)t, 0x15, obj, 0x400);
}
