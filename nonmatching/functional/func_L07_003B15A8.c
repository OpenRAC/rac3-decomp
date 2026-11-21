/* functional: high. Written from PAL asm using the NTSC draft's structure; PAL differs: turn 0.12566371, speed step 1.6000001, fade step 0.096, timeout 0x33 frames, direction scale 0.10000001 (not 0.0833), every callee renamed; arg to func_L01_00404A10 is func_L07_003B1C08. VU0 vadd.xyz as float adds; 16-byte copy as four words. 253 diff = scheduling. */
typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    s32 w1C;
    f32 v20[4];
} Glob_003B15A8;

typedef struct {
    f32 f00, f04, f08;
    u8 pad0C[4];
    f32 f10, f14, f18;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[3];
    u8 b24;
    u8 pad25;
    u8 b26;
} Priv_003B15A8;

extern Glob_003B15A8 D_L07_001E8C00;
extern s32 D_001A71A0;
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004CB320(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004CB358(void);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(s32, s32, s32, void *, void *, f32);
extern void func_L01_00456230(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L07_003B1A30(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003B1C08();
extern void func_003C2880(void *);

void func_L07_003B15A8(u8 *obj) {
    f32 v0[4];
    f32 v10[4];
    Priv_003B15A8 *p;
    u8 *e;
    s32 hit;
    s32 w;
    f32 *op;

    p = *(Priv_003B15A8 **)(obj + 0x68);
    op = (f32 *)(obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        p->f18 = func_0038DAB8(p->f18, 0.12566371f);
        p->f10 = p->f10 + 1.6000001f;
        func_0038CE20(v0, obj + 0xC0, p->f10);
        w = *(s32 *)(obj + 0xB8);
        v0[0] = op[0] + v0[0];
        v0[1] = op[1] + v0[1];
        v0[2] = op[2] + v0[2];
        func_L01_004CB320();
        hit = func_003D3CB0(op, v0, 0, w, 0);
        if (hit != 0) {
            e = D_L07_001E8C00.p18;
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            p->f10 = func_0038CF00(op, D_L07_001E8C00.v20);
            if (D_L07_001E8C00.w1C > 0) {
                ((s32 *)p)[0] = ((s32 *)D_L07_001E8C00.v20)[0];
                ((s32 *)p)[1] = ((s32 *)D_L07_001E8C00.v20)[1];
                ((s32 *)p)[2] = ((s32 *)D_L07_001E8C00.v20)[2];
                ((s32 *)p)[3] = ((s32 *)D_L07_001E8C00.v20)[3];
                p->b24 = 1;
                p->f08 = p->f08 + 0.1f;
            }
            if ((s32)D_L07_001E8C00.p18 == D_001A71A0) {
                func_0038CF68(v10, obj + 0xC0, 0.10000001f);
                func_L01_00446A70((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, D_L07_001E8C00.v20, v10, (f32)p->b26);
                func_L01_00456230(*(s32 *)(obj + 0xB8), 1);
            }
            func_L01_004450F0(obj, 1, -1);
        } else {
            *(u16 *)(obj + 0x96) += 1;
            if (*(u16 *)(obj + 0x96) >= 0x33) {
                func_L01_004450F0(obj, 1, -1);
            }
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 1:
        if (p->f14 < 0.5f) {
            func_0038CE20(v0, obj + 0xC0, p->f10);
            w = *(s32 *)(obj + 0xB8);
            v0[0] = op[0] + v0[0];
            v0[1] = op[1] + v0[1];
            v0[2] = op[2] + v0[2];
            if (func_003D3CB0(op, v0, 0, w, 0) != 0) {
                if ((s32)D_L07_001E8C00.p18 == D_001A71A0) {
                    func_0038CF68(v10, obj + 0xC0, 0.10000001f);
                    func_L01_00446A70((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, D_L07_001E8C00.v20, v10, (f32)p->b26);
                    func_L01_00456230(*(s32 *)(obj + 0xB8), 1);
                }
            }
        }
        func_L07_003B1A30(obj);
        p->f18 = func_0038DAB8(p->f18, 0.12566371f);
        p->f14 = p->f14 + 0.096f;
        if (p->f14 >= 1.0f) {
            p->f14 = 1.0f;
            if (p->b24 != 0) {
                func_L01_004450F0(obj, 2, -1);
            } else {
                func_L01_004450F0(obj, 3, -1);
            }
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 2:
        if (func_L07_003B1A30(obj) != 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        func_L01_00404A10(func_L07_003B1C08, obj);
        break;
    case 3:
        func_003C2880(obj);
        break;
    }
}
