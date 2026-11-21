/* functional: medium. Not byte-checked in detail; recommend the gate cover states 11/13/24/25/26. */
typedef int Q_003C7468 __attribute__((mode(TI)));

extern void func_L07_003C7E70(void *);
extern void func_L07_003C80C0(void *);
extern void func_L07_003C84F8(void *, void *);
extern void func_L07_003C8718(void *, s32);
extern s32 func_L07_003C8960(void *);
extern void func_L07_003C8A10(void *);
extern void func_L07_003C8A88(void *);
extern void func_L07_003C8AD0(void *);
extern void func_L07_003C8B18(void *);
extern void func_L07_003C8B60(void *);
extern void func_L07_003C8BA0(void *);
extern void func_L07_003C8C30(void *);
extern void func_L07_003C8C90(void *);
extern void func_L07_003C8CF8(void *, f32);
extern void func_L07_003C8D60(void *);
extern void func_L07_003C8FF8(void *, void *, f32);
extern void func_L07_003C90F8(void *);
extern void func_L07_003C9150(void *, void *);
extern void func_L07_003C91A8(void *, void *);
extern void func_L07_003C9280(void *);
extern void func_L07_003C9488(void *, s32, s32);
extern f32 func_L07_003C9528(void *);
extern void func_L07_003C96C0(void *, void *, f32);
extern void func_L07_003C9780(void *, void *, f32, f32);
extern void func_L07_003C97E0(void *);
extern void func_L07_003C99A0(void *);
extern void func_L07_003C9C40(void *);
extern void func_L07_003C9D50(void *);
extern s16 func_L07_003BAF28(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045A9F0(void *);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_0045A748(void *, void *);
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 D_L07_001DF41C;
extern s32 D_L07_001DF500;
extern s32 *D_L07_0021D2C0[];

void func_L07_003C7468(u8 *obj) {
    Q_003C7468 saved;
    Q_003C7468 tmp;
    u8 *p;
    f32 f20, f21, ang, dist;
    s32 v;
    s32 base;

    if (obj[0x20] == 1) return;
    if (obj[0x20] == 0) func_L07_003C7E70(obj);
    func_L07_003C80C0(obj);
    saved = *(Q_003C7468 *)(obj + 0x10);
    p = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 2:
        if (func_L01_004561B8(obj)) {
            *(s16 *)(p + 0x4C6) = (*(s16 *)(p + 0x4C4) * 5 + 2) / 6;
        }
        if (func_L07_003C8960(obj)) {
            if (func_0038CB00(p + 0x4C6)) func_L07_003C8718(obj, 3);
        }
        break;
    case 3:
        base = D_L07_001DF41C + (*(s32 *)(p + 0x4C0) << 8);
        func_L01_00409598(obj, (void *)(base + 0x10), (void *)(base + 0xF0), 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
        *(Q_003C7468 *)(p + 0x440) = *(Q_003C7468 *)(obj + 0x10);
        func_L07_003C8A10(obj);
        break;
    case 4:
        if (func_L01_004561B8(obj)) func_L07_003C9488(obj, *(s32 *)(p + 0x4A8), 2);
        if (func_L07_003C8960(obj)) {
            func_L07_003C8B18(obj);
        } else if (func_L01_0045BDE8(obj, *(s32 *)(p + 0x4A8))) {
            func_L07_003C8718(obj, 4);
        }
        break;
    case 5:
        func_L01_0045A9F0(obj);
        if (func_L07_003C8960(obj)) func_L07_003C8B18(obj);
        break;
    case 6:
        if (func_L01_004561B8(obj)) func_L07_003C9488(obj, *(s32 *)(p + 0x4AC), 1);
        if (func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 0xA);
        } else if (func_L01_0045BDE8(obj, *(s32 *)(p + 0x4AC))) {
            func_L07_003C8A88(obj);
        }
        break;
    case 7:
        if (func_L07_003C8960(obj)) func_L07_003C8C90(obj);
        break;
    case 8:
        func_L01_0045A9F0(obj);
        if (func_L01_00454370(obj, p + 0x70) & 2) {
            if (*(s32 *)(p + 0x4B8) == -1 && *(s32 *)(p + 0x4B0) == -1) {
                func_L07_003C8718(obj, 9);
            } else {
                func_L07_003C8C90(obj);
            }
        }
        break;
    case 9:
        if (func_L01_004561B8(obj)) *(s16 *)(p + 0x4C6) = 0xFA;
        if (func_L07_003C8960(obj)) {
            func_L07_003C8B18(obj);
        } else if (func_0038CB00(p + 0x4C6)) {
            func_L07_003C8AD0(obj);
        }
        break;
    case 10:
        if (func_L01_004561B8(obj)) func_L07_003C9488(obj, *(s32 *)(p + 0x4AC), 0);
        if (func_L07_003C8960(obj)) {
            if (func_L01_0045BDE8(obj, *(s32 *)(p + 0x4AC))) func_L07_003C8B60(obj);
        } else {
            func_L07_003C8718(obj, 9);
        }
        break;
    case 11:
        if (func_L01_004561B8(obj)) *(u32 *)(p + 0x188) |= 0x10;
        f20 = *(f32 *)(p + 0x4CC) + (*(f32 *)(p + 0x4D0) - *(f32 *)(p + 0x4CC)) * 0.6f;
        func_L07_003C8CF8(obj, *(f32 *)(p + 0x4CC) + (*(f32 *)(p + 0x4D0) - *(f32 *)(p + 0x4CC)) * 0.5f);
        ang = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
        func_L07_003C8FF8(obj, &saved, ang);
        func_L07_003C9150(obj, p + 0x130);
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 9);
            break;
        }
        if (!func_0038CB00(p + 0x4D4)) break;
        dist = func_L01_0040E570(obj + 0x10, p + 0x130);
        if (!(dist < f20 * f20)) break;
        goto try_attack;
    case 12:
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 9);
            break;
        }
        if (*(s32 *)(p + 0x1D0) >= 9) p[0x4DD] = 1;
        if (p[0x4DD] || (func_L01_0045A748(obj, p + 0x440) & 0x80)) func_L07_003C8718(obj, 0xD);
        break;
    case 13:
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 9);
            break;
        }
        f21 = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
        func_L01_0045AA10(obj, f21);
        f20 = func_0038CF38(obj + 0x10, p + 0x130);
        if (!func_0038CB00(p + 0x4D4)) break;
        if (!(*(f32 *)(p + 0x4CC) < f20)) break;
        if (!(f20 < *(f32 *)(p + 0x4D0))) break;
        dist = func_0038DBA0(f21, *(f32 *)(obj + 0xF8));
        if (!(dist < 0.43633232f)) break;
    try_attack:
        v = func_L07_003BAF28(obj);
        *(s16 *)(p + 0x460) = v;
        if ((s16)v > 0) break;
        func_L07_003C8BA0(obj);
        break;
    case 14:
    case 18:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) func_L07_003C8718(obj, obj[0x20] + 1);
        break;
    case 15:
    case 19:
        if (func_L01_004561B8(obj)) {
            func_003A52A0(2, 0, obj);
            *(s16 *)(p + 0x4C6) = 0x19;
        }
        func_L01_0045A9F0(obj);
        func_L07_003C8D60(obj);
        func_L07_003C91A8(obj, p + 0x470);
        func_L07_003C97E0(obj);
        if (func_0038CB00(p + 0x4C6)) func_L07_003C8718(obj, obj[0x20] + 1);
        break;
    case 16:
    case 20:
        if (func_L01_004561B8(obj)) {
            *(s32 *)(p + 0x488) = 0;
            *(s16 *)(p + 0x4C6) = 0x19;
            func_003A52A0(1, 0, obj);
        }
        func_L01_0045A9F0(obj);
        func_L07_003C91A8(obj, p + 0x470);
        func_L07_003C9780(p + 0x488, p + 0x48C, 0.12f, 0.192f);
        func_L07_003C9280(obj);
        func_L07_003C99A0(obj);
        func_L01_00404808(func_L07_003C9C40, obj);
        if (func_0038CB00(p + 0x4C6)) func_L07_003C8718(obj, obj[0x20] + 1);
        break;
    case 17:
    case 21:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) func_L07_003C8C30(obj);
        break;
    case 22:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) func_L07_003C8B60(obj);
        break;
    case 23:
        if (func_L07_003C8960(obj)) {
            if (func_L01_0045A748(obj, (void *)(D_L07_001DF500 + (*(s32 *)(p + 0x4B8) << 7) + 0x30)) & 0x80)
                func_L07_003C8718(obj, 0x18);
        } else {
            func_L07_003C8718(obj, 7);
        }
        break;
    case 24:
        if (func_L01_004561B8(obj)) {
            *(s32 *)(p + 0x488) = 0;
            *(f32 *)(p + 0x4C8) = *(f32 *)(obj + 0xF8);
        }
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 7);
            break;
        }
        func_L07_003C9780(p + 0x488, p + 0x48C, 0.012f, 0.192f);
        func_L01_00404808(func_L07_003C9D50, obj);
        func_L01_0045A9F0(obj);
        goto finish_shoot;
    case 25:
        if (func_L01_004561B8(obj)) {
            *(u32 *)(p + 0x188) |= 0x10;
            func_L07_003C9488(obj, *(s32 *)(p + 0x4B0), 2);
            if (obj[0x94] != obj[0x20]) {
                *(s32 *)(p + 0x488) = 0;
                *(f32 *)(p + 0x4C8) = *(f32 *)(obj + 0xF8);
                if (obj[0x94] != obj[0x20]) func_003A52A0(1, 0, obj);
            }
        }
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 7);
            break;
        }
        func_L07_003C9780(p + 0x488, p + 0x48C, 0.012f, 0.192f);
        func_L01_00404808(func_L07_003C9D50, obj);
        if (func_L01_0045BDE8(obj, *(s32 *)(p + 0x4B0))) func_L07_003C8718(obj, 0x19);
        func_L07_003C8FF8(obj, &saved, *(f32 *)(obj + 0xF8));
    finish_shoot:
        func_L07_003C90F8(obj);
        f20 = *(f32 *)(p + 0x4BC) * 0.017453292f;
        *(f32 *)(p + 0x3A0) = f20;
        *(f32 *)(p + 0x320) = -f20;
        break;
    case 26:
        if (func_L01_004561B8(obj)) {
            *(u32 *)(p + 0x188) |= 0x10;
            func_L07_003C9488(obj, *(s32 *)(p + 0x4B0), 2);
            if (obj[0x94] != obj[0x20]) {
                *(s32 *)(p + 0x488) = 0;
                func_L07_003C96C0(D_L07_0021D2C0[*(s32 *)(p + 0x4B4)], p + 0x470,
                                  func_L07_003C9528(obj) * (f32)*D_L07_0021D2C0[*(s32 *)(p + 0x4B4)]);
                if (obj[0x94] != obj[0x20]) func_003A52A0(1, 0, obj);
            }
        }
        if (!func_L07_003C8960(obj)) {
            func_L07_003C8718(obj, 7);
            break;
        }
        func_L07_003C96C0(D_L07_0021D2C0[*(s32 *)(p + 0x4B4)], &tmp,
                          func_L07_003C9528(obj) * (f32)*D_L07_0021D2C0[*(s32 *)(p + 0x4B4)]);
        func_0038CDF8(p + 0x470, p + 0x470, &tmp, 0.10000000149011612f);
        func_L07_003C9780(p + 0x488, p + 0x48C, 0.012f, 0.192f);
        func_L07_003C9280(obj);
        func_L07_003C99A0(obj);
        func_L01_00404808(func_L07_003C9C40, obj);
        if (func_L01_0045BDE8(obj, *(s32 *)(p + 0x4B0))) func_L07_003C8718(obj, 0x1A);
        func_L07_003C8FF8(obj, &saved, *(f32 *)(obj + 0xF8));
        func_L07_003C9150(obj, p + 0x470);
        func_L07_003C91A8(obj, p + 0x470);
        break;
    default:
        break;
    }
    func_L07_003C84F8(obj, &saved);
}
