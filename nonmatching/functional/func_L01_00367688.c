/* functional: high. Only a vadd scheduling diff (4 words); callee names and D_001EAA20 checked against asm */
/* localdecomp:start func_L01_00367688 */
typedef struct {
    u8 pad[0x25C0];
    u8 *hero;
} Hero_00367688;
extern State_00366240 D_001A4BE0;
extern s32 D_001D545C;
extern s128 D_L01_001EAA20;
void func_L01_00367688(s128 *from, s128 *dir, s128 *out) {
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_L01_0040BE10(s128 *, s128 *);
    extern void func_003C7C38(void *);
    extern void func_L01_003F3740(s32);
    extern void func_L01_003F3768(s32);
    extern s32 func_003D3CB0(s128 *, s128 *, s32, s32, s32);
    s128 pos;
    f32 distance = 40.0f;
    if (D_001D545C == 11) distance = 80.0f;
    func_0038CE20(&pos, dir, distance);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(pos) : "m"(pos), "m"(*from) : "vf1", "vf2");
    func_L01_0040BE10(from, &pos);
    *(s32 *)(((Hero_00367688 *)&D_001A4BE0)->hero + 0x98) = 0;
    func_003C7C38(((Hero_00367688 *)&D_001A4BE0)->hero);
    func_L01_003F3740(0);
    if (func_003D3CB0(from, &pos, 0, 0, 0)) *out = D_L01_001EAA20;
    else *out = pos;
    *(s32 *)(((Hero_00367688 *)&D_001A4BE0)->hero + 0x98) = *(s32 *)(*(u8 **)(((Hero_00367688 *)&D_001A4BE0)->hero + 0x24) + 0x10);
    func_003C7C38(((Hero_00367688 *)&D_001A4BE0)->hero);
    func_L01_003F3768(0);
}
/* localdecomp:end func_L01_00367688 */
