/* functional: high. Same reads/writes/calls as retail read against the asm; vadd.xyz is plain float adds on xyz with w kept (as vadd.xyz does). Retail's gp-relative stores of the D_L01_001DF9xx floats are plain globals here. Reuses the file's own Type_004A3A90 declarations for D_L01_001E001C/001E0020 (cast to u8 *); 0x1CD018 is D_001CCFD0+0x48. */
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_001CCFD0[];
extern char D_L01_00237800[];
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
extern s32 D_L01_001F3F40;
extern void func_0038CB78(unsigned int *, unsigned int, int);
extern Type_004A3A90 *D_L01_001E0020;
__asm__(".extern D_L01_001E0020, 16");
extern void *func_0038CC88(void *, void *, s32);
extern void func_L01_0042B068(s32, s32);
extern void func_L01_004ED3F8(s32, s32);
extern void func_003C7C38(s32);
extern void func_0038D308(s32, void *);
extern void func_L01_003F5AC0(s32, s32);
extern void func_L01_004A3B88(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412FE0(void *, void *, f32, f32);

typedef struct { f32 x, y, z, w; } V4_004A3848 __attribute__((aligned(16)));

void func_L01_004A3848(void) {
    u8 *e = (u8 *)D_L01_00237800;
    u8 *g = D_001A4BE0;
    V4_004A3848 v;
    s32 cur;
    s32 saved;
    s32 k;
    s32 id;
    s32 i;
    u8 *p;

    g[0x25F7] = 0xF;
    if (*(s32 *)e == 0) {
        func_0038CB78((unsigned int *)D_L01_00236B90, 0, 0xC70);
        return;
    }
    func_0038CC88(D_L01_00236B90, e, 0xC70);
    *(V4_004A3848 *)(g + 0x80) = *(V4_004A3848 *)(e + 0x10);
    *(V4_004A3848 *)(g + 0x90) = *(V4_004A3848 *)(e + 0x20);
    *(s32 *)(*(s32 *)(g + 0x25C0) + 0x38) = *(s32 *)(e + 0x30);
    *(s32 *)(*(s32 *)(g + 0x25C0) + 0x3C) = *(s32 *)(e + 0x34);
    D_001A30B0[0x43] |= 7;
    saved = *(s32 *)(e + 0xC68);
    cur = D_L01_001F3F40;
    *(u16 *)(D_001CCFD0 + 0x48) = *(u16 *)(e + 0xC64);
    *(s32 *)(D_001A30B0 + 0xB4) = *(s32 *)(e + 0x38);
    D_001A30B0[0x40] = e[0x3C];
    D_001A30B0[0x41] = e[0x3D];
    D_001A30B0[0x42] = e[0x3E];
    if (cur != saved) {
        func_L01_0042B068(saved, *(s32 *)(e + 0xC64));
    }
    D_L01_001DF9E4 = e[0x3F];
    D_L01_001DF9E5 = e[0x40];
    D_L01_001DF9E6 = e[0x41];
    D_L01_001DF9E8 = *(f32 *)(e + 0x44);
    D_L01_001DF9EC = *(f32 *)(e + 0x48);
    D_L01_001DF9F0 = *(f32 *)(e + 0x4C);
    D_L01_001DF9F4 = *(f32 *)(e + 0x50);
    k = *(s32 *)(e + 0x54);
    if (k != 0 && k != 3) {
        if (k == 1) {
            id = 0x57;
        } else if (k == 2) {
            id = 0x1A3;
        } else {
            id = 0;
        }
        for (i = 0; (u8 *)D_L01_001E001C + (i << 8) < (u8 *)D_L01_001E0020; i++) {
            p = (u8 *)D_L01_001E001C + (i << 8);
            if (*(s16 *)(p + 0xAA) == id) {
                func_L01_004ED3F8(*(s32 *)(e + 0x54), *(s32 *)(e + 0x5C));
                break;
            }
        }
    }
    func_003C7C38(*(s32 *)(g + 0x25C0));
    func_0038D308(*(s32 *)(g + 0x25C0) + 0xC0, g + 0x90);
    func_L01_003F5AC0(0, 1);
    func_L01_004A3B88();
    func_0038CF68(&v, g + 0x20, *(f32 *)(g + 0x16CC));
    v.x = v.x + *(f32 *)(g + 0x80);
    v.y = v.y + *(f32 *)(g + 0x84);
    v.z = v.z + *(f32 *)(g + 0x88);
    func_L01_00412FE0(g + 0x1540, &v, *(f32 *)(g + 0x98), 0.0f);
}
