/* functional: high. Written from the asm, 269 diff (register allocation and colour-expression sharing only; frame size and block order agree). 4 callees renamed via catalogue places; D_001D64E0/D_0021D500/D_001E8E58 as in the file. Route array: entry idx+1/idx+2 are 16-byte quads after a count word. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CFC58;
typedef struct {
    s32 path;
    u8 pad4[0x1C];
    s32 x20;
    f32 x24;
    f32 x28;
    u8 c0, c1, c2, c3;
    u8 pad30[0x24];
    V4_3CFC58 *route;
    f32 timer;
    s32 idx;
    s32 sound;
    s32 cooldown;
    u8 pad68[8];
    V4_3CFC58 a;
    V4_3CFC58 b;
    V4_3CFC58 c;
    V4_3CFC58 d;
    s32 xB0;
    s32 xB4;
    s32 xB8;
    s32 xBC;
} V_3CFC58;
extern V4_3CFC58 *D_0021D500[];
extern u8 D_001D64E0[];
extern u8 D_001D66F0[8];
extern u8 D_001A30B0[];
extern s32 D_001E8E58;
extern s32 D_00142668[];
extern void func_003C2880(void *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_0040E050(void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003C7DD8(void *);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L19_003D0108(void *);
extern s32 func_L19_003D0130(s32 a);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L19_003CFC58(u8 *obj) {
    V_3CFC58 *v = *(V_3CFC58 **)(obj + 0x68);
    V4_3CFC58 *e;
    u8 *s;
    s32 col;
    s32 a1;

    switch (obj[0x20]) {
    case 0:
        if (v->path == -1) {
            func_003C2880(obj);
            return;
        }
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        v->idx = 0;
        v->route = D_0021D500[v->path];
        col = (v->c3 << 24) | (v->c2 << 16) | (v->c1 << 8) | v->c0;
        v->c = v->route[1];
        v->a = v->route[1];
        v->d = v->route[2];
        v->b = v->route[2];
        v->xB4 = -1;
        v->xB8 = col;
        v->xBC = col;
        v->xB0 = -1;
        func_L01_0040C7A0(&v->c, D_001D64E0);
        if (v->x20 == 0) {
            a1 = 2;
            v->timer = (v->x28 * 5.0f + 2.0f) / 6.0f;
        } else {
            a1 = 1;
            v->timer = (v->x24 * 5.0f + 2.0f) / 6.0f;
        }
        func_L01_004450F0(obj, a1, -1);
        break;
    case 2:
        if (v->sound != -1 && (s = D_001A30B0 + (v->sound << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
            func_003A4F28(v->sound);
        v->sound = -1;
        if (func_L01_0040E050(&v->timer) == 0)
            return;
        v->timer = (v->x24 * 5.0f + 2.0f) / 6.0f;
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_0040E050(&v->timer) != 0) {
            v->idx++;
            if (v->idx < *(s32 *)v->route - 1) {
                v->timer = (v->x24 * 5.0f + 2.0f) / 6.0f;
            } else {
                v->idx = 0;
                v->timer = (v->x28 * 5.0f + 2.0f) / 6.0f;
                func_L01_004450F0(obj, 2, -1);
            }
            e = v->route + v->idx;
            v->c = e[1];
            v->a = e[1];
            v->d = e[2];
            v->b = e[2];
            *(V4_3CFC58 *)(obj + 0x10) = e[2];
            func_003C7DD8(obj);
            if (obj[0x20] == 2)
                return;
        }
        if (v->sound == -1 || (s = D_001A30B0 + (v->sound << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
            v->sound = func_003A52A0(0, 4, obj);
        col = (v->c3 << 24) | (v->c2 << 16) | (v->c1 << 8) | v->c0;
        func_L01_0046B458((u8 *)&v->a, 1, 1.0f, 1.0f, col, 0, 0, D_001D66F0, 0.0f, 0);
        col = (v->c3 << 24) | (v->c2 << 16) | (v->c1 << 8) | v->c0;
        func_L01_0046B458((u8 *)&v->b, 1, 1.0f, 1.0f, col, 0, 0, D_001D66F0, 0.0f, 0);
        func_L01_0040C8A0(&v->c, D_001D64E0);
        func_L01_00404A10(func_L19_003D0108, obj);
        if (func_L03_00433C70(obj, &v->a, &v->b, 0x410001, 0, 1, 0,
                              (f32)func_L19_003D0130(D_00142668[0] / 5 + 1), 1.0f) != 0
            && D_001E8E58 != 0 && v->cooldown <= 0) {
            func_003A52A0(1, 0, obj);
            v->cooldown = 0x11;
        }
        break;
    }
}
