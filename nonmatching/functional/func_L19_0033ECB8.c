/* functional: medium. Vector ops as plain C (vu0.h asm needs -mvu0-use-vf0-vf2). Draft (PAL names confirmed against asm) (122 diff: tail-merge of the func_L01_004450F0 calls differs, behaviour unchanged). Four-state mover (init/idle/moving-to/moving-back) of an object between two vectors x70 and x80 with a sound; vector-op macros from vu0.h. Case 0 copy from D_001DF800[xA4].v (offset +0x30) taken from the draft, unverified in the asm because the lq/sq words are raw. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_33ECB8;
static void vsub_33ECB8(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *x = (f32 *)a, *y = (f32 *)b;
    o[0] = x[0] - y[0];
    o[1] = x[1] - y[1];
    o[2] = x[2] - y[2];
    o[3] = x[3];
}
static void vadd_33ECB8(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *x = (f32 *)a, *y = (f32 *)b;
    o[0] = x[0] + y[0];
    o[1] = x[1] + y[1];
    o[2] = x[2] + y[2];
    o[3] = x[3];
}
typedef struct { u8 pad[0x30]; V4_33ECB8 v; u8 pad2[0x40]; } P_33ECB8;
typedef struct {
    u8 pad0[0x70];
    V4_33ECB8 x70;
    V4_33ECB8 x80;
    s32 x90;
    s32 x94;
    s32 x98;
    s32 x9C;
    s32 xA0;
    s32 xA4;
} V_33ECB8;
__asm__(".extern D_L19_001DD204, 4");
extern f32 D_L19_001DD204;
extern P_33ECB8 *D_L19_001DF800;
extern u8 D_001A30B0[];
extern s32 func_L01_00456250(u8 *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C4DA8(u8 *, void *, void *, void *);

void func_L19_0033ECB8(u8 *obj) {
    V_33ECB8 *v = *(V_33ECB8 **)(obj + 0x68);
    u8 *p = obj + 0x10;
    V4_33ECB8 save;
    V4_33ECB8 d;

    save = *(V4_33ECB8 *)(obj + 0x10);
    if (obj[0x21] != 0xFF)
        v->x98 = func_L01_00456250(obj);
    switch (obj[0x20]) {
    case 0:
        v->x9C = -1;
        v->x70 = *(V4_33ECB8 *)(obj + 0x10);
        v->x80 = *(V4_33ECB8 *)(obj + 0x10);
        if (v->xA4 != -1)
            v->x80 = D_L19_001DF800[v->xA4].v;
        else
            v->x80.z = func_003C3D30(p, 0, 0, 0.5f)
                + D_L19_001DD204 * *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
        v->x94 = (f32)v->x94 * 50.0f;
        v->x98 = v->x90;
        if (v->x98 != 0) {
            *(V4_33ECB8 *)(obj + 0x10) = v->x70;
            v->xA0 = v->x94;
        } else {
            *(V4_33ECB8 *)(obj + 0x10) = v->x80;
            v->xA0 = 0;
        }
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (v->x98 != 0) {
            if (v->xA0 < v->x94)
                func_L01_004450F0(obj, 2, -1);
        } else if (v->xA0 > 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2: {
        s32 id;
        s32 n;
        u8 *s;

        id = v->x9C;
        if (id == -1 || (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
            v->x9C = func_003A52A0(0, 4, obj);
        n = v->xA0 + 1;
        v->xA0 = n;
        vsub_33ECB8(&d, &v->x70, &v->x80);
        func_0038CE20(&d, &d, (f32)n / (f32)v->x94);
        vadd_33ECB8(obj + 0x10, &d, &v->x80);
        if (v->x98 == 0) {
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 3, -1);
        } else if (v->x94 < v->xA0) {
            v->xA0 = v->x94;
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
    case 3: {
        s32 id;
        u8 *s;

        if (*(u16 *)(obj + 0x96) >= 0x33) {
            id = v->x9C;
            if (id == -1 || (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
                v->x9C = func_003A52A0(0, 4, obj);
            func_0038CAD0(&v->xA0);
            vsub_33ECB8(&d, &v->x70, &v->x80);
            func_0038CE20(&d, &d, (f32)v->xA0 / (f32)v->x94);
            vadd_33ECB8(obj + 0x10, &d, &v->x80);
        }
        if (v->x98 != 0) {
            func_L01_004450F0(obj, 2, -1);
        } else if (v->xA0 <= 0) {
            v->xA0 = 0;
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
    }
    if (*(u16 *)(obj + 0x96) < 0xFFFF)
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    vsub_33ECB8(&d, obj + 0x10, &save);
    func_003C4DA8((u8 *)v + 0x30, &d, obj + 0xF0, obj + 0xF0);
}
