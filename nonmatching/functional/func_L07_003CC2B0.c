/* functional: medium. Recommend the gate cover states 15-20 and 24. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CC2B0;

extern void func_L07_003CCAF0(void *);
extern void func_L07_003CCE68(void *);
extern void func_L07_003CD610(void *);
extern void func_L07_003CD6A8(void *, f32);
extern void func_L07_003CD7E0(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L07_003CD9F8(void *, s32);
extern void func_L07_003CD938(void *);
extern void func_L07_003CDC80(void *);
extern void func_L07_003CDDC0(void *);
extern void func_L07_003CDE10(void *);
extern void func_L07_003CDE48(void *);
extern void func_L07_003CDF40(void *);
extern void func_L07_003CE080(void *);
extern s32 func_L07_003CEC48(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045A9F0(void *);
extern void func_L01_0045BD10(void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_0045A748(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L06_003584D0(void *, void *, void *, void *, s32, s32, f32);
extern s32 D_L07_001DF41C;
extern s32 D_L07_001DF500;

void func_L07_003CC2B0(u8 *obj) {
    V4_003CC2B0 v20;
    V4_003CC2B0 d10;
    u8 *p;
    u8 *t;
    f32 dist, ang;
    s32 base;
    s32 r;

    if (obj[0x20] == 0) func_L07_003CCAF0(obj);
    func_L07_003CCE68(obj);
    p = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 1:
        if (*(s16 *)(p + 0x144) == 1) func_L01_004450F0(obj, 5, -1);
        break;
    case 2:
        func_L01_0045A9F0(obj);
        if (func_L01_00454370(obj, p + 0x70) & 2) {
            if (obj[0x94] >= 6) func_L07_003CD2E8(obj, 6);
            else func_L07_003CD2E8(obj, 5);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj)) *(s16 *)(p + 0x42E) = (*(s16 *)(p + 0x42C) * 5 + 2) / 6;
        if (func_L07_003CEC48(obj)) {
            if (func_0038CB00(p + 0x42E)) func_L07_003CD2E8(obj, 4);
        }
        break;
    case 4:
        base = D_L07_001DF41C + (*(s32 *)(p + 0x428) << 8);
        func_L01_00409598(obj, (void *)(base + 0x10), (void *)(base + 0xF0), 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
        func_L07_003CD2E8(obj, 5);
        break;
    case 5:
        if (func_L07_003CEC48(obj)) {
            if (*(s32 *)(p + 0x40C) != -1) func_L07_003CD2E8(obj, 0x18);
            else func_L07_003CD2E8(obj, 6);
        }
        break;
    case 6:
        if (!func_L07_003CEC48(obj)) {
            func_L07_003CD2E8(obj, 5);
            break;
        }
        if (*(s32 *)(p + 0x40C) != -1) {
            func_L07_003CD2E8(obj, 0x18);
            break;
        }
        r = func_L07_003CD9F8(obj, 0);
        if (r != -1) {
            p[0x406] = 0;
            p[0x405] = 1;
            p[0x404] = r;
            func_L07_003CD938(obj);
        }
        break;
    case 7:
        func_L07_003CD6A8(obj, 6.0f);
        break;
    case 8:
        func_L07_003CD6A8(obj, 10.0f);
        break;
    case 9:
        func_L07_003CD610(obj);
        if (obj[0x60] & 2) func_L07_003CD2E8(obj, 0xA);
        break;
    case 10:
        if (func_L07_003CEC48(obj)) func_L07_003CD6A8(obj, -1.0f);
        else func_L07_003CD2E8(obj, 5);
        break;
    case 11:
        if (obj[0x60] & 2) func_L07_003CD2E8(obj, p[0x404] + 0xC);
        break;
    case 12:
        if (p[0x406] == 0) {
            dist = func_L01_004395E0(obj);
            if (14.0f <= dist && dist <= 24.0f) func_L07_003CDE48(obj);
        }
        func_L07_003CDC80(obj);
        break;
    case 13:
        if (p[0x406] == 0) {
            dist = func_L01_004395E0(obj);
            if (12.0f <= dist && dist <= 20.0f) func_L07_003CDF40(obj);
        }
        func_L07_003CDC80(obj);
        break;
    case 14:
        if (p[0x406] == 0) {
            dist = func_L01_004395E0(obj);
            if (15.0f <= dist && dist <= 21.0f) func_L07_003CE080(obj);
        }
        func_L07_003CDC80(obj);
        break;
    case 15:
        if (p[0x406] == 0) {
            dist = func_L01_004395E0(obj);
            if (22.0f <= dist && dist <= 26.0f) func_L07_003CE080(obj);
        }
        func_L07_003CD7E0(obj, 0xD, 0, 1, func_L01_004395E0(obj), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        func_L07_003CDC80(obj);
        break;
    case 16:
        p[0x430] = 0;
        func_L07_003CD7E0(obj, 0xD, 0, 1, func_L01_004395E0(obj), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        func_L07_003CDC80(obj);
        break;
    case 17:
        if (func_L01_0044E1B8(obj, 14.0f)) {
            if (obj[0x42] == 0xE) {
                func_003C2F58(obj, 4, &v20);
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(d10) : "m"(*(V4_003CC2B0 *)(p + 0x130)), "m"(v20) : "vf1", "vf2");
                func_0038CF68(&d10, &d10, 0.50000006f);
                func_L06_003584D0(obj, &d10, &v20, obj + 0xF0, 1, 0, (f32)p[0x45]);
            }
        }
        func_L07_003CDC80(obj);
        break;
    case 18:
        func_L07_003CD7E0(obj, 8, 1, 1, func_L01_004395E0(obj), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_003CDDC0(obj);
        break;
    case 19:
        func_L07_003CD7E0(obj, 7, 1, -1, func_L01_004395E0(obj), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_003CDDC0(obj);
        break;
    case 20:
        func_L07_003CD7E0(obj, 9, 0, -1, func_L01_004395E0(obj), 1.5f, 3.0f, 8.0f, 24.0f, 16.0f);
        func_L07_003CDDC0(obj);
        break;
    case 21:
    case 22:
    case 23:
        func_L07_003CDE10(obj);
        break;
    case 24:
        t = (u8 *)(D_L07_001DF500 + (*(s32 *)(p + 0x40C) << 7));
        if (*(s16 *)(p + 0x144) != 1) func_L07_003CD2E8(obj, 5);
        t += 0x30;
        dist = func_0038CF38(obj + 0x10, t);
        if (!(dist <= 1.0f)) {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 8);
            func_L01_0045A748(obj, t);
            break;
        }
        ang = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
        if (!(func_0038DBA0(*(f32 *)(obj + 0xF8), ang) < 0.4363323f) && obj[0x42] != 0xE) {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 8);
            {
                u8 *tgt = *(u8 **)(p + 0x140);
                ang = func_0038D160(*(f32 *)(tgt + 0x10) - *(f32 *)(obj + 0x10), *(f32 *)(tgt + 0x14) - *(f32 *)(obj + 0x14));
            }
            func_L01_0045BD10(obj, ang);
            break;
        }
        if (obj[0x43] != 0xE) func_003C3A10(obj, 0xE, 0, 0xC);
        if (func_L01_0044E1B8(obj, 14.0f) && obj[0x42] == 0xE) {
            func_003C2F58(obj, 4, &v20);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(d10) : "m"(*(V4_003CC2B0 *)(p + 0x130)), "m"(v20) : "vf1", "vf2");
            func_0038CF68(&d10, &d10, 0.50000006f);
            func_L06_003584D0(obj, &d10, &v20, obj + 0xF0, 1, 0, 1.0f);
        }
        if (obj[0x60] & 2) {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 8);
        }
        break;
    default:
        break;
    }
}
