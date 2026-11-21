/* functional: high. Uses the file's raw VU0 asm style. */
/* localdecomp:start func_L01_004741B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004741B8;
void func_L01_004741B8(u8 *p)
{
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    V_004741B8 delta;
    u8 *params = p + 0x30;
    u8 *tail;
    f32 t, scale;
    s32 alpha;
    s32 first, second;
    if (func_0038CB00(p + 0xA)) {
        func_003CD250(p);
        return;
    }
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*(V_004741B8 *)(p + 0x10)), "m"(*(V_004741B8 *)(p + 0x20)) : "vf1", "vf2");
    delta.w = 0;
    func_0038CF68(&delta, &delta, *(f32 *)params);
    tail = p + 0x20;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1"
        : "+m"(*(V_004741B8 *)(p + 0x10)), "+m"(*(V_004741B8 *)(p + 0x20)) : "m"(delta) : "vf1", "vf2");
    func_L01_004CAB30(p + 0x10, p + 0x10);
    func_L01_004CAB30(tail, tail);
    t = (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(params + 0xC);
    scale = 1.0f + (*(f32 *)(params + 8) - 1.0f) * t;
    *(f32 *)(p + 0x1C) = *(f32 *)(params + 4) * scale;
    if (*(s16 *)(p + 0xA) < p[8]) {
        alpha = (s32)(((f32)*(s16 *)(p + 0xA) / (f32)p[8]) * 127.0f);
        first = *(s32 *)(p + 4) & 0xFFFFFF;
        second = *(s32 *)(p + 0xC) & 0xFFFFFF;
        *(s32 *)(p + 0xC) = (alpha << 24) | second;
        *(s32 *)(p + 4) = (alpha << 24) | first;
    }
}
/* localdecomp:end func_L01_004741B8 */
