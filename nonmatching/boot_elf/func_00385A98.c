/* US draft of func_00385A98 (rac3-uya-decomp func_00385A70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00385A98 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__ using the "j" (VU0
   register) constraint, which needs -mvu0-use-vf0-vfN. The original build used N = 2 on every
   file (tools/text_parts.txt carries -mvu0-use-vf0-vf2 on every line); see Matching-Patterns,
   "VU0 j-form: one asm statement per instruction". */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3813E0;
typedef int Q_3813E0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x1430];
    s32 f1430;
    u8 p1434[0x2C];
    u8 *f1460;
    f32 f1464;
    f32 f1468;
} S_3813E0;
typedef struct { f32 f0; s16 h4; u8 p6[0xA]; f32 f10; } P_3813E0;
extern S_3813E0 D_001A4BE0;
__asm__(".extern D_001D57C8, 4");
__asm__(".extern D_001D57CC, 4");
__asm__(".extern D_001D57D0, 4");
__asm__(".extern D_001D57D4, 4");
__asm__(".extern D_001D57D8, 4");
__asm__(".extern D_001D57E8, 4");
__asm__(".extern D_001D57F8, 4");
__asm__(".extern D_001D5804, 4");
__asm__(".extern D_001D5808, 4");
__asm__(".extern D_001D580C, 4");
__asm__(".extern D_001D5810, 4");
__asm__(".extern D_001D5814, 4");
__asm__(".extern D_001D5818, 4");
__asm__(".extern D_001D581C, 4");
__asm__(".extern D_001D5820, 4");
__asm__(".extern D_001D5824, 4");
__asm__(".extern D_001D5828, 4");
__asm__(".extern D_001D582C, 4");
__asm__(".extern D_001D5830, 4");
__asm__(".extern D_001D5834, 4");
extern f32 D_001D57C8, D_001D57CC, D_001D57D0, D_001D57D4, D_001D5804, D_001D5808, D_001D5830, D_001D5834;
extern s32 D_001D57D8, D_001D57E8;
extern f32 D_001D57F8;
extern s32 D_001D580C, D_001D5810, D_001D5814, D_001D5818, D_001D581C, D_001D5820, D_001D5824, D_001D5828, D_001D582C;
extern s32 D_001D4BD0_00385A98, D_001D4BD4_00385A98;
extern P_3813E0 *func_00382728(u8 *);
extern void func_00386488(f32 *, void *);
extern f32 func_0038D2E0(void *, void *);
extern f32 func_0038D540(f32, f32);
extern void func_0038C0B8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_0038C8E0(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern long func_00389978(s32);
void func_00385A98(void) {
    f32 scr[4];
    f32 pos[2];
    V4_3813E0 v;
    s32 rgb4[4];
    s32 clr2[4];
    u8 *obj;
    P_3813E0 *info;
    f32 total, part, zoom, size;
    s32 i;
    if (D_001A4BE0.f1430 == 0 && D_001A4BE0.f1464 == 0.0f) return;
    if (D_001A4BE0.f1430 != (s32)D_001A4BE0.f1460) {
        func_003C44F0(&D_001A4BE0.f1464, 0.0f, D_001D57D4 * 0.016666668f);
        if (D_001A4BE0.f1464 <= 0.0f) D_001A4BE0.f1460 = (u8 *)D_001A4BE0.f1430;
    } else if (D_001A4BE0.f1430 != 0 && D_001A4BE0.f1464 < 1.0f) {
        func_003C44F0(&D_001A4BE0.f1464, 1.0f, D_001D57D4 * 0.016666668f);
        D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_0038DE98)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.016666668f);
    }
    D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_0038DE98)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.016666668f);
    obj = D_001A4BE0.f1460;
    if (obj == 0) return;
    if (D_001A4BE0.f1464 == 0.0f) return;
    part = 0.0f;
    info = func_00382728(obj);
    total = part;
    if (info != 0) {
        Q_3813E0 qa, qb;
        func_0038D348((s32)&v, (s32)(obj + 0xE0), info->f10);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_3813E0 *)(obj + 0x10)));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
        total = (f32)info->h4;
        part = info->f0;
    } else {
        v = *(V4_3813E0 *)(obj + 0x10);
    }
    zoom = 0.75f;
    func_00386488(scr, &v);
    pos[0] = (scr[0] - (f32)D_001D4BD0_00385A98) * 0.0625f;
    pos[1] = (scr[1] - (f32)D_001D4BD4_00385A98) * 0.0625f;
    if (info != 0) zoom = info->f10;
    if (zoom > 2.0f) zoom = 2.0f;
    size = func_0038D540(func_0038D2E0(D_00222480, obj + 0x10), zoom) * D_001D57C8;
    if (size > D_001D57CC) size = D_001D57CC;
    else if (size < D_001D57D0) size = D_001D57D0;
    for (i = 0; i < 3; i++) {
        f32 ang, sc;
        long tex;
        s32 rgba;
        switch (i) {
        case 0: ang = D_001A4BE0.f1468; break;
        case 1: ang = -D_001A4BE0.f1468; break;
        case 2: default: ang = D_001D5804 * 0.017453292f; break;
        }
        tex = func_00389978(i + 0x33);
        rgba = ((s32 (*)(s32, s32, f32))func_0038DFB8)((&D_001D57E8)[i], (&D_001D57D8)[i], D_001A4BE0.f1464);
        sc = (((&D_001D57F8)[i] - 1.0f) * (1.0f - D_001A4BE0.f1464) + 1.0f) * size;
        func_0038C0B8(pos[0], pos[1], sc, sc, ang, 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DE98)(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DE98)(ang, 3.1415927f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038C0B8(pos[0], pos[1], sc, sc, func_0038DEE0(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
    }
    if (total != 0.0f) {
        long x, y;
        f32 half;
        f32 half2;
        s32 rgba;
        clr2[0] = D_001D5810;
        clr2[1] = D_001D5814;
        clr2[2] = D_001D5818;
        clr2[3] = D_001D581C;
        rgba = ((s32 (*)(s32, s32, f32))func_0038DFB8)(D_001D5828 & 0xFFFFFF, D_001D5828, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        x = (s32)scr[0];
        y = (s32)scr[1];
        half = D_001D5834 * func_0038D540(D_001D5830, total);
        func_0038C8E0(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, -half);
        rgba = ((s32 (*)(s32, s32, f32))func_0038DFB8)(D_001D582C & 0xFFFFFF, D_001D582C, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        half2 = half - (half + half) * (part / total);
        func_0038C8E0(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, half2);
    }
}
/* localdecomp:end func_00385A98 */
