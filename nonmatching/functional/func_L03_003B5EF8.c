/* functional: high. Rewrote from PAL asm (NTSC draft constants differ: 0.02 not 1/60, gp slots). VU0 vsub/vadd via inline asm as allowed; 137 byte diff only from VU scheduling. */
/* localdecomp:start func_L03_003B5EF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3B5EF8;
typedef int Q_3B5EF8 __attribute__((mode(TI)));
extern u8 *D_L03_001E9218;
extern u8 D_L03_001E1DC8[];
__asm__(".extern D_001DEA08_sda, 4");
__asm__(".extern D_001DEA0C_sda, 4");
__asm__(".extern D_001DEA00_sda, 4");
__asm__(".extern D_001DE9FC_sda, 4");
__asm__(".extern D_001DE9F8_sda, 4");
extern f32 D_001DEA08_sda;
extern f32 D_001DEA0C_sda;
extern f32 D_001DEA00_sda;
extern f32 D_001DE9FC_sda;
extern s32 D_001DE9F8_sda;
extern void func_L03_003B6370(void);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L03_0034B218(void *, s32, s32, s32, void (*)(void), f32);

u8 *func_L03_003B5EF8(u8 *self, s32 joint, s32 kind, f32 speed) {
    V_3B5EF8 start, end, delta, point;
    u8 collision[0x30];
    u8 *owner = *(u8 **)(self + 0x68);
    u8 *object;
    u8 *state;
    func_003C2F58(*(void **)owner, joint, &start);
    func_003C2F58(*(void **)owner, joint + 0x20, &end);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(start), "m"(end));
    func_0038CF68(&delta, &delta, D_001DEA08_sda);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(point) : "m"(start), "m"(delta));
    func_L01_00446748(collision, self, 0, 0.0f);
    *(u16 *)(collision + 0x1A) = *(u16 *)(self + 0xAA);
    if (func_003D3CB0(&start, &point, 0, self, collision)) {
        if (D_L03_001E9218 && *(s16 *)(D_L03_001E9218 + 0xAA) == 0x1C06)
            return 0;
        if (kind == 0 || kind == 3 || kind == 6) {
            u8 *hit = D_L03_001E9218;
            if (hit && *(s16 *)(hit + 0xAA) == 0x1C04) {
                s32 hit_kind = *(s32 *)(*(u8 **)(hit + 0x68) + 0x24);
                if (hit_kind == 0 || hit_kind == 3 || hit_kind == 6) return 0;
            }
        }
    }
    object = func_003C24B0(0x1C04, 0x80);
    if (object) {
        *(u8 *)(object + 0x30) = 0xFF;
        *(u8 *)(object + 0x31) = 1;
        *(u16 *)(object + 0x32) = 0x40;
        *(f32 *)(object + 0x2C) *= D_001DEA0C_sda;
        *(void **)(object + 0xB8) = self;
        state = *(u8 **)(object + 0x68);
        if (kind == 0 || kind == 3 || kind == 6) {
            *(u8 *)(object + 0x31) = 0;
            *(u16 *)(object + 0x34) |= 1;
        } else {
            *(u8 *)(object + 0x31) = 1;
            *(u16 *)(object + 0x34) &= 0xFFFE;
        }
        *(s32 *)(object + 0x98) = *(s32 *)(*(u8 **)(object + 0x24) + 0x10);
        *(s32 *)(state + 0x24) = kind;
        *(f32 *)(state + 0x20) = speed * 0.02f;
        *(s32 *)(state + 0x30) = joint;
        *(f32 *)(state + 0x38) = D_001DEA00_sda;
        *(f32 *)(state + 0x3C) = D_001DE9FC_sda;
        *(s32 *)(state + 0x28) = 0;
        *(s32 *)(state + 0x34) = 0;
        *(Q_3B5EF8 *)(state + 0x10) = *(Q_3B5EF8 *)&start;
        *(Q_3B5EF8 *)state = *(Q_3B5EF8 *)&end;
        *(void **)(state + 0x2C) = *(void **)owner;
        *(Q_3B5EF8 *)(object + 0x10) = *(Q_3B5EF8 *)&start;
    }
    if (D_001DE9F8_sda == 0) {
        D_001DE9F8_sda = 1;
        func_L03_0034B218(D_L03_001E1DC8, 0x19, 0x11, 2, func_L03_003B6370, 2.1f);
    }
    return object;
}
/* localdecomp:end func_L03_003B5EF8 */
