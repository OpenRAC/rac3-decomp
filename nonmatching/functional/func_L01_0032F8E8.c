/* functional: high. Written from the PAL asm (not the NTSC-U draft); retail's frame is bigger and scheduling differs, behaviour same: same calls/args/stores in the same order. */
typedef int Q_32F8E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32F8E8;
extern u8 *D_001A71A0;
extern s32 D_001DCEC8_sda;
__asm__(".extern D_001DCEC8_sda, 4");
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_L01_004C80F8(void *, s32);
extern void func_003C2880(void *);
extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
extern void func_003C7C38(void *);

u8 *func_L01_0032F8E8(u8 *owner, Q_32F8E8 *pos, Q_32F8E8 *vel) {
    u8 *o;
    u8 *s;
    V4_32F8E8 a0;
    V4_32F8E8 a1;
    V4_32F8E8 b;
    V4_32F8E8 c;
    V4_32F8E8 d;
    Q_32F8E8 q;
    f32 f;
    s32 r;
    s32 v;

    o = func_003C24B0(0x1367, 0xC0);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(Q_32F8E8 *)(o + 0x10) = *pos;
        *(Q_32F8E8 *)s = *vel;
        func_0038D308(o + 0xC0, D_001A71A0 + 0xF0);
        func_L01_004C7D98(o + 0x10, &a0);
        func_0038CF68(&a1, o + 0xE0, 1.0f);
        func_0038CE90(&c, &a1, &a0);
        f = func_0038CE68(&a1, &a0) * 0.5f;
        func_0038CE20(&b, &c, func_0038D0B0(f));
        b.w = func_0038D098(f);
        func_0038D810(&b, &d);
        func_0038D5F0(o + 0xC0, &d, o + 0xC0);
        *(Q_32F8E8 *)(s + 0x10) = 0;
        *(f32 *)(s + 0x10) = 1.0f;
        *(s32 *)(s + 0x68) = (s32)owner;
        *(s32 *)(s + 0x64) = 0;
        *(s32 *)(s + 0x50) = 0;
        *(s32 *)(s + 0x44) = 0;
        *(s16 *)(s + 0x92) = 0;
        *(s32 *)(s + 0x60) = 13;
        *(s16 *)(s + 0x4C) = 1;
        q = *(Q_32F8E8 *)(s + 0x10);
        *(Q_32F8E8 *)(s + 0x20) = q;
        *(f32 *)(s + 0x58) = 0.031415928f;
        *(Q_32F8E8 *)(s + 0x30) = q;
        *(s32 *)(s + 0x40) = (D_001DCEC8_sda * 5 + 2) / 6;
        r = func_L01_004C80F8(o, 0);
        *(s32 *)(s + 0x48) = r;
        if (r == -1) {
            func_003C2880(o);
            return 0;
        }
        v = func_L01_004C85C8(o, 0, 1.0f, 1.0f, 1.0f);
        s[0x4E] = -1;
        *(s32 *)(s + 0x70) = 0;
        s[0x4F] = v;
        func_003C7C38(o);
    }
    return o;
}
