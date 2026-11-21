/* functional: high. Near miss at level 01 (4 instructions scheduled differently, same operations); checked against PAL asm. */
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_0032C6B8 */
typedef struct {
    u8 pad0[0x48];
    s32 w48;
} S_32C6B8m;
typedef struct {
    u8 pad0[0x68];
    S_32C6B8m *p68;
} S_32C6B8;
extern u8 *func_L01_004C80D0(s32 a0);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C47E8(void *, void *);

void func_L01_0032C6B8(S_32C6B8 *a0, s128 *a1) {
    struct { s128 a, b, c, d, e, f, g; } L;
    u8 *r;

    r = func_L01_004C80D0(a0->p68->w48);
    L.a = L.d = *a1;
    L.e = 0;
    ((f32 *)&L.e)[2] = 1.0f;
    func_0038CE90(&L.b, &L.a, &L.e);
    func_0038CF68(&L.b, &L.b, 1.0f);
    func_0038CE90(&L.c, &L.b, &L.a);
    func_003C47E8(r + 0x10, &L.a);
    func_003C2F58(a0, 0, &L.f);
    func_0038D000(&L.d, a1, (u8 *)a0 + 0xC0);
    vec_add_ab(&L.g, &L.d, &L.f);
}
/* localdecomp:end func_L01_0032C6B8 */
