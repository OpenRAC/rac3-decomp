/* functional: high. Same instructions as retail, only ordering of independent stores/prologue differs. */
typedef int Q_331D28 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];           /* 0x00: D_001D66B0 scaled by 1.0; w replaced by 5627.925 */
    void *obj;          /* 0x10 */
    s32 target;         /* 0x14: pvar+0x64 */
    u8 b18;             /* 0x18 */
    u8 b19;             /* 0x19 */
    u16 h1A;            /* 0x1A */
    f32 f1C;            /* 0x1C: the call's f12 argument */
    s32 w20;            /* 0x20 */
} S_331D28 __attribute__((aligned(16)));
extern u8 D_001D66B0[];
extern void func_0038CF68(void *, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);

void func_L01_00331D28(u8 *obj, f32 f) {
    S_331D28 s;
    u8 *st = *(u8 **)(obj + 0x68);

    s.obj = obj;
    *(Q_331D28 *)s.v = *(Q_331D28 *)D_001D66B0;
    s.target = *(s32 *)(st + 0x64);
    s.f1C = f;
    s.w20 = 1;
    func_0038CF68(s.v, s.v, 1.0f);
    s.h1A = *(u16 *)(obj + 0xAA);
    s.v[3] = 5627.925f;
    s.b18 = 3;
    s.b19 = 2;
    func_003D4D00(obj + 0x10, 0, 0, &s, *(f32 *)(st + 0x68));
}
