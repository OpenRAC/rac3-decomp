/* functional: high. Same order: call per entry, then two quad stores after it. Callee func_L01_0040C7A0(entry+0x270, obj+0x7F0). */
/* localdecomp:start func_L03_003AEA48 */
typedef int Q_3AEA48 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3AEA48;
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0040C7A0(void *, void *);
void func_L03_003AEA48(u8 *obj) {
    V_3AEA48 center;
    V_3AEA48 pts[8];
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    for (i = 0; i < 8; i++) {
        func_003C2F58(*(void **)v, 0x20 + i * 4, &pts[i]);
    }
    func_003C2F58(*(void **)v, 0x41, &center);
    for (i = 0; i < 8; i++) {
        u8 *e = v + i * 0xB0;
        *(s32 *)(e + 0x290) = 0x1B4E206C;
        *(s32 *)(e + 0x294) = -1;
        func_L01_0040C7A0(e + 0x270, v + 0x7F0);
        *(Q_3AEA48 *)(e + 0x270) = *(Q_3AEA48 *)&center;
        *(Q_3AEA48 *)(e + 0x280) = *(Q_3AEA48 *)&pts[i];
    }
}
/* localdecomp:end func_L03_003AEA48 */
