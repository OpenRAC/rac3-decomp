/* functional: high. Only 28 byte diff words (callee order). Sibling of func_L03_003B5EF8 without the ray test. */
/* localdecomp:start func_L03_003B6CB8 */
typedef int Q_3B6CB8 __attribute__((mode(TI)));
extern u8 D_L03_001E1DE8[];
__asm__(".extern D_001DEA68_sda, 4");
__asm__(".extern D_001DEA64_sda, 4");
__asm__(".extern D_001DEA38_sda, 4");
extern f32 D_001DEA68_sda;
extern f32 D_001DEA64_sda;
extern s32 D_001DEA38_sda;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L03_003B7190(void);
extern void func_L03_0034B218(void *, s32, s32, s32, void (*)(void), f32);

u8 *func_L03_003B6CB8(u8 *self, s32 joint, f32 speed) {
    u8 *obj = func_003C24B0(0x1C06, 0x80);
    u8 *state;
    u8 *owner;
    if (obj) {
        obj[0x30] = 0xFF;
        obj[0x31] = 1;
        obj[0x20] = 5;
        *(u16 *)(obj + 0x32) = 0x40;
        *(u8 **)(obj + 0xB8) = self;
        state = *(u8 **)(obj + 0x68);
        *(u16 *)(obj + 0x96) = 0;
        *(f32 *)(state + 0x20) = speed * 0.02f;
        *(f32 *)(state + 0x38) = D_001DEA68_sda;
        *(f32 *)(state + 0x3C) = D_001DEA64_sda;
        *(s32 *)(state + 0x24) = 0;
        *(s32 *)(state + 0x30) = joint;
        *(s32 *)(state + 0x34) = 0;
        *(s32 *)(state + 0x48) = 0;
        owner = *(u8 **)(self + 0x68);
        func_003C2F58(*(void **)owner, joint, state + 0x10);
        func_003C2F58(*(void **)owner, joint + 0x20, state);
        *(f32 *)(state + 0x44) = *(f32 *)(*(u8 **)owner + 0xF0);
        *(void **)(state + 0x28) = *(void **)owner;
        *(Q_3B6CB8 *)(obj + 0x10) = *(Q_3B6CB8 *)(state + 0x10);
    }
    if (D_001DEA38_sda == 0) {
        D_001DEA38_sda = 1;
        func_L03_0034B218(D_L03_001E1DE8, 0x19, 0x11, 0, func_L03_003B7190, 2.1f);
    }
    return obj;
}
/* localdecomp:end func_L03_003B6CB8 */
