/* functional: high. Rewritten from the PAL asm (the NTSC-U draft differs: 2.0f probe, 0.56 scale, state 0x25, other callees/args); only register allocation differs, all callee addresses and constants match. */
/* localdecomp:start func_L09_003BE5D0 */
extern u8 *D_L09_001E009C;
extern f32 D_001A4CB0[];
extern s32 D_001A71A0;
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L09_003E7BC0(void *, void *, void *, s32, s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038CB00(void *);

void func_L09_003BE5D0(u8 *self, s32 flag, s32 a2, s32 a3, s32 e) {
    f32 v0[4];
    f32 v1[4];
    f32 v2[4];
    u8 *t;
    u8 *o;
    f32 ang;
    f32 d;
    f32 *tv;
    s32 x;

    t = *(u8 **)(self + 0x68);
    o = D_L09_001E009C + (*(s32 *)(t + 0xCD0) << 8);
    if ((u8)(o[0x43] - 3) < 2) {
        if (func_L01_0044E1B8(o, 2.0f) != 0) {
            func_003C2F58(o, o[0x43] == 3 ? 7 : 0xB, v0);
            func_003C2F58(o, o[0x43] == 3 ? 8 : 0xC, v1);
            if (e != 0) {
                if (self[0x20] == 7) {
                    v2[0] = func_0038D098(2.96705961f) * 0.56000006f;
                    v2[1] = func_0038D0B0(2.96705961f) * 0.56000006f;
                    *(s32 *)&v2[2] = 0;
                    tv = v2;
                    goto call;
                }
                if (self[0x20] == 0x14) {
                    ang = func_0038D160(v1[0] - v0[0], v1[1] - v0[1]);
                    d = func_0038CF38(v1, D_001A4CB0);
                    func_00382760(v2, 0.56000006f, ang, func_0038D160(d, D_001A4CB0[2] - v1[2]));
                    tv = v2;
                    goto call;
                }
            }
            if (flag != 0 || e != 0) {
                vec_sub_ab(v2, v1, v0);
                func_0038CF68(v2, v2, 0.56000006f);
                tv = v2;
            } else {
                ang = func_0038D160(v1[0] - v0[0], v1[1] - v0[1]);
                d = func_0038CF38(v1, D_001A4CB0);
                func_00382760(v2, 0.56000006f, ang, func_0038D160(d, D_001A4CB0[2] - v1[2]));
                tv = v2;
            }
        call:
            func_003A52A0(1, 0, o);
            func_L09_003E7BC0(self, v1, tv, e != 0 ? 0 : D_001A71A0, t[0x45], flag, a2, a3);
        } else if (o[0x60] & 2) {
            func_003C3A10(o, 0, 0, 4);
        }
    } else {
        if (func_0038CB00(t + 0xD36) != 0 || a3 != 0) {
            x = t[0xD2D] + 1;
            *(s16 *)(t + 0xD36) = 0x25;
            t[0xD2D] = x;
            func_003C3A10(o, (x & 1) ? 3 : 4, 0, 8);
        }
    }
}
/* localdecomp:end func_L09_003BE5D0 */
