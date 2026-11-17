/* func_L19_003CF440: 41 diff in L19_003CDD90.c (-mvu0-use-vf0-vf2 @ps2as): two states (start the four beams; keep the sound, step and damage like func_L19_00323000). Left: the v->x4 colour is computed in $v1 (retail $v0), and the two spilled pointers (obj + 0xC0 at sp+0, obj + 0xF0 at sp+4): retail computes the first after func_L19_003CFB20 and stores it in func_003824E0's delay slot, here sched1 hoists it above the call. */
typedef struct {
    V4_3CF090 pos;
    V4_3CF090 x10;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
    u8 pad30[0x80];
} E_3CF440;
typedef struct {
    f32 x0;
    s32 x4;
    s32 x8;
    u8 padC[4];
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    u8 pad28[0x18];
    E_3CF440 e[4];
    s32 x300;
} D_3CF440;
typedef struct { u8 pad[8]; s32 x8; } G_3CF440;
typedef struct { u8 pad[0x18]; u8 *x18; } H_3CF440;
__asm__(".extern D_L19_001DEB3C, 4");
extern f32 D_L19_001DEB3C;
extern G_3CF440 D_00142660;
extern H_3CF440 D_L19_001E8E40;
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern u8 D_L19_001D66F0[8];
extern s32 func_00382468(s32);
extern void func_L19_003CFB20(u8 *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L19_003CF930(u8 *obj);
extern s32 func_L19_003D0130(s32 a);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_0038D308(void *, void *);

void func_L19_003CF440(u8 *obj) {
    D_3CF440 *v = *(D_3CF440 **)(obj + 0x68);
    E_3CF440 *e;
    u8 *p;
    u8 *a;
    u8 *b;
    u8 *s;
    s32 i;
    s32 k;
    s32 j;
    f32 f;

    switch (obj[0x20]) {
    case 0:
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        if (v->x8 > 4)
            v->x8 = 4;
        else if (v->x8 <= 0)
            v->x8 = 1;
        func_L19_003CF388((Foo_003CF388 *)obj);
        v->x4 = (v->x1C << 24) | (v->x18 << 16) | (v->x14 << 8) | v->x10;
        if (v->x4 <= 0) {
            k = 0xFF;
            k = (k << (func_00382468(3) * 8)) | 0xDD000000;
            v->x4 = k;
        }
        func_L19_003CFB20(obj);
        for (i = 0; i < v->x8; i++) {
            e = &v->e[i];
            e->pos = *(V4_3CF090 *)(obj + 0x10);
            e->x20 = -1;
            e->x24 = -1;
            e->x28 = v->x4;
            e->x2C = v->x4;
            func_L01_0040C7A0(e, &v->x300);
        }
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (v->x20 == -1 || (s = D_001A30B0 + (v->x20 << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
            v->x20 = func_003A52A0(0, 4, obj);
        k = 12;
        k -= (s32)(func_0038CF00(obj + 0x10, D_001A4C60) * D_L19_001DEB3C);
        if (k > 12)
            k = 12;
        else if (k < 4)
            k = 4;
        v->x300 = k;
        b = obj + 0xF0;
        func_L19_003CFB20(obj);
        a = obj + 0xC0;
        f = func_003824E0(1.0f, 2.0f);
        func_L01_0046B458(obj + 0x10, 2, f, f, v->x4, 0, 0, D_L19_001D66F0, 0.0f, 0);
        for (j = 0; j < v->x8; j++) {
            func_L01_0040C8A0(&v->e[j], &v->x300);
            func_L01_00404A10(func_L19_003CF930, obj);
            if (func_L03_00433C70(obj, obj + 0x10, &v->e[j].x10, 0x410001, 0, 1, 0,
                                  (f32)func_L19_003D0130(D_00142660.x8 / 5 + 1), 1.0f) != 0
                && D_L19_001E8E40.x18 != 0 && v->x24 <= 0) {
                func_003A52A0(1, 0, obj);
                v->x24 = 0x11;
            }
        }
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), v->x0 * 0.0200000014f);
        func_0038D308(a, b);
        break;
    }
}
