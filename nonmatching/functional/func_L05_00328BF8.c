/* functional: high. Control flow, delay-slot stores and call argument order follow retail; the compiler lays out the VU (vsub.xyz) differently and the frame differs. diff[3]=o+0x1C because retail's sqc2 stores vf1 with its untouched w. */
typedef int u128_328BF8 __attribute__((mode(TI)));
extern void func_L05_0032AB50(u8 *, u8 *);
extern void func_L05_003298C0(s32, u8 *);
extern void func_L05_00328F00(u8 *, u8 *);
extern s32 func_L05_00328FF8(s32);
extern void func_L05_00329A78(s32, Obj329158 *);
extern s32 func_L05_00329AD0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L05_00329050(u8 *, u8 *, s32);
extern void func_L05_0032A0B0(u8 *, u8 *, s32, s32);
extern s32 func_L05_00329DA8(u8 *, u8 *);
extern void func_L05_00329ED0(u8 *, u8 *, s32);
extern s32 func_L05_0032A4D8(u8 *, u8 *);
extern void func_L05_00329C68(s32, u8 *);
extern void func_L05_00329C58(s32, void *);
extern void func_L05_00329CA0(void *, u8 *, f32 *, f32 *, f32 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L05_00329BC8(s32, u8 *);
extern void func_L05_00329120(u8 *, u8 *);
extern void func_L05_003293B0(u8 *, u8 *, void *);
extern void func_L05_003296F8(u8 *, u8 *);

void func_L05_00328BF8(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u128_328BF8 save[2];
    f32 sp30[3];
    f32 diff[4];
    s32 st;
    s32 idx;

    if (o[0x20] == 0) {
        func_L05_0032AB50(o, s);
    }
    save[0] = *(u128_328BF8 *)(o + 0x10);
    save[1] = *(u128_328BF8 *)(o + 0xF0);
    *(u128_328BF8 *)(o + 0x10) = *(u128_328BF8 *)(s + 0x1B0);
    *(u128_328BF8 *)(o + 0xF0) = *(u128_328BF8 *)(s + 0x1C0);
    func_L05_003298C0((s32)o, s);
    st = o[0x20];
    if (st == 2) {
        if (func_L05_00328FF8((s32)o) == 0) {
            func_L05_00329ED0(o, s, func_L05_00329DA8(o, s));
        } else {
            func_L05_00329A78((s32)o, (Obj329158 *)s);
            if (func_L05_00329AD0() != 0) {
                func_L01_004450F0(o, 3, -1);
                idx = func_L05_00329050(o, s, *(s32 *)(s + 0xA0 + *(s32 *)(s + 0x15C) * 4));
                func_L05_0032A0B0(o, s, *(s32 *)(s + 0xA0 + *(s32 *)(s + 0x15C) * 4), *(s32 *)(s + 0x90 + idx * 4));
                *(s32 *)(s + 0x15C) = idx;
            }
        }
    } else if (st == 1) {
        func_L05_00328F00(o, s);
        if (*(s32 *)(s + 0x70) != 0) {
            func_L05_00329ED0(o, s, func_L05_00329DA8(o, s));
        }
    } else if (st == 3) {
        if (func_L05_0032A4D8(o, s) == 0) {
            func_L01_004450F0(o, 2, -1);
            func_L05_00329C68((s32)o, s);
        } else if (*(s32 *)(s + 0x80) == 0) {
            s32 r = func_L05_00328FF8((s32)o);
            *(s32 *)(s + 0x80) = r;
            if (r == 0) {
                func_L05_00329C58((s32)o, s);
            }
        }
    }
    *(u128_328BF8 *)(s + 0x1B0) = *(u128_328BF8 *)(o + 0x10);
    *(u128_328BF8 *)(s + 0x1C0) = *(u128_328BF8 *)(o + 0xF0);
    func_L05_00329CA0(o, s, &sp30[0], &sp30[1], &sp30[2]);
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + sp30[0];
    *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), sp30[1]);
    *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), sp30[2]);
    diff[0] = *(f32 *)(o + 0x10) - ((f32 *)&save[0])[0];
    diff[1] = *(f32 *)(o + 0x14) - ((f32 *)&save[0])[1];
    diff[2] = *(f32 *)(o + 0x18) - ((f32 *)&save[0])[2];
    diff[3] = *(f32 *)(o + 0x1C);
    func_003C4DA8(s + 0x30, diff, &save[1], o + 0xF0);
    if (func_L05_00328FF8((s32)o) != 0 && o[0x20] == 3) {
        func_L05_00329BC8((s32)o, s);
    }
    func_L05_00329120(o, s);
    func_L05_003293B0(o, s, &save[0]);
    func_L05_003296F8(o, s);
}
