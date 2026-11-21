/* functional: high. Rewritten from the PAL boot_elf assembly (no draft; frontbin twin func_003AD7D8 unmatched). Straight-line widget setup; register allocation and scheduling differ. func_003AB608 and func_003ABDB0 are called with (obj, name, pool) as retail does: both forward a1/a2 to func_003AB3F0 in registers, though their matched C in 3AAD90.c declares one parameter. Colour words passed in float registers to func_003AD8F0 are built from their bit patterns. */
typedef union { u32 u; f32 f; } FB_003ADB90;
extern s32 D_00143950_bfDB90[];
extern char D_001D8530_bfDB90[];
extern char D_001D8540_bfDB90[];
extern char D_001D8550_bfDB90[];
extern char D_001D8558_bfDB90[];
extern char D_001D8568_bfDB90[];
extern char D_001D8578_bfDB90[];
extern char D_001D8588_bfDB90[];
extern char D_001D8598_bfDB90[];
extern char D_001D85A8_bfDB90[];
extern char D_001D85B8_bfDB90[];
extern char D_001D85C8_bfDB90[];
extern char D_001D85D8_bfDB90[];
extern char D_001D85E8_bfDB90[];
extern char D_001D85F8_bfDB90[];
extern char D_001D8608_bfDB90[];
extern char D_001D8618_bfDB90[];
extern char D_001D8630_bfDB90[];
extern char D_001D8640_bfDB90[];
extern char D_001D8650_bfDB90[];
extern char D_001D8660_bfDB90[];
extern char D_001D8670_bfDB90[];
/* two ring layouts ($gp data): { s32 ox, oy; f32 scale, rx, ry; s32 cx, cy; } then a colour */
extern s32 D_001D867C_bfDB90;
extern s32 D_001D8680_bfDB90;
extern f32 D_001D8684_bfDB90;
extern f32 D_001D8688_bfDB90;
extern f32 D_001D868C_bfDB90;
extern s32 D_001D8690_bfDB90;
extern s32 D_001D8694_bfDB90;
extern s32 D_001D8698_bfDB90;
extern s32 D_001D869C_bfDB90;
extern f32 D_001D86A0_bfDB90;
extern f32 D_001D86A4_bfDB90;
extern f32 D_001D86A8_bfDB90;
extern s32 D_001D86AC_bfDB90;
extern s32 D_001D86B0_bfDB90;
extern s32 D_001D86B4_bfDB90;

