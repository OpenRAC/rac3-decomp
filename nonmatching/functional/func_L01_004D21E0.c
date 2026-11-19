/* functional: high. No draft; written from asm. 119 diff words from constant-hoisting/scheduling; unsigned loop index conversion pattern matches retail */
extern s32 D_L01_001DFD60[];
extern f32 D_001DB76C_sda;
extern f32 D_001DB770_sda;
extern f32 D_001DB774_sda;
extern f32 D_001DB778_sda;
extern s32 D_001DB77C_sda;
extern s32 D_001DB780_sda;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004D2118(u8 *, s32, u32, s32, s32, s32);

void func_L01_004D21E0(u8 *obj, s32 i, s32 ax, s32 ay, s32 z) {
    u32 k;

    if (D_L01_001DFD60[0] == 0) {
        return;
    }
    for (k = 0; k < 8; k++) {
        f32 t = (f32)k;
        f32 ang;
        s32 x;
        s32 y;
        f32 dx;
        f32 dy;

        t = t + t;
        ang = t * 3.1415927f / (f32)D_L01_001DFD60[0] - 3.1415927f + 1.5707964f;
        dx = func_0038D098(ang) * 74.0f * D_001DB76C_sda;
        x = (s32)((f32)ax + D_001DB774_sda + (f32)(s32)dx);
        dy = func_0038D0B0(ang) * 74.0f * D_001DB770_sda;
        y = (s32)((f32)ay + D_001DB778_sda + (f32)(s32)dy);
        if (k == D_001DB780_sda) {
            func_L01_004D2118(obj, i, k, x, y + D_001DB77C_sda, z);
        } else {
            func_L01_004D2118(obj, i, k, x, y, z);
        }
    }
}
