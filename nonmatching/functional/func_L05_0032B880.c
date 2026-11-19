/* functional: high. PAL twin of the NTSC-U draft with PAL constants (lifetime 25 / 250 vs 30 / 300) and callees renamed to catalogue names; check.py shows scheduling/constant-materialisation order only. */
typedef int u128_32B880 __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(void *);

u8 *func_L05_0032B880(void *pos, void *vel, s32 col, f32 f) {
    u8 *obj;
    u8 *p;

    obj = func_003C24B0(0x184D, 0x80);
    if (obj != 0) {
        obj[0x31] = 1;
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0x1FF;
        obj[0x23] = 0x60;
        p = *(u8 **)(obj + 0x68);
        obj[0x20] = 0;
        if (col != 0) {
            *(s32 *)(obj + 0xB8) = col;
        }
        *(u128_32B880 *)(obj + 0x10) = *(u128_32B880 *)pos;
        *(s32 *)(p + 0x10) = 25;
        *(f32 *)(p + 0x20) = f;
        *(u128_32B880 *)p = *(u128_32B880 *)vel;
        *(s32 *)(p + 0x18) = 250;
        *(s32 *)(p + 0x14) = 0;
        *(f32 *)(obj + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(obj + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(obj + 0xFC) = 0;
        *(f32 *)(obj + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        func_003C7C38(obj);
    }
    return obj;
}
