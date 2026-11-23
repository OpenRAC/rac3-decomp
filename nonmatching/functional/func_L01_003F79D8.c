/* functional: high. 95 instruction positions differ at L01: retail saves registers with sq (needs an entry in config/levels/sq_ra_funcs.txt), and the early-return/arg-reload layout differs; all calls, constants and stores match as a multiset. */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00439880(u8 *, s32 *, s32 *);
extern s32 func_L01_00439A68(u8 *, s32);
extern u8 *func_L01_00448FF0(void *);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044E820(u8 *, s32);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(u8 *);
extern f32 func_0038D0B0(f32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern void func_L01_003F7CE0(u8 *, s32, s32, void *, void *, s32, s32, f32);
extern void func_L01_002FFF00(void);

u8 *func_L01_003F79D8(u8 *obj, s32 mode, s32 id, s32 sh, void *pos, void *rot, void *vel, s32 flag, f32 fa, f32 fb, s32 x10, s32 x11, s32 x12) {
    f32 q[4];
    s32 info[2];
    u8 *o2;
    u8 *rec;
    s32 key;
    f32 s;
    s32 t;

    flag &= 0xFF;
    if (id != 0xCDB && (u32)(mode - 1) < 2) {
        func_L01_00439880(obj, &info[0], &info[1]);
        if (((info[0] >> sh) ^ 1) & 1) {
            return 0;
        }
        if (mode == 2 && func_L01_00439A68(obj, sh) == 0) {
            return 0;
        }
    }
    o2 = func_003C24B0(id, x12);
    key = 0;
    rec = func_L01_00448FF0(obj);
    if (rec != 0) {
        key = (rec[4] | (rec[5] << 8) | (rec[6] << 16)) | 0x80000000;
    }
    if (o2 == 0) {
        return o2;
    }
    func_L01_00456160(o2, obj);
    if (key != 0) {
        func_L01_0044E820(o2, key);
    }
    *(vu0_q *)(o2 + 0x10) = *(vu0_q *)pos;
    *(vu0_q *)(o2 + 0xF0) = *(vu0_q *)rot;
    func_0038D308(o2 + 0xC0, o2 + 0xF0);
    if (obj != 0) {
        f32 scale = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
        *(f32 *)(o2 + 0x2C) = *(f32 *)(*(u8 **)(o2 + 0x24) + 0x24) * scale;
    }
    func_003C7DD8(o2);
    t = *(u16 *)(o2 + 0x34) & 0xABDB;
    *(u16 *)(o2 + 0x34) = t | 0x140;
    if (obj != 0) {
        if (*(u16 *)(obj + 0x34) & 0x800) {
            *(u16 *)(o2 + 0x34) = t | 0x940;
        }
        if (obj[0x7E] & 0x80) {
            u8 b = (o2[0x7E] | 0x80) & 0x8F;
            o2[0x7E] = b;
            o2[0x7E] = b | (obj[0x7E] & 0x70);
        }
    }
    *(s32 *)(o2 + 0x98) = 0;
    *(u8 **)(*(u8 **)(o2 + 0x68) + 0x54) = obj;
    s = func_0038D0B0(fa * 0.017453292f * 0.020000001f * 0.5f);
    func_L01_00443B88(q, s, s);
    q[3] = sqrt_asm(1.0f - s * s);
    if (mode == 1) {
        if (obj != 0) {
            o2[0x42] = obj[0x43];
            o2[0x43] = obj[0x43];
        }
        func_003C29B0(o2);
        *(s32 *)(o2 + 0x44) = 0;
        *(s32 *)(o2 + 0x48) = 0;
        func_003C6FE0(o2);
    }
    func_L01_003F7CE0(o2, mode, sh, vel, q, flag, x10, fb);
    t = *(u16 *)(o2 + 0x34);
    if ((*(u16 *)(o2 + 0x7C) & 0x8000) && (t & 0x10)) {
        *(u16 *)(o2 + 0x34) = t & 0xFFEF;
        t = *(u16 *)(o2 + 0x34);
    }
    *(void **)(o2 + 0x64) = func_L01_002FFF00;
    *(u16 *)(o2 + 0x34) = t & 0xFFFD;
    return o2;
}
