/* functional: high. Per-frame state machine of a Thran level pickup/switch with two linked slots (pv+0, +4 hold ids into the object table D_L19_001DF71C, entries 0x100 bytes): state 0 init, 1 wait for the linked objects to reach type 0xFE/0xFD, 3 fade out (pv+0x24 counts down via func_003C4138), then draws a ring effect and registers func_L19_003557B0. The lqc2 vector add is plain float adds. Float constants decoded from retail hex. */
extern u8 *D_L19_001DF71C[];
extern u8 D_001E2100[];
extern s32 D_001DD6B8_sda;
extern f32 D_001DD6BC_sda, D_001DD6C0_sda, D_001DD6C4_sda;
extern void func_L01_00456230(void *, s32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L19_003557B0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L19_0045E1A8(void *, void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L19_003553A0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 v[4];
    s32 idx, t;

    if (obj[0x20] == 0) {
        if (*(s32 *)(pv + 0x14) != 0) {
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) |= 0x41;
        }
        *(f32 *)(pv + 0x24) = 1.0f;
        if (*(s32 *)(pv + 0x8) != -1 || *(s32 *)(pv + 0xC) != *(s32 *)(pv + 0x8)) {
            func_L01_004450F0(obj, 1, -1);
        } else {
            func_L01_004450F0(obj, 2, -1);
        }
    }
    if (obj[0x20] == 0 || obj[0x20] == 1) {
        s32 ok = 1;
        idx = *(s32 *)(pv + 0x8);
        if (idx != -1) {
            t = D_L19_001DF71C[0][(idx << 8) + 0x20];
            if (t != 0xFE && t != 0xFD) {
                ok = 0;
            }
        }
        if (ok) {
            idx = *(s32 *)(pv + 0xC);
            if (idx != -1) {
                t = D_L19_001DF71C[0][(idx << 8) + 0x20];
                if (t != 0xFE && t != 0xFD) {
                    ok = 0;
                }
            }
            if (ok) {
                func_L01_004450F0(obj, 2, -1);
            }
        }
    } else if (obj[0x20] == 3) {
        u8 *p = *(u8 **)(pv + 0x1C);
        if (p != 0 && (p[0x20] == 0xFE || p[0x20] == 0xFD)) {
            idx = *(s32 *)pv;
            if (idx != -1) {
                func_L01_00456230(D_L19_001DF71C[0] + (idx << 8), 1);
            }
            idx = *(s32 *)(pv + 4);
            if (idx != -1) {
                func_L01_00456230(D_L19_001DF71C[0] + (idx << 8), 1);
            }
            func_003C4138(pv + 0x24, 0.0f, 0.01986755f);
            if (*(f32 *)(pv + 0x24) <= 0.0f) {
                func_L01_004450F0(obj, 4, -1);
            }
        }
    }
    if (obj[0x31] != 0) {
        if (0.0f < *(f32 *)(pv + 0x24)) {
            if (*(s32 *)(pv + 0x10) != 0) {
                f32 a, b;
                a = func_0038DAB8(1.5707964f, *(f32 *)(D_001E2100 + 0x18));
                v[0] = func_0038D098(a) * D_001DD6C4_sda;
                b = func_0038DAB8(1.5707964f, *(f32 *)(D_001E2100 + 0x18));
                v[1] = func_0038D0B0(b) * D_001DD6C4_sda;
                v[2] = 0.0f;
                v[0] = v[0] + *(f32 *)(obj + 0x10);
                v[1] = v[1] + *(f32 *)(obj + 0x14);
                v[2] = v[2] + *(f32 *)(obj + 0x18);
                v[2] = v[2] + D_001DD6C0_sda;
                func_L19_0045E1A8(v, obj, *(s32 *)(pv + 0x10) + 2, D_001DD6B8_sda, 0x20, 2, 0xFF, D_001DD6BC_sda);
            }
            if (0.0f < *(f32 *)(pv + 0x24)) {
                func_L01_00404A10(func_L19_003557B0, obj);
            }
        }
        if (obj[0x31] != 0) {
            func_L01_00451DB8(obj, pv + 0x20, 0x80909090, 0x80404040, 0.07330383f);
        }
    }
}
