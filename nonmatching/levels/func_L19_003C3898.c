/* func_L19_003C3898: 3 diff; file L19_003C0938.c now builds with @ps2as (func_L19_003C3788); only the 3 rows below differ. */
typedef struct { f32 x, y, z, w; } V_3C3898 __attribute__((aligned(16)));
typedef struct { u8 pad[0x12]; s16 h12; u8 pad2[0xC]; s32 *x20; u8 pad3[0xC]; } E_3C3898;
typedef struct { u8 pad[0x20]; E_3C3898 e[1]; } T_3C3898;
typedef struct { u8 pad[0x30]; V_3C3898 v; u8 pad2[0x40]; } P_3C3898;
extern T_3C3898 *D_001DF34C;
extern P_3C3898 *D_001DF800;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_003824E0(f32, f32);

void func_L19_003C3898(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    E_3C3898 *e = &D_001DF34C->e[*(s32 *)(p + 0x84)];
    V_3C3898 v;
    f32 a;

    if (e->h12 == 1) {
        P_3C3898 *tab = D_001DF800;

        *(s32 *)(p + 0x9C) = 0;
        v = tab[e->x20[0]].v;
    } else {
        P_3C3898 *tab = D_001DF800;
        s32 n = (*(s32 *)(p + 0x9C) + 1) % e->h12;

        *(s32 *)(p + 0x9C) = n;
        v = tab[e->x20[n]].v;
    }
    a = func_0038D160(v.x - *(f32 *)(obj + 0x10), v.y - *(f32 *)(obj + 0x14));
    *(f32 *)(p + 0xAC) = func_0038DB48(a - *(f32 *)(obj + 0xF8));
    *(f32 *)(p + 0xB8) = func_003824E0(0.5235988f, 1.0471976f);
}
