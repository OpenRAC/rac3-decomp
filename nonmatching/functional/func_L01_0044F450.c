/* functional: high. PAL near-miss draft (19 diff words with vu0 helper asm) rewritten with plain float code for the one vadd.xyz (vec_add_ba) and plain copies; checked the vadd/lqc2 forms and callee names against asm. Plain-C version has 68 diff words (VU scheduling only). Types s128_44C0E8/M_44C0E8 come from the file context */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0044F450;
typedef struct {
    V4_0044F450 matrix[4];
    void *extra;
    u8 *parent;
    s16 id;
    u8 last, bone, flags, copy, period, phase;
} Link_0044F450;
extern u8 *D_L01_001E001C[];
extern u8 *D_L01_001E0DC8[];
extern u8 *D_L01_001E0EDC;
extern u8 *D_L01_001E0DD0;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 4");
extern void *D_L01_00238470[];
void func_L01_0044F450(u8 *obj, Link_0044F450 *links) {
    extern void func_0038CD28(void *, void *, s32);
    extern void func_0038D308(void *, void *);
    extern void func_003C2EC0(u8 *, int, s128_44C0E8 *);
    extern void func_0038D590(void *, void *);
    extern void func_L01_0044F368(M_44C0E8 *, void *, void *);
    extern void func_0038D570(void *, void *);
    extern void func_003C48A8(f32 *, f32 *);
    extern void func_L01_0044F280(void *, void *, void *, void *, void *);
    extern void func_003C7C38(u8 *);
    extern void func_L01_004B3338(s32, long);
    extern f32 func_0038CEA8(void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE50(f32, void *, void *);
    V4_0044F450 matrix[4];
    V4_0044F450 temp[4];
    Link_0044F450 *p;
    void **table;
    f32 factor;
    if (links->last == 0) return;
    if (links->copy) func_0038CD28(matrix, obj + 0xC0, 0x30);
    else func_0038D308(matrix, obj + 0xF0);
    matrix[3] = *(V4_0044F450 *)(obj + 0x10);
    table = D_L01_00238470;
    factor = 4096.0f;
    matrix[3].w = 0.0f;
    p = links;
    do {
        if (p->parent) {
            func_003C2EC0(p->parent, p->bone, (s128_44C0E8 *)temp);
            func_0038D590(matrix, temp);
        }
        switch (p->flags & 3) {
        case 0: {
            u8 *m = D_L01_001E001C[0] + (p->id << 8);
            if (*(s32 *)(m + 0x24) == 0) func_0038D308(m + 0xC0, m + 0xF0);
            func_L01_0044F368((M_44C0E8 *)p, matrix, m + 0xC0);
            if (*(s32 *)(m + 0x24) == 0) {
                func_0038D570(temp, m + 0xC0);
                func_003C48A8((f32 *)temp, (f32 *)(m + 0xF0));
            }
            break; }
        case 1: {
            func_L01_0044F368((M_44C0E8 *)p, matrix, D_L01_001E0EDC + (p->id << 6));
            break; }
        case 2: {
            u8 *m = (u8 *)((p->id << 6) + (s32)D_L01_001E0DD0);
            f32 scale = *(f32 *)(m + 0x1C);
            func_L01_0044F368((M_44C0E8 *)p, matrix, m);
            *(f32 *)((p->id << 6) + (s32)D_L01_001E0DD0 + 0x1C) = scale;
            break; }
        }
        switch (p->flags & 3) {
        case 0: {
            u8 *m = D_L01_001E001C[0] + (p->id << 8);
            func_L01_0044F280(m + 0x10, p, &matrix[3], matrix, m + 0xC0);
            break; }
        case 1: {
            u8 *m = D_L01_001E0EDC + (p->id << 6);
            func_L01_0044F280(m + 0x30, p, &matrix[3], matrix, m);
            break; }
        case 2: {
            u8 *m = D_L01_001E0DD0 + (p->id << 6);
            func_L01_0044F280(m + 0x30, p, &matrix[3], matrix, m);
            break; }
        }
        switch (p->flags & 3) {
        case 0: {
            u8 *m = (u8 *)((p->id << 8) + (s32)D_L01_001E001C[0]);
            if (*(s32 *)(m + 0x24)) func_003C7C38(m);
            break; }
        case 1: {
            long active = 0;
            if (p->period == 0) active = 1;
            else if (p->period == 255) active = 0;
            else {
                active = 1;
                if (D_L01_001DFB40 % p->period != p->phase) active = 0;
            }
            func_L01_004B3338(p->id, active);
            break; }
        case 2: {
            u8 *m = D_L01_001E0DD0 + (p->id << 6);
            u8 *n = D_L01_001E0DC8[0] + (p->id << 5);
            f32 scale;
            s32 x, y;
            scale = func_0038CEA8(m);
            scale += func_0038CEA8(m + 0x10);
            scale *= 0.5f;
            x = (s32)(func_0038CEA8(m + 0x20) * factor);
            y = (s32)(scale * factor);
            if (x > 65536) x = 65536;
            if (y > 65536) y = 65536;
            *(s32 *)(m + 0x2C) = y | (x << 16);
            func_0038D000(n, table[n[0x1A]], m);
            func_0038CE50(*(f32 *)(m + 0x3C), n, n);
            ((V4_0044F450 *)n)->x = ((V4_0044F450 *)n)->x + ((V4_0044F450 *)(m + 0x30))->x;
            ((V4_0044F450 *)n)->y = ((V4_0044F450 *)n)->y + ((V4_0044F450 *)(m + 0x30))->y;
            ((V4_0044F450 *)n)->z = ((V4_0044F450 *)n)->z + ((V4_0044F450 *)(m + 0x30))->z;
            break; }
        }
    } while ((p++)->last != 1);
}
