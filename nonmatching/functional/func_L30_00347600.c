/* functional: high. From asm; func_003D3CB0 cast to the file's char* prototype; D_L30_001E9020 is an int128 in this file so read as f32[3]; 135 diff = scheduling */
extern f32 D_L30_001DD010;
extern f32 D_L30_001DD000;
__asm__(".extern D_L30_001DD010, 4");
__asm__(".extern D_L30_001DD000, 4");
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern int func_003D3CB0(char *first, char *second, int mode, int flag, int extra);

s32 func_L30_00347600(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    vu0_v4 step;
    f32 delta = 0.0f;
    f32 ang;
    f32 len;

    do {
        ang = func_0038DB48(*(f32 *)(v + 0x48) + delta);
        step.x = func_0038D098(ang) * (*(f32 *)(v + 0x40) + *(f32 *)(v + 0x44));
        step.y = 0.0f;
        step.z = func_0038D0B0(ang) * (*(f32 *)(v + 0x40) + *(f32 *)(v + 0x44));
        step.x += *(f32 *)(obj + 0x10);
        step.y += *(f32 *)(obj + 0x14);
        step.z += *(f32 *)(obj + 0x18);
        if (func_003D3CB0((char *)(obj + 0x10), (char *)&step, 0x12, (int)obj, 0) != 0) {
            *(f32 *)(v + 0x48) = ang;
            step.x = ((f32 *)&D_L30_001E9020)[0] - *(f32 *)(obj + 0x10);
            step.y = ((f32 *)&D_L30_001E9020)[1] - *(f32 *)(obj + 0x14);
            step.z = ((f32 *)&D_L30_001E9020)[2] - *(f32 *)(obj + 0x18);
            if (*(f32 *)(v + 0x40) < func_0038CEA8(&step)) {
                func_0038CF68(&step, &step, func_0038CEA8(&step) - *(f32 *)(v + 0x40));
                *(f32 *)(obj + 0x10) += step.x;
                *(f32 *)(obj + 0x14) += step.y;
                *(f32 *)(obj + 0x18) += step.z;
            }
            return 1;
        }
        if (delta <= 0.0f) {
            delta = D_L30_001DD010 - delta;
        } else {
            delta = -delta;
        }
    } while (delta < 1.5707964f);
    step.x = func_0038D098(*(f32 *)(v + 0x48)) * D_L30_001DD000;
    step.y = 0.0f;
    step.z = func_0038D0B0(*(f32 *)(v + 0x48)) * D_L30_001DD000;
    *(f32 *)(obj + 0x10) += step.x;
    *(f32 *)(obj + 0x14) += step.y;
    *(f32 *)(obj + 0x18) += step.z;
    return 0;
}