extern void func_003AB608(void *, char *, s32);
extern void func_003AB7E0(u8 *, u8 *, s32);
extern void func_003AB288(void *, f32, f32, f32, f32);
extern void func_003AB3B0(void *, f32, f32, f32, f32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003ABDB0(void *, char *, s32);
extern void func_003ABE40(void *, void *);
extern void func_003ABE38(void *, s32);
extern void func_003ABB30(void *, char *, s32);
extern s32 *func_003AB270(void *);
extern f32 *func_003AB268(void *);
extern void func_003ABD40(void *, s32, s32);
extern void *func_003AC270(s32);
extern s32 func_003F2740(s32, s32);
extern void func_003AB348(void *, s32);
extern void func_003AB2B8(void *, s32);
extern void func_003AB2D8(void *, void *);
extern s32 func_0011B2E8(char *, const char *, ...);
extern f32 func_0038DE98(f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern void func_003AD7E0(void *, s32);
extern void func_003AD940(void *, s32);
extern void func_003AD8F0(void *, s32, f32, f32, f32, f32, f32);
extern void func_003AD928(void *, s32, f32, f32);
extern void func_003AD8A0(void *, void *);
extern void func_003AD988(void *, s32);
extern void func_003AD8D8(void *, void *);
extern void func_003AD948(void *, s32);
extern void func_003AD990(void *, f32);
extern void func_003AD8E0(void *, s32);

static __inline__ f32 fb_003ADB90(u32 v) {
    FB_003ADB90 b;
    b.u = v;
    return b.f;
}

static __inline__ void anim_tail_003ADB90(u8 *a, void *target, void *list) {
    func_003AD8A0(a, target);
    func_003AD988(a, 0);
    func_003AD8D8(a, list);
    func_003AD948(a, -1);
    func_003AD990(a, D_00143950_bfDB90[0] != 0 ? 1.0f : 0.8333333f);
    func_003AD8E0(a, 0);
}

/* Builds one HUD panel object (0xB50 bytes, called per player from 3AF0C8.c): its sprites,
 * text boxes, the 8-slot ring of icons and labels laid out on two ellipses, and six
 * fade/scale animators (p+0x7E8..0xA90) bound to the panel's widgets. */
void func_003ADB90(u8 *p, u8 *bank, s32 pool) {
    char buf[16];
    u8 *tex = bank + 0x7090;
    s32 i;

    p[0xB40] = 0;
    *(s32 *)(p + 0xB44) = 0;
    func_003AB608(p, D_001D8530_bfDB90, pool);
    func_003AB7E0(p, tex, 0);
    func_003AB288(p, 10.0f, 10.0f, 0.0f, 0.0f);
    p[0x3A] = 1;
    func_003AB608(p + 0x3C, D_001D8540_bfDB90, pool);
    func_003AB288(p + 0x3C, 10.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0(p + 0x3C, tex, 0);
    p[0x76] = 1;
    func_003AB608(p + 0x78, D_001D8550_bfDB90, pool);
    func_003AB288(p + 0x78, 10.0f, 18.5f, 0.0f, 0.0f);
    func_003AB7E0(p + 0x78, tex, 0);
    p[0xB2] = 1;
    func_0011A264(p + 0xB4, 0, 0x18);
    func_003ABDB0(p + 0xD0, D_001D8558_bfDB90, pool);
    func_003AB3B0(p + 0xD0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003ABE40(p + 0xD0, p + 0xB4);
    func_003AB288(p + 0xD0, 64.0f, 15.0f, 0.0f, 0.0f);
    func_003ABE38(p + 0xD0, 0);
    func_003ABB30(p + 0x110, D_001D8568_bfDB90, pool);
    func_003AB3B0(p + 0x110, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x110, 20.0f, 15.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x110) = 0x60F0F0B0;
    func_003AB608(p + 0x140, D_001D8578_bfDB90, pool);
    func_003AB288(p + 0x140, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0(p + 0x140, tex, 0);
    func_003AB608(p + 0x17C, D_001D8588_bfDB90, pool);
    func_003AB288(p + 0x17C, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003AB7E0(p + 0x17C, tex, 0);
    func_0011A264(p + 0x1B8, 0, 0x18);
    func_003ABDB0(p + 0x1D0, D_001D8598_bfDB90, pool);
    func_003AB3B0(p + 0x1D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003ABE40(p + 0x1D0, p + 0x1B8);
    func_003AB288(p + 0x1D0, 440.0f, 15.0f, 0.0f, 0.0f);
    func_003ABE38(p + 0x1D0, 2);
    func_003ABB30(p + 0x210, D_001D85A8_bfDB90, pool);
    func_003AB3B0(p + 0x210, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x210, 457.0f, 15.0f, 0.0f, 0.0f);
    func_003ABD40(p + 0x210, 0x7567, 0);
    if (pool != 0) {
        f32 *q = (f32 *)func_003F2740(0x10, (s32)func_003AC270(pool));
        *(f32 **)(p + 0x7E4) = q;
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 0.0f;
    }

    func_003AB608(p + 0x244, D_001D85B8_bfDB90, pool);
    func_003AB7E0(p + 0x244, tex, 0x29);
    func_003AB3B0(p + 0x244, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x244, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x244) = 0x1465B7;
    func_003AB348(p + 0x244, *(s32 *)(p + 0x7E4));
    p[0x27E] = 1;
    func_003AB608(p + 0x280, D_001D85C8_bfDB90, pool);
    func_003AB7E0(p + 0x280, tex, 0x25);
    func_003AB3B0(p + 0x280, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x280, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x280) = 0x2299DE;
    func_003AB348(p + 0x280, *(s32 *)(p + 0x7E4));
    p[0x2BA] = 1;
    func_003AB608(p + 0x628, D_001D85D8_bfDB90, pool);
    func_003AB7E0(p + 0x628, tex, 0x2A);
    func_003AB288(p + 0x628, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x628) = 0xFFFEED;
    func_003AB2B8(p + 0x628, 0);
    p[0x662] = 1;
    func_003AB608(p + 0x49C, D_001D85E8_bfDB90, pool);
    func_003AB7E0(p + 0x49C, tex, 0x27);
    func_003AB288(p + 0x49C, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x49C) = 0x8000FFFF;
    func_003AB348(p + 0x49C, *(s32 *)(p + 0x7E4));
    p[0x4D6] = 1;
    func_003AB608(p + 0x4D8, D_001D85F8_bfDB90, pool);
    func_003AB7E0(p + 0x4D8, tex, 0x28);
    func_003AB288(p + 0x4D8, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x4D8) = 0x80FFFF00;
    func_003AB348(p + 0x4D8, *(s32 *)(p + 0x7E4));
    p[0x512] = 1;
    func_003AB608(p + 0x514, D_001D8608_bfDB90, pool);
    func_003AB7E0(p + 0x514, tex, 0x26);
    func_003AB288(p + 0x514, 125.0f, 208.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x514) = 0x800000FF;
    func_003AB348(p + 0x514, *(s32 *)(p + 0x7E4));
    p[0x54E] = 1;
    func_003AB608(p + 0x550, D_001D8618_bfDB90, pool);
    func_003AB7E0(p + 0x550, tex, 0x8B);
    func_003AB288(p + 0x550, 52.0f, 281.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x550) = 0x800000FF;
    func_003AB348(p + 0x550, *(s32 *)(p + 0x7E4));
    p[0x58A] = 1;
    {
        f32 *s = func_003AB268(p + 0x550);
        s[0] = -s[0];
    }
    func_003AB608(p + 0x58C, D_001D8630_bfDB90, pool);
    func_003AB7E0(p + 0x58C, tex, 0x8A);
    func_003AB288(p + 0x58C, 52.0f, 281.0f, 0.0f, 0.0f);
    *func_003AB270(p + 0x58C) = 0x800000FF;
    func_003AB348(p + 0x58C, *(s32 *)(p + 0x7E4));
    p[0x5C6] = 1;
    {
        f32 *s = func_003AB268(p + 0x58C);
        s[0] = -s[0];
    }
    func_003ABB30(p + 0x5C8, D_001D8640_bfDB90, pool);
    func_003AB3B0(p + 0x5C8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x5C8, 24.0f, 278.0f, 0.0f, 0.0f);
    func_003ABD40(p + 0x5C8, 0xED51, 0);
    func_003AB2B8(p + 0x5C8, 0);
    *func_003AB270(p + 0x5C8) = 0xF0F0B0;
    func_003ABB30(p + 0x5F8, D_001D8650_bfDB90, pool);
    func_003AB3B0(p + 0x5F8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003AB288(p + 0x5F8, 23.0f, 277.0f, 0.0f, 0.0f);
    func_003ABD40(p + 0x5F8, 0xED56, 0);
    func_003AB2B8(p + 0x5F8, 0);
    *func_003AB270(p + 0x5F8) = 0xF0F0B0;

    /* the eight ring icons (p+0x2BC, 0x3C each) and labels (p+0x664, 0x30 each) */
    i = 0;
    do {
        u8 *icon;
        u8 *label;
        f32 a, x, y;

        func_0011B2E8(buf, D_001D8660_bfDB90, i);
        icon = p + 0x2BC + i * 0x3C;
        func_003AB608(icon, buf, pool);
        func_003AB7E0(icon, tex, i + 3);
        func_003AB3B0(icon, 1.0f, 1.0f, 0.0f, 0.0f);
        func_003AB288(icon, 125.0f, 208.0f, 0.0f, 0.0f);
        func_003AB348(icon, *(s32 *)(p + 0x7E4));
        p[i * 0x3C + 0x2F6] = 1;
        *func_003AB270(icon) = 0x1465B7;

        func_0011B2E8(buf, D_001D8670_bfDB90, i);
        label = p + 0x664 + i * 0x30;
        func_003ABB30(label, buf, pool);
        func_003AB2B8(label, 0);
        a = func_0038DE98(((f32)i + (f32)i) * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        i++;
        x = (f32)(D_001D8690_bfDB90 + D_001D867C_bfDB90 + (s32)(D_001D8684_bfDB90 * func_0038D478(a) * D_001D8688_bfDB90));
        y = (f32)(D_001D8694_bfDB90 + D_001D8680_bfDB90 + (s32)(D_001D8684_bfDB90 * func_0038D490(a) * D_001D868C_bfDB90));
        func_003AB288(label, x, y, 0.0f, 0.0f);
        func_003AB3B0(label, 32.0f, 32.0f, 0.0f, 0.0f);
        *func_003AB270(label) = 0xF0F0B0;
    } while (i < 8);

    {
        s32 *c = func_003AB270(p + 0x5C8);
        *c = (*c & 0xFF000000) | 0x1465B7;
        c = func_003AB270(p + 0x5F8);
        *c = (*c & 0xFF000000) | 0x1465B7;
    }

    /* second layout for the labels */
    i = 0;
    do {
        u8 *label;
        f32 a, x, y;
        s32 *c;

        a = func_0038DE98(((f32)i + (f32)i) * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D86AC_bfDB90 + D_001D8698_bfDB90 + (s32)(D_001D86A0_bfDB90 * func_0038D478(a) * D_001D86A4_bfDB90));
        y = (f32)(D_001D86B0_bfDB90 + D_001D869C_bfDB90 + (s32)(D_001D86A0_bfDB90 * func_0038D490(a) * D_001D86A8_bfDB90));
        label = p + 0x664 + i * 0x30;
        i++;
        func_003AB288(label, x, y, 0.0f, 0.0f);
        func_003AB3B0(label, 32.0f, 32.0f, 0.0f, 0.0f);
        c = func_003AB270(label);
        *c = (*c & 0xFF000000) | (D_001D86B4_bfDB90 & 0xFFFFFF);
    } while (i < 8);

    /* icons 1-7 and labels 1-7 share slot 0's scale */
    for (i = 0; i < 7; i++) {
        func_003AB2D8(p + 0x2F8 + i * 0x3C, func_003AB268(p + 0x2BC));
        func_003AB2D8(p + 0x694 + i * 0x30, func_003AB268(p + 0x664));
    }
    func_003AB2D8(p + 0x244, func_003AB268(p + 0x2BC));

    /* animator 0x7E8 */
    func_003AD7E0(p + 0x7E8, pool);
    func_003AD940(p + 0x7E8, 3);
    func_003AD8F0(p + 0x7E8, 0, 0.0f, fb_003ADB90(0x442D00), 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x7E8, 1, 0.3f, fb_003ADB90(0x331465B7), 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x7E8, 2, 1.0f, fb_003ADB90(0x331465B7), 0.0f, 0.0f, 0.0f);
    func_003AD928(p + 0x7E8, 1, 0.0f, 2.0f);
    anim_tail_003ADB90(p + 0x7E8, func_003AB270(p + 0x2BC), p + 0xB1C);

    /* animator 0x870 */
    func_003AD7E0(p + 0x870, pool);
    func_003AD940(p + 0x870, 3);
    func_003AD8F0(p + 0x870, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x870, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x870, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    anim_tail_003ADB90(p + 0x870, func_003AB268(p + 0x2BC), p + 0xB18);

    /* animator 0xA08 */
    func_003AD7E0(p + 0xA08, pool);
    func_003AD940(p + 0xA08, 3);
    func_003AD8F0(p + 0xA08, 0, 0.0f, fb_003ADB90(0xF0F0B0), 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0xA08, 1, 0.5f, fb_003ADB90(0xF0F0B0), 0.0f, 0.0f, 0.0f);
    func_003AD928(p + 0xA08, 0, 0.0f, 0.0f);
    func_003AD8F0(p + 0xA08, 2, 1.0f, fb_003ADB90(0x80FFFFFF), 0.0f, 0.0f, 0.0f);
    func_003AD928(p + 0xA08, 1, 0.0f, 0.0f);
    anim_tail_003ADB90(p + 0xA08, func_003AB270(p + 0x664), p + 0xB1C);

    /* animator 0x8F8 */
    func_003AD7E0(p + 0x8F8, pool);
    func_003AD940(p + 0x8F8, 3);
    func_003AD8F0(p + 0x8F8, 0, 0.0f, fb_003ADB90(0xF0C070), 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x8F8, 1, 0.3f, fb_003ADB90(0x332299DE), 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x8F8, 2, 1.0f, fb_003ADB90(0x332299DE), 0.0f, 0.0f, 0.0f);
    func_003AD928(p + 0x8F8, 1, 0.0f, 3.0f);
    anim_tail_003ADB90(p + 0x8F8, func_003AB270(p + 0x280), p + 0xB1C);

    /* animator 0x980 */
    func_003AD7E0(p + 0x980, pool);
    func_003AD940(p + 0x980, 3);
    func_003AD8F0(p + 0x980, 0, 0.0f, 1.2f, 1.2f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x980, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0x980, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    anim_tail_003ADB90(p + 0x980, func_003AB268(p + 0x280), p + 0xB18);

    /* animator 0xA90 */
    func_003AD7E0(p + 0xA90, pool);
    func_003AD940(p + 0xA90, 3);
    func_003AD8F0(p + 0xA90, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0xA90, 1, 0.01f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003AD8F0(p + 0xA90, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    anim_tail_003ADB90(p + 0xA90, *(void **)(p + 0x7E4), p + 0xB18);

    *(s32 *)(p + 0xB28) = 0;
    *(s32 *)(p + 0xB3C) = -1;
    *(s32 *)(p + 0xB2C) = -1;
    *(s32 *)(p + 0xB30) = 0;
    *(s32 *)(p + 0xB34) = -1;
    *(s32 *)(p + 0xB38) = 0;
}
