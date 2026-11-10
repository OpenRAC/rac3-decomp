/* func_L24_003B8878: near miss (Sonnet w4 p2w3): NEAR 4
   Size 336 bytes. needs --as ps2as (inline float consts); all matches except final 4 insns: reg alloc of slot/p24/value tail (a1/v1/a0 vs a0/v0/v1); twin was wrong, written from asm
   Left for lead: see note.
*/
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[0x70]; s32 w98; } Slot24;
typedef struct { u8 pad[0x25C0]; Slot24 *slot; } Hero24;
extern Hero24 D_1A4BE0;
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00446760(void *, void *, void *, void *, f32);
extern s32 func_003D3CB0();
void func_L24_003B8878(u8 *obj, void *p1, void *p2, void *p3, s32 b4, s32 b5, s32 p6, f32 sc, f32 len) {
    f32 dir[4] __attribute__((aligned(16)));
    u8 q[0x30] __attribute__((aligned(16)));
    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(u128_t *)dir = *(u128_t *)(obj + 0xC0);
    } else {
        dir[0] = func_0038D098(*(f32 *)(obj + 0xF8));
        dir[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
        dir[2] = 0.0f;
    }
    func_0038CE20(dir, dir, len);
    dir[2] = 1.0f;
    dir[3] = 5627.9248046875f;
    func_L01_00446760(q, obj, p3, dir, sc);
    *(u8 *)(q + 0x18) = b4;
    *(u8 *)(q + 0x19) = b5;
    *(u8 **)(q + 0x10) = obj;
    *(u16 *)(q + 0x1A) = *(u16 *)(obj + 0xAA);
    D_1A4BE0.slot->w98 = 0;
    func_003D3CB0(p1, p2, p6, obj, q);
    D_1A4BE0.slot->w98 = *(s32 *)(D_1A4BE0.slot->p24 + 0x10);
}
